// ConsoleApplication2.cpp : Defines the exported functions for the DLL application.
//
#include <boost/asio.hpp>
#include "BotClass.h"
#include "PacketData.h"
#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector < unsigned char> vfriend1;
std::vector < unsigned char> vfriend2;
std::vector < unsigned char> vfriend3;
std::vector < unsigned char> vfriend4;
std::vector < unsigned char> vfriend5;
std::vector < unsigned char> vfriend6;
std::vector < unsigned char> vfriend7;
std::vector < unsigned char> vfriend8;
std::vector < unsigned char> vfriend9;
std::vector < unsigned char> vfriend10;
std::vector < unsigned char> vfriend11;
std::vector < unsigned char> vfriend12;
std::vector < unsigned char> vfriend13;
std::vector < unsigned char> vfriend14;
std::vector < unsigned char> vfriend15;
std::vector < unsigned char> vfriend16;
std::vector < unsigned char> vfriend17;
std::vector < unsigned char> vfriend18;
std::vector < unsigned char> vfriend19;
bool bEU(0);
bool bNA(0);
bool bKillian(0);
bool bTR(0);
bool bMT(0);
bool bKn(0);
bool bFR(0);
bool bWatcher(0);
bool bPowerLevel(0);
bool bPowerLeveled(0);
bool bTeraClub(0);
bool bAutoLogin(1);
int nThrallCD(0);
int size123 = 127;
void FillMap();
void UpdateParameters(std::ofstream& fout)
{
	int nPattern(0);
	using namespace std;
	cout << "Enter thrall cooldown in seconds : " << endl;
	cin >> nThrallCD;
	cout << "Chose a bot pattern by entering a number :\n1 for Kelsaik.\n2 for Powerlevel.\n3 for getting powerleveled.\n4 for Watcher." << endl;
	cin >> nPattern;
	while (nPattern != 1 && nPattern != 2 && nPattern != 3 && nPattern != 4)
	{
		cout << "Wrong input, please enter the correct number :\n1 for Kelsaik.\n2 for Powerlevel.\n3 for getting powerleveled.\n4 for Watcher. " << endl;
	}
	switch (nPattern)
	{
	case 1:
		bKn = 1;
		break;
	case 2:
		bPowerLevel = 1;
		break;
	case 3:
		bPowerLeveled = 1;
		break;
	case 4:
		bWatcher = 1;
		break;
	}
	cout << "Would you like to use AutoLogin feature (supported on UE) ? (enter y/n)" << endl;
	char chLogin;
	cin >> chLogin; 
	while (chLogin != 'y'&& chLogin != 'n')
	{
		cout << "Wrong input, only enter y or n" << endl;
		cin >> chLogin;
	}
	switch (chLogin)
	{
	case 'y':
		bAutoLogin = 1;
		break;
	case 'n':
		bAutoLogin = 0;
		break;
	}
	cout << "Use this bot for UE  ?(y/n)" << endl;
	char chEu;
	cin >> chEu;
	while (chEu != 'y'&& chEu != 'n')
	{
		chEu = '0';
		cout << "Wrong input, only enter y or n" << endl;
		cin >> chEu;
	}
	switch (chEu)
	{
	case 'y':
		bEU = 1;
		bNA = 0;
		break;
	case 'n':
		bNA = 1;
		bEU = 0;
		cout << "Assuming this bot is meant for NA cotinent." << endl;
	}
	cout << "Chose your server : \n 1 for MT,\n2 for TR, \n3 for Killian \n4 for Fraya." << endl;
	int nServer(0);
	cin >> nServer;
	while (nServer != 1 && nServer != 2 && nServer != 3 && nServer != 4)
	{
		nServer = 0;
		cout << "Chose your server : \n 1 for MT,\n2 for TR, \n3 for Killian \n4 for Fraya." << endl;
		cin >> nServer;
	}
	switch (nServer)
	{
	case 1:
		bMT = 1;
		bFR = 0;
		bTR = 0;
		bKillian = 0;
		break;
	case 2:
		bMT = 0;
		bFR = 0;
		bTR = 1;
		bKillian = 0;
		break;
	case 3:
		bMT = 0;
		bFR = 0;
		bTR = 0;
		bKillian = 1;
		break;
	case 4:
		bMT = 0;
		bFR = 1;
		bTR = 0;
		bKillian = 0;
		break;
	}
	string parameters="";
	parameters = "[friends]\n";
	parameters += "[Mystic Partner]\n";
	parameters += "[Watcher]\n";
	parameters += "[ThrallCooldown]\n";
	parameters += to_string(nThrallCD);
	parameters += "\n";
	parameters += "[Patterns]\n";
	if (bKn)
		parameters += "Kelsaik = TRUE\n";
	else
		parameters += "Kelsaik = FALSE\n";
	if (bPowerLevel)
		parameters += "PowerLevel = TRUE\n";
	else
		parameters += "PowerLevel = FALSE\n";
	if (bWatcher)
		parameters += "Watcher = TRUE\n";
	else
		parameters += "Watcher = FALSE\n";
	if (bPowerLeveled)
		parameters += "GetLeveled = TRUE\n";
	else
		parameters += "GetLeveled = FALSE\n";
	parameters += "[Game Version]\n";
	if (bEU)
		parameters += "EU = TRUE\n";
	else
		parameters += "EU = FALSE\n";
	if (bNA)
		parameters += "NA = TRUE\n";
	else
		parameters += "NA = FALSE\n";
	parameters += "[Servers]\n";
	if (bMT)
		parameters += "Mount Tyranas = TRUE\n";
	else
		parameters += "Mount Tyranas = FALSE\n";
	if (bFR)
		parameters += "Fraya = TRUE\n";
	else
		parameters += "Fraya = FALSE\n";
	if (bKillian)
		parameters += "Killian = TRUE\n";
	else
		parameters += "Killian = FALSE\n";
	if (bTR)
		parameters += "Tempest Reach = TRUE\n";
	else
		parameters += "Tempest Reach = FALSE\n";
	parameters += "[Login]\n";
	if (chLogin == 'y')
		parameters += "Use Auto Login = TRUE\n";
	else
		parameters += "Use Auto Login = FALSE\n";
	fout << parameters;

}
int HandleConfig()
{
	using namespace std;
	fstream fin("config.txt");
	if (fin.is_open())
	{
		cout << "Config file detected. Retrieving data settings.." << endl;
		fin.close();
		return 0;
	}
	else
	{
		fin.open("o.txt");
		cout << "No config file detected, assuming first use for this bot session. \nCreating new config file. \nPlease enter the requested information from console, enter mystic names directly in the config.txt file afterwards." << endl;
		ofstream fout("config.txt");
		UpdateParameters(fout);
		fout.close();
	}
	return 1;
}
void UpdateMysticPartner(string &line) {
	if (line != "[Mystic Partner]")
	{
		if (Mystic.m_vMysticPartner.empty())
		{
			for (int iii = 0; iii < line.size(); iii++)
			{
				Mystic.m_vMysticPartner.push_back(line[iii]);
				Mystic.m_vMysticPartner.push_back(0x00);
			}
			cout << "Registering a partner : " << line << endl;
		}
		else
		{
			for (int iii = 0; iii < line.size(); iii++)
			{
				Mystic.m_vMysticPartner2.push_back(line[iii]);
				Mystic.m_vMysticPartner2.push_back(0x00);
			}
			cout << "Registering a partner : " << line << endl;
		}
	}
}

void UpdateLogin(string &line) {
	if (line != "[Login]")
	{
		if (line == "Use Auto Login = TRUE")
		{
			bAutoLogin = 1;
			cout << "This bot is set up to start with my self-coded Tera Launcher." << endl;
		}
		else
		{
			bAutoLogin = 0;
			cout << "This bot is set up to start with Tera.exe client." << endl;
		}
	}
}
void UpdateWatcher(string &line) {
	if (line != "[Watcher]")
	{
		for (int iii = 0; iii < line.size(); iii++)
		{
			Mystic.m_vWatcher.push_back(line[iii]);
			Mystic.m_vWatcher.push_back(0x00);
		}
		cout << "Registering a watcher : " << line << endl;
	}

}

void UpdateRunSpeed(string &line) {
	int centaine = 0;
	int dizaine;
	int unite;
	if (line != "[Speed]")
	{
		for (int iii = 0; iii < line.size(); iii++)
		{
			if (iii == 0)
			{
				if (line[iii] == '1')
					centaine = 1;
				if (line[iii] == '2')
					centaine = 2;
				if (line[iii] == '3')
					centaine = 3;
				if (line[iii] == '4')
					centaine = 4;
				if (line[iii] == '5')
					centaine = 5;
				if (line[iii] == '6')
					centaine = 6;
				if (line[iii] == '7')
					centaine = 7;
				if (line[iii] == '8')
					centaine = 8;
				if (line[iii] == '9')
					centaine = 9;
			}
			if (iii == 1)
			{
				if (line[iii] == '1')
					dizaine = 1;
				if (line[iii] == '2')
					dizaine = 2;
				if (line[iii] == '3')
					dizaine = 3;
				if (line[iii] == '4')
					dizaine = 4;
				if (line[iii] == '5')
					dizaine = 5;
				if (line[iii] == '6')
					dizaine = 6;
				if (line[iii] == '7')
					dizaine = 7;
				if (line[iii] == '8')
					dizaine = 8;
				if (line[iii] == '9')
					dizaine = 9;
			}
			if (iii == 2)
			{
				if (line[iii] == '1')
					unite = 1;
				if (line[iii] == '2')
					unite = 2;
				if (line[iii] == '3')
					unite = 3;
				if (line[iii] == '4')
					unite = 4;
				if (line[iii] == '5')
					unite = 5;
				if (line[iii] == '6')
					unite = 6;
				if (line[iii] == '7')
					unite = 7;
				if (line[iii] == '8')
					unite = 8;
				if (line[iii] == '9')
					unite = 9;
			}
		}
		Mystic.m_nSpeed = 100 * centaine + 10 * dizaine + unite;
		cout << "Registering Run Speed : " << Mystic.m_nSpeed << " ms between movement packets (higher = slower)." << endl;
	}
}
void UpdateLoginArbiterSize(string &line) {
	cout << "The size of Login arbiter has been set to 123 bytes." << endl;
	size123 = 123;
}
void ManageTeraClub(string &line) {
	if (line == "Tera Club = TRUE")
	{
		bTeraClub = 1;
		cout << "Tera Club pattern On." << endl;
	}
	else if (line == "Tera Club = FALSE")
	{
		bTeraClub = 0;
		cout << "Tera Club pattern Off." << endl;
	}
}
void UpdateSkillsCooldown(string &line) {
	int centaine = 0;
	int dizaine;
	int unite;
	if (line != "[ThrallCooldown]")
	{
		for (int iii = 0; iii < line.size(); iii++)
		{
			if (iii == 0)
			{
				if (line[iii] == '1')
					centaine = 1;
				if (line[iii] == '2')
					centaine = 2;
				if (line[iii] == '3')
					centaine = 3;
				if (line[iii] == '4')
					centaine = 4;
				if (line[iii] == '5')
					centaine = 5;
				if (line[iii] == '6')
					centaine = 6;
				if (line[iii] == '7')
					centaine = 7;
				if (line[iii] == '8')
					centaine = 8;
				if (line[iii] == '9')
					centaine = 9;
			}
			if (iii == 1)
			{
				if (line[iii] == '1')
					dizaine = 1;
				if (line[iii] == '2')
					dizaine = 2;
				if (line[iii] == '3')
					dizaine = 3;
				if (line[iii] == '4')
					dizaine = 4;
				if (line[iii] == '5')
					dizaine = 5;
				if (line[iii] == '6')
					dizaine = 6;
				if (line[iii] == '7')
					dizaine = 7;
				if (line[iii] == '8')
					dizaine = 8;
				if (line[iii] == '9')
					dizaine = 9;
			}
			if (iii == 2)
			{
				if (line[iii] == '1')
					unite = 1;
				if (line[iii] == '2')
					unite = 2;
				if (line[iii] == '3')
					unite = 3;
				if (line[iii] == '4')
					unite = 4;
				if (line[iii] == '5')
					unite = 5;
				if (line[iii] == '6')
					unite = 6;
				if (line[iii] == '7')
					unite = 7;
				if (line[iii] == '8')
					unite = 8;
				if (line[iii] == '9')
					unite = 9;
			}
		}
		nThrallCD = 100 * centaine + 10 * dizaine + unite;
		cout << "Registering Thrall Cooldown : " << nThrallCD <<  " seconds." << endl;
	}
}
void RunChosenPattern(string &line) {
	if (line == "Kelsaik = TRUE")
	{
		bKn = 1;
		cout << "This bot is set up to run Kelsaik dungeon pattern." << endl;
	}
	else if (line == "Watcher = TRUE")
	{
		bWatcher = 1;
		cout << "This bot is set up to be a Watcher." << endl;
	}
	else if (line == "PowerLevel = TRUE")
	{
		bPowerLevel = 1;
		cout << "This bot is set up to PowerLevel" << endl;
	}
	else if (line == "GetLeveled = TRUE")
	{
		bPowerLeveled = 1;
		cout << "This bot is set up to get leveled" << endl;
	}
}
void ServerToBot(string &line) {
	if (line == "Mount Tyranas = TRUE")
	{
		bMT = 1;
		cout << "Server : Mount Tyranas" << endl;
	}
	else if (line == "Mount Tyranas = FALSE")
		bMT = 0;
	if (line == "Killian = TRUE")
	{
		bKillian = 1;
		cout << "Server : Killian" << endl;
	}
	else if (line == "Killian = FALSE")
		bKillian = 0;
	if (line == "Tempest Reach = TRUE")
	{
		bTR = 1;
		cout << "Server : Tempest Reach" << endl;
	}
	else if (line == "Tempest Reach = FALSE")
		bTR = 0;
	if (line == "Fraya = TRUE")
	{
		bFR = 1;
		cout << "Server : Fraya" << endl;
	}
	else if (line == "Fraya = FALSE")
		bFR = 0;
}
void GameVersion(string &line) {
	if (line == "EU = TRUE")
	{
		bEU = 1;
		cout << "Configuration for European Tera" << endl;
	}
	else if (line == "EU = FALSE")
		bEU = 0;
	if (line == "NA = TRUE")
	{
		bNA = 1;
		cout << "Configuration for EN MASSE (NA) Tera" << endl;
	}
	else if (line == "NA = FALSE")
		bNA = 0;
}
void RegisterFriend(std::vector <unsigned char> &vectArg, string &line) {
	for (int iii = 0; iii < line.size(); iii++)
	{
		vectArg.push_back(line[iii]);
		vectArg.push_back(0x00);
	}
}
void SortAndRegisterFriend(string &line) {
	if (vfriend1.empty())
		RegisterFriend(vfriend1, line);
	else if (vfriend2.empty())
		RegisterFriend(vfriend2, line);
	else if (vfriend3.empty())
		RegisterFriend(vfriend3, line);
	else if (vfriend4.empty())
		RegisterFriend(vfriend4, line);
	else if (vfriend5.empty())
		RegisterFriend(vfriend5, line);
	else if (vfriend6.empty())
		RegisterFriend(vfriend6, line);
	else if (vfriend7.empty())
		RegisterFriend(vfriend7, line);
	else if (vfriend8.empty())
		RegisterFriend(vfriend8, line);
	else if (vfriend9.empty())
		RegisterFriend(vfriend9, line);
	else if (vfriend10.empty())
		RegisterFriend(vfriend10, line);
	else if (vfriend11.empty())
		RegisterFriend(vfriend11, line);
	else if (vfriend12.empty())
		RegisterFriend(vfriend12, line);
	else if (vfriend13.empty())
		RegisterFriend(vfriend13, line);
	else if (vfriend14.empty())
		RegisterFriend(vfriend14, line);
	else if (vfriend15.empty())
		RegisterFriend(vfriend15, line);
	else if (vfriend16.empty())
		RegisterFriend(vfriend16, line);
	else if (vfriend17.empty())
		RegisterFriend(vfriend17, line);
	else if (vfriend18.empty())
		RegisterFriend(vfriend18, line);
	else if (vfriend19.empty())
		RegisterFriend(vfriend19, line);
}
void ReadConfigFile() {
	FillMap();
	//default auto login
	bAutoLogin = 1;
	string line;
	HandleConfig();
	ifstream myfile("config.txt");
	if (myfile.is_open())
	{
		int statementType;
		while (myfile)
		{
			getline(myfile, line);
			if (line == "[partners]")//whisper msg box parameter
				statementType = 1;
			else if (line == "[friends]")
				statementType = 2;
			else if (line == "[Tera Club]")
				statementType = 3;
			else if (line == "[ThrallCooldown]")
				statementType = 4;
			else if (line == "[Patterns]")
				statementType = 5;
			else if (line == "[Game Version]")
				statementType = 6;
			else if (line == "[Servers]")
				statementType = 7;
			else if (line == "[Speed]")
				statementType = 8;
			else if (line == "[LoginArbiter]")
				statementType = 9;
			else if (line == "[Mystic Partner]")
				statementType = 10;
			else if (line == "[Watcher]")
				statementType = 11;
			else if (line == "[Login]")
				statementType = 12;
			switch (statementType)
			{
			case 1:
				break;
			case 2:
				SortAndRegisterFriend(line);
				break;
			case 3:
				ManageTeraClub(line);
				break;
			case 4:
				UpdateSkillsCooldown(line);
				break;
			case 5:
				RunChosenPattern(line);
				break;
			case 6:
				GameVersion(line);
				break;
			case 7:
				ServerToBot(line);
				break;
			case 8:
				UpdateRunSpeed(line);
				break;
			case 9:
				UpdateLoginArbiterSize(line);
				break;
			case 10:
				UpdateMysticPartner(line);
				break;
			case 11:
				UpdateWatcher(line);
				break;
			case 12:
				UpdateLogin(line);
				break;
			}

		}
		myfile.close();
	}
	else
		cout << "could not find or open config.txt" << endl;
}

void FillMap(){
	using namespace std;
	std::ifstream file("_OpCodes_Dec.txt");
	if (file.is_open())
	{
		cout << "File found. Loading packets.." << endl;
	}
	else
	{
		cout << "File not found. Program will now close" << endl;
		system("pause");
		exit(2);
	}

	string aa;
	string bb;
	string cc;
	int o;
	while ((file >> aa) && (file >> bb) && (file >> cc))
	{
		o = stoi(cc);
		PacketHandlers[o] = aa;
		PacketHandlers_NA[o] = aa;
		//cout << o << " " << aa << endl;
	}
	cout << "Packets loaded." << endl;
}
/*			if (line == "Malua")
cout << "matched " << endl;
cout << line << '\n';
for (int iii = 0; iii < line.size(); iii++)
{
printf("%02X", line[iii]);
partnerfriend.push_back(line[iii]);
partnerfriend.push_back(0x00);
}
cout << endl;
for (int iii = 0; iii < 2 * line.size(); iii++)
{
printf("%02X", partnerfriend[iii]);
}
cout << endl;
partnerfriend.clear();
Sleep(500);*/