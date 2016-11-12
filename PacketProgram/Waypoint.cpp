#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
//#include <cstdlib>
#include <string.h>
#include <math.h>
#include <ctime>
#include <vector>
#include "BotClass.h"
#include "UseSkills.h"
#define PI 3.14159265
#include "Packet.h"
#include "MonsterInterraction.h"
#include "Pattern.h"
int wantedXForKnStairs = 0x478CF92A;
int wantedYForKnStairs = 0x480B18A3;
int wantedZForKnStairs = 0xC6263E03;
int wantedXForEaxKnFeetInt = 0x478F646F;
int wantedYForEaxKnFeetInt = 0x480B9548;
int wantedZForEaxKnFeetInt = 0xC62CCF89;
int wantedXForEaxKnSideFeetInt = 0x478FA60B;
int wantedYForEaxKnSideFeetInt = 0x480C3027;
int wantedZForEaxKnSideFeetInt = 0xC62CCF89;
int wantedXForEaxKnInvincibleFeetInt = 0x478F646F;
int wantedYForEaxKnInvincibleFeetInt = 0x480B9548;
int wantedZForEaxKnInvincibleFeetInt = 0xC62DB4D7;
int KnEntranceInsideDungeonX = 0x477497EC;
int KnEntranceInsideDungeonY = 0x4811AE7A;
int KnEntranceInsideDungeonZ = 0xC6140B13;
int InterractSellNpcKnX = 0x47743F89;
int InterractSellNpcKnY = 0x48118D6B;
int InterractSellNpcKnZ = 0xC6140B13;
//
int nCentralPowerLevelX = 0x46878256;
int nCentralPowerLevelY = 0xC6125EDF;
int nCentralPowerLevelZ = 0x457027D5;
//
int wantedXEnterKnDungeon = 0x460C55CE;
int wantedYEnterKnDungeon = 0x470524D8;
int wantedZEnterKnDungeon = 0x460ebb80; // 0x46103318;

//pointers
using namespace std;
int camAngle;
std::vector<unsigned char> MovementPacket;
std::vector<unsigned char> MovementPacket2;
void Get3EmptyBytes(std::vector<unsigned char> &vectArg) {
	vectArg.push_back(0);
	vectArg.push_back(0);
	vectArg.push_back(0);
}
int TurnVectInto32_int(std::vector<unsigned char> &vectArgument,int StartCount, int &nAnalyzedSize)
{
	int nVariable = ((vectArgument[StartCount + nAnalyzedSize]) | (vectArgument[StartCount + 1 + nAnalyzedSize] << 8) | ((vectArgument[StartCount + 2 + nAnalyzedSize]) << 16) | (vectArgument[StartCount + 3 + nAnalyzedSize] << 24));
	return nVariable;
}
long long TurnVecInto64_int(std::vector<unsigned char> &vectArgument, int StartCount, int &nAnalyzedSize)
{
	long long llVariable = ((vectArgument[StartCount + nAnalyzedSize]) | (vectArgument[StartCount + 1 + nAnalyzedSize] << 8) | ((vectArgument[StartCount + 2 + nAnalyzedSize]) << 16) | (vectArgument[StartCount + 3 + nAnalyzedSize] << 24) | (vectArgument[StartCount + 4 + nAnalyzedSize] << 32) | (vectArgument[StartCount + 5 + nAnalyzedSize] << 40) | (vectArgument[StartCount + 6 + nAnalyzedSize] << 48) | (vectArgument[StartCount + 7 + nAnalyzedSize] << 56));
	return llVariable;
}
void TurnInt32_tIntoVect(int &int32_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(int32_t & 0xFF);
	vectArg.push_back((int32_t >> 8) & 0xFF);
	vectArg.push_back((int32_t >> 16) & 0xFF);
	vectArg.push_back((int32_t >> 24) & 0xFF);
}
void TurnInt32_tIntoVect_rvalue(int int32_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(int32_t & 0xFF);
	vectArg.push_back((int32_t >> 8) & 0xFF);
	vectArg.push_back((int32_t >> 16) & 0xFF);
	vectArg.push_back((int32_t >> 24) & 0xFF);
}
std::vector<unsigned char> TurnInt32_tIntoVect2(int &int32_t) { //every packet class has its own
	std::vector <unsigned char> vectArg;
	vectArg.push_back(int32_t & 0xFF);
	vectArg.push_back((int32_t >> 8) & 0xFF);
	vectArg.push_back((int32_t >> 16) & 0xFF);
	vectArg.push_back((int32_t >> 24) & 0xFF);
	return vectArg;
}
void TurnInt32_tIntoTwoBytesVect(int &int32_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(int32_t & 0xFF);
	vectArg.push_back((int32_t >> 8) & 0xFF);
	vectArg.push_back(0);
	vectArg.push_back(0);
}
void TurnInt32_tIntoTwoBytesVect_2(int &int32_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(int32_t & 0xFF);
	vectArg.push_back((int32_t >> 8) & 0xFF);
}
void Turnuint16_t_tIntoVect(int &uint16_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(uint16_t & 0xFF);
	vectArg.push_back(uint16_t >> 8);
}
void Turnuint16_t_tIntoVect_rvalue(int uint16_t, std::vector<unsigned char> &vectArg) { //every packet class has its own
	vectArg.push_back(uint16_t & 0xFF);
	vectArg.push_back(uint16_t >> 8);
}
//HandleUndecipheredPacket(size09x09, C_SELECT_USER, { 0x88, 0xaf, 0x21, 0x00, 0x00 }, socket);
void calculateCoordonatesDifference(float &expectedX, float &expectedY)
{
	Mystic.differenceX = expectedX - Mystic.xPosition;//this must be in float
	Mystic.differenceY = expectedY - Mystic.yPosition;
}
long double result1;
void calculateCameraAngle(float &xargument, float &yargument) // we give it the differences
{
	long double result; // définies telles de bonnes vraies variables locales
	{
		result1 = atan2(yargument, xargument);
		result = result1*(0xFFFF / (2 * PI));//FFFF = 65535
		camAngle = (int)result;
		//cout << "resulting cam angle is : " << hex << camAngle << endl;
	}
}
int n;
float result;
float calculateTotalDistance(float &xarg, float &yarg) {
	float fTotalDistance = (Mystic.differenceY / sin(result1));
	//cout << "distance is : " << fTotalDistance << endl;
	return fTotalDistance;
}
float smallx;
float smally;
int smallx_2;
int smally_2;
float interPacketX;
float interPacketY;
int interPacket_X;
int interPacket_Y;
void calculateSmallXandY() {
	smallx = 160 * cos(result1);
	smally = 160 * sin(result1);
	float innerPacketFinalX = smallx + Mystic.xPosition;//ici
	float innerPacketFinalY = smally + Mystic.yPosition;
	smally_2 = *(int*)&innerPacketFinalY;
	smallx_2 = *(int*)&innerPacketFinalX;
	//cout << "en float puis en hex, voici DeltaX : " << smallx << " hex : " << hex << smallx_2 << endl;
	//cout << "en float puis en hex, voici DeltaX : " << smally << " hex : " << hex << smally_2 << endl;

}
int wantedX = 0x478b906f;
int wantedY = 0xc7a77e69;
int wantedZ = 0xC55b678f;
int currentX = 0x47883dda;
int currentY = 0xc7a439f3;
int currentZ = 0xC55b678f;
int nOnTheMove = 0;
int nAfterTheMove = 0x07; //07 normally
float followingLocX;
int followingLoc_X;
float followingLocY;
int followingLoc_Y;
float reCastedY;
float reCastedX;
void emulatePackets();
std::vector<unsigned char> ForMovementPacket(int nWantedX, int nWantedY, int nWantedZ);
int maiytn() {
		while (1)
		{
			int prout;
			cin >> prout;
			MovementPacket2 = ForMovementPacket(wantedX, wantedY, wantedZ);
			for (int iii = 0; iii <= 38; ++iii)
			{
				printf(" %02x", MovementPacket2[iii]);
			}
		}
	return 0;
}
void emulatePackets() {
	interPacketX = (20 * sqrt(17)) * cos(result1);
	interPacketY = (20 * sqrt(17)) * sin(result1);
	//cout << "starting adresses : " << currentX << " y : " << currentY << endl;
	followingLocX = Mystic.xPosition + interPacketX;
	//Mystic.xPosition = Mystic.xPosition + interPacketX;
	followingLoc_X = *(int*)&followingLocX;
	currentX = followingLoc_X;
	followingLocY = Mystic.yPosition + interPacketY; // cest la location en float du prochain packet
	//Mystic.yPosition = Mystic.yPosition + interPacketY;
	followingLoc_Y = *(int*)&followingLocY;
	currentY = followingLoc_Y;
	//cout << "next packet starting address (true) : " << followingLoc_X << " and y : " << followingLoc_Y << endl; // its the next packet start
}
int ReturnCamAngleInt(int nWantedX, int nWantedY, int nWantedZ) {
	std::vector<unsigned char> MovementPacket;
	reCastedX = *(float *)&nWantedX;
	reCastedY = *(float *)&nWantedY;
	Mystic.xPosition = *(float *)&currentX;
	Mystic.yPosition = *(float *)&currentY;
	calculateCoordonatesDifference(reCastedX, reCastedY);
	calculateCameraAngle(Mystic.differenceX, Mystic.differenceY);
	TurnInt32_tIntoTwoBytesVect(camAngle, MovementPacket);
	return camAngle;
}
std::vector<unsigned char> FormSkillDestinationCoordonates(int nWantedX, int nWantedY, int nWantedZ)
{
	std::vector<unsigned char> MovementPacket;
	reCastedX = *(float *)&nWantedX;
	reCastedY = *(float *)&nWantedY;
	Mystic.xPosition = *(float *)&currentX;
	Mystic.yPosition = *(float *)&currentY;
	calculateCoordonatesDifference(reCastedX, reCastedY);
	calculateCameraAngle(Mystic.differenceX, Mystic.differenceY);
	float fDistance = calculateTotalDistance(Mystic.differenceX, Mystic.differenceY);
	if (fDistance >= (20 * sqrt(17))) //82.4(20 * sqrt(17)
	{
		calculateSmallXandY();
		TurnInt32_tIntoTwoBytesVect_2(camAngle, MovementPacket);
		TurnInt32_tIntoVect(currentX, MovementPacket);
		TurnInt32_tIntoVect(currentY, MovementPacket);
		TurnInt32_tIntoVect(currentZ, MovementPacket);
		TurnInt32_tIntoVect(smallx_2, MovementPacket);
		TurnInt32_tIntoVect(smally_2, MovementPacket);
		TurnInt32_tIntoVect(currentZ, MovementPacket);
		return MovementPacket;
	}
	else
	{
		currentX = nWantedX;
		currentY = nWantedY;
		currentZ = nWantedZ;
		TurnInt32_tIntoTwoBytesVect_2(camAngle, MovementPacket);
		TurnInt32_tIntoVect(currentX, MovementPacket);
		TurnInt32_tIntoVect(currentY, MovementPacket);
		TurnInt32_tIntoVect(currentZ, MovementPacket);
		TurnInt32_tIntoVect(nWantedX, MovementPacket);
		TurnInt32_tIntoVect(nWantedY, MovementPacket);
		TurnInt32_tIntoVect(nWantedZ, MovementPacket);
		return MovementPacket;
	}
}
std::vector<unsigned char> ForMovementPacket(int nWantedX, int nWantedY, int nWantedZ) {
	std::vector<unsigned char> MovementPacket;
	reCastedX = *(float *)&nWantedX;
	reCastedY = *(float *)&nWantedY;
	Mystic.xPosition = *(float *)&currentX;
	Mystic.yPosition = *(float *)&currentY;
	calculateCoordonatesDifference(reCastedX, reCastedY);
	calculateCameraAngle(Mystic.differenceX, Mystic.differenceY);
	float fDistance = calculateTotalDistance(Mystic.differenceX, Mystic.differenceY);
	if (fDistance >= (20 * sqrt(17))) //82.4  == (20 * sqrt(17)
	{
		calculateSmallXandY();
		TurnInt32_tIntoVect(currentX, MovementPacket);
		TurnInt32_tIntoVect(currentY, MovementPacket);
		TurnInt32_tIntoVect(currentZ, MovementPacket);
		TurnInt32_tIntoTwoBytesVect(camAngle, MovementPacket);
		TurnInt32_tIntoVect(smallx_2, MovementPacket);
		TurnInt32_tIntoVect(smally_2, MovementPacket);
		TurnInt32_tIntoVect(currentZ, MovementPacket);
		TurnInt32_tIntoVect(nOnTheMove, MovementPacket);
		Get3EmptyBytes(MovementPacket);
		int tick = GetTickCount();
		TurnInt32_tIntoVect(tick, MovementPacket);
		//cout << "long distance." << endl;
		emulatePackets();
		return MovementPacket;
	}
	else
	{
		currentX = nWantedX;
		currentY = nWantedY;
		currentZ = nWantedZ;
		TurnInt32_tIntoVect(nWantedX, MovementPacket);
		TurnInt32_tIntoVect(nWantedY, MovementPacket);
		TurnInt32_tIntoVect(nWantedZ, MovementPacket);
		TurnInt32_tIntoTwoBytesVect(camAngle, MovementPacket);
		TurnInt32_tIntoVect(nWantedX, MovementPacket);
		TurnInt32_tIntoVect(nWantedY, MovementPacket);
		TurnInt32_tIntoVect(nWantedZ, MovementPacket);
		TurnInt32_tIntoVect(nAfterTheMove, MovementPacket);
		Get3EmptyBytes(MovementPacket);
		int tick = GetTickCount();
		TurnInt32_tIntoVect(tick, MovementPacket);
		//cout << "short distance." << endl;
		return MovementPacket;
	}
}

std::vector <unsigned char> FormNotifyActionLocationPacket(int nWantedX, int nWantedY, int nWantedZ) {
std::vector <unsigned char> vLocationAction;
	currentX = nWantedX - 0x1;
	currentY = nWantedY - 0x1; // this so it will send a unique movement packet
	currentZ = nWantedZ;
	TurnInt32_tIntoVect(JauntId, MovementPacket);
	vLocationAction.push_back(0x01);
	Get3EmptyBytes(vLocationAction);
	TurnInt32_tIntoVect(nWantedX, MovementPacket);
	TurnInt32_tIntoVect(nWantedY, MovementPacket);
	TurnInt32_tIntoVect(nWantedZ, MovementPacket);
	vLocationAction.push_back(0x00);
	vLocationAction.push_back(0x00);
	return vLocationAction;
}


void GoToTheseCoordonateAtThisSpeed(int nSleepTime, int wantedXForEaxKnFeetInt, int wantedYForEaxKnFeetInt, int wantedZForEaxKnFeetInt, boost::asio::ip::tcp::socket & socket)
{
	do
	{
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(nSleepTime);
	} while (wantedXForEaxKnFeetInt != currentX);
}
void GoToTheseCoordonateAtThisSpeedUndetected(int nSleepTime, int wantedXForEaxKnFeetInt, int wantedYForEaxKnFeetInt, int wantedZForEaxKnFeetInt, int nHideZ, boost::asio::ip::tcp::socket & socket)
{
	do
	{
		if (nNumberOfEnnemies)
		{
			DealWithEnnemiesDuringPlvl(socket, nHideZ);
		}
		MovementPacket2 = ForMovementPacket(wantedXForEaxKnFeetInt, wantedYForEaxKnFeetInt, wantedZForEaxKnFeetInt);
		HandleUndecipheredPacket(size43x2b, C_PLAYER_LOCATION, MovementPacket2, socket);
		Sleep(nSleepTime);
	} while (wantedXForEaxKnFeetInt != currentX);
}