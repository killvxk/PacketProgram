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
#include <map>
#include <set>
#include <math.h>
#include <ctime>
#include <vector>
#include "BotClass.h"
#include "UseSkills.h"
#define PI 3.14159265
#include "Packet.h"
#include "ItemInterraction.h"
#include "Waypoint.h"

int nVMWA_ID = 0x000001BF;  //0x00025072;
int nMWA_ID = 0x000001BF;
int nBOX1_ID = 0x0002bb80;
int nBOX2_ID = 0x0002bb81;
int nCoupons = 0x000167AA;
const int nBecPhoenix = 0x045e;
const int nCoeurBete = 0x045f;
const int nTier5alk = 0x016ffd;
int nPanace = 0x81;
int nCOUPON_MODE_ID = 0x000167aa;
int nSPEED_POTION_ID = 0x00001f47;
std::set<int32_t> UnpickedItems = { nBOX1_ID, nBOX2_ID, nCoupons, nBecPhoenix, nCoeurBete, nTier5alk, nSPEED_POTION_ID, nPanace };
int inMoodForShop = 0;
int waitForS_INVEN_Update = 0;
boost::shared_ptr <Items> ptrItem1;
boost::shared_ptr <Items> ptrItem2;
boost::shared_ptr <Items> ptrItem3;
boost::shared_ptr <Items> ptrItem4;
boost::shared_ptr <Items> ptrItem5;
boost::shared_ptr <Items> ptrItem6;
boost::shared_ptr <Items> ptrItem7;
boost::shared_ptr <Items> ptrItem8;
boost::shared_ptr <Items> ptrItem9;
boost::shared_ptr <Items> ptrItem10;
boost::shared_ptr <Items> ptrItem11;
boost::shared_ptr <Items> ptrItem12;
boost::shared_ptr <Items> ptrItem13;
boost::shared_ptr <Items> ptrItem14;
boost::shared_ptr <Items> ptrItem15;
boost::shared_ptr <Items> ptrItem16;
boost::shared_ptr <Items> ptrItem17;
boost::shared_ptr <Items> ptrItem18;
boost::shared_ptr <Items> ptrItem19;
boost::shared_ptr <Items> ptrItem20;
boost::shared_ptr <Items> ptrItemClosest;

boost::shared_ptr <ItemsToSell> ptrSellItem1;
boost::shared_ptr <ItemsToSell> ptrSellItem2;
boost::shared_ptr <ItemsToSell> ptrSellItem3;
boost::shared_ptr <ItemsToSell> ptrSellItem4;
boost::shared_ptr <ItemsToSell> ptrSellItem5;
boost::shared_ptr <ItemsToSell> ptrSellItem6;
boost::shared_ptr <ItemsToSell> ptrSellItem7;
boost::shared_ptr <ItemsToSell> ptrSellItem8;
boost::shared_ptr <ItemsToSell> ptrSellItem9;
boost::shared_ptr <ItemsToSell> ptrSellItem10;
boost::shared_ptr <ItemsToSell> ptrSellItem11;
boost::shared_ptr <ItemsToSell> ptrSellItem12;
boost::shared_ptr <ItemsToSell> ptrSellItem13;
boost::shared_ptr <ItemsToSell> ptrSellItem14;
boost::shared_ptr <ItemsToSell> ptrSellItem15;
boost::shared_ptr <ItemsToSell> ptrSellItem16;
boost::shared_ptr <ItemsToSell> ptrSellItem17;
boost::shared_ptr <ItemsToSell> ptrSellItem18;
boost::shared_ptr <ItemsToSell> ptrSellItem19;
boost::shared_ptr <ItemsToSell> ptrSellItem20;
boost::shared_ptr <ItemsToSell> ptrSellItem21;
boost::shared_ptr <ItemsToSell> ptrSellItem22;
boost::shared_ptr <ItemsToSell> ptrSellItem23;
boost::shared_ptr <ItemsToSell> ptrSellItem24;
boost::shared_ptr <ItemsToSell> ptrSellItem25;
boost::shared_ptr <ItemsToSell> ptrSellItem26;
boost::shared_ptr <ItemsToSell> ptrSellItem27;
boost::shared_ptr <ItemsToSell> ptrSellItem28;
boost::shared_ptr <ItemsToSell> ptrSellItem29;
boost::shared_ptr <ItemsToSell> ptrSellItem30;
boost::shared_ptr <ItemsToSell> ptrSellItem31;
boost::shared_ptr <ItemsToSell> ptrSellItem32;
void getClosestItem();
std::vector <unsigned char> FormPickUpPacket()
{
	std::vector <unsigned char> PickUpItemVec;

	return PickUpItemVec;
}

void SellBasketFull(boost::asio::ip::tcp::socket & socket);

void LootEveryRegisteredItem(boost::asio::ip::tcp::socket & socket)
{
	std::cout << "Looting every item." << std::endl;
	int nSleep = 700;
	getClosestItem(); // must be called once before iteration
	if (ptrItemClosest)
	while (ptrItemClosest->nId)
	{
		getClosestItem(); // this getter function calculates current distance to all items and gets the closest item pointer.
		//if ((ptrItemClosest->m_nId != nPanace) && (ptrItemClosest->m_nId != nSPEED_POTION_ID) && (ptrItemClosest->m_nId != nBOX1_ID) && (ptrItemClosest->m_nId != nBOX2_ID) && (ptrItemClosest->m_nId != nCoupons))//there you can filter picked up items
		if (UnpickedItems.find(ptrItemClosest->m_nId) == UnpickedItems.end()) // items filtered here
		{
			if (Mystic.m_bTpHackLoot)
			{
				currentX = ptrItemClosest->m_X - 5;
				currentY = ptrItemClosest->m_Y - 5;
			}
			while (ptrItemClosest->m_X != currentX) // this gets the bot right on the item
			{
				MovementPacket2 = ForMovementPacket(ptrItemClosest->m_X, ptrItemClosest->m_Y, ptrItemClosest->m_Z);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			HandleUndecipheredPacket(size12x0C, C_TRY_LOOT_DROPITEM, ptrItemClosest->m_Id, socket);
		}
		else
		{//update the int holding filtered items we chose not to pick up
			++Mystic.m_nFilteredPickUpItems;
		}
		ptrItemClosest->m_X = 1;
		ptrItemClosest->m_Y = 1;
		-- ptrItemClosest->nId;
		std::cout << "nombre d'items a pick up : " << ptrItemClosest->nId << std::endl;
		Sleep(nSleep);
	}
	Items::nId = 0; //useless but kept for readability purposes
	ptrItemClosest.reset();
	ReleaseAllItemPickUpPointers();
	std::cout << "looted." << std::endl;
}

void StoreEveryFittingItem(boost::asio::ip::tcp::socket & socket)
{
	std::cout << "Storing every item fitting the ID requirements." << std::endl;
	std::vector <unsigned char> TempVec;
	int iii = 0;
	int nSleep = 3000;
	int yyy = 0;
	while ((waitForS_INVEN_Update != 2) && (yyy < 200))
	{
		Sleep(200);
		++yyy;
	}
	waitForS_INVEN_Update = 0;
	if (ptrSellItem32)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem32->m_nId == nVMWA_ID) || (ptrSellItem32->m_nId == nMWA_ID) || (ptrSellItem32->m_nId == nBOX1_ID) || (ptrSellItem32->m_nId == nBOX2_ID) || (ptrSellItem32->m_nId == nCOUPON_MODE_ID) || (ptrSellItem32->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem32->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem32->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem32->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem32.reset();
	}
	if (ptrSellItem31)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem31->m_nId == nVMWA_ID) || (ptrSellItem31->m_nId == nMWA_ID) || (ptrSellItem31->m_nId == nBOX1_ID) || (ptrSellItem31->m_nId == nBOX2_ID) || (ptrSellItem31->m_nId == nCOUPON_MODE_ID) || (ptrSellItem31->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem31->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem31->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem31->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}

		}
		ptrSellItem31.reset();
	}
	if (ptrSellItem30)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem30->m_nId == nVMWA_ID) || (ptrSellItem30->m_nId == nMWA_ID) || (ptrSellItem30->m_nId == nBOX1_ID) || (ptrSellItem30->m_nId == nBOX2_ID) || (ptrSellItem30->m_nId == nCOUPON_MODE_ID) || (ptrSellItem30->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem30->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem30->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem30->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem30.reset();
	}
	if (ptrSellItem29)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem29->m_nId == nVMWA_ID) || (ptrSellItem29->m_nId == nMWA_ID) || (ptrSellItem29->m_nId == nBOX1_ID) || (ptrSellItem29->m_nId == nBOX2_ID) || (ptrSellItem29->m_nId == nCOUPON_MODE_ID) || (ptrSellItem29->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem29->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem29->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem29->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem29.reset();
	}
	if (ptrSellItem28)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem28->m_nId == nVMWA_ID) || (ptrSellItem28->m_nId == nMWA_ID) || (ptrSellItem28->m_nId == nBOX1_ID) || (ptrSellItem28->m_nId == nBOX2_ID) || (ptrSellItem28->m_nId == nCOUPON_MODE_ID) || (ptrSellItem28->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem28->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem28->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem28->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem28.reset();
	}
	if (ptrSellItem27)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem27->m_nId == nVMWA_ID) || (ptrSellItem27->m_nId == nMWA_ID) || (ptrSellItem27->m_nId == nBOX1_ID) || (ptrSellItem27->m_nId == nBOX2_ID) || (ptrSellItem27->m_nId == nCOUPON_MODE_ID) || (ptrSellItem27->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem27->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem27->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem27->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem27.reset();
	}
	if (ptrSellItem26)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem26->m_nId == nVMWA_ID) || (ptrSellItem26->m_nId == nMWA_ID) || (ptrSellItem26->m_nId == nBOX1_ID) || (ptrSellItem26->m_nId == nBOX2_ID) || (ptrSellItem26->m_nId == nCOUPON_MODE_ID) || (ptrSellItem26->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem26->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem26->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem26->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem26.reset();
	}
	if (ptrSellItem25)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem25->m_nId == nVMWA_ID) || (ptrSellItem25->m_nId == nMWA_ID) || (ptrSellItem25->m_nId == nBOX1_ID) || (ptrSellItem25->m_nId == nBOX2_ID) || (ptrSellItem25->m_nId == nCOUPON_MODE_ID) || (ptrSellItem25->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem25->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem25->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem25->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem25.reset();
	}
	if (ptrSellItem24)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem24->m_nId == nVMWA_ID) || (ptrSellItem24->m_nId == nMWA_ID) || (ptrSellItem24->m_nId == nBOX1_ID) || (ptrSellItem24->m_nId == nBOX2_ID) || (ptrSellItem24->m_nId == nCOUPON_MODE_ID) || (ptrSellItem24->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem24->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem24->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem24->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem24.reset();
	}
	if (ptrSellItem23)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem23->m_nId == nVMWA_ID) || (ptrSellItem23->m_nId == nMWA_ID) || (ptrSellItem23->m_nId == nBOX1_ID) || (ptrSellItem23->m_nId == nBOX2_ID) || (ptrSellItem23->m_nId == nCOUPON_MODE_ID) || (ptrSellItem23->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem23->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem23->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem23->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem23.reset();
	}
	if (ptrSellItem22)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem22->m_nId == nVMWA_ID) || (ptrSellItem22->m_nId == nMWA_ID) || (ptrSellItem22->m_nId == nBOX1_ID) || (ptrSellItem22->m_nId == nBOX2_ID) || (ptrSellItem22->m_nId == nCOUPON_MODE_ID) || (ptrSellItem22->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem22->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem22->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem22->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem22.reset();
	}
	if (ptrSellItem21)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem21->m_nId == nVMWA_ID) || (ptrSellItem21->m_nId == nMWA_ID) || (ptrSellItem21->m_nId == nBOX1_ID) || (ptrSellItem21->m_nId == nBOX2_ID) || (ptrSellItem21->m_nId == nCOUPON_MODE_ID) || (ptrSellItem21->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem21->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem21->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem21->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem21.reset();
	}
	if (ptrSellItem20)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem20->m_nId == nVMWA_ID) || (ptrSellItem20->m_nId == nMWA_ID) || (ptrSellItem20->m_nId == nBOX1_ID) || (ptrSellItem20->m_nId == nBOX2_ID) || (ptrSellItem20->m_nId == nCOUPON_MODE_ID) || (ptrSellItem20->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem20->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem20->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem20->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
	}
		ptrSellItem20.reset();
	}
	if (ptrSellItem19)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem19->m_nId == nVMWA_ID) || (ptrSellItem19->m_nId == nMWA_ID) || (ptrSellItem19->m_nId == nBOX1_ID) || (ptrSellItem19->m_nId == nBOX2_ID) || (ptrSellItem19->m_nId == nCOUPON_MODE_ID) || (ptrSellItem19->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem19->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem19->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem19->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem19.reset();
	}
	if (ptrSellItem18)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem18->m_nId == nVMWA_ID) || (ptrSellItem18->m_nId == nMWA_ID) || (ptrSellItem18->m_nId == nBOX1_ID) || (ptrSellItem18->m_nId == nBOX2_ID) || (ptrSellItem18->m_nId == nCOUPON_MODE_ID) || (ptrSellItem18->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem18->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem18->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem18->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem18.reset();
	}
	if (ptrSellItem17)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem17->m_nId == nVMWA_ID) || (ptrSellItem17->m_nId == nMWA_ID) || (ptrSellItem17->m_nId == nBOX1_ID) || (ptrSellItem17->m_nId == nBOX2_ID) || (ptrSellItem17->m_nId == nCOUPON_MODE_ID) || (ptrSellItem17->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem17->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem17->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem17->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem17.reset();
	}
	if (ptrSellItem16)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem16->m_nId == nVMWA_ID) || (ptrSellItem16->m_nId == nMWA_ID) || (ptrSellItem16->m_nId == nBOX1_ID) || (ptrSellItem16->m_nId == nBOX2_ID) || (ptrSellItem16->m_nId == nCOUPON_MODE_ID) || (ptrSellItem16->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem16->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem16->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem16->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem16.reset();
	}
	if (ptrSellItem15)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem15->m_nId == nVMWA_ID) || (ptrSellItem15->m_nId == nMWA_ID) || (ptrSellItem15->m_nId == nBOX1_ID) || (ptrSellItem15->m_nId == nBOX2_ID) || (ptrSellItem15->m_nId == nCOUPON_MODE_ID) || (ptrSellItem15->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem15->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem15->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem15->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem15.reset();
	}
	if (ptrSellItem14)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem14->m_nId == nVMWA_ID) || (ptrSellItem14->m_nId == nMWA_ID) || (ptrSellItem14->m_nId == nBOX1_ID) || (ptrSellItem14->m_nId == nBOX2_ID) || (ptrSellItem14->m_nId == nCOUPON_MODE_ID) || (ptrSellItem14->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem14->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem14->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem14->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem14.reset();
	}
	if (ptrSellItem13)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem13->m_nId == nVMWA_ID) || (ptrSellItem13->m_nId == nMWA_ID) || (ptrSellItem13->m_nId == nBOX1_ID) || (ptrSellItem13->m_nId == nBOX2_ID) || (ptrSellItem13->m_nId == nCOUPON_MODE_ID) || (ptrSellItem13->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem13->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem13->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem13->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem13.reset();
	}
	if (ptrSellItem12)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem12->m_nId == nVMWA_ID) || (ptrSellItem12->m_nId == nMWA_ID) || (ptrSellItem12->m_nId == nBOX1_ID) || (ptrSellItem12->m_nId == nBOX2_ID) || (ptrSellItem12->m_nId == nCOUPON_MODE_ID) || (ptrSellItem12->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem12->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem12->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem12->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem12.reset();
	}
	if (ptrSellItem11)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem11->m_nId == nVMWA_ID) || (ptrSellItem11->m_nId == nMWA_ID) || (ptrSellItem11->m_nId == nBOX1_ID) || (ptrSellItem11->m_nId == nBOX2_ID) || (ptrSellItem11->m_nId == nCOUPON_MODE_ID) || (ptrSellItem11->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem11->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem11->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem11->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem11.reset();
	}
	if (ptrSellItem10)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem10->m_nId == nVMWA_ID) || (ptrSellItem10->m_nId == nMWA_ID) || (ptrSellItem10->m_nId == nBOX1_ID) || (ptrSellItem10->m_nId == nBOX2_ID) || (ptrSellItem10->m_nId == nCOUPON_MODE_ID) || (ptrSellItem10->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem10->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem10->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem10->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem10.reset();
	}
	if (ptrSellItem9)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem9->m_nId == nVMWA_ID) || (ptrSellItem9->m_nId == nMWA_ID) || (ptrSellItem9->m_nId == nBOX1_ID) || (ptrSellItem9->m_nId == nBOX2_ID) || (ptrSellItem9->m_nId == nCOUPON_MODE_ID) || (ptrSellItem9->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem9->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem9->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem9->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem9.reset();
	}
	if (ptrSellItem8)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem8->m_nId == nVMWA_ID) || (ptrSellItem8->m_nId == nMWA_ID) || (ptrSellItem8->m_nId == nBOX1_ID) || (ptrSellItem8->m_nId == nBOX2_ID) || (ptrSellItem8->m_nId == nCOUPON_MODE_ID) || (ptrSellItem8->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem8->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem8->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem8->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem8.reset();
	}
	if (ptrSellItem7)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem7->m_nId == nVMWA_ID) || (ptrSellItem7->m_nId == nMWA_ID) || (ptrSellItem7->m_nId == nBOX1_ID) || (ptrSellItem7->m_nId == nBOX2_ID) || (ptrSellItem7->m_nId == nCOUPON_MODE_ID) || (ptrSellItem7->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem7->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem7->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem7->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem7.reset();
	}
	if (ptrSellItem6)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem6->m_nId == nVMWA_ID) || (ptrSellItem6->m_nId == nMWA_ID) || (ptrSellItem6->m_nId == nBOX1_ID) || (ptrSellItem6->m_nId == nBOX2_ID) || (ptrSellItem6->m_nId == nCOUPON_MODE_ID) || (ptrSellItem6->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem6->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem6->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem6->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem6.reset();
	}
	if (ptrSellItem5)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem5->m_nId == nVMWA_ID) || (ptrSellItem5->m_nId == nMWA_ID) || (ptrSellItem5->m_nId == nBOX1_ID) || (ptrSellItem5->m_nId == nBOX2_ID) || (ptrSellItem5->m_nId == nCOUPON_MODE_ID) || (ptrSellItem5->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem5->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem5->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem5->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem5.reset();
	}
	if (ptrSellItem4)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem4->m_nId == nVMWA_ID) || (ptrSellItem4->m_nId == nMWA_ID) || (ptrSellItem4->m_nId == nBOX1_ID) || (ptrSellItem4->m_nId == nBOX2_ID) || (ptrSellItem4->m_nId == nCOUPON_MODE_ID) || (ptrSellItem4->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem4->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem4->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem4->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem4.reset();
	}
	if (ptrSellItem3)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem3->m_nId == nVMWA_ID) || (ptrSellItem3->m_nId == nMWA_ID) || (ptrSellItem3->m_nId == nBOX1_ID) || (ptrSellItem3->m_nId == nBOX2_ID) || (ptrSellItem3->m_nId == nCOUPON_MODE_ID) || (ptrSellItem3->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem3->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem3->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem3->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem3.reset();
	}
	if (ptrSellItem2)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem2->m_nId == nVMWA_ID) || (ptrSellItem2->m_nId == nMWA_ID) || (ptrSellItem2->m_nId == nBOX1_ID) || (ptrSellItem2->m_nId == nBOX2_ID) || (ptrSellItem2->m_nId == nCOUPON_MODE_ID) || (ptrSellItem2->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem2->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem2->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem2->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem2.reset();
	}
	if (ptrSellItem1)
	{
		if (!TempVec.empty())
			TempVec.clear();
		if (!((ptrSellItem1->m_nId == nVMWA_ID) || (ptrSellItem1->m_nId == nMWA_ID) || (ptrSellItem1->m_nId == nBOX1_ID) || (ptrSellItem1->m_nId == nBOX2_ID) || (ptrSellItem1->m_nId == nCOUPON_MODE_ID) || (ptrSellItem1->m_nId == nSPEED_POTION_ID)))
		{
			++iii;
			TempVec = vAddBasketItems;
			TurnInt32_tIntoVect(ptrSellItem1->m_nId, TempVec);
			TurnInt32_tIntoVect(ptrSellItem1->m_nAmount, TempVec);
			TurnInt32_tIntoVect(ptrSellItem1->m_nEmplacement, TempVec);
			HandleUndecipheredPacket(size28x1c, C_STORE_SELL_ADD_BASKET, TempVec, socket);
			if (iii >= 8)
			{
				waitForS_INVEN_Update = 1;
				HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
				Sleep(nSleep);
				iii = 0;
				int yyy = 0;
				while ((waitForS_INVEN_Update != 2) && (yyy < 20))
				{
					Sleep(200);
					++yyy;
				}
				waitForS_INVEN_Update = 0;
			}
		}
		ptrSellItem1.reset();
	}
	
		HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
	Sleep(600);

		if (!TempVec.empty())
			TempVec.clear();
		TempVec = vContractId;
		HandleUndecipheredPacket(size12x0C, C_CANCEL_CONTRACT, TempVec, socket);
		HandleUndecipheredPacket(size12x0C, C_CANCEL_CONTRACT, TempVec, socket);
		if (!TempVec.empty())
			TempVec.clear();
		if (!vInterractNpcDialogId_1.empty())
		{
			TempVec = vInterractNpcDialogId_1;
			TempVec.push_back(02);//Forms close dialog vector
			for (int uuu = 0; uuu < 7; ++uuu)
				TempVec.push_back(00);
			HandleUndecipheredPacket(size16x10, C_DIALOG_EVENT, TempVec, socket); //2 samples get sent here.
		}
	std::cout << "Stored." << std::endl;
}
void getClosestItem() {
	if (ptrItem1 && ptrItem2)
	{
		ptrItem1->GetSquareDistance();
		ptrItem2->GetSquareDistance();
		if (ptrItem1-> m_fDistanceToItem < ptrItem2 -> m_fDistanceToItem)
			ptrItemClosest = ptrItem1;
		else
			ptrItemClosest = ptrItem2;
	}
	if (ptrItem3)
	{
		ptrItem3->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem3->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem3;
	}
	if (ptrItem4)
	{
		ptrItem4->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem4->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem4;
	}
	if (ptrItem5)
	{
		ptrItem5->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem5->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem5;
	}
	if (ptrItem6)
	{
		ptrItem6->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem6->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem6;
	}
	if (ptrItem7)
	{
		ptrItem7->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem7->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem7;
	}
	if (ptrItem8)
	{
		ptrItem8->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem8->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem8;
	}
	if (ptrItem9)
	{
		ptrItem9->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem9->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem9;
	}
	if (ptrItem10)
	{
		ptrItem10->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem10->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem10;
	}
	if (ptrItem11)
	{
		ptrItem11->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem11->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem11;
	}
	if (ptrItem12)
	{
		ptrItem12->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem12->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem12;
	}
	if (ptrItem13)
	{
		ptrItem13->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem13->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem13;
	}
	if (ptrItem14)
	{
		ptrItem14->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem14->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem14;
	}
	if (ptrItem15)
	{
		ptrItem15->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem15->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem15;
	}
	if (ptrItem16)
	{
		ptrItem16->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem16->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem16;
	}
	if (ptrItem17)
	{
		ptrItem17->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem17->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem17;
	}
	if (ptrItem18)
	{
		ptrItem18->GetSquareDistance();
	if (ptrItemClosest->m_fDistanceToItem < ptrItem18->m_fDistanceToItem)
		Sleep(1);
	else
			ptrItemClosest = ptrItem18;
	}
	if (ptrItem19)
	{
		ptrItem19->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem19->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem19;
	}
	if (ptrItem20)
	{
		ptrItem20->GetSquareDistance();
		if (ptrItemClosest->m_fDistanceToItem < ptrItem20->m_fDistanceToItem)
			Sleep(1);
		else
			ptrItemClosest = ptrItem20;
	}
}
void ReleaseAllItemPickUpPointers() {
	std::cout << "Releasing all Item picked up pointers. " << std::endl;
	if (ptrItem20)
		ptrItem20.reset();
	if (ptrItem19)
		ptrItem19.reset();
	if (ptrItem18)
		ptrItem18.reset();
	if (ptrItem17)
		ptrItem17.reset();
	if (ptrItem16)
		ptrItem16.reset();
	if (ptrItem15)
		ptrItem15.reset();
	if (ptrItem14)
		ptrItem14.reset();
	if (ptrItem13)
		ptrItem13.reset();
	if (ptrItem12)
		ptrItem12.reset();
	if (ptrItem11)
		ptrItem11.reset();
	if (ptrItem10)
		ptrItem10.reset();
	if (ptrItem9)
		ptrItem9.reset();
	if (ptrItem8)
		ptrItem8.reset();
	if (ptrItem7)
		ptrItem7.reset();
	if (ptrItem6)
		ptrItem6.reset();
	if (ptrItem5)
		ptrItem5.reset();
	if (ptrItem4)
		ptrItem4.reset();
	if (ptrItem3)
		ptrItem3.reset();
	if (ptrItem2)
		ptrItem2.reset();
	if (ptrItem1)
		ptrItem1.reset();
	std::cout << "Released all Item picked up pointers. " << std::endl;
}
void ReleaseAllItemSellPointers()
{
	std::cout << "Releasing itemSell pointers." << std::endl;
	if (ptrSellItem32)
		ptrSellItem32.reset();
	if (ptrSellItem31)
		ptrSellItem31.reset();
	if (ptrSellItem30)
		ptrSellItem30.reset();
	if (ptrSellItem29)
		ptrSellItem29.reset();
	if (ptrSellItem28)
		ptrSellItem28.reset();
	if (ptrSellItem27)
		ptrSellItem27.reset();
	if (ptrSellItem26)
		ptrSellItem26.reset();
	if (ptrSellItem25)
		ptrSellItem25.reset();
	if (ptrSellItem24)
		ptrSellItem24.reset();
	if (ptrSellItem23)
		ptrSellItem23.reset();
	if (ptrSellItem22)
		ptrSellItem22.reset();
	if (ptrSellItem21)
		ptrSellItem21.reset();
	if (ptrSellItem20)
		ptrSellItem20.reset();
	if (ptrSellItem19)
		ptrSellItem19.reset();
	if (ptrSellItem18)
		ptrSellItem18.reset();
	if (ptrSellItem17)
		ptrSellItem17.reset();
	if (ptrSellItem16)
		ptrSellItem16.reset();
	if (ptrSellItem15)
		ptrSellItem15.reset();
	if (ptrSellItem14)
		ptrSellItem14.reset();
	if (ptrSellItem13)
		ptrSellItem13.reset();
	if (ptrSellItem12)
		ptrSellItem12.reset();
	if (ptrSellItem11)
		ptrSellItem11.reset();
	if (ptrSellItem10)
		ptrSellItem10.reset();
	if (ptrSellItem9)
		ptrSellItem9.reset();
	if (ptrSellItem8)
		ptrSellItem8.reset();
	if (ptrSellItem7)
		ptrSellItem7.reset();
	if (ptrSellItem6)
		ptrSellItem6.reset();
	if (ptrSellItem5)
		ptrSellItem5.reset();
	if (ptrSellItem4)
		ptrSellItem4.reset();
	if (ptrSellItem3)
		ptrSellItem3.reset();
	if (ptrSellItem2)
		ptrSellItem2.reset();
	if (ptrSellItem1)
		ptrSellItem1.reset();
	std::cout << "itemSellPointers released" << std::endl;

}

void SellBasketFull(boost::asio::ip::tcp::socket & socket) {
	int nSleep = 3000;
	ReleaseAllItemSellPointers();
	waitForS_INVEN_Update = 1;
	HandleUndecipheredPacket(size16x10, C_STORE_COMMIT, vAddBasketItems, socket);
	Sleep(nSleep);
	int yyy = 0;
	while ((waitForS_INVEN_Update != 2) && (yyy < 30))
	{
		Sleep(200);
		++yyy;
	}
	waitForS_INVEN_Update = 0;
}