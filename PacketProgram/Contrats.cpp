#include "Contracts.h"
#include "PacketData.h"
#include "Packet.h"
#include "DllInject.h"
#include "PacketReception.h"
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
boost::shared_ptr < Contracts > contractPtr = 0;
using namespace std;
void Contracts::ReplyToS_Request_Contract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket) {
	std::vector<unsigned char> TempVec;
	if (m_nContractType == m_nTypeStore)
	{
		if (!(vContractId.empty()))
			vContractId.clear();
		for (int uuu = 28; uuu < 36; ++uuu)
		{
			vContractId.push_back(vectArgument[uuu + nAnalyzedSize]);
		}
		if (!vAddBasketItems.empty())
			vAddBasketItems.clear();
		for (int uuu = 12; uuu < 20; ++uuu)//20 or 19
		{
			vAddBasketItems.push_back(vectArgument[uuu + nAnalyzedSize]);
		}
		for (int uuu = 32; uuu < 36; ++uuu)
			vAddBasketItems.push_back(vectArgument[uuu + nAnalyzedSize]);
	}
	else if (m_nContractType == m_nTypeKn)
	{
		TempVec = vInterractNpcDialogId_1;
		TempVec.push_back(0x01);
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
		TempVec.clear();
		TempVec.push_back(0x10);
		TempVec.push_back(00);
		TempVec.push_back(00);
		TempVec.push_back(00);
		for (int uuu = 32; uuu < 36; ++uuu)
			TempVec.push_back(vectArgument[uuu+nAnalyzedSize]);
		HandleUndecipheredPacket(size12x0C, C_CANCEL_CONTRACT, TempVec, socket);
	}
	else if (m_nContractType == m_nTypeParty)
	{

	}
}