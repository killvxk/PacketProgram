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
#include <thread>
#include <ctime>
#include "PacketData.h"
#include "PacketReception.h"
#include "ConfigFile.h"
using namespace std;
string packetContentOutIn = "Complete logs.txt";
ofstream CompleteLogFile(packetContentOutIn.c_str());
boost::mutex mtx_;
boost::mutex mtx_lockHandlePackets;
void WriteToFile(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	mtx_.lock();
	std::map <int, std::string> ::iterator it;
	if (bEU)
		it = PacketHandlers.find(title);
	if (bNA)
		it = PacketHandlers_NA.find(title);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	CompleteLogFile << "[" << dec << (now->tm_year + 1900) << '-'
		<< dec << (now->tm_mon + 1) << '-'
		<< dec << now->tm_mday << " "
		<< dec << now->tm_hour << ":"
		<< dec << now->tm_min << ":"
		<< dec << now->tm_sec << "]"
		<< "title : " << hex << it->second << " # read size is : " << dec << size << std::endl;
	for (int uuu = 0; uuu < size; ++uuu)
	{
		CompleteLogFile << hex << setw(2) << setfill('0') << int(vectArgument[nAnalyzedSize + uuu]) << " ";
	}
	if (generalFlag)
		CompleteLogFile << "THIS PACKET ## MARKED" << endl;
	generalFlag = 0;
	CompleteLogFile << endl;
	mtx_.unlock();
}

void WriteToFile_C(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	mtx_.lock();
	std::map <int, std::string> ::iterator it;
	if (bEU)
		it = PacketHandlers.find(title);
	if (bNA)
		it = PacketHandlers_NA.find(title);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	CompleteLogFile << "[" << dec << (now->tm_year + 1900) << '-'
		<< dec << (now->tm_mon + 1) << '-'
		<< dec << now->tm_mday << " "
		<< dec << now->tm_hour << ":"
		<< dec << now->tm_min << ":"
		<< dec << now->tm_sec << "]"
		<< "title : " << hex << it->second << " # read size is : " << dec << size << std::endl;
	for (int uuu = 0; uuu < size; ++uuu)
	{
		CompleteLogFile << hex << setw(2) << setfill('0') << int(vectArgument[uuu]) << " ";
	}
	CompleteLogFile << endl;
	mtx_.unlock();
}
void WriteToFile_C(uint16_t& size, const uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	mtx_.lock();
	std::map <int, std::string> ::iterator it;
	if (bEU)
	it = PacketHandlers.find(title);
	if (bNA)
	it = PacketHandlers_NA.find(title);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	CompleteLogFile << "[" << dec << (now->tm_year + 1900) << '-'
		<< dec << (now->tm_mon + 1) << '-'
		<< dec << now->tm_mday << " "
		<< dec << now->tm_hour << ":"
		<< dec << now->tm_min << ":"
		<< dec << now->tm_sec << "]"
		<< "title : " << hex << it->second << " # read size is : " << dec << size << std::endl;
	for (int uuu = 0; uuu < size; ++uuu)
	{
		CompleteLogFile << hex << setw(2) << setfill('0') << int(vectArgument[uuu]) << " ";
	}
	CompleteLogFile << endl;
	mtx_.unlock();
}
void WriteToFile(uint16_t& size, const uint16_t& title, std::vector <unsigned char> &vectArgument)
{
	mtx_.lock();
	std::map <int, std::string> ::iterator it;
	if (bEU)
		it = PacketHandlers.find(title);
	if (bNA)
		it = PacketHandlers_NA.find(title);
	time_t t = time(0);
	struct tm * now = localtime(&t);
	CompleteLogFile << "[" << dec << (now->tm_year + 1900) << '-'
		<< dec << (now->tm_mon + 1) << '-'
		<< dec << now->tm_mday << " "
		<< dec << now->tm_hour << ":"
		<< dec << now->tm_min << ":"
		<< dec << now->tm_sec << "]"
		<< "title : " << hex << it->second << " # read size is : " << dec << size << std::endl;
	for (int uuu = 0; uuu < size; ++uuu)
	{
		CompleteLogFile << hex << setw(2) << setfill('0') << int(vectArgument[nAnalyzedSize + uuu]) << " ";
	}
	CompleteLogFile << endl;
	mtx_.unlock();
}
void WriteToFile(std::string & stringArg)
{
	mtx_.lock();
	time_t t = time(0);
	struct tm * now = localtime(&t);
	CompleteLogFile << "[" << dec << (now->tm_year + 1900) << '-'
		<< dec << (now->tm_mon + 1) << '-'
		<< dec << now->tm_mday << " "
		<< dec << now->tm_hour << ":"
		<< dec << now->tm_min << ":"
		<< dec << now->tm_sec << "]"
		<< "Bot State : " << std::endl;
	CompleteLogFile << stringArg << endl;
	mtx_.unlock();
}