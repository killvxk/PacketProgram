#ifndef MONSTERINTERRACTION_H
#define MONSTERINTERRACTION_H
#include <vector>
#include <future>
#include <thread>
#include "Waypoint.h"
class Monsters;
void getClosestMonster();
extern std::map<long long, boost::shared_ptr <Monsters>*> MonstersMap;
extern std::map<long long, boost::shared_ptr <Monsters>> MonstersMapSavedPointer;
extern std::map<long long, boost::shared_ptr <Monsters>> MonstersMapSavedPointerSelectedMonsters;
class Monsters
{
public:
	std::vector <unsigned char> m_Id;
	long long m_llId;
	int m_X;
	int m_Y;
	int m_Z;
	uint16_t m_nSize;
	long long m_llDescriptor;
	bool m_LifeState;
	bool m_bSelected;
	float m_fDistanceToMonster;
	static int m_nRegisteredMonters;
	void updatePtr(boost::shared_ptr <Monsters> & ptrMobArg);
	bool SelectMonsters(std::vector <unsigned char> &vectArg, int & nAnalyzedSize);
	Monsters::Monsters() {

	}
	Monsters::Monsters(std::vector <unsigned char> &vectArg, int &nAnalyzedSize, boost::shared_ptr < Monsters > & MonsterPtr) : m_LifeState(1)
	{
		std::cout << "Create monster constructor" << std::endl;
		++m_nRegisteredMonters;
		m_X = TurnVectInto32_int(vectArg, 26, nAnalyzedSize);
		m_Y = TurnVectInto32_int(vectArg, 30, nAnalyzedSize);
		m_Z = TurnVectInto32_int(vectArg, 34, nAnalyzedSize);
		for (int uuu = 10; uuu < 18; ++uuu)
		{
			m_Id.push_back(vectArg[uuu + nAnalyzedSize]);
		}
		memcpy(&m_llId, &m_Id[0], sizeof(m_llDescriptor));
		std::vector <unsigned char > TempVec;
		m_nSize = ((vectArg[nAnalyzedSize]) | (vectArg[nAnalyzedSize + 1] << 8));
		for (int uuu = m_nSize - 8; uuu != m_nSize; ++uuu)
			TempVec.push_back(vectArg[nAnalyzedSize + uuu]);
		memcpy(&m_llDescriptor, &TempVec[0], sizeof(m_llDescriptor));
		m_bSelected = SelectMonsters(vectArg, nAnalyzedSize);
	}
	int GetSquareDistanceToMonster() {
		float x;
		float y;
		float xm;
		float ym;
		x = *(float *)&m_X;
		y = *(float *)&m_Y;
		ym = *(float *)&currentY;
		xm = *(float *)&currentX;
		float dif1 = x - xm;
		float dif2 = y - ym;
		m_fDistanceToMonster = (pow(dif1, 2) + pow(dif2, 2));
		return 1;

	}
	~Monsters() {
		--m_nRegisteredMonters;
	}
	void updatePtrValue(boost::shared_ptr <Monsters> &Mobptr);
	static void SaveNewPointer(boost::shared_ptr < Monsters > & MobPtrArg);
	static void Monsters::SaveNewSelectedMonsterPointer(boost::shared_ptr <Monsters> & MobPtrArg);
};

extern boost::shared_ptr <Monsters> ptrMobKn;
extern boost::shared_ptr <Monsters> ptrMob1;
extern boost::shared_ptr <Monsters> ptrMob2;
extern boost::shared_ptr <Monsters> ptrMob3;
extern boost::shared_ptr <Monsters> ptrMob4;
extern boost::shared_ptr <Monsters> ptrMob5;
extern boost::shared_ptr <Monsters> ptrMob6;
extern boost::shared_ptr <Monsters> ptrMob7;
extern boost::shared_ptr <Monsters> ptrMob8;
extern boost::shared_ptr <Monsters> ptrMob9;
extern boost::shared_ptr <Monsters> ptrMob10;
extern boost::shared_ptr <Monsters> ptrMob11;
extern boost::shared_ptr <Monsters> ptrMob12;
extern boost::shared_ptr <Monsters> ptrMob13;
extern boost::shared_ptr <Monsters> ptrMob14;
extern boost::shared_ptr <Monsters> ptrMob15;
extern boost::shared_ptr <Monsters> ptrMob16;
extern boost::shared_ptr <Monsters> ptrMob17;
extern boost::shared_ptr <Monsters> ptrMob18;
extern boost::shared_ptr <Monsters> ptrMob19;
extern boost::shared_ptr <Monsters> ptrMob20;
#endif