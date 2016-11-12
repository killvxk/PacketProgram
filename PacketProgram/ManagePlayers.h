
#ifndef MANAGEPLAYERS_H
#define MANAGEPLAYERS_H
#include <vector>
#include <boost/shared_ptr.hpp>
#include <map>
#include <iostream>
extern int vecSize;
extern std::vector<unsigned char> vPlayer1;
extern std::vector<unsigned char> vPlayer2;
extern std::vector<unsigned char> vPlayer3;
extern std::vector<unsigned char> vPlayer4;
extern std::vector<unsigned char> vPlayer5;
extern std::vector<unsigned char> vPlayer6;
extern std::vector<unsigned char> vPlayer7;
extern std::vector<unsigned char> vPlayer8;
extern std::vector<unsigned char> vPlayer9;
extern std::vector<unsigned char> vPlayer10;
extern bool PlayerSafe;
// #############################################################################  FUNCTION PROTOTYPES
void InitializeAPlayerId(std::vector<unsigned char> & PlayerID);
	void RemoveAPlayerId(std::vector<unsigned char> & PlayerID);
	bool IsThisPlayerFriendly(std::vector<unsigned char> & PlayerID);
	void RemoveAllPlayerId();
	void IsThisSafeToBot();
	int KeepOnWaitingSafety();
	void PlayerJustLeft();
	class Players
	{
	public:
		std::vector <unsigned char> m_Id;
		long long m_llId;
		long long m_llId2;
		long long m_llId3;
		long long m_llId4;
		long long m_llId5;
		int m_X;
		int m_Y;
		int m_Z;
		long long m_llDescriptor;
		bool m_LifeState;
		bool m_bSelected;
		static int s_nRegisteredPlayers;
		bool SelectMonsters(std::vector <unsigned char> &vectArg, int & nAnalyzedSize);
		bool m_bOrderedToFollow;
		Players() {

		}
		Players(std::vector <unsigned char> &vectArg, int &nAnalyzedSize, boost::shared_ptr < Players > & PlayerPtr) : m_LifeState(1), m_bOrderedToFollow(0)
		{
			uint16_t m_nSize = ((vectArg[nAnalyzedSize]) | (vectArg[nAnalyzedSize + 1] << 8));
			++s_nRegisteredPlayers;
			/*
			m_X = TurnVectInto32_int(vectArg, 26, nAnalyzedSize);
			m_Y = TurnVectInto32_int(vectArg, 30, nAnalyzedSize);
			m_Z = TurnVectInto32_int(vectArg, 34, nAnalyzedSize);
			*/
			std::vector <unsigned char > vplayerId = { 0x0b, 0x00, 0x00, 0x80, 0x00, 0x00 };
			std::vector <unsigned char> ::iterator it = std::search(vectArg.begin() + nAnalyzedSize, vectArg.begin() + nAnalyzedSize + m_nSize, vplayerId.begin(), vplayerId.end());
			if (it != (vectArg.begin() + nAnalyzedSize + m_nSize))
			{
				for (int uuu = 0; uuu < 8; ++uuu)
				{
					m_Id.push_back(*(it + uuu - 2));
				}
				memcpy(&m_llId, &m_Id[0], sizeof(m_llDescriptor));
				std::cout << "######################### REGISTERED ! #############################" << m_llId << std::endl;
			}
			//
			m_Id.clear();
			it = std::search(it+1, vectArg.begin() + nAnalyzedSize + m_nSize, vplayerId.begin(), vplayerId.end());
			if (it != (vectArg.begin() + nAnalyzedSize + m_nSize))
			{
				for (int uuu = 0; uuu < 8; ++uuu)
				{
					m_Id.push_back(*(it + uuu - 2));
				}
				memcpy(&m_llId2, &m_Id[0], sizeof(m_llDescriptor));
				std::cout << "######################### REGISTERED ! #############################" << m_llId2 << std::endl;
			}
			//
			m_Id.clear();
			it = std::search(it + 1, vectArg.begin() + nAnalyzedSize + m_nSize, vplayerId.begin(), vplayerId.end());
			if (it != (vectArg.begin() + nAnalyzedSize + m_nSize))
			{
				for (int uuu = 0; uuu < 8; ++uuu)
				{
					m_Id.push_back(*(it + uuu - 2));
				}
				memcpy(&m_llId3, &m_Id[0], sizeof(m_llDescriptor));
				std::cout << "######################### REGISTERED ! #############################" << m_llId3 << std::endl;
			}
			//
			m_Id.clear();
			it = std::search(it + 1, vectArg.begin() + nAnalyzedSize + m_nSize, vplayerId.begin(), vplayerId.end());
			if (it != (vectArg.begin() + nAnalyzedSize + m_nSize))
			{
				for (int uuu = 0; uuu < 8; ++uuu)
				{
					m_Id.push_back(*(it + uuu - 2));
				}
				memcpy(&m_llId4, &m_Id[0], sizeof(m_llDescriptor));
				std::cout << "######################### REGISTERED ! #############################" << m_llId4 << std::endl;
			}
			//			
			m_Id.clear();
			it = std::search(it + 1, vectArg.begin() + nAnalyzedSize + m_nSize, vplayerId.begin(), vplayerId.end());
			if (it != (vectArg.begin() + nAnalyzedSize + m_nSize))
			{
				for (int uuu = 0; uuu < 8; ++uuu)
				{
					m_Id.push_back(*(it + uuu - 2));
				}
				memcpy(&m_llId5, &m_Id[0], sizeof(m_llDescriptor));
				std::cout << "######################### REGISTERED ! #############################" << m_llId5 << std::endl;
			}

		}
		~Players() {
			--s_nRegisteredPlayers;
		}
		static void SaveNewPlayerPointer(boost::shared_ptr < Players > & PlayerPtrArg);
	};
	extern std::map < long long, boost::shared_ptr < Players>> PlayersMapSavedPointer;
#endif