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

string namepic =
R"(
      @@@@@@        @@@@@@@@@@@@@@   @@@@      @@@@@   @@@@     @@@@   @@@@@    @@@@  @@@@@     @@@@@  
   @@@@@@@@@@@@     @@@@@@@@@@@@@@   @@@@    @@@@@@@   @@@@     @@@@   @@@@@  @@@@@   @@@@@   @@@@@@@  
  @@@@@     @@@@@   @@@@@    @@@@@   @@@@  @@@@@@@@@   @@@@     @@@@   @@@@@ @@@@     @@@@@ @@@@@@@@@ 
  @@@@@             @@@@@    @@@@@   @@@@@@@@@ @@@@@   @@@@@@@@@@@@@   @@@@@@@@@      @@@@@@@@@ @@@@@ 
  @@@@@     @@@@@   @@@@@    @@@@@   @@@@@@@   @@@@@     @@@@@@@@@@@   @@@@@ @@@@@    @@@@@@@@  @@@@@ 
   @@@@@@@@@@@@@    @@@@@    @@@@@   @@@@@@    @@@@@            @@@@   @@@@@  @@@@@   @@@@@@    @@@@@ 
      @@@@@@        @@@@@    @@@@@   @@@@@     @@@@@            @@@@   @@@@@   @@@@@  @@@@@     @@@@@ )";
const string comppic =
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
void drawmatches(int count)
{
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n";
	cout << "\t";
	for (int i = 0; i < count; i++)
		cout << "() ";
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 6; i++)
	{
		cout << "\t";
		for (int j = 0; j < count; j++)
			cout << "|| ";
		cout << endl;
	}
}
void PVI2()
{
	system("cls");
	//int count = 0;
	int i = 25;
	random_device rd;
	mt19937 mersenne(rd());
	//string temp = formnumber();
	string text = namepic + "\n\n\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
	cout << namepic;
	cout << "\n\n\n" << endl;
	cout << "  ������ ��������� ������� ����� �������, ���� �������, � ��� ����� ������ ������. \n" << endl;
	int temp = (unsigned int)mersenne() % 2;
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
		cout << comppic;
		cout << endl;
		cout << "  ��� �� ��� �����..." << endl;
		Sleep(2000);
		cout << "  ����� ����..." << endl;
		Sleep(2000);
		cout << "  ���..." << endl;
		Sleep(2000);
		cout << "  � ����� ������?..." << endl;
		Sleep(2000);
		random_device rd;
		mt19937 mersenne(rd());
		system("cls");
		cout << comppic;
		if ((unsigned int)mersenne() % 2)
		{
			i -= 4;
			cout << "\n � ������ ������ ������!" << endl;
		}
		else
		{
			i -= 1;
			cout << "\n � ������ ���� ������." << endl;
		}
		Sleep(1500);
	}
	int vibor;
	while (true)
	{
		system("cls");
		drawmatches(i);
		cout << endl << endl;
		cout << "  �������� ������ (���� ���� �������): " << i << endl;
		cout << "  ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������." << endl;
		//cout << "\n(������� \"�����\" ����� �����)\n";
		string str = "";
		char ch;
		int vibor = -1;
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
			/*while ((ch = _getch()) != '\n')
			{
				str += ch;
			}*/
			if (str == "�����")
				throw MyException();
			try
			{
				vibor = stoi(str);
				if (!((vibor != 1 && vibor != 2 && vibor != 4) || (vibor == 4 && i < 4) || (vibor == 2 && i < 2)))
					break;
			}
			catch (...)
			{
				//cout << msg;
				//while (_kbhit()) _getch();
			}
			system("cls");
			if (tmp == 40)
			{
				//fpr
				mciSendString(L"stop all", NULL, 0, NULL);
				mciSendString(L"play \"audio/tnt.mp3\" wait", NULL, 0, NULL);
				//Sleep(6500);
				exit(0);
			}
			if (tmp > 20)
				cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			else if (tmp > 5)
				cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
			//cout << msg;
			
		//	//while (_kbhit()) _getch();
		//	tmp++;
		//	str = "";
		//}
			//cout << msg;
			drawmatches(i);
			cout << endl << endl;
			cout << "  �������� ������ (���� ���� �������): " << i << endl;
			cout << "  ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������.\n";
			if (vibor == 4 && i < 4)
			{
				cout << "  ������ ����� 4 ������, ���� ���� ����� " << i << ". ��������� �� ����.\n  ";
			}
			else if (vibor == 2 && i < 2)
			{
				cout << "  ������ ����� 2 ������, ���� ���� ����� " << i << ". ��������� �� ����.\n  ";
			}
			else
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
			tmp++;
			str = "";
			playsound("negative.mp3", "");
		}


		//vibor = read("  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 4)
		//while (_kbhit()) _getch();
		//cin >> vibor;
		//int tmp = 0;
		//while (!cin.good() || (vibor != 1 && vibor != 2 && vibor != 4) || (vibor == 4 && i < 4) || (vibor == 2 && i < 2))
		//{
		//	if (vibor == 4 && i < 4)
		//	{
		//		cout << "������ ����� 4 ������, ���� ���� ����� " << i << ". ������� �� ����.\n  ";
		//	}
		//	else if (vibor == 2 && i < 2)
		//	{
		//		cout << "������ ����� 2 ������, ���� ���� ����� " << i << ". ������� �� ����.\n  ";
		//	}
		//	else
		//	{
		//		if (tmp == 40)
		//			exit(0);
		//		if (tmp > 20)
		//			cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
		//		else if (tmp > 5)
		//			cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;

		//		cin.clear();
		//		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		//		cout << "��������, �����: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������." << endl;
		//	}
		//	cin >> vibor;
		//	tmp++;
		//}
		i -= vibor;
		if (i <= 0)
		{
			cout << "  ����������. �� �������. ���������. ����������.\n  ";
			playsound("win.mp3", "gthree");
			system("pause");
			//Sleep(4000);
			return;
		}
		cout << "  ������." << endl;
		Sleep(1000);
		system("cls");
		cout << comppic;
		cout << endl;
		Sleep(2000);
		int t = i % 3;
		random_device rd;
		mt19937 mersenne(rd());
		if (i == 4 && (unsigned int)mersenne() % 5 == 0)
		{
			cout << "  � ������ ��� ������." << endl;
			Sleep(5000);
			cout << "  ��. �������. � ������� ��� ���������� ������." << endl;
			Sleep(2000);
			cout << "  �� ���������." << endl;
			Sleep(2000);
			cout << "  �� �� ��������������." << endl;
			Sleep(2000);
			cout << "  ��� �����-������ ���������." << endl;
			Sleep(2000);
			cout << "  ����� � �� ��������." << endl;
			Sleep(2000);
			playsound("sadtrom.mp3", "gthree");
			return;
		}
		random_device d;
		mt19937 mersenned(d());
		unsigned int cs = mersenned();
		switch (i % 3)
		{
		case 0:
			if (cs % 3 == 0 && i != 3)
			{
				i -= 4;
				cout << "  � ������ ����� ������ ������!" << endl;
			}
			else if (cs % 3 == 1 || i < 3)
			{
				i -= 1;
				cout << "  � ������ ����� ���� ������." << endl;
			}
			else if (cs % 3 == 2 || i == 3)
			{
				cout << "  �������, � ������ ����� ���� ������." << endl;
				i--;
			}
			break;
		case 1:

			if ((unsigned int)mersenned() % 2 && i != 1)
			{
				i -= 4;
				cout << "  � ������ ����� ������ ������!" << endl;
			}
			else
			{
				i -= 1;
				cout << "  � ������ ����� ���� ������." << endl;
			}
			break;
		case 2:
			i -= 2;
			cout << "  � ������ ��� ������." << endl;
			break;
		default:
			break;
		}
		Sleep(1500);
		if (i <= 0)
		{
			cout << "  �� ���������!\n  ";
			playsound("sadtrom.mp3", "gthree");
			system("pause");
			//Sleep(4000);
			return;
		}
	}
	
}
void PVP2()
{
	string voprosi = "";
	random_device rd;
	mt19937 mersenne(rd());
	system("cls");
	cout << namepic;
	cout << "\n\n\n" << endl;
	cout << "  ����� ��� ��� ������ ����, ���������� �������, ��� ����� ���������� �����.\n  ��� ����� ��� ����� ������ ���� �����." << endl;
	string name1, name2;
	//Sleep(1000);
	cout << endl << "  ������ ����� ������� ���� ���.\t";
	while (_kbhit()) _getch();
	name1 = readstr(namepic + "\n\n\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  ������������, " << name1 << ". ���������� ���.\n" << endl;
	Sleep(1000);
	system("cls");
	cout << namepic;
	cout << "\n\n\n" << endl;
	cout << "  ������ ����� ������� ���� ���!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(namepic + "\n\n\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  �����������, " << name2 << ". ����� ������������ ���!\n\n";
	Sleep(1000);
	while (true)
	{
		int i = 25;
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  ������, ������ ��������� ������� ����� �������, ��� ����� ������ ������.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  ��� ������������, ����� " << (temp ? name1 : name2) << ". �� ������ �������.\n  ";
		system("pause");
		int vibor;
		while (true)
		{
			system("cls");
			drawmatches(i);
			cout << endl << endl;
			cout << "  �������� ������ (���� ���� �������): " << i << endl;
			cout << "  ����� " << (temp ? name1 : name2) << ", ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������." << endl;
			//cout << "\n(������� \"�����\" ����� �����)\n";
			string str = "";
			char ch;
			int vibor = -1;
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
					if (!((vibor != 1 && vibor != 2 && vibor != 4) || (vibor == 4 && i < 4) || (vibor == 2 && i < 2)))
						break;
				}
				catch (...)
				{

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
				drawmatches(i);
				cout << endl << endl;
				cout << "  �������� ������ (���� ���� �������): " << i << endl;
				cout << "  ����� " << (temp ? name1 : name2) << ", ���� ������� ����� ������: 1 - ����� ����, 2 - ����� ���, 4 - ����� ������.\n";
				if (vibor == 4 && i < 4)
				{
					cout << "  ������ ����� 4 ������, ���� ���� ����� " << i << ". ��������� �� ����.\n  ";
				}
				else if (vibor == 2 && i < 2)
				{
					cout << "  ������ ����� 2 ������, ���� ���� ����� " << i << ". ��������� �� ����.\n  ";
				}
				else
					cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				tmp++;
				str = "";
				playsound("negative.mp3", "");
			}
			i -= vibor;
			if (i <= 0)
			{
				cout << "  ����������! ����� " << (temp ? name1 : name2) << " �������.\n  ";
				playsound("win.mp3", "gthree");
				system("pause");
				break;
			}
			
			cout << "  ������." << endl;
			temp++;
			temp %= 2;
			Sleep(1000);
		}
		
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n";
		string text = namepic + "\n\n\n\n  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		vibor = read(text, 1, 2);
		if (vibor == 2)
			break;
	}
}

void startgamemathes()
{
	if (music)
	{
		mciSendString(L"open \"audio/3.mp3\" alias gthree", NULL, 0, NULL);
		mciSendString(L"play gthree repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gthree volume to 100", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");

		//string temp = formnumber();
		string text = namepic + "\n\n\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		cout << namepic;
		cout << "\n\n\n\n";
		//cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string text = namepic + "\n\n\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				cout << namepic;
				cout << "\n\n\n" << endl;
				cout << "  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n";
				int vibor = read(text, 1, 3);
				if (vibor == 1)
					PVI2();
				else if (vibor == 2)
					PVP2();
				else if (vibor == 3)
					break;
			}
		}

		else if (vibor == 2)
		{
			system("cls");
			//string temp = formnumber();
			cout << namepic;
			cout << "\n\n\n" << endl;
			cout << "  �������. " << endl << endl;
			cout << "  �� ����������� ����� ����� 25 ������.\n  �������� �� ������� ����� ����� 1, 2 ��� 4 ������.\n  ��� �� ����� ������� ��� (������ �� ��������), �����������.\n  ��� ������.\n\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gthree", NULL, 0, NULL);
}