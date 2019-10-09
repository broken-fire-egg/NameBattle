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

	wchar_t name[64];		//�̸� (���� �ѱ۷θ� �̷�� ���ߵ�, �ɷ�ġ �õ尪�� �̿��)
	wchar_t skill[64];
	unsigned int seed;
	int hp;				//ü��
	int mp;				//����
	int armour;			//����
	int basic_damage;	//��Ÿ ������
	int magic_damage;	//���� ������
	int critial_chance;	//ũ��Ƽ�� Ȯ��
	Character()
	{
		seed = 1;
		if (first)
		{
			wprintf(L"[����] : �ð��� ���, �׳༮�� ��±��� �ö�� �༮�̷α� �ٵ� �� �̸��� ��������...?");
			Sleep(1000);
			wprintf(L"\n(�ѱ۸� ����Ұ�, ���� ����)\n�������� �̸� : ");
		}
		else
			wprintf(L"[����] : ���� ���� ������ ����� ��������... �� �̸��� ������?\n\n���������� �̸� : ");
		wscanf(L"%s", name);
		if (first)
			wprintf(L"\n[%s] : �� �̸��� %s(��)��\n", name, name);
		else
			wprintf(L"[����] : ��, ���� �׷� �̸��̿����� ����.\n");
		Sleep(1000);
		for (int i = 0; i < 64; i++)
		{
			if ((int)name[i] == 0)
				break;
			else if ((int)name[i] < 0xAC00 || (int)name[i] > 0xD7AF)
			{
				if (first)
					wprintf(L"\n[����] : �̸��� �� �׵�����? ���� �ѱ��ε鸸�� �������ε�? ������ ������ �־���? ��� ��ٷ���\n�����, ���� �ѱ����� �ƴ϶�� ������ ���濡 ���� �i�ܳ���... \n\n\n���� �Ѿ!!! �쳡������ ��ȣ : �ϡ�\n���� ���� ���� : �ѱ����� �ƴϿ��� �i�ܳ�.\n\n");
				else
					wprintf(L"\n[����] : %s...?? �� �ܱ����̿���? ���� �ѱ��ε鸸�� �������ε�???, ���� �׷� �װ� �ڵ� ����̳�.\n\n\n���� �Ѿ!!! �쳡������ ��ȣ : �̡�\n���� ���� ���� : ���α��ڰ� �ѱ����� �ƴϿ��� Ż����.\n\n", name);
				Sleep(15000);
				exit(0);
			}
			seed = seed + (int)name[i] * (i + 1);
		}
		if (first)
			wprintf(L"[����] : ��.. %s��� �и� ��Ư�Ⱑ... ��������?\n\n�������� ����� �̸� : ", name);
		else
			wprintf(L"[����] : ���, %s��� ��Ư���...\n\n���α����� ����� �̸� : ", name);
		wscanf(L"%s", skill);
		bool trigger = false;
		for (int i = 0; i < 64; i++)
		{
			if ((int)skill[i] == 0)
				break;
			else if ((int)skill[i] < 0xAC00 || (int)skill[i] > 0xD7AF)
			{
				if (first) {
					wprintf(L"\n[����] : ����̸��� �� �׵�����? ���� �ѱ۸� ��ߵ� ���ž� \n\n\n���� �Ѿ!!! �쳡������ ��ȣ : ���\n���� ���� ���� : ����̸��� �ѱ��� �ƴϿ��� �i�ܳ�.\n\n");
					Sleep(15000);
					exit(0);
				}
				else if(trigger == false)
				{
					wprintf(L"\n[����] : %s...?? �۳⿣ ����̸��� �ܱ��̸����� �ص� �糪 ����\n", skill);
					trigger = true;
					Sleep(2000);
					continue;
				}
			}
		}
		if (first) {
			wprintf(L"\n[����] : �� ����̸��� �׷��� â�� �̸�����?");
			Sleep(2000);
			wprintf(L"\n[%s] : �츮 �����̸� ���� �����ǵ�...",name);
			Sleep(2000);
			wprintf(L"\n[����] : ��..�ƾ� �̾�... �ƹ�ư...\n");
		}
		else
			wprintf(L"\n[����] : �� �װ� �߿��Ѱ� �ƴ϶� ���� �� ��Ⱑ ���۵ȴ�. ����Ͷ�\n");
		first = false;
		Sleep(1500);
		srand(seed);

		hp = rand() % 950 + 50;
		mp = rand() % 240 + 15;
		armour = rand() % 25;
		basic_damage = rand() % 75 + 25;
		magic_damage = basic_damage + rand() % 125;
		critial_chance = rand() % 100 + 1;
		
		wprintf(L"%s�� �ɷ�ġ�� ���ðڽ��ϱ� ? (��/��) :",name);
		wchar_t tmp[20];
		wscanf(L"%s", tmp);
		if (12615 == (int)tmp[0])
		{
			wprintf(L"�̸� : %s\nü�� : %d\n���� : %d\n���� : %d\n�⺻ ���ط� : %d\n��Ư�� : %s\n��� ���ط� : %d\nġ��Ÿ Ȯ�� : %d % \n",name,hp,mp,armour,basic_damage,skill,magic_damage,critial_chance);
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
	~Character()
	{

	}
	void Print()
	{
		wprintf(L"�̸� : %s", name);

	}
};

