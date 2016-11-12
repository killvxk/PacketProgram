#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

//====================================Function prototypes
void DecryptReceived_First_128_Bytes();
void DecryptReceived_Second_128_Bytes();
void Decryption_016B8070();
void CreateArchitectureKey_184_Bytes();
void Encryption_0170AE20();
void EncryptionCaller_016b8070(void * ptrPacketToSend, int sizeOfPacket); 
void DecryptionCaller_016b8070(void* ptrPacketToSend, int sizeOfPacket);
//====================================End
extern int chSecondSentKey;
extern void* ptrSecondSentKey;
extern char szFirstGeneratedKey_UnSent[128];
extern char szSecondGeneratedKey_Sent[128];
#endif
