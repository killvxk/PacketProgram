
#ifndef PACKET_H
#define PACKET_H
#include <cstdlib>
#include <boost/thread/mutex.hpp>
//============================================== Function Prototypes
void HandlePacket(uint16_t nSize, uint16_t nTitle, boost::asio::ip::tcp::socket &socket);
void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, boost::asio::ip::tcp::socket & socket);
void HandleUndecipheredPacket(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg, int nIteration, boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
//
extern boost::mutex mtx_lockHandlePackets;
class BasePacket
{
public:
	uint16_t m_nPacketSize; // all packets have a size

	uint16_t m_nPacketTitle; // all packets have a title

	std::vector<unsigned char> vect; //all packets have an unsigned char array

	std::vector<unsigned char>::iterator ii = vect.begin();

	BasePacket();// default constructor, should never be used

	BasePacket(uint16_t nSize, uint16_t nTitle);
	
	void FormPacket(); 

	~BasePacket();

void EncryptPacket();

friend void SendPacket(std::vector<unsigned char> &vecArgument, boost::asio::ip::tcp::socket &socket);  //every packet gets sent


};

class UndecipheredPacket : virtual public BasePacket // this kind of packet will always be handed over a data vector to work with
{
public:
	std::vector<unsigned char> undecVec; //vect will take data from undecVec instead of int16_t because we can't predict the data size of this kind of packet

	UndecipheredPacket(); // default constructor, should never be used

	UndecipheredPacket(std::vector<unsigned char> undecVecArg, uint16_t nSize, const uint16_t nTitle);

	void FormPacket();

	~UndecipheredPacket();
};
#endif
