#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#ifndef Packet_Program_Boost
#define Packet_Program_Boost
//extern boost::asio::ip::tcp::socket socket();
extern char szFirstGeneratedKey_UnSent[128];
extern char szSecondGeneratedKey_Sent[128];
extern char szReceivedFirstKey[128];
extern char szSentSecondKey[128];
extern int bufferHolder;
extern bool EncryptionOrDecryptionBusy;
extern void*ptrReceivedFirstKey;
extern void*ptrRandomedFirstKey;
extern void*ptrRandomedSecondKey;
extern void*ptrReceivedSecondKey;
extern void*ptrSentSecondKey;
extern char chArchitectureKey[128000];
extern void*ptrArchitectureKey;
extern char keyEncryption_1;
extern char keyDecryption_1;
extern char keyEncryption_2;
extern char keyDecryption_2;
extern char keyEncryption_3;
extern char keyDecryption_3;
extern void* ptrKeyEncryption_1;
extern void* ptrKeyEncryption_2;
extern void* ptrKeyEncryption_3;
extern void* ptrKeyDecryption_1;
extern void* ptrKeyDecryption_2;
extern void* ptrKeyDecryption_3;
extern char bufferReceivedPacket;
extern void* ptrBufferReceivedPacket;
extern void* ptrPacketToSend;
extern int nBotNumber;
extern HWND consoleWindow;
#endif

