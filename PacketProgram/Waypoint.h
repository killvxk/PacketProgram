#ifndef WAYPOINT_H
#define WAYPOINT_H
#include <vector>
std::vector<unsigned char> ForMovementPacket(int nWantedX, int nWantedY, int nWantedZ);
void TurnInt32_tIntoVect(int &int32_t, std::vector<unsigned char> &vectArg);
void Turnuint16_t_tIntoVect(int &uint16_t, std::vector<unsigned char> &vectArg);
int TurnVectInto32_int(std::vector<unsigned char> &vectArgument, int StartCount, int &nAnalyzedSize);
void TurnInt32_tIntoVect_rvalue(int int32_t, std::vector<unsigned char> &vectArg);
void Turnuint16_t_tIntoVect_rvalue(int uint16_t, std::vector<unsigned char> &vectArg);
void GoToTheseCoordonateAtThisSpeedUndetected(int nSleepTime, int wantedXForEaxKnFeetInt, int wantedYForEaxKnFeetInt, int wantedZForEaxKnFeetInt, int nHideZ, boost::asio::ip::tcp::socket & socket);
std::vector<unsigned char> TurnInt32_tIntoVect2(int &int32_t);
long long TurnVecInto64_int(std::vector<unsigned char> &vectArgument, int StartCount, int &nAnalyzedSize);
int ReturnCamAngleInt(int nWantedX, int nWantedY, int nWantedZ);
std::vector <unsigned char> FormNotifyActionLocationPacket(int nWantedX, int nWantedY, int nWantedZ);
std::vector<unsigned char> FormSkillDestinationCoordonates(int nWantedX, int nWantedY, int nWantedZ);
void GoToTheseCoordonateAtThisSpeed(int nSleepTime, int wantedXForEaxKnFeetInt, int wantedYForEaxKnFeetInt, int wantedZForEaxKnFeetInt, boost::asio::ip::tcp::socket & socket);
extern std::vector <unsigned char> vLocationAction;
extern std::vector<unsigned char> MovementPacket;
extern std::vector<unsigned char> MovementPacket2;
extern int nAfterTheMove;
extern int currentX;
extern int currentY;
extern int currentZ;
extern int wantedXForKnStairs;
extern int wantedYForKnStairs;
extern int wantedZForKnStairs;
extern int wantedXForEaxKnFeetInt;
extern int wantedYForEaxKnFeetInt;
extern int wantedZForEaxKnFeetInt;
extern int wantedXForEaxKnSideFeetInt;
extern int wantedYForEaxKnSideFeetInt;
extern int wantedZForEaxKnSideFeetInt;
extern int wantedXForEaxKnInvincibleFeetInt;
extern int wantedYForEaxKnInvincibleFeetInt;
extern int wantedZForEaxKnInvincibleFeetInt;
extern int wantedXEnterKnDungeon;
extern int wantedYEnterKnDungeon;
extern int wantedZEnterKnDungeon;
extern int InterractSellNpcKnX;
extern int InterractSellNpcKnY;
extern int InterractSellNpcKnZ;
extern int KnEntranceInsideDungeonX;
extern int KnEntranceInsideDungeonY;
extern int KnEntranceInsideDungeonZ;
extern int nCentralPowerLevelX;
extern int nCentralPowerLevelY;
extern int nCentralPowerLevelZ;
#endif