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
#define PI 3.14159265
#include "Packet.h"
#include "Waypoint.h"
#include "PacketData.h"
#include "UseSkills.h"
time_t tcurrentTime2;
std::vector <unsigned char> vSendSkillPacket2;
int JauntId = 0x04029874;
int ThrallWrathId(0x040532DC);//*
int orderPetAttack(0x04055794);//*
int yoyoSkill(0x04066904);
int vengeancePet(0x04050E88);
int agroPet(0x0403d6d0);//*
int auraSpeedBuff(0x040223A8);//*
int powerBuff(0x0400765C);
int iceNeedle(0x04005208);
int ArcanePulse(0x04009fd1);//(0x04009fcf);
int OverLoad(0x040161e8);
boost::shared_ptr <ProjectilePacket> ProjectilePtr;
cSkillProperties cThrall(6.1);
cSkillProperties cGoldBoost(5400);
int PressSkill::s_nStage = 0;
int GraineDeVie(0x0002C36C);
int stun(0x0000EAC4);
int Kd(0x00038658);
int teraClubGoldBuff(0x0002C8A4);
int coupDeMetamorphose(0x00013CCC);
int petFood(0x0002B3EB);
int teleportBook(0x0002C37D);
int autoAttack(0x00002BC0);
int endurancePanacea(0x00000081);
int auraCritBuff(0x0001FC98);
int jauntSkill(0x04029874);
int backstepSkill_Archer(0x0000EAC4);
int thrallOfLife(0x040423C4);
int aggroPet(0x0003D6D0);
int zero(0);

std::vector < unsigned char > FormSendSkillPacket(int nSkillId, int zero, int nWantedX, int nWantedY, int nWantedZ)
{
	std::cout << "forming skill packet" << std::endl;
std::vector <unsigned char> vSendSkillPacket;
TurnInt32_tIntoVect(nSkillId, vSendSkillPacket);
Turnuint16_t_tIntoVect(zero, vSendSkillPacket);
TurnInt32_tIntoVect(currentX, vSendSkillPacket);
TurnInt32_tIntoVect(currentY, vSendSkillPacket);
TurnInt32_tIntoVect(currentZ, vSendSkillPacket);
TurnInt32_tIntoVect(nWantedX, vSendSkillPacket);
TurnInt32_tIntoVect(nWantedY, vSendSkillPacket);
TurnInt32_tIntoVect(nWantedZ, vSendSkillPacket);
vSendSkillPacket.push_back(0x01);
for (int uuu = 0; uuu < 10; ++uuu)
	vSendSkillPacket.push_back(0x00);
std::cout << "formed skill packet" << std::endl;
return vSendSkillPacket;
}
std::vector < unsigned char > FormSendSkillPacketWithDest(int nSkillId, boost::shared_ptr <Monsters> MobPtrArg )
{
	std::cout << "forming skill packet" << std::endl;
	std::vector <unsigned char> vSendSkillPacket;
	TurnInt32_tIntoVect(nSkillId, vSendSkillPacket);
	std::vector <unsigned char> CamAndCoordonatesVec = FormSkillDestinationCoordonates(MobPtrArg->m_X, MobPtrArg->m_Y, MobPtrArg->m_Z);
	vSendSkillPacket.insert(vSendSkillPacket.end(), CamAndCoordonatesVec.begin(), CamAndCoordonatesVec.end());
	if (nSkillId == ArcanePulse)
	{
		vSendSkillPacket.push_back(0x00);
		vSendSkillPacket.push_back(0x00);
		vSendSkillPacket.push_back(0x01);
		for (int uuu = 0; uuu < 8; ++uuu)
			vSendSkillPacket.push_back(0x00);
	}
	else
	{
		vSendSkillPacket.push_back(0x01);
		for (int uuu = 0; uuu < 10; ++uuu)
			vSendSkillPacket.push_back(0x00);
	}

	std::cout << "formed skill packet" << std::endl;
	return vSendSkillPacket;
}
std::vector < unsigned char > FormSendSkillPacketWithTarget(int nSkillId, std::vector <unsigned char> vecArg, int zero, int nWantedX, int nWantedY, int nWantedZ) // Overload #1
{
	std::cout << "forming skill packet" << std::endl;
	std::vector <unsigned char> vSendSkillPacket;
	TurnInt32_tIntoVect(nSkillId, vSendSkillPacket);
	Turnuint16_t_tIntoVect(zero, vSendSkillPacket);
	TurnInt32_tIntoVect(currentX, vSendSkillPacket);
	TurnInt32_tIntoVect(currentY, vSendSkillPacket);
	TurnInt32_tIntoVect(currentZ, vSendSkillPacket);
	TurnInt32_tIntoVect(nWantedX, vSendSkillPacket);
	TurnInt32_tIntoVect(nWantedY, vSendSkillPacket);
	TurnInt32_tIntoVect(nWantedZ, vSendSkillPacket);
	vSendSkillPacket.push_back(0x01);
	for (int uuu = 0; uuu < 2; ++uuu)
		vSendSkillPacket.push_back(0x00);
	if (!(vecArg.empty()))
	{
		for (int uuu = 0; uuu < 8; ++uuu)
			vSendSkillPacket.push_back(vecArg[uuu]);
	}
	else
		std::cout << "error ! kn vector id was empty !" << std::endl;
	std::cout << "formed skill packet" << std::endl;
	return vSendSkillPacket;
}