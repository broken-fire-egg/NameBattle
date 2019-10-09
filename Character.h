#pragma once
#pragma warning(disable: 4996)
#include <locale.h>
#include <iostream>
#include <random>
#include <wchar.h>
#include <stdio.h>
#include <windows.h>
bool first = true;
class Character
{
public:

	wchar_t name[64];		//이름 (오직 한글로만 이루어 져야됨, 능력치 시드값에 이용됨)
	wchar_t skill[64];
	unsigned int seed;
	int hp;				//체력
	int mp;				//마나
	int armour;			//방어력
	int basic_damage;	//평타 데미지
	int magic_damage;	//마법 데미지
	int critial_chance;	//크리티컬 확률
	Character()
	{
		seed = 1;
		if (first)
		{
			wprintf(L"[경비경] : 시간이 됬다, 네녀석이 결승까지 올라온 녀석이로군 근데 니 이름이 뭐였더라...?");
			Sleep(1000);
			wprintf(L"\n(한글만 사용할것, 띄어쓰기 금지)\n도전자의 이름 : ");
		}
		else
			wprintf(L"[경비경] : 이제 너의 마지막 상대인 선수권자... 의 이름이 뭐였지?\n\n선수권자의 이름 : ");
		wscanf(L"%s", name);
		if (first)
			wprintf(L"\n[%s] : 내 이름은 %s(이)다\n", name, name);
		else
			wprintf(L"[경비경] : 뭐, 대충 그런 이름이였던것 같다.\n");
		Sleep(1000);
		for (int i = 0; i < 64; i++)
		{
			if ((int)name[i] == 0)
				break;
			else if ((int)name[i] < 0xAC00 || (int)name[i] > 0xD7AF)
			{
				if (first)
					wprintf(L"\n[경비경] : 이름이 왜 그따구야? 여긴 한국인들만의 투기장인데? 서류상에 문제가 있었나? 잠깐 기다려봐\n잠시후, 나는 한국인이 아니라는 이유로 경비경에 의해 쫒겨났다... \n\n\n유희 넘어서!!! ≪끝나가는 번호 : 일≫\n유희를 넘은 이유 : 한국인이 아니여서 쫒겨남.\n\n");
				else
					wprintf(L"\n[경비경] : %s...?? 걔 외국인이였음? 여긴 한국인들만의 투기장인데???, ㅅㅂ 그럼 네가 자동 우승이네.\n\n\n유희 넘어서!!! ≪끝나가는 번호 : 이≫\n유희를 넘은 이유 : 선두권자가 한국인이 아니여서 탈락됬다.\n\n", name);
				Sleep(15000);
				exit(0);
			}
			seed = seed + (int)name[i] * (i + 1);
		}
		if (first)
			wprintf(L"[경비경] : 흠.. %s라면 분명 주특기가... 뭐였더라?\n\n도전자의 기술의 이름 : ", name);
		else
			wprintf(L"[경비경] : 잠깐, %s라면 주특기는...\n\n선두권자의 기술의 이름 : ", name);
		wscanf(L"%s", skill);
		bool trigger = false;
		for (int i = 0; i < 64; i++)
		{
			if ((int)skill[i] == 0)
				break;
			else if ((int)skill[i] < 0xAC00 || (int)skill[i] > 0xD7AF)
			{
				if (first) {
					wprintf(L"\n[경비경] : 기술이름이 왜 그따구야? 여긴 한글만 써야되 병신아 \n\n\n유희 넘어서!!! ≪끝나가는 번호 : 삼≫\n유희를 넘은 이유 : 기술이름이 한글이 아니여서 쫒겨남.\n\n");
					Sleep(15000);
					exit(0);
				}
				else if(trigger == false)
				{
					wprintf(L"\n[경비경] : %s...?? 작년엔 기술이름을 외국이름으로 해도 됬나 보네\n", skill);
					trigger = true;
					Sleep(2000);
					continue;
				}
			}
		}
		if (first) {
			wprintf(L"\n[경비경] : 뭔 기술이름이 그렇게 창녀 이름같냐?");
			Sleep(2000);
			wprintf(L"\n[%s] : 우리 엄마이름 따서 지은건데...",name);
			Sleep(2000);
			wprintf(L"\n[경비경] : 앗..아앗 미안... 아무튼...\n");
		}
		else
			wprintf(L"\n[경비경] : 뭐 그게 중요한게 아니라 이제 곧 경기가 시작된다. 따라와라\n");
		first = false;
		Sleep(1500);
		srand(seed);

		hp = rand() % 950 + 50;
		mp = rand() % 240 + 15;
		armour = rand() % 25;
		basic_damage = rand() % 75 + 25;
		magic_damage = basic_damage + rand() % 125;
		critial_chance = rand() % 100 + 1;
		
		wprintf(L"%s의 능력치를 보시겠습니까 ? (ㅇ/ㄴ) :",name);
		wchar_t tmp[20];
		wscanf(L"%s", tmp);
		if (12615 == (int)tmp[0])
		{
			wprintf(L"이름 : %s\n체력 : %d\n많아 : %d\n방어력 : %d\n기본 피해량 : %d\n주특기 : %s\n기술 피해량 : %d\n치명타 확률 : %d % \n",name,hp,mp,armour,basic_damage,skill,magic_damage,critial_chance);
			Sleep(3000);
		}
		else if (12596 == (int)tmp[0])
		{
		}
		else
		{
			printf("병신 ㅋㅋ 그거하나 제대로 입력 못하냐 ㅉㅉ");
			Sleep(2000);
			exit(0);
		}
	}
	~Character()
	{

	}
	void Print()
	{
		wprintf(L"이름 : %s", name);

	}
};

