#ifndef ITEMINTERRACTION_H
#define ITEMINTERRACTION_H
#include <vector>
#include "Waypoint.h"
class Items
{
public:
	std::vector <unsigned char> m_Id;
	int m_X;
	int m_Y;
	int m_Z;
	int32_t m_nId;
	float x;
	float y;
	float xm;
	float ym;
	bool m_LifeState;
	int m_nSquareDistance;
	float m_fDistanceToItem;
	static int nId;
	Items::Items(std::vector <unsigned char> &vectArg, int &nAnalyzedSize) : m_LifeState(1)
	{
		m_X = TurnVectInto32_int(vectArg, 16, nAnalyzedSize);
		m_Y = TurnVectInto32_int(vectArg, 20, nAnalyzedSize);
		m_Z = TurnVectInto32_int(vectArg, 24, nAnalyzedSize);
		++nId;
		for (int uuu = 8; uuu < 16; ++uuu)
		{
			m_Id.push_back(vectArg[uuu + nAnalyzedSize]);
		}
		m_nId = TurnVectInto32_int(vectArg, 28, nAnalyzedSize);
	}
	int GetSquareDistance() {
		x = *(float *)&m_X;
		y = *(float *)&m_Y;
		ym = *(float *)&currentY;
		xm = *(float *)&currentX;
		float dif1 = x - xm;
		float dif2 = y - ym;
		m_fDistanceToItem = (pow(dif1, 2) + pow(dif2, 2));
		return 1;

	}
	friend void LootEveryRegisteredItem(boost::asio::ip::tcp::socket & socket);

};
class ItemsToSell
{
public:
	int m_nAmount;
	int m_nId;
	int m_nEmplacement;
	std::vector <unsigned char> m_vector;
	ItemsToSell::ItemsToSell(std::vector <unsigned char> &vectArg, int &nId, int &nAmount, int &nEmplacement) :m_vector(vectArg), m_nAmount(nAmount), m_nId(nId), m_nEmplacement(nEmplacement)
	{

	}
	void StoreItems()
	{

	}
	friend void StoreEveryFittingItem(boost::asio::ip::tcp::socket & socket);
	friend void ReleaseAllItemSellPointers();
};
extern int inMoodForShop;
extern int waitForS_INVEN_Update;
void ReleaseAllItemSellPointers();
void ReleaseAllItemPickUpPointers();
extern boost::shared_ptr <Items> ptrItem1;
extern boost::shared_ptr <Items> ptrItem2;
extern boost::shared_ptr <Items> ptrItem3;
extern boost::shared_ptr <Items> ptrItem4;
extern boost::shared_ptr <Items> ptrItem5;
extern boost::shared_ptr <Items> ptrItem6;
extern boost::shared_ptr <Items> ptrItem7;
extern boost::shared_ptr <Items> ptrItem8;
extern boost::shared_ptr <Items> ptrItem9;
extern boost::shared_ptr <Items> ptrItem10;
extern boost::shared_ptr <Items> ptrItem11;
extern boost::shared_ptr <Items> ptrItem12;
extern boost::shared_ptr <Items> ptrItem13;
extern boost::shared_ptr <Items> ptrItem14;
extern boost::shared_ptr <Items> ptrItem15;
extern boost::shared_ptr <Items> ptrItem16;
extern boost::shared_ptr <Items> ptrItem17;
extern boost::shared_ptr <Items> ptrItem18;
extern boost::shared_ptr <Items> ptrItem19;
extern boost::shared_ptr <Items> ptrItem20;
extern boost::shared_ptr <Items> ptrItemClosest;

extern boost::shared_ptr <ItemsToSell> ptrSellItem1;
extern boost::shared_ptr <ItemsToSell> ptrSellItem2;
extern boost::shared_ptr <ItemsToSell> ptrSellItem3;
extern boost::shared_ptr <ItemsToSell> ptrSellItem4;
extern boost::shared_ptr <ItemsToSell> ptrSellItem5;
extern boost::shared_ptr <ItemsToSell> ptrSellItem6;
extern boost::shared_ptr <ItemsToSell> ptrSellItem7;
extern boost::shared_ptr <ItemsToSell> ptrSellItem8;
extern boost::shared_ptr <ItemsToSell> ptrSellItem9;
extern boost::shared_ptr <ItemsToSell> ptrSellItem10;
extern boost::shared_ptr <ItemsToSell> ptrSellItem11;
extern boost::shared_ptr <ItemsToSell> ptrSellItem12;
extern boost::shared_ptr <ItemsToSell> ptrSellItem13;
extern boost::shared_ptr <ItemsToSell> ptrSellItem14;
extern boost::shared_ptr <ItemsToSell> ptrSellItem15;
extern boost::shared_ptr <ItemsToSell> ptrSellItem16;
extern boost::shared_ptr <ItemsToSell> ptrSellItem17;
extern boost::shared_ptr <ItemsToSell> ptrSellItem18;
extern boost::shared_ptr <ItemsToSell> ptrSellItem19;
extern boost::shared_ptr <ItemsToSell> ptrSellItem20;
extern boost::shared_ptr <ItemsToSell> ptrSellItem21;
extern boost::shared_ptr <ItemsToSell> ptrSellItem22;
extern boost::shared_ptr <ItemsToSell> ptrSellItem23;
extern boost::shared_ptr <ItemsToSell> ptrSellItem24;
extern boost::shared_ptr <ItemsToSell> ptrSellItem25;
extern boost::shared_ptr <ItemsToSell> ptrSellItem26;
extern boost::shared_ptr <ItemsToSell> ptrSellItem27;
extern boost::shared_ptr <ItemsToSell> ptrSellItem28;
extern boost::shared_ptr <ItemsToSell> ptrSellItem29;
extern boost::shared_ptr <ItemsToSell> ptrSellItem30;
extern boost::shared_ptr <ItemsToSell> ptrSellItem31;
extern boost::shared_ptr <ItemsToSell> ptrSellItem32;
#endif