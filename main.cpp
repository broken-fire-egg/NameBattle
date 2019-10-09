#include "Character.h"
using namespace std;
void Battle(Character * p1, Character * p2)
{
	wprintf(L"곧 전투가 시작된다 ....\n");
	wprintf(L"5\n");
	Sleep(1000);
	wprintf(L"4\n");
	Sleep(1000);	
	wprintf(L"3\n");
	Sleep(1000);	
	wprintf(L"2\n");
	Sleep(1000);	
	wprintf(L"1\n");
	Sleep(1000);

	srand(p1->seed + p2->seed);
	bool p1turn = rand() % 1 == 0 ? true : false;
	Character * currentChar;
	Character * oppenentChar;
	int dmg = 0;
	while (true)
	{
		currentChar = p1turn ? p1 : p2;
		oppenentChar = p1turn ? p2 : p1;
		wprintf(L"\n%s의 차례!\n\n", currentChar->name);
		Sleep(750);
		if (currentChar->mp >= 50)
		{
			if (rand() % 2 == 0)
			{
				wprintf(L"%s는 %s를 시전했다!\n",currentChar->name,currentChar->skill);
				Sleep(1000);
				if (rand() % 100 <= currentChar->critial_chance)
				{
					dmg = (currentChar->magic_damage + rand() % 50 - 25) * 2;
					wprintf(L"앗! 그 공격은 합필이면 영 좋지 않은 곳에 맞았다.\n");
					Sleep(1000);
				}
				else
				{

					dmg = currentChar->magic_damage + rand() % 50 - 25;
				}
			}
			else
			{
				wprintf(L"%s는 일반 공격을 했다!", currentChar->name);
				Sleep(1000);
				if (rand() % 100 < currentChar->critial_chance)
				{
					dmg = (currentChar->basic_damage + rand() % 10 - 5) * 2 - oppenentChar->armour;
					wprintf(L"앗! 그 공격은 합필이면 영 좋지 않은 곳에 맞았다.\n");
					Sleep(1000);
				}
				else
				{
					dmg = currentChar->basic_damage + rand() % 10 - 5 - oppenentChar->armour;
				}
			}
		}
		else
		{
			wprintf(L"%s는 일반 공격을 했다!",currentChar->name);
			Sleep(1000);
			if (rand() % 100 < currentChar->critial_chance)
			{
				dmg = (currentChar->basic_damage + rand() % 10 - 5) * 2 - oppenentChar->armour;
				wprintf(L"앗! 그 공격은 합필이면 영 좋지 않은 곳에 맞았다.\n");
				Sleep(1000);
			}
			else
			{
				dmg = currentChar->basic_damage + rand() % 10 - 5 - oppenentChar->armour;
			}
		}
		oppenentChar->hp -= dmg;
		wprintf(L"%s은(는) %d의 피해를 입었다!\n\n", oppenentChar->name, dmg);

		Sleep(1000);
		if (oppenentChar->hp <= 0)
			break;
		wprintf(L"%s의 남은 체력 : %d\n%s의 남은 체력 : %d\n", p1->name, p1->hp, p2->name, p2->hp);
		Sleep(1000);
		p1turn = !p1turn;
	}
	wprintf(L"%s이(가) 쓰러졌다!!!\n%s의 승리!!!\n", oppenentChar->name, currentChar->name);
	Sleep(5000);
}
void Intro()
{
	wprintf(L"도입부를 보시겠습니까 ? (ㅇ/ㄴ) :");
	wchar_t tmp[20];
	wscanf(L"%s", tmp);		
	if (12615 == (int)tmp[0])
	{
		printf("국밥먹을 돈을 벌기 위해 어떤 싸움 대회에 참가했는데 결승까지 감\n");
		Sleep(4000);
		printf("끝임\n");
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
int main()
{
	setlocale(LC_ALL, "korean");
	Intro();
	Character * p1 = new Character();
	Character * p2 = new Character();
	Battle(p1, p2);
	
	return 0;
}