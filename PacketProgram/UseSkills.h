#include <vector>
#include "PacketData.h"
#include "Packet.h"
#include "PacketReception.h"
#include "MonsterInterraction.h"
#include "Waypoint.h"
#ifndef USESKILL_H
#define USESKILL_H
using namespace std;
extern int zero;
extern int JauntId;
extern int yoyoSkill;
extern int ThrallWrathId;
extern int orderPetAttack;
extern int agroPet;
extern int vengeancePet;
extern int auraSpeedBuff;
extern int powerBuff;
extern int iceNeedle;
extern int ArcanePulse;
extern int OverLoad;
extern time_t tcurrentTime2;
extern std::vector <unsigned char> vSendSkillPacket2;
//========================================================== Function prototypes :
std::vector < unsigned char > FormSendSkillPacket(int nSkillId, int zero = 0, int nWantedX = 0, int nWantedY = 0, int nWantedZ = 0);
std::vector < unsigned char > FormSendSkillPacketWithTarget(int nSkillId, std::vector <unsigned char> vecArg, int zero = 0,int nWantedX = 0, int nWantedY = 0, int nWantedZ = 0); // overload #1
std::vector < unsigned char > FormSendSkillPacketWithDest(int nSkillId, boost::shared_ptr <Monsters> MobPtrArg);
//
class cSkillProperties
{
private :
	double m_dCoolTime = 0;
	time_t m_tSkillUsedTime = 1;
public:
	cSkillProperties() {

	}

	cSkillProperties(double dCoolTime) : m_dCoolTime(dCoolTime) {

	}

	bool CheckIfCooldownReady() {
		tcurrentTime2 = time(0);
		double dDiffTime = (difftime(tcurrentTime2, m_tSkillUsedTime) - m_dCoolTime);
		if (dDiffTime >= 0)
			return 1;
		else
			return 0;
	}
	void UseSkill(uint16_t nSize, const uint16_t nTitle, std::vector<unsigned char> vectArgument, boost::shared_ptr<boost::asio::ip::tcp::socket> socket) {
		if (CheckIfCooldownReady())
		{
			HandleUndecipheredPacket(nSize, nTitle, vectArgument, socket);
			m_tSkillUsedTime = time(0);
		}
	}
};
extern cSkillProperties cThrall;
extern cSkillProperties cGoldBoost;
class PressSkill
{
private:

public:
	static int s_nStage;
	PressSkill()
	{
		s_nStage = -1;
	}
	static void IncreaseSkillStage()
	{
		++s_nStage;
	}
	static void FormAndSendPressSkillPackets(boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
	{
		std::vector <unsigned char> SkillId;
		std::vector<unsigned char> PressSkillPacket;
		SkillId = { 0xc4, 0x9f, 0x00, 0x04 };
		PressSkillPacket.insert(PressSkillPacket.end(), SkillId.begin(), SkillId.end());
		if (s_nStage == -1)
		{
			PressSkillPacket.push_back(0x01);
		}
		else
		{
			PressSkillPacket.push_back(0x00);
		}
		++s_nStage;
		std::vector < unsigned char > MobX = TurnInt32_tIntoVect2(currentX);
		std::vector < unsigned char > MobY = TurnInt32_tIntoVect2(currentY);
		std::vector < unsigned char > MobZ = TurnInt32_tIntoVect2(currentZ);
		PressSkillPacket.insert(PressSkillPacket.end(), MobX.begin(), MobX.end());
		PressSkillPacket.insert(PressSkillPacket.end(), MobY.begin(), MobY.end());
		PressSkillPacket.insert(PressSkillPacket.end(), MobZ.begin(), MobZ.end());
		PressSkillPacket.push_back(0x00);
		PressSkillPacket.push_back(0x00);
		HandleUndecipheredPacket(size23x17, C_PRESS_SKILL, PressSkillPacket, socket);
	}

};

class ProjectilePacket {
private :
	std::vector <unsigned char> vProjectileCount;
	std::vector <unsigned char> vEndingCoordonatesProjectile;
	std::vector <unsigned char> vHitMobProjectilePacket;
	std::vector <unsigned char> vEndProjectilePacket;
	std::vector <unsigned char> vHitPacket;
	ProjectilePacket() {} //default constructor is private as it is not supposed to be called
public :
	bool m_bLifeState;
	ProjectilePacket(std::vector<unsigned char> &undecVecArg) : m_bLifeState(1)
	{
		vHitPacket.push_back(0x01);
		vHitPacket.push_back(0x00);
		vHitPacket.push_back(0x1D);
		vHitPacket.push_back(0x00);
		for (int uuu = 20; uuu < 28; ++uuu)
		{
			vProjectileCount.push_back(undecVecArg[uuu + nAnalyzedSize]);
		}
		for (int uuu = 44; uuu < 56; ++uuu)
		{
			vEndingCoordonatesProjectile.push_back(undecVecArg[uuu + nAnalyzedSize]);
		}
	}
	void FormPojectilePackets(boost::shared_ptr <Monsters> & MobPtrArg)
	{ //forming ending projectile packet first
		for (int uuu = 0; uuu < 4; ++uuu)
		{
			vEndProjectilePacket.push_back(0x00);
		}
		cout << "//1" << endl;
		vEndProjectilePacket.insert(vEndProjectilePacket.end(), vProjectileCount.begin(), vProjectileCount.end());
		vEndProjectilePacket.push_back(0x01);//doesn't hit byte
		vEndProjectilePacket.insert(vEndProjectilePacket.end(), vEndingCoordonatesProjectile.begin(), vEndingCoordonatesProjectile.end());
		//forming hitting projectile Packet
		cout << "//2" << endl;
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), vHitPacket.begin(), vHitPacket.end());
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), vProjectileCount.begin(), vProjectileCount.end());
		vHitMobProjectilePacket.push_back(0x00);//hits byte
		//The way this code goes there can be only one mob hit per projectile object
		cout << "//2.5" << endl;
		std::vector < unsigned char > MobX = TurnInt32_tIntoVect2(MobPtrArg->m_X);
		std::vector < unsigned char > MobY = TurnInt32_tIntoVect2(MobPtrArg->m_Y);
		std::vector < unsigned char > MobZ = TurnInt32_tIntoVect2(MobPtrArg->m_Z);
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), MobX.begin(), MobX.end());
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), MobY.begin(), MobY.end());
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), MobZ.begin(), MobZ.end());
		cout << "//3" << endl;
		vHitMobProjectilePacket.push_back(0x1D);
		vHitMobProjectilePacket.push_back(0x00);
		vHitMobProjectilePacket.push_back(0x00);
		vHitMobProjectilePacket.push_back(0x00);
		vHitMobProjectilePacket.insert(vHitMobProjectilePacket.end(), (MobPtrArg->m_Id).begin(), (MobPtrArg->m_Id).end());
	}
	void SendProjectileHitPacket(int nIteration, boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
	{
		HandleUndecipheredPacket(size41x29, C_HIT_USER_PROJECTILE, vHitMobProjectilePacket, nIteration, socket);
	}
	void SendProjectileEndPacket(boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
	{
		cout << "sending  end projectile" << endl;
		cout << "the size of end projectile vector is " << vEndProjectilePacket.size() << endl;
		HandleUndecipheredPacket(size29x1D, C_HIT_USER_PROJECTILE, vEndProjectilePacket, socket);
	}
};
extern boost::shared_ptr <ProjectilePacket> ProjectilePtr;

#endif