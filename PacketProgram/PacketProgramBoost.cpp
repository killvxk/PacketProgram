
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
#include "cryptography.h"
#include "PacketProgram.h"
#include "Packet.h"
#include "PacketReception.h"
#include "ManagePlayers.h"
#include "PacketData.h"
#include "Waypoint.h"
#include "UseSkills.h"
#include "ItemInterraction.h"
#include "MonsterInterraction.h"
#include "BotClass.h"
#include "DataFileSaving.h"
#include "DllInject.h"
#include "ConfigFile.h"
#include "Pattern.h"
#include "Contracts.h"
#include "TeraLauncher.h"
#include <thread>
#include <ctime>
//
using namespace std;
void WriteStatsFile();
int bufferHolder;
time_t tStartingTime;
time_t tCurrentTime;
bool debug(0);
bool recent_ID(0);
unsigned char chFirstReadRandomedKey[128000];
bool EncryptionOrDecryptionBusy(0);
int addressFirstKey(0xdb93b000);
int addressThirdKey(0xda310010);
int addressFourthKey(0xda300010);
char test[144];
char length_2[144];
int nRandomCount(0);
int nRandomMax(128);
int nThereWasEnnemy = 0;
unsigned char szGeneratedKey[128];
int nNewRandomedNumber(0);
unsigned char chsecondReadRandomedKey[128000];
unsigned char chThirdReadReceivedKey[150000];
unsigned char chFourthReadReceivedKey[150000];
void*ptrReceivedFirstKey = (&chThirdReadReceivedKey);
void*ptrReceivedSecondKey = (&chFourthReadReceivedKey);
void*ptrRandomedFirstKey = &chFirstReadRandomedKey;
void*ptrRandomedSecondKey = &chsecondReadRandomedKey;
void*ptrSentSecondKey;
char chArchitectureKey[128000];
void* ptrPacketToSend;
void*ptrArchitectureKey = &chArchitectureKey;
//tte se voient rajouter 0x100
char keyEncryption_1[0x000001DD0] = "\xC1\x84\x31\x6D\xC8\x08\xE7\x9E\x02\xC9\x97\x1C\xD2\xEB\x4D\x64\xEB\xB1\xF7\xBB\xC8\x14\x82\x98\x1E\xC5\xF8\xB9\x3B\x6B\x50\x97\x31\xBD\x50\xB0\xFE\x10\x88\x21\x78\xB8\xD6\x5E\x7D\x71\xF7\xEC\x34\x84\x2F\xE2\xBB\xA2\xF9\x7F\xAF\xB5\xF8\x5D\x35\x0B\x40\xAA\x41\xDE\x8B\x54\xFF\x55\x8B\x0E\x07\xD6\x49\xA8\x1F\x72\x9C\xBB\x78\xD2\xB8\x64\xD5\x2E\xA1\x77\x59\x48\x89\x5A\xEE\x14\x79\xF1\x8C\x3D\x2A\x32\x45\xCB\x84\xA5\xA6\x57\xB7\x8E\xDB\xA1\xC6\xD7\xC3\x0B\xF8\xC4\x22\x4F\xE6\x8E\xF0\x07\x76\xD4\x50\xAB\x55\xD8\x41\x8C\xF8\x05\xC3\xAD\x6C\xDC\xE0\x28\xAB\xEC\xA2\x3D\xEB\x07\x0D\xA2\x87\x4B\xE3\x08\xF6\xB4\x8B\x61\x31\x77\x0A\xD8\x0B\x23\x2B\x02\x21\xF2\xAE\xAB\x5B\x42\x6F\x44\x02\xAD\x5D\xCF\xAD\x51\x2B\x90\x02\xE5\x47\xB7\xA9\x1D\x3B\x87\x20\x5D\x96\x4A\xDB\xAC\x81\xB3\x42\xD2\xA0\xD2\xC2\x88\xCA\x11\x82\x89\x96\x1F\x12\x32\xF4\xB7\x60\x59\x46\xCF\xF7\x66\x30\xEF\x33\xBE";
char keyDecryption_1[0x000001DD0];
char keyEncryption_2[0x000001E50] = "\xAF\x37\x64\xB7\xD6\x82\x71\x28\xEA\x8D\x92\xD9\xBF\x04\x95\x4F\xEA\x4D\xD7\xAE\x6D\x95\xB7\xEB\x75\x1E\x34\xAE\xED\x0E\xB5\x7A\x35\xFF\x9F\x27\xAA\x92\xE9\xA1\xC9\x7F\xCB\xC8\xE7\x7C\x62\xCD\xE4\x57\x3C\xBE\xD4\x52\x49\x16\xE7\x9F\xCF\x81\xCF\x94\x8E\x8E\xCF\x31\x6A\x85\x7A\x13\xDB\x73\x89\xFE\xFA\xFB\x6B\xAD\xA3\xD3\x99\x2C\x60\x5A\x0C\x9F\xF8\x46\x58\x76\x77\x67\x28\xE3\x64\x22\x5E\x59\xD2\xB4\x92\xAB\xCF\xB4\x8E\x80\xF3\x10\xCE\xE8\x5D\x79\xFF\x94\x79\x35\x57\xE6\x03\x3A\x35\xDB\xD2\x10\x94\x7F\x6C\x48\xDF\xC6\xCD\x91\x86\xC5\xBF\x9A\xB2\x2A\x03\x67\x7E\x13\x3B\x3D\x19\x3F\xBB\x2F\x98\x46\x0C\x17\xEC\xD0\xED\x93\x76\xD5\x02\xF6\xEC\x27\x64\xED\xF5\x8E\x9B\x4E\xA9\x4C\x9D\xF7\xB7\x2F\x43\xD4\xA6\xB1\x0E\xA5\xCB\x32\xCA\x16\x84\x66\xA2\xA9\x32\xE2\x16\x64\xEC\x57\xD8\x9A\x8E\x73\x3A\x03\x6B\x37\xC1\x84\x08\x75\x47\x1E\x50\xFE\xB6\xD0\x6A\xFB\x34\xE0\xBD\x71\x65\xC5\x96\x37\x70\x6A\xA6\x86\xEB\xA0";
char keyDecryption_2[0x000001E50];
char keyEncryption_3[0x000001E90] = "\x60\x16\x29\x36\x77\xAF\x1F\x20\xDB\x01\x6F\x38\x64\x9B\x34\x61\xBC\x95\xCA\xDF\x50\xED\xF9\xC6\x4C\x35\xC7\x9F\x9E\xF1\x90\x2B\x06\x79\x07\x92\xA3\x7E\xD3\x3B\x9F\x98\xBD\x41\x60\xCD\x66\x50\x1A\x7D\xBA\xA9\x86\xCF\x9A\x22\x1D\x1D\x4F\xB1\xFD\x88\x53\xB9\x78\x1C\x6B\x64\xEB\x75\x2E\xC8\xDE\xB2\xFF\x8F\xC3\xC3\x50\x52\x6E\x56\xA9\x27\x9B\x5A\x5F\x80\xB9\x84\x54\x78\xAD\xF8\x4C\xC0\xF6\xF3\x15\x6B\xB5\x2A\x8F\x22\x3F\x97\xCC\x92\xD1\x0A\xAD\x9C\x87\x61\x25\x00\x4D\x8B\xD9\xD6\x9F\x35\xCE\x16\xB1\xC1\xC8\x69\x98\x42\xA0\x24\x33\x95\x79\x1F\x24\x8A\x2F\xB6\x9E\x8D\x7A\x97\xBB\x92\x8F\x67\x1E\xE9\xC9\xC9\x40\xA2\xAD\xD6\x72\x5E\x8A\xBF\x35\x52\xEB\x10\xDE\xB0\x7E\x06\x86\x99\x80\xE9\xC4\x78\xEC\xF4\x1F\xF2\x43\x8A\x95\x4F\xF8\x5F\x2D\x33\x65\xF8\xB5\x5B\xCB\xF1\x1C\x56\x2A\x4C\x96\xB4\xE2\x41\x76\x68\x1A\x0C\xB6\x8A\x3C\xC5\x62\x2E\x50\x9D\x25\xF0\x9A\xDE\x33\x45\xDB\xF2\xBA\x77\x3A\xC7\x80\xD1\x48\x4B\x96\x25\x39\xC0";
char keyDecryption_3[0x000001E90];
std::vector<char> bufferReceivedPacket2(123);
//identification key also containing C_check version packet
char bufferReceivedPacket[128] = "\x20\x00\xBC\x4D\x02\x00\x08\x00\x08\x00\x14\x00\x00\x00\x00\x00\x71\x72\x04\x00\x14\x00\x00\x00\x01\x00\x00\x00\xAD\x7A\x04\x00\x5B\x00\x2C\xD1\x13\x00\x29\x00\x32\x00\x00\x00\x00\x00\x00\x06\x00\x00\x00\x55\x00\x51\x00\x4C\x00\x31\x00\x30\x00\x31\x00\x4B\x00\x57\x00\x49\x00\x4C\x00\x00\x00\x5F\x75\x48\x65\x74\x61\x66\x76\x69\x62\x6C\x45\x6D\x35\x6A\x65\x5F\x4B\x6C\x47\x4B\x33\x57\x4B\x77\x6A\x34\x6B\x43\x46\x54\x58\x6B\x50\x58\x35\x61\x52\x50\x37\x44\x6F\x33\x65\x35\x58\x41\x4A\x44\x6E\x4A\x44\x6E\x4A";
void* ptrBufferReceivedPacket = &bufferReceivedPacket;
void* ptrKeyEncryption_1 = &keyEncryption_1;
void* ptrKeyEncryption_2 = &keyEncryption_2;
void* ptrKeyEncryption_3 = &keyEncryption_3;
void* ptrKeyDecryption_1 = &keyDecryption_1;
void* ptrKeyDecryption_2 = &keyDecryption_2;
void* ptrKeyDecryption_3 = &keyDecryption_3;
DWORD someAddress = 0x01CC36F4;
DWORD retrievedAddress;
HWND consoleWindow;
char key[] = "\x0B\xB3\x45\xE1\x46\xD9\x8A\x2C\x56\x1B\xB1\x34\x08\xDF\x13\x3A\xB2\xF5\xD7\x1B\xC6\xD6\x21\xBC\xA6\x29\x87\xAA\xBA\x8C\xC5\x02\xC1\x90\xB1\x8F\x64\x05\x71\x33\x11\x79\xEB\x88\x06\xFB\x7D\xC6\xAC\x25\xEE\xE8\x27\x59\xA5\x0A\x2B\x4A\x19\x16\x11\xBE\x89\x9F\x2A\x93\xED\x0D\x53\x00\x2C\xFB\xC9\x1E\x8F\xDD\x3F\xA7\x76\xE6\x2E\xFD\x4A\x29\x6D\x6E\xB2\xFE\x01\xB6\x0A\xA7\x36\xC5\x11\x33\xEF\xC3\xE1\xA3\x3A\x52\x25\x4C\x27\x13\x86\x7C\xDB\x6B\x66\x60\xE0\x87\xD1\x25\xBF\x9D\xB0\x5E\xD1\x75\x40\xA6\x52\x29\xC3\x86\xB7\x29\x76\x99\x41\x81\xC2\xED\xD3\x5F\xB6\xAD\x01\xCF\xB5\xFD\x69\xCA\x6C\x26\x46\x6F\x07\xF3\x42\x90\xA5\x5B\x8C\x70\x09\x5F\x2B\xCB\x92\x36\x92\x17\x6D\xA8\x74\x0A\x09\xB8\xD9\x5C\xCB\x85\x72\xCE\x04\x72\x29\x6B\x20\x85\xFD\x0E\x20\x0D\x0D\x24\x4A\x88\xF2\xB3\x1E\xC3\x52\x9C\x8D\x43\xB2\x1D\x66\xE4\x8C\x99\x11\xC0\xA2\x9C\x7F\x52\x91\x1A\x61\xDC\xA9\xF7\x98\x05\xFC\xCC\xED\xC7\xB5\xE9\x03\x88\xAC\x96\x89\x87\x37\x9F\xB4\x7A\x42\x0F\xED\x76\xA2\x3B\xC7\x0E\xA6\x02\x33\xBF\xEF\x54\xF7\x8C\x82\xF1\x5C\xE5";
int x;
int nBotNumber(0);
int nFailedRunsCount(0);
string log1;
double dBotTotalHour(0);
double dAverageTimePerCycle;
using namespace boost::asio::ip;
string packetContent3 = "Bot State Logs.txt";
int Items::nId = 0;
//filename = "BotLog1.txt";
void SellKnFunction(boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile);
void KillKnWithThrall(boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile);
void KillKnWithPets(boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile);
ofstream fileout3(packetContent3.c_str());
void BotNumb(int *nBotNumb)
{
	int nRandomInteger = 0;
	std::cin >> nRandomInteger;
	if (*nBotNumb == 0)
		*nBotNumb = nRandomInteger;
}
int main() // this function creates a true connection with the server (!= sniff)
{
	std::vector<int> vTimes;
	ofstream aFile("Enter Times.txt");
	ReadConfigFile();
	if (bAutoLogin == 0)
	{
		GetHandle();
		char chDllName[] = "StealLogInKeyDll.dll";
		InjectDll(chDllName);
		int GameLogAttempt(0);
		std::cout << "Waiting for the game to start a connection attempt." << endl;
		while (GameLogAttempt != 0x10)
		{
			Sleep(500);
			ReadProcessMemory(hProc, (LPCVOID)0x0043425E, &GameLogAttempt, (DWORD)sizeof(retrievedAddress), NULL);
		}
		ReadProcessMemory(hProc, (LPCVOID)0x00434256, &retrievedAddress, (DWORD)sizeof(retrievedAddress), NULL);
		std::cout << "adress i ll read : " << hex << retrievedAddress << endl;
		ReadProcessMemory(hProc, (LPCVOID)retrievedAddress, &bufferReceivedPacket, (DWORD)sizeof(bufferReceivedPacket), NULL);
		std::cout << "Taille buffer read : " << sizeof(bufferReceivedPacket) << endl;
	}
	else // use auto login configuration
	{
		LoginMain(bufferReceivedPacket);
		cout << "here1" << endl;
	}
	// Création du service principal et du résolveur.
	boost::asio::io_service ios;
	// On veut se connecter sur la machine locale, port 7171
	int port = 7801;
	string ipadd = "79.110.94.211";
	if (debug)
	{
		cout << ipadd << " " << port << endl;
	}
	if (bEU)
	{
		if (bKillian)
		port = 7801;
		if (bFR)
			port = 7802;
	}
	if (bNA)
	{
		port = 10001;
	}
	if (bKillian)
	{
		ipadd = "79.110.94.211";
	}
	if (bFR)
	{
		ipadd = "79.110.94.212";
	}
	if (bMT)
	{
		ipadd = "208.67.49.93";
	}
	if (bTR)
	{
		ipadd = "208.67.49.28";
	}
	if (debug)
	{
		cout << ipadd << " " << port << endl;
	}
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ipadd), port);
	boost::shared_ptr<boost::asio::ip::tcp::socket> socket(new boost::asio::ip::tcp::socket(ios));
	boost::system::error_code error;
	cout << bTR << " " << bKillian << " " << bMT << " " << bFR << " " << bNA << bEU << endl;
	socket->connect(endpoint);
	boost::array<char, 132000> buf;
	boost::array<char, 128> buf2;
	int len = socket->read_some(boost::asio::buffer(buf), error);
	std::string msg("\xB7\x29\x76\x99\x41\x81\xC2\xED\xD3\x5F\xB6\xAD\x01\xCF\xB5\xFD\x69\xCA\x6C\x26\x46\x6F\x07\xF3\x42\x90\xA5\x5B\x8C\x70\x09\x5F\x2B\xCB\x92\x36\x92\x17\x6D\xA8\x74\x0A\x09\xB8\xD9\x5C\xCB\x85\x72\xCE\x04\x72\x29\x6B\x20\x85\xFD\x0E\x20\x0D\x0D\x24\x4A\x88\xF2\xB3\x1E\xC3\x52\x9C\x8D\x43\xB2\x1D\x66\xE4\x8C\x99\x11\xC0\xA2\x9C\x7F\x52\x91\x1A\x61\xDC\xA9\xF7\x98\x05\xFC\xCC\xED\xC7\xB5\xE9\x03\x88\xAC\x96\x89\x87\x37\x9F\xB4\x7A\x42\x0F\xED\x76\xA2\x3B\xC7\x0E\xA6\x02\x33\xBF\xEF\x54\xF7\x8C\x82\xF1\x5C\xE5"); // (2)
	CreateArchitectureKey_184_Bytes();
	socket->send(boost::asio::buffer(msg)); // (5)
	len = socket->read_some(boost::asio::buffer(chThirdReadReceivedKey), error);
	if (debug)
	{
	
	cout << "we've read " << len << " bytes." << endl;
    }
ptrReceivedFirstKey = &(chThirdReadReceivedKey);
	if (debug)
	{ 
	cout << "adress of received key : " << ptrReceivedFirstKey << endl;
	for (int kkk = 0; kkk < 128; kkk++)
	{
		printf("0x%02X", chThirdReadReceivedKey[kkk]);
		cout << " ";
	}
	}
	ptrRandomedFirstKey = &chRandomedKey_1;
	ptrRandomedSecondKey = &chRandomedKey_2;
	DecryptReceived_First_128_Bytes();
	ptrSentSecondKey = ptrSecondSentKey;
	cout << "\nSent second key : " << endl;
	unsigned char *array = static_cast<unsigned char*>(ptrSecondSentKey);
	for (int kkk = 0; kkk < 128; kkk++)
	{
		if (debug)
		{ 
		printf("0x%02X", *(array + kkk));
		cout << " ";
		}
		buf2[kkk] = *(array + kkk);
	}
	socket->send(boost::asio::buffer(buf2)); // (5)
	len = socket->read_some(boost::asio::buffer(chFourthReadReceivedKey), error);
	ptrReceivedSecondKey = &chFourthReadReceivedKey;
	if (debug)
	{ 
	cout << "\nEvery key has been sent or received. Pointers to First Randomed, Second Randomed (=First Sent), Second Sent, Second Received key in this order : \n"
		<< ptrRandomedFirstKey << "\n"
		<< ptrRandomedSecondKey << "\n" // at this point the first received key no longer exists within the program
		<< ptrSentSecondKey << "\n"
		<< ptrReceivedSecondKey << endl;
	}
	DecryptReceived_Second_128_Bytes();
	const int nCorrectedSize =  123;//
	const int nCorrectedSize127 = sizeof(bufferReceivedPacket) - 1;
	if (size123 == 123)
	{
		cout << "Sending 123 bytes arbiter" << endl;
		char bufferReceivedPacket_2[nCorrectedSize];
		memcpy(bufferReceivedPacket_2, bufferReceivedPacket, size123);
		//
		socket->send(boost::asio::buffer(bufferReceivedPacket_2)); // (5)
		Sleep(200);
	}
	else
	{
		cout << "Sending 127 bytes arbiter" << endl;
		char bufferReceivedPacket_2[nCorrectedSize127];
		memcpy(bufferReceivedPacket_2, bufferReceivedPacket, nCorrectedSize127);
		//
		socket->send(boost::asio::buffer(bufferReceivedPacket_2)); // (5)
		Sleep(200);
	}
	thread f(HandlePacketReception, socket);
	//	
	while (!Mystic.m_bConnexionState)
	{
		Sleep(200);
	}
	int jh;
	if (Mystic.m_bConnexionState == 1)
	{ 
		jh = 0x04;
	DWORD bonebreaker = 0x0043425A;
	WriteProcessMemory(hProc, (LPVOID) bonebreaker, &jh, (DWORD)sizeof(jh), NULL);
	Sleep(1000); // was 5000
	}
	HandleUndecipheredPacket(size08x08, C_SET_VISIBLE_RANGE, { 0xc4, 0x09, 0x00, 0x00 }, socket);//0x208a
	//
	//thread g(SpamPartyChat, socket);
	//
	Sleep(1000);
	HandlePacket(size04x04, C_GET_USER_LIST, *socket); //bdb7
	//	
	Sleep(1000);
	HandlePacket(size04x04, C_TRADE_BROKER_HIGHEST_ITEM_LEVEL, *socket);
	//
	Sleep(100);
	//HandlePacket(size04x04, C_UNION_SUMMARY, *socket);
	//	
	Sleep(100);
	HandlePacket(size04x04, C_REQUEST_INGAMESTORE_PRODUCT_LIST, *socket);
	//
	Sleep(100);
	HandleUndecipheredPacket(size08x08, C_SIMPLE_TIP_REPEAT_CHECK, { 0x01, 0x00, 0x00, 0x00 }, socket);
	//
	Sleep(100);
	HandleUndecipheredPacket(size08x08, C_SIMPLE_TIP_REPEAT_CHECK, { 0x23, 0x00, 0x00, 0x00 }, socket);//simple tip repeat check
	//
	Sleep(100);
	HandleUndecipheredPacket(size08x08, C_SIMPLE_TIP_REPEAT_CHECK, { 0x27, 0x00, 0x00, 0x00 }, socket);
	//
	Sleep(100);
	HandleUndecipheredPacket(size08x08, C_SIMPLE_TIP_REPEAT_CHECK, { 0x29, 0x00, 0x00, 0x00 }, socket);
	bInsideKn = 0;
	Mystic.m_nStartingGold = Mystic.m_nGoldInventory;
	cout << "Enter the bot number" << endl;
	std::async(BotNumb, &nBotNumber);
	while (nBotNumber == 0)
	{
		Sleep(200);
	}
	if ((nBotNumber == 5) && bKn)
	{
		for (int uuu = 0; uuu < Mystic.m_vMysticName.size(); ++uuu)
			printf("0x%02X ", Mystic.m_vMysticName[uuu]);
		cout << endl;
		for (int uuu = 0; uuu < Mystic.m_vMysticPartner2.size(); ++uuu)
			printf("0x%02X ", Mystic.m_vMysticPartner2[uuu]);
		cout << endl;
		for (int uuu = 0; uuu < Mystic.m_vMysticPartner.size(); ++uuu)
			printf("0x%02X ", Mystic.m_vMysticPartner[uuu]);
		cout << endl;
		if (Mystic.m_vMysticName == Mystic.m_vMysticPartner2)
		{
			PartyInvite(Mystic.m_vMysticPartner, *socket);
			cout << "Ok" << endl;
		}
		else if (Mystic.m_vMysticName == Mystic.m_vMysticPartner)
		{
			PartyInvite(Mystic.m_vMysticPartner2, *socket);
			cout << "Ok2" << endl;
		}
		Sleep(1000);
		PartyInvite(Mystic.m_vWatcher, *socket);
		Sleep(1000);
		contractPtr.reset();
		nBotNumber = 2;
		HandleUndecipheredPacket(size62x3e, C_CHAT, { 0x0a, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x46, 0x00, 0x4f, 0x00, 0x4e, 0x00, 0x54, 0x00, 0x3e, 0x00, 0x2E, 0x00, 0x6E, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x62, 0x00, 0x65, 0x00, 0x72, 0x00, 0x31, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3c, 0x00, 0x2f, 0x00, 0x46, 0x00, 0x4f, 0x00, 0x4e, 0x00, 0x54, 0x00, 0x3e, 0x00, 0x00, 0x00 }, socket);
	}
	tStartingTime = time(0);
	int angle;
	if (bPowerLevel)
	{
		PowerLevel(socket);
		//PowerLevelNeedle(socket);
	}
	if(bPowerLeveled)
	{
		PowerLeveled( fileout3, socket);
	}
	while (0)
	{
		cin >> nBotNumber;
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, { 0x74, 0x98, 0x02, 0x04, 0x24, 0xF7, 0xF3, 0x9D, 0x74, 0x47, 0x33, 0xAA, 0x11, 0x48, 0x13, 0x0B, 0x14, 0xC6, 0x81, 0xcd, 0x7d, 0x47, 0xee, 0xd0, 0x0d, 0x48, 0xF9, 0xD3, 0x13, 0xC6, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, socket);

	}
	while (bWatcher)
	{
		//GoToTheseCoordonateAtThisSpeed(500, 0x4604e672, 0x47087b1c, 0x46124438, *socket); this places up the pillar the watcher
		GoToTheseCoordonateAtThisSpeed(500, 0x4614BEC6, 0x47034D5B, 0x460E8C00, *socket);
		while (1)
		{
			if ((!nNumberOfEnnemies) && (Monsters::m_nRegisteredMonters <= 1))
			{
				if (nThereWasEnnemy)
				{
					PlayerJustLeft();
					nThereWasEnnemy = 0;
				}
				if (!(KeepOnWaitingSafety()))
					HandleUndecipheredPacket(size58x3a, C_CHAT, vSignalClearPacket, socket);
				else
					cout << "It has been less than 20 minutes since an unexpected player was around." << endl;
				Sleep(1000);
			}
			else
			{
				nThereWasEnnemy = 1;
				Sleep(1000);
				cout << "there is : " << nNumberOfEnnemies << " ennemies." << endl;
				cout << "there is : " << Monsters::m_nRegisteredMonters << " detected players under the form of monsters." << endl;
			}
		}
	}
	while (0)//bKn)
	{
		if (((nNumerOfRuns + nBotNumber + 1) % 2) == 0)//sell pattern
		{
			WriteStatsFile();
			++nNumerOfRuns;
			log1 = "run n# ";
			log1 += std::to_string(nNumerOfRuns);
			WriteToFile(log1);
			fileout3 << "getting near tp npc in order to enter" << endl;
			log1 = "getting near tp npc in order to enter";
			WriteToFile(log1);
			Sleep(1000);//4000 before spawnme rewrite
			/*
			while (wantedXEnterKnDungeon != currentX)
			{
				MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			*/
			GoToTheseCoordonateAtThisSpeedUndetected(Mystic.m_nSpeed, wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon, 0x460a4b80, *socket);
			Sleep(3800);
			fileout3 << "enterdungeonwhenrdy function" << endl;
			log1 = "enterdungeonwhenrdy function";
			time_t tStartEnter = time(0);
			WriteToFile(log1);
			EnterDungeonWhenReady(*socket);
			int iii(0);
			while ((!bInsideKn))
			{
				++iii;
				if (iii >= 25)
				{
					int nRand;
					srand(time(0));
					nRand = rand() % 6;
					Sleep(nRand);
					EnterDungeonWhenReady(*socket);
					Sleep(9000);
					if (iii == 25)
					{
						log1 = "Troubles entering at run# ";
						log1 += (std::to_string(nNumerOfRuns));
						WriteToFile(log1);
					}
				}
				Sleep(1000);
			}
			time_t tEndEnter = time(0);
			int anInt = difftime(tEndEnter, tStartEnter);
			vTimes.push_back(anInt);
			for (auto it = vTimes.begin(); it != vTimes.end(); ++it)
				aFile << *it << " ";
			aFile << endl;
			vNpc_Menu_SelectionLatest.clear();
			vSendSkillPacket2 = FormSendSkillPacket(auraSpeedBuff);
			HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
			Sleep(8000);//makes sure other mystic doesnt receive dialogs
			fileout3 << "got inside Kn, heading up to Npc for selling" << endl;
			log1 = "got inside Kn, heading up to Npc for selling";
			WriteToFile(log1);
			while (InterractSellNpcKnX != currentX)
			{
				MovementPacket2 = ForMovementPacket(InterractSellNpcKnX, InterractSellNpcKnY, InterractSellNpcKnZ);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			//
			
			ReleaseAllItemSellPointers();
			HandleUndecipheredPacket(size12x0C, C_NPC_CONTACT, vNewNpcSellerId, socket);
			Sleep(3000);
			StoreEveryFittingItem(*socket);
			fileout3 << "finished selling." << endl;
			Sleep(3000); // Gives more room for movement packets or for server packets to arrive (S_iNVEN)
			
			fileout3 << "moving to entrance away from npc." << endl;
			log1 = "moving to entrance away from npc.";
			WriteToFile(log1);
			while (KnEntranceInsideDungeonX != currentX)
			{
				MovementPacket2 = ForMovementPacket(KnEntranceInsideDungeonX, KnEntranceInsideDungeonY, KnEntranceInsideDungeonZ);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			if (bTeraClub)
			{
				cGoldBoost.UseSkill(size08x08, C_PCBANGINVENTORY_USE_SLOT, { 0x01, 0x00, 0x00, 0x00 }, socket);
			}
			HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2e, 0x00, 0x72, 0x00, 0x65, 0x00, 0x61, 0x00, 0x64, 0x00, 0x79, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
			fileout3 << "moved, the bot has done : " << nNumerOfRuns << " runs so far." << endl;
			log1 = "moved, the bot has done :  runs so far.";
			WriteToFile(log1);
			int jjj = 0;
			while (bInsideKn)
			{
				Sleep(1000);
				++jjj;
				if (jjj > 500)
				{
					cout << "stuck at this iteration n°1" << endl;//packets ready gets resent in case main bot took too much time to enter
					HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2e, 0x00, 0x72, 0x00, 0x65, 0x00, 0x61, 0x00, 0x64, 0x00, 0x79, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
				}
			}
			//cin >> x;
		}
		else // ================================================================================================= Kill Kn Path
		{
			WriteStatsFile();
			++nNumerOfRuns;
			log1 = "run n# ";
			log1 += std::to_string(nNumerOfRuns);
			WriteToFile(log1);
			fileout3 << "Mystic currently has : " << Mystic.m_nGoldInventory << " gold." << endl;
			Mystic.m_dAverageGph = (Mystic.m_nGoldInventory - Mystic.m_nStartingGold) / dBotTotalHour;
			fileout3 << "The current GPH is : " << Mystic.m_dAverageGph << "." << endl;
			Mystic.m_bPartnerReady = 0; // partner will turn this flag around once ready
			fileout3 << "getting near tp npc in order to enter" << endl;
			log1 = "getting near tp npc in order to enter";
			WriteToFile(log1);
			Sleep(1000);//fixes the crashs after reset ##deleted after spawnme rewrite 3000
			/*
			while (wantedXEnterKnDungeon != currentX)
			{
				MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			*/
			GoToTheseCoordonateAtThisSpeedUndetected(Mystic.m_nSpeed, wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon, 0x460a4b80, *socket);
			Sleep(500);//800 before spawnme rewrite
			fileout3 << "enterdungeonwhenrdy function" << endl;
			log1 = "enterdungeonwhenrdy function";
			WriteToFile(log1);
			time_t tStartEnter = time(0);
			EnterDungeonWhenReady(*socket);
			int iii(0);
			while ((!bInsideKn))
			{
				Sleep(1000);
				++iii;
				if (iii >= 8)
				{
					EnterDungeonWhenReady(*socket);
				}
			}
			Sleep(1000);
			time_t tEndEnter = time(0);
			int anInt = difftime(tEndEnter, tStartEnter);
			vTimes.push_back(anInt);
			for (auto it = vTimes.begin(); it != vTimes.end(); ++it)
				aFile << *it << " ";
			aFile << endl;
			vSendSkillPacket2 = FormSendSkillPacket(auraSpeedBuff);
			HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
			Sleep(1600);
			fileout3 << "heading up to Kn stairs" << endl;
			log1 = "heading up to Kn stairs";
			WriteToFile(log1);
			
			while (wantedXForKnStairs != currentX)
			{
				MovementPacket2 = ForMovementPacket(wantedXForKnStairs, wantedYForKnStairs, wantedZForKnStairs);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);//was 450
			}
			
			fileout3 << "timer." << endl;
			log1 = "timer.";
			WriteToFile(log1);
			timersUsa();
			currentX = wantedXForEaxKnFeetInt - 5;
			currentY = wantedYForEaxKnFeetInt - 5;
			while (wantedXForEaxKnFeetInt != currentX)
			{
				MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
				HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
				Sleep(Mystic.m_nSpeed);
			}
			fileout3 << "Fight with Kn" << endl;
			log1 = "Fight with Kn";
			WriteToFile(log1);
			bThrallActions = 0;
			vSendSkillPacket2 = FormSendSkillPacket(ThrallWrathId);
			HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
			Sleep(2900);//2200 eu before brawler
	while (wantedZForEaxKnInvincibleFeetInt != currentZ)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnInvincibleFeetInt, wantedYForEaxKnInvincibleFeetInt, wantedZForEaxKnInvincibleFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	//was after sleep2200
	if (ptrMobKn)
	{
		vSendSkillPacket2 = FormSendSkillPacketWithTarget(orderPetAttack, ptrMobKn->m_Id);
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	}
	else
		fileout3 << "WARNING ! THERE WAS NO KELSAIK INSIDE THE DUNGEON" << endl;
	Sleep(1000);//was 250 before brawler
	//
	if (ptrMobKn)
	{ 
		int jjj(0);
		Sleep(1000);//if no fail put this to lower amount
		double tTimeInWhile;
		time_t tStartWhileTime = time(0);
		tCurrentTime = time(0);
		tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
		while ((ptrMobKn->m_LifeState) && (tTimeInWhile <= 22))
		{
			tCurrentTime = time(0);
			tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
			cThrall.UseSkill(size45x2d, C_START_SKILL, { 0x04, 0x69, 0x06, 0x04, 0x80, 0x0F, 0x6F, 0x64, 0x8F, 0x47, 0x48, 0x95, 0x0B, 0x48, 0xD7, 0xB4, 0x2D, 0xC6, 0x62, 0x93, 0x8F, 0x47, 0x10, 0x9E, 0x0B, 0x48, 0xBA, 0x3E, 0x2D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, socket);
			if (bThrallActions)
			{
				for (int uuu = 0; uuu < 18; ++uuu)
				{
					HandleUndecipheredPacket(size26x1a, C_NOTIFY_SPIRIT_LOCATION_IN_ACTION, vPacketThrallToBeSent, socket);
				}
				--bThrallActions;
			}
			Sleep(20);
		}
		if (ptrMobKn ->m_LifeState == 0)
			fileout3 << "Kelsaik died." << endl;
		Sleep(5000);//if you take this out you will get in combat during run
		if (ptrMobKn)
			ptrMobKn.reset();//assuming it is dead
		else
			fileout3 << "ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! " << endl;
	Sleep(1500); //receive the spawn item packet
	if (!ptrItem1)
	{ 
		++nFailedRunsCount;
		fileout3 << "!! no item are registered, (kelsaik did not die ?)" << endl;
	}
	else
	{
		fileout3 << "will loot, there is at least 1 registered item" << endl;
		string log1 = "will loot, there is at least 1 registered item";
		WriteToFile(log1);
	}
	LootEveryRegisteredItem(*socket);
	}
	log1 = "The partner is not ready yet";
	while (!Mystic.m_bPartnerReady)
	{
		Sleep(500);
		cout << "The partner is not ready yet" << endl;
		WriteToFile(log1);
	}
	nNumberOfEnnemies = 1;
	fileout3 << "waitingennemies to clear of the zone." << endl;
	log1 = "waitingennemies to clear of the zone.";
	WriteToFile(log1);
	Sleep(1300); // waits before sending reset packet
	while (nNumberOfEnnemies)
	{
		Sleep(500);
		cout << "there is " << nNumberOfEnnemies << " ennemies." << endl;
	}
	tCurrentTime = time(0);
	dBotTotalHour = (difftime(tCurrentTime, tStartingTime)) / 3600;
	fileout3 << "The bot has been running for : " << dBotTotalHour << " hours." << endl;
	fileout3 << "the bot has done : " << nNumerOfRuns << " runs so far." << endl;
	double dPercentageFailure = double(nFailedRunsCount)*2*100/nNumerOfRuns;
	dAverageTimePerCycle = (difftime(tCurrentTime, tStartingTime)) * 2 / nNumerOfRuns;
	fileout3 << "There have been : " << nFailedRunsCount << " failed runs. This represent a failure of : " << dPercentageFailure << " %." << endl;
	fileout3 << "The average time per cycle is : " << dAverageTimePerCycle << " seconds." << endl;
	fileout3 << "will now reset" << endl;
	log1 = "will now reset";
	WriteToFile(log1);
	if (Mystic.bm_LeaderState == 0)
	HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
	if (Mystic.bm_LeaderState == 1)
	HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
	int jjj = 0;
	while (bInsideKn && (Mystic.m_bConnexionState == 1))
	{
		Sleep(1000);
		++jjj;
		if (jjj > 50)
		{
			cout << "stuck at this iteration n°1" << endl;
			if (Mystic.bm_LeaderState == 0)
			HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
			else if (Mystic.bm_LeaderState == 1)
			HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
		}
		if (jjj == 50)
			Beep(5000, 300);
	}
	fileout3 << "the new loop is about to start" << endl;
	}
	}
	while (0)
	{
		KillKnWithPets(socket, vTimes, aFile);
	}
	bool bTestPattern = 1;
	while (bTestPattern)
	{
		if (((nBotNumber) % 2) == 0)
		{
			if ((nNumerOfRuns % 4) == 0)
				KillKnWithThrall(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 1)
				SellKnFunction(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 2)
				KillKnWithPets(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 3)
				SellKnFunction(socket, vTimes, aFile);
		}
		else // nBotNumber impair
		{
			if ((nNumerOfRuns % 4) == 0)
				SellKnFunction(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 1)
				KillKnWithThrall(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 2)
				SellKnFunction(socket, vTimes, aFile);
			else if ((nNumerOfRuns % 4) == 3)
				KillKnWithPets(socket, vTimes, aFile);
		}
	}
	return 0;

}
//########################################################################End of main function
void WriteStatsFile()
{
	ofstream foutStat("Stats.txt");
	foutStat << "GPH : " << Mystic.m_dAverageGph << endl;
	foutStat << "Mystic current gold : " << Mystic.m_nGoldInventory << endl;
	foutStat << "Mystic number of runs : " << nNumerOfRuns << endl;
	foutStat << "Mystic average cycle time : " << dAverageTimePerCycle << endl;
	foutStat << "The bot has been running for : " << dBotTotalHour << " hours." << endl;
	foutStat << "The amount of dropped items is : " << Mystic.m_nDroppedItems << endl;
	foutStat << "The amount of picked up items is : " << (Mystic.m_nPickedItems)/2<< endl;
	foutStat << "Amount of fileterd Items at pick up is : " << Mystic.m_nFilteredPickUpItems << endl;
}
void SellKnFunction(boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile)
{
	WriteStatsFile();
	++nNumerOfRuns;
	log1 = "run n# ";
	log1 += std::to_string(nNumerOfRuns);
	WriteToFile(log1);
	fileout3 << "getting near tp npc in order to enter" << endl;
	log1 = "getting near tp npc in order to enter";
	WriteToFile(log1);
	Sleep(1000);// deleted on 02.11.16
	/*
	while (wantedXEnterKnDungeon != currentX)
	{
	MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
	HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
	Sleep(Mystic.m_nSpeed);
	}
	*/
	GoToTheseCoordonateAtThisSpeedUndetected(Mystic.m_nSpeed, wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon, 0x460a4b80, *socket);
	//Sleep(1000); // 02.11.16 Sleep(3800);
	fileout3 << "enterdungeonwhenrdy function" << endl;
	log1 = "enterdungeonwhenrdy function";
	time_t tStartEnter = time(0);
	WriteToFile(log1);
	EnterDungeonWhenReady(*socket);
	int iii(0);
	while ((!bInsideKn))
	{
		Sleep(1000);
		++iii;
		if (iii >= 10)
		{
			int nRand;
			srand(time(0));
			nRand = rand() % 6;
			Sleep(nRand);
			EnterDungeonWhenReady(*socket);
			Sleep(9000);
			if (iii == 10)
			{
				log1 = "Troubles entering at run# ";
				log1 += (std::to_string(nNumerOfRuns));
				WriteToFile(log1);
			}
		}
	}
	time_t tEndEnter = time(0);
	int anInt = difftime(tEndEnter, tStartEnter);
	vTimes.push_back(anInt);
	for (auto it = vTimes.begin(); it != vTimes.end(); ++it)
		aFile << *it << " ";
	aFile << endl;
	vNpc_Menu_SelectionLatest.clear();
	Sleep(2500);//need to get npc id  02.11.16 Sleep(8000);//makes sure other mystic doesnt receive dialogs
	fileout3 << "got inside Kn, heading up to Npc for selling" << endl;
	log1 = "got inside Kn, heading up to Npc for selling";
	WriteToFile(log1);
	while (InterractSellNpcKnX != currentX)
	{
		MovementPacket2 = ForMovementPacket(InterractSellNpcKnX, InterractSellNpcKnY, InterractSellNpcKnZ);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	//

	ReleaseAllItemSellPointers();
	HandleUndecipheredPacket(size12x0C, C_NPC_CONTACT, vNewNpcSellerId, socket);
	Sleep(3000);
	StoreEveryFittingItem(*socket);
	fileout3 << "finished selling." << endl;
	Sleep(3000); // Gives more room for movement packets or for server packets to arrive (S_iNVEN)

	fileout3 << "moving to entrance away from npc." << endl;
	log1 = "moving to entrance away from npc.";
	WriteToFile(log1);
	while (KnEntranceInsideDungeonX != currentX)
	{
		MovementPacket2 = ForMovementPacket(KnEntranceInsideDungeonX, KnEntranceInsideDungeonY, KnEntranceInsideDungeonZ);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	if (bTeraClub)
	{
		cGoldBoost.UseSkill(size08x08, C_PCBANGINVENTORY_USE_SLOT, { 0x01, 0x00, 0x00, 0x00 }, socket);
	}
	HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2e, 0x00, 0x72, 0x00, 0x65, 0x00, 0x61, 0x00, 0x64, 0x00, 0x79, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
	fileout3 << "moved, the bot has done : " << nNumerOfRuns << " runs so far." << endl;
	log1 = "moved, the bot has done :  runs so far.";
	WriteToFile(log1);
	int jjj = 0;
	while (bInsideKn)
	{
		Sleep(1000);
		++jjj;
		if (jjj > 500)
		{
			cout << "stuck at this iteration n°1" << endl;//packets ready gets resent in case main bot took too much time to enter
			HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2e, 0x00, 0x72, 0x00, 0x65, 0x00, 0x61, 0x00, 0x64, 0x00, 0x79, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
		}
	}
}
void KillKnWithPets (boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile)
{
	WriteStatsFile();
	++nNumerOfRuns;
	log1 = "run n# ";
	log1 += std::to_string(nNumerOfRuns);
	WriteToFile(log1);
	fileout3 << "Mystic currently has : " << Mystic.m_nGoldInventory << " gold." << endl;
	Mystic.m_dAverageGph = (Mystic.m_nGoldInventory - Mystic.m_nStartingGold) / dBotTotalHour;
	fileout3 << "The current GPH is : " << Mystic.m_dAverageGph << "." << endl;
	Mystic.m_bPartnerReady = 0; // partner will turn this flag around once ready
	fileout3 << "getting near tp npc in order to enter" << endl;
	log1 = "getting near tp npc in order to enter";
	WriteToFile(log1);
	// 02.11.16 Sleep(1000);//fixes the crashs after reset ##deleted after spawnme rewrite 3000
	/*
	while (wantedXEnterKnDungeon != currentX)
	{
	MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
	HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
	Sleep(Mystic.m_nSpeed);
	}
	*/
	// 02.11.16 GoToTheseCoordonateAtThisSpeedUndetected(Mystic.m_nSpeed, wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon, 0x460a4b80, *socket);
	// 02.11.16 Sleep(500);//800 before spawnme rewrite
	fileout3 << "enterdungeonwhenrdy function" << endl;
	log1 = "enterdungeonwhenrdy function";
	WriteToFile(log1);
	time_t tStartEnter = time(0);
	EnterDungeonWhenReady(*socket);
	int iii(0);
	while ((!bInsideKn))
	{
		Sleep(100);//was 1000 02.11.16
		++iii;
		if (iii >= 100) // was 10 02.11.16
		{
			int nRand;
			srand(time(0));
			nRand = rand() % 6;
			Sleep(nRand);
			EnterDungeonWhenReady(*socket);
			Sleep(9000);
			if (iii == 10)
			{
				log1 = "Troubles entering at run# ";
				log1 += (std::to_string(nNumerOfRuns));
				WriteToFile(log1);
			}
		}
	}
	Sleep(300);////02.11.16 Sleep(1000);
	time_t tEndEnter = time(0);
	int anInt = difftime(tEndEnter, tStartEnter);
	vTimes.push_back(anInt);
	for (auto it = vTimes.begin(); it != vTimes.end(); ++it)
		aFile << *it << " ";
	aFile << endl;
	fileout3 << "heading up to Kn stairs" << endl;
	log1 = "heading up to Kn stairs";
	WriteToFile(log1);
	if (!Mystic.m_bTpHack)
	{
		while (wantedXForKnStairs != currentX)
		{
			MovementPacket2 = ForMovementPacket(wantedXForKnStairs, wantedYForKnStairs, wantedZForKnStairs);
			HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
			Sleep(Mystic.m_nSpeed);//was 450
		}
	}
	vSendSkillPacket2 = FormSendSkillPacket(agroPet);
	HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	Sleep(2100);
	currentX = wantedXForEaxKnFeetInt - 5;
	currentY = wantedYForEaxKnFeetInt - 5;
	while (wantedXForEaxKnFeetInt != currentX)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	Sleep(1000); // finishes cast before vengeance pet
	fileout3 << "Fight with Kn" << endl;
	log1 = "Fight with Kn";
	WriteToFile(log1);
	bThrallActions = 0;
	vSendSkillPacket2 = FormSendSkillPacket(vengeancePet);
	HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	Sleep(1600);//2200 eu before brawler
	while (wantedZForEaxKnInvincibleFeetInt != currentZ)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnInvincibleFeetInt, wantedYForEaxKnInvincibleFeetInt, wantedZForEaxKnInvincibleFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	//was after sleep2200
	if (ptrMobKn)
	{
		vSendSkillPacket2 = FormSendSkillPacketWithTarget(orderPetAttack, ptrMobKn->m_Id);
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	}
	else
		fileout3 << "WARNING ! THERE WAS NO KELSAIK INSIDE THE DUNGEON" << endl;
	Sleep(1000);//was 250 before brawler
	//
	if (ptrMobKn)
	{
		int jjj(0);
		Sleep(1000);//if no fail put this to lower amount
		double tTimeInWhile;
		time_t tStartWhileTime = time(0);
		tCurrentTime = time(0);
		tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
		while ((ptrMobKn->m_LifeState) && (tTimeInWhile <= 38))//38 and not 22 because no thrall
		{
			tCurrentTime = time(0);
			tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
			cThrall.UseSkill(size45x2d, C_START_SKILL, { 0x04, 0x69, 0x06, 0x04, 0x80, 0x0F, 0x6F, 0x64, 0x8F, 0x47, 0x48, 0x95, 0x0B, 0x48, 0xD7, 0xB4, 0x2D, 0xC6, 0x62, 0x93, 0x8F, 0x47, 0x10, 0x9E, 0x0B, 0x48, 0xBA, 0x3E, 0x2D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, socket);
			if (bThrallActions > 0)
			{
				for (int uuu = 0; uuu < 18; ++uuu)
				{
					HandleUndecipheredPacket(size26x1a, C_NOTIFY_SPIRIT_LOCATION_IN_ACTION, vPacketThrallToBeSent, socket);
				}
				--bThrallActions;
			}
			Sleep(20);
		}
		if (ptrMobKn->m_LifeState == 0)
			fileout3 << "Kelsaik died." << endl;
		Sleep(5000);//if you take this out you will get in combat during run
		if (ptrMobKn)
			ptrMobKn.reset();//assuming it is dead
		else
			fileout3 << "ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! " << endl;
		Sleep(1000); //receive the spawn item packet 02.11.16 was 1500
		if (!ptrItem1)
		{
			++nFailedRunsCount;
			fileout3 << "!! no item are registered, (kelsaik did not die ?)" << endl;
			log1 = "!! no item are registered, (kelsaik did not die ?)";
			WriteToFile(log1);
		}
		else
		{
			fileout3 << "will loot, there is at least 1 registered item" << endl;
			string log1 = "will loot, there is at least 1 registered item";
			WriteToFile(log1);
		}
		LootEveryRegisteredItem(*socket);
	}
	log1 = "The partner is not ready yet";
	while (!Mystic.m_bPartnerReady)
	{
		Sleep(500);
		cout << "The partner is not ready yet" << endl;
		WriteToFile(log1);
	}
	nNumberOfEnnemies = 1;
	fileout3 << "waitingennemies to clear of the zone." << endl;
	log1 = "waitingennemies to clear of the zone.";
	WriteToFile(log1);
	// 02.11.16 Sleep(1300); // waits before sending reset packet
	while (nNumberOfEnnemies)
	{
		Sleep(500);
		cout << "there is " << nNumberOfEnnemies << " ennemies." << endl;
	}
	tCurrentTime = time(0);
	dBotTotalHour = (difftime(tCurrentTime, tStartingTime)) / 3600;
	fileout3 << "The bot has been running for : " << dBotTotalHour << " hours." << endl;
	fileout3 << "the bot has done : " << nNumerOfRuns << " runs so far." << endl;
	double dPercentageFailure = double(nFailedRunsCount) * 2 * 100 / nNumerOfRuns;
	dAverageTimePerCycle = (difftime(tCurrentTime, tStartingTime)) * 2 / nNumerOfRuns;
	fileout3 << "There have been : " << nFailedRunsCount << " failed runs. This represent a failure of : " << dPercentageFailure << " %." << endl;
	fileout3 << "The average time per cycle is : " << dAverageTimePerCycle << " seconds." << endl;
	fileout3 << "will now reset" << endl;
	log1 = "will now reset";
	WriteToFile(log1);
	if (Mystic.bm_LeaderState == 0)
		HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
	if (Mystic.bm_LeaderState == 1)
		HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
	int jjj = 0;
	while (bInsideKn && (Mystic.m_bConnexionState == 1))
	{
		Sleep(100); //02.11.16 was 1000
		++jjj;
		if (jjj > 500) // 02.11.16 was 50
		{
			Sleep(900); //02.11.16 added to compensate and avoid spam
			cout << "stuck at this iteration n°1" << endl;
			if (Mystic.bm_LeaderState == 0)
				HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
			else if (Mystic.bm_LeaderState == 1)
				HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
		}
		if (jjj == 50)
			Beep(5000, 300);
	}
	fileout3 << "the new loop is about to start" << endl;
}
void KillKnWithThrall(boost::shared_ptr<boost::asio::ip::tcp::socket> &socket, std::vector<int> & vTimes, ofstream& aFile)
{
	WriteStatsFile();
	++nNumerOfRuns;
	log1 = "run n# ";
	log1 += std::to_string(nNumerOfRuns);
	WriteToFile(log1);
	fileout3 << "Mystic currently has : " << Mystic.m_nGoldInventory << " gold." << endl;
	Mystic.m_dAverageGph = (Mystic.m_nGoldInventory - Mystic.m_nStartingGold) / dBotTotalHour;
	fileout3 << "The current GPH is : " << Mystic.m_dAverageGph << "." << endl;
	Mystic.m_bPartnerReady = 0; // partner will turn this flag around once ready
	fileout3 << "getting near tp npc in order to enter" << endl;
	log1 = "getting near tp npc in order to enter";
	WriteToFile(log1);
	// 02.11.16 Sleep(1000);//fixes the crashs after reset ##deleted after spawnme rewrite 3000
	/*
	while (wantedXEnterKnDungeon != currentX)
	{
	MovementPacket2 = ForMovementPacket(wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon);
	HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
	Sleep(Mystic.m_nSpeed);
	}
	*/
	// 02.11.16 GoToTheseCoordonateAtThisSpeedUndetected(Mystic.m_nSpeed, wantedXEnterKnDungeon, wantedYEnterKnDungeon, wantedZEnterKnDungeon, 0x460a4b80, *socket);
	//Sleep(500) 02.11.16 ;//800 before spawnme rewrite
	fileout3 << "enterdungeonwhenrdy function" << endl;
	log1 = "enterdungeonwhenrdy function";
	WriteToFile(log1);
	time_t tStartEnter = time(0);
	EnterDungeonWhenReady(*socket);
	int iii(0);
	while ((!bInsideKn))
	{
		Sleep(100); // 02.11.16 1000
		++iii;
		if (iii >= 100) // 02.11.16 10
		{
			int nRand;
			srand(time(0));
			nRand = rand() % 6;
			Sleep(nRand);
			EnterDungeonWhenReady(*socket);
			Sleep(9000);
			if (iii == 10)
			{
				log1 = "Troubles entering at run# ";
				log1 += (std::to_string(nNumerOfRuns));
				WriteToFile(log1);
			}
		}
	}
	// 02.11.16 Sleep(1000);
	time_t tEndEnter = time(0);
	int anInt = difftime(tEndEnter, tStartEnter);
	vTimes.push_back(anInt);
	for (auto it = vTimes.begin(); it != vTimes.end(); ++it)
		aFile << *it << " ";
	aFile << endl;
	//vSendSkillPacket2 = FormSendSkillPacket(auraSpeedBuff); 02.11.16
	//HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket); 02.11.16
	//Sleep(1600); 02.11.16
	fileout3 << "heading up to Kn stairs" << endl;
	log1 = "heading up to Kn stairs";
	WriteToFile(log1);
	if (!Mystic.m_bTpHack)
	{
		while (wantedXForKnStairs != currentX)
		{
			MovementPacket2 = ForMovementPacket(wantedXForKnStairs, wantedYForKnStairs, wantedZForKnStairs);
			HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
			Sleep(Mystic.m_nSpeed);//was 450
		}
	}
	Sleep(400);//02.11.16 inserts some delay to avoid thrall failures
	fileout3 << "timer." << endl;
	log1 = "timer.";
	WriteToFile(log1);
	int nTimeWaited = timersUsa();
	if (nTimeWaited)
	{
		fileout3 << "Bot waited for thrall CD : " << nTimeWaited << "seconds" << endl;
		log1 = "Bot waited for thrall CD : " + nTimeWaited;
		log1 += " seconds";
		WriteToFile(log1);
	}
	currentX = wantedXForEaxKnFeetInt - 5;
	currentY = wantedYForEaxKnFeetInt - 5;
	while (wantedXForEaxKnFeetInt != currentX)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	fileout3 << "Fight with Kn" << endl;
	log1 = "Fight with Kn";
	WriteToFile(log1);
	bThrallActions = 0;
	vSendSkillPacket2 = FormSendSkillPacket(ThrallWrathId);
	HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	Sleep(2900);//2200 eu before brawler
	while (wantedZForEaxKnInvincibleFeetInt != currentZ)
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnInvincibleFeetInt, wantedYForEaxKnInvincibleFeetInt, wantedZForEaxKnInvincibleFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(Mystic.m_nSpeed);
	}
	//was after sleep2200
	if (ptrMobKn)
	{
		vSendSkillPacket2 = FormSendSkillPacketWithTarget(orderPetAttack, ptrMobKn->m_Id);
		HandleUndecipheredPacket(size45x2d, C_START_SKILL, vSendSkillPacket2, socket);
	}
	else
		fileout3 << "WARNING ! THERE WAS NO KELSAIK INSIDE THE DUNGEON" << endl;
	Sleep(1000);//was 250 before brawler
	//
	if (ptrMobKn)
	{
		int jjj(0);
		Sleep(1000);//if no fail put this to lower amount
		double tTimeInWhile;
		time_t tStartWhileTime = time(0);
		tCurrentTime = time(0);
		tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
		while ((ptrMobKn->m_LifeState) && (tTimeInWhile <= 22))
		{
			tCurrentTime = time(0);
			tTimeInWhile = difftime(tCurrentTime, tStartWhileTime);
			cThrall.UseSkill(size45x2d, C_START_SKILL, { 0x04, 0x69, 0x06, 0x04, 0x80, 0x0F, 0x6F, 0x64, 0x8F, 0x47, 0x48, 0x95, 0x0B, 0x48, 0xD7, 0xB4, 0x2D, 0xC6, 0x62, 0x93, 0x8F, 0x47, 0x10, 0x9E, 0x0B, 0x48, 0xBA, 0x3E, 0x2D, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, socket);
			if (bThrallActions)
			{
				for (int uuu = 0; uuu < 18; ++uuu)
				{
					HandleUndecipheredPacket(size26x1a, C_NOTIFY_SPIRIT_LOCATION_IN_ACTION, vPacketThrallToBeSent, socket);
				}
				--bThrallActions;
			}
			Sleep(20);
		}
		if (ptrMobKn->m_LifeState == 0)
			fileout3 << "Kelsaik died." << endl;
		Sleep(5000);//if you take this out you will get in combat during run
		if (ptrMobKn)
			ptrMobKn.reset();//assuming it is dead
		else
			fileout3 << "ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! ERROR !!!! You SHOULD NOT SEE THIS !!! " << endl;
		Sleep(1000); //receive the spawn item packet 02.11.16 was 1500
		if (!ptrItem1)
		{
			++nFailedRunsCount;
			fileout3 << "!! no item are registered, (kelsaik did not die ?)" << endl;
		}
		else
		{
			fileout3 << "will loot, there is at least 1 registered item" << endl;
			string log1 = "will loot, there is at least 1 registered item";
			WriteToFile(log1);
		}
		LootEveryRegisteredItem(*socket);
	}
	log1 = "The partner is not ready yet";
	while (!Mystic.m_bPartnerReady)
	{
		Sleep(500);
		cout << "The partner is not ready yet" << endl;
		WriteToFile(log1);
	}
	nNumberOfEnnemies = 1;
	fileout3 << "waitingennemies to clear of the zone." << endl;
	log1 = "waitingennemies to clear of the zone.";
	WriteToFile(log1);
	// 02.11.16 Sleep(1300); // waits before sending reset packet
	while (nNumberOfEnnemies)
	{
		Sleep(500);
		cout << "there is " << nNumberOfEnnemies << " ennemies." << endl;
	}
	tCurrentTime = time(0);
	dBotTotalHour = (difftime(tCurrentTime, tStartingTime)) / 3600;
	fileout3 << "The bot has been running for : " << dBotTotalHour << " hours." << endl;
	fileout3 << "the bot has done : " << nNumerOfRuns << " runs so far." << endl;
	double dPercentageFailure = double(nFailedRunsCount) * 2 * 100 / nNumerOfRuns;
	dAverageTimePerCycle = (difftime(tCurrentTime, tStartingTime)) * 2 / nNumerOfRuns;
	fileout3 << "There have been : " << nFailedRunsCount << " failed runs. This represent a failure of : " << dPercentageFailure << " %." << endl;
	fileout3 << "The average time per cycle is : " << dAverageTimePerCycle << " seconds." << endl;
	fileout3 << "will now reset" << endl;
	log1 = "will now reset";
	WriteToFile(log1);
	if (Mystic.bm_LeaderState == 0)
		HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
	if (Mystic.bm_LeaderState == 1)
		HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
	int jjj = 0;
	while (bInsideKn && (Mystic.m_bConnexionState == 1))
	{
		Sleep(100);
		++jjj;
		if (jjj > 500)
		{
			cout << "stuck at this iteration n°1" << endl;
			if (Mystic.bm_LeaderState == 0)
				HandleUndecipheredPacket(size58x3a, C_CHAT, { 0x0A, 0x00, 0x01, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x2E, 0x00, 0x72, 0x00, 0x65, 0x00, 0x73, 0x00, 0x65, 0x00, 0x74, 0x00, 0x31, 0x00, 0x34, 0x00, 0x32, 0x00, 0x35, 0x00, 0x3C, 0x00, 0x2F, 0x00, 0x46, 0x00, 0x4F, 0x00, 0x4E, 0x00, 0x54, 0x00, 0x3E, 0x00, 0x00, 0x00 }, socket);
			else if (Mystic.bm_LeaderState == 1)
				HandlePacket(size04x04, C_RESET_ALL_DUNGEON, *socket);
		}
		if (jjj == 500)
			Beep(5000, 300);
	}
	fileout3 << "got ouside Kelsaik, the new loop is about to start" << endl;
}