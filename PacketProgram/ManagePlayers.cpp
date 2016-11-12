#include "ManagePlayers.h"
#include <ctime>
#include <vector>
#include <iostream>
#include "PacketReception.h"
#include "ConfigFile.h"
// ==================================== Friends
std::vector<unsigned char> Tryvire = { 0x54, 0x00, 0x72, 0x00, 0x79, 0x00, 0x76, 0x00, 0x69, 0x00, 0x72, 0x00, 0x65, 0x00 };//ends by 00  // 14 bytes
std::vector<unsigned char> Malua = { 0x4D, 0x00, 0x61, 0x00, 0x6C, 0x00, 0x75, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00 };
//
time_t tCleared;
bool PlayerSafe(1);
int vecSize = 8;
std::vector<unsigned char> vPlayer1;
std::vector<unsigned char> vPlayer2;
std::vector<unsigned char> vPlayer3;
std::vector<unsigned char> vPlayer4;
std::vector<unsigned char> vPlayer5;
std::vector<unsigned char> vPlayer6;
std::vector<unsigned char> vPlayer7;
std::vector<unsigned char> vPlayer8;
std::vector<unsigned char> vPlayer9;
std::vector<unsigned char> vPlayer10;
std::map < long long, boost::shared_ptr < Players>> PlayersMapSavedPointer;
int Players::s_nRegisteredPlayers = 1;
void Players::SaveNewPlayerPointer(boost::shared_ptr <Players> & PlayerPtrArg)
{
	//check if second already exist and release it if so
	PlayersMapSavedPointer[PlayerPtrArg->m_llId] = PlayerPtrArg;
	if (PlayerPtrArg->m_llId2)
		PlayersMapSavedPointer[PlayerPtrArg->m_llId2] = PlayerPtrArg;
	else
		std::cout << "MMM>>>> NO <<<<<" << std::endl;
	PlayersMapSavedPointer[PlayerPtrArg->m_llId2] = PlayerPtrArg;
	if (PlayerPtrArg->m_llId3)
		PlayersMapSavedPointer[PlayerPtrArg->m_llId3] = PlayerPtrArg;
	else
		std::cout << "MMM>>>> NO <<<<<" << std::endl;
	if (PlayerPtrArg->m_llId4)
		PlayersMapSavedPointer[PlayerPtrArg->m_llId4] = PlayerPtrArg;
	else
		std::cout << "MMM>>>> NO <<<<<" << std::endl;
	if (PlayerPtrArg->m_llId5)
		PlayersMapSavedPointer[PlayerPtrArg->m_llId5] = PlayerPtrArg;
	else
		std::cout << "MMM>>>> NO <<<<<" << std::endl;
}
bool CompareWithFriends(std::vector <unsigned char> & PlayerVecName, std::vector <unsigned char> &vectArgument) {
	auto it = std::search(PlayerVecName.begin(), PlayerVecName.end(), vectArgument.begin(), vectArgument.end());
	if (it != PlayerVecName.end())
	{
		PlayerSafe = 1;
		return true;
	}
	else
		return false;
}
bool IsThisPlayerFriendly(std::vector<unsigned char> & PlayerVecName)
{
	PlayerSafe = 0;
	bool FriendResult;
	if (!vfriend1.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend1);
	if (!vfriend2.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend2);
	if (!vfriend3.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend3);
	if (!vfriend4.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend4);
	if (!vfriend5.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend5);
	if (!vfriend6.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend6);
	if (!vfriend7.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend7);
	if (!vfriend8.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend8);
	if (!vfriend9.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend9);
	if (!vfriend10.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend10);
	if (!vfriend11.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend11);
	if (!vfriend12.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend12);
	if (!vfriend13.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend13);
	if (!vfriend14.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend14);
	if (!vfriend15.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend15);
	if (!vfriend16.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend16);
	if (!vfriend17.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend17);
	if (!vfriend18.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend18);
	if (!vfriend19.empty())
		FriendResult = CompareWithFriends(PlayerVecName, vfriend19);
	if (PlayerSafe)
	{
		return true;
	}
	else
	{
		std::cout << "Non-Friendly Player around." << std::endl;
		PlayerSafe = 0;
		return false;
	}
}
void IsThisSafeToBot() {
	if (vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty() && vPlayer1.empty())
		PlayerSafe = 1;
	else
		PlayerSafe = 0;
}
void InitializeAPlayerId(std::vector<unsigned char> & PlayerID) {
	if (vPlayer1.empty())
	{
		vPlayer1 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
		++nNumberOfEnnemies;
	}
	else if (vPlayer2.empty())
	{
		vPlayer2 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer3.empty())
	{
		vPlayer3 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer4.empty())
	{
		vPlayer4 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer5.empty())
	{
		vPlayer5 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer6.empty())
	{
		vPlayer6 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer7.empty())
	{
		vPlayer7 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer8.empty())
	{
		vPlayer8 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer9.empty())
	{
		vPlayer9 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else if (vPlayer10.empty())
	{
		vPlayer10 = PlayerID;
		if (nNumberOfEnnemies <= 0)
			nNumberOfEnnemies = 1;
		else
			++nNumberOfEnnemies;
	}
	else
		std::cout << "not enough player vectors to register this new ID." << std::endl;
	std::cout << "initialisation : " << std::endl;
	for (int kkk = 0; kkk < 8; ++kkk)
	{
		printf("0x%02X", vPlayer1[kkk]);
		std::cout << " ";
	}
	std::cout << std::endl;
	for (int kkk = 0; kkk < 8; ++kkk)
	{
		printf("0x%02X", PlayerID[kkk]);
		std::cout << " ";
	}
	std::cout << std::endl;
}
void RemoveAPlayerId(std::vector<unsigned char> & PlayerID) {
	if (vPlayer1 == PlayerID)
	{
		vPlayer1.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer2 == PlayerID)
	{
		vPlayer2.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer3 == PlayerID)
	{
		vPlayer3.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer4 == PlayerID)
	{
		vPlayer4.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer5 == PlayerID)
	{
		vPlayer5.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer6 == PlayerID)
	{
		vPlayer6.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer7 == PlayerID)
	{
		vPlayer7.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer8 == PlayerID)
	{
		vPlayer8.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer9 == PlayerID)
	{
		vPlayer9.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else if (vPlayer10 == PlayerID)
	{
		vPlayer10.clear();
		if (nNumberOfEnnemies > 0)
			--nNumberOfEnnemies;
		else
			nNumberOfEnnemies = 0;

	}
	else
		std::cout << "COULD NOT IDENTIFY THE PLAYER LEAVING. !" << std::endl;
}

void RemoveAllPlayerId() {
	if (!vPlayer1.empty())
	{
		vPlayer1.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer2.empty())
	{
		vPlayer2.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer3.empty())
	{
		vPlayer3.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer4.empty())
	{
		vPlayer4.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer5.empty())
	{
		vPlayer5.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer6.empty())
	{
		vPlayer6.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer7.empty())
	{
		vPlayer7.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer8.empty())
	{
		vPlayer8.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer9.empty())
	{
		vPlayer9.clear();
		--nNumberOfEnnemies;

	}
	if (!vPlayer10.empty())
	{
		vPlayer10.clear();
		--nNumberOfEnnemies;

	}
	nNumberOfEnnemies = 0;
}
int KeepOnWaitingSafety() {
	time_t tCurrentTime = time(0);
	int timeWaited = difftime(tCurrentTime, tCleared);
	if (timeWaited <= 1200)
		return 1;
	else
		return 0;
}
void PlayerJustLeft()
{
	tCleared = time(0);
}