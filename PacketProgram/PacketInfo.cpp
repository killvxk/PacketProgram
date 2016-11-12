/*

C_STORE_SELL_ADD_BASKET
{
uint16_t size;
uint16_t opcode;
uint32_t ID;
uint32_t ID;
uint32_t ID; untill here its session fix IDs
uint32_t ID; Item Id
uint32_t ID; amount of said items to be sold
uint32_t ID; Inventory space location
}
S_LOAD_TOPO (21)
{
[0]   	1500BBD5 6E1B0000 BA1B0A46 14800447	....n......F...G
[16]  	18371046 00				.7.F
}

S_LOAD_HINT (8)
{
[0]   	0800C787 00000000 			.......
}


S_VOTE_RESET_ALL_DUNGEON (5)
{
uint16_t size;
uint16_t opcode;
bool; 01 result vote is yes 00 otherwise
}


S_COMPLETE_VOTE (4)
{
uint16_t size;
uint16_t opcode;
}

S_SPAWN_NPC
{
Npc ID = byte 10 to 17
Npc skill ID = byte 38,39
}


C_START_SKILL
{
uint16_t size;
uint16_t opcode;
uint32_t skillID;
uint16_t cam;
uint32_t currentX;
uint32_t currentY;
uint32_t currentZ;
uint32_t destinationX;
uint32_t destinationY;
uint32_t destinationZ;
uint16_t; 0100
bool ; 00
uint64_t; 00s or the target ID if there is a target. (length = 8 bytes).

}

S_SPAWN_DROPITEM
{
uint16_t size;
uint16_t opcode;
uint32_t Seems static, unknown function;
uint32_t ItemID;    ID : 8 to 15
uint32_t ItemID;
float x;
float y;
float z;
uint16_t probably Item type (mwa, vmwa, armor..);
uint16_t ; 00 00
uint32_t ; amount of said item
bytes 36 to 47 = same numbers every time
}

S_DESPAWN_NPC (32)
{
uint16_t size;
uint16_t opcode;
uint32_t NpcID;
uint32_t NpcID;
float x;
float y;
float z;
..
}


S_SPAWN_ME
/*
struct
{
uint16_t size;
uint16_t opcode;
uint32_t ??
uint32_t ??
float x;
float y;
float z;
uint16_t X camera angle;
uint16_t 0100
}


struct C_PLAYER_LOCATION
{
uint16_t size; 43
uint16_t opcode; 
float x; depart
float y;
float z;
uint32_t X camera angle;
float x; arrivée
float y;
float z;
uint32_t packet type (from 00 .. to 07...)
uint24_t only 0s
uint32_t (float?) total ran distance / connection timestamp ?
} 


C_NOTIFY_LOCATION_IN_ACTION
{

uint16_t size; 26
uint16_t opcode;
uint32_t skillId;
uint32_t 01000000;
float x; arrivée
float y;
float z;
uint16_t camAngle;

}

C_TRY_LOOT_DROPITEM
{
uint16_t size; (12)
uint16_t opcode;
uint64_t ID;
}










*/

