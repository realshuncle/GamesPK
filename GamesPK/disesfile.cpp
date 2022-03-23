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

const auto jackpot =
R"(
  
     _            _                _   
    (_)          | |              | |  
     _  __ _  ___| | ___ __   ___ | |_ 
    | |/ _` |/ __| |/ / '_ \ / _ \| __|
    | | (_| | (__|   <| |_) | (_) | |_ 
    | |\__,_|\___|_|\_\ .__/ \___/ \__|
   _/ |               | |              
  |__/                |_|              )";
string namepicd =
R"(         
           88 88                        
           88 ""                        
           88                           
   ,adPPYb,88 88  ,adPPYba,  ,adPPYba,  
  a8"    `Y88 88 a8"     "" a8P_____88  
  8b       88 88 8b         8PP"""""""  
  "8a,   ,d88 88 "8a,   ,aa "8b,   ,aa  
   `"8bbdP"Y8 88  `"Ybbd8"'  `"Ybbd8"' 
)";
const auto startgamepic =

R"(
   ##   ## ####### ##   ## #######   ###   #######
   ##   ## ##   ## ##   ## ##   ##  ## ##  ##   ##
   ####### ####### ####### ####### ##   ## ##   ##
   ##   ## ##   ##      ## ##   ## ##   ## ##   ##
   ##   ## ##   ##      ## ##   ## ##   ## #######

          ##   ## ####### ####### ##     ##
          ##  ### ##      ##   ## ##     ## 
          ## # ## ##      ####### ###### ## 
          ###  ## ##      ##      ##  ## ## 
          ##   ## ##      ##      ###### ##)";
const auto winpic =
R"(
  @@@@@@@@@   @@@        @@@  @@@    @@@/  @@@@@@@@  @@@@@@@@   @@@.      ,@@@  #@@(  @@@. (@@@
  @@@   @@@@  @@@        @@@  @@@   @@@@/  @@@@@@@@  @@@  ,@@@  @@@.      ,@@@  #@@(  @@@. (@@@
  @@@@@@@@@   @@@@@@(    @@@  @@@  @@@@@/  @@@       @@@   @@@  @@@@@@,   ,@@@  #@@(  @@@. (@@@
  @@@@@@@@@@  @@@@@@@@@* @@@  @@@@@@&@@@/  @@@       @@@@@@@@   @@@@@@@@@%,@@@  #@@(  @@@. (@@@
  @@@   @@@@  @@@   @@@@ @@@  @@@@@  @@@/  @@@       @@@        @@@.  @@@@,@@@  #@@(  @@@. (@@@
  @@@@@@@@@@  @@@@@@@@@, @@@  @@@@%  @@@/  @@@       @@@        @@@@@@@@@#,@@@  #@@@@@@@@@@@@@@)";

const auto losepic =
R"(               
  @@@@@@@@@@   @@@@@@@*     @@@@@@    @@@    @@@@  @@@@@@@@( @@@@@@@@   @@@        @@@  @@@@  @@@   @@@  @@@&      
  @@@@@@@@@@   @@@@@@@@&  @@@@@@@@@#  @@@   @@@@@  @@@@@@@@( @@@@@@@@@  @@@        @@@  @@@@  @@@   @@@  @@@&      
  @@@&   @@@   @@@  ,@@@ &@@@    @@@  @@@  @@@@@@  @@@       @@@   @@@  @@@***.    @@@  @@@@  @@@   @@@  @@@@**.   
  @@@&   @@@   @@@@@@@@  @@@@    @@@. @@@,@@@@@@@  @@@       @@@@@@@@.  @@@@@@@@@% @@@  @@@@  @@@   @@@  @@@@@@@@@@
  @@@&   @@@   @@@       /@@@   .@@@  @@@@@@ @@@@  @@@       @@@        @@@   &@@@ @@@  @@@@  @@@   @@@  @@@&  (@@@
  @@@&   @@@   @@@        @@@@@@@@@   @@@@@  @@@@  @@@       @@@        @@@@@@@@@@ @@@  @@@@@@@@@@@@@@@  @@@@@@@@@@
  @@@&   @@@   @@@          /@@@@/    @@@/   @@@@  @@@       @@@        @@@@@@&/   @@@  @@@@@@@@@@@@@@@  @@@@@@&/  )";

string dices[6][8] =
{
	{
		" nnnnnnnnnnnnnn ",
		"#              #",
		"#              #",
		"#      oo      #",
		"#      oo      #",
		"#              #",
		"#              #",
		" nnnnnnnnnnnnnn ",
	},
	{
		" nnnnnnnnnnnnnn ",
		"#  oo          #",
		"#  oo          #",
		"#              #",
		"#              #",
		"#          oo  #",
		"#          oo  #",
		" nnnnnnnnnnnnnn ",
	},
	{
		" nnnnnnnnnnnnnn ",
		"#  oo          #",
		"#  oo          #",
		"#      oo      #",
		"#      oo      #",
		"#          oo  #",
		"#          oo  #",
		" nnnnnnnnnnnnnn ",
	},
	{
		" nnnnnnnnnnnnnn ",
		"#  oo      oo  #",
		"#  oo      oo  #",
		"#              #",
		"#              #",
		"#  oo      oo  #",
		"#  oo      oo  #",
		" nnnnnnnnnnnnnn ",
	},
	{
		" nnnnnnnnnnnnnn ",
		"#  oo      oo  #",
		"#  oo      oo  #",
		"#      oo      #",
		"#      oo      #",
		"#  oo      oo  #",
		"#  oo      oo  #",
		" nnnnnnnnnnnnnn ",
	},
	{
		" nnnnnnnnnnnnnn ",
		"#  oo  oo  oo  #",
		"#  oo  oo  oo  #",
		"#              #",
		"#              #",
		"#  oo  oo  oo  #",
		"#  oo  oo  oo  #",
		" nnnnnnnnnnnnnn ",
	},
};
//string digpic[10][5] =
//{
//	{
//		"000000",
//		"00  00",
//		"00  00",
//		"00  00",
//		"000000"
//	},
//	{
//		"1111  ",
//		"  11  ",
//		"  11  ",
//		"  11  ",
//		"111111"
//	},
//	{
//		"222222",
//		"    22",
//		"222222",
//		"22    ",
//		"222222"
//	},
//	{
//		"333333",
//		"    33",
//		"333333",
//		"    33",
//		"333333"
//	},
//	{
//		"44  44",
//		"44  44",
//		"444444",
//		"    44",
//		"    44"
//	},
//	{
//		"555555",
//		"55    ",
//		"555555",
//		"    55",
//		"555555"
//	},
//	{
//		"666666",
//		"66    ",
//		"666666",
//		"66  66",
//		"666666"
//	},
//	{
//		"777777",
//		"    77",
//		"    77",
//		"    77",
//		"    77"
//	},
//	{
//		"888888",
//		"88  88",
//		"888888",
//		"88  88",
//		"888888"
//	},
//	{
//		"999999",
//		"99  99",
//		"999999",
//		"    99",
//		"999999"
//	},
//};
extern string digpic[11][5];
extern bool music;
extern bool sounds;
class MyException {};
void drawnumber(unsigned long long num)
{
	vector<int>digits;
	unsigned long long x = num;
	unsigned long long const maxx = 10000000000000000000;
	if (num > 9)
		while (x > 0)
		{
			digits.push_back(x % 10);
			x = x / 10;
		}
	else
		digits.push_back(x % 10);
	for (int i = 0; i < 5; i++)
	{
		cout << "  ";
		for (int j = digits.size() - 1; j >= 0; j--)
		{
			cout << digpic[digits[j]][i] << " ";
		}
		cout << endl;
	}

}
void drawminusnumber(unsigned long long num, unsigned long long sub)
{
	int size = 1;
	unsigned long long x = num;
	unsigned long long const maxx = 10000000000000000000;
	unsigned long long trtr = 1;
	if (num > 9)
	{
		while (x > 0)
		{
			x = x / 10;
			size++;
			trtr *= 10;
		}
	}

	unsigned long long n = num > sub ? num - sub : 0;
	while (_kbhit()) _getch();
	while (num > n)
	{
		system("cls");
		if (_kbhit())
		{
			cout << "\n  Ваши очки:\n\n";
			drawnumber(n);
			return;
		}
		cout << "\n  Ваши очки:\n\n";
		drawnumber(num);
		while ((num - n) / 10 <= trtr || num - trtr < n)
		{
			trtr /= 10;
			if (trtr == 0)
			{
				trtr = 1;
				break;
			}
		}

		num -= trtr;
	}
	system("cls");
	cout << "\n  Ваши очки:\n\n";
	drawnumber(num);
}
void drawplusnumber(unsigned long long num, unsigned long long sub)
{
	int size = 1;
	unsigned long long const maxx = 10000000000000000000;
	unsigned long long trtr = 1;
	if (num >= maxx || sub >= maxx || maxx - num <= sub || maxx - sub <= num)
	{
		cout << "  ЭТО КОНЕЦ!" << endl;
		return;
	}
	unsigned long long x = num + sub;

	if (num > 9)
	{
		while (x > 0)
		{
			x = x / 10;
			size++;
			trtr *= 10;
		}
	}

	unsigned long long n = num + sub;
	while (_kbhit()) _getch();
	while (num < n)
	{
		system("cls");
		if (_kbhit())
		{
			cout << "\n  Ваши очки:\n\n";
			//cout << "";
			drawnumber(n);
			return;
		}
		cout << "\n  Ваши очки:\n\n";
		drawnumber(num);
		while ((n - num) / 10 <= trtr || n - trtr < num)
		{
			trtr /= 10;
			if (trtr == 0)
			{
				trtr = 1;
				break;
			}
		}

		num += trtr;
	}
	system("cls");
	cout << "\n  Ваши очки:\n\n";
	drawnumber(num);
}
int read(string msg, int b, int e);
string readstr(string msg);
void playsound(string soundname, string musicalias);
void drawdices(int a, int b)
{
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "  ";
		for (auto j : dices[a - 1][i])
		{
			if (j == 'o')
				SetConsoleTextAttribute(hConsole, 9);
			else
				SetConsoleTextAttribute(hConsole, 14);
			cout << j;
		}
		cout << "\t";
		for (auto j : dices[b - 1][i])
		{
			if (j == 'o')
				SetConsoleTextAttribute(hConsole, 9);
			else
				SetConsoleTextAttribute(hConsole, 14);
			cout << j;
		}
		cout << "\n";
	}
	cout << endl;
}
int dicesanimation(int ochki, int stv, int num)
{
	if (sounds)
	{
		mciSendString(L"open \"audio/diseshake.mp3\" alias st", NULL, 0, NULL);
		mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
		//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
		mciSendString(L"play st from 0", NULL, 0, NULL);
	}

	
	random_device rd;
	int a, b;
	mt19937 mersenne(rd());
	//while (_kbhit()) _getch();
	for (int i = 50; i > 23; i--)
	{
		a = (unsigned int)mersenne() % 6 + 1;
		b = (unsigned int)mersenne() % 6 + 1;
		system("cls");
		drawdices(a, b);
		cout << endl << "  ОЧКИ           \t" << ochki << endl << "  СУММА СТАВКИ   \t" << stv << endl << "  СТАВКА НА ЧИСЛО\t" << num;
		Sleep(2000 / i);
		/*if (_kbhit() && i != 3)
		{
			i = 3;
		}*/
	}
	mciSendString(L"close st", NULL, 0, NULL);
	Sleep(300);
	return a + b;
	
}

string shifr(bool flag, string num = "0");

void startdices()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(hConsole, 14);
	if (music)
	{
		mciSendString(L"open \"audio/4.mp3\" alias gfour", NULL, 0, NULL);
		mciSendString(L"play gfour repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gthree volume to 100", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");
		string text = namepicd + "\n\n\n  Игра \"Кости\"\n\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		cout << namepicd;
		cout << "\n\n\n";
		cout << "  Игра \"Кости\"\n" << endl;
		//string temp = formnumber();
		//string text = namepic + "\n\n\n\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		//cout << namepic;
		//cout << "\n\n\n\n";
		//cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		int vibor = read(text, 1, 3);
	
		if (vibor == 1)
		{
			/*system("cls");
			cout << startgamepic << endl << endl;
			Sleep(1200);*/
			system("cls");

			int ochki = 100;
			bool f1 = true;
			string recordsmen = shifr(1);
			string name;
			unsigned long long bestscore;
			int t1 = 0;
			while (recordsmen[t1] != ' ' && t1 < recordsmen.length())
			{
				name += recordsmen[t1];
				t1++;
			}
			t1++;
			if (name == "НЕТ_ДАННЫХ")
				bestscore = 0;
			else
				bestscore = stoull(recordsmen.substr(t1));
			while (true)
			{

				system("cls");
				cout << endl;
				cout << "  Ваши очки:\n\n";
				drawnumber(ochki);
				cout << endl << endl;
				cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
				//cout << namepicd << "\n\n\n  Игра \"Кости\"\n"
				cout << "\n  МЕНЮ\n\n\t1 - ввести ставку\n\t2 - поставить всю сумму\n\t3 - поставить полсуммы\n\t4 - поставить четверь суммы\n\t5 - закончить игру\n\n  ";
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
					/*while ((ch = _getch()) != '\n')
					{
						str += ch;
					}*/
					if (str == "выход")
 						throw MyException();
					try
					{
						vibor = stoi(str);
						if (vibor > 0 && vibor < 6)
							//return vibor;
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

					//cout << namepicd + "\n\n\n  Игра \"Кости\"\n\n  Ведите ставку\n";
					cout << endl;
					cout << "  Ваши очки:\n\n";
					drawnumber(ochki);
					cout << endl << endl;
					cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
					//cout << namepicd << "\n\n\n  Игра \"Кости\"\n"
					cout << "\n  МЕНЮ\n\n\t1 - ввести ставку\n\t2 - поставить всю сумму\n\t3 - поставить полсуммы\n\t4 - поставить четверь суммы\n\t5 - закончить игру\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
					playsound("negative.mp3", "");
					//while (_kbhit()) _getch();
					tmp++;
					str = "";
				}
				/*string text = "\n  Ваши очки:\n\n" + "Рекорд:\t" + name + "\t" + (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) + "\n  МЕНЮ\n\n\t1 - ввести ставку\n\t2 - поставить всю сумму\n\t3 - поставить полсуммы\n\t4 - поставить четверь суммы\n\t5 - закончить игру\n\n  Похоже вы ввели что - то не то.Попробуйте еще разок.\n  ";*/
				tmp = 0;
				int stavka = 1;
				//cout << "Команды: 1 - ввести ставку, 2 - поставить всю сумму, , , ." << endl;
				//vibor = read(text, 1, 5);
				//cin >> vibor;
				//while (!cin.good() || (vibor != 1 && vibor != 2 && vibor != 3 && vibor != 4 && vibor != 5))
				//{
				//	if (tmp == 40)
				//		exit(0);
				//	if (tmp > 20)
				//		cout << "Это Вам не кликкер! До перегрева: " << 40 - tmp << endl;
				//	else if (tmp > 5)
				//		cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
				//	cin.clear();
				//	cin.ignore((std::numeric_limits<std::streamsize>::max) (), '\n');
				//	cout << "Не правильно! Команды: 1 - ввести ставку, 2 - поставить всю сумму, 3 - поставить полсуммы, 4 - поставить четверь суммы, 5 - закончить игру" << endl;
				//	cin >> vibor;
				//	tmp++;
				//}
				if (vibor == 1)
				{
					system("cls");
					cout << endl;
					cout << "  Ваши очки:\n\n";
					drawnumber(ochki);
					cout << endl << endl;
					cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
					cout << "  Введите ставку.\n\n";
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
						/*while ((ch = _getch()) != '\n')
						{
							str += ch;
						}*/
						if (str == "выход")
							throw MyException();
						try
						{
							stavka = stoi(str);
							if (stavka <= ochki && stavka != 0)
								//return vibor;
								break;
						}
						catch (...)
						{
							stavka = -1;
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
						cout << endl;
						cout << "  Ваши очки:\n\n";
						drawnumber(ochki);
						cout << endl << endl;
						cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
						//cout << namepicd + "\n\n\n  Игра \"Кости\"\n\n  Ведите ставку\n";
						if (stavka > ochki)
							cout << "  Не хватает очков. Введит меньшую ставку!\n  ";
						else if (stavka == 0)
							cout << "  Минимальная ставка 1. Введите большую ставку!\n  ";
						else
							cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  Введите ставку.\n";
						playsound("negative.mp3", "");
						//cout << "\n\n";
						//while (_kbhit()) _getch();
						tmp++;
						str = "";
					}
					//string text =Возмож";
					//cout << "Введите ставку!" << endl;

	/*				cin >> stavka;
					tmp = 0;
					while (!cin.good() || stavka > ochki || stavka == 0)
					{
						if (tmp == 40)
							exit(0);
						if (tmp > 20)
							cout << "Это Вам не кликкер! До перегрева: " << 40 - tmp << endl;
						else if (tmp > 5)
							cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
						cin.clear();
						cin.ignore((std::numeric_limits<std::streamsize>::max) (), '\n');
						
						cin >> stavka;
						tmp++;
					}*/
				}
				else if (vibor == 2)
					stavka = ochki;
				else if (vibor == 3 && ochki / 2 != 0)
					stavka = ochki / 2;
				else if (vibor == 4 && ochki / 4 != 0)
					stavka = ochki / 4;
				else if (vibor == 5)
				{
					cout << "  КОНЕЦ ИГРЫ\nВы заработали: " << ochki << endl;
					system("pause");
					break;
				}
				int num;
				system("cls");
				cout << endl;
				cout << "  Ваши очки:\n\n";
				drawnumber(ochki);
				cout << endl << endl;
				cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
				//cout << namepicd << "\n\n\n  Игра \"Кости\"\n"
				cout << "\n  Введите любое число в диапазоне от 2 до 12!\n\n  ";
				str = "";
				//char ch;
				//int vibor;
				tmp = 0;
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
					/*while ((ch = _getch()) != '\n')
					{
						str += ch;
					}*/
					if (str == "выход")
						throw MyException();
					try
					{
					num = stoi(str);
						if (num > 1 && num < 13)
							//return vibor;
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

					//cout << namepicd + "\n\n\n  Игра \"Кости\"\n\n  Ведите ставку\n";
					cout << endl;
					cout << "  Ваши очки:\n\n";
					drawnumber(ochki);
					cout << endl << endl;
					cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
					//cout << namepicd << "\n\n\n  Игра \"Кости\"\n"
					cout << "\n  Введите любое число в диапазоне от 2 до 12!\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
					playsound("negative.mp3", "");
					//while (_kbhit()) _getch();
					tmp++;
					str = "";
				}
				//cout << "Введите любое число в диапазоне от 2 до 12!" << endl;
				//int num;
				//cin >> num;
				//tmp = 0;
				//while (!cin.good() || num < 2 || num > 12)
				//{
				//	if (tmp == 40)
				//		exit(0);
				//	if (tmp > 20)
				//		cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				//	else if (tmp > 5)
				//		cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;

				//	cin.clear();
				//	cin.ignore((std::numeric_limits<std::streamsize>::max) (), '\n');
				//	cout << "Не правильно! Введите правильную команду! Введите любое число в диапазоне от 2 до 12!" << endl;
				//	cin >> num;
				//	tmp++;
				//}
				cout << "\n  Хорошо. Бросаем кубики!" << endl;
				Sleep(1000);
				int count = dicesanimation(ochki, stavka, num);
				cout << endl << endl;
				cout << "  В сумме на двух костях выпало: " << count << endl;
				Sleep(3500);
				if (num == count)
				{
					system("cls");
					playsound("windices.mp3", "gfour");
					/*if (music)
						mciSendString(L"setaudio gfour volume to 10", NULL, 0, NULL);*/
					if (music)
						mciSendString(L"pause gfour", NULL, 0, NULL);
					if(music)
					{
						mciSendString(L"open \"audio/klubnichka.mp3\" alias st", NULL, 0, NULL);
						mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
						//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
						mciSendString(L"play st from 0", NULL, 0, NULL);
					}
					
					//if(sounds)
					//{
					//	mciSendString(L"open \"audio/windices.mp3\" alias st", NULL, 0, NULL);
					//	mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
					//	//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
					//	mciSendString(L"play st from 0", NULL, 0, NULL);
					//}
				/*	if (music)
						mciSendString(L"pause gfour", NULL, 0, NULL);*/
					
					for (int i = 0; i < 10; i++)
					{
						cout << jackpot;
						Sleep(500);
						system("cls");
						Sleep(200);
					}
					cout << jackpot;
					cout << endl << endl;
					cout << "  Число на которое Вы ставили и число на кубиках СОВПАЛИ!\n  Поздравляем!\n  Вы сорвали джекпот!\n  Вы получаете в ЧЕТЫРЕ раза больше того, что ставили!\n  ";
					//cout << "  "; 
					if (music)
						mciSendString(L"setaudio gfour volume to 1000", NULL, 0, NULL); 
					system("pause");
					drawplusnumber(ochki, stavka * 4);
					cout << "\n  ";
					system("pause");
					ochki += stavka * 4;
					if (music)
					{
						mciSendString(L"close st", NULL, 0, NULL);
						mciSendString(L"play gfour", NULL, 0, NULL);
					}

				}
				else if (num < 7 && count < 7 || num > 7 && count > 7)
				{
					system("cls");
					cout << endl;
					cout << "  Ваши очки:\n\n";
					drawnumber(ochki);
					cout << endl << endl;
					cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
					//system("cls");
					//cout << winpic << endl << endl;
					
					cout << "\n  ВЫИГРЫШ.\n";
					cout << "  Вы поставили на число " << num << endl;
					cout << "  На кубиках выпало число " << count << endl;
					cout << "  Оба числа " << (num < 7 ? "меньше" : "больше") << " 7" << endl << endl;
					playsound("win.mp3", "gfour");
					cout << "  "; system("pause");
					drawplusnumber(ochki, stavka);

					ochki += stavka;
				}
				else
				{
					system("cls");
					cout << endl;
					cout << "  Ваши очки:\n\n";
					drawnumber(ochki);
					cout << endl << endl;
					cout << "  Рекорд:\t" << name << "\t" << (name == "НЕТ_ДАННЫХ" ? "" : to_string(bestscore)) << endl;
					//system("cls");
					//cout << winpic << endl << endl;

					cout << "\n  ПРОИГРЫШ.\n";
					//system("cls");
					//cout << losepic << endl << endl;
					cout << "\tВы поставили на число " << num << endl;
					cout << "\tНа кубиках выпало число " << count << endl;
					cout << "\tВаше число " << (num < 7 ? "меньше" : num > 7 ? "больше" : "равно") << " 7" << endl;
					cout << "\tА число на кубиках " << (count < 7 ? "меньше" : count > 7 ? "больше" : "равно") << " 7" << endl << endl;
					playsound("sadtrom.mp3", "gfour");
					cout << "  "; system("pause");
					drawminusnumber(ochki, stavka);
					ochki -= stavka;
				}
				if (ochki == 0)
				{
					cout << "\n\tУ ВАС ЗАКОНЧИЛИСЬ ОЧКИ.\n\n";
					cout << "\tИгра окончена.\n\n";
					system("pause");
					break;

				}
				if (ochki > bestscore)
				{
					cout << endl << endl;
					if (f1)
					{
						cout << "\tПОЗДРАВЛЯЕМ! ВЫ УСТАНОВИЛИ НОВЫЙ РЕКОРД!\n\n";
						cout << "\tВедите ваше имя: ";
						cin >> name;
						bestscore = ochki;
						shifr(0, name + " " + to_string(ochki));
						cout << "\tВаш рекорд сохранен!" << endl << endl;
						f1 = 0;
					}
					else
					{
						bestscore = ochki;
						shifr(0, name + " " + to_string(ochki));
						cout << "\tПОЗДРАВЛЯЕМ! ВЫ ПОБИЛИ СВОЙ РЕКОРД!" << endl;
					}
					system("pause");
				}
			}
		}
		else if (vibor == 2)
		{
			system("cls");
			//string temp = formnumber();
			cout << namepicd;
			cout << "\n\n\n";
			cout << "  Игра \"Кости\"\n" << endl;
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  В игре Вам надо назвать любое число в диапазоне от 2 до 12 и сделать ставку.\n  Затем бросаются два виртуальных кубика.\n\n  *\tЕсли сумма выпавших цифр меньше 7 и Вы задумали число меньше 7, то Вы выигрываете сделанную ставку.\n  *\tЕсли сумма выпавших цифр больше 7 и Вы задумали число больше 7, Вы также выигрываете сделанную ставку.\n  *\tЕсли Вы угадали сумму цифр, то Вы получаете в 4 раза больше очков, чем сделанная ставка.\n  *\tВо всех остальных случаях ставка считается проиграной.\n\n  В начале игры Вам выдается 100 очков.\n  Игра продолжается до тех пор, пока у Вас есть очки и Вы можете сделать ставку, или пока Вы не захотите уйти.\n  Все просто.\n  ";
			system("pause");
		}
		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gfour", NULL, 0, NULL);
}
