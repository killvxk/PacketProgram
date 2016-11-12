#ifndef PATTERN_H
#include <boost/asio.hpp>
#define PATTERN_H
void PowerLevel(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void PowerLevelNeedle(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
void DealWithEnnemiesDuringPlvl(boost::shared_ptr<boost::asio::ip::tcp::socket> socket, int nWantedZHide);
void DealWithEnnemiesDuringPlvl(boost::asio::ip::tcp::socket &socket, int nWantedZHide);
void PowerLeveled(ofstream& fileout, boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
#endif