
//#include "PacketProgram.h"
//
#include <fstream> 
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
//#include <boost/lexical_cast.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
// =file includes
#include "PacketProgramBoost.h"
#include "cryptography.h"
#include "Packet.h"
#include "PacketData.h"
#include "DataFileSaving.h"
using namespace std;
string packetSentContent = "Packet sent content.txt";
ofstream fileoutSent(packetSentContent.c_str());
BasePacket::BasePacket() {} // default constructor, should never be used

BasePacket::BasePacket(uint16_t nSize, uint16_t nTitle) : m_nPacketSize(nSize), m_nPacketTitle(nTitle) {

}
BasePacket::~BasePacket() {

}
void BasePacket::FormPacket() { //every packet class has its own
	vect.push_back(m_nPacketSize & 0xFF);
	vect.push_back(m_nPacketSize >> 8);
	vect.push_back(m_nPacketTitle & 0xFF);
	vect.push_back(m_nPacketTitle >> 8);
}

void BasePacket::EncryptPacket() { //every packet needs to be encrypted
	int ooo = 0;
	while ((EncryptionOrDecryptionBusy))
	{
		++ooo;
		Sleep(10);
		if (ooo <=500)
			cout << "Encryption is busy" << endl;
	}
	EncryptionOrDecryptionBusy = 1;
	ii = vect.begin();
	ptrPacketToSend = &(*ii); 
	try{
		//vect.at(m_nPacketSize-1) == 0;
		vect.at(0) == 0;
	}
	catch (std::out_of_range o){
		while (1)
		{
		std::cout << o.what() << "Error at encryption size-wise ! ########################" << std::endl;
		Sleep(500);
		}
	}
	int yyy = 0;
	while (m_nPacketSize != vect.size())
	{
		std::cout << "## error on the size of the packet : size is : "<< dec << m_nPacketSize <<" and vect size is : " << dec << vect.size() << std::endl;
		if (yyy == 0)
		{
			cout << "storing corrupted packet to file" << endl;
			uint16_t nSize = vect.size();
			//std::cout << "\nSize is : " << rPsize << endl;
			uint16_t nTitle = ((vect[2]) | (vect[3] << 8));
			WriteToFile_C(nSize, nTitle, vect);
		}
		++yyy;
		Sleep(1000);
	}
	EncryptionCaller_016b8070(ptrPacketToSend, m_nPacketSize);
	EncryptionOrDecryptionBusy = 0;
}

//function body
void SendPacket(std::vector<unsigned char> &vecArgument, boost::asio::ip::tcp::socket &socket) {

	socket.send(boost::asio::buffer(vecArgument));
	//include a packet destructor here to free the memory
}
//
UndecipheredPacket::UndecipheredPacket(std::vector<unsigned char> undecVecArg, uint16_t nSize, uint16_t nTitle) : BasePacket(nSize, nTitle), undecVec(undecVecArg) {

}

UndecipheredPacket::~UndecipheredPacket() {

}

void UndecipheredPacket::FormPacket() {
	vect.push_back(m_nPacketSize & 0xFF);
	vect.push_back(m_nPacketSize >> 8);
	vect.push_back(m_nPacketTitle & 0xFF);
	vect.push_back(m_nPacketTitle >> 8);
	vect.insert(vect.end(), undecVec.begin(), undecVec.end());
}

void HandlePacket(uint16_t nSize, uint16_t nTitle, boost::asio::ip::tcp::socket &socket) {
	mtx_lockHandlePackets.lock();
	BasePacket thisPacket(nSize, nTitle);
	std::map <int, std::string> ::iterator it = PacketHandlers.find(nTitle);
	thisPacket.BasePacket::FormPacket();
	cout << "storing packet to file" << endl;
	WriteToFile_C(nSize, nTitle, thisPacket.vect);
	cout << "stored." << endl;
	cout << "will encrypt" << endl;
	thisPacket.EncryptPacket();
	cout << "encrypted, will send" << endl;
	SendPacket(thisPacket.vect, socket);
	mtx_lockHandlePackets.unlock();
}

void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, boost::shared_ptr<boost::asio::ip::tcp::socket> socket) {
	mtx_lockHandlePackets.lock();
	UndecipheredPacket thisPacket(undecVecArg, nSize, nTitle);
	std::map <int, std::string> ::iterator it = PacketHandlers.find(nTitle);
	cout << "will form" << endl;
	thisPacket.UndecipheredPacket::FormPacket();
	cout << "storing packet to file" << endl;
	WriteToFile_C(nSize, nTitle, thisPacket.vect);
	cout << "stored." << endl;
	cout << "will encrypt" << endl;
		thisPacket.EncryptPacket();
		cout << "encrypted, will send" << endl;
		SendPacket(thisPacket.vect, *socket);
		cout << "sent" << endl;
		mtx_lockHandlePackets.unlock();
}

void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, boost::asio::ip::tcp::socket & socket) { //overload 
	mtx_lockHandlePackets.lock();
	UndecipheredPacket thisPacket(undecVecArg, nSize, nTitle);
	std::map <int, std::string> ::iterator it = PacketHandlers.find(nTitle);
	cout << "will form" << endl;
	thisPacket.UndecipheredPacket::FormPacket();
	cout << "storing packet to file" << endl;
	WriteToFile_C(nSize, nTitle, thisPacket.vect);
	cout << "stored." << endl;
	cout << "will encrypt" << endl;
	thisPacket.EncryptPacket();
	cout << "encrypted, will send" << endl;
	while (thisPacket.m_nPacketSize != thisPacket.vect.size())
	{
		Sleep(1000);
		std::cout << "## error on the size of the packet" << std::endl;
	}
	SendPacket(thisPacket.vect, socket);
	cout << "sent" << endl;
	mtx_lockHandlePackets.unlock();
}
void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, int nIteration, boost::shared_ptr<boost::asio::ip::tcp::socket> socket) {
	mtx_lockHandlePackets.lock();
	int nSavedIteration = nIteration;
	while (nIteration >0)
	{
	UndecipheredPacket thisPacket(undecVecArg, nSize, nTitle);
	std::map <int, std::string> ::iterator it = PacketHandlers.find(nTitle);
	cout << "will form" << endl;
	thisPacket.UndecipheredPacket::FormPacket();
	if (nIteration == nSavedIteration) // this way the packet is wrote only once
	{
		cout << "storing packet to file" << endl;
		WriteToFile_C(nSize, nTitle, thisPacket.vect);
		cout << "stored." << endl;
	}
		cout << "will encrypt" << endl;
		thisPacket.EncryptPacket();
		cout << "encrypted, will send" << endl;
		SendPacket(thisPacket.vect, *socket);
		cout << "sent" << endl;
		thisPacket.~UndecipheredPacket();
		--nIteration;
	}
	mtx_lockHandlePackets.unlock();
}