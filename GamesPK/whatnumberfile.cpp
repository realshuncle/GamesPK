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

void playsound(string soundname, string musicalias);

string digpic[11][5] =
{
	{
		"  ___  ",
		" / _ \\ ",
		"| | | |",
		"| |_| |",
		" \\___/ ",
	},
	{	"   _   ",
		"  / |  ",
		"  | |  ",
		"  | |  ",
		"  |_|  ",
	},
	{
		" ____  ",
		"|___ \\ ",
		"  __) |",
		" / __/ ",
		"|_____|",
	},
	{
		" _____ ",
		"|___ / ",
		"  |_ \\ ",
		" ___) |",
		"|____/ ",
	},
	{
		" _  _  ",
		"| || | ",
		"| || | ",
		"|__   |",
		"   |_| ",
	},
	{
		" ____  ",
		"| ___| ",
		"|___ \\ ",
		" ___) |",
		"|____/ ",
	},
	{
		"  __   ",
		" / /_  ",
		"| '_ \\ ",
		"| (_) |",
		" \\___/ ",
	},
	{
		" _____ ",
		"|___  |",
		"   / / ",
		"  / /  ",
		" /_/   ",
	},
	{
		"  ___  ",
		" ( _ ) ",
		" / _ \\ ",
		"| (_) |",
		" \\___/ ",
	},
	{
		"  ___  ",
		" / _ \\ ",
		"| (_) |",
		" \\__, |",
		"   /_/ ",

	},
	{
		"  ___  ",
		" |__ \\ ",
		"   / / ",
		"  |_|  ",
		"  (_)  ",
	},
};
int read(string msg, int b, int e);
string readstr(string msg);
//int read(string msg, int b, int e)
//{
//	string str = "";
//	char ch;
//	int vibor;
//
//	//cin >> vibor;
//	int tmp = 0;
//	cout << "  ";
//	while (_kbhit()) _getch();
//	while (true)
//	{
//
//		while (cin.get(ch))
//		{
//			if (ch == '\n')
//				break;
//			str += ch;
//		}
//		/*while ((ch = _getch()) != '\n')
//		{
//			str += ch;
//		}*/
//		try
//		{
//			vibor = stoi(str);
//			if (vibor >= b && vibor <= e)
//				return vibor;
//		}
//		catch (...)
//		{
//			//cout << msg;
//			//while (_kbhit()) _getch();
//		}
//		system("cls");
//		if (tmp == 40)
//		{
//			//fpr
//			mciSendString(L"stop all", NULL, 0, NULL);
//			mciSendString(L"play \"audio/tnt.mp3\"", NULL, 0, NULL);
//			Sleep(6500);
//			exit(0);
//		}
//		if (tmp > 20)
//			cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
//		else if (tmp > 5)
//			cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
//		cout << msg;
//		//while (_kbhit()) _getch();
//		tmp++;
//		str = "";
//	}
//	//while (/*!cin.good()*/|| vibor < b || vibor > e)
//	//{
//	//    system("cls");
//	//    if (tmp == 40)
//	//        exit(0);
//	//    if (tmp > 20)
//	//        cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
//	//    else if (tmp > 5)
//	//        cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
//	//    cin.clear();
//	//    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
//	//    cout << msg;
//	//    while (_kbhit()) _getch();
//	//    cin >> vibor;
//	//    tmp++;
//	//}
//	//return vibor;
//}
//string digpic[11][5] =
//{
//	{
//		"  _|_|  ",
//		"_|    _|",
//		"_|    _|",
//		"_|    _|",
//		"  _|_|  ",
//	},
//	{
//		"   _|   ",
//		" _|_|   ",
//		"   _|   ",
//		"   _|   ",
//		" _|_|_| ",
//	},
//	{
//		"  _|_|  ",
//		"_|    _|",
//		"    _|  ",
//		"  _|    ",
//		"_|_|_|_|",
//	},
//	{
//		"_|_|_|  ",
//		"      _|",
//		"  _|_|  ",
//		"      _|",
//		"_|_|_|  ",
//	},
//	{
//		"_|  _|  ",
//		"_|  _|  ",
//		"_|_|_|_|",
//		"    _|  ",
//		"    _|  ",
//	},
//	{
//		"_|_|_|_|",
//		"_|      ",
//		"_|_|_|  ",
//		"      _|",
//		"_|_|_|  ",
//
//	},
//	{
//		"  _|_|_|",
//		"_|      ",
//		"_|_|_|  ",
//		"_|    _|",
//		"  _|_|  ",
//
//	},
//	{
//		"_|_|_|_|",
//		"      _|",
//		"     _| ",
//		"   _|   ",
//		"  _|    ",
//
//	},
//	{
//		"  _|_|  ",
//		"_|    _|",
//		"  _|_|  ",
//		"_|    _|",
//		"  _|_|  ",
//	},
//	{
//		"  _|_|  ",
//		"_|    _|",
//		"  _|_|_|",
//		"      _|",
//		"_|_|_|  ",
//
//	},
//		{
//		" _|_|   ",
//		"     _| ",
//		" _|_|   ",
//		"        ",
//		" _|     ",
//
//	},
//};
string formnumber()
{
	string result;
	random_device rd;
	mt19937 mersenne(rd());
	unsigned int num = (unsigned int)mersenne() % 1000;
	vector<int>digits;
	unsigned long long x = num;
	//int size = 1;

	unsigned long long const maxx = 10000000000000000000;
	//unsigned long long trtr = 1;
	if (num > 9)
		while (x > 0)
		{
			digits.push_back(x % 10);
			x = x / 10;
			//size++;
			//trtr *= 10;
		}
	else
		digits.push_back(x % 10);
	result += "\n";
	for (int i = 0; i < 5; i++)
	{
		result += "  ";
		//cout << "  ";
		for (int j = digits.size() - 1; j >= 0; j--)
		{
			result += digpic[digits[j]][i] + " ";
			//cout << digpic[digits[j]][i] << " ";
		}
		result += "  " + digpic[10][i] + "\n";
		//cout << digpic[digits[10]][i] << endl;
	}
	result += "\n";
	return result;
}
void PVI1()
{
	system("cls");
	int count = 0;
	random_device rd;
	mt19937 mersenne(rd());
	string temp = formnumber();
	string text = temp + "\n\n\n  ���� \"������ �����\"\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
	cout << temp;
	cout << "\n\n\n";
	cout << "  ���� \"������ �����\"\n" << endl;
	//cout << "  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n";
	//int vibor = read(text, 1, 3);
	//srand(time(0)); // �������������� ������������
	cout << "  ������ ��������� ������� ����� �������, ��� ����� ���������� �����. \n" << endl;
	Sleep(1000);
	//_getch();
	int c = (unsigned int)mersenne() % 2;
	//int comp = 1 + rand() % 6;
	//int player = 1 + rand() % 6;
	int number;
	if (c == 0)
	{
		cout << "\n  ���������� ����� ����� ���������.\n  ";
		number = 1 + (unsigned int)mersenne() % 1000;
		system("pause");
		system("cls");
		//system("cls");
		cout << "\n  ��������� ������� ����� �� 1 �� 1000." << endl;
		int popit = 10;
		int temp;
		string voprosi = "";
		while (popit > 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  ������� �����, ��� �������� �� ������ ������ ������ �� ��� ����������� ��� ���.\n  ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0." << endl;
			temp = read("\n" + voprosi + "\n  ������� �����, ��� �������� �� ������ ������ ������ �� ��� ����������� ��� ���.\n  ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0.\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 0, 1000);
			/*while (!cin.good() || temp < 0 || temp > 1000)
			{
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
				cout << "������� �����, ��� �������� �� ������ �������� ����� �� ������. ������: \"����� ��, ��� ���������� ����� ������, ��� ��, ��� �� �����\". ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0." << endl;
				cin >> temp;
			}*/
			if (temp == 0)
			{
				system("cls");
				cout << "\n" << voprosi << "\n  ������� ���������� �����." << endl;
				//cin >> temp;
				temp = read("\n" + voprosi + "\n  ������� ���������� �����. \n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 1000);
				/*while (!cin.good() || temp < 0 || temp > 1000)
				{
					cin.clear();
					cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
					cout << "������� ���������� �����." << endl;
					cin >> temp;
				}*/
				if (temp == number)
				{
					cout << "\n  �� ��������! (���������� �����: " << count << ").\n  ";
					playsound("win.mp3", "gone");
				}
				else
				{
					cout << "\n  ���. �� ��������� :( ����� ����: " << number << "\n  ";
					//Sleep(400);
					playsound("sadtrom.mp3", "gone");
					//if (sounds)
					//{
					//	mciSendString(L"open \"audio/sadtrom.mp3\" alias st", NULL, 0, NULL);	
					//	Sleep(500);
					//	while (_kbhit()) _getch();
					//	if (music)
					//		mciSendString(L"setaudio gone volume to 400", NULL, 0, NULL);
					//	mciSendString(L"setaudio st volume to 700", NULL, 0, NULL);
					//	//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
					//	mciSendString(L"play st wait", NULL, 0, NULL);
					//	//mciSendString(L"play \"audio/sadtrom.mp3\" wait", NULL, 0, NULL);
					//	if (music)
					//		mciSendString(L"setaudio gone volume to 1000", NULL, 0, NULL);
					//	while (_kbhit()) _getch();
					//}
						
				}
				break;
			}
			voprosi += "  ����� �� ������ ����� " + to_string(++count) + ": ";
			cout << "  ����� �� ������ ����� " << count << ": ";
			if (temp < number)
			{
				voprosi += "  " + to_string(temp) + " ������ ����������� �����\n";
				cout << "  " << temp << " ������ ����������� �����" << endl;
			}

			else
			{
				voprosi += "  " + to_string(temp) + " �� ������ ����������� ����� (�.�. ���� ������, ���� �����)\n";
				cout << "  " << temp << " �� ������ ����������� ����� (�.�. ���� ������, ���� �����)" << endl;
			}
			popit--;
		}
		if (popit == 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  ������� ���������� �����." << endl;
			//cin >> temp;
			temp = read("\n" + voprosi + "\n  ������� ���������� �����. \n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n", 1, 1000);
			/*while (!cin.good() || temp < 0 || temp > 1000)
			{
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
				cout << "������� ���������� �����." << endl;
				cin >> temp;
			}*/
			if (temp == number)
			{
				cout << "\n  �� ��������! (���������� �����: " << count << ").\n  ";
				playsound("win.mp3", "gone");
			}
			else
			{
				cout << "\n  ���. �� ��������� :( ����� ����: " << number << "\n  ";
				playsound("sadtrom.mp3", "gone");
			}
		}
		system("pause");
	}
	else
	{
		string voprosi = "";
		cout << "\n  ���������� ����� ������ ��.\n  ";
		system("pause");
		system("cls");
		int vib;
		cout << "\n  ��������� ����� �� 1 �� 1000 � ������� ���.\n";
		number = read("\n  ��������� ����� �� 1 �� 1000 � ������� ���.\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 1000);
		//cin >> number;
		/*while (!cin.good() && number < 0 && number > 1000)
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000!";
			cout << "������� ���������� �����." << endl;
			cin >> number;
		}*/
		int popit = 10;
		int dv = 512;
		int num = dv;
		voprosi += "  �� ����� �����: " + to_string(number) + "\n";
		while (popit > 0)
		{

			cout << "  ������ ����� " << ++count << ": ���� ����� ������ " << num << "? " << "�������: 1 - ��, 2 - ���" << endl;
			vib = read(voprosi + "\n  ������ ����� " + to_string(count) + ": ���� ����� ������ " + to_string(num) + "?\n" + "  �������: 1 - ��, 2 - ���\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 2);
			//cin >> vib;
			voprosi += "  ������ ����� " + to_string(count) + ": ���� ����� ������ " + to_string(num) + "? ";
			/*while (!cin.good() || vib < 0 || vib > 2)
			{
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "�� ���������! �� ����� �� ��, ��� ����. ";
				cout << "������� 1 - ��, 2 - ���" << endl;
				cin >> vib;
			}*/
			/*if (dv % 2 != 0)
				dv++;*/
			dv = dv / 2;
			switch (vib)
			{
			case 1:
				if (num == 1000 || number <= num)
				{
					system("cls");
					cout << "\n  � �� ��������! � ��� �� �����!\n  ";
					playsound("obman.mp3", "gone");
					system("pause");
					return;
				}
				voprosi += "��� �����: ��.\n";
				while (num + dv > 1000)
					dv /= 2;
				num += dv;
				break;
			case 2:
				if (num == 1000 || number > num)
				{
					system("cls");
					cout << "\n  � �� ��������! � ��� �� �����!\n  ";
					playsound("obman.mp3", "gone");
					system("pause");
					return;
				}
				voprosi += "��� �����: ���.\n";
				while (num - dv < 1)
					dv /= 2;
				num -= dv;
			default:
				break;
			}
			if (dv == 0)
			{
				if (vib == 1)
					num++;
				cout << voprosi << "\n  ���� �����: " << num << "\n  ";
				system("pause");
				return;
			}
			popit--;
		}
		if (vib == 1)
			num++;
		cout << voprosi << "\n  ���� �����: " << num << "\n  ";
		system("pause");
	}

}
void PVP1()
{
	string voprosi = "";
	random_device rd;
	mt19937 mersenne(rd());
	system("cls");
	string tempi = formnumber();
	cout << tempi;
	cout << "\n\n\n";
	cout << "  ���� \"������ �����\"\n" << endl;
	cout << "  ����� ��� ��� ������ ����, ���������� �������, ��� ����� ���������� �����.\n  ��� ����� ��� ����� ������ ���� �����." << endl;
	string name1, name2;
	//Sleep(1000);
	cout << endl << "  ������ ����� ������� ���� ���.\t";
	while (_kbhit()) _getch();
	name1 = readstr(tempi + "\n\n\n" + "  ���� \"������ �����\"\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  ������������, " << name1 << ". ���������� ���.\n" << endl;
	Sleep(1000);
	system("cls");
	tempi = formnumber();
	cout << tempi;
	cout << "\n\n\n";
	cout << "  ���� \"������ �����\"\n" << endl;
	cout << "  ������ ����� ������� ���� ���!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(tempi + "\n\n\n" + "  ���� \"������ �����\"\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n\n  ������ ����� ������� ���� ���.\t");
	cout << endl << "  �����������, " << name2 << ". ����� ������������ ���!\n\n";
	Sleep(1000);

	while (true)
	{
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ������, ������ ��������� ������� ����� �������, ��� ����� ���������� �����.\n  � ��� ����������.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����� ���������� ����� " << (temp ? name1 : name2) << endl;
		int number;

		cout << "\n  ����� " << (!temp ? name1 : name2) << " ������ �����������.\n\n  ";
		system("pause");
		system("cls");

		//cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		cout << "\n  ����� " << (temp ? name1 : name2) << " ��������� ����� �� 1 �� 1000 � ������� ���." << endl;
		number = read("\n  ����� " + (temp ? name1 : name2) + " ��������� ����� �� 1 �� 1000 � ������� ���.\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 1000);
		system("cls");
		cout << "\n  ������ ����� " << (!temp ? name1 : name2) << " ����� �������� ����������. \n\n  ";
		system("pause");
		int vib;
		int popit = 10;
		while (popit > 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  ������� �����, ��� �������� �� ������ ������ ������ �� ��� ����������� ��� ���.\n  ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0." << endl;
			temp = read("\n" + voprosi + "\n  ������� �����, ��� �������� �� ������ ������ ������ �� ��� ����������� ��� ���.\n  ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0.\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 0, 1000);
			/*while (!cin.good() || temp < 0 || temp > 1000)
			{
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
				cout << "������� �����, ��� �������� �� ������ �������� ����� �� ������. ������: \"����� ��, ��� ���������� ����� ������, ��� ��, ��� �� �����\". ���� �� ��� ������ ����� � ������ ������ �����, �� ������� 0." << endl;
				cin >> temp;
			}*/
			if (temp == 0)
			{
				system("cls");
				cout << "\n" << voprosi << "\n  ������� ���������� �����." << endl;
				//cin >> temp;
				temp = read("\n" + voprosi + "\n  ������� ���������� �����. \n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ", 1, 1000);
				/*while (!cin.good() || temp < 0 || temp > 1000)
				{
					cin.clear();
					cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
					cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
					cout << "������� ���������� �����." << endl;
					cin >> temp;
				}*/
				if (temp == number)
				{
					cout << "\n  ����� " << (temp ? name1 : name2) << ", �� ��������!(���������� �����: " << count << ").\n  ";
					playsound("win.mp3", "gone");
				}
				else
				{
					cout << "\n  ����� " << (temp ? name1 : name2) << ", �� ��������� :( ����� ����: " << number << "\n  ";
					playsound("sadtrom.mp3", "gone");
				}

				break;
			}
			voprosi += "  ����� �� ������ ����� " + to_string(++count) + ": ";
			cout << "  ����� �� ������ ����� " << count << ": ";
			if (temp < number)
			{
				voprosi += "  " + to_string(temp) + " ������ ����������� �����\n";
				cout << "  " << temp << " ������ ����������� �����" << endl;
			}

			else
			{
				voprosi += "  " + to_string(temp) + " �� ������ ����������� ����� (�.�. ���� ������, ���� �����)\n";
				cout << "  " << temp << " �� ������ ����������� ����� (�.�. ���� ������, ���� �����)" << endl;
			}
			popit--;
		}
		if (popit == 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  ������� ���������� �����." << endl;
			//cin >> temp;
			temp = read("\n" + voprosi + "\n  ������� ���������� �����. \n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n", 1, 1000);
			/*while (!cin.good() || temp < 0 || temp > 1000)
			{
				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "�� ���������! ������� ����������� ����� �� 1 �� 1000! ";
				cout << "������� ���������� �����." << endl;
				cin >> temp;
			}*/
			if (temp == number)
			{
				cout << "\n  ����� " << (temp ? name1 : name2) << ", �� ��������! (���������� �����: " << count << ").\n  ";
				playsound("win.mp3", "gone");
			}
			else
			{
				//mciSendString(L"stop gone", NULL, 0, NULL);
				cout << "\n  ����� " << (temp ? name1 : name2) << ", �� ��������� :( ����� ����: " << number << "\n  ";
				playsound("sadtrom.mp3", "gone");
			}
		}
		//system("pause");
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n";
		string text = tempi + "\n\n\n  ���� \"������ �����\"\n\n  ����\n\n\t1 - ������� ��� ���\n\t2 - ��������� � ������ ������ ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		number = read(text, 1, 2);
		if (number == 2)
			break;
	}
}
void startgameygchislo()
{
	if (music)
	{
		mciSendString(L"open \"audio/1.mp3\" alias gone", NULL, 0, NULL);
		mciSendString(L"play gone repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gone volume to 100", NULL, 0, NULL);
	}
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");*/

	while (true)
	{
		system("cls");
		string temp = formnumber();
		string text = temp + "\n\n\n  ���� \"������ �����\"\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		cout << temp;
		cout << "\n\n\n";
		cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string temp = formnumber();
				string text = temp + "\n\n\n  ���� \"������ �����\"\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				cout << temp;
				cout << "\n\n\n";
				cout << "  ���� \"������ �����\"\n" << endl;
				cout << "  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n";
				int vibor = read(text, 1, 3);
				if (vibor == 1)
					PVI1();
				else if (vibor == 2)
					PVP1();
				else if (vibor == 3)
					break;
			}
		}

		else if (vibor == 2)
		{
			system("cls");
			string temp = formnumber();
			cout << temp;
			cout << "\n\n\n";
			cout << "  ���� \"������ �����\"\n" << endl;
			cout << "  �������. " << endl << endl;
			cout << "  � ���� ������ ��� ������.\n  ���� ���������� ����� �� 1 �� 1000, ������ ����������.\n  ��� ����� ����� �������� �� 10 ��������.\n  � ������� ����� �������� �������� �� ���������� ����� ������ ���������������.\n  ����� ����� ���� � ������ 10 ��������.\n  ���� ������ ����� ������� �����, �� �� ��������� ����������, ���� �� �������, �� �����������.\n  ��� ����������, � ��� ���������� ���������� ��������� �������.\n  ��� ������.\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gone", NULL, 0, NULL);
	//system("pause");
}