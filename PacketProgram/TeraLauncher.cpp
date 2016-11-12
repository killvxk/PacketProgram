// TeraLauncher.cpp : Defines the entry point for the console application.
//
/*
#include <openssl/bio.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/lhash.h>
#include <openssl/conf.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
*/


//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <vector>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/interprocess/streams/vectorstream.hpp>
//
#include <fstream>
#include <string>
#include <sstream>
#include "ConfigFile.h"
void decompress(unsigned char * arr, int nCopySize);
void decompress(unsigned char * arr, int nCopySize, std::vector <unsigned char>& vecArg);
bool bDebug(0);
int differenceSize = 0;
enum { max_length = 1024 };
void test0()
{
	unsigned char arrOutput[] = { 0x1F, 0x8B, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1D, 0xCD, 0xC1, 0x0D, 0xC3, 0x30, 0x08, 0x00, 0xC0, 0x55, 0xAC, 0x0C, 0x60, 0xD4, 0x6F, 0x45, 0xBC, 0x47, 0x9F, 0x04, 0x13, 0xDB, 0x52, 0x0C, 0x15, 0xC1, 0x8F, 0x6E, 0x5F, 0x29, 0xB7, 0xC0, 0x61, 0x8F, 0x79, 0x15, 0x3C, 0xAC, 0xFE, 0xCA, 0xC7, 0x56, 0x22, 0x97, 0x74, 0xC8, 0xD0, 0x96, 0x90, 0x52, 0x77, 0x39, 0xF7, 0xAD, 0x47, 0x7C, 0xEF, 0x37, 0x00, 0x31, 0xDB, 0xD2, 0xC8, 0x21, 0x4E, 0xB9, 0xD1, 0x94, 0xD3, 0xBC, 0x49, 0x66, 0x9B, 0x70, 0xD1, 0x52, 0xEE, 0xE2, 0xF0, 0x82, 0x7B, 0x34, 0x1D, 0xBA, 0x15, 0x97, 0x3A, 0x5C, 0x38, 0xA4, 0x22, 0x50, 0xC9, 0x08, 0x4F, 0x81, 0xF0, 0x7C, 0x7F, 0x19, 0xD4, 0x47, 0x16, 0x76, 0x00, 0x00, 0x00 };
	using namespace std;

}
using namespace std;
namespace io = boost::iostreams; //<-- good practice
typedef std::vector<char> buffer_t;

void testft(const buffer_t &compressed,
	buffer_t &decompressed)
{
	io::filtering_ostream os;

	os.push(io::gzip_decompressor());
	os.push(io::back_inserter(decompressed));
	//boost::iostreams::copy(os, cout);
	//io::write(os, &compressed[0], compressed.size());
}
int maooin()
{
	using namespace std;
	using namespace boost::iostreams;

	ifstream file("2.txt.html", ios_base::in | ios_base::binary);
	filtering_streambuf<input> in;
	in.push(gzip_decompressor());
	in.push(file);
	boost::iostreams::copy(in, cout);
	int x;
	cin >> x;
	unsigned char buf2[] = { 0x1F, 0x8B, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1D, 0xCD, 0xC1, 0x0D, 0xC3, 0x20, 0x0C, 0x05, 0xD0, 0x55, 0x50, 0x06, 0xC0, 0xEA, 0xB5, 0x72, 0xD9, 0xA3, 0x47, 0xC7, 0xFC, 0x40, 0xA4, 0x80, 0x2B, 0xD7, 0x1C, 0xBA, 0x7D, 0xA5, 0x2C, 0xF0, 0x1E, 0xF7, 0x18, 0x57, 0xE1, 0xDD, 0xEA, 0xAF, 0xBC, 0x6D, 0x25, 0x71, 0xA4, 0x1D, 0xE7, 0x6C, 0x89, 0x25, 0x75, 0xC7, 0xF1, 0xDA, 0x7A, 0xC4, 0xE7, 0xFB, 0x24, 0x12, 0x55, 0x5B, 0x33, 0x72, 0xC0, 0x25, 0x37, 0x19, 0x38, 0xCC, 0x1B, 0xB2, 0xDA, 0xA0, 0x4B, 0xD6, 0xD4, 0x0E, 0xA7, 0xC7, 0x56, 0x1C, 0xF5, 0x74, 0x68, 0xA0, 0x32, 0x49, 0xC9, 0x4C, 0xB7, 0xCD, 0x74, 0x47, 0x7F, 0x82, 0xCE, 0xDA, 0x8D, 0x6F, 0x00, 0x00, 0x00 };
	std::string str1(reinterpret_cast<const char *>(buf2), sizeof(buf2));
	for (auto uuu = str1.begin(); uuu != str1.end(); ++uuu)
		printf(" %02x", *uuu);
	auto sizeT = str1.size();
	cout << "\nSize : " << sizeT << endl;
	istringstream file2(str1, ios_base::in | ios_base::binary);
	filtering_streambuf<input> iin;
	iin.push(gzip_decompressor());
	iin.push(file2);
	boost::iostreams::copy(iin, cout);
	cin >> x;
	return 0;
}
class client
{
public:
	client(boost::asio::io_service& io_service,
		boost::asio::ssl::context& context,
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
		: socket_(io_service, context)
	{
		socket_.set_verify_mode(boost::asio::ssl::verify_peer);
		socket_.set_verify_callback(
			boost::bind(&client::verify_certificate, this, _1, _2));

		boost::asio::async_connect(socket_.lowest_layer(), endpoint_iterator,
			boost::bind(&client::handle_connect, this,
			boost::asio::placeholders::error));
	}

	bool verify_certificate(bool preverified,
		boost::asio::ssl::verify_context& ctx)
	{
		// The verify callback can be used to check whether the certificate that is
		// being presented is valid for the peer. For example, RFC 2818 describes
		// the steps involved in doing this for HTTPS. Consult the OpenSSL
		// documentation for more details. Note that the callback is called once
		// for each certificate in the certificate chain, starting from the root
		// certificate authority.

		// In this example we will simply print the certificate's subject name.
		char subject_name[256];
		X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
		X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
		std::cout << "Verifying " << subject_name << "\n";

		return preverified;
	}

	void handle_connect(const boost::system::error_code& error)
	{
		if (!error)
		{
			socket_.async_handshake(boost::asio::ssl::stream_base::client,
				boost::bind(&client::handle_handshake, this,
				boost::asio::placeholders::error));
		}
		else
		{
			std::cout << "Connect failed: " << error.message() << "\n";
		}
	}

	void handle_handshake(const boost::system::error_code& error)
	{
		if (!error)
		{
			std::cout << "Enter message: ";
			std::cin.getline(request_, max_length);
			size_t request_length = strlen(request_);

			boost::asio::async_write(socket_,
				boost::asio::buffer(request_, request_length),
				boost::bind(&client::handle_write, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}
		else
		{
			std::cout << "Handshake failed: " << error.message() << "\n";
		}
	}

	void handle_write(const boost::system::error_code& error,
		size_t bytes_transferred)
	{
		if (!error)
		{
			boost::asio::async_read(socket_,
				boost::asio::buffer(reply_, bytes_transferred),
				boost::bind(&client::handle_read, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
		}
		else
		{
			std::cout << "Write failed: " << error.message() << "\n";
		}
	}

	void handle_read(const boost::system::error_code& error,
		size_t bytes_transferred)
	{
		if (!error)
		{
			std::cout << "Reply: ";
			std::cout.write(reply_, bytes_transferred);
			std::cout << "\n";
		}
		else
		{
			std::cout << "Read failed: " << error.message() << "\n";
		}
	}

private:
	boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
	char request_[max_length];
	char reply_[max_length];
};

int maion(int argc, char* argv[])
{
	try
	{
		if (argc != 1)
		{
			std::cerr << "Usage: client <host> <port>\n";
			int u;
			std::cin >> u;
			return 1;
		}

		boost::asio::io_service io_service;

		boost::asio::ip::tcp::resolver resolver(io_service);
		boost::asio::ip::tcp::resolver::query query("79.110.94.195", "https");
		boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

		boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
		ctx.load_verify_file("ca.pem");

		client c(io_service, ctx, iterator);

		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	int u;
	std::cin >> u;
	return 0;
}
using namespace std;

std::string out = "Received Messages.txt";
std::ofstream fout1(out.c_str());
void test3(std::ofstream& fout, char * arr, std::string& strArg)
{
	bDebug = 0;
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;
	// Create a context that uses the default paths for
	// finding CA certificates.
	ssl::context ctx(ssl::context::tlsv1);
	ctx.set_default_verify_paths();

	// Open a socket and connect it to the remote host.
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("account.tera.gameforge.com", "https");
	//tcp::resolver::query query("facebook.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));

	// Perform SSL handshake and verify the remote host's
	// certificate.
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("account.tera.gameforge.com"));
	sock.handshake(ssl_socket::client);
	string toc;
	std::string fourth = "FourthSentMessage.txt";
	std::ifstream fin4(fourth.c_str());
	while (getline(fin4, fourth))
	{
		//cout << s << endl;
		toc += fourth;
		toc.push_back(0x0d);
		toc.push_back(0x0a);
	}
	toc.append(strArg);
	cout << toc << endl;
	sock.write_some(boost::asio::buffer(toc));
	char data[4000];
	int size = 900;
	int nSizeRead = 0;
	unsigned char tempArray[4000];
	int tempRead = 0;
	do
	{
		try
		{
			tempRead = sock.read_some(boost::asio::buffer(data, size));
		}
		catch (std::exception& c)
		{
			//std::cerr << c.what();
			cout << "\nNo new data was received." << endl;
			tempRead = 0;
			continue;
		}
		int iii = 0;
		for (int uuu = nSizeRead; uuu != (tempRead + nSizeRead); ++uuu, ++iii)
		{
			tempArray[uuu] = data[iii];
		}
		nSizeRead += tempRead;
		if (bDebug)
			cout << "We ve read : " << dec << nSizeRead << " bytes." << endl;
		if (bDebug)
			for (int uuu = 0; uuu != nSizeRead; ++uuu)
			{
			printf(" %02X", data[uuu]);
			}
	} while (tempRead != 0);
	//analyze data
	int trol;
	std::vector <unsigned char> vec;
	for (int uuu = 1; uuu != nSizeRead; ++uuu)
		vec.push_back(data[uuu - 1]);
	std::vector<unsigned char> vContentLength = { 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x4C, 0x65, 0x6E, 0x67, 0x74, 0x68, 0x3A, 0x20 };
	auto it = std::search(vec.begin(), vec.end(), vContentLength.begin(), vContentLength.end());
	if (it != vec.end())
	{
		if (bDebug)
			cout << "Content-Length found." << endl;
		it += vContentLength.size();
		string str1;
		for (int uuu = 0; uuu != 3; ++uuu)
		{
			str1.push_back(*it);
			++it;
		}
		if (bDebug)
			cout << str1 << endl;
		trol = (str1[0] - 0x30) * 100 + (str1[1] - 0x30) * 10 + (str1[2] - 0x30);
		cout << "Number of compressed bytes : " << trol << endl;
	}
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", tempArray[uuu]);
		}
	if (bDebug)
		cout << "\nData\n" << endl;
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", data[uuu]);
		}
	//decompress
	std::vector <unsigned char> vTicket;
	std::vector<unsigned char> vReceivedPacket;
	decompress(&tempArray[nSizeRead - trol], trol, vReceivedPacket);
	std::vector <unsigned char> vTicketSignature = { 0x74, 0x69, 0x63, 0x6B, 0x65, 0x74 };
	auto ot = std::search(vReceivedPacket.begin(), vReceivedPacket.end(), vTicketSignature.begin(), vTicketSignature.end());
	if (ot != vReceivedPacket.end())
	{
		cout << "Ticket found :" << endl;
		while (*(ot + 9) != '"')
		{
			cout << *(ot + 9);
			vTicket.push_back(*(ot + 9));
			++ot;
		}
	}
	else
		cout << "Error, ticket not found." << endl;
	cout << endl; // flushes out buffer
	std::vector <unsigned char> vMasterAccountName;
	std::vector <unsigned char> vMasterAccountNameSignature = { 0x22, 0x6D, 0x61, 0x73, 0x74, 0x65, 0x72, 0x5F, 0x61, 0x63, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x5F, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22 };
	ot = std::search(vReceivedPacket.begin(), vReceivedPacket.end(), vMasterAccountNameSignature.begin(), vMasterAccountNameSignature.end());
	if (ot != vReceivedPacket.end())
	{
		cout << "Account master name found :" << endl;
		while (*(ot + 23) != '"')
		{
			cout << *(ot + 23);
			vMasterAccountName.push_back(*(ot + 23));
			vMasterAccountName.push_back(0x00);
			++ot;
		}
		vMasterAccountName.push_back(0x00);
		vMasterAccountName.push_back(0x00);
		cout << endl; // flushes out buffer
	}
	//eu vector
	//123
	std::vector<unsigned char> vVersionPacket1 = { 0x20, 0x00, 0xBC, 0x4D, 0x02, 0x00, 0x08, 0x00, 0x08, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x9e, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x52, 0xa0, 0x04, 0x00, 0x5B, 0x00, 0xbf, 0xb5, 0x17, 0x00, 0x29, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0xfd, 0x11, 0x00, 0x00 };
	//127
	std::vector<unsigned char> vVersionPacket = { 0x20, 0x00, 0xBC, 0x4D, 0x02, 0x00, 0x08, 0x00, 0x08, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0xAE, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xaf, 0xad, 0x04, 0x00, 0x5F, 0x00, 0xe4, 0x9d, 0x17, 0x00, 0x2D, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0xad, 0x26, 0x00, 0x00 };
	vVersionPacket.insert(vVersionPacket.end(), vMasterAccountName.begin(), vMasterAccountName.end());
	vVersionPacket.insert(vVersionPacket.end(), vTicket.begin(), vTicket.end());
	for (int uuu = 0; uuu != vVersionPacket.size(); ++uuu)
	{
		printf(" %02X", vVersionPacket[uuu]);
		arr[uuu] = vVersionPacket[uuu];
	}
	cout << "\n\t the size of the vector is : " << vVersionPacket.size() << endl;
	size123 = vVersionPacket.size();
	fout << tempArray << endl;
	sock.shutdown();
}
void test3NA(std::ofstream& fout, char * arr)
{
	bDebug = 0;
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;

	// Create a context that uses the default paths for
	// finding CA certificates.
	ssl::context ctx(ssl::context::tlsv11);
	ctx.set_default_verify_paths();

	// Open a socket and connect it to the remote host.
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	//NA login ip : 208.67.49.148
	tcp::resolver::query query("account.enmasse.com", "https");
	//tcp::resolver::query query("facebook.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));

	// Perform SSL handshake and verify the remote host's
	// certificate.
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("account.enmasse.com.com"));
	sock.handshake(ssl_socket::client);
	string toc;
	std::string fourth = "FourthSentMessage.txt";
	std::ifstream fin4(fourth.c_str());
	while (getline(fin4, fourth))
	{
		//cout << s << endl;
		toc += fourth;
		toc.push_back(0x0d);
		toc.push_back(0x0a);
	}
	toc.push_back(0x0a);
	cout << toc << endl;
	sock.write_some(boost::asio::buffer(toc));
	char data[4000];
	int size = 900;
	int nSizeRead = 0;
	unsigned char tempArray[4000];
	int tempRead = 0;
	do
	{
		try
		{
			tempRead = sock.read_some(boost::asio::buffer(data, size));
		}
		catch (std::exception& c)
		{
			//std::cerr << c.what();
			cout << "\nNo new data was received." << endl;
			tempRead = 0;
			continue;
		}
		int iii = 0;
		for (int uuu = nSizeRead; uuu != (tempRead + nSizeRead); ++uuu, ++iii)
		{
			tempArray[uuu] = data[iii];
		}
		nSizeRead += tempRead;
		if (bDebug)
			cout << "We ve read : " << dec << nSizeRead << " bytes." << endl;
		if (bDebug)
			for (int uuu = 0; uuu != nSizeRead; ++uuu)
			{
			printf(" %02X", data[uuu]);
			}
	} while (tempRead != 0);
	//analyze data
	int trol;
	std::vector <unsigned char> vec;
	for (int uuu = 1; uuu != nSizeRead; ++uuu)
		vec.push_back(data[uuu - 1]);
	std::vector<unsigned char> vContentLength = { 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x4C, 0x65, 0x6E, 0x67, 0x74, 0x68, 0x3A, 0x20 };
	auto it = std::search(vec.begin(), vec.end(), vContentLength.begin(), vContentLength.end());
	if (it != vec.end())
	{
		if (bDebug)
			cout << "Content-Length found." << endl;
		it += vContentLength.size();
		string str1;
		for (int uuu = 0; uuu != 3; ++uuu)
		{
			str1.push_back(*it);
			++it;
		}
		if (bDebug)
			cout << str1 << endl;
		trol = (str1[0] - 0x30) * 100 + (str1[1] - 0x30) * 10 + (str1[2] - 0x30);
		cout << "Number of compressed bytes : " << trol << endl;
	}
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", tempArray[uuu]);
		}
	if (bDebug)
		cout << "\nData\n" << endl;
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", data[uuu]);
		}
	//decompress
	std::vector <unsigned char> vTicket;
	std::vector<unsigned char> vReceivedPacket;
	decompress(&tempArray[nSizeRead - trol], trol, vReceivedPacket);
	std::vector <unsigned char> vTicketSignature = { 0x74, 0x69, 0x63, 0x6B, 0x65, 0x74 };
	auto ot = std::search(vReceivedPacket.begin(), vReceivedPacket.end(), vTicketSignature.begin(), vTicketSignature.end());
	if (ot != vReceivedPacket.end())
	{
		cout << "Ticket found :" << endl;
		while (*(ot + 9) != '"')
		{
			cout << *(ot + 9);
			vTicket.push_back(*(ot + 9));
			++ot;
		}
	}
	else
		cout << "Error, ticket not found." << endl;
	cout << endl; // flushes out buffer
	std::vector <unsigned char> vMasterAccountName;
	std::vector <unsigned char> vMasterAccountNameSignature = { 0x22, 0x6D, 0x61, 0x73, 0x74, 0x65, 0x72, 0x5F, 0x61, 0x63, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x5F, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22 };
	ot = std::search(vReceivedPacket.begin(), vReceivedPacket.end(), vMasterAccountNameSignature.begin(), vMasterAccountNameSignature.end());
	if (ot != vReceivedPacket.end())
	{
		cout << "Account master name found :" << endl;
		while (*(ot + 23) != '"')
		{
			cout << *(ot + 23);
			vMasterAccountName.push_back(*(ot + 23));
			vMasterAccountName.push_back(0x00);
			++ot;
		}
		vMasterAccountName.push_back(0x00);
		vMasterAccountName.push_back(0x00);
		cout << endl; // flushes out buffer
	}
	std::vector<unsigned char> vVersionPacket = { 0x20, 0x00, 0xBC, 0x4D, 0x02, 0x00, 0x08, 0x00, 0x08, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x9d, 0x04, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0a, 0x99, 0x04, 0x00, 0x5F, 0x00, 0xf0, 0xb8, 0x17, 0x00, 0x2D, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x6e, 0x10, 0x00, 0x00 };
	vVersionPacket.insert(vVersionPacket.end(), vMasterAccountName.begin(), vMasterAccountName.end());
	vVersionPacket.insert(vVersionPacket.end(), vTicket.begin(), vTicket.end());
	for (int uuu = 0; uuu != vVersionPacket.size(); ++uuu)
	{
		printf(" %02X", vVersionPacket[uuu]);
		arr[uuu] = vVersionPacket[uuu];
	}
	cout << "\n\t the size of the vector is : " << vVersionPacket.size() << endl;
	fout << tempArray << endl;
	sock.shutdown();
}
void test2(ofstream& fout, std::string& strArg)
{
	bDebug = 0;
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;
	ssl::context ctx(ssl::context::tlsv1);
	ctx.set_default_verify_paths();
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("account.tera.gameforge.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("account.tera.gameforge.com"));
	sock.handshake(ssl_socket::client);
	std::string third = "ThirdSentMessage.txt";
	std::ifstream fin3(third.c_str());
	string toc;
	while (getline(fin3, third))
	{
		//cout << s << endl;
		toc += third;
		toc.push_back(0x0d);
		toc.push_back(0x0a);
	}
	//toc.push_back(0x0a);
	toc.append(strArg);
	cout << toc << endl;
	sock.write_some(boost::asio::buffer(toc));
	char data[4000];
	int size = 900;
	int nSizeRead = 0;
	unsigned char tempArray[4000];
	int tempRead = 0;
	int x;
	do
	{
		try
		{
			tempRead = sock.read_some(boost::asio::buffer(data, size));
		}
		catch (std::exception& c)
		{
			//std::cerr << c.what();
			cout << "\nNo new data was received." << endl;
			tempRead = 0;
			continue;
		}
		int iii = 0;
		for (int uuu = nSizeRead; uuu != (tempRead + nSizeRead); ++uuu, ++iii)
		{
			tempArray[uuu] = data[iii];
		}
		nSizeRead += tempRead;
		if (bDebug)
			cout << "We ve read : " << dec << nSizeRead << " bytes." << endl;
		if (bDebug)
			for (int uuu = 0; uuu != nSizeRead; ++uuu)
			{
			printf(" %02X", data[uuu]);
			}
	} while (tempRead != 0);
	fout << tempArray << endl;
	sock.shutdown();
}
void LoginUE(char * arr, string& strArg) {
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;

	// Create a context that uses the default paths for
	// finding CA certificates.
	ssl::context ctx(ssl::context::tlsv1);
	ctx.set_default_verify_paths();

	// Open a socket and connect it to the remote host.
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	tcp::resolver::query query("account.tera.gameforge.com", "https");
	//tcp::resolver::query query("facebook.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));

	// Perform SSL handshake and verify the remote host's
	// certificate.
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("account.tera.gameforge.com"));
	sock.handshake(ssl_socket::client);

	// ... read and write as normal ...
	int x;
	//second send 
	string toc;
	std::string s = "token.txt";
	std::ifstream fin(s);
	while (getline(fin, s))
	{
		//cout << s << endl;
		toc += s;
	}
	toc += strArg;
	//Changes the token to get uniq and different identifier every time
	auto nSize1 = toc.rfind("box%5D=0200");
	toc[nSize1 + 16] = rand() % 0x1a + 0x41;
	toc[nSize1 + 17] = rand() % 0x1a + 0x61;
	toc[nSize1 + 18] = rand() % 0x1a + 0x41;
	toc[nSize1 + 19] = rand() % 0x1a + 0x61;
	toc[nSize1 + 25] = rand() % 0x1a + 0x41;
	toc[nSize1 + 26] = rand() % 0x1a + 0x61;
	toc[nSize1 + 27] = rand() % 0x1a + 0x41;
	toc[nSize1 + 28] = rand() % 0x1a + 0x61;
	//
	cout << "THIS ## " << toc.size() << "\n" << endl;
	//we get the size as a string format
	string strSize;
	int Local1 = (toc.size() / 1000);
	strSize.push_back(Local1 + 0x30);
	Local1 = (toc.size() / 100) - ((toc.size() / 1000) * 10);
	strSize.push_back(Local1 + 0x30);
	Local1 = (toc.size() / 10) - ((toc.size() / 100) * 10);
	strSize.push_back(Local1 + 0x30);
	Local1 = (toc.size()) - ((toc.size() / 10) * 10);
	strSize.push_back(Local1 + 0x30);
	cout << strSize << endl;
	//first message sent :
	std::string first = "FirstSentMessage.txt";
	std::ifstream firstSentMessage(first.c_str());
	string toc1;
	while (getline(firstSentMessage, first))
	{
		//cout << s << endl;
		toc1 += first;
		toc1.push_back(0x0d);
		toc1.push_back(0x0a);
	}
	toc1.push_back(0x0a);
	//Now we insert the length at the right place
	auto nPlace = toc1.rfind("Content-Length: ");
	toc1.insert(nPlace + 16, strSize);
	cout << toc1 << endl;
	if (bDebug)
		for (auto uuu = toc1.begin(); uuu != toc1.end(); ++uuu)
			printf(" %02x", *uuu);
	sock.write_some(boost::asio::buffer(toc1));
	if (bDebug)
		cout << toc << endl;
	sock.write_some(boost::asio::buffer(toc));
	string tic;
	unsigned char data[1000];
	memset(data, 0, 1000);
	int size = 900;
	int trol;
	string buffer1;
	int nSizeRead = 0;
	trol = 500;
	unsigned char tempArray[2000];
	int tempRead = 0;
	do
	{
		try
		{
			tempRead = sock.read_some(boost::asio::buffer(data, size));
		}
		catch (std::exception& c)
		{
			//std::cerr << c.what();
			cout << "\nNo new data was received." << endl;
			tempRead = 0;
			continue;
		}
		int iii = 0;
		for (int uuu = nSizeRead; uuu != (tempRead + nSizeRead); ++uuu, ++iii)
		{
			tempArray[uuu] = data[iii];
		}
		nSizeRead += tempRead;
		if (bDebug)
			cout << "We ve read : " << dec << nSizeRead << " bytes." << endl;
		if (bDebug)
			for (int uuu = 0; uuu != nSizeRead; ++uuu)
			{
			printf(" %02X", data[uuu]);
			}
	} while (tempRead != 0);
	//analyze data
	std::vector <unsigned char> vec;
	for (int uuu = 1; uuu != nSizeRead; ++uuu)
		vec.push_back(data[uuu - 1]);
	std::vector<unsigned char> vContentLength = { 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x4C, 0x65, 0x6E, 0x67, 0x74, 0x68, 0x3A, 0x20 };
	auto it = std::search(vec.begin(), vec.end(), vContentLength.begin(), vContentLength.end());
	if (it != vec.end())
	{
		if (bDebug)
			cout << "Content-Length found." << endl;
		it += vContentLength.size();
		string str1;
		for (int uuu = 0; uuu != 3; ++uuu)
		{
			str1.push_back(*it);
			++it;
		}
		if (bDebug)
			cout << str1 << endl;
		trol = (str1[0] - 0x30) * 100 + (str1[1] - 0x30) * 10 + (str1[2] - 0x30);
		cout << "Number of compressed bytes : " << trol << endl;
	}
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", tempArray[uuu]);
		}
	if (bDebug)
		cout << "\nData\n" << endl;
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", data[uuu]);
		}
	//decompress
	if (trol == 113)
		cout << "\n\t\t\t**Login Successful !**\n\n" << endl;
	else
	{
		cout << "Login failed." << endl;
		int x;
		cin >> x;
	}
	decompress(&tempArray[nSizeRead - trol], trol);
	//store answer to file
	fout1 << tempArray << endl;
	sock.shutdown();
	return;
}
void LoginNA(char * arr, string& strArg) {
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;

	// Create a context that uses the default paths for
	// finding CA certificates.
	ssl::context ctx(ssl::context::tlsv11);
	ctx.set_default_verify_paths();

	// Open a socket and connect it to the remote host.
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	//NA login ip : 208.67.49.148
	tcp::resolver::query query("account.enmasse.com", "https");
	//tcp::resolver::query query("facebook.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));

	// Perform SSL handshake and verify the remote host's
	// certificate.
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("account.enmasse.com.com"));
	sock.handshake(ssl_socket::client);

	// ... read and write as normal ...
	int x;
	std::string first = "FirstSentMessage.txt";
	std::ifstream firstSentMessage(first.c_str());
	string toc;
	while (getline(firstSentMessage, first))
	{
		//cout << s << endl;
		toc += first;
		toc.push_back(0x0d);
		toc.push_back(0x0a);
	}
	toc.push_back(0x0a);
	//cout << toc << endl;
	if (bDebug)
		for (auto uuu = toc.begin(); uuu != toc.end(); ++uuu)
			printf(" %02x", *uuu);
	sock.write_some(boost::asio::buffer(toc));
	toc.clear();
	//second send 
	std::string s = "token.txt";
	std::ifstream fin(s);
	while (getline(fin, s))
	{
		//cout << s << endl;
		toc += s;
	}
	toc += strArg;
	cout << "THIS ## " << toc << endl;
	if (bDebug)
		cout << toc << endl;
	sock.write_some(boost::asio::buffer(toc));
	string tic;
	unsigned char data[1000];
	memset(data, 0, 1000);
	int size = 900;
	int trol;
	string buffer1;
	int nSizeRead = 0;
	trol = 500;
	unsigned char tempArray[2000];
	int tempRead = 0;
	do
	{
		try
		{
			tempRead = sock.read_some(boost::asio::buffer(data, size));
		}
		catch (std::exception& c)
		{
			//std::cerr << c.what();
			cout << "\nNo new data was received." << endl;
			tempRead = 0;
			continue;
		}
		int iii = 0;
		for (int uuu = nSizeRead; uuu != (tempRead + nSizeRead); ++uuu, ++iii)
		{
			tempArray[uuu] = data[iii];
		}
		nSizeRead += tempRead;
		if (bDebug)
			cout << "We ve read : " << dec << nSizeRead << " bytes." << endl;
		if (bDebug)
			for (int uuu = 0; uuu != nSizeRead; ++uuu)
			{
			printf(" %02X", data[uuu]);
			}
	} while (tempRead != 0);
	//analyze data
	std::vector <unsigned char> vec;
	for (int uuu = 1; uuu != nSizeRead; ++uuu)
		vec.push_back(data[uuu - 1]);
	std::vector<unsigned char> vContentLength = { 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x4C, 0x65, 0x6E, 0x67, 0x74, 0x68, 0x3A, 0x20 };
	auto it = std::search(vec.begin(), vec.end(), vContentLength.begin(), vContentLength.end());
	if (it != vec.end())
	{
		if (bDebug)
			cout << "Content-Length found." << endl;
		it += vContentLength.size();
		string str1;
		for (int uuu = 0; uuu != 3; ++uuu)
		{
			str1.push_back(*it);
			++it;
		}
		if (bDebug)
			cout << str1 << endl;
		trol = (str1[0] - 0x30) * 100 + (str1[1] - 0x30) * 10 + (str1[2] - 0x30);
		cout << "Number of compressed bytes : " << trol << endl;
	}
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", tempArray[uuu]);
		}
	if (bDebug)
		cout << "\nData\n" << endl;
	if (bDebug)
		for (int uuu = 0; uuu != nSizeRead; ++uuu)
		{
		printf(" %02X", data[uuu]);
		}
	//decompress
	if (trol == 113)
		cout << "\n\t\t\t**Login Successful !**\n\n" << endl;
	else
	{
		cout << "Login failed." << endl;
		int x;
		cin >> x;
	}
	decompress(&tempArray[nSizeRead - trol], trol);
	//store answer to file
	fout1 << tempArray << endl;
	sock.shutdown();
	return;
}

void decompress(unsigned char * arr, int nCopySize, std::vector <unsigned char>& vecArg)
{
	using namespace boost::iostreams;
	using namespace boost::interprocess;
	std::string str1(reinterpret_cast<const char *>(arr), nCopySize);
	if (bDebug)
		for (auto uuu = str1.begin(); uuu != str1.end(); ++uuu)
			printf(" %02x", *uuu);
	auto sizeT = str1.size();
	if (bDebug)
		cout << "\nSize : " << sizeT << endl;
	stringstream file2(str1, ios_base::in | ios_base::binary);
	filtering_streambuf<input> iin;
	iin.push(gzip_decompressor());
	iin.push(file2);
	std::string str2;
	stringstream file3;
	boost::iostreams::copy(iin, file3);
	file3 >> str2;
	cout << str2 << endl;
	for (int uuu = 1; uuu != str2.size(); ++uuu)
		vecArg.push_back(str2[uuu]);
}
void decompress(unsigned char * arr, int nCopySize)
{
	using namespace boost::iostreams;
	std::string str1(reinterpret_cast<const char *>(arr), nCopySize);
	if (bDebug)
		for (auto uuu = str1.begin(); uuu != str1.end(); ++uuu)
			printf(" %02x", *uuu);
	auto sizeT = str1.size();
	if (bDebug)
		cout << "\nSize : " << sizeT << endl;
	istringstream file2(str1, ios_base::in | ios_base::binary);
	filtering_streambuf<input> iin;
	iin.push(gzip_decompressor());
	iin.push(file2);
	boost::iostreams::copy(iin, cout);
	file2 >> str1;
	cout << "\nStr1 : \n" << str1 << endl;
}
void ConnectIeSnare()
{
	using boost::asio::ip::tcp;
	namespace ssl = boost::asio::ssl;
	typedef ssl::stream<tcp::socket> ssl_socket;

	// Create a context that uses the default paths for
	// finding CA certificates.
	ssl::context ctx(ssl::context::tlsv11);
	ctx.set_default_verify_paths();

	// Open a socket and connect it to the remote host.
	boost::asio::io_service io_service;
	ssl_socket sock(io_service, ctx);
	tcp::resolver resolver(io_service);
	//NA login ip : 208.67.49.148
	tcp::resolver::query query("mpsnare.iesnare.com", "https");
	//tcp::resolver::query query("facebook.com", "https");
	boost::asio::connect(sock.lowest_layer(), resolver.resolve(query));
	sock.lowest_layer().set_option(tcp::no_delay(true));

	// Perform SSL handshake and verify the remote host's
	// certificate.
	sock.set_verify_mode(ssl::verify_none);
	sock.set_verify_callback(ssl::rfc2818_verification("mpsnare.iesnare.com"));
	sock.handshake(ssl_socket::client);
}
void GetFogAms(std::string& strArg)
{
	std::string out = "Received Messages.txt";
	std::ifstream finGetAms(out.c_str());
	string toc;
	while (getline(finGetAms, out))
	{
		toc += out;
		toc.push_back(0x0d);
		toc.push_back(0x0a);
	}
	toc.push_back(0x0a);
	//search for fog ams id
	auto SizeStart = toc.find("Cookie: _fog_ams_session");
	//auto SizeEnd = toc.find_last_of("Cookie: ");
	std::string strAString;
	strAString = toc.substr(SizeStart);
	auto SizeEnd = strAString.find_first_of(";");
	strAString = strAString.substr(0, SizeEnd);
	strAString.append("\n\n");
	cout << strAString << endl;
	strArg = strAString;
}
void SetTokenEnd(string& strArg)
{
	string account = "Account.txt";
	std::ifstream accountInput(account);
	string str1 = "email%5D=";
	string str2;
	string str3 = "&user%5Bpassword%5D=";
	string str4;
	string str5 = "&user%5Blanguage%5D=fr";
	//we get the mail here
	getline(accountInput, str2);
	//we replace @ by %40
	auto nSize1 = str2.find_first_of("@");
	if (nSize1 != string::npos)
	{
		str2[nSize1] = '%';
		str2.insert(nSize1 + 1, "40");
	}
	nSize1 = str2.find_first_of("+");
	if (nSize1 != string::npos)
	{
		str2[nSize1] = '%';
		str2.insert(nSize1 + 1, "2B");
	}
	//we get the password
	getline(accountInput, str4);
	//we append them all
	str1 += str2 += str3 += str4 += str5;
	cout << str1 << endl;
	cout << "size : " << str1.size() << endl;
	strArg = str1;

}
int LoginMain(char *arr)
{
	//makes sure further rand() actually have different values each time the program is ran
	int oui;
	srand(time(0));
	string str1;
	SetTokenEnd(str1);
	std::string fog_ams;
	 //char arr[128];
	int nChoice = 1;
	cout << "Type 1 to send First Message, 2, 3 or 4 respectively." << endl;
	nChoice = 1;
	switch (nChoice)
	{
	case 1:
		LoginUE(arr, str1);
		GetFogAms(fog_ams);
		test2(fout1, fog_ams);
		test3(fout1, arr, fog_ams);
		break;
	case 2:
		break;
	case 3:
		test2(fout1, fog_ams);
		break;
	case 4:
		test3(fout1, arr, fog_ams);
		break;
	}
	return 0;
}

