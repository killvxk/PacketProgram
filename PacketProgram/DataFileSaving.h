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
#ifndef DATAFILESAVING_H
#define DATAFILESAVING_H
// ========================================= Functions prototypes
void WriteToFile(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument);
void WriteToFile(uint16_t& size, const uint16_t& title, std::vector <unsigned char> &vectArgument);
void WriteToFile_C(uint16_t& size, const uint16_t& title, std::vector <unsigned char> &vectArgument);
void WriteToFile_C(uint16_t& size, uint16_t& title, std::vector <unsigned char> &vectArgument);
void WriteToFile(std::string & stringArg);
extern boost::mutex mtx_lockHandlePackets;
#endif