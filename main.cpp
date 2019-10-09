#include "Character.h"
using namespace std;
void Battle(Character * p1, Character * p2)
{
	wprintf(L"�� ������ ���۵ȴ� ....\n");
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
		wprintf(L"\n%s�� ����!\n\n", currentChar->name);
		Sleep(750);
		if (currentChar->mp >= 50)
		{
			if (rand() % 2 == 0)
			{
				wprintf(L"%s�� %s�� �����ߴ�!\n",currentChar->name,currentChar->skill);
				Sleep(1000);
				if (rand() % 100 <= currentChar->critial_chance)
				{
					dmg = (currentChar->magic_damage + rand() % 50 - 25) * 2;
					wprintf(L"��! �� ������ �����̸� �� ���� ���� ���� �¾Ҵ�.\n");
					Sleep(1000);
				}
				else
				{

					dmg = currentChar->magic_damage + rand() % 50 - 25;
				}
			}
			else
			{
				wprintf(L"%s�� �Ϲ� ������ �ߴ�!", currentChar->name);
				Sleep(1000);
				if (rand() % 100 < currentChar->critial_chance)
				{
					dmg = (currentChar->basic_damage + rand() % 10 - 5) * 2 - oppenentChar->armour;
					wprintf(L"��! �� ������ �����̸� �� ���� ���� ���� �¾Ҵ�.\n");
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
			wprintf(L"%s�� �Ϲ� ������ �ߴ�!",currentChar->name);
			Sleep(1000);
			if (rand() % 100 < currentChar->critial_chance)
			{
				dmg = (currentChar->basic_damage + rand() % 10 - 5) * 2 - oppenentChar->armour;
				wprintf(L"��! �� ������ �����̸� �� ���� ���� ���� �¾Ҵ�.\n");
				Sleep(1000);
			}
			else
			{
				dmg = currentChar->basic_damage + rand() % 10 - 5 - oppenentChar->armour;
			}
		}
		oppenentChar->hp -= dmg;
		wprintf(L"%s��(��) %d�� ���ظ� �Ծ���!\n\n", oppenentChar->name, dmg);

		Sleep(1000);
		if (oppenentChar->hp <= 0)
			break;
		wprintf(L"%s�� ���� ü�� : %d\n%s�� ���� ü�� : %d\n", p1->name, p1->hp, p2->name, p2->hp);
		Sleep(1000);
		p1turn = !p1turn;
	}
	wprintf(L"%s��(��) ��������!!!\n%s�� �¸�!!!\n", oppenentChar->name, currentChar->name);
	Sleep(5000);
}
void Intro()
{
	wprintf(L"���Ժθ� ���ðڽ��ϱ� ? (��/��) :");
	wchar_t tmp[20];
	wscanf(L"%s", tmp);		
	if (12615 == (int)tmp[0])
	{
		printf("������� ���� ���� ���� � �ο� ��ȸ�� �����ߴµ� ��±��� ��\n");
		Sleep(4000);
		printf("����\n");
		Sleep(3000);
	}
	else if (12596 == (int)tmp[0])
	{

	}
	else
	{
		printf("���� ���� �װ��ϳ� ����� �Է� ���ϳ� ����");
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