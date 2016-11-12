#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
//#include <cstdlib>
#include <string.h>
#include <math.h>
#include <ctime>
#include <vector>
#include "BotClass.h"
#include "UseSkills.h"
#define PI 3.14159265
#include "Packet.h"
#include "Contracts.h"
#include "ItemInterraction.h"
#include "Waypoint.h"
#include "BotClass.h"
#include "ConfigFile.h"
#include "Packet.h"
#include <ctime>
Bot Mystic;
int resetTimer_2;
int ResumeAfterCd_2(0);
time_t currentTime2;
time_t thrallTime;
int nNumerOfRuns(0);

void PartyInvite(std::vector<unsigned char> & vectArgument, boost::asio::ip::tcp::socket & socket) {//this function creates a fake send partyinvite first to take a peek at the needed size.
	contractPtr = boost::shared_ptr<Contracts>(new Contracts(Contracts::NullContract, vectArgument, socket));
	std::vector <unsigned char> TempVec;
	TempVec = vPartyInvite; //{ 0x1A, 0x00, 0x26, 0x00, 0x01, 0x00, 0x04, 0x00 };
	for (int uuu = 0; uuu < 14; ++uuu)
		TempVec.push_back(00);
	TempVec.insert(TempVec.end(), vectArgument.begin(), vectArgument.end());
	for (int uuu = 0; uuu < 3; ++uuu)
		TempVec.push_back(00);
	int nSize = TempVec.size() + 4;
	//HandleUndecipheredPacket(nSize, C_REQUEST_CONTRACT, TempVec, socket);
	std::vector <unsigned char> TempVec2;
	TempVec2 = { 0x1A, 0x00 };
	Turnuint16_t_tIntoVect_rvalue((TempVec.size())+4 - 1, TempVec2);
	TempVec2.push_back(0x01);
	TempVec2.push_back(0x00);
	TempVec2.push_back(0x04);
	TempVec2.push_back(0x00);
	for (int uuu = 0; uuu < 14; ++uuu)
		TempVec2.push_back(00);
	TempVec2.insert(TempVec2.end(), vectArgument.begin(), vectArgument.end());
	for (int uuu = 0; uuu < 3; ++uuu)
		TempVec2.push_back(00);
	nSize = TempVec2.size() + 4;
	HandleUndecipheredPacket(nSize, C_REQUEST_CONTRACT, TempVec2, socket);
}
void EnterDungeonWhenReady(boost::asio::ip::tcp::socket & socket) {
	/*
	HandlePacket(size04x04, C_DUNGEON_COOL_TIME_LIST, socket);
	Sleep(500);
	do //(!nDungeonsClear)
	{
		Sleep(1000);
		std::cout << "Dungeon on cooldown." << std::endl;
		HandlePacket(size04x04, C_DUNGEON_COOL_TIME_LIST, socket);
	} while (0); // keeps the former skeleton code
	*/
	//commented the code above on 12.04.16
	do //makes sure it wont try to interract while being far from Kn Tp Npc
	{
		MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	} while ((wantedXEnterKnDungeon != currentX) && (bInsideKn != 1));
	vNpc_Menu_SelectionLatest.clear(); // makes clean entrances
	HandleUndecipheredPacket(size12x0C, C_NPC_CONTACT, vInterractKnNpc, socket);
}
int timersUsa()
{
	int nTimeWaited(0);
	if (!(nNumerOfRuns == 0))
	{
		currentTime2 = time(0);
		resetTimer_2 = difftime(currentTime2, thrallTime);
		//these are here so that we don't necessarily enter the loop and therefore sometimes lose a second
		while (resetTimer_2 <= (nThrallCD-1)) // 214
		{
			currentTime2 = time(0);
			resetTimer_2 = difftime(currentTime2, thrallTime);
			ResumeAfterCd_2 = nThrallCD - resetTimer_2;//215 eu
			std::cout << "Thrall timer ! Bot will resume in : " << ResumeAfterCd_2 << std::endl;
			++nTimeWaited;
			Sleep(1000);
		}
	}
	thrallTime = time(0);
	return nTimeWaited;
}
void timerPowerLevel()
{
		currentTime2 = time(0);
		resetTimer_2 = difftime(currentTime2, thrallTime);
		//these are here so that we don't necessarily enter the loop and therefore sometimes lose a second
		while (resetTimer_2 <= (11 - 1)) // 10
		{
			currentTime2 = time(0);
			resetTimer_2 = difftime(currentTime2, thrallTime);
			ResumeAfterCd_2 = 11 - resetTimer_2;//215 eu
			std::cout << "Thrall timer ! Bot will resume in : " << ResumeAfterCd_2 << std::endl;
			Sleep(1000);
		}
}