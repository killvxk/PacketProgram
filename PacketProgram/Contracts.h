
#ifndef CONTRACTS_H
#define CONTRACTS_H

#include "PacketData.h"
#include "Packet.h"
#include "DllInject.h"
#include "PacketReception.h"
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

class Contracts
{
private :
	int m_nContractType;
	int m_nTypeKn = 0x01;
	int m_nTypeParty = 0x02;
	int m_nTypeStore = 0x03;
public:
	//std::vector <unsigned char> vRequestContractKn{ 0x1A, 0x00, 0x1C, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 };
	enum eContracts
	{
		NullContract = 0
	};
	Contracts()
	{

	}
	Contracts(int nCaseContract, std::vector <unsigned char> & vectArgument, boost::asio::ip::tcp::socket &socket) : m_nContractType(nCaseContract)
	{
		std::cout << "starting new contract" << std::endl;
		if (nCaseContract == m_nTypeKn)//type 0x10
		{
			HandleUndecipheredPacket(size32x20, C_REQUEST_CONTRACT, vRequestContractKn, socket);
		}
		else if (nCaseContract == m_nTypeStore)//type 0x09
		{
			std::cout << "reply to accept contract" << std::endl;
			std::vector <unsigned char> TempVec{ 0x1A, 0x00, 0x1C, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00 };
			for (int uuu = 12; uuu < 20; ++uuu)
				TempVec.push_back(vectArgument[uuu + nAnalyzedSize]);
			std::vector <unsigned char> vRequestContractItemSell{ 0xA8, 0x86, 0x01, 0x00, 0x00, 0x00, 0xA8, 0x86, 0x01, 0x00 };
			TempVec.insert(TempVec.end(), vRequestContractItemSell.begin(), vRequestContractItemSell.end());
			HandleUndecipheredPacket(size32x20, C_REQUEST_CONTRACT, TempVec, socket);
		}
		else if (nCaseContract == NullContract) // used during party invites
		{

		}
		std::cout << "started." << std::endl;
	}
	void ReplyToS_Request_Contract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
};

extern boost::shared_ptr < Contracts > contractPtr;
#endif

