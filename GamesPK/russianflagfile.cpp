#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <fstream>
#include <set>
#include <map>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include <random>
#include <vector>

using namespace std;
extern HANDLE  hConsole;

const string cirle[12] =
{
"        <\\/><\\/><\\/>        ",
"    <\\/></\\></\\></\\><\\/>    ",
"    </\\>            </\\>    ",
" <\\/>                  <\\/> ",
" </\\>                  </\\> ",
"<\\/>                    <\\/>",
"</\\>                    </\\>",
" <\\/>                  <\\/> ",
" </\\>                  </\\> ",
"    <\\/>            <\\/>    ",
"    </\\><\\/><\\/><\\/></\\>    ",
"        </\\></\\></\\>        "
};
void drawlogo()
{
	cout << "\n";
	for (int i = 0; i < 12; i++)
	{
		cout << "  ";
		SetConsoleTextAttribute(hConsole, 15);
		cout << cirle[i] << " ";
		SetConsoleTextAttribute(hConsole, 9);
		cout << cirle[i] << " ";
		SetConsoleTextAttribute(hConsole, 12);
		cout << cirle[i] << "\n";
	}
	SetConsoleTextAttribute(hConsole, 14);
}
void drawlunki(vector<int>& lunki)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "  ";
		SetConsoleTextAttribute(hConsole, 8);
		for (int j = (lunki.size() / 3) * i; j < lunki.size() / 3 + (lunki.size() / 3) * i; j++)
		{
			if (j < 9)
				cout << " ";
			cout << j + 1 << " ";
		}
		cout << endl;
		cout << "  ";
		for (int j = (lunki.size() / 3) * i; j < lunki.size() / 3 + (lunki.size() / 3) * i; j++)
		{
			if (lunki[j] == 0)
				SetConsoleTextAttribute(hConsole, 15);
			else if (lunki[j] == 1)
				SetConsoleTextAttribute(hConsole, 9);
			else if (lunki[j] == 2)
				SetConsoleTextAttribute(hConsole, 12);
			cout << " o ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 14);
}
void drawlunki(vector<int>& lunki, int b, int e = -1)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "  ";
		SetConsoleTextAttribute(hConsole, 8);
		for (int j = (lunki.size() / 3) * i; j < lunki.size() / 3 + (lunki.size() / 3) * i; j++)
		{
			if (j < 9)
				cout << " ";
			if (j == b || j == e)
				SetConsoleTextAttribute(hConsole, 10);
			cout << j + 1 << " ";
			SetConsoleTextAttribute(hConsole, 8);
		}
		cout << endl;
		cout << "  ";
		for (int j = (lunki.size() / 3) * i; j < lunki.size() / 3 + (lunki.size() / 3) * i; j++)
		{
			if (lunki[j] == 0)
				SetConsoleTextAttribute(hConsole, 15);
			else if (lunki[j] == 1)
				SetConsoleTextAttribute(hConsole, 9);
			else if (lunki[j] == 2)
				SetConsoleTextAttribute(hConsole, 12);
			cout << " o ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 14);
}
int minim(vector<int> lunki)
{
	int count = 0;
	int pos1, pos2;
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] == 1)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] == 2)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 2)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 1)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}

	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] != 0)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] != 0)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] != 1)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 1)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		swap(lunki[pos1], lunki[pos2]);
		count++;
	}
	return count;
}
void minimtoshow(vector<int> lunki)
{
	int count = minim(lunki);
	int pos1, pos2;
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] == 1)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] == 2)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 2)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 1)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}

	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] != 0)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 0; i < lunki.size() / 3 + (lunki.size() / 3) * 0; i++)
		{
			if (lunki[i] != 0)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 0)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;
		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	while (true)
	{
		pos1 = -1; pos2 = -1;
		for (int i = (lunki.size() / 3) * 1; i < lunki.size() / 3 + (lunki.size() / 3) * 1; i++)
		{
			if (lunki[i] != 1)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = (lunki.size() / 3) * 2; i < lunki.size() / 3 + (lunki.size() / 3) * 2; i++)
		{
			if (lunki[i] == 1)
			{
				pos2 = i;
				break;
			}
		}
		if (pos1 == -1 || pos2 == -1)
			break;

		system("cls");
		cout << "\n  �������� �����: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  ������ ������� ������ � �������� " << pos1 + 1 << " � " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	system("cls");
	cout << "\n  �������� �����: " << count << "." << endl;
	cout << endl;
	drawlunki(lunki);
	cout << endl;
	cout << endl << "  ��� ������!" << "\n  ";
	system("pause");
}
extern bool music;
extern bool sounds;
class MyException {};

int read(string msg, int b, int e);
string readstr(string msg);
void playsound(string soundname, string musicalias);

void playgame()
{
	system("cls");
	random_device rd;
	mt19937 mersenne(rd());
	drawlogo();
	cout << "\n\n\n";
	cout << "  ���� \"���������� ����\"\n\n";
	cout << "  ������� ���������� �����. ���������� ����� ������ ���� ������� ���� � ������ ���� ������ 0 � �� ������ 99\n";
	string str = "";
	char ch;
	int vibor;
	int tmp = 0;
	cout << "  ";
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
			if (!(vibor < 1 || vibor > 99 || vibor % 3 != 0))
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
		drawlogo();
		cout << "\n\n\n";
		cout << "  ���� \"���������� ����\"\n\n";
		cout << "  ������� ���������� �����. ���������� ����� ������ ���� ������� ���� � ������ ���� ������ 0 � �� ������ 99\n";
		cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		playsound("negative.mp3", "");
		//while (_kbhit()) _getch();
		tmp++;
		str = "";
	}
	//while (_kbhit()) _getch();
	int yroven;
	//int vibor;
	//cin >> vibor;
	/*int tmp = 0;
	while (!cin.good() || vibor < 1 || vibor > 99 || vibor % 3 != 0)
	{
		if (tmp == 40)
			exit(0);
		if (tmp > 20)
			cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
		else if (tmp > 5)
			cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;

		cin.clear();
		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		cout << "������ �����. ������� ���������� �����. ���������� ����� ������ ���� ������� ���� � ������ ���� ������ 0 � �� ������ 99." << endl;
		cin >> vibor;
		tmp++;
	}*/
	vector<int>lunki;
	int countb[3] = { 0, 0, 0 };
	for (int i = 0; i < vibor; i++)
	{
		int vib = (unsigned int)mersenne() % 3;
		while (countb[vib] == vibor / 3)
		{
			vib = (vib + 1) % 3;
		}
		if (vib == 0)
			lunki.push_back(0);
		else if (vib == 1)
			lunki.push_back(1);
		else if (vib == 2)
			lunki.push_back(2);
		countb[vib]++;
	}
	vector<int>lunkitoshow(lunki);
	system("cls");
	drawlogo();
	cout << "\n\n\n";
	cout << "  ���� \"���������� ����\"\n\n";
	cout << "  �������� ������� ���������:\n\t1 - ������\n\t2 - �������\n\t3 - �������.\n";
	str = "";
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
			yroven = stoi(str);
			if (!(yroven < 1 || yroven > 3))
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
		drawlogo();
		cout << "\n\n\n";
		cout << "  ���� \"���������� ����\"\n\n";
		cout << "  �������� ������� ���������:\n\t1 - ������\n\t2 - �������\n\t3 - �������.\n";
		cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		playsound("negative.mp3", "");
		//while (_kbhit()) _getch();
		tmp++;
		str = "";
	}
	//cin >> yroven;
	//tmp = 0;
	///*while (!cin.good() || yroven < 1 || yroven > 3)
	//{
	//	if (tmp == 40)
	//		exit(0);
	//	if (tmp > 20)
	//		cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
	//	else if (tmp > 5)
	//		cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;

	//	cin.clear();
	//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	//	cout << "������ �����. �������� ������� ��������� : 1 - ������, 2 - �������, 3 - �������." << endl;
	//	cin >> yroven;
	//	tmp++;
	//}*/
	if (minim(lunki) == 0)
	{
		system("cls");
		cout << "\n";
		drawlunki(lunki);
		cout << endl;
		cout << "  ��� ����������, ��� ��� ������ ��� ��������� �� ����� ������. �����������!\n  ";
		system("pause");
	}
	else
	{
		int hodi;
		if (yroven == 1)
			hodi = lunki.size() - 1;
		else if (yroven == 2)
			hodi = lunki.size() - 1 - ((lunki.size() - 1) - minim(lunki)) / 2;
		else
			hodi = minim(lunki);
		while (minim(lunki) != 0 && hodi > 0)
		{
			int pos1 = -1, pos2 = -1;
			system("cls");
			cout << "\n  �������� �����: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;	
			cout << "  ������� ������� ������� ������, ������� �� ������ �������� �� ������ �����.\n  ";
			str = "";
			tmp = 0;
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
					pos1 = stoi(str);
					if (!(pos1 < 1 || pos1 > lunki.size()))
						break;
				}
				catch (...)
				{
					pos1 = -1;
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
				//drawlogo();
				//system("cls");
				cout << "\n  �������� �����: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki);
				cout << endl;
				cout << "  ������� ������� ������� ������, ������� �� ������ �������� �� ������ �����.\n";
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				playsound("negative.mp3", "");
				//while (_kbhit()) _getch();
				tmp++;
				str = "";
			}
			//cin >> pos1;
			//int tmp = 0;
			//while (!cin.good() || pos1 < 1 || pos1 > lunki.size())
			//{
			//	if (tmp == 40)
			//		exit(0);
			//	if (tmp > 20)
			//		cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			//	else if (tmp > 5)
			//		cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
			//	cin.clear();
			//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			//	cout << "������ �����. ������� ������� ������� ������, ������� �� ������ �������� �� ������ �����." << endl;
			//	cin >> pos1;
			//	tmp++;
			//}
			system("cls");
			cout << "\n  �������� �����: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki, pos1 - 1);
			cout << endl;
			cout << "  ������� ������� ������� ������, ������� �� ������ �������� �� ����� �������.\n  ";
			str = "";
			tmp = 0;
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
					pos2 = stoi(str);
					if (!(pos2 < 1 || pos2 > lunki.size() || pos1 == pos2))
						break;
				}
				catch (...)
				{
					pos2 = -1;
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
				//drawlogo();
				//system("cls");
				cout << "\n  �������� �����: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki, pos1 - 1);
				cout << endl;
				cout << "  ������� ������� ������� ������, ������� �� ������ �������� �� ����� �������.\n";
				if (pos1 == pos2)
					cout << "  ������� ������� � ������� ������� ���������. ��� ������.\n";
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				playsound("negative.mp3", "");
				//while (_kbhit()) _getch();
				tmp++;
				str = "";
			}
			
			/*cin >> pos2;
			tmp = 0;
			while (!cin.good() || pos2 < 1 || pos2 > lunki.size() || pos1 == pos2)
			{
				if (pos1 == pos2)
					cout << "������� ������� � ������� ������� ���������. ��� ������." << endl;
				if (tmp == 40)
					exit(0);
				if (tmp > 20)
					cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;

				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "������ �����. ������� ������� ������� ������, ������� �� ������ �������� �� ����� �������." << endl;
				cin >> pos2;
				tmp++;
			}*/
			swap(lunki[pos1 - 1], lunki[pos2 - 1]);
			hodi--;
		}
		if (hodi > 0 || minim(lunki) == 0)
		{
			system("cls");
			cout << "\n  �������� �����: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;
			cout << "  �� ��������! �����������!\n  ";
			playsound("win.mp3", "gseven");
			system("pause");
		}
		else
		{

			system("cls");
			cout << "\n  �������� �����: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;
			cout << "  �� ���������!\n";
			playsound("sadtrom.mp3", "gseven");
			str = "";
			tmp = 0;
			cout << "  ���� �� ������ ������� ��� ������ ������������ ������ 1, ���� �� ������ ������� 2.\n  ";
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
					if (!(vibor < 1 || vibor > 2))
						break;
				}
				catch (...)
				{
					vibor = -1;
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
				//drawlogo();
				//system("cls");
				cout << "\n  �������� �����: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki);
				cout << endl;
				cout << "  �� ���������!\n";
				cout << "  ���� �� ������ ������� ��� ������ ������������ ������ 1, ���� �� ������ ������� 2.\n";
				cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";				
				playsound("negative.mp3", "");
				//while (_kbhit()) _getch();
				tmp++;
				str = "";
			}
			//cin >> vibor;
			//tmp = 0;
			//while (!cin.good() || vibor < 1 || vibor > 2)
			//{
			//	if (tmp == 40)
			//		exit(0);
			//	if (tmp > 20)
			//		cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			//	else if (tmp > 5)
			//		cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;

			//	cin.clear();
			//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			//	cout << "������ �����. ���� �� ������ ������ ��� ������ ������������ ������ 1, ���� �� ������ ������� 2." << endl;
			//	cin >> vibor;
			//	tmp++;
			//}
			if (vibor == 1)
				minimtoshow(lunkitoshow);
		}
	}

}
void startrf()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(hConsole, 14);
	if (music)
	{
		mciSendString(L"open \"audio/7.mp3\" alias gseven", NULL, 0, NULL);
		mciSendString(L"play gseven repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gthree volume to 100", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");
		drawlogo();
		cout << "\n\n\n";
		cout << "  ���� \"���������� ����\"\n\n";
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
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
				if (vibor >= 1 && vibor <= 3)
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
			drawlogo();
			cout << "\n\n\n";
			cout << "  ���� \"���������� ����\"\n\n";
			cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
			cout << "  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
			playsound("negative.mp3", "");
			//while (_kbhit()) _getch();
			tmp++;
			str = "";
		}
		if (vibor == 1)
			playgame();
		else if (vibor == 2)
		{
			system("cls");
			//string temp = formnumber();
			drawlogo();
			cout << "\n\n\n";
			cout << "  ���� \"���������� ����\"\n\n";
			cout << "  �������. " << endl << endl;
			cout << "  ����� ����� ����������� ����� (���������� ����� ������ 3).\n  � ������ ����� ����� �������, ����� ��� ����� ���.\n  ����� ����� ����������� ������ ������� ��� ����� ����.\n  ���������� �������� ����, ����� ��� ����� ���� ��� �������, �� ���� - ����� ����, � ������� - ����������.\n  ��������� ����� ����� ��� ������ ���������, ������� ������� �� ���������� �����.\n\n  ��� �������� ����� �� ������ ������������� � ��� ����: �����, ����� � ������� ���.\n  ����� ������ ����� �������������.\n  ";
			system("pause");
		}
		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gseven", NULL, 0, NULL);
}
