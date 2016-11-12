#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
//#include <cstdlib>
#include <string.h>
#include <math.h>
#include <ctime>
#include <vector>
#include <future>
#include "BotClass.h"
#include "UseSkills.h"
#define PI 3.14159265
#include "Packet.h"
#include "MonsterInterraction.h"
int Monsters::m_nRegisteredMonters = 0;

void updateLocations() {

}
void(*ftpointer)() = updateLocations;

std::map<long long, boost::shared_ptr <Monsters>*> MonstersMap;
std::map<long long, boost::shared_ptr <Monsters>> MonstersMapSavedPointer;
std::map<long long, boost::shared_ptr <Monsters>> MonstersMapSavedPointerSelectedMonsters;
bool Monsters::SelectMonsters(std::vector <unsigned char> &vectArg, int & nAnalyzedSize)
{
	if ((vectArg[84 + nAnalyzedSize] != 0x01) || (vectArg[63 + nAnalyzedSize] != 0x00) || (vectArg[62 + nAnalyzedSize] != 0x01))//(vectArg[64 + nAnalyzedSize] != 0x01) || means new spawn or not
	{
		/*
		int iii = 0;
		for (std::vector <unsigned char> ::iterator uuu = vectArg.begin(); iii<131;  ++uuu, ++iii)
			printf("0x%02X ", *(uuu + nAnalyzedSize));
		cout << endl;
		*/
		return false;
	}
	/*
	printf(" long long descriptor : 0x%16X", m_llDescriptor);
	cout << " regular cout of descriptor: " << hex << m_llDescriptor << endl;
	cout << "regular cout of ID : " << hex << m_llId << endl;
	cout << "size is : " << hex << m_nSize << endl;
	*/
	if ((m_llDescriptor != 0x0000C0C1C11D0020) && (m_llDescriptor != 0x00000033005f0029) && (m_llDescriptor != 0x0000D06cc774c0ac) && (m_llDescriptor != 0x00000029bca8b808))
	{
		return false;
	}
	else
	return true;
}
void Monsters::SaveNewSelectedMonsterPointer(boost::shared_ptr <Monsters> & MobPtrArg)
{
	if (MobPtrArg->m_bSelected)
	{
		MonstersMapSavedPointerSelectedMonsters[MobPtrArg->m_llId] = MobPtrArg;
	}
}
void Monsters::SaveNewPointer(boost::shared_ptr <Monsters> & MobPtrArg)
{
	//check if second already exist and release it if so
	MonstersMapSavedPointer[MobPtrArg->m_llId] = MobPtrArg;
}
void Monsters::updatePtrValue(boost::shared_ptr <Monsters>& MonsterPtr) {
	MonstersMap[m_llId] = &MonsterPtr;
}
void Monsters::updatePtr(boost::shared_ptr <Monsters>& MonsterPtr) {
	while (!MonsterPtr)
	{
		Sleep(100);
	}
	Sleep(100); // this is in case of atomic race problems
	MonstersMap[m_llId] = &MonsterPtr;
}



boost::shared_ptr <Monsters> ptrMobKn;
boost::shared_ptr <Monsters> ptrMob1;
boost::shared_ptr <Monsters> ptrMob2;
boost::shared_ptr <Monsters> ptrMob3;
boost::shared_ptr <Monsters> ptrMob4;
boost::shared_ptr <Monsters> ptrMob5;
boost::shared_ptr <Monsters> ptrMob6;
boost::shared_ptr <Monsters> ptrMob7;
boost::shared_ptr <Monsters> ptrMob8;
boost::shared_ptr <Monsters> ptrMob9;
boost::shared_ptr <Monsters> ptrMob10;
boost::shared_ptr <Monsters> ptrMob11;
boost::shared_ptr <Monsters> ptrMob12;
boost::shared_ptr <Monsters> ptrMob13;
boost::shared_ptr <Monsters> ptrMob14;
boost::shared_ptr <Monsters> ptrMob15;
boost::shared_ptr <Monsters> ptrMob16;
boost::shared_ptr <Monsters> ptrMob17;
boost::shared_ptr <Monsters> ptrMob18;
boost::shared_ptr <Monsters> ptrMob19;
boost::shared_ptr <Monsters> ptrMob20;

void getClosestMonster() {
	cout << "Get closest monster function. map size is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
	if (MonstersMapSavedPointerSelectedMonsters.size() == 0)
		return;
	std::map <long long, boost::shared_ptr < Monsters>> ::iterator it = MonstersMapSavedPointerSelectedMonsters.begin();
	if (MonstersMapSavedPointerSelectedMonsters.size() == 1)
	{
		ptrMob1 = it->second; //otherwise it would crash because ptrMob1 would hold no value.
		return;
	}
	//thus far, if the map's size was 0 or 1 the function returned respectively without or with a pointer.
	if (it != MonstersMapSavedPointerSelectedMonsters.end())
	{
		cout << "it doesn't point to map.end()" << endl;
	}
	else
	{
		cout << "it points to map.end(), expect a crash" << endl;
	}
	std::map <long long, boost::shared_ptr <Monsters>> ::iterator it2 = MonstersMapSavedPointerSelectedMonsters.upper_bound(it->first);
	if (it->second && it2->second)
	{
		cout << "the iterators have associated pointers (ie second values) " << endl;
		it->second->GetSquareDistanceToMonster();
		it2->second->GetSquareDistanceToMonster();
		if (it->second->m_fDistanceToMonster < it2->second->m_fDistanceToMonster)
		{
			ptrMob1 = it->second;
		}
		else
			ptrMob1 = it2->second;
	}
	else
	{
		cout << "the iterators don't have second values (ie associated pointers)" << endl;
	}
	int uuu = 0;
	if (MonstersMapSavedPointerSelectedMonsters.size() == 2)
		return;
	if (uuu <= (MonstersMapSavedPointerSelectedMonsters.size() - 3))
	while (uuu <= (MonstersMapSavedPointerSelectedMonsters.size() - 3))
	{
		++uuu;
		cout << "Calculating nearest monster. uuu = " << uuu << "  and size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() <<  endl;
	it2 = MonstersMapSavedPointerSelectedMonsters.upper_bound(it2->first);
	if (it2->second)
	{
		it2->second->GetSquareDistanceToMonster();
		if (ptrMob1->m_fDistanceToMonster < it2->second->m_fDistanceToMonster)
			Sleep(1);
		else
			ptrMob1 = it2->second;
	}
	}
}