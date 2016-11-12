#ifndef BOTCLASS_H
#define BOTCLASS_H
#include <atomic>
extern time_t thrallTime;
class Bot
{
public:
	int m_nFilteredPickUpItems = 0;
	float xPosition = 0;
	float yPosition = 0;
	float zPosition = 0;
	float differenceX = 0;
	float differenceY;
	float differenceZ;
	char name[14];
	int m_nSpeed = 370; // used to be 350 brawler patch
	int m_nGoldInventory = 0;
	int m_nStartingGold = 0;
	bool bm_LeaderState = 1;
	bool m_bPartnerReady = 0;
	bool m_bSendDialogEnd = 0;
	int m_bConnexionState = 0;
	std::atomic <int64_t> m_SentOctets = 0;
	std::atomic <int64_t> m_ReceivedOctets = 0;
	std::atomic <int64_t> m_TotalOctets = 0;
	std::atomic <int> m_nPickedItems = 0;
	std::atomic <int> m_nDroppedItems = 0;
	std::atomic <bool> m_bTpHack = 1;
	std::atomic <bool> m_bTpHackLoot = 1;
	double m_dAverageGph = 0;
	int m_nLevel = 0;
	std::vector <unsigned char> m_vMysticPartner;
	std::vector <unsigned char> m_vMysticPartner2;
	std::vector <unsigned char> m_vWatcher;
	std::vector <unsigned char> m_vId;
	std::vector <unsigned char> vm_Id;
	std::vector <unsigned char> m_vMysticName;
	std::vector <unsigned char> m_vDialogVectorEnd;
	Bot(float x, float y, float z) : xPosition(x), yPosition(y), zPosition(z){

	}
	Bot(){

	}
};
void EnterDungeonWhenReady(boost::asio::ip::tcp::socket & socket);
int timersUsa();
void timerPowerLevel();
void PartyInvite(std::vector<unsigned char> & vectArgument, boost::asio::ip::tcp::socket & socket);
extern int nNumerOfRuns;
#endif

extern Bot Mystic;