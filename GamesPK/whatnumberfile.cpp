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
string formnumber()
{
	string result;
	random_device rd;
	mt19937 mersenne(rd());
	unsigned int num = (unsigned int)mersenne() % 1000;
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
	result += "\n";
	for (int i = 0; i < 5; i++)
	{
		result += "  ";
		for (int j = digits.size() - 1; j >= 0; j--)
		{
			result += digpic[digits[j]][i] + " ";
		}
		result += "  " + digpic[10][i] + "\n";
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
	string text = temp + "\n\n\n  Игра \"Угадай число\"\n\n  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
	cout << temp;
	cout << "\n\n\n";
	cout << "  Игра \"Угадай число\"\n" << endl;
	cout << "  Сейчас случайным образом будет выбрано, кто будет загадывать число. \n" << endl;
	Sleep(1000);
	int c = (unsigned int)mersenne() % 2;
	int number;
	if (c == 0)
	{
		cout << "\n  Загадывать число будет компьютер.\n  ";
		number = 1 + (unsigned int)mersenne() % 1000;
		system("pause");
		system("cls");
		cout << "\n  Компьютер загадал число от 1 до 1000." << endl;
		int popit = 10;
		int temp;
		string voprosi = "";
		while (popit > 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  Введите число, для которого Вы хотите узнать больше ли оно загаданного или нет.\n  Если вы уже знаете число и хотите ввести ответ, то введите 0." << endl;
			temp = read("\n" + voprosi + "\n  Введите число, для которого Вы хотите узнать больше ли оно загаданного или нет.\n  Если вы уже знаете число и хотите ввести ответ, то введите 0.\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 0, 1000);
			if (temp == 0)
			{
				system("cls");
				cout << "\n" << voprosi << "\n  Введите загаданное число." << endl;
				temp = read("\n" + voprosi + "\n  Введите загаданное число. \n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 1000);
				if (temp == number)
				{
					cout << "\n  Вы выиграли! (Количество ходов: " << count << ").\n  ";
					playsound("win.mp3", "gone");
				}
				else
				{
					cout << "\n  УВЫ. Вы проиграли :( Число было: " << number << "\n  ";
					playsound("sadtrom.mp3", "gone");					
				}
				break;
			}
			voprosi += "  Ответ на вопрос номер " + to_string(++count) + ": ";
			cout << "  Ответ на вопрос номер " << count << ": ";
			if (temp < number)
			{
				voprosi += "  " + to_string(temp) + " меньше загаданного числа\n";
				cout << "  " << temp << " меньше загаданного числа" << endl;
			}

			else
			{
				voprosi += "  " + to_string(temp) + " не меньше загаданного числа (т.е. либо больше, либо равно)\n";
				cout << "  " << temp << " не меньше загаданного числа (т.е. либо больше, либо равно)" << endl;
			}
			popit--;
		}
		if (popit == 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  Введите загаданное число." << endl;
			temp = read("\n" + voprosi + "\n  Введите загаданное число. \n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n", 1, 1000);
			if (temp == number)
			{
				cout << "\n  Вы выиграли! (Количество ходов: " << count << ").\n  ";
				playsound("win.mp3", "gone");
			}
			else
			{
				cout << "\n  УВЫ. Вы проиграли :( Число было: " << number << "\n  ";
				playsound("sadtrom.mp3", "gone");
			}
		}
		system("pause");
	}
	else
	{
		string voprosi = "";
		cout << "\n  Загадывать число будете вы.\n  ";
		system("pause");
		system("cls");
		int vib;
		cout << "\n  Загадайте число от 1 до 1000 и введите его.\n";
		number = read("\n  Загадайте число от 1 до 1000 и введите его.\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 1000);
		int popit = 10;
		int dv = 512;
		int num = dv;
		voprosi += "  Вы ввели число: " + to_string(number) + "\n";
		while (popit > 0)
		{

			cout << "  Вопрос номер " << ++count << ": Ваше число больше " << num << "? " << "Введите: 1 - да, 2 - нет" << endl;
			vib = read(voprosi + "\n  Вопрос номер " + to_string(count) + ": Ваше число больше " + to_string(num) + "?\n" + "  Введите: 1 - да, 2 - нет\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 2);
			voprosi += "  Вопрос номер " + to_string(count) + ": Ваше число больше " + to_string(num) + "? ";
			dv = dv / 2;
			switch (vib)
			{
			case 1:
				if (num == 1000 || number <= num)
				{
					system("cls");
					cout << "\n  А вы обманщик! Я так не играю!\n  ";
					playsound("obman.mp3", "gone");
					system("pause");
					return;
				}
				voprosi += "Ваш ответ: да.\n";
				while (num + dv > 1000)
					dv /= 2;
				num += dv;
				break;
			case 2:
				if (num == 1000 || number > num)
				{
					system("cls");
					cout << "\n  А вы обманщик! Я так не играю!\n  ";
					playsound("obman.mp3", "gone");
					system("pause");
					return;
				}
				voprosi += "Ваш ответ: нет.\n";
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
				cout << voprosi << "\n  Ваше число: " << num << "\n  ";
				system("pause");
				return;
			}
			popit--;
		}
		if (vib == 1)
			num++;
		cout << voprosi << "\n  Ваше число: " << num << "\n  ";
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
	cout << "  Игра \"Угадай число\"\n" << endl;
	cout << "  Перед тем как начать игру, небоходимо выбрать, кто будет загадывать число.\n  Для этого вам нужно ввести ваши имена." << endl;
	string name1, name2;
	cout << endl << "  Первый игрок введите свое имя.\t";
	while (_kbhit()) _getch();
	name1 = readstr(tempi + "\n\n\n" + "  Игра \"Угадай число\"\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Первый игрок введите свое имя.\t");
	cout << endl << "  Здравствуйте, " << name1 << ". Интересное имя.\n" << endl;
	Sleep(1000);
	system("cls");
	tempi = formnumber();
	cout << tempi;
	cout << "\n\n\n";
	cout << "  Игра \"Угадай число\"\n" << endl;
	cout << "  Второй игрок введите свое имя!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(tempi + "\n\n\n" + "  Игра \"Угадай число\"\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Второй игрок введите свое имя.\t");
	cout << endl << "  Приветствую, " << name2 << ". Какое замечательно имя!\n\n";
	Sleep(1000);

	while (true)
	{
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  Игроки, сейчас случайным образом будет выбрано, кто будет загадывать число.\n  А кто отгадывать.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  Число загадывает игрок " << (temp ? name1 : name2) << endl;
		int number;

		cout << "\n  Игрок " << (!temp ? name1 : name2) << " должен отвернуться.\n\n  ";
		system("pause");
		system("cls");
		cout << "\n  Игрок " << (temp ? name1 : name2) << " загадайте число от 1 до 1000 и введите его." << endl;
		number = read("\n  Игрок " + (temp ? name1 : name2) + " загадайте число от 1 до 1000 и введите его.\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 1000);
		system("cls");
		cout << "\n  Теперь игрок " << (!temp ? name1 : name2) << " может начинать отгадывать. \n\n  ";
		system("pause");
		int vib;
		int popit = 10;
		while (popit > 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  Введите число, для которого Вы хотите узнать больше ли оно загаданного или нет.\n  Если вы уже знаете число и хотите ввести ответ, то введите 0." << endl;
			temp = read("\n" + voprosi + "\n  Введите число, для которого Вы хотите узнать больше ли оно загаданного или нет.\n  Если вы уже знаете число и хотите ввести ответ, то введите 0.\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 0, 1000);

			if (temp == 0)
			{
				system("cls");
				cout << "\n" << voprosi << "\n  Введите загаданное число." << endl;
				temp = read("\n" + voprosi + "\n  Введите загаданное число. \n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 1000);
				if (temp == number)
				{
					cout << "\n  Игрок " << (temp ? name1 : name2) << ", Вы выиграли!(Количество ходов: " << count << ").\n  ";
					playsound("win.mp3", "gone");
				}
				else
				{
					cout << "\n  Игрок " << (temp ? name1 : name2) << ", Вы проиграли :( Число было: " << number << "\n  ";
					playsound("sadtrom.mp3", "gone");
				}

				break;
			}
			voprosi += "  Ответ на вопрос номер " + to_string(++count) + ": ";
			cout << "  Ответ на вопрос номер " << count << ": ";
			if (temp < number)
			{
				voprosi += "  " + to_string(temp) + " меньше загаданного числа\n";
				cout << "  " << temp << " меньше загаданного числа" << endl;
			}

			else
			{
				voprosi += "  " + to_string(temp) + " не меньше загаданного числа (т.е. либо больше, либо равно)\n";
				cout << "  " << temp << " не меньше загаданного числа (т.е. либо больше, либо равно)" << endl;
			}
			popit--;
		}
		if (popit == 0)
		{
			system("cls");
			cout << "\n" + voprosi << "\n  Введите загаданное число." << endl;
			temp = read("\n" + voprosi + "\n  Введите загаданное число. \n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n", 1, 1000);
			if (temp == number)
			{
				cout << "\n  Игрок " << (temp ? name1 : name2) << ", Вы выиграли! (Количество ходов: " << count << ").\n  ";
				playsound("win.mp3", "gone");
			}
			else
			{
				cout << "\n  Игрок " << (temp ? name1 : name2) << ", Вы проиграли :( Число было: " << number << "\n  ";
				playsound("sadtrom.mp3", "gone");
			}
		}
		system("cls");
		tempi = formnumber();
		cout << tempi;
		cout << "\n\n\n";
		cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n";
		string text = tempi + "\n\n\n  Игра \"Угадай число\"\n\n  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
	}

	while (true)
	{
		system("cls");
		string temp = formnumber();
		string text = temp + "\n\n\n  Игра \"Угадай число\"\n\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		cout << temp;
		cout << "\n\n\n";
		cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string temp = formnumber();
				string text = temp + "\n\n\n  Игра \"Угадай число\"\n\n  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
				cout << temp;
				cout << "\n\n\n";
				cout << "  Игра \"Угадай число\"\n" << endl;
				cout << "  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n";
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
			cout << "  Игра \"Угадай число\"\n" << endl;
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  В игру играют два игрока.\n  Один загадывает число от 1 до 1000, второй отгадывает.\n  Для этого можно задавать до 10 вопросов.\n  В вопросе можно узнавать является ли загаданное число больше предполагаемого.\n  Ответ можно дать и раньше 10 вопросов.\n  Если второй игрок отгадал число, то он считается выигравшим, если не отгадал, то проигравшим.\n  Кто загадывает, а кто отгадывает выбирается случайным образом.\n  Все просто.\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gone", NULL, 0, NULL);
}