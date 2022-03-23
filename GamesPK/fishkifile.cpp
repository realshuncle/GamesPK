#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <fstream>
#include <set>
#include <map>
#include <cstdlib>
#include <chrono>
#include <random>
#include <mmsystem.h>
#include <thread>

using namespace std;
extern bool music;
extern bool sounds;
extern HANDLE hConsole;
int read(string msg, int b, int e);
string readstr(string msg);
void playsound(string soundname, string musicalias);
class MyException {};

string namepicf =
R"(
      (@@@@*      @@@*   @@@@&  @@@@  %@@@   @@@%  @@@@  @@@@@ @@@@    @@@@
  @@@@&@@@%@@@@%  @@@*  @@@@@&  @@@@  %@@@   @@@%  @@@@ @@@*   @@@@  @@@@@@
  @@@  @@@% @@@@  @@@*@@@@@@@&  @@@@  %@@@   @@@%  @@@@@@@     @@@@@@@@@@@@
  @@@@@@@@@@@@@.  @@@@@@  @@@&  @@@@  %@@@   @@@%  @@@@ @@@@   @@@@@@  @@@@
       @@@%       @@@@    @@@&  @@@@@@@@@@@@@@@@%  @@@@  @@@@, @@@@@   @@@@)";
const string comppicc =
R"(  
       ____________________________
      !\_________________________/!\
      !!                         !! \
      !!                         !!  \
      !!                         !!  !
      !!                         !!  !
      !!         ��� ���         !!  !
      !!                         !!  !
      !!                         !!  !
      !!                         !!  /
      !!_________________________!! /
      !/_________________________\!/
         __\_________________/__/!_
        !_______________________!/
      ________________________
     /oooo  oooo  oooo  oooo /!
    /ooooooooooooooooooooooo/ /
   /ooooooooooooooooooooooo/ /
  /C=_____________________/_/     
)";
//HANDLE  hConsole;
int check(set<int>& player, set<int>& comp)
{
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};
	set<int> tempp, tempc;
	if (player.size() + comp.size() == 9)
		return 0;
	for (int i = 0; i < 8; i++)
	{
		tempp.clear();
		tempc.clear();
		set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
		set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
		if (tempp.size() == 3)
			return 1;
		if (tempc.size() == 3)
			return -1;
	}
	return 2;
}
int playg(set<int>& player, set<int>& comp)
{

	set<int> tempp, tempc;
	random_device rd;
	mt19937 mersenne(rd());
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};

	if (player.size() == 1 && player.find(5) != player.end() && comp.size() == 0)
	{
		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(5) == player.end() && comp.size() == 0 || player.size() == 0 && comp.size() == 0)
	{
		comp.insert(5);
		return 5;
	}
	else if (player.size() == 1 && player.find(2) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(8);
		return 8;
	}
	else if (player.size() == 1 && player.find(4) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(6);
		return 6;
	}
	else if (player.size() == 1 && player.find(6) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(4);
		return 4;
	}
	else if (player.size() == 1 && player.find(8) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(2);
		return 2;
	}
	else if (player.size() == 1 && player.find(1) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 4 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 6 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 2)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 4)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(7) != player.end() && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 8)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && comp.size() == 2 && comp.find(5) != comp.end())
	{
		int a[2] = { 0, 0 };
		int k = 0;
		int chet, nechet;
		for (auto j : player)
		{
			a[k] = j;
			k++;
		}
		if ((a[0] + a[1]) % 2 == 1)
		{
			if (a[0] % 2 == 0)
			{
				chet = a[0];
				nechet = a[1];
			}
			else
			{
				chet = a[1];
				nechet = a[0];
			}
			if (nechet == 1)
				if (chet == 2 && comp.find(4) == comp.end())
				{
					comp.insert(4);
					return 4;
				}
				else if(chet == 4 && comp.find(2) == comp.end())
				{
					comp.insert(2);
					return 2;
				}
			else if (nechet == 3)
				if (chet == 2 && comp.find(6) == comp.end())
				{
					comp.insert(6);
					return 6;
				}
				else if (chet == 6 && comp.find(2) == comp.end())
				{
					comp.insert(2);
					return 2;
				}
			else if (nechet == 7)
				if (chet == 4 && comp.find(8) == comp.end())
				{
					comp.insert(8);
					return 8;
				}
				else if (chet == 8 && comp.find(4) == comp.end())
				{
					comp.insert(4);
					return 4;
				}
			else if (nechet == 9)
				if (chet == 8 && comp.find(6) == comp.end())
				{
					comp.insert(6);
					return 6;
				}
				else if (chet == 6 && comp.find(8) == comp.end())
				{
					comp.insert(8);
					return 8;
				}
		}

	}
	if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else
	{

		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempc.size() == 2 && tempp.size() == 0)
			{
				tempp.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempc.begin(), tempc.end(), inserter(tempp, tempp.begin()));
				for (auto j : tempp)
				{
					comp.insert(j);
					return j;
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempp.size() == 2 && tempc.size() == 0)
			{
				tempc.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempp.begin(), tempp.end(), inserter(tempc, tempc.begin()));
				for (auto j : tempc)
				{
					comp.insert(j);
					return j;
				}
			}
		}

		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
		t1 = ((unsigned int)mersenne() % 5 + 1) * 2 - 1;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 9)
				t1 = 1;
			if (t1 == 5)
				t1 = 7;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	}
}
void drawFishki(set<int>& f)
{
	cout << "  ";
	for (int i = 0; i < f.size(); i++)
		cout << "   -----   " << " ";
	cout << "\n  ";
	for (int i = 0; i < f.size(); i++)
		cout << " /       \\ " << " ";
	cout << "\n  ";
	for (int i = 0; i < 10; i++)
	{
		if (f.find(i) != f.end())
			cout << " |   " << i << "   | " << " ";
	}
	cout << "\n  ";
	for (int i = 0; i < f.size(); i++)
		cout << " \\       / " << " ";
	cout << "\n  ";
	for (int i = 0; i < f.size(); i++)
		cout << "   -----   " << " ";
	cout << "  ";
}

void PVI3()
{
	system("cls");
	//int count = 0;
	int i = 25;
	random_device rd;
	mt19937 mersenne(rd());
	//string temp = formnumber();
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};
	set<int> fishkibili = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, player, comp;
	cout << namepicf;
	cout << "\n\n\n" << endl;
	cout << "  ������ ��������� ������� ����� �������, ���� �������, � ��� ����� ������ ������. \n" << endl;
	int temp = (unsigned int)mersenne() % 2;
	bool hod = false;
	int fishka;
	Sleep(1000);
	if (temp)
	{
		cout << "  � ����� ���������, ������� ������ ��...\n  ";
		system("pause");
	}
	else
	{
		cout << "\n  ���! � ���� ������!\n  ";
		system("pause");
		system("cls");
		hod = true;
	}
	int vibor;
	bool flag = false;
	while (true)
	{
		set<int> tempp, tempc;
		if (player.size() + comp.size() == 9)
		{
			system("cls");
			cout << "\n  �����\n\n  ���� �����: ";
			for (auto i : player)
				cout << i << " ";
			cout << "\n  ��� �����: ";
			for (auto i : comp)
				cout << i << " ";
			cout << "\n\n  ����� �� ���� ������� � ���� ��� ����� � ������ 15";
			cout << "\n  ";
			system("pause");
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
			if (tempp.size() == 3)
			{
				system("cls");
				cout << "\n  ������� ��� ������������! �� ��������!";
				cout << "\n\n  ���� �����: ";
				for (auto i : player)
					cout << i << " ";
				cout << "\n  ��� �����: ";
				for (auto i : comp)
					cout << i << " ";
				cout << "\n\n  �� ������� � ���� ��� ����� � ������ 15: ";
				for (auto i : tempp)
					cout << i << " ";
				playsound("win.mp3", "gfive");
				cout << "\n  ";
				system("pause");
				flag = true;
				break;
			}
			if (tempc.size() == 3)
			{
				system("cls");
				cout << "\n  � �������! �� � �� ��������� :(";
				cout << "\n\n  ���� �����: ";
				for (auto i : player)
					cout << i << " ";
				cout << "\n  ��� �����: ";
				for (auto i : comp)
					cout << i << " ";
				cout << "\n\n  � ������ � ���� ��� ����� � ������ 15: ";
				for (auto i : tempc)
					cout << i << " ";
				playsound("sadtrom.mp3", "gfive");
				cout << "\n  ";
				system("pause");
				flag = true;
				break;
			}
		}
		if (flag)
			break;
		if (hod)
		{
			system("cls");
			cout << comppicc;
			cout << endl;
			Sleep(1000);
			fishka = playg(player, comp);
			cout << "  � ������ ����� � ������� " << fishka << "\n  ";
			fishkibili.erase(fishka);
			hod = false;
			system("pause");
			continue;
		}
		system("cls");
		cout << endl;
		cout << "  ��� �����" << endl;
		drawFishki(comp);
		cout << endl;
		cout << "  ���������� �����" << endl;
		drawFishki(fishkibili);
		cout << endl;
		cout << "  ���� �����" << endl;
		drawFishki(player);
		cout << endl;
		cout << "  ���� ������� ����� �����. ������� ����� �����, ������� �� ������ �����.\n  ";
		string str = "";
		char ch;
		int vibor;
		int tmp = 0;
		cout << "  ";
		while (_kbhit()) _getch();
		while (true)
		{
			SetConsoleTextAttribute(hConsole, 8);cout << "\n  (���� �� ������ ����� �� ���� ������� \"�����\")\n  ";SetConsoleTextAttribute(hConsole, 14);
			while (cin.get(ch))
			{
				if (ch == '\n')
					break;
				str += ch;
			}
			if (str == "�����")
				throw MyException();
			try
			{
				vibor = stoi(str);
				if (vibor >= 1 && vibor <= 9 && fishkibili.find(vibor) != fishkibili.end())
					break;
			}
			catch (...)
			{
				vibor = 0;
			}
			system("cls");
			if (tmp == 40)
			{
				mciSendString(L"stop all", NULL, 0, NULL);
				mciSendString(L"play \"audio/tnt.mp3\" wait", NULL, 0, NULL);
				exit(0);
			}
			if (tmp > 20)
				cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			else if (tmp > 5)
				cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
			system("cls");
			cout << endl;
			cout << "  ��� �����" << endl;
			drawFishki(comp);
			cout << endl;
			cout << "  ���������� �����" << endl;
			drawFishki(fishkibili);
			cout << endl;
			cout << "  ���� �����" << endl;
			drawFishki(player);
			cout << endl;
			cout << "  ���� ������� ����� �����. ������� ����� �����, ������� �� ������ �����.\n";
			//drawmatches(i);
			// cout<< endl << endl;
			//cout << "  �������� ������ (���� ���� �������): " << i << endl;
			//cout << "  ����� " << (temp ? name1 : name2) << ", ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������.\n";
			if (vibor > 0 && vibor < 10 && fishkibili.find(vibor) == fishkibili.end())
			{
				cout << "  ��� ����� ��� �����. �������� ������.\n";
			}
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
			tmp++;
			str = "";
			playsound("negative.mp3", "");
		}
		//while (_kbhit()) _getch();
		//cin >> vibor;
		//int tmp = 0;
		//while (!cin.good() || (vibor < 1 && vibor > 9) || fishkibili.find(vibor) == fishkibili.end())
		//{
		//	if (vibor > 0 && vibor < 10 && fishkibili.find(vibor) == fishkibili.end())
		//	{
		//		cout << "��� ����� ��� �����. �������� ������." << endl;
		//	}
		//	else
		//	{
		//		if (tmp == 40)
		//			exit(0);
		//		if (tmp > 20)
		//			cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
		//		else if (tmp > 5)
		//			cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
		fishkibili.erase(vibor);
		player.insert(vibor);
		cout << "  ������." << endl;
		hod = true;
		Sleep(1000);
	}
}
void PVP3()
{
	string voprosi = "";
	random_device rd;
	mt19937 mersenne(rd());
	system("cls");
	cout << namepicf;
	cout << "\n\n\n" << endl;
	cout << "  ����� ��� ��� ������ ����, ���������� �������, ��� ����� ���������� �����.\n  ��� ����� ��� ����� ������ ���� �����." << endl;
	string name1, name2;
	//Sleep(1000);
	cout << endl << "  ������ ����� ������� ���� ���.\t";
	while (_kbhit()) _getch();
	name1 = readstr(namepicf + "\n\n\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  ������������, " << name1 << ". ���������� ���.\n" << endl;
	Sleep(1000);
	system("cls");
	cout << namepicf;
	cout << "\n\n\n" << endl;
	cout << "  ������ ����� ������� ���� ���!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(namepicf + "\n\n\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  �����������, " << name2 << ". ����� ������������ ���!\n\n";
	Sleep(1000);
	while (true)
	{
		set<int> winpos[8] =
		{
			{2, 4, 9},
			{3, 5, 7},
			{1, 6, 8},
			{2, 6, 7},
			{1, 5, 9},
			{3, 4, 8},
			{2, 5, 8},
			{4, 5, 6}
		};
		set<int> fishkibili = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, player, comp;
		bool hod = false;
		//int i = 25;
		system("cls");
		cout << namepicf;
		cout << "\n\n\n" << endl;
		cout << "  ������, ������ ��������� ������� ����� �������, ��� ����� ������ ������.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		cout << namepicf;
		cout << "\n\n\n" << endl;
		cout << "  ��� ������������, ����� " << (temp ? name1 : name2) << ". �� ������ �������.\n  ";
		if (!temp)
		{
			hod = true;
		}
		system("pause");
		int vibor;
		bool flag = false;
		while (true)
		{
			set<int> tempp, tempc;
			if (player.size() + comp.size() == 9)
			{
				system("cls");
				cout << "\n  �����\n\n����� ������ " << name1 << ": ";
				for (auto i : player)
					cout << i << " ";
				cout << "\n  ����� ������ " << name2 << ": ";
				for (auto i : comp)
					cout << i << " ";
				cout << "\n\n  ����� �� ���� ������� � ���� ��� ����� � ������ 15";
				cout << "\n  ";
				system("pause");
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				tempp.clear();
				tempc.clear();
				set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
				set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
				if (tempc.size() == 3)
				{
					system("cls");
					cout << "\n  ������� ��� ������������ ����� " << name1 << "! �� ��������!";
					cout << "\n\n  ����� ������ " << name1 << ": ";
					for (auto i : comp)
						cout << i << " ";
					cout << "\n  ����� ������ " << name2 << ": ";
					for (auto i : player)
						cout << i << " ";
					cout << "\n\n  ����� " << name1 << " ������ � ���� ��� ����� � ������ 15: ";
					for (auto i : tempc)
						cout << i << " ";
					playsound("win.mp3", "gfive");
					cout << "\n  ";
					system("pause");
					flag = true;
					break;
				}
				if (tempp.size() == 3)
				{
					system("cls");
					cout << "\n  ������� ��� ������������ ����� " << name2 << "! �� ��������!";
					cout << "\n\n  ����� ������ " << name1 << ": ";
					for (auto i : comp)
						cout << i << " ";
					cout << "\n  ����� ������ " << name2 << ": ";
					for (auto i : player)
						cout << i << " ";
					cout << "\n\n  ����� " << name2 << " ������ � ���� ��� ����� � ������ 15: ";
					for (auto i : tempp)
						cout << i << " ";
					playsound("win.mp3", "gfive");
					cout << "\n  ";
					system("pause");
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			system("cls");
			cout << endl;
			cout << "  ����� ������ " << name1 << "\n";
			drawFishki(comp);
			cout << endl;
			cout << "  ���������� �����" << endl;
			drawFishki(fishkibili);
			cout << endl;
			cout << "  ����� ������ " << name2 << "\n";
			drawFishki(player);
			cout << endl;
			cout << "  ����� " << (!hod ? name1 : name2) << " ���� ������� ����� �����.\n";
			cout << "  ���� ������� ����� �����. ������� ����� �����, ������� �� ������ �����.\n  ";
			string str = "";
			char ch;
			int vibor;
			int tmp = 0;
			cout << "  ";
			while (_kbhit()) _getch();
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 8);cout << "\n  (���� �� ������ ����� �� ���� ������� \"�����\")\n  ";SetConsoleTextAttribute(hConsole, 14);
				while (cin.get(ch))
				{
					if (ch == '\n')
						break;
					str += ch;
				}
				if (str == "�����")
					throw MyException();
				try
				{
					vibor = stoi(str);
					if (vibor >= 1 && vibor <= 9 && fishkibili.find(vibor) == fishkibili.end())
						break;
				}
				catch (...)
				{
					vibor = 0;
				}
				system("cls");
				if (tmp == 40)
				{
					mciSendString(L"stop all", NULL, 0, NULL);
					mciSendString(L"play \"audio/tnt.mp3\" wait", NULL, 0, NULL);
					exit(0);
				}
				if (tmp > 20)
					cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
				system("cls");
				cout << endl;
				cout << " ����� ������ " << name1 << "\n";
				drawFishki(comp);
				cout << endl;
				cout << "  ���������� �����" << endl;
				drawFishki(fishkibili);
				cout << endl;
				cout << " ����� ������ " << name2 << "\n";
				drawFishki(player);
				cout << endl;
				cout << "  ����� " << (!hod ? name1 : name2) << " ���� ������� ����� �����.\n";
				cout << "  ���� ������� ����� �����. ������� ����� �����, ������� �� ������ �����.\n";
				//drawmatches(i);
				// cout<< endl << endl;
				//cout << "  �������� ������ (���� ���� �������): " << i << endl;
				//cout << "  ����� " << (temp ? name1 : name2) << ", ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������.\n";
				if (vibor > 0 && vibor < 10 && fishkibili.find(vibor) == fishkibili.end())
				{
					cout << "  ��� ����� ��� �����. �������� ������.\n";
				}
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				tmp++;
				str = "";
				playsound("negative.mp3", "");
			}
			//while (_kbhit()) _getch();
			//cin >> vibor;
			//int tmp = 0;
			//while (!cin.good() || (vibor < 1 && vibor > 9) || fishkibili.find(vibor) == fishkibili.end())
			//{
			//	if (vibor > 0 && vibor < 10 && fishkibili.find(vibor) == fishkibili.end())
			//	{
			//		cout << "��� ����� ��� �����. �������� ������." << endl;
			//	}
			//	else
			//	{
			//		if (tmp == 40)
			//			exit(0);
			//		if (tmp > 20)
			//			cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			//		else if (tmp > 5)
			//			cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
			fishkibili.erase(vibor);
			hod ? player.insert(vibor) : comp.insert(vibor);
			cout << "  ������." << endl;
			if (hod)
				hod = false;
			else
				hod = true;
			
			//Sleep(1000);
		}

		system("cls");
		cout << namepicf;
		cout << "\n\n\n" << endl;
		cout << "  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n";
		string text = namepicf + "\n\n\n\n  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		vibor = read(text, 1, 2);
		if (vibor == 2)
			break;
	}
}

void startgamefishki()
{
	if (music)
	{
		mciSendString(L"open \"audio/5.mp3\" alias gfive", NULL, 0, NULL);
		mciSendString(L"play gfive repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gfive volume to 100", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");

		//string temp = formnumber();
		string text = namepicf + "\n\n\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		cout << namepicf;
		cout << "\n\n\n\n";
		//cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string text = namepicf + "\n\n\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				cout << namepicf;
				cout << "\n\n\n" << endl;
				cout << "  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n";
				int vibor = read(text, 1, 3);
				if (vibor == 1)
					PVI3();
				else if (vibor == 2)
					PVP3();
				else if (vibor == 3)
					break;
			}
		}

		else if (vibor == 2)
		{
			system("cls");
			//string temp = formnumber();
			cout << namepicf;
			cout << "\n\n\n" << endl;
			cout << "  �������. " << endl << endl;
			cout << "  �� ����������� ����� ����� ����� � ������� 1, 2, 3, 4, 5, 6, 7, 8, 9.\n  ��� ������ �� ������� ����� ����� (�� ������ ��� ����� ����� ������ ���� �����).\n  ���������� ��� �����, ������� ������ ������ � ���� ��� ����� � ������ 15.\n  ���� �� � ������ ������ ����� ����� �� �����, ����������� �����.\n  ��� ������.\n\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gfive", NULL, 0, NULL);
}