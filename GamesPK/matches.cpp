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
      !!         МОЙ ХОД         !!  !
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
	string text = namepic + "\n\n\n\n  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
	cout << namepic;
	cout << "\n\n\n" << endl;
	cout << "  Сейчас случайным образом будет выбрано, кому повезло, и кто будет ходить первым. \n" << endl;
	int temp = (unsigned int)mersenne() % 2;
	Sleep(1000);
	if (temp)
	{
		cout << "  К моему сожалению, первыми ходите Вы...\n  ";
		system("pause");
	}
	else
	{
		cout << "\n  УРА! Я ХОЖУ ПЕРВЫМ!\n  ";
		system("pause");
		system("cls");
		cout << comppic;
		cout << endl;
		cout << "  Что же мне взять..." << endl;
		Sleep(2000);
		cout << "  Может одну..." << endl;
		Sleep(2000);
		cout << "  Две..." << endl;
		Sleep(2000);
		cout << "  А может четыре?..." << endl;
		Sleep(2000);
		random_device rd;
		mt19937 mersenne(rd());
		system("cls");
		cout << comppic;
		if ((unsigned int)mersenne() % 2)
		{
			i -= 4;
			cout << "\n Я возьму четыре спички!" << endl;
		}
		else
		{
			i -= 1;
			cout << "\n Я возьму одну спичку." << endl;
		}
		Sleep(1500);
	}
	int vibor;
	while (true)
	{
		system("cls");
		drawmatches(i);
		cout << endl << endl;
		cout << "  ОСТАЛОСЬ СПИЧЕК (если лень считать): " << i << endl;
		cout << "  Ваша очередь брать спички: 1 - взять одну, 2 - взять две, 4 - взять четыре." << endl;
		//cout << "\n(Введите \"выход\" чтобы выйти)\n";
		string str = "";
		char ch;
		int vibor = -1;
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
				cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
			else if (tmp > 5)
				cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
			//cout << msg;
			
		//	//while (_kbhit()) _getch();
		//	tmp++;
		//	str = "";
		//}
			//cout << msg;
			drawmatches(i);
			cout << endl << endl;
			cout << "  ОСТАЛОСЬ СПИЧЕК (если лень считать): " << i << endl;
			cout << "  Ваша очередь брать спички: 1 - взять одну, 2 - взять две, 4 - взять четыре.\n";
			if (vibor == 4 && i < 4)
			{
				cout << "  Нельзя взять 4 спички, если есть всего " << i << ". Подумайте об этом.\n  ";
			}
			else if (vibor == 2 && i < 2)
			{
				cout << "  Нельзя взять 2 спички, если есть всего " << i << ". Подумайте об этом.\n  ";
			}
			else
				cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
			tmp++;
			str = "";
			playsound("negative.mp3", "");
		}


		//vibor = read("  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ", 1, 4)
		//while (_kbhit()) _getch();
		//cin >> vibor;
		//int tmp = 0;
		//while (!cin.good() || (vibor != 1 && vibor != 2 && vibor != 4) || (vibor == 4 && i < 4) || (vibor == 2 && i < 2))
		//{
		//	if (vibor == 4 && i < 4)
		//	{
		//		cout << "Нельзя взять 4 спички, если есть всего " << i << ". Подумай об этом.\n  ";
		//	}
		//	else if (vibor == 2 && i < 2)
		//	{
		//		cout << "Нельзя взять 2 спички, если есть всего " << i << ". Подумай об этом.\n  ";
		//	}
		//	else
		//	{
		//		if (tmp == 40)
		//			exit(0);
		//		if (tmp > 20)
		//			cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
		//		else if (tmp > 5)
		//			cout << "Ну как так-то? Ты не можешь попасть по кнопке уже вот столько раз: " << tmp << endl;

		//		cin.clear();
		//		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		//		cout << "ПОВТОРЯЮ, ВВЕДИ: 1 - взять одну, 2 - взять две, 4 - взять четыре." << endl;
		//	}
		//	cin >> vibor;
		//	tmp++;
		//}
		i -= vibor;
		if (i <= 0)
		{
			cout << "  ПОЗДРАВЛЯЮ. ВЫ ПОБЕДИЛ. РАДУЙТЕСЬ. ВЕСЕЛИТЕСЬ.\n  ";
			playsound("win.mp3", "gthree");
			system("pause");
			//Sleep(4000);
			return;
		}
		cout << "  Хорошо." << endl;
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
			cout << "  Я возьму две спички." << endl;
			Sleep(5000);
			cout << "  ХА. Обманул. Я забираю все оставшиеся спички." << endl;
			Sleep(2000);
			cout << "  Вы проиграли." << endl;
			Sleep(2000);
			cout << "  Но не растраивайтесь." << endl;
			Sleep(2000);
			cout << "  Все когда-нибудь случается." << endl;
			Sleep(2000);
			cout << "  Может и вы победите." << endl;
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
				cout << "  Я возьму целых четыре спички!" << endl;
			}
			else if (cs % 3 == 1 || i < 3)
			{
				i -= 1;
				cout << "  Я возьму всего одну спичку." << endl;
			}
			else if (cs % 3 == 2 || i == 3)
			{
				cout << "  Пожалуй, я возьму всего одну спичку." << endl;
				i--;
			}
			break;
		case 1:

			if ((unsigned int)mersenned() % 2 && i != 1)
			{
				i -= 4;
				cout << "  Я возьму целых четыре спички!" << endl;
			}
			else
			{
				i -= 1;
				cout << "  Я возьму всего одну спичку." << endl;
			}
			break;
		case 2:
			i -= 2;
			cout << "  Я возьму две спички." << endl;
			break;
		default:
			break;
		}
		Sleep(1500);
		if (i <= 0)
		{
			cout << "  ВЫ ПРОИГРАЛИ!\n  ";
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
	cout << "  Перед тем как начать игру, небоходимо выбрать, кто будет загадывать число.\n  Для этого вам нужно ввести ваши имена." << endl;
	string name1, name2;
	//Sleep(1000);
	cout << endl << "  Первый игрок введите свое имя.\t";
	while (_kbhit()) _getch();
	name1 = readstr(namepic + "\n\n\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Первый игрок введите свое имя.\t");
	cout << endl << "  Здравствуйте, " << name1 << ". Интересное имя.\n" << endl;
	Sleep(1000);
	system("cls");
	cout << namepic;
	cout << "\n\n\n" << endl;
	cout << "  Второй игрок введите свое имя!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(namepic + "\n\n\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Второй игрок введите свое имя.\t");
	cout << endl << "  Приветствую, " << name2 << ". Какое замечательно имя!\n\n";
	Sleep(1000);
	while (true)
	{
		int i = 25;
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  Игроки, сейчас случайным образом будет выбрано, кто будет ходить первым.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  Мои поздравления, игрок " << (temp ? name1 : name2) << ". Вы ходите первыми.\n  ";
		system("pause");
		int vibor;
		while (true)
		{
			system("cls");
			drawmatches(i);
			cout << endl << endl;
			cout << "  ОСТАЛОСЬ СПИЧЕК (если лень считать): " << i << endl;
			cout << "  Игрок " << (temp ? name1 : name2) << ", Ваша очередь брать спички: 1 - взять одну, 2 - взять две, 4 - взять четыре." << endl;
			//cout << "\n(Введите \"выход\" чтобы выйти)\n";
			string str = "";
			char ch;
			int vibor = -1;
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
					cout << "Это не кликкер! До перегрева: " << 40 - tmp << endl;
				else if (tmp > 5)
					cout << "Ну как так-то? Вы не можете попасть по кнопке уже вот столько раз: " << tmp << endl;
				drawmatches(i);
				cout << endl << endl;
				cout << "  ОСТАЛОСЬ СПИЧЕК (если лень считать): " << i << endl;
				cout << "  Игрок " << (temp ? name1 : name2) << ", Ваша очередь брать спички: 1 - взять одну, 2 - взять две, 4 - взять четыре.\n";
				if (vibor == 4 && i < 4)
				{
					cout << "  Нельзя взять 4 спички, если есть всего " << i << ". Подумайте об этом.\n  ";
				}
				else if (vibor == 2 && i < 2)
				{
					cout << "  Нельзя взять 2 спички, если есть всего " << i << ". Подумайте об этом.\n  ";
				}
				else
					cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
				tmp++;
				str = "";
				playsound("negative.mp3", "");
			}
			i -= vibor;
			if (i <= 0)
			{
				cout << "  ПОЗДРАВЛЯЮ! ИГРОК " << (temp ? name1 : name2) << " ПОБЕДИЛ.\n  ";
				playsound("win.mp3", "gthree");
				system("pause");
				break;
			}
			
			cout << "  Хорошо." << endl;
			temp++;
			temp %= 2;
			Sleep(1000);
		}
		
		system("cls");
		cout << namepic;
		cout << "\n\n\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n";
		string text = namepic + "\n\n\n\n  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
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
		string text = namepic + "\n\n\n\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		cout << namepic;
		cout << "\n\n\n\n";
		//cout << "  Игра \"Угадай число\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string text = namepic + "\n\n\n\n  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
				cout << namepic;
				cout << "\n\n\n" << endl;
				cout << "  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n";
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
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  На виртуальном столе лежат 25 спичек.\n  Играющие по очереди могут взять 1, 2 или 4 спички.\n  Кто не может сделать ход (спичек не осталось), проигрывает.\n  Все просто.\n\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gthree", NULL, 0, NULL);
}