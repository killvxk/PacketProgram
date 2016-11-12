
#include <iostream>
#include <string.h>
#include <fstream>
#include <thread>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <future>
#include "PacketProgramBoost.h"
#include "PacketReception.h"
#include "cryptography.h"
#include "PacketData.h"
#include "Packet.h"
#include "ManagePlayers.h"
#include "Waypoint.h"
#include "ItemInterraction.h"
#include "MonsterInterraction.h"
#include "BotClass.h"
#include "ConfigFile.h"
#include "Contracts.h"
#include "UseSkills.h"
using namespace std;
boost::system::error_code error_2;
std::vector<unsigned char> vectReception(1000000); //all packets have an unsigned char array
std::vector<unsigned char> vectReception2(500000);
std::vector<unsigned char> vectReception3(100000);
std::vector<unsigned char> vectReception4(100000);
int generalFlag(0);
int length;
bool errorflag;
bool bTpHack(0);
bool flagonce(0);
int nAnalyzedSize = 0;
void* ptrReceivedPacket;
int iteration(0);
int length_trackdown = 0;
int nNumberOfEnnemies(0);
std::vector<unsigned char>::iterator oo = vectReception.begin();
void handler(const boost::system::error_code & ec,
	std::size_t bytes_transferred) {
	cout << "this gets even read ?" << endl;
	if (ec)
	{
		cout << "an error occured !" << endl;
	}
	else {
		cout << "We transfered : " << bytes_transferred << " bytes." << endl;
	}
}
void DecryptPacket(int size, std::vector <unsigned char > & vectReceptionArg){

}

int16_t RetrievePacketTitle(int size) {

}
void ReleaseAllMonsterPtr()
{
	if (ptrMob1)
	{
		ptrMob1.reset();
	}
	if (ptrMob2)
		ptrMob2.reset();
	if (ptrMob3)
		ptrMob3.reset();
	if (ptrMob4)
		ptrMob4.reset();
	if (ptrMob5)
		ptrMob5.reset();
	if (ptrMob6)
		ptrMob6.reset();
	if (ptrMob7)
		ptrMob7.reset();
	if (ptrMob8)
		ptrMob8.reset();
	if (ptrMob9)
		ptrMob9.reset();
	if (ptrMob10)
		ptrMob10.reset();
	if (ptrMob11)
		ptrMob11.reset();
	if (ptrMob12)
		ptrMob12.reset();
	if (ptrMob13)
		ptrMob13.reset();
	if (ptrMob14)
		ptrMob14.reset();
	if (ptrMob15)
		ptrMob15.reset();
	if (ptrMob16)
		ptrMob16.reset();
	if (ptrMob17)
		ptrMob17.reset();
	if (ptrMob18)
		ptrMob18.reset();
	if (ptrMob19)
		ptrMob19.reset();
}
bool AssignPartyMemberPtr(std::vector <unsigned char> &vectArgument) {
	boost::shared_ptr <Players> Playerptr = boost::shared_ptr <Players>(new Players(vectArgument, nAnalyzedSize, Playerptr));
	Players::SaveNewPlayerPointer(Playerptr);
	return true;
}
bool AssignMobPtr(std::vector <unsigned char> &vectArgument) {
	boost::shared_ptr <Monsters> Mobptr = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, Mobptr));
	Monsters::SaveNewPointer(Mobptr);
	Monsters::SaveNewSelectedMonsterPointer(Mobptr);
	/*
	if (!ptrMob1)
	{
		ptrMob1 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob1));
		ptrMob1->updatePtr(ptrMob1);
	}
	else if (!ptrMob2)
	{
		ptrMob2 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob2));
		ptrMob2->updatePtr(ptrMob2);
	}
	else if (!ptrMob3)
	{
		ptrMob3 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob3));
		ptrMob3->updatePtr(ptrMob3);
	}
	else if (!ptrMob4)
	{
		ptrMob4 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob4));
		ptrMob4->updatePtr(ptrMob4);
	}
	else if (!ptrMob5)
	{
		ptrMob5 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob5));
		ptrMob5->updatePtr(ptrMob5);
	}
	else if (!ptrMob6)
	{
		ptrMob6 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob6));
		ptrMob6->updatePtr(ptrMob6);
	}
	else if (!ptrMob7)
	{
		ptrMob7 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob7));
		ptrMob7->updatePtr(ptrMob7);
	}
	else if (!ptrMob8)
	{
		ptrMob8 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob8));
		ptrMob8->updatePtr(ptrMob8);
	}
	else if (!ptrMob9)
	{
		ptrMob9 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob9));
		ptrMob9->updatePtr(ptrMob9);
	}
	else if (!ptrMob10)
	{
		ptrMob10 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob10));
		ptrMob10->updatePtr(ptrMob10);
	}
	else if (!ptrMob11)
	{
		ptrMob11 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob11));
		ptrMob11->updatePtr(ptrMob11);
	}
	else if (!ptrMob12)
	{
		ptrMob12 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob12));
		ptrMob12->updatePtr(ptrMob12);
	}
	else if (!ptrMob13)
	{
		ptrMob13 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob13));
		ptrMob13->updatePtr(ptrMob13);
	}
	else if (!ptrMob14)
	{
		ptrMob14 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob14));
		ptrMob14->updatePtr(ptrMob14);
	}
	else if (!ptrMob15)
	{
		ptrMob15 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob15));
		ptrMob15->updatePtr(ptrMob15);
	}
	else if (!ptrMob16)
	{
		ptrMob16 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob16));
		ptrMob16->updatePtr(ptrMob16);
	}
	else if (!ptrMob17)
	{
		ptrMob17 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob17));
		ptrMob17->updatePtr(ptrMob17);
	}
	else if (!ptrMob18)
	{
		ptrMob18 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob18));
		ptrMob18->updatePtr(ptrMob18);
	}
	else if (!ptrMob19)
	{
		ptrMob19 = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMob19));
		ptrMob19->updatePtr(ptrMob19);
		while (1)
		{
			cout << "ERROR" << endl;
			Sleep(1000);
		}
	}
	else
		return FALSE;
		*/
	return TRUE;
}
void LoginArbiter(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	//this should never touch data which is outside of the size of the packet
	if (vectArgument[nAnalyzedSize + 4] == 0x01)
	{
		cout << "Logged in." << endl;
		Mystic.m_bConnexionState = 1;
	}
	else
	{
		cout << "Connexion refused." << endl;
		cout << "Program will exit in 1 second" << endl;
		Mystic.m_bConnexionState = 2;
		Sleep(1000);
		exit(2);
	}

}
string filename = "Bot session whispers.txt";
//filename = "BotLog1.txt";
ofstream fout(filename.c_str());
void LogWhispers(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	std::vector <unsigned char> vZero = { 0x00, 0x00, 0x00 };
	std::vector<unsigned char> start{ 0x2e, 0x00, 0x63, 0x00, 0x6c, 0x00, 0x65, 0x00, 0x61, 0x00, 0x72, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00 };//detects .clear1425
	std::vector <unsigned char> delog{ 0x2e, 0x00, 0x64, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x6f, 0x00, 0x67, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00 };
	auto it = std::search(vectArgument.begin(), vectArgument.end(), start.begin(), start.end());
	if (it != vectArgument.end())
	{ 
		cout << "CLEAR ! RESET ALLOWED #### !!! CLEAR !" << endl;
		nNumberOfEnnemies = 0;
	}
	it = std::search(((vectArgument.begin())), vectArgument.end(), delog.begin(), delog.end());
	if (it != vectArgument.end())
	{
		HandlePacket(size04x04, C_RETURN_TO_LOBBY, socket);
	}
	std::vector <unsigned char> vInviteDetection{ 0x2E, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x76, 0x00, 0x69, 0x00, 0x74, 0x00, 0x65, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00 }; //detects .invite1425
	it = std::search(((vectArgument.begin())+21), vectArgument.end(), vInviteDetection.begin(), vInviteDetection.end());
	if (it != vectArgument.end())
	{ 
		cout << "INVITE REQUEST DETECTED #### INVITE REQUEST DETECTED #### " << endl; 
	TempVec = vPartyInvite;
	for (int uuu = 0; uuu < 14; ++uuu)
		TempVec.push_back(00);
	std::vector <unsigned char> ::const_iterator itera = vectArgument.begin() + 21;
	it = std::search(((vectArgument.begin()) + 21), vectArgument.end(), vZero.begin(), vZero.end());
	for (; itera != it; ++itera)
		TempVec.push_back(*itera);
	for (int uuu = 0; uuu < 4; ++uuu)
		TempVec.push_back(00);
	int nSize = TempVec.size() + 4;
	HandleUndecipheredPacket(nSize, C_REQUEST_CONTRACT, TempVec, socket);
	}
	char message[sizeof(vectArgument)];
	char * msgptr = new char[sizeof(vectArgument)-nAnalyzedSize];
	//msgptr is deprecated
	for (int uuu = 4; uuu < size; ++uuu)
	{
		fout << vectArgument[nAnalyzedSize + uuu];
	}
	fout<< " " << endl;
	HWND hwnd = NULL;
	std::async(MessageBox, hwnd, (LPCSTR)Mystic.name, (LPCSTR)("Whisper"), 0X0L);
	delete[] msgptr;
}
void ReplyToUserLevelUp(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector<unsigned char>::iterator it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vId.begin(), Mystic.m_vId.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		Mystic.m_nLevel = TurnVectInto32_int(vectArgument, 12, nAnalyzedSize);
	}
	cout << "Level up ! " << dec << Mystic.m_nLevel << endl;
}
void ReplyToSLogin(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	for (int uuu = 18; uuu <= 25; ++uuu)
		Mystic.m_vId.push_back(vectArgument[uuu + nAnalyzedSize]);
}
void LogFirstUser(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector<unsigned char> TempVec;
	if (size123 == 127)
	{
		for (int uuu = 55; uuu <= 58; ++uuu)
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	else
	{
		TempVec = { 0x94, 0x6d, 0x1d, 0x00 };
	}
	Mystic.vm_Id = TempVec;
	//carrefull : Insert TempVec now because after the following pushback it will not match correctly.
	TempVec.push_back(00);
	HandleUndecipheredPacket(size09x09, C_SELECT_USER, TempVec, socket);
	TempVec.clear();
	auto it = std::search(vectArgument.begin(), vectArgument.end(), vNameSignature.begin(), vNameSignature.end());
	std::vector <unsigned char> ::const_iterator itera = it;
	char truiy[20] = { 0 };
	int nZerosInARow(0);
	if (it != vectArgument.end())
	{
		for (int uuu = 0; uuu <= 26; ++uuu, ++itera)
		{
			//if ((uuu%2) == 0)//wont print 00s on console title
			if (*(itera + 23) == 0x00)
			{
				++nZerosInARow;
				if (nZerosInARow >= 2)
					break; //if you get 0x00 twice in a row the string is terminated.
				TempVec.push_back(*(itera + 23));
				continue;
			}
			TempVec.push_back(*(itera + 23));
			nZerosInARow = 0; //if we get to this point there was a char inside the vector thus we zero our zero count.
			truiy[uuu-(uuu/2)] = TempVec[uuu];
		}
		cout << truiy << endl;
		for (int uuu = 0; uuu < TempVec.size(); ++uuu)
			printf("0x%02X ", TempVec[uuu]);
		cout << endl;
		Mystic.m_vMysticName = TempVec;
	}
	void *test = &TempVec;
	consoleWindow = GetConsoleWindow();
	//SetWindowText(consoleWindow, test);
	SetConsoleTitle(
		 (LPCTSTR) truiy
		);
	for (int uuu = 0; uuu < 14; ++uuu)
	{
		Mystic.name[uuu] = truiy[uuu];
	}

}
void ProcessChangePartyManager(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	for (int uuu = 10; uuu < 14; ++uuu)
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	if (Mystic.vm_Id == TempVec)
	{
		Mystic.bm_LeaderState = 1;
		if (bWatcher)
		{
			HandlePacket(size04x04, C_RETURN_TO_LOBBY, socket);
		}
	}
	else
		Mystic.bm_LeaderState = 0;
}
void ProcessPartyMemberList(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	for (int uuu = 26; uuu < 30; ++uuu)
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	if (Mystic.vm_Id == TempVec)
	{
		Mystic.bm_LeaderState = 1;
		if (bWatcher)
		{
			HandlePacket(size04x04, C_RETURN_TO_LOBBY, socket);
		}
	}
	else
		Mystic.bm_LeaderState = 0;
	//
	AssignPartyMemberPtr(vectArgument);
}
void ReplyToVisitNewSection(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
		std::vector <unsigned char> TempVec;
		for (int uuu = 5; uuu < 17; ++uuu)
		{
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
		}
		HandleUndecipheredPacket(size16x10, C_VISIT_NEW_SECTION, TempVec, socket);

}
void ReplyToGuardPkPolicy(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	if (size == 0x05)
	{
		HandlePacket(size04x04, C_GUARD_PK_POLICY, socket);
	}
}
void ReplyToReignInfo(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	for (int uuu = 8; uuu < 12; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	HandleUndecipheredPacket(size08x08, C_REIGN_INFO, TempVec, socket);
}
void HandleNpcDespawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "releasing npc ID" << endl;
	std::vector <unsigned char> TempVec;//Puts the despawning mob Id into TempVec
	for (int uuu = 4; uuu < 12; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	long long llId;
	memcpy(&llId, &TempVec[0], sizeof(llId));
		if ((ptrMobKn) && (TempVec == ptrMobKn->m_Id))
	{
			cout << "Kelsaik is despawning." << endl;
		ptrMobKn->m_LifeState = 0;
		MonstersMapSavedPointer.find(llId)->second.reset();
	}
		else {
	if (MonstersMapSavedPointer.find(llId)->second.use_count())
	{
			cout << "reseting monster pointer" << endl;
			if (MonstersMapSavedPointer.find(llId)->second->m_bSelected)
			{
				cout << "You killed a mob !" << endl;
				MonstersMapSavedPointerSelectedMonsters.find(llId)->second.reset();
				MonstersMapSavedPointerSelectedMonsters.erase(llId);
			}
			MonstersMapSavedPointer.find(llId)->second.reset();
			MonstersMapSavedPointer.erase(llId);
	}
	else
	{
		while (1)
		{
			Sleep(1000);
			cout << "ERROR ! THERE IS NO pointer for this npc being released" << endl;
		}
	}
		}
	cout << "released npc Id" << endl;
}
void CreateItem(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "registering item id (instantiating an item class)." << endl;
	if (!ptrItem1)
	ptrItem1 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem2)
		ptrItem2 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem3)
		ptrItem3 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem4)
		ptrItem4 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem5)
		ptrItem5 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem6)
		ptrItem6 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem7)
		ptrItem7 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem8)
		ptrItem8 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem9)
		ptrItem9 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem10)
		ptrItem10 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem11)
		ptrItem11 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem12)
		ptrItem12 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem13)
		ptrItem13 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem14)
		ptrItem14 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem15)
		ptrItem15 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem16)
		ptrItem16 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem17)
		ptrItem17 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem18)
		ptrItem18 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem19)
		ptrItem19 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else if (!ptrItem20)
		ptrItem20 = boost::shared_ptr <Items>(new Items(vectArgument, nAnalyzedSize));
	else
	{
		cout << "All Item pointers are used up. The bot can currently no longer loot." << endl;
	}
}
void ManageNpcLocation(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "1" << endl;
	std::vector <unsigned char> TempVec;//Puts the despawning mob Id into TempVec
	for (int uuu = 4; uuu < 12; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	long long llId;
	memcpy(&llId, &TempVec[0], sizeof(llId));
	cout << "2" << endl;
	std::map <long long, boost::shared_ptr < Monsters>> ::iterator it = MonstersMapSavedPointer.find(llId);
	if (it != MonstersMapSavedPointer.end())
	{
		cout << "found mob ptr" << endl;
		if (it->second)//this operation crashs
		{
			cout << "mobptr has a value" << endl;
			cout << "3" << endl;
			(it->second)->m_X = TurnVectInto32_int(vectArgument, 28, nAnalyzedSize);
			cout << "4" << endl;
			(it->second)->m_Y = TurnVectInto32_int(vectArgument, 32, nAnalyzedSize);
			cout << "5" << endl;
			(it->second)->m_Z = TurnVectInto32_int(vectArgument, 36, nAnalyzedSize);
			cout << "6" << endl;
		}
		else
			cout << "mobptr does not have a value" << endl;
	}
	else
		cout << "couldn't retrieve mob ptr from map" << endl;
}
void CreateNpc (uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "registering new npc id." << endl;
		if (size == 129)// npc tp size, patched from 130 to 133 12.08.61 then 133 to 129 29.09.16
		{
			std::vector <unsigned char> TempVec;
			for (int uuu = 123; uuu < 127; ++uuu)
			{
				TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);

			}
			if (TempVec == vNpcTpIdLastBytes)
			{
				vInterractKnNpc.clear();
				for (int uuu = 10; uuu < 18; ++uuu)
					vInterractKnNpc.push_back(vectArgument[uuu + nAnalyzedSize]);
			}
			AssignMobPtr(vectArgument);
		}
		else if (size == 137) // thrall size, patched from 138 to 141 on 12.08.16 then 137
		{
			std::vector <unsigned char> TempVec;
			for (int uuu = 123; uuu < 137; ++uuu)
			{
				TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
			}
			if (TempVec == vNpcThrallIdLastBytes)
			{
				vNewThrallId.clear();
				for (int uuu = 10; uuu < 18; ++uuu)
				{
					vNewThrallId.push_back(vectArgument[uuu + nAnalyzedSize]);
				}
				vCurrentThrallSkillId.clear();
				for (int uuu = 38; uuu < 40; ++uuu)
				{
					vCurrentThrallSkillId.push_back(vectArgument[uuu + nAnalyzedSize]);
				}
				//send attack packets
				Sleep(1000);
				TempVec.clear();
				TempVec = vNewThrallId;
				int x1 = 0x478f7c4f;
				int y1 = 0x480b9238;
				int z1 = 0xc62cd220;
				TurnInt32_tIntoVect(x1, TempVec);
				TurnInt32_tIntoVect(y1, TempVec);
				TurnInt32_tIntoVect(z1, TempVec);
				for (int uuu = 0; uuu < 2; ++uuu)
					TempVec.push_back(vCurrentThrallSkillId[uuu]);
				HandleUndecipheredPacket(size26x1a, C_NOTIFY_SPIRIT_LOCATION_IN_ACTION, TempVec, socket);
				cout << "registering Thrall npc id for (instantiating a monster class)." << endl;
				AssignMobPtr(vectArgument);
			}
			else if (TempVec == vNpcNpcSellerIdLastBytes)
			{
				cout << "registering new sell npc id." << endl;
				if (!(vNewNpcSellerId.empty()))
					vNewNpcSellerId.clear();
				for (int uuu = 10; uuu < 18; ++uuu)
					vNewNpcSellerId.push_back(vectArgument[uuu + nAnalyzedSize]);
				AssignMobPtr(vectArgument);
			}
			else
			{
				AssignMobPtr(vectArgument);
			}
		}
		else if (size == 123) // Kn case
		{
			std::vector <unsigned char> TempVec;
			for (int uuu = 111; uuu < 123; ++uuu)
			{
				TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
			}
			if (TempVec == vNpcKelsaikBossLastBytes)
			{
				cout << "registering kn npc id for Kn (instantiating a monster class)." << endl;
				ptrMobKn = boost::shared_ptr <Monsters>(new Monsters(vectArgument, nAnalyzedSize, ptrMobKn));
				Monsters::SaveNewPointer(ptrMobKn);
				Monsters::SaveNewSelectedMonsterPointer(ptrMobKn);
			}
			else
			{
				AssignMobPtr(vectArgument);
			}
		}
		else
		{
			AssignMobPtr(vectArgument);
		}
}
void ReplyToActionStage(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	cout << "registering npc id from action_stage." << endl;
	for (int uuu = 8; uuu < 16; ++uuu)
	{ 
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
		if (TempVec == vNewThrallId)
		{
			cout << "met registering conditions" << endl;
			vCurrentThrallSkillId.clear();
			for (int uuu = 28; uuu < 30; ++uuu)
				vCurrentThrallSkillId.push_back(vectArgument[uuu + nAnalyzedSize]);
			//send spirit notifies
			Sleep(1000);
			TempVec.clear();
			TempVec = vNewThrallId;
			int x1 = 0x478f7c4f;
			int y1 = 0x480b9238;
			int z1 = 0xc62cd220;
			TurnInt32_tIntoVect(x1, TempVec);
			TurnInt32_tIntoVect(y1, TempVec);
			TurnInt32_tIntoVect(z1, TempVec);
			for (int uuu = 0; uuu < 2; ++uuu)
			{ 
				TempVec.push_back(vCurrentThrallSkillId[uuu]);
			}
			vPacketThrallToBeSent.clear();
			vPacketThrallToBeSent = TempVec;
			++bThrallActions;
			cout << "Finished sending notify spirit locations." << endl;
		}
		TempVec.clear();
		for (int uuu = 34; uuu < 38; ++uuu)
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
		std::vector <unsigned char> vPressSkill = { 0xc4, 0x9f, 0x00, 0x04 };
		if (TempVec == vPressSkill)
			PressSkill::IncreaseSkillStage();
	
}
void ReplyToSGrantSkill(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "-1" << endl;
	int ArcanePulseFromPacket = TurnVectInto32_int(vectArgument, 4, nAnalyzedSize);
	std::map <long long, boost::shared_ptr <Monsters>> ::iterator itlow;
	cout << "0" << endl;
	itlow = MonstersMapSavedPointerSelectedMonsters.begin();
	cout << "1" << endl;
	if (!itlow->second)
		cout << "expecting a crash, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
	else
		cout << "no crash, there is a pointer in the map and size is " << MonstersMapSavedPointerSelectedMonsters.size() << "\n" << endl;
	vSendSkillPacket2 = FormSendSkillPacketWithDest(ArcanePulseFromPacket, itlow->second);
	HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
}
void ProcessSChat(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	vCleanReset = { 0x2e, 0x00, 0x63, 0x00, 0x6c, 0x00, 0x65, 0x00, 0x61, 0x00, 0x72, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35 }; //inefficient, delete me
	auto it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, leave.begin(), leave.end());
	if (it != vectArgument.begin() + nAnalyzedSize + size)
	{ 
		HandlePacket(size04x04, C_LEAVE_PARTY, socket);
	}
	it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, reset.begin(), reset.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		cout << "Reset Request detected ### Reset Request detected ### " << endl;
		if (Mystic.bm_LeaderState == 1)
		{ 
		HandlePacket(size04x04, C_RESET_ALL_DUNGEON, socket);
		}
	}
	it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, vBotNumber.begin(), vBotNumber.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		if (nBotNumber == 0)
		nBotNumber = 1;
	}
	it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, readyMate.begin(), readyMate.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		cout << "Partner is ready." << endl;
		Mystic.m_bPartnerReady = 1;
	}
	if (!bWatcher)
	{
		it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, vCleanReset.begin(), vCleanReset.end());
		if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		generalFlag = 1;
		nNumberOfEnnemies = 0;
	}
	}
	std::vector <unsigned char> TempVec;//Puts the despawning mob Id into TempVec
	for (int uuu = 12; uuu < 20; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	long long llId;
	memcpy(&llId, &TempVec[0], sizeof(llId));
	std::map < long long, boost::shared_ptr < Players>>::iterator iit = PlayersMapSavedPointer.find(llId);
	if (iit != PlayersMapSavedPointer.end())
	{
		if (PlayersMapSavedPointer.find(llId)->second) // if you get there the player speaking is saved as a party member
		{
			it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, vFollow.begin(), vFollow.end());
			if (it != (vectArgument.begin() + nAnalyzedSize + size))
			{
				cout << "Follow Request detected ### " << endl;
				PlayersMapSavedPointer.find(llId)->second->m_bOrderedToFollow = 1;
			}
			else
			{
				it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, vUnfollow.begin(), vUnfollow.end());
				if (it != (vectArgument.begin() + nAnalyzedSize + size))
				{
					cout << "Stop follow Request detected ### " << endl;
					PlayersMapSavedPointer.find(llId)->second->m_bOrderedToFollow = 0;
				}
			}
		}
	}
}
void ContinueFirstNpcDialog(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket) //S_DIALOG function treatment
{
	std::vector<unsigned char> TempVec;
	if (vNpc_Menu_SelectionLatest == vNpc_Menu_Selection1stStage)
	{ //case in which it's the first S_DIALOG received
		cout << "1st stage" << endl;
		for (int uuu = 40; uuu <= 43; ++uuu) //takes ID for immediat reuse
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
		vInterractNpcDialogId_1.clear();//clear before write else it's unusable
	for (int uuu = 40; uuu <= 43; ++uuu) //stores ID
		vInterractNpcDialogId_1.push_back(vectArgument[uuu + nAnalyzedSize]);
	for (int uuu = 0; uuu < 8; ++uuu) // forms open dialog vector
	TempVec.push_back(00);
	HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);
	}
	if (vNpc_Menu_SelectionLatest == vNpc_Menu_Selection2ndStage)
	{//case in which it's the second S_DIALOG received
		cout << "2nd stage " << endl;
		TempVec = vInterractNpcDialogId_1; //legit id_1 , it's a close
		vInterractNpcDialogId_2.clear();//clear before write else it's unusable
		for (int uuu = 40; uuu <= 43; ++uuu)
			vInterractNpcDialogId_2.push_back(vectArgument[uuu + nAnalyzedSize]);
		TempVec.push_back(02);//Forms close dialog vector
		for (int uuu = 0; uuu < 7; ++uuu)
			TempVec.push_back(00);
		HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket); //only 1 sample sent here
		TempVec.clear();
		TempVec = vInterractNpcDialogId_2;
		vInterractNpcDialogId_1 = vInterractNpcDialogId_2; // horribly written fix to get correct close dialog events
		for (int uuu = 0; uuu < 8; ++uuu) // forms open dialog vector
			TempVec.push_back(00);
		HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);//only 1 sample sent
	}
}
void UpdateMenuSlection(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	cout << "UPDATED MENU SELECTION" << endl;
	vNpc_Menu_SelectionLatest.clear();
	for (int uuu = 4; uuu < 8; ++uuu)
		vNpc_Menu_SelectionLatest.push_back(vectArgument[uuu + nAnalyzedSize]);
	flagonce = 0;
}
 void ReplyToSStoreSellList(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket) {
	 //used to contain c_show_inven, turned out to cause disconects
}
void SortS_DIALOG_EVENT (uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket) // sorts S dialog_EVENT packets and adapts
{
	//Checks if this packet is addressed to the bot : 
	auto it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vId.begin(), Mystic.m_vId.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		std::vector <unsigned char> TempVec;
		{
			TempVec.clear(); // clear for reuse
			cout << "SDIALOG detected ! BABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
			std::vector<unsigned char> TempVec;
			if (vectArgument[nAnalyzedSize + 20] == 0x02) //if that is the case it's a close dialog and there is no need to answer it
			{
				if (bInsideKn)//otherwise this packet is sent when bot  interacts with tp npc
				{
					waitForS_INVEN_Update = 1;
					HandleUndecipheredPacket(size08x08, C_SHOW_INVEN, { 0x01, 0x00, 0x00, 0x00 }, socket);
				}
			}
			else if (vNpc_Menu_SelectionLatest == vNpc_Menu_Selection1stStage)
			{
				cout << "you got here" << endl;
				TempVec = vInterractNpcDialogId_1;
				TempVec.push_back(01);
				TempVec.push_back(00);
				TempVec.push_back(00);
				TempVec.push_back(00);
				for (int uuu = 0; uuu < 8; ++uuu)
					TempVec.push_back(0xFF);
				HandleUndecipheredPacket(size20x14, C_DIALOG, TempVec, socket);//sends the size 20 C_DIALOG packet
				TempVec.clear();
				TempVec = vInterractNpcDialogId_1;
				TempVec.push_back(02);//Forms close dialog vector
				for (int uuu = 0; uuu < 7; ++uuu)
					TempVec.push_back(00);
				HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket); //2 samples get sent here.
				HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);

			}
			if (vNpc_Menu_SelectionLatest == vNpc_Menu_Selection2ndStage)
			{
				if (!flagonce)
					//HandleUndecipheredPacket(size32x20, C_REQUEST_CONTRACT, vRequestContractKn, socket);
					contractPtr = boost::shared_ptr<Contracts>(new Contracts(0x01, vectArgument, socket));
				flagonce = 1;
			}
		}
	}
}
void ReplyToArbiterContract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	ofstream file1("logs debug");
	if (!(Mystic.m_vMysticPartner.empty() || Mystic.m_vWatcher.empty() || Mystic.m_vMysticPartner2.empty()))
	{
		file1 << "all mystic name vectors are filled" << endl;
		std::vector <unsigned char> TempVec;
		std::vector <unsigned char> ::iterator itera;
		itera = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vMysticPartner.begin(), Mystic.m_vMysticPartner.end());
		if (!Mystic.m_vMysticPartner.empty())
		if (Mystic.m_vMysticName != Mystic.m_vMysticPartner)//because both sender and receiver have their name in the request packet we make sure the reply doesn't involve the receiver's name
		if (itera != vectArgument.begin() + nAnalyzedSize + size)
		{
			TempVec.push_back(0x16);
			TempVec.push_back(0x00);
			for (int uuu = 0; uuu < 12; ++uuu)
			{
				TempVec.push_back(vectArgument[nAnalyzedSize + 10 + uuu]);
			}
			TempVec.push_back(0x01);//means accept contract
			for (int uuu = 0; uuu < 3; ++uuu)
				TempVec.push_back(0x00);
			TempVec.insert(TempVec.end(), Mystic.m_vMysticPartner.begin(), Mystic.m_vMysticPartner.end());
			TempVec.push_back(0x00);
			TempVec.push_back(0x00);
			int vSize = 4 + TempVec.size();
			//Sleep(2000);
			HandleUndecipheredPacket(vSize, C_REPLY_THROUGH_ARBITER_CONTRACT, TempVec, socket);
		}
		std::vector <unsigned char> ::iterator itera2 = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vMysticPartner2.begin(), Mystic.m_vMysticPartner2.end());
		if (!Mystic.m_vMysticPartner2.empty())
			if (Mystic.m_vMysticName != Mystic.m_vMysticPartner2)
			if (itera2 != vectArgument.begin() + nAnalyzedSize + size)
			{
			TempVec.push_back(0x16);
			TempVec.push_back(0x00);
			for (int uuu = 0; uuu < 12; ++uuu)
			{
				TempVec.push_back(vectArgument[nAnalyzedSize + 10 + uuu]);
			}
			TempVec.push_back(0x01);//means accept contract
			for (int uuu = 0; uuu < 3; ++uuu)
				TempVec.push_back(0x00);
			TempVec.insert(TempVec.end(), Mystic.m_vMysticPartner2.begin(), Mystic.m_vMysticPartner2.end());
			TempVec.push_back(0x00);
			TempVec.push_back(0x00);
			int vSize = 4 + TempVec.size();
			//Sleep(2000);
			HandleUndecipheredPacket(vSize, C_REPLY_THROUGH_ARBITER_CONTRACT, TempVec, socket);
			}
		std::vector <unsigned char> ::iterator itera3 = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vWatcher.begin(), Mystic.m_vWatcher.end());
		if (!Mystic.m_vWatcher.empty())
		if (Mystic.m_vMysticName != Mystic.m_vWatcher)
		if (itera3 != vectArgument.begin() + nAnalyzedSize + size)
		{
			TempVec.push_back(0x16);
			TempVec.push_back(0x00);
			for (int uuu = 0; uuu < 12; ++uuu)
			{
				TempVec.push_back(vectArgument[nAnalyzedSize + 10 + uuu]);
			}
			TempVec.push_back(0x01);//means accept contract
			for (int uuu = 0; uuu < 3; ++uuu)
				TempVec.push_back(0x00);
			TempVec.insert(TempVec.end(), Mystic.m_vWatcher.begin(), Mystic.m_vWatcher.end());
			TempVec.push_back(0x00);
			TempVec.push_back(0x00);
			int vSize = 4 + TempVec.size();
			//Sleep(2000);
			HandleUndecipheredPacket(vSize, C_REPLY_THROUGH_ARBITER_CONTRACT, TempVec, socket);
		}
	}
	else
	{
		file1 << "no mystic name vector is filled" << endl;
	}
}
void ReplyToAcceptContract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	if (!contractPtr)
	{
		contractPtr = boost::shared_ptr<Contracts>(new Contracts(0x03, vectArgument, socket));
	}
	cout << "replied" << endl;
}
void ConfirmS_REQUEST_CONTRACT (uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	//Checks if this packet is addressed to the bot : 
	auto it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.m_vId.begin(), Mystic.m_vId.end());
	if (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
		cout << "Confirm Request Contract" << endl;
		if (contractPtr)
		{
			contractPtr->ReplyToS_Request_Contract(size, title, vectArgument, socket);
			contractPtr.reset();
		}
		else
		{
			if (!(vContractId.empty()))
				vContractId.clear();
			for (int uuu = 28; uuu < 36; ++uuu)
			{
				vContractId.push_back(vectArgument[uuu + nAnalyzedSize]);
			}
			if (!vAddBasketItems.empty())
				vAddBasketItems.clear();
			for (int uuu = 12; uuu < 20; ++uuu)
				vAddBasketItems.push_back(vectArgument[uuu + nAnalyzedSize]);
			for (int uuu = 32; uuu < 36; ++uuu)
				vAddBasketItems.push_back(vectArgument[uuu + nAnalyzedSize]);
		}
		cout << "contract confirmed" << endl;
	}
}
void ReplyToDialogClose(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{

	std::vector<unsigned char> TempVec;
	if (!(vInterractNpcDialogId_3.empty()))
	vInterractNpcDialogId_3.clear();
	for (int uuu = 4; uuu < 8; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
		vInterractNpcDialogId_3.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	TempVec.push_back(02);//Forms close dialog vector
	for (int uuu = 0; uuu < 7; ++uuu)
		TempVec.push_back(00); 
	Mystic.m_vDialogVectorEnd.clear();
	Mystic.m_vDialogVectorEnd = TempVec;
	Sleep(900);//1100  12.04.16
	HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket); //3x close dialog here
	Mystic.m_bSendDialogEnd = 1;
	/* patch 12.04.16
	Sleep(200);//was 5200
	HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);
	Sleep(200);
	HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);
	*/
}
void ReplyToCompletedMissionInfo (uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector<unsigned char> TempVec;
	if (nNumerOfRuns == 0)
	{

	}
	else
	{
		if ((!(vInterractNpcDialogId_1.empty())) && (((nNumerOfRuns + nBotNumber) % 2) == 0))
		{
			TempVec = vInterractNpcDialogId_1;
			TempVec.push_back(02);//Forms close dialog vector
			for (int uuu = 0; uuu < 7; ++uuu)
				TempVec.push_back(00);
			HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket);
		}
		if ((!vInterractNpcDialogId_1.empty()) && (((nNumerOfRuns + nBotNumber + 1) % 2) == 0))
		{

			TempVec = vInterractNpcDialogId_1;
			TempVec.push_back(02);//Forms close dialog vector
			for (int uuu = 0; uuu < 7; ++uuu)
				TempVec.push_back(00);
			HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket); //2 samples get sent here.
		}
	}
}
void ManageSales(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	if (size > 5000)
	ReleaseAllItemSellPointers();
	cout << "filtering S_INVEN" << endl;
	std::vector <unsigned char> TempVec;
//retrieves gold amount from inventory
	Mystic.m_nGoldInventory = TurnVectInto32_int(vectArgument, 16, nAnalyzedSize);
	Mystic.m_nGoldInventory = Mystic.m_nGoldInventory / 10000;
	//retrieves items to sell structure
	if (!TempVec.empty())
		TempVec.clear();
	/* //deprecated since Dawnfall patch, we instead use Mystic.vm_Id that holds character vector
	for (int uuu = 73; uuu < 76; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	auto it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, TempVec.begin(), TempVec.end());
	*/
	auto it = std::search(vectArgument.begin() + nAnalyzedSize, vectArgument.begin() + nAnalyzedSize + size, Mystic.vm_Id.begin(), Mystic.vm_Id.end());
	while (it != (vectArgument.begin() + nAnalyzedSize + size))
	{
	if ((((*(it + 8)) >= 0x48 ) && ((*(it + 8)) <= 0x67)) && (it != vectArgument.end()))//finds out if emplacement matches
	{ //extract emplacement, Id and amount of said item
		int nPlace = (*(it + 8));
		int nId = ((*(it - 12)) | ((*(it - 11) << 8)) | (*(it - 10) << 16) | (*(it - 9) << 24));
		int nAmount = ((*(it + 16)) | ((*(it + 17) << 8)) | (*(it + 18) << 16) | (*(it + 19) << 24));
		if  (!vAddBasketItems.empty())
		{ 
			cout << "you got there ### " << endl;
		if ((!ptrSellItem1))
			ptrSellItem1 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem2)
			ptrSellItem2 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem3)
			ptrSellItem3 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem4)
			ptrSellItem4 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem5)
			ptrSellItem5 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem6)
			ptrSellItem6 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem7)
			ptrSellItem7 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem8)
			ptrSellItem8 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem9)
			ptrSellItem9 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem10)
			ptrSellItem10 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem11)
			ptrSellItem11 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem12)
			ptrSellItem12 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem13)
			ptrSellItem13 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem14)
			ptrSellItem14 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem15)
			ptrSellItem15 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem16)
			ptrSellItem16 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem17)
			ptrSellItem17 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem18)
			ptrSellItem18 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem19)
			ptrSellItem19 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem20)
			ptrSellItem20 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem21)
			ptrSellItem21 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem22)
			ptrSellItem22 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem23)
			ptrSellItem23 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem24)
			ptrSellItem24 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem25)
			ptrSellItem25 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem26)
			ptrSellItem26 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem27)
			ptrSellItem27 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem28)
			ptrSellItem28 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem29)
			ptrSellItem29 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem30)
			ptrSellItem30 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem31)
			ptrSellItem31 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else if (!ptrSellItem32)
			ptrSellItem32 = boost::shared_ptr <ItemsToSell>(new ItemsToSell(vAddBasketItems, nId, nAmount, nPlace));
		else
			cout << "#### All the Item Sell Pointers are currently occupied ####" << endl;
		}

	}
	it = std::search(it + 1, vectArgument.begin() + nAnalyzedSize + size, Mystic.vm_Id.begin(), Mystic.vm_Id.end());
	}
	cout << "filtered." << endl;
	if (waitForS_INVEN_Update == 1)
		waitForS_INVEN_Update = 2;
}
void ReplyToDungeonCoolTime (uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;
	if (size == 12)
	{ 
	for (int uuu = 4; uuu < 12; ++uuu)
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	if (TempVec == vEmptyDefaultVector)
	{
		nDungeonsClear = 1;
	}
	else
		nDungeonsClear = 0;
	}
	if (size == 26)
	{
		if (!TempVec.empty())
		TempVec.clear();
		for (int uuu = 16; uuu < 18; ++uuu)
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
			if (TempVec == KnDungeonIdVector)
				nDungeonsClear = 0;
			else
				nDungeonsClear = 1;
	}
	if (size == 40)
	{
		if (!TempVec.empty())
			TempVec.clear();
		for (int uuu = 30; uuu < 32; ++uuu)
			TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
		if (TempVec == KnDungeonIdVector)
			nDungeonsClear = 0;
		else
			nDungeonsClear = 1;
	}
}
string filename2 = "Bot session User detection.txt";
//filename = "BotLog1.txt";
ofstream fileUserout(filename2.c_str());
void HandleUserSpawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	std::vector<unsigned char> PlayerVecName;
	for (int uuu = 264; uuu < 294; ++uuu)//306 was 290 before brawler patch 276 => 264 29.09.16
		PlayerVecName.push_back(vectArgument[uuu + nAnalyzedSize]);
	std::vector<unsigned char> PlayerVecId;
	for (int uuu = 38; uuu < 46; ++uuu)
		PlayerVecId.push_back(vectArgument[uuu + nAnalyzedSize]);
	//
	for (int kkk = 0; kkk < 8; ++kkk)
	{
		printf("0x%02X", PlayerVecId[kkk]);
		std::cout << " ";
	}
	//
	std::cout << std::endl;
	if (!(IsThisPlayerFriendly(PlayerVecName)))
	InitializeAPlayerId(PlayerVecId);
	if (!PlayerSafe)
	{
		char array[60] = "Player detected ";
		fileUserout << "Player detected : ";
		for (int uuu = 264; uuu < 285; ++uuu)
		{
			fileUserout << vectArgument[nAnalyzedSize + uuu];
			array[17 + uuu] = vectArgument[nAnalyzedSize + uuu];
		}
		fileUserout << " Tagged as ennemy.";
		fileUserout << endl;
		
		if (!bWatcher)
		{
			HWND hwnd2 = NULL;
			std::async(MessageBox, hwnd2, (LPCSTR)"Mystic saw a player", (LPCSTR)("Player detected"), 0X0L);
		}
		
	}
}

void FollowNearbyUser(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket) {
	int UserCurrentX = ((vectArgument[12 + nAnalyzedSize]) | (vectArgument[13 + nAnalyzedSize] << 8) | ((vectArgument[14 + nAnalyzedSize]) << 16) | (vectArgument[15 + nAnalyzedSize] << 24));
	int UserCurrentY = ((vectArgument[16 + nAnalyzedSize]) | (vectArgument[17 + nAnalyzedSize] << 8) | ((vectArgument[18 + nAnalyzedSize]) << 16) | (vectArgument[19 + nAnalyzedSize] << 24));
	int UserCurrentZ = ((vectArgument[20 + nAnalyzedSize]) | (vectArgument[21 + nAnalyzedSize] << 8) | ((vectArgument[22 + nAnalyzedSize]) << 16) | (vectArgument[23 + nAnalyzedSize] << 24));
	int WP_X = UserCurrentX;
	int WP_Y = UserCurrentY;
	int WP_Z = UserCurrentZ;
	while (WP_X != currentX)
	{
		MovementPacket2 = ForMovementPacket(WP_X, WP_Y, WP_Z);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(20);
	}

}
void ReplyToSUserLocation(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	std::vector <unsigned char> TempVec;//Puts the despawning mob Id into TempVec
	for (int uuu = 4; uuu < 12; ++uuu)
	{
		TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	long long llId;
	memcpy(&llId, &TempVec[0], sizeof(llId));
	std::map < long long, boost::shared_ptr < Players>>::iterator iit = PlayersMapSavedPointer.find(llId);
	if (iit != PlayersMapSavedPointer.end())
	{
		if (PlayersMapSavedPointer.find(llId)->second)
		{
			if (PlayersMapSavedPointer.find(llId)->second->m_bOrderedToFollow == 1)
			{
				cout << "###################################################### !!" << endl;
				FollowNearbyUser(size, title, vectArgument, socket);
			}
			else
				cout << "llId and pointer were found but there ordertofollow is set to 0" << endl;
		}
		else
			cout << "llId was found on map but there were no associated pointer" << endl;
	}
	else
		cout << "llId wasn't found on map" << endl;
}
void ReplyToInstantMove(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	if (bTpHack)
	{
	Sleep(50);
	std::vector <unsigned char> vLocationAction2 = FormNotifyActionLocationPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
	HandleUndecipheredPacket(size26x1a, C_NOTIFY_LOCATION_IN_ACTION, vLocationAction2, socket);
	while (wantedXForEaxKnFeetInt != currentX)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(450);
	}
	bTpHack = 0;
	}
}

void HandleUserDeSpawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	std::vector<unsigned char> PlayerVecId;
	for (int uuu = 4; uuu < 12; ++uuu)
		PlayerVecId.push_back(vectArgument[uuu + nAnalyzedSize]);
	RemoveAPlayerId(PlayerVecId);
}
void SpawnMe(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket)
{
	currentX = ((vectArgument[12 + nAnalyzedSize]) | (vectArgument[13 + nAnalyzedSize] << 8) | ((vectArgument[14 + nAnalyzedSize]) << 16) | (vectArgument[15 + nAnalyzedSize] << 24));
	currentY = ((vectArgument[16 + nAnalyzedSize]) | (vectArgument[17 + nAnalyzedSize] << 8) | ((vectArgument[18 + nAnalyzedSize]) << 16) | (vectArgument[19 + nAnalyzedSize] << 24));
	currentZ = ((vectArgument[20 + nAnalyzedSize]) | (vectArgument[21 + nAnalyzedSize] << 8) | ((vectArgument[22 + nAnalyzedSize]) << 16) | (vectArgument[23 + nAnalyzedSize] << 24));
	cout << "current X Y Z : " << currentX << " " << currentY << " " << currentZ << endl;
	//Port under ground at Kn entrance :
	if (currentZ == 0x46103718)
	{
		currentX = wantedXEnterKnDungeon;
		currentY = wantedYEnterKnDungeon;
		currentZ = wantedZEnterKnDungeon;
	}
	// 02.11.16 GoToTheseCoordonateAtThisSpeed(450, currentX, currentY, currentZ, socket);
	MovementPacket2 = ForMovementPacket(currentX, currentY, currentZ);
	HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
	if (currentX == 0x47749d00)
		bInsideKn = 1;
	else
		bInsideKn = 0;
}
void ReadPacket(boost::asio::ip::tcp::socket &socket, std::vector <unsigned char > & vectReceptionArg) {
	 nAnalyzedSize = 0;
	 try{
		 cout << "will read.." << endl;
	 length = socket.read_some(boost::asio::buffer(vectReception), error_2);
	 cout << "read :" << length << " bytes." << endl;
	 if (length == 0)
	 {
		 cout << "Connection Terminated by Server." << endl;
		 mtx_lockHandlePackets.lock();
		 Sleep(36000000);
	 }
	 }
	 catch (std::exception & ec1)
	 {
		 std::cerr << ec1.what() << endl;
	 }

	 try {
		oo = vectReception.begin();
		ptrReceivedPacket = &(*oo);
		int ooo = 0;
		while ((EncryptionOrDecryptionBusy))
		{
			++ooo;
			Sleep(10);
			if (ooo <= 15)
				cout << "Encryption is busy" << endl;
		}
		EncryptionOrDecryptionBusy = 1;
		cout << "will decrypt " << endl;
		DecryptionCaller_016b8070(ptrReceivedPacket, length);
		EncryptionOrDecryptionBusy = 0;
		cout << "decrypted" << endl;
	 }
	 catch (std::exception & ec2)
	 {
		 std::cerr << ec2.what() << endl;
	 }
	 uint16_t rPsize = ((vectReceptionArg[nAnalyzedSize]) | (vectReceptionArg[nAnalyzedSize + 1] << 8));
	 //std::cout << "\nSize is : " << rPsize << endl;
	 uint16_t rTitle = ((vectReceptionArg[nAnalyzedSize + 2]) | (vectReceptionArg[nAnalyzedSize + 3] << 8));
	 //std::cout << "Title is : " << rTitle << endl;
		iteration=0;
		while (nAnalyzedSize < length)
		{
			if ((iteration > 6000) | errorflag)
			{
				errorflag = 1;
				cout << "There was an error in the analyzing loop : length trackdown : " << length_trackdown<< endl;
				if (iteration > 500)
				{
					length_trackdown = length;
				}
			}
			rPsize = ((vectReceptionArg[nAnalyzedSize]) | (vectReceptionArg[nAnalyzedSize + 1] << 8));
			rTitle = ((vectReceptionArg[nAnalyzedSize + 2]) | (vectReceptionArg[nAnalyzedSize + 3] << 8));
			while (rPsize > (length - nAnalyzedSize)) // if the decrypted packet is larger than the received one, it cannot be analyzed yet
			{
				cout << "high size." << endl;
				cout << "will read.." << endl;
				int length2 = socket.read_some(boost::asio::buffer(vectReception2), error_2);
	 if (length2 == 0)
	 {
		 cout << "Connection Terminated by Server." << endl;
		 mtx_lockHandlePackets.lock();
		 Sleep(36000000);
	 }
				cout << "read :" << length2 << " bytes." << endl;
				cout << "The packet received was too small : The received packet size was : " << length2 << " and rPsize : " << rPsize << endl;
				oo = vectReception2.begin();
				ptrReceivedPacket = &(*oo);
				int ooo = 0;
				while ((EncryptionOrDecryptionBusy))
				{
					++ooo;
					Sleep(10);
					if (ooo <= 15)
						cout << "Encryption is busy" << endl;
				}
				EncryptionOrDecryptionBusy = 1;
				cout << "will decrypt " << endl;
				DecryptionCaller_016b8070(ptrReceivedPacket, length2);
				EncryptionOrDecryptionBusy = 0;
				cout << "decrypted" << endl;
				//change iterator after decryption
				oo = vectReception.end();
				//vectReception.insert(oo, vectReception2.begin(), vectReception2.end());
				for (int uuu = 0; uuu < length2; ++uuu)
				{
					vectReception[length + uuu] = vectReception2[uuu];
				}
				//update new length
				length += length2;
				rPsize = ((vectReceptionArg[nAnalyzedSize]) | (vectReceptionArg[nAnalyzedSize + 1] << 8));//these lines' purpose is in case only 1 byte received excess the last processed packet
				rTitle = ((vectReceptionArg[nAnalyzedSize + 2]) | (vectReceptionArg[nAnalyzedSize + 3] << 8));
			}
			try {
				cout << "will analyze data." << endl;
				ProcessUndecryptedPacketData(socket, rPsize, rTitle, vectReceptionArg, length); //call a function that will process information    // make sure this call is before nAnalyzedSize gets incremented
				nAnalyzedSize += rPsize;
				++iteration;
			}
			catch (std::exception & ec3)
			{
				std::cerr << ec3.what() << endl;
			}
		}
		cout << "Finished analyzing data." << endl;
}

PacketReception::PacketReception() {

}

void HandlePacketReception(boost::shared_ptr<boost::asio::ip::tcp::socket> socket){
//	PacketReception ReceptionObject();
	errorflag = 0;
	while (1)
	{
		try{
		//vectReception.clear();//added 09.02.16
		ReadPacket(*socket, vectReception);
		Sleep(10); // from 80 to 50 on 18.10.15 then 30 then 10
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}

void SpamPartyChat(boost::shared_ptr<boost::asio::ip::tcp::socket> socket){
	while (1)
	{
		try{
			HandleUndecipheredPacket(size96x60, C_CHAT, { 0x60, 0x00, 0xF8, 0x70, 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x74, 0x00, 0x68, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x69, 0x00, 0x73, 0x00, 0x20, 0x00, 0x61, 0x00, 0x20, 0x00, 0x73, 0x00, 0x69, 0x00, 0x6D, 0x00, 0x70, 0x00, 0x6C, 0x00, 0x65, 0x00, 0x20, 0x00, 0x6D, 0x00, 0x65, 0x00, 0x73, 0x00, 0x73, 0x00, 0x61, 0x00, 0x67, 0x00, 0x65, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
			Sleep(10); // from 80 to 50 on 18.10.15 then 30 then 10
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}