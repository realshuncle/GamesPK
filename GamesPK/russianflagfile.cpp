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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
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
		cout << "\n  Осталось ходов: " << count << "." << endl;
		cout << endl;
		drawlunki(lunki, pos1, pos2);
		cout << endl;
		cout << endl << "  Меняем местами шарики с номерами " << pos1 + 1 << " и " << pos2 + 1 << "\n  ";
		swap(lunki[pos1], lunki[pos2]);
		count--;
		system("pause");
	}
	system("cls");
	cout << "\n  Осталось ходов: " << count << "." << endl;
	cout << endl;
	drawlunki(lunki);
	cout << endl;
	cout << endl << "  Это победа!" << "\n  ";
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
	cout << "  Игра \"Российский флаг\"\n\n";
	cout << "  Введите количество лунок. Количество лунок должно быть кратным трем и должно быть БОЛЬШЕ 0 и НЕ БОЛЬШЕ 99\n";
	string str = "";
	char ch;
	int vibor;
	int tmp = 0;
	cout << "  ";
	while (true)
	{
		SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
		while (cin.get(ch))
		{
			if (ch == '\n')
				break;
			str += ch;
		}
		if (str == "выход")
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
			cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
		else if (tmp > 5)
			cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
		drawlogo();
		cout << "\n\n\n";
		cout << "  Игра \"Российский флаг\"\n\n";
		cout << "  Введите количество лунок. Количество лунок должно быть кратным трем и должно быть БОЛЬШЕ 0 и НЕ БОЛЬШЕ 99\n";
		cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
			cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
		else if (tmp > 5)
			cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;

		cin.clear();
		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		cout << "Ошибка ввода. Введите количество лунок. Количество лунок должно быть кратным трем и должно быть БОЛЬШЕ 0 и НЕ БОЛЬШЕ 99." << endl;
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
	cout << "  Игра \"Российский флаг\"\n\n";
	cout << "  Выберите уровень сложности:\n\t1 - легкий\n\t2 - средний\n\t3 - сложный.\n";
	str = "";
	while (true)
	{
		SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
		while (cin.get(ch))
		{
			if (ch == '\n')
				break;
			str += ch;
		}
		if (str == "выход")
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
			cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
		else if (tmp > 5)
			cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
		drawlogo();
		cout << "\n\n\n";
		cout << "  Игра \"Российский флаг\"\n\n";
		cout << "  Выберите уровень сложности:\n\t1 - легкий\n\t2 - средний\n\t3 - сложный.\n";
		cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
	//		cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
	//	else if (tmp > 5)
	//		cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;

	//	cin.clear();
	//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	//	cout << "Ошибка ввода. Выберите уровень сложности : 1 - легкий, 2 - средний, 3 - сложный." << endl;
	//	cin >> yroven;
	//	tmp++;
	//}*/
	if (minim(lunki) == 0)
	{
		system("cls");
		cout << "\n";
		drawlunki(lunki);
		cout << endl;
		cout << "  Так получилось, что все шарики уже находятся на своих местах. Поздравляем!\n  ";
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
			cout << "\n  Осталось ходов: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;	
			cout << "  Введите позицию первого шарика, который вы хотите положить на другое место.\n  ";
			str = "";
			tmp = 0;
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
				while (cin.get(ch))
				{
					if (ch == '\n')
						break;
					str += ch;
				}
				if (str == "выход")
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
					cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
				//drawlogo();
				//system("cls");
				cout << "\n  Осталось ходов: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki);
				cout << endl;
				cout << "  Введите позицию первого шарика, который вы хотите положить на другое место.\n";
				cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
			//		cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
			//	else if (tmp > 5)
			//		cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;
			//	cin.clear();
			//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			//	cout << "Ошибка ввода. Введите позицию первого шарика, который вы хотите положить на другое место." << endl;
			//	cin >> pos1;
			//	tmp++;
			//}
			system("cls");
			cout << "\n  Осталось ходов: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki, pos1 - 1);
			cout << endl;
			cout << "  Введите позицию второго шарика, который вы хотите положить на место первого.\n  ";
			str = "";
			tmp = 0;
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
				while (cin.get(ch))
				{
					if (ch == '\n')
						break;
					str += ch;
				}
				if (str == "выход")
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
					cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
				//drawlogo();
				//system("cls");
				cout << "\n  Осталось ходов: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki, pos1 - 1);
				cout << endl;
				cout << "  Введите позицию второго шарика, который вы хотите положить на место первого.\n";
				if (pos1 == pos2)
					cout << "  Позиция первого и второго шариков совпадают. Так нельзя.\n";
				cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
					cout << "Позиция первого и второго шариков совпадают. Так нельзя." << endl;
				if (tmp == 40)
					exit(0);
				if (tmp > 20)
					cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;

				cin.clear();
				cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				cout << "Ошибка ввода. Введите позицию второго шарика, который вы хотите положить на место первого." << endl;
				cin >> pos2;
				tmp++;
			}*/
			swap(lunki[pos1 - 1], lunki[pos2 - 1]);
			hodi--;
		}
		if (hodi > 0 || minim(lunki) == 0)
		{
			system("cls");
			cout << "\n  Осталось ходов: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;
			cout << "  Вы выиграли! Поздравляем!\n  ";
			playsound("win.mp3", "gseven");
			system("pause");
		}
		else
		{

			system("cls");
			cout << "\n  Осталось ходов: " << hodi << "." << endl;
			cout << endl;
			drawlunki(lunki);
			cout << endl;
			cout << "  Вы проиграли!\n";
			playsound("sadtrom.mp3", "gseven");
			str = "";
			tmp = 0;
			cout << "  Если Вы ходите увидеть как играет профессионал ввдите 1, если не хотите введите 2.\n  ";
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
				while (cin.get(ch))
				{
					if (ch == '\n')
						break;
					str += ch;
				}
				if (str == "выход")
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
					cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
				//drawlogo();
				//system("cls");
				cout << "\n  Осталось ходов: " << hodi << "." << endl;
				cout << endl;
				drawlunki(lunki);
				cout << endl;
				cout << "  Вы проиграли!\n";
				cout << "  Если Вы ходите увидеть как играет профессионал ввдите 1, если не хотите введите 2.\n";
				cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";				
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
			//		cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
			//	else if (tmp > 5)
			//		cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;

			//	cin.clear();
			//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			//	cout << "Ошибка ввода. Если Вы ходите увдеть как играет профессионал ввдите 1, если не хотите введите 2." << endl;
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
		cout << "  Игра \"Российский флаг\"\n\n";
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		string str = "";
		char ch;
		int vibor;
		int tmp = 0;
		cout << "  ";
		while (_kbhit()) _getch();
		while (true)
		{
			SetConsoleTextAttribute(hConsole, 8);cout << "\n  (Если Вы хотите выйти из игры введите \"выход\")\n  ";SetConsoleTextAttribute(hConsole, 14);
			while (cin.get(ch))
			{
				if (ch == '\n')
					break;
				str += ch;
			}
			if (str == "выход")
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
				cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
			else if (tmp > 5)
				cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
			drawlogo();
			cout << "\n\n\n";
			cout << "  Игра \"Российский флаг\"\n\n";
			cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
			cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
			cout << "  Игра \"Российский флаг\"\n\n";
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  Вдоль доски расположены лунки (количество лунок кратно 3).\n  В каждой лунке лежит красный, белый или синий шар.\n  Одним ходом разрешается менять местами два любых шара.\n  Необходимо добиться того, чтобы все белые шары шли первыми, за ними - синие шары, а красные - последними.\n  Программа может имеет три уровня сложности, которые зависят от количества ходов.\n\n  Для удобства лунки на экране распологаются в три ряда: белый, синий и красный ряд.\n  Также каждая лунка пронумерована.\n  ";
			system("pause");
		}
		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gseven", NULL, 0, NULL);
}
