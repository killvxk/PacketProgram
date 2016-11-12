#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <thread>
#include <iostream>
#include <Windows.h>
#ifndef PACKETRECEPTION_H
#define PACKETRECEPTION_H
//=========================================================================== PROTOTYPES DECLARATIONS =====================================================================
DWORD WINAPI Thread_no_1(LPVOID lpParam);
void ReceptionFunction(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void handler(const boost::system::error_code &ec, std::size_t bytes_transferred);
void HandlePacketReception(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void DecryptPacket(int size, std::vector <unsigned char > & vectReceptionArg);
void LoginArbiter(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument);
void LogWhispers(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void SpawnMe(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void HandleUserSpawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument);
void HandleUserDeSpawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument);
void FollowNearbyUser(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void LogFirstUser(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ContinueFirstNpcDialog(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void SortS_DIALOG_EVENT(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void UpdateMenuSlection(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ConfirmS_REQUEST_CONTRACT(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void CreateNpc(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToVisitNewSection(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToGuardPkPolicy(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToReignInfo(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToDialogClose(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToInstantMove(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToActionStage(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void HandleNpcDespawn(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void CreateItem(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToCompletedMissionInfo(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToDungeonCoolTime(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ManageSales(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ProcessSChat(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToAcceptContract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ProcessPartyMemberList(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ProcessChangePartyManager(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void WriteInOutToFile(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> undecVecArg);
void SpamPartyChat(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void ReplyToSStoreSellList(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ManageNpcLocation(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToSGrantSkill(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToSUserLocation(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToArbiterContract(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToSLogin(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReplyToUserLevelUp(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument, boost::asio::ip::tcp::socket &socket);
void ReleaseAllMonsterPtr();
//=========================================================================== PROTOTYPES DECLARATIONS ENDS HERE ===========================================================
class PacketReception
{
	PacketReception(); // default constructor, used by default


	int16_t RetrievePacketTitle(int size); //Give this decrypted packet size and it will retrieve the packet title, returning it in the process

	friend void ReadPacket(boost::asio::ip::tcp::socket & socket, std::vector<unsigned char> & vectReceptionArg);
};
//============================================================================== VARIABLES =============================
extern std::vector<unsigned char> vectReception; //all packets have an unsigned char array
extern int nAnalyzedSize;
extern bool bTpHack;
extern std::vector<unsigned char>::iterator oo;
extern int nNumberOfEnnemies;
extern int generalFlag;
#endif

