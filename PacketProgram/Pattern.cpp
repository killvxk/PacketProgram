#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream> 
//file includes == Warning == always include those last.
#include "Packet.h"
#include "PacketReception.h"
#include "PacketData.h"
#include "Waypoint.h"
#include "UseSkills.h"
#include "ItemInterraction.h"
#include "MonsterInterraction.h"
#include "BotClass.h"
#include "DataFileSaving.h"
#include "DllInject.h"
#include "ConfigFile.h"
#include <thread>
#include <ctime>
void DealWithEnnemiesDuringPlvl(boost::shared_ptr<boost::asio::ip::tcp::socket> socket, int nWantedZHide)
{
	int savedX = currentX;
	int savedY = currentY;
	int savedZ = currentZ;
	Sleep(1000);//in case it matters
	while (nWantedZHide != currentZ)
	{
		MovementPacket2 = ForMovementPacket(currentX, currentY, nWantedZHide);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}

	//	GoToTheseCoordonateAtThisSpeed(Mystic.m_nSpeed, currentX -1, currentY, 0x45579000, *socket);
	cout << "there is : " << nNumberOfEnnemies << " ennemies." << endl;
	Sleep(60000);
	while (nNumberOfEnnemies)
	{
		cout << "there is : " << nNumberOfEnnemies << " ennemies." << endl;
		Sleep(1000);
	}
	//go back
	while (savedZ != currentZ)
	{
		MovementPacket2 = ForMovementPacket(savedX, savedY, savedZ);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
}
void DealWithEnnemiesDuringPlvl(boost::asio::ip::tcp::socket &socket, int nWantedZHide)
{
	int savedX = currentX;
	int savedY = currentY;
	int savedZ = currentZ;
	Sleep(1000);//in case it matters
	while (nWantedZHide != currentZ)
	{
		MovementPacket2 = ForMovementPacket(currentX, currentY, nWantedZHide);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}

	//	GoToTheseCoordonateAtThisSpeed(Mystic.m_nSpeed, currentX -1, currentY, 0x45579000, *socket);
	cout << "there is : " << nNumberOfEnnemies << " ennemies." << endl;
	Sleep(60000);
	while (nNumberOfEnnemies)
	{
		cout << "there is : " << nNumberOfEnnemies << " ennemies." << endl;
		Sleep(1000);
	}
	//go back
	while (savedZ != currentZ)
	{
		MovementPacket2 = ForMovementPacket(savedX, savedY, savedZ);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
}
void PowerLeveled(ofstream& fileout, boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
	int nCurrentLevel = Mystic.m_nLevel;
	while (1)
	{
		GoToTheseCoordonateAtThisSpeed(500, 0x4683ffe2, 0xc61e89c9, 0x4566c2c1, *socket);
		if (nCurrentLevel != Mystic.m_nLevel)
		{
			fileout << "Level up ! Bot is now level : " << Mystic.m_nLevel << endl;
			nCurrentLevel = Mystic.m_nLevel;
		}
		Sleep(50000);
	}
}
void PowerLevel(boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
	while (1)//(bPowerLevel) // arcane pulse pattern
	{
		if (nNumberOfEnnemies)
		{
			DealWithEnnemiesDuringPlvl(socket, 0x45579000);
		}
		cout << "-1" << endl;
		while (MonstersMapSavedPointerSelectedMonsters.size() == 0)
		{
			cout << "waiting, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
			Sleep(200);
			while ((nCentralPowerLevelX != currentX) && (MonstersMapSavedPointerSelectedMonsters.size() == 0))
			{
				if (nNumberOfEnnemies)
				{
					DealWithEnnemiesDuringPlvl(socket, 0x45579000);
				}
				MovementPacket2 = ForMovementPacket(nCentralPowerLevelX, nCentralPowerLevelY, nCentralPowerLevelZ);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
		}
		std::map <long long, boost::shared_ptr <Monsters>> ::iterator itlow;
		cout << "0" << endl;
		itlow = MonstersMapSavedPointerSelectedMonsters.begin();
		cout << "1" << endl;
		if (!itlow->second)
		{
			cout << "expecting a crash, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
			while (!itlow->second)
			{
				Sleep(100);
				itlow = MonstersMapSavedPointerSelectedMonsters.begin();
				cout << "Bot doesn't detect Teraliths, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
			}
		}
		else
			cout << "no crash, there is a pointer in the map and size is " << MonstersMapSavedPointerSelectedMonsters.size() << "\n" << endl;
		/*use this if you wanna load skill during movement
		getClosestMonster();
		timerPowerLevel();
		PressSkill cArcane;
		PressSkill::FormAndSendPressSkillPackets(socket);
		*/
		getClosestMonster();
		while (ptrMob1->m_X != currentX)
		{
			if (nNumberOfEnnemies)
			{
				DealWithEnnemiesDuringPlvl(socket, 0x45579000);
				itlow = MonstersMapSavedPointerSelectedMonsters.begin();
				getClosestMonster();
			}
			MovementPacket2 = ForMovementPacket(ptrMob1->m_X, ptrMob1->m_Y, ptrMob1->m_Z);
			HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
			Sleep(Mystic.m_nSpeed);
		}
		timerPowerLevel();
		PressSkill cArcane;
		PressSkill::FormAndSendPressSkillPackets(socket);
		int uuu = 0;
		while ((PressSkill::s_nStage < 4) && (uuu < 100))
		{
			++uuu;
			Sleep(50);
		}
		PressSkill::FormAndSendPressSkillPackets(socket);
		//timer starts
		int hhh = 0;
		while ((!ProjectilePtr) && (hhh < 100))
		{
			++hhh;
			Sleep(30);
		}
		if (ProjectilePtr)
		{
			thrallTime = time(0);//timer starts
			cout << "## itlow second still exist ? " << endl;
			cout << ptrMob1 << " ###" << endl;
			cout << "###########################################0#############################################" << endl;
			ProjectilePtr->FormPojectilePackets(ptrMob1);
			cout << "###########################################1#############################################" << endl;
			cout << "value of projectile pointer : " << ProjectilePtr << endl;
			if (!nNumberOfEnnemies)
			{
				ProjectilePtr->SendProjectileHitPacket(400, socket);
			}
			cout << "###########################################2#############################################" << endl;
			cout << "value of projectile pointer : " << ProjectilePtr << endl;
			ProjectilePtr->SendProjectileEndPacket(socket);
			cout << "###########################################3#############################################" << endl;
			ProjectilePtr.reset();
		}
		Sleep(2000); // so the despawn packet gets treated
	}

}


//###############################################


void PowerLevelNeedle(boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
	while (1) //ice needle loop
	{
		while (MonstersMapSavedPointerSelectedMonsters.size() == 0)
		{
			cout << "waiting, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
			Sleep(200);
		}
		std::map <long long, boost::shared_ptr <Monsters>> ::iterator itlow;
		cout << "0" << endl;
		itlow = MonstersMapSavedPointerSelectedMonsters.begin();
		cout << "1" << endl;
		if (!itlow->second)
			cout << "expecting a crash, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
		else
			cout << "no crash, there is a pointer in the map and size is " << MonstersMapSavedPointerSelectedMonsters.size() << "\n" << endl;
		getClosestMonster();
		cout << "-1" << endl;
		cout << "0" << endl;
		itlow = MonstersMapSavedPointerSelectedMonsters.begin();
		cout << "1" << endl;
		if (!itlow->second)
			cout << "expecting a crash, size of map is : " << MonstersMapSavedPointerSelectedMonsters.size() << endl;
		else
			cout << "no crash, there is a pointer in the map and size is " << MonstersMapSavedPointerSelectedMonsters.size() << "\n" << endl;
		vSendSkillPacket2 = FormSendSkillPacket(OverLoad);
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
		Sleep(1200);
		GoToTheseCoordonateAtThisSpeed(Mystic.m_nSpeed, ptrMob1->m_X, ptrMob1->m_Y, ptrMob1->m_Z, *socket);
		vSendSkillPacket2 = FormSendSkillPacketWithDest(iceNeedle, ptrMob1);
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
		int hhh = 0;
		while ((!ProjectilePtr) && (hhh < 100))
		{
			++hhh;
			Sleep(30);
		}
		if (ProjectilePtr)
		{
			//Sleep(300);
			cout << "## itlow second still exist ? " << endl;
			cout << ptrMob1 << " ###" << endl;
			cout << "###########################################0#############################################" << endl;
			ProjectilePtr->FormPojectilePackets(ptrMob1);
			cout << "###########################################1#############################################" << endl;
			thrallTime = time(0);//timer starts
			cout << "value of projectile pointer : " << ProjectilePtr << endl;
			if (!nNumberOfEnnemies)
			{
				ProjectilePtr->SendProjectileHitPacket(1200, socket);
			}
			cout << "###########################################2#############################################" << endl;
			cout << "value of projectile pointer : " << ProjectilePtr << endl;
			ProjectilePtr->SendProjectileEndPacket(socket);
			cout << "###########################################3#############################################" << endl;
			ProjectilePtr.reset();
		}
		int x;
		cin >> x;
	}
}