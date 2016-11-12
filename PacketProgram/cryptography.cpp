#include <iostream>
#include "PacketProgramBoost.h"
#include "ConfigFile.h"
int chSecondSentKey(0);
void * ptrSecondSentKey = &chSecondSentKey;
int stackholder(0);
int nComparisonHolder(0);
int n021650FC(0x7e40d858);
void f_TERA_01739C30();
void f_TERA_01754B40();
void f_TERA_017541E0();
void f_TERA_01758630();
void f_memset();
void f_memcpy();
void test();
void f_TERA_01744DB0();
void Decryption_016b8070();
/*
//
hiro :
jmp hiro
//
*/
void AsmInsertionPrologue()
{
	_asm
	{
			push eax
			push ebx
			push ecx
			push edx
			push esi
			push edi
			push ebp
			push esp
	}
}
void AsmInsertionEpilogue()
{
	_asm
	{
			pop esp
			pop ebp
			pop edi
			pop esi
			pop edx
			pop ecx
			pop ebx
			pop eax
	}
}
void CreateArchitectureKey_184_Bytes()
{
	_asm
	{
		push ebp
			mov stackholder, esp
			sub esp, 220
			mov edi, ecx
			mov edi, ptrArchitectureKey // patched by glenn
		starting_point :
			push 0x000000DC
			mov[edi], 0x00000000
			mov[edi + 0x04], 0x00000000
			mov[edi + 0x08], 0x00000037
			mov[edi + 0x10], 0x0000001F
			mov[edi + 0x14], 0x0000001F
			//call esi  -- > calls allocator function
			mov eax, ptrKeyEncryption_1
			mov[edi + 0x1C], eax
			mov[edi + 0x20], 0x00000000
			mov[edi + 0x18], 0x00000000
			mov[edi + 0x0C], 0x00000000
			push 0x000000E4
			mov[edi + 0x24], 0x00000039
			mov[edi + 0x2C], 0x00000032
			mov[edi + 0x30], 0x00000032
			//call esi  -- > calls allocator function
			mov eax, ptrKeyEncryption_2
			mov[edi + 0x38], eax
			mov[edi + 0x3C], 00000000
			mov[edi + 0x34], 00000000
			mov[edi + 0x28], 00000000
			push 0x000000E8
			mov[edi + 0x40], 0x0000003A
			mov[edi + 0x48], 0x00000027
			mov[edi + 0x4C], 0x00000027
			//call esi  -- > calls allocator function
			add esp, 0x0C //adds the esp substracted by the pushes before allocating (call esi)
			mov eax, ptrKeyEncryption_3
			mov[edi + 0x54], eax
			mov[edi + 0x58], 00000000
			mov eax, edi
			mov[edi + 0x50], 00000000
			mov[edi + 0x44], 00000000
			//pop edi removed its push therefore removed its pop
			push eax
			mov eax, nComparisonHolder
			test eax,eax
			pushfd
			add nComparisonHolder, 0x01
			popfd
			pop eax
			jne skip_Comparison
			push eax
			mov eax, ptrKeyDecryption_1
			mov ptrKeyEncryption_1,eax
			mov eax, ptrKeyDecryption_2
			mov ptrKeyEncryption_2, eax
			mov eax, ptrKeyDecryption_3
			mov ptrKeyEncryption_3, eax
			pop eax
			lea edi,[edi + 0x5C] //patched by glenn
			je starting_point
		skip_Comparison:
			mov nComparisonHolder, 0
			mov esp, stackholder
			pop ebp
	}
}
void DecryptReceived_First_128_Bytes()
{
	_asm
	{
		//call AsmInsertionPrologue
			//eax doesn't matter however it's 80
			//ebx doesn't matter (gets xored)
			//ecx doesn't matter
			//edx is 80
			//esi is buffer address minus 10
			//edi is buffer address
			push ebp
			mov stackholder,esp
			sub esp,120
			mov eax, 0x80
			mov edx, 0x80
			mov edi,ptrReceivedFirstKey
			lea esi, [edi-0x10]
			mov ecx, 0x0000FFFF
			//following 3 code lines are a tweak
			mov ebx, ptrRandomedFirstKey
			sub ebx, 0x0c
			mov[esi + 0x0002001C], ebx
			xor ebx, ebx
			//sub ecx, [esi + 0x00010010] substracts 0 therefore removed
			cmp ecx, edx
			sete bl
			//removed opcodes because untaken road / code (1)
			//mov ecx, [edi + 0x00010000] // moves 0 into ecx (666) so i replaced it by xor ecx ecx
			xor ecx,ecx
			mov eax, 0x0000FFFF
			sub eax, ecx
			//(1)
			lea eax, [ecx + edx] // puts 80 in eax
			/*
		hiro :
				mov ebx, [edi]
					jmp hiro
					*/
			mov[edi + 0x00010000], eax // moves 80 there
			mov eax, [esi] //puts info in eax usefull for function call // we dont care about this
			mov ecx, esi
			push edx // key length
			//push[ebp - 04](666)
			push edi //key buffer
			//call function
			push ebp
			mov ebp, esp
			push ebx //0
			push esi
			mov esi, ecx
			push edi
			mov ecx, [esi + 0x0002001C] //puts buffer to randomed keys in ecx
			test ecx, ecx
			// conditional jump taken (removed) code (2)
			mov eax, [ecx]
			//mov eax, [eax + 0x18]
			//call eax donc les deux instructions précedentes sont inutiles, la seconde pose des problemes et est suppr.
			xor eax, eax
			cmp dword ptr[ecx + 0x08], 04
			sete al
			//Ret
			mov ecx, [esi + 0x0002001C] //met dans ecx l'adress du buffer des clefs randomisé, mais il les contient déjà
			test al, al
			mov eax, [ecx]//donne à eax une valeur à call
			//(2) taken
			lea ebx, [esi + 0x10] // ici ebx doit être égal à edi
			//call dword ptr[eax + 1C]
			mov eax, 0x00000080
			//ret
			mov ecx, ebx // inutile car ecx == ebx
			mov edi, eax
			//call 011B0440
			mov eax, [ecx + 0x00010000]
			//ret
			cmp eax, edi
			//(2)
			mov eax, [esi + 0x0002001C]// le buffer de la clef randomisé est dans ecx
			mov ecx, ebx
			mov edi, [eax] // mets dans edi une valeur pour function call un peu plus tard
			//call 011B0220
			mov eax, ecx
			//ret
			mov ecx, [esi + 0x0002001C] // le buffer de la clef randomisé est dans ecx
			push eax // the reception buffer is pushed
			//the function mother_1 within which the decryption is done gets called here
			//call dword ptr [edi+08]
			push ebp
			mov ebp, esp
			mov [ecx + 0x08],0x02 // patched by glenn
			mov eax, [ecx + 0x08] // this moves 02 into eax, this is the most important likeliness problem source atm
			dec eax
			//(2)
			dec eax
			//(2) taken
			pop ebp
			//(2) taken
			push ebp
			mov ebp, esp
			sub esp, 0x0000008C // ##################################### the works begins here
			mov eax, [0x020E402C] //warning   this moved 1290D0CF into eax
			xor eax, ebp // ebp == 00384664
			mov[ebp - 0x04], eax // gets stored in the stack
			mov eax, ecx
			push ebx
			mov ebx, [ebp + 0x08] // useless, ebx already holds this value (packet data received buffer)
			push esi
			mov [eax + 04],0x01
			cmp dword ptr[eax + 04], 0x01 // this sets zero flag on
			push edi
			mov[ebp - 0x00000088], eax//puts randomed key buffer in stack
			mov[ebp - 0x0000008C], ebx//puts received key buffer in stack
			//(2) untaken
			mov edx, 0x00000043
			xor esi, esi
		loop1://code gets inverted here for the first time
		cmp edx, 0x00000080
			jnge route1
			add edx, -0x80
		route1:
			  mov al, [ebx + esi]
			  inc esi
			  mov[ebp + edx - 0x00000084], al
			  inc edx
			  cmp esi, 0x00000080
			  jnge loop1
			  mov ecx, 0x00000020
			  lea esi, [ebp - 0x00000084]
			  mov edi, ebx
			  repe movsd //## This will copy the inverted key back to original buffer
			  mov esi, [ebp - 0x00000088]
			  lea eax, [esi + 0x0000008C]
			  mov eax, ptrRandomedSecondKey // patched by glenn
			  push eax
			  push ebx
			  //call 016D3FD0 This does the first decryption // eax holds the former key location and ebx holds the current key buffer (after repe movsd)
			 //both decryptions call this exact same function, the calls are made in 016B8864 and 016B886E respectively.
			 //here eax needs to have the second randomed key !
			 sub esp,0x04
			  push ebp // ici nous somme dans un function call non refait, donc on doit placer un sub esp,04 au début et un add esp 04 fin.
			  mov ebp, esp
			  mov ecx, [ebp + 0x08]
			  push esi
			  mov esi, [ebp + 0x0C]
			  push edi
			  lea eax, [ecx + 0x04]
			  mov edi, 0x00000008
			  lea edx, [esi + 0x0C]
			  sub esi, ecx
			  //(2) taken
		  loop2:
			  mov ecx, [edx - 0x0C]
			  lea eax, [eax + 0x10]
			  xor[eax - 0x14], ecx
			  lea edx, [edx + 0x10]
			  mov ecx, [esi + eax - 0x10]
			  xor[eax - 0x10], ecx
			  mov ecx, [edx - 0x14]
			  xor[eax - 0x0C], ecx
			  mov ecx, [edx - 0x10]
			  xor[eax - 0x08], ecx
			  dec edi
			  jne loop2
			  pop edi
			  pop esi
			  pop ebp
			  add esp,0x04
			  //ret // =========================================== ici seule edx est une valeur suspecte
			  lea eax, [esi + 0x0C]
			  push eax
			  push ebx
			  //call 016D3FD0 this does the second decryption // eax holds the former key location and ebx holds the current received key buffer.
			  sub esp,0x04 // patched by glenn
			  push ebp
			  mov ebp, esp
			  mov ecx, [ebp + 0x08]
			  push esi
			  mov esi, [ebp + 0x0C]
			  push edi
			  lea eax, [ecx + 0x04]
			  mov edi, 0x00000008
			  lea edx, [esi + 0x0C]
			  sub esi, ecx
			  //(1)
		  loop3:
			  mov ecx, [edx - 0x0C]
			  lea eax, [eax + 0x10]
			  xor[eax - 0x14], ecx
			  lea edx, [edx + 0x10]
			  mov ecx, [esi + eax - 0x10]
			  xor[eax - 0x10], ecx
			  mov ecx, [edx - 0x14]
			  xor[eax - 0x0C], ecx
			  mov ecx, [edx - 0x10]
			  xor[eax - 0x08], ecx
			  dec edi
			  jne loop3
			  pop edi
			  pop esi
			  pop ebp
			  add esp,0x04
			  //ret
			  add esp, 0x10
			  mov edx, 0x0000001D
			  xor esi, esi
			  lea ecx, [ecx + 0x00]
		  loop4: // code gets inverted here for the second time
			  cmp edx, 0x00000080
			  jnge route2
			  add edx, -0x80
		  route2:
				mov al, [ebx + esi]
				inc esi
				mov[ebp + edx - 0x00000084], al
				inc edx
				cmp esi, 0x00000080
				jnge loop4
				mov edi, ebx
				lea esi, [ebp - 0x00000084]
				mov ebx, [ebp - 0x00000088]
				mov ecx, 0x00000020
				mov ptrSecondSentKey, edi
				repe movsd //## This will copy the inverted key back to original buffer
				mov[ebx + 0x08], 0x00000003
				//(2) taken
				mov ecx, [ebp - 0x04]
				mov al, 0x01
				pop edi
				pop esi
				xor ecx, ebp
				pop ebx
				//call 01895B04
				//cmp ecx, [020E402C]
				//jne skip1
			  //(2) untaken
				//ret
				mov esp, ebp
				pop ebp
				//ret 0004 function mother_1 ends here.
				//call AsmInsertionEpilogue
				mov esp, stackholder
				pop ebp
	}
}

__declspec (naked) void Encryption_0170AE20()
{
	_asm
	{

	TERA_0170AD90:

		PUSH EBP
			MOV EBP, ESP
			SUB ESP, 0x28
			MOV EAX, DWORD PTR DS : [ECX + 0x4]
			mov edx, [ebp + 0x0C]
			PUSH EBX
			PUSH ESI
			PUSH EDI
			LEA EDI, DWORD PTR DS : [ECX + 0x4]
			mov[ebp - 0x24], edi
			TEST EAX, EAX
			JE TERA_0170ADE1
			MOV ESI, ECX
			MOV EBX, EDX
			SUB ESI, EAX
			ADD ESI, 0x4
			CMP EDX, EAX
			CMOVG EBX, EAX
			TEST EBX, EBX
			JLE TERA_0170ADD4
			MOV EDX, [ebp + 0x08]
			MOV EDI, EBX
			SUB ESI, EDX

		TERA_0170ADC2 :

		MOV AL, BYTE PTR DS : [ESI + EDX]
			XOR BYTE PTR DS : [EDX], AL
			INC EDX
			DEC EDI
			JNZ TERA_0170ADC2
			mov edi, [ebp - 0x24]
			mov[ebp + 0x08], edx
			mov edx, [ebp + 0x0C]

		TERA_0170ADD4:

			SUB DWORD PTR DS : [EDI], EBX
				JNZ TERA_0170B0AD
				SUB EDX, EBX
				mov[ebp + 0x0C], edx

			TERA_0170ADE1 :

			MOV EAX, DWORD PTR DS : [ECX + 0x020]
				MOV ESI, DWORD PTR DS : [ECX + 0x018]
				MOV EBX, DWORD PTR DS : [ECX + 0x034]
				MOV EDI, DWORD PTR DS : [ECX + 0x050]
				mov[ebp - 0x14], eax
				MOV EAX, DWORD PTR DS : [ECX + 0x03C]
				mov[ebp - 0x10], eax
				MOV EAX, DWORD PTR DS : [ECX + 0x058]
				SHR EDX, 0x2
				mov[ebp - 0x0C], eax
				XOR EAX, EAX
				mov[ebp - 0x28], edx
				mov[ebp - 0x1C], esi
				mov[ebp - 0x04], ebx
				mov[ebp - 0x08], edi
				mov[ebp - 0x18], eax
				TEST EDX, EDX
				JLE TERA_0170AF72

			TERA_0170AE18 :

			MOV EDX, EBX
				MOV EAX, EBX
				OR EDX, ESI
				AND EAX, ESI
				AND EDX, EDI
				OR EDX, EAX
				mov[ebp - 0x20], edx
				CMP ESI, EDX
				JNZ TERA_0170AE8C
				MOV ESI, DWORD PTR DS : [ECX + 0x010]
				MOV EAX, DWORD PTR DS : [ECX + 0x01C]
				MOV EDX, DWORD PTR DS : [ECX + 0x0C]
				MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
				INC ESI
				MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
				INC EDX
				CMP EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x010], ESI
				MOV DWORD PTR DS : [ECX + 0x0C], EDX
				LEA EAX, DWORD PTR DS : [EDI + EBX]
				CMOVA EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x020], EAX
				mov[ebp - 0x14], eax
				CMP EDI, EAX
				JBE TERA_0170AE5D
				MOV DWORD PTR DS : [ECX + 0x018], 0x1
				JMP TERA_0170AE64

			TERA_0170AE5D :

			MOV DWORD PTR DS : [ECX + 0x018], 0x0

			TERA_0170AE64 :

						  MOV EAX, DWORD PTR DS : [ECX + 0x8]
						  CMP EDX, EAX
						  JNZ TERA_0170AE72
						  MOV DWORD PTR DS : [ECX + 0x0C], 0x0

					  TERA_0170AE72 :

									CMP ESI, EAX
									JNZ TERA_0170AE7D
									MOV DWORD PTR DS : [ECX + 0x010], 0x0

								TERA_0170AE7D :

											  MOV EAX, DWORD PTR DS : [ECX + 0x018]
											  mov edx, [ebp - 0x20]
											  mov ebx, [ebp - 0x04]
											  mov edi, [ebp - 0x08]
											  mov[ebp - 0x1C], eax

										  TERA_0170AE8C :

			CMP EBX, EDX
				JNZ TERA_0170AEEE
				MOV ESI, DWORD PTR DS : [ECX + 0x02C]
				MOV EAX, DWORD PTR DS : [ECX + 0x038]
				MOV EDX, DWORD PTR DS : [ECX + 0x028]
				MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
				INC ESI
				MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
				INC EDX
				CMP EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x02C], ESI
				MOV DWORD PTR DS : [ECX + 0x028], EDX
				LEA EAX, DWORD PTR DS : [EDI + EBX]
				CMOVA EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x03C], EAX
				mov[ebp - 0x10], eax
				CMP EDI, EAX
				JBE TERA_0170AEC2
				MOV DWORD PTR DS : [ECX + 0x034], 0x1
				JMP TERA_0170AEC9

			TERA_0170AEC2 :

			MOV DWORD PTR DS : [ECX + 0x034], 0x0

			TERA_0170AEC9 :

						  MOV EAX, DWORD PTR DS : [ECX + 0x024]
						  CMP EDX, EAX
						  JNZ TERA_0170AED7
						  MOV DWORD PTR DS : [ECX + 0x028], 0x0

					  TERA_0170AED7 :

									CMP ESI, EAX
									JNZ TERA_0170AEE2
									MOV DWORD PTR DS : [ECX + 0x02C], 0x0

								TERA_0170AEE2 :

											  MOV EAX, DWORD PTR DS : [ECX + 0x034]
											  mov edx, [ebp - 0x20]
											  mov edi, [ebp - 0x08]
											  mov[ebp - 0x04], eax

										  TERA_0170AEEE :

			CMP EDI, EDX
				JNZ TERA_0170AF4A
				MOV ESI, DWORD PTR DS : [ECX + 0x048]
				MOV EAX, DWORD PTR DS : [ECX + 0x054]
				MOV EDX, DWORD PTR DS : [ECX + 0x044]
				MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
				INC ESI
				MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
				INC EDX
				CMP EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x048], ESI
				MOV DWORD PTR DS : [ECX + 0x044], EDX
				LEA EAX, DWORD PTR DS : [EDI + EBX]
				CMOVA EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x058], EAX
				mov[ebp - 0x0C], eax
				CMP EDI, EAX
				JBE TERA_0170AF24
				MOV DWORD PTR DS : [ECX + 0x050], 0x1
				JMP TERA_0170AF2B

			TERA_0170AF24 :

			MOV DWORD PTR DS : [ECX + 0x050], 0x0

			TERA_0170AF2B :

						  MOV EAX, DWORD PTR DS : [ECX + 0x040]
						  CMP EDX, EAX
						  JNZ TERA_0170AF39
						  MOV DWORD PTR DS : [ECX + 0x044], 0x0

					  TERA_0170AF39 :

									CMP ESI, EAX
									JNZ TERA_0170AF44
									MOV DWORD PTR DS : [ECX + 0x048], 0x0

								TERA_0170AF44 :

											  MOV EDI, DWORD PTR DS : [ECX + 0x050]
											  mov[ebp - 0x08], edi

										  TERA_0170AF4A :

			mov ebx, [ebp - 0x18]
				mov edx, [ebp + 0x08]
				mov esi, [ebp - 0x1C]
				MOV EAX, DWORD PTR DS : [EDX + EBX * 4]
				xor eax, [ebp - 0x0C]
				xor eax, [ebp - 0x10]
				xor eax, [ebp - 0x14]
				MOV DWORD PTR DS : [EDX + EBX * 4], EAX
				INC EBX
				cmp ebx, [ebp - 0x28]
				mov[ebp - 0x18], ebx
				mov ebx, [ebp - 0x04]
				JL TERA_0170AE18

			TERA_0170AF72 :

			and dword ptr[ebp + 0x0C], 0x03
				JE TERA_0170B0AD
				MOV EDX, EBX
				MOV EAX, EBX
				OR EDX, ESI
				AND EAX, ESI
				AND EDX, EDI
				OR EDX, EAX
				mov[ebp - 0x20], edx
				CMP ESI, EDX
				JNZ TERA_0170AFDC
				MOV ESI, DWORD PTR DS : [ECX + 0x010]
				MOV EAX, DWORD PTR DS : [ECX + 0x01C]
				MOV EDX, DWORD PTR DS : [ECX + 0x0C]
				MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
				INC ESI
				MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
				INC EDX
				CMP EDI, EBX
				MOV DWORD PTR DS : [ECX + 0x010], ESI
				MOV DWORD PTR DS : [ECX + 0x0C], EDX
				LEA EAX, DWORD PTR DS : [EDI + EBX]
				CMOVA EDI, EBX
				CMP EAX, EDI
				MOV DWORD PTR DS : [ECX + 0x020], EAX
				mov[ebp - 0x14], eax
				SBB EAX, EAX
				NEG EAX
				MOV DWORD PTR DS : [ECX + 0x018], EAX
				MOV EAX, DWORD PTR DS : [ECX + 0x8]
				CMP EDX, EAX
				JNZ TERA_0170AFCB
				MOV DWORD PTR DS : [ECX + 0x0C], 0x0

			TERA_0170AFCB :

						  CMP ESI, EAX
						  JNZ TERA_0170AFD6
						  MOV DWORD PTR DS : [ECX + 0x010], 0x0

					  TERA_0170AFD6 :

									mov edx, [ebp - 0x20]
									mov ebx, [ebp - 0x04]

								TERA_0170AFDC :

											  CMP EBX, EDX
											  JNZ TERA_0170B02A
											  MOV ESI, DWORD PTR DS : [ECX + 0x02C]
											  MOV EAX, DWORD PTR DS : [ECX + 0x038]
											  MOV EDX, DWORD PTR DS : [ECX + 0x028]
											  MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
											  INC ESI
											  MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
											  INC EDX
											  CMP EDI, EBX
											  MOV DWORD PTR DS : [ECX + 0x02C], ESI
											  MOV DWORD PTR DS : [ECX + 0x028], EDX
											  LEA EAX, DWORD PTR DS : [EDI + EBX]
											  CMOVA EDI, EBX
											  CMP EAX, EDI
											  MOV DWORD PTR DS : [ECX + 0x03C], EAX
											  mov[ebp - 0x10], eax
											  SBB EAX, EAX
											  NEG EAX
											  MOV DWORD PTR DS : [ECX + 0x034], EAX
											  MOV EAX, DWORD PTR DS : [ECX + 0x024]
											  CMP EDX, EAX
											  JNZ TERA_0170B01C
											  MOV DWORD PTR DS : [ECX + 0x028], 0x0

										  TERA_0170B01C :

														CMP ESI, EAX
														JNZ TERA_0170B027
														MOV DWORD PTR DS : [ECX + 0x02C], 0x0

													TERA_0170B027 :

																  mov edx, [ebp - 0x20]

															  TERA_0170B02A :

																			cmp[ebp - 0x08], edx
																			JNZ TERA_0170B076
																			MOV ESI, DWORD PTR DS : [ECX + 0x048]
																			MOV EAX, DWORD PTR DS : [ECX + 0x054]
																			MOV EDX, DWORD PTR DS : [ECX + 0x044]
																			MOV EBX, DWORD PTR DS : [EAX + ESI * 4]
																			INC ESI
																			MOV EDI, DWORD PTR DS : [EAX + EDX * 4]
																			INC EDX
																			CMP EDI, EBX
																			MOV DWORD PTR DS : [ECX + 0x048], ESI
																			MOV DWORD PTR DS : [ECX + 0x044], EDX
																			LEA EAX, DWORD PTR DS : [EDI + EBX]
																			CMOVA EDI, EBX
																			CMP EAX, EDI
																			MOV DWORD PTR DS : [ECX + 0x058], EAX
																			mov[ebp - 0x0C], eax
																			SBB EAX, EAX
																			NEG EAX
																			MOV DWORD PTR DS : [ECX + 0x050], EAX
																			MOV EAX, DWORD PTR DS : [ECX + 0x040]
																			CMP EDX, EAX
																			JNZ TERA_0170B06B
																			MOV DWORD PTR DS : [ECX + 0x044], 0x0

																		TERA_0170B06B :

																					  CMP ESI, EAX
																					  JNZ TERA_0170B076
																					  MOV DWORD PTR DS : [ECX + 0x048], 0x0

																				  TERA_0170B076 :

																								mov eax, [ebp - 0x0C]
																								xor eax, [ebp - 0x10]
																								xor eax, [ebp - 0x14]
																								mov ebx, [ebp + 0x0C]
																								MOV DWORD PTR DS : [ECX], EAX
																								TEST EBX, EBX
																								JLE TERA_0170B0A1
																								mov esi, [ebp - 0x18]
																								mov eax, [ebp + 0x08]
																								LEA EDX, DWORD PTR DS : [EAX + ESI * 4]
																								MOV ESI, EBX
																								SUB ECX, EDX

																							TERA_0170B095 :

			MOV AL, BYTE PTR DS : [ECX + EDX]
				LEA EDX, DWORD PTR DS : [EDX + 0x1]
				XOR BYTE PTR DS : [EDX - 0x1], AL
				DEC ESI
				JNZ TERA_0170B095

			TERA_0170B0A1 :

			mov ecx, [ebp - 0x24]
				MOV EAX, 0x4
				SUB EAX, EBX
				MOV DWORD PTR DS : [ECX], EAX

			TERA_0170B0AD :

			POP EDI
				POP ESI
				POP EBX
				MOV ESP, EBP
				POP EBP
				RETN 0x8
	}
}
__declspec (naked) void Encryption_0170AE202()
{
	_asm
	{
push ebp
mov ebp, esp
sub esp, 0x28
mov eax, [ecx + 0x04]
mov edx, [ebp + 0x0C]
push ebx
push esi
push edi
lea edi, [ecx + 0x04]
mov[ebp - 0x24], edi
test eax, eax
je encrypt_jump_1
mov esi, ecx
mov ebx, edx
sub esi, eax
add esi, 0x04
cmp edx, eax
cmovg ebx, eax
test ebx, ebx
jle encrypt_jump_2
mov edx, [ebp + 0x08]
mov edi, ebx
sub esi, edx
		encrypt_jump_3:
		mov al, [esi + edx]
xor[edx], al
inc edx
dec edi
jne encrypt_jump_3
mov edi, [ebp - 0x24]
mov[ebp + 0x08], edx
mov edx, [ebp + 0x0C]
		encrypt_jump_2:
			sub[edi], ebx
jne encrypt_jump_4
sub edx, ebx
mov[ebp + 0x0C], edx
		encrypt_jump_1:
		mov eax, [ecx + 0x20]
mov esi, [ecx + 0x18]
mov ebx, [ecx + 0x34]
mov edi, [ecx + 0x50]
mov[ebp - 0x14], eax
mov eax, [ecx + 0x3C]
mov[ebp - 0x10], eax
mov eax, [ecx + 0x58]
shr edx, 0x02
mov[ebp - 0x0C], eax
xor eax, eax
mov[ebp - 0x28], edx
mov[ebp - 0x1C], esi
mov[ebp - 0x04], ebx
mov[ebp - 0x08], edi
mov[ebp - 0x18], eax
test edx, edx
jng encrypt_jump_5
		encrypt_jump_20:
		mov edx, ebx
mov eax, ebx
or edx, esi
and eax, esi
and edx, edi
or edx, eax
mov[ebp - 0x20], edx
cmp esi, edx
jne encrypt_jump_6
mov esi, [ecx + 0x10]
mov eax, [ecx + 0x1C]
mov edx, [ecx + 0x0C]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x10], esi
mov[ecx + 0x0C], edx
lea eax, [edi + ebx]
cmova edi, ebx
mov[ecx + 0x20], eax
mov[ebp - 0x14], eax
cmp edi, eax
jna encrypt_jump_7
mov dword ptr [ecx + 0x18], 0x00000001
jmp encrypt_jump_forgotten_1
		encrypt_jump_7:
		mov dword ptr[ecx + 0x18], 0x00000000
		encrypt_jump_forgotten_1:
		mov eax, [ecx + 0x08]
cmp edx, eax
jne encrypt_jump_8
mov dword ptr[ecx + 0x0C], 0x00000000
		encrypt_jump_8:
		cmp esi, eax
jne encrypt_jump_9
mov dword ptr[ecx + 0x10], 0x00000000
		encrypt_jump_9:
					  mov eax, [ecx + 0x18]
mov edx, [ebp - 0x20]
mov ebx, [ebp - 0x04]
mov edi, [ebp - 0x08]
mov[ebp - 0x1C], eax
		encrypt_jump_6:
		cmp ebx, edx
jne encrypt_jump_10
mov esi, [ecx + 0x2C]
mov eax, [ecx + 0x38]
mov edx, [ecx + 0x28]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x2C], esi
mov[ecx + 0x28], edx
lea eax, [edi + ebx]
cmova edi, ebx
mov[ecx + 0x3C], eax
mov[ebp - 0x10], eax
cmp edi, eax
jna encrypt_jump_11
mov dword ptr[ecx + 0x34], 0x00000001
jmp encrypt_jump_12
		encrypt_jump_11:
		mov dword ptr[ecx + 0x34], 0x00000000
		encrypt_jump_12:
					   mov eax, [ecx + 0x24]
cmp edx, eax
jne encrypt_jump_13
mov dword ptr [ecx + 0x28], 0x00000000
		encrypt_jump_13:
					   cmp esi, eax
jne encrypt_jump_14
mov dword ptr [ecx + 0x2C], 0x00000000
		encrypt_jump_14:
					   mov eax, [ecx + 0x34]
mov edx, [ebp - 0x20]
mov edi, [ebp - 0x08]
mov[ebp - 0x04], eax
		encrypt_jump_10:
		cmp edi, edx
jne encrypt_jump_15
mov esi, [ecx + 0x48]
mov eax, [ecx + 0x54]
mov edx, [ecx + 0x44]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x48], esi
mov[ecx + 0x44], edx
lea eax, [edi + ebx]
cmova edi, ebx
mov[ecx + 0x58], eax
mov[ebp - 0x0C], eax
cmp edi, eax
jna encrypt_jump_16
mov dword ptr[ecx + 0x50], 0x00000001
jmp encrypt_jump_17
		encrypt_jump_16:
		mov dword ptr[ecx + 0x50], 0x00000000
		encrypt_jump_17:
					   mov eax, [ecx + 0x40]
cmp edx, eax
jne encrypt_jump_18
mov dword ptr[ecx + 0x44], 0x00000000
		encrypt_jump_18:
					   cmp esi, eax
jne encrypt_jump_19
mov dword ptr[ecx + 0x48], 0x00000000
		encrypt_jump_19:
					   mov edi, [ecx + 0x50]
mov[ebp - 0x08], edi
		encrypt_jump_15:
		mov ebx, [ebp - 0x18]
mov edx, [ebp + 0x08]
mov esi, [ebp - 0x1C]
mov eax, [edx + ebx * 0x04]
xor eax, [ebp - 0x0C]
xor eax, [ebp - 0x10]
xor eax, [ebp - 0x14]
mov[edx + ebx * 4], eax
inc ebx
cmp ebx, [ebp - 0x28]
mov[ebp - 0x18], ebx
mov ebx, [ebp - 0x04]
jl encrypt_jump_20
		encrypt_jump_5:
			and dword ptr[ebp + 0x0C], 0x03
je encrypt_jump_4
mov edx, ebx
mov eax, ebx
or edx, esi
and eax, esi
and edx, edi
or edx, eax
mov[ebp - 0x20], edx
cmp esi, edx
jne encrypt_jump_21
mov esi, [ecx + 0x10]
mov eax, [ecx + 0x1C]
mov edx, [ecx + 0x0C]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x10], esi
mov[ecx + 0x0C], edx
lea eax, [edi + ebx]
cmova edi, ebx
cmp eax, edi
mov[ecx + 0x20], eax
mov[ebp - 0x14], eax
sbb eax, eax
neg eax
mov[ecx + 0x18], eax
mov eax, [ecx + 0x08]
cmp edx, eax
jne encrypt_jump_22
mov dword ptr[ecx + 0x0C], 0x00000000
		encrypt_jump_22:
			cmp esi, eax
jne encrypt_jump_23
mov dword ptr[ecx + 0x10], 0x00000000
		encrypt_jump_23:
					   mov edx, [ebp - 0x20]
mov ebx, [ebp - 0x04]
		encrypt_jump_21:
				cmp ebx, edx
jne encrypt_jump_24
mov esi, [ecx + 0x2C]
mov eax, [ecx + 0x38]
mov edx, [ecx + 0x28]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x2C], esi
mov[ecx + 0x28], edx
lea eax, [edi + ebx]
cmova edi, ebx
cmp eax, edi
mov[ecx + 0x3C], eax
mov[ebp - 0x10], eax
sbb eax, eax
neg eax
mov[ecx + 0x34], eax
mov eax, [ecx + 0x24]
cmp edx, eax
jne encrypt_jump_25
mov dword ptr[ecx + 0x28], 0x00000000
		encrypt_jump_25:
			cmp esi, eax
jne encrypt_jump_26
mov dword ptr[ecx + 0x2C], 0x00000000
		encrypt_jump_26:
					   mov edx, [ebp - 0x20]
		encrypt_jump_24:
				cmp[ebp - 0x08], edx
jne encrypt_jump_27
mov esi, [ecx + 0x48]
mov eax, [ecx + 0x54]
mov edx, [ecx + 0x44]
mov ebx, [eax + esi * 0x04]
inc esi
mov edi, [eax + edx * 0x04]
inc edx
cmp edi, ebx
mov[ecx + 0x48], esi
mov[ecx + 0x44], edx
lea eax, [edi + ebx]
cmova edi, ebx
cmp eax, edi
mov[ecx + 0x58], eax
mov[ebp - 0x0C], eax
sbb eax, eax
neg eax
mov[ecx + 0x50], eax
mov eax, [ecx + 0x40]
cmp edx, eax
jne encrypt_jump_28
mov dword ptr[ecx + 0x44], 0x00000000
		encrypt_jump_28:
			cmp esi, eax
jne encrypt_jump_27
mov dword ptr[ecx + 0x48], 0x00000000
		encrypt_jump_27:
			mov eax, [ebp - 0x0C]
xor eax, [ebp - 0x10]
xor eax, [ebp - 0x14]
mov ebx, [ebp + 0x0C]
mov[ecx], eax
test ebx, ebx
jle decrypt_jump_28
mov esi, [ebp - 0x18]
mov eax, [ebp + 0x08]
lea edx, [eax + esi * 0x04]
mov esi, ebx
sub ecx, edx
		decrypt_jump_29:
			mov al, [ecx + edx]
lea edx, [edx + 0x01]
xor[edx - 0x01], al
dec esi
jne decrypt_jump_29
		decrypt_jump_28:
			mov ecx, [ebp - 0x24]
mov eax, 0x00000004
sub eax, ebx
mov[ecx], eax
		encrypt_jump_4:
			pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret 0x08
	}
}
void Decryption_016B8070() //banned, don't use this one
{
	_asm
	{
push ebp
mov ebp,esp
sub esp,0x28
mov eax,[ecx+0x04]
mov edx,[ebp+0x0C]
push ebx
push esi
push edi
lea edi,[ecx+0x04] //puts buffer to key_dec1 in edi ecx = edi - 04 at this point
mov [ebp-0x24],edi
test eax,eax
je decrypt_jump_1
mov esi,ecx
mov ebx,edx
sub esi,eax
add esi,04
cmp edx,eax
cmovg ebx,eax
test ebx,ebx
jle decrypt_jump_2
mov edx,[ebp+0x08]
mov edi,ebx
sub esi,edx
		decrypt_jump_3:
mov al,[esi+edx]
xor [edx],al
inc edx
dec edi
jne decrypt_jump_3
mov edi,[ebp-0x24]
mov [ebp+0x08],edx
mov edx,[ebp+0x0C]
decrypt_jump_2:
	sub [edi],ebx
jne decrypt_jump_4
sub edx,ebx
mov [ebp+0x0C],edx
	decrypt_jump_1:
mov eax,[ecx+0x20]
mov esi,[ecx+0x18]
mov ebx,[ecx+0x34]
mov edi,[ecx+0x50]
mov [ebp-0x14],eax
mov eax,[ecx+0x3C]
mov [ebp-0x10],eax
mov eax,[ecx+58]
shr edx,0x02
mov [ebp-0x0C],eax
xor eax,eax
mov [ebp-0x28],edx
mov [ebp-0x1C],esi
mov [ebp-0x04],ebx
mov [ebp-0x08],edi
mov [ebp-0x18],eax
test edx,edx
jng decrypt_jump_5
	decrypt_jump_18:
mov edx,ebx
mov eax,ebx
or edx,esi
and eax,esi
and edx,edi
or edx,eax
mov [ebp-0x20],edx
cmp esi,edx
jne decrypt_jump_7
mov esi,[ecx+0x10]
mov eax,[ecx+0x1C]
mov edx,[ecx+0x0C]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x10],esi
mov [ecx+0x0C],edx
lea eax,[edi+ebx]
cmova edi,ebx
mov [ecx+0x20],eax
mov [ebp-0x14],eax
cmp edi,eax
jna decrypt_jump_8
mov [ecx+0x18],0x00000001
jmp decrypt_jump_9
	decrypt_jump_8:
mov [ecx+0x18],0x00000000
	decrypt_jump_9:
mov eax,[ecx+0x08]
cmp edx,eax
	jne decrypt_jump_32
mov [ecx+0x0C],0x00000000
	decrypt_jump_32:
cmp esi,eax
jne decrypt_jump_10
mov [ecx+0x10],0x00000000
decrypt_jump_10:
	mov eax,[ecx+0x18]
mov edx,[ebp-0x20]
mov ebx,[ebp-0x04]
mov edi,[ebp-0x08]
mov [ebp-0x1C],eax
	decrypt_jump_7:
cmp ebx,edx
jne decrypt_jump_11
mov esi,[ecx+0x2C]
mov eax,[ecx+0x38]
mov edx,[ecx+0x28]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x2C],esi
mov [ecx+0x28],edx
lea eax,[edi+ebx]
cmova edi,ebx
mov [ecx+0x3C],eax
mov [ebp-0x10],eax
cmp edi,eax
jna decrypt_jump_12
mov [ecx+0x34],0x00000001
jmp decrypt_jump_29
	decrypt_jump_12:
mov [ecx+0x34],0x00000000
	decrypt_jump_29:
mov eax,[ecx+24]
cmp edx,eax
jne decrypt_jump_30
mov [ecx+0x28],0x00000000
	decrypt_jump_30:
cmp esi,eax
jne decrypt_jump_13
mov [ecx+0x2C],0x00000000
	decrypt_jump_13:
mov eax,[ecx+0x34]
mov edx,[ebp-0x20]
mov edi,[ebp-0x08]
mov [ebp-0x04],eax
	decrypt_jump_11:
cmp edi,edx
jne decrypt_jump_14
mov esi,[ecx+0x48]
mov eax,[ecx+0x54]
mov edx,[ecx+0x44]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x48],esi
mov [ecx+0x44],edx
lea eax,[edi+ebx]
cmova edi,ebx
mov [ecx+0x58],eax
mov [ebp-0x0C],eax
cmp edi,eax
jna decrypt_jump_15
mov [ecx+0x50],0x00000001
jmp decrypt_jump_16
	decrypt_jump_15:
mov [ecx+0x50],0x00000000
	decrypt_jump_16:
mov eax,[ecx+0x40]
cmp edx,eax
jne decrypt_jump_17
mov [ecx+0x44],0x00000000
	decrypt_jump_17:
cmp esi,eax
jne decrypt_jump_31
mov [ecx+0x48],0x00000000
	decrypt_jump_31:
mov edi,[ecx+0x50]
mov [ebp-0x08],edi
	decrypt_jump_14:
mov ebx,[ebp-0x18]
mov edx,[ebp+0x08]
mov esi,[ebp-0x1C]
mov eax,[edx+ebx*0x4]
xor eax,[ebp-0x0C]
xor eax,[ebp-0x10]
xor eax,[ebp-0x14]
mov [edx+ebx*0x4],eax
inc ebx
cmp ebx,[ebp-0x28]
mov [ebp-0x18],ebx
mov ebx,[ebp-0x04]
jl decrypt_jump_18
	decrypt_jump_5:
and dword ptr [ebp+0x0C],0x03
je decrypt_jump_4
mov edx,ebx
mov eax,ebx
or edx,esi
and eax,esi
and edx,edi
or edx,eax
mov [ebp-0x20],edx
cmp esi,edx
jne decrypt_jump_19
mov esi,[ecx+0x10]
mov eax,[ecx+0x1C]
mov edx,[ecx+0x0C]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x10],esi
mov [ecx+0x0C],edx
lea eax,[edi+ebx]
cmova edi,ebx
cmp eax,edi
mov [ecx+0x20],eax
mov [ebp-0x14],eax
sbb eax,eax
neg eax
mov [ecx+18],eax
mov eax,[ecx+0x08]
cmp edx,eax
jne decrypt_jump_20
mov [ecx+0x0C],0x00000000
	decrypt_jump_20:
cmp esi,eax
jne decrypt_jump_21
mov [ecx+0x10],0x00000000
	decrypt_jump_21:
mov edx,[ebp-0x20]
mov ebx,[ebp-0x04]
	decrypt_jump_19:
cmp ebx,edx
jne decrypt_jump_22
mov esi,[ecx+0x2C]
mov eax,[ecx+0x38]
mov edx,[ecx+0x28]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x2C],esi
mov [ecx+0x28],edx
lea eax,[edi+ebx]
cmova edi,ebx
cmp eax,edi
mov [ecx+0x3C],eax
mov [ebp-0x10],eax
sbb eax,eax
neg eax
mov [ecx+0x34],eax
mov eax,[ecx+0x24]
cmp edx,eax
jne decrypt_jump_23
mov [ecx+0x28],0x00000000
	decrypt_jump_23:
cmp esi,eax
jne decrypt_jump_24
mov [ecx+0x2C],0x00000000
	decrypt_jump_24:
mov edx,[ebp-0x20]
	decrypt_jump_22:
cmp [ebp-0x08],edx
jne decrypt_jump_25
mov esi,[ecx+0x48]
mov eax,[ecx+0x54]
mov edx,[ecx+0x44]
mov ebx,[eax+esi*0x4]
inc esi
mov edi,[eax+edx*0x4]
inc edx
cmp edi,ebx
mov [ecx+0x48],esi
mov [ecx+0x44],edx
lea eax,[edi+ebx]
cmova edi,ebx
cmp eax,edi
mov [ecx+0x58],eax
mov [ebp-0x0C],eax
sbb eax,eax
neg eax
mov [ecx+0x50],eax
mov eax,[ecx+0x40]
cmp edx,eax
jne decrypt_jump_26
mov [ecx+0x44],0x00000000
	decrypt_jump_26:
cmp esi,eax
jne decrypt_jump_25
mov [ecx+0x48],0x00000000
	decrypt_jump_25:
mov eax,[ebp-0x0C]
xor eax,[ebp-0x10]
xor eax,[ebp-0x14]
mov ebx,[ebp+0x0C]
mov [ecx],eax
test ebx,ebx
jle decrypt_jump_27
mov esi,[ebp-0x18]
mov eax,[ebp+0x08]
lea edx,[eax+esi*0x4]
mov esi,ebx
sub ecx,edx
	decrypt_jump_28:
mov al,[ecx+edx]
lea edx,[edx+0x01]
xor [edx-0x01],al
dec esi
jne decrypt_jump_28
	decrypt_jump_27:
mov ecx,[ebp-0x24]
mov eax,0x00000004
sub eax,ebx
mov [ecx],eax
	decrypt_jump_4:
pop edi
pop esi
pop ebx
mov esp,ebp
pop ebp
//ret //008 but taken out because here it's a void. // we dont show rets in inline asm anyway
	}
}
void DecryptReceived_Second_128_Bytes()
{
	_asm
	{
		//eax doesn't matter however it's 80
		//ebx doesn't matter (gets xored)
		//ecx doesn't matter
		//edx is 80
		//esi is buffer address minus 10
		//edi is buffer address
		push ebp
			//probably should add mov ebp,esp
			mov stackholder, esp
			sub esp, 120
		mov eax, 0x80
		mov edx, 0x80
		mov ecx, 0x0000FFFF
		mov edi, ptrReceivedSecondKey
		lea esi, [edi - 0x10]
		xor ebx, ebx
		xor ecx, ecx // patched by glenn, replaces original : mov ecx, [edi + 00010000] 
		mov eax, 0x0000FFFF
		sub eax, ecx
		cmp eax, edx
		//(2) untaken
		lea eax, [ecx + edx] // putes 80 in eax
		mov[edi + 0x00010000], eax
		mov eax, [esi] // gives eax a value for a function call
		mov ecx, esi
		push edx
		mov[ebp - 0x04], edi
		push[ebp - 0x04] // contains buffer address so Glenn patched the previous line
		//call dword ptr [eax+10]
		sub esp,0x04
		push ebp
		mov ebp, esp
		push ebx
		push esi
		mov esi, ecx //useless here
		push edi
		push eax
		mov eax, ptrRandomedFirstKey //patched by glenn along with eax stack instructions [it is 12 bytes before key]
		sub eax,0x0C
		mov [esi + 0x0002001C], eax
		pop eax
		mov ecx, [esi + 0x0002001C] // this is 8 bytes before buffer that contains the 2 randomed keys // 2nd one is intact, first idk yet
		test ecx, ecx
		//(2) taken
		mov eax, [ecx]
		//mov eax, [eax + 0x18] // puts a function call value inside eax, has been removed, caused the program to crash
		//call eax
		sub esp,0x04
		xor eax, eax
		cmp dword ptr[ecx + 0x08], 0x04
		sete al // needs not to happen (zf unset)
		add esp,0x04
		//ret
		mov ecx, [esi + 0x0002001C]//useless
		test al, al
		mov eax, [ecx] //useless, it's done for a function call
		//(2) taken
		lea ebx, [esi + 0x10]
		//call dword ptr [eax+1C]
		sub esp,0x04
		mov eax, 0x00000080
		add esp,0x04
		mov ecx, ebx
		mov edi, eax
		//call 011B0440
		mov eax, [ecx + 0x00010000]
		//ret
		cmp eax, edi
		//(2) untaken
		mov eax, [esi + 0x0002001C]
		mov ecx, ebx
		mov edi, [eax] // gives edi the value for a function call
		//call 011B0220
		mov eax, ecx
		//ret
		mov ecx, [esi + 0x0002001C]
		push eax
		//call dword ptr [edi+08]
		sub esp,0x04
		push ebp
		mov ebp, esp
		mov eax, [ecx + 0x08]
		dec eax
		//(2) untaken
		dec eax
		//(2) untaken
		dec eax
		//(2) taken
		pop ebp
		push ebp
		mov ebp, esp
		sub esp, 0x00000088
		mov eax, [0x020E402C]
		xor eax, ebp
		mov[ebp - 0x04], eax
		mov eax, ecx
		push ebx
		mov ebx, [ebp + 0x08]
		mov eax, ptrArchitectureKey//patched by glenn
		mov [ebp - 0x00000088], eax
		mov [eax + 04],0x01 // patched by glenn
		cmp dword ptr[eax + 0x04], 0x01 // zf must be set
		mov[eax + 04], 0x00000000 // ok but has to be 0 here anyway
		//(2) taken
		mov eax, 0x00000029
		xor edx, edx
		nop
	loop_bis_1:
		cmp eax, 0x00000080
			jnge skip_bis_2
			add eax, -0x80
		skip_bis_2 :
				   mov cl, [edx + ebx]
				   inc edx
				   mov[ebp + eax - 0x00000084], cl
				   inc eax
				   cmp edx, 0x00000080
				   jnge loop_bis_1
				   push esi
				   push edi
				   mov ecx, 0x00000020
				   lea esi, [ebp - 0x00000084]
				   mov edi, ebx
				   repe movsd
				   push eax//patched by glenn
				   mov eax, ptrRandomedFirstKey
				   lea eax, [eax - 0x0C]
				   mov[ebp - 0x00000088], eax
				   pop eax
				   mov ecx, [ebp - 0x00000088] // needs to be first randomed key here
				   push 0x00000080
				   push ebx // was missing so i added it
				   lea ecx, [ecx + 0x0000010C] //useless anyway, it needs to be architecture key buffer
				   mov ecx, ptrArchitectureKey
				   //patched by glenn because of hiro jmp
				   //lea ecx, [ecx + 0x000005C] // [buffer sur la clef de décryptage (non analysée as of now)] Patched 10C -> 5C by glenn
				   //call 016B8070
				   //call Decryption_016B8070
				   push 0x80
				   push ptrReceivedSecondKey
				   call Decryption_016b8070
				   mov edx, [ebp - 0x00000088] // this is supposed to put a buffer to the first randomed key
				   mov ecx, 0x00000020
				   mov esi, ebx
				   push 0x00000080
				   lea eax, [edx + 0x0000008C] // needs to put 2nd randomed key buffer in eax
				   mov eax, ptrRandomedSecondKey
				   mov edi, eax
				   repe movsd
				   push eax
				   lea ecx, [edx + 0x00000168] // needs to be arch key here of decrypt ie base arch key + 0x5c
				   mov ecx, ptrArchitectureKey
				   lea ecx, [ecx + 0x0000005c]
				   call f_TERA_01744DB0 // this call 
				   push eax
				   mov eax, size123
				   cmp eax, 123
				   jne skip1
				   push 0x7b
				   jmp skip2
				   skip1:
		push 0x7f
		skip2 :
			  push ptrBufferReceivedPacket
			  mov ecx, ptrArchitectureKey
			call Encryption_0170AE20 // encrypts the 123 byte ID key !!! 127 bytes since 21.11.2015
				// calls the function which writes the 3 (5) ? inner keys for decryption
				//end of the function writting inner keys
			mov esp,stackholder
			pop ebp

	}
}
void EncryptionCaller_016b8070(void* ptrPacketToSend, int sizeOfPacket)
{

	_asm{
		push ebp
			mov stackholder, esp
			sub esp, 120
		mov ecx,ptrArchitectureKey
			push sizeOfPacket
			push ptrPacketToSend
		call Encryption_0170AE20
		mov esp, stackholder
		pop ebp
	}
}
void DecryptionCaller_016b8070(void* ptrPacketToDecrypt, int sizeOfPacket)
{

	_asm{
		push ebp
			mov stackholder, esp
			sub esp, 120
			mov ecx, ptrArchitectureKey
			lea ecx,[ecx + 0x5c]
			push sizeOfPacket
			push ptrPacketToDecrypt
			call Decryption_016b8070
			mov esp, stackholder
			pop ebp
	}
}
__declspec (naked) void Decryption_016b8070()
{
	_asm
	{
	Decryption_016b8070_jump_address:
			push ebp
			mov ebp, esp
			sub esp, 0x28
			push eax //patched by glenn
			/*
			mov eax, ptrReceivedSecondKey        THiS taken out because it only mean arg.1 should be pushed containing ptrreceived2nd key
			mov dword ptr[ebp + 0x08], eax
			*/
			pop eax //patch ends here 
			mov eax, [ecx + 0x04]
			//mov dword ptr[ebp + 0x0C], 0x80 // this is a patch
			mov edx, [ebp + 0x0C]
			push ebx
			push esi
			push edi
			lea edi, [ecx + 0x04] //puts buffer to key_dec1 in edi ecx = edi - 04 at this point
			mov[ebp - 0x24], edi
			test eax, eax
			je decrypt_jump_1
			mov esi, ecx
			mov ebx, edx
			sub esi, eax
			add esi, 04
			cmp edx, eax
			cmovg ebx, eax
			test ebx, ebx
			jle decrypt_jump_2
			mov edx, [ebp + 0x08]
			mov edi, ebx
			sub esi, edx
		decrypt_jump_3 :
		mov al, [esi + edx]
			xor[edx], al
			inc edx
			dec edi
			jne decrypt_jump_3
			mov edi, [ebp - 0x24]
			mov[ebp + 0x08], edx
			mov edx, [ebp + 0x0C]
		decrypt_jump_2:
			sub[edi], ebx
				jne decrypt_jump_4
				sub edx, ebx
				mov[ebp + 0x0C], edx
			decrypt_jump_1 :
			mov eax, [ecx + 0x20]
				mov esi, [ecx + 0x18]
				mov ebx, [ecx + 0x34]
				mov edi, [ecx + 0x50]
				mov[ebp - 0x14], eax
				mov eax, [ecx + 0x3C]
				mov[ebp - 0x10], eax
				mov eax, [ecx + 0x58]
				shr edx, 0x02 // should be 80 here and then 20
				mov[ebp - 0x0C], eax
				xor eax, eax
				mov[ebp - 0x28], edx
				mov[ebp - 0x1C], esi
				mov[ebp - 0x04], ebx
				mov[ebp - 0x08], edi
				mov[ebp - 0x18], eax
				test edx, edx
				jng decrypt_jump_5
			decrypt_jump_18 :
			mov edx, ebx
				mov eax, ebx
				or edx, esi
				and eax, esi
				and edx, edi
				or edx, eax
				mov[ebp - 0x20], edx
				cmp esi, edx
				jne decrypt_jump_7
				mov esi, [ecx + 0x10]
				mov eax, [ecx + 0x1C] // at this point ecx gives eax the first inner key // checked untill this point
				mov edx, [ecx + 0x0C]
				mov ebx, [eax + esi * 0x4]
				inc esi
				mov edi, [eax + edx * 0x4]
				inc edx
				cmp edi, ebx
				mov dword ptr[ecx + 0x10], esi
				mov dword ptr[ecx + 0x0C], edx
				lea eax, [edi + ebx]
				cmova edi, ebx
				mov dword ptr[ecx + 0x20], eax
				mov dword ptr[ebp - 0x14], eax
				cmp edi, eax
				jna decrypt_jump_8
				mov dword ptr[ecx + 0x18], 0x00000001 // checked so far working
				jmp decrypt_jump_9
			decrypt_jump_8 :
			mov dword ptr[ecx + 0x18], 0x00000000
			decrypt_jump_9 :
						   mov eax, [ecx + 0x08]
						   cmp edx, eax
						   jne decrypt_jump_32
						   mov dword ptr[ecx + 0x0C], 0x00000000
					   decrypt_jump_32 :
									   cmp esi, eax
									   jne decrypt_jump_10
									   mov dword ptr[ecx + 0x10], 0x00000000
								   decrypt_jump_10 :
												   mov eax, [ecx + 0x18]
												   mov edx, [ebp - 0x20]
												   mov ebx, [ebp - 0x04]
												   mov edi, [ebp - 0x08]
												   mov[ebp - 0x1C], eax
											   decrypt_jump_7 :
			cmp ebx, edx
				jne decrypt_jump_11
				mov esi, [ecx + 0x2C]
				mov eax, [ecx + 0x38]
				mov edx, [ecx + 0x28]
				mov ebx, [eax + esi * 0x4]
				inc esi
				mov edi, [eax + edx * 0x4]
				inc edx
				cmp edi, ebx
				mov dword ptr[ecx + 0x2C], esi
				mov dword ptr[ecx + 0x28], edx
				lea eax, [edi + ebx]
				cmova edi, ebx
				mov dword ptr[ecx + 0x3C], eax
				mov dword ptr[ebp - 0x10], eax
				cmp edi, eax
				jna decrypt_jump_12
				mov dword ptr[ecx + 0x34], 0x00000001
				jmp decrypt_jump_29
			decrypt_jump_12 :
			mov dword ptr[ecx + 0x34], 0x00000000 // uses byte ptr and fails
			decrypt_jump_29 :
							mov eax, [ecx + 0x24]
							cmp edx, eax
							jne decrypt_jump_30
							mov dword ptr[ecx + 0x28], 0x00000000
						decrypt_jump_30 :
										cmp esi, eax
										jne decrypt_jump_13
										mov dword ptr[ecx + 0x2C], 0x00000000
									decrypt_jump_13 :
													mov eax, [ecx + 0x34]
													mov edx, [ebp - 0x20]
													mov edi, [ebp - 0x08]
													mov[ebp - 0x04], eax
												decrypt_jump_11 :
			cmp edi, edx
				jne decrypt_jump_14
				mov esi, [ecx + 0x48]
				mov eax, [ecx + 0x54]
				mov edx, [ecx + 0x44]
				mov ebx, [eax + esi * 0x4]
				inc esi
				mov edi, [eax + edx * 0x4]
				inc edx
				cmp edi, ebx
				mov[ecx + 0x48], esi
				mov[ecx + 0x44], edx
				lea eax, [edi + ebx]
				cmova edi, ebx
				mov[ecx + 0x58], eax
				mov[ebp - 0x0C], eax
				cmp edi, eax
				jna decrypt_jump_15
				mov dword ptr[ecx + 0x50], 0x00000001
				jmp decrypt_jump_16
			decrypt_jump_15 :
			mov dword ptr[ecx + 0x50], 0x00000000
			decrypt_jump_16 :
							mov eax, [ecx + 0x40]
							cmp edx, eax
							jne decrypt_jump_17
							mov dword ptr[ecx + 0x44], 0x00000000
						decrypt_jump_17 :
										cmp esi, eax
										jne decrypt_jump_31
										mov dword ptr[ecx + 0x48], 0x00000000 //checked thus far
									decrypt_jump_31 :
													mov edi, [ecx + 0x50]
													mov[ebp - 0x08], edi
												decrypt_jump_14 :
			mov ebx, [ebp - 0x18]
				mov edx, [ebp + 0x08]
				mov esi, [ebp - 0x1C]
				mov eax, [edx + ebx * 0x4]
				xor eax, [ebp - 0x0C]
				xor eax, [ebp - 0x10]
				xor eax, [ebp - 0x14]
				mov[edx + ebx * 0x04], eax
				inc ebx
				cmp ebx, [ebp - 0x28]
				mov[ebp - 0x18], ebx
				mov ebx, [ebp - 0x04]
				jl decrypt_jump_18
			decrypt_jump_5 :
			and dword ptr[ebp + 0x0C], 0x03
				je decrypt_jump_4
				mov edx, ebx
				mov eax, ebx
				or edx, esi
				and eax, esi
				and edx, edi
				or edx, eax
				mov[ebp - 0x20], edx
				cmp esi, edx
				jne decrypt_jump_19
				mov esi, [ecx + 0x10]
				mov eax, [ecx + 0x1C]
				mov edx, [ecx + 0x0C]
				mov ebx, [eax + esi * 0x4]
				inc esi
				mov edi, [eax + edx * 0x4]
				inc edx
				cmp edi, ebx
				mov[ecx + 0x10], esi
				mov[ecx + 0x0C], edx
				lea eax, [edi + ebx]
				cmova edi, ebx
				cmp eax, edi
				mov[ecx + 0x20], eax
				mov[ebp - 0x14], eax
				sbb eax, eax
				neg eax
				mov[ecx + 0x18], eax
				mov eax, [ecx + 0x08]
				cmp edx, eax
				jne decrypt_jump_20
				mov dword ptr[ecx + 0x0C], 0x00000000
			decrypt_jump_20:
			cmp esi, eax
				jne decrypt_jump_21
				mov dword ptr[ecx + 0x10], 0x00000000
			decrypt_jump_21 :
							mov edx, [ebp - 0x20]
							mov ebx, [ebp - 0x04]
						decrypt_jump_19 :
										cmp ebx, edx
										jne decrypt_jump_22
										mov esi, [ecx + 0x2C]
										mov eax, [ecx + 0x38]
										mov edx, [ecx + 0x28]
										mov ebx, [eax + esi * 0x04]
										inc esi
										mov edi, [eax + edx * 0x04]
										inc edx
										cmp edi, ebx
										mov[ecx + 0x2C], esi
										mov[ecx + 0x28], edx
										lea eax, [edi + ebx]
										cmova edi, ebx
										cmp eax, edi
										mov[ecx + 0x3C], eax
										mov[ebp - 0x10], eax
										sbb eax, eax
										neg eax
										mov[ecx + 0x34], eax
										mov eax, [ecx + 0x24]
										cmp edx, eax
										jne decrypt_jump_23
										mov dword ptr[ecx + 0x28], 0x00000000
									decrypt_jump_23:
			cmp esi, eax
				jne decrypt_jump_24
				mov dword ptr[ecx + 0x2C], 0x00000000
			decrypt_jump_24 :
							mov edx, [ebp - 0x20]
						decrypt_jump_22 :
										cmp[ebp - 0x08], edx
										jne decrypt_jump_25
										mov esi, [ecx + 0x48]
										mov eax, [ecx + 0x54]
										mov edx, [ecx + 0x44]
										mov ebx, [eax + esi * 0x04]
										inc esi
										mov edi, [eax + edx * 0x04]
										inc edx
										cmp edi, ebx
										mov[ecx + 0x48], esi
										mov[ecx + 0x44], edx
										lea eax, [edi + ebx]
										cmova edi, ebx
										cmp eax, edi
										mov[ecx + 0x58], eax
										mov[ebp - 0x0C], eax
										sbb eax, eax
										neg eax
										mov[ecx + 0x50], eax
										mov eax, [ecx + 0x40]
										cmp edx, eax
										jne decrypt_jump_26
										mov dword ptr[ecx + 0x44], 0x00000000
									decrypt_jump_26:
			cmp esi, eax
				jne decrypt_jump_25
				mov dword ptr[ecx + 0x48], 0x00000000
			decrypt_jump_25 :
							mov eax, [ebp - 0x0C]
							xor eax, [ebp - 0x10]
							xor eax, [ebp - 0x14]
							mov ebx, [ebp + 0x0C]
							mov[ecx], eax
							test ebx, ebx
							jle decrypt_jump_27
							mov esi, [ebp - 0x18]
							mov eax, [ebp + 0x08]
							lea edx, [eax + esi * 0x04]
							mov esi, ebx
							sub ecx, edx
						decrypt_jump_28 :
			mov al, [ecx + edx]
				lea edx, [edx + 0x01]
				xor[edx - 0x01], al
				dec esi
				jne decrypt_jump_28
			decrypt_jump_27 :
			mov ecx, [ebp - 0x24]
				mov eax, 0x00000004
				sub eax, ebx
				mov[ecx], eax
			decrypt_jump_4 :
			pop edi // edi is a  buffer zero'd priori to which is a key
				pop esi // seems to hold garbage
				pop ebx // holds a buffer to the altered received key (likely)
				mov esp, ebp
				pop ebp
			ret 0x08 //but taken out because here it's a void. this is the end of the decryption function
	}
}
__declspec (naked) void f_TERA_01744DB0()
{
	_asm{
	TERA_01744DB0:

		PUSH EBP
			MOV EBP, ESP
			SUB ESP, 0x308
			push eax //patched by glenn
			mov eax, 0x7e40d858
			mov n021650FC,eax
			pop eax
			MOV EAX, n021650FC
			XOR EAX, EBP
			MOV DWORD PTR SS : [EBP - 0x4], EAX
			PUSH EBX
			MOV EBX, DWORD PTR SS : [EBP + 0x0C]
			PUSH ESI
			PUSH EDI
			MOV EDI, DWORD PTR SS : [EBP + 0x8]
			MOV ESI, ECX
			XOR ECX, ECX

		TERA_01744DD0 :

		MOV EAX, ECX
			XOR EDX, EDX
			DIV EBX
			MOV AL, BYTE PTR DS : [EDX + EDI]
			MOV BYTE PTR SS : [EBP + ECX - 0x2AC], AL
			INC ECX
			CMP ECX, 0x2A8
			JL TERA_01744DD0
			MOV BYTE PTR SS : [EBP - 0x2AC], BL
			XOR EDI, EDI

		TERA_01744DF1 :

		PUSH 0x2A8
			LEA EAX, DWORD PTR SS : [EBP - 0x2AC]
			MOV DWORD PTR SS : [EBP - 0x308], 0x67452301
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x308]
			MOV DWORD PTR SS : [EBP - 0x304], 0xEFCDAB89
			MOV DWORD PTR SS : [EBP - 0x300], 0x98BADCFE
			MOV DWORD PTR SS : [EBP - 0x2FC], 0x10325476
			MOV DWORD PTR SS : [EBP - 0x2F8], 0xC3D2E1F0
			MOV DWORD PTR SS : [EBP - 0x2F0], 0x0
			MOV DWORD PTR SS : [EBP - 0x2F4], 0x0
			call f_TERA_01754B40 // <= Jump / Call Address Not Resolved
			LEA ECX, DWORD PTR SS : [EBP - 0x308]
			call f_TERA_01739C30 //<= Jump / Call Address Not Resolved
			MOV EAX, DWORD PTR SS : [EBP - 0x308]
			MOV DWORD PTR SS : [EBP + EDI - 0x2AC], EAX
			MOV EAX, DWORD PTR SS : [EBP - 0x304]
			MOV DWORD PTR SS : [EBP + EDI - 0x2A8], EAX
			MOV EAX, DWORD PTR SS : [EBP - 0x300]
			MOV DWORD PTR SS : [EBP + EDI - 0x2A4], EAX
			MOV EAX, DWORD PTR SS : [EBP - 0x2FC]
			MOV DWORD PTR SS : [EBP + EDI - 0x2A0], EAX
			MOV EAX, DWORD PTR SS : [EBP - 0x2F8]
			MOV DWORD PTR SS : [EBP + EDI - 0x29C], EAX
			ADD EDI, 0x14
			CMP EDI, 0x2A8
			JL TERA_01744DF1
			XOR EDX, EDX
			CMP DWORD PTR DS : [ESI + 0x8], EDX
			JLE TERA_01744EC3

		TERA_01744EB0 :

		MOV ECX, DWORD PTR DS : [ESI + 0x01C]
			MOV EAX, DWORD PTR SS : [EBP + EDX * 4 - 0x2AC]
			MOV DWORD PTR DS : [ECX + EDX * 4], EAX
			INC EDX
			CMP EDX, DWORD PTR DS : [ESI + 0x8]
			JL TERA_01744EB0

		TERA_01744EC3 :

		MOV EAX, DWORD PTR DS : [ESI + 0x014]
			MOV ECX, DWORD PTR DS : [ESI + 0x8]
			MOV DWORD PTR DS : [ESI + 0x020], 0x0
			MOV DWORD PTR DS : [ESI + 0x018], 0x0
			MOV DWORD PTR DS : [ESI + 0x0C], 0x0
			MOV DWORD PTR DS : [ESI + 0x010], EAX
			CMP EAX, ECX
			JLE TERA_01744EEE

		TERA_01744EE5 :

		SUB EAX, ECX
			CMP EAX, ECX
			JG TERA_01744EE5
			MOV DWORD PTR DS : [ESI + 0x010], EAX

		TERA_01744EEE :

		XOR EDX, EDX
			CMP DWORD PTR DS : [ESI + 0x024], EDX
			JLE TERA_01744F13
			JMP TERA_01744F00
			LEA ESP, DWORD PTR SS : [ESP]
			MOV EDI, EDI

		TERA_01744F00 :

		MOV ECX, DWORD PTR DS : [ESI + 0x038]
			MOV EAX, DWORD PTR SS : [EBP + EDX * 4 - 0x1D0]
			MOV DWORD PTR DS : [ECX + EDX * 4], EAX // this writes the inner keys
			INC EDX
			CMP EDX, DWORD PTR DS : [ESI + 0x024]
			JL TERA_01744F00

		TERA_01744F13 :

		MOV EAX, DWORD PTR DS : [ESI + 0x030]
			MOV ECX, DWORD PTR DS : [ESI + 0x024]
			MOV DWORD PTR DS : [ESI + 0x03C], 0x0
			MOV DWORD PTR DS : [ESI + 0x034], 0x0
			MOV DWORD PTR DS : [ESI + 0x028], 0x0
			MOV DWORD PTR DS : [ESI + 0x02C], EAX
			CMP EAX, ECX
			JLE TERA_01744F3E

		TERA_01744F35 :

		SUB EAX, ECX
			CMP EAX, ECX
			JG TERA_01744F35
			MOV DWORD PTR DS : [ESI + 0x02C], EAX

		TERA_01744F3E :

		XOR EDX, EDX
			CMP DWORD PTR DS : [ESI + 0x040], EDX
			JLE TERA_01744F63
			JMP TERA_01744F50
			LEA ESP, DWORD PTR SS : [ESP]
			MOV EDI, EDI

		TERA_01744F50 :

		MOV ECX, DWORD PTR DS : [ESI + 0x054]
			MOV EAX, DWORD PTR SS : [EBP + EDX * 4 - 0xEC]
			MOV DWORD PTR DS : [ECX + EDX * 4], EAX
			INC EDX
			CMP EDX, DWORD PTR DS : [ESI + 0x040]
			JL TERA_01744F50

		TERA_01744F63 :

		MOV EAX, DWORD PTR DS : [ESI + 0x04C]
			MOV ECX, DWORD PTR DS : [ESI + 0x040]
			MOV DWORD PTR DS : [ESI + 0x058], 0x0
			MOV DWORD PTR DS : [ESI + 0x050], 0x0
			MOV DWORD PTR DS : [ESI + 0x044], 0x0
			MOV DWORD PTR DS : [ESI + 0x048], EAX
			CMP EAX, ECX
			JLE TERA_01744F8E

		TERA_01744F85 :

		SUB EAX, ECX
			CMP EAX, ECX
			JG TERA_01744F85
			MOV DWORD PTR DS : [ESI + 0x048], EAX

		TERA_01744F8E :

		MOV ECX, DWORD PTR SS : [EBP - 0x4]
			POP EDI
			POP ESI
			XOR ECX, EBP
			POP EBX
			//CALL TERA_018F6322; <= Jump / Call Address Not Resolved useless therefore deleted   REMOVED
			MOV ESP, EBP
			POP EBP
			RETN 0x8
	}
}
__declspec (naked) void f_TERA_01754B40()
{
	_asm{
	TERA_01754B40: //; <= Procedure Start

		PUSH EBP
		MOV EBP, ESP
		SUB ESP, 0xC
		MOV EDX, ECX
		mov ecx, [ebp + 0x0C]
		PUSH EBX
		PUSH ESI
		mov[ebp - 0x08], edx
		MOV EAX, DWORD PTR DS : [EDX + 0x014]
		LEA ESI, DWORD PTR DS : [EAX + ECX * 0x08]
		CMP ESI, EAX
		JNB TERA_01754B5D
		INC DWORD PTR DS : [EDX + 0x018]

	TERA_01754B5D :

				  mov ebx, [ebp + 0x08]
				  MOV EAX, ECX
				  SHR EAX, 0x1D
				  ADD DWORD PTR DS : [EDX + 0x018], EAX
				  MOV DWORD PTR DS : [EDX + 0x014], ESI
				  CMP ECX, 0x40
				  JB TERA_01754BD9
				  ADD EDX, 0x1C
				  MOV[ebp + 0x08], EBX
				  SHR ECX, 0x6
				  MOV[ebp - 0x0c], EDX
				  MOV[ebp - 0x04], ECX
				  PUSH EDI

			  TERA_01754B80 :

				  MOV ESI, EBX
					  MOV ECX, 0x10
					  MOV EBX, [ebp - 0x0C]
					  XOR EAX, EAX
					  MOV EDI, EBX
					  REP MOVS DWORD PTR ES : [EDI], DWORD PTR DS : [ESI]

				  TERA_01754B90 :

								MOV ESI, DWORD PTR DS : [EBX + EAX * 4]
								ROL ESI, 0x10
								MOV EDX, ESI
								MOV ECX, ESI
								SHR EDX, 0x8
								SHL ECX, 0x8
								XOR EDX, ECX
								SHL ESI, 0x8
								AND EDX, 0xFF00FF
								XOR EDX, ESI
								MOV DWORD PTR DS : [EBX + EAX * 4], EDX
								INC EAX
								CMP EAX, 0x10
								JL TERA_01754B90
								MOV ECX, [ebp - 0x08] // what is in ecx differs between bot and tera
								call f_TERA_017541E0 //; <= Jump / Call Address Not Resolved
								MOV EBX, [EBP + 0x08]
								MOV ECX, [EBP + 0x0c]
								ADD EBX, 0x40
								SUB ECX, 0x40
								MOV[EBP + 0x08], EBX
								DEC[EBP - 0x04]
								mov[ebp + 0x0C], ecx
								JNZ TERA_01754B80
								mov edx, [ebp - 0x08]
								POP EDI

							TERA_01754BD9 :

				  PUSH ECX
					  LEA EAX, DWORD PTR DS : [EDX + 0x01C]
					  PUSH EBX
					  PUSH EAX
					  call f_memcpy//; <= Jump / Call Address Not Resolved; JMP to msvcr120.memcpy
					  ADD ESP, 0xC
					  POP ESI
					  POP EBX
					  MOV ESP, EBP
					  POP EBP
					  RETN 0x8; <= Procedure End
	}
}
__declspec (naked) void f_TERA_01739C30()
{
	_asm
	{

	TERA_01739C30:   //<= Procedure Start

		PUSH EBP
			MOV EBP, ESP
			PUSH ECX
			PUSH EBX
			PUSH ESI
			PUSH EDI
			MOV EDI, ECX
			MOV EBX, DWORD PTR DS : [EDI + 0x014]
			MOV ECX, EBX
			MOV EAX, DWORD PTR DS : [EDI + 0x018]
			SHR ECX, 0x3
			AND ECX, 0x3F
			MOV[ebp - 0x04], EAX
			MOV BYTE PTR DS : [ECX + EDI + 0x01C], 0x80
			INC ECX
			CMP ECX, 0x38
			JLE TERA_01739C86
			MOV EAX, 0x40
			SUB EAX, ECX
			PUSH EAX
			LEA EAX, DWORD PTR DS : [EDI + 0x01C]
			ADD EAX, ECX
			PUSH 0x0
			PUSH EAX
			CALL f_memset//; <= Jump / Call Address Not Resolved; JMP to msvcr120.memset
			LEA ESI, DWORD PTR DS : [EDI + 0x01C]
			PUSH 0x40
			PUSH ESI
			call f_TERA_01758630//; <= Jump / Call Address Not Resolved
			ADD ESP, 0x14
			MOV ECX, EDI
			call f_TERA_017541E0//; <= Jump / Call Address Not Resolved
			PUSH 0x38
			PUSH 0x0
			PUSH ESI
			JMP TERA_01739C96

		TERA_01739C86 :

		MOV EAX, 0x38
			SUB EAX, ECX
			PUSH EAX
			LEA EAX, DWORD PTR DS : [EDI + 0x01C]
			PUSH 0x0
			ADD EAX, ECX
			PUSH EAX

		TERA_01739C96 :
		call f_memset//CALL TERA_018F6368  <= Jump / Call Address Not Resolved; JMP to msvcr120.memset
		ADD ESP, 0xC
			LEA ESI, DWORD PTR DS : [EDI + 0x01C]
			PUSH 0x40
			PUSH ESI
			call f_TERA_01758630 //; <= Jump / Call Address Not Resolved
			MOV EAX, [ebp - 0x04]
			ADD ESP, 0x8
			MOV ECX, EDI
			MOV DWORD PTR DS : [EDI + 0x054], EAX
			MOV DWORD PTR DS : [EDI + 0x058], EBX
			call f_TERA_017541E0 //; <= Jump / Call Address Not Resolved
			PUSH 0x14
			PUSH ESI
			call f_TERA_01758630 //; <= Jump / Call Address Not Resolved
			ADD ESP, 0x8
			POP EDI
			POP ESI
			POP EBX
			MOV ESP, EBP
			POP EBP
			RETN //; <= Procedure End
	}
}
__declspec (naked) void f_TERA_017541E0()
{
	_asm{
	TERA_017541E0: //; <= Procedure Start

		PUSH EBP
			MOV EBP, ESP
			SUB ESP, 0x158
			MOV EAX, n021650FC
			XOR EAX, EBP
			mov[ebp - 04], eax
			PUSH EBX
			MOV EBX, ECX
			MOV EDX, 0x40
			PUSH ESI
			PUSH EDI
			mov[ebp - 0x00000158], ebx
			mov eax, [ebx + 0x1C]
			mov[ebp - 0x00000144], eax
			mov eax, [ebx + 0x20]
			mov[ebp - 0x00000140], eax
			mov eax, [ebx + 0x24]
			mov[ebp - 0x0000013C], eax
			mov eax, [ebx + 0x28]
			mov[ebp - 0x00000138], eax
			mov eax, [ebx + 0x2C]
			mov[ebp - 0x00000134], eax
			mov eax, [ebx + 0x30]
			mov[ebp - 0x00000130], eax
			mov eax, [ebx + 0x34]
			mov[ebp - 0x0000012C], eax
			mov eax, [ebx + 0x38]
			mov[ebp - 0x00000128], eax
			mov eax, [ebx + 0x3C]
			mov[ebp - 0x00000124], eax
			mov eax, [ebx + 0x40]
			mov[ebp - 0x00000120], eax
			mov eax, [ebx + 0x44]
			mov[ebp - 0x0000011C], eax
			mov eax, [ebx + 0x48]
			mov[ebp - 0x00000118], eax
			mov eax, [ebx + 0x4C]
			mov[ebp - 0x00000114], eax
			mov eax, [ebx + 0x50]
			mov[ebp - 0x00000110], eax
			mov eax, [ebx + 0x54]
			mov[ebp - 0x0000010C], eax
			mov eax, [ebx + 0x58]
			mov[ebp - 0x00000108], eax
			lea eax, [ebp - 0x0000013C]
			LEA ESP, DWORD PTR SS : [ESP]

		TERA_017542A0 :

					  MOV ECX, DWORD PTR DS : [EAX + 0x02C]
					  LEA EAX, DWORD PTR DS : [EAX + 0x4]
					  XOR ECX, DWORD PTR DS : [EAX + 0x014]
					  XOR ECX, DWORD PTR DS : [EAX - 0xC]
					  XOR ECX, DWORD PTR DS : [EAX - 0x4]
					  MOV DWORD PTR DS : [EAX + 0x034], ECX
					  DEC EDX
					  JNZ TERA_017542A0
					  MOV EAX, DWORD PTR DS : [EBX + 0x0C]
					  MOV ECX, DWORD PTR DS : [EBX]
					  MOV EDI, DWORD PTR DS : [EBX + 0x4]
					  MOV ESI, DWORD PTR DS : [EBX + 0x8]
					  mov[ebp - 0x00000150], eax
					  MOV EAX, DWORD PTR DS : [EBX + 0x010]
					  mov ebx, [ebp - 0x00000150]
					  mov[ebp - 0x00000148], ecx
					  mov[ebp - 0x00000154], eax
					  mov[ebp - 0x0000014C], edx

				  TERA_017542E1 :

		MOV EDX, ECX
			MOV EAX, ESI
			AND EAX, EDI
			ROL EDX, 0x5
			MOV ECX, EDI
			NOT ECX
			AND ECX, EBX
			OR ECX, EAX
			mov eax, [ebp - 0x0000014C]
			ADD EDX, ECX
			ADD EDX, DWORD PTR SS : [EBP + EAX * 4 - 0x144]
			mov eax, [ebp - 0x00000154]
			ADD EAX, 0x5A827999
			mov[ebp - 0x00000154], ebx
			add edx, eax
			mov ebx, esi
			mov eax, [ebp - 0x0000014C]
			mov esi, edi
			mov edi, [ebp - 0x00000148]
			INC EAX
			ROR ESI, 0x2
			MOV ECX, EDX
			mov[ebp - 0x00000148], edx
			mov[ebp - 0x0000014C], eax
			CMP EAX, 0x14
			JL TERA_017542E1
			mov[ebp - 0x00000150], ebx
			mov eax, ebx
			mov dword ptr [ebp - 0x00000148], 0x00000014
			LEA ECX, DWORD PTR DS : [ECX]

		TERA_01754350 :

					  XOR EAX, ESI
					  ROL EDX, 0x5
					  XOR EAX, EDI
					  ADD EDX, EAX
					  mov eax, [ebp - 0x00000148]
					  inc dword ptr [ebp - 0x00000148]
					  add edx, [ebp + eax * 0x4 - 0x00000144]
					  mov eax, [ebp - 0x00000154]
					  ADD EAX, 0x6ED9EBA1
					  ADD EDX, EAX
					  mov eax, [ebp - 0x00000150]
					  mov[ebp - 0x00000154], eax
					  mov eax, esi
					  mov esi, edi
					  mov[ebp - 0x00000150], eax
					  ror esi, 0x02
					  mov edi, ecx
					  cmp dword ptr[ebp - 0x00000148], 0x28
					  mov ecx, edx
			jnge TERA_01754350
					  mov[ebp - 0x00000148], ecx
					  mov ebx, edx
					  mov dword ptr [ebp - 0x0000014C], 0x00000028

				  TERA_017543B1:

		MOV ECX, ESI
			ROL EDX, 0x5
			add edx, [ebp - 0x00000154]
			or ecx, edi
			and ecx, eax
			mov eax, esi
			and eax, edi
			or ecx, eax
			mov eax, [ebp - 0x0000014C]
			add ecx, 0x8F1BBCDC
			add ecx, [ebp + eax * 0x4 - 0x00000144]
			mov eax, [ebp - 0x00000150]
			add edx, ecx
			mov ecx, [ebp - 0x0000014C]
			mov[ebp - 0x00000154], eax
			inc ecx
			mov eax, esi
			mov[ebp - 0x0000014C], ecx
			mov esi, edi
			mov[ebp - 0x00000150], eax
			ror esi, 0x02
			mov edi, ebx
			mov ebx, edx
			cmp ecx, 0x3C
			JL TERA_017543B1
			mov[ebp - 0x00000148], ebx
			mov ecx, edx
			mov dword ptr [ebp - 0x0000014C], 0x0000003C
			LEA ESP, DWORD PTR SS : [ESP]

		TERA_01754420 :

					  mov ebx, [ebp - 0x0000014C]
					  xor eax, esi
					  xor eax, edi
					  rol edx, 0x05
					  add edx, [ebp - 0x00000154]
					  add eax, 0xCA62C1D6
					  add eax, [ebp + ebx * 0x4 - 0x00000144]
					  inc ebx
					  add edx, eax
					  mov[ebp - 0x0000014C], ebx
					  mov eax, [ebp - 0x00000150]
					  mov[ebp - 0x00000154], eax
					  mov eax, esi
					  mov esi, edi
					  mov[ebp - 0x00000150], eax
					  ror esi, 0x02
					  mov edi, ecx
					  cmp ebx, 0x50
					  mov ecx, edx
					  mov ebx, [ebp - 0x00000158]
					  JL TERA_01754420
					  ADD DWORD PTR DS : [EBX + 0x4], EDI
					  ADD DWORD PTR DS : [EBX + 0x8], ESI
					  ADD DWORD PTR DS : [EBX + 0x0C], EAX
					  mov ecx, [ebp - 0x04]
					  add[ebx], edx
					  xor ecx, ebp
					  mov eax, [ebp - 0x00000154]
					  ADD DWORD PTR DS : [EBX + 0x010], EAX
					  POP EDI
					  POP ESI
					  POP EBX
					  // CALL @TERA_018F6322; <= Jump / Call Address Not Resolved								DELETED
					  MOV ESP, EBP
					  POP EBP
					  RETN //; <= Procedure End
	}
}
__declspec (naked) void f_TERA_01758630()
{
	_asm{
	TERA_01758630:  // ; <= Procedure Start

		PUSH EBP
			MOV EBP, ESP
			PUSH ESI
			PUSH EDI
			mov edi, [ebp + 0x0C]
			XOR ESI, ESI
			SHR EDI, 0x2
			TEST EDI, EDI
			JLE TERA_0175866B
			PUSH EBX
			mov ebx, [ebp + 0x08]

		TERA_01758645:

			MOV EDX, DWORD PTR DS : [EBX + ESI * 0x4]
				ROL EDX, 0x10
				MOV ECX, EDX
				MOV EAX, EDX
				SHR ECX, 0x8
				SHL EAX, 0x8
				XOR ECX, EAX
				SHL EDX, 0x8
				AND ECX, 0xFF00FF
				XOR ECX, EDX
				MOV DWORD PTR DS : [EBX + ESI * 0x4], ECX
				INC ESI
				CMP ESI, EDI
				JL TERA_01758645
				POP EBX

			TERA_0175866B :

			POP EDI
				POP ESI
				POP EBP
				RETN//; <= Procedure End
	}
}

__declspec (naked) void f_memset()
{
	_asm
	{
		mov edx, [esp + 0x0C]
		mov ecx, [esp + 0x04]
		movzx eax, byte ptr[esp + 0x08]
		mov ecx, [esp + 0x0C]
		push edi
		mov edi, [esp + 0x08]
		repe stosb
		mov eax, [esp + 0x08]
		pop edi
		ret
	}
}
/*			memset template	
sub esp, 04
mov edx,[esp+0C]
		mov ecx, [esp+04]
		movzx eax, byte ptr[esp+08]
		mov ecx, [esp+0C]
		push edi
		mov edi, [esp+08]
		repe stosb
		mov eax, [esp+08]
		pop edi
		add esp,0x04
		*/
__declspec (naked) void f_memcpy()
{
	_asm{
		push edi
			push esi
			mov esi, [esp + 0x10]
			mov ecx, [esp + 0x14]
			mov edi, [esp + 0x0C]
			mov eax, ecx
			mov edx, ecx
			add eax, esi
			repe movsb
			mov eax, [esp + 0x0C]
			pop esi
			pop edi
			ret
	}
}
/*
push edi
push esi
mov esi, [esp+10]
mov ecx, [esp+14]
mov edi, [esp+0C]
mov eax, ecx
mov edx, ecx
add eax, esi
repe movsb
mov eax, [esp+0C]
pop esi
pop edi
*/