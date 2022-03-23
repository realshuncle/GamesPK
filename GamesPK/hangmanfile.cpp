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

using namespace std;
extern HANDLE  hConsole;

string namepics[8] =
{
		R"(88          
88          
88          
88,dPPYba,  
88P'    "8a 
88       88 
88       88 
88       88 
            
            )",
	R"(                      
                      
                      
            ,adPPYYba,
            ""     `Y8
            ,adPPPPP88
            88,    ,88
            `"8bbdP"Y8
                      
                      )",
	R"(                                  
                                  
                                  
                       8b,dPPYba, 
                       88P'   `"8a
                       88       88
                       88       88
                       88       88
                                  
                                  )",
	R"(                                               
                                               
                                               
                                    ,adPPYb,d8 
                                   a8"    `Y88 
                                   8b       88 
                                   "8a,   ,d88 
                                    `"YbbdP"Y8 
                                    aa,    ,88 
                                     "Y8bbdP"   )",
	R"(                                                                 
                                                                 
                                                                 
                                               88,dPYba,,adPYba, 
                                               88P'   "88"    "8a
                                               88      88      88
                                               88      88      88
                                               88      88      88
                                                                 
                                                                 )",
	R"(                                                                            
                                                                            
                                                                            
                                                                  ,adPPYYba,
                                                                  ""     `Y8
                                                                  ,adPPPPP88
                                                                  88,    ,88
                                                                  `"8bbdP"Y8
                                                                            
                                                                            )",
	R"(                                                                                        
                                                                                        
                                                                                        
                                                                             8b,dPPYba, 
                                                                             88P'   `"8a
                                                                             88       88
                                                                             88       88
                                                                             88       88
                                                                                        
                                                                                        )",
};
string namepichm =
R"(
  88                                                                                      
  88                                                                                      
  88                                                                                      
  88,dPPYba,  ,adPPYYba, 8b,dPPYba,   ,adPPYb,d8 88,dPYba,,adPYba,  ,adPPYYba, 8b,dPPYba, 
  88P'    "8a ""     `Y8 88P'   `"8a a8"    `Y88 88P'   "88"    "8a ""     `Y8 88P'   `"8a
  88       88 ,adPPPPP88 88       88 8b       88 88      88      88 ,adPPPPP88 88       88
  88       88 88,    ,88 88       88 "8a,   ,d88 88      88      88 88,    ,88 88       88
  88       88 `"8bbdP"Y8 88       88  `"YbbdP"Y8 88      88      88 `"8bbdP"Y8 88       88
                                      aa,    ,88                                          
                                       "Y8bbdP"                                           )";
string hangpics[16][13] =
{
	{
		  "-------------------",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "-------------------",
	},
	{
		  "-------------------",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|                 |",
		  "|  |         |    |",
		  "-------------------",
	},
	{
		 "-------------------",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|                 |",
		 "|  __ ________    |",
		 "|  |         |    |",
		 "-------------------"
	},
	{
		"-------------------",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{			  
		"-------------------",
		"|                 |",
		"|                 |",
		"|                 |",
		"|                 |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|                 |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------"
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/           |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (   )   |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |      |     |",
		"|    |      |     |",
		"|    |      |     |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |     _|_    |",
		"|    |      |     |",
		"|    |      |     |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |     _|_    |",
		"|    |    / |     |",
		"|    |      |     |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------"
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |     _|_    |",
		"|    |    / | \\   |",
		"|    |      |     |",
		"|    |            |",
		"|    |            |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (0_0)   |",
		"|    |     _|_    |",
		"|    |    / | \\   |",
		"|    |      |     |",
		"|    |     /      |",
		"|    |    /       |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	},
	{
		"-------------------",
		"|    ___________  |",
		"|    |/     |     |",
		"|    |    (x_x)   |",
		"|    |     _|_    |",
		"|    |    / | \\   |",
		"|    |      |     |",
		"|    |     / \\    |",
		"|    |    /   \\   |",
		"|    |            |",
		"|  __|________    |",
		"|  |         |    |",
		"-------------------",
	}
};
set<string> set_words;
class MyException {};
set<string> set_words_in_arr;
extern bool music;
extern bool sounds;
int read(string msg, int b, int e);
void playsound(string soundname, string musicalias);

string arr_words[18] = {
"АРБУЗ",
"АВТОКРАТИЯ",
"ТОЛЕРАНТНОСТЬ",
"ЭКСГУМАЦИЯ",
"ЛИБЕРАЛИЗМ",
"ЭКСПОНАТ",
"ПЫШНОСТЬ",
"СКАБРЁЗНОСТЬ",
"ШАЛОВЛИВОСТЬ",
"ЭКСПОЗИЦИЯ",
"ИНДУЛЬГЕНЦИЯ",
"ДЕМУЛЬТИПЛИКАТОР",
"НАПЫЩЕННОСТЬ",
"ЭПИТАФИЯ",
"БАРБЕКЮ",
"ЭНЦЕФАЛОПАТИЯ",
"ПАРАШЮТИСТ",
"ГИДРОКАРБОНАТ" };

string TakeWord()
{
	string word;
	fstream in("words.txt");
	int size = 0;
	if (!in)
	{
		cout << endl << endl << "  Проблема с открытием файла со словами. Отсутствует файл: words.txt" << endl;
		cout << "  Будет использоваться встроенный словарь.\n\n  ";
		system("pause");
		if (set_words_in_arr.size() == 18)
		{
			set_words_in_arr.clear();
		}
		random_device rd;
		mt19937 mersenne(rd());
		int temp = mersenne() % 18;
		while (true)
		{
			if (temp == 18)
				temp = 0;
			word = arr_words[temp];
			if (set_words_in_arr.find(word) == set_words_in_arr.end())
			{
				set_words_in_arr.insert(word);
				return word;
			}
			temp++;
		}
	}
	while (in)
	{
		getline(in, word);
		size++;
	}
	string temp;
	in.clear();
	in.seekg(0);
	random_device rd;
	mt19937 mersenne(rd());
	int num_tr = mersenne() % size;
	for (int i = 0; i < num_tr; i++)
	{
		getline(in, word);
	}
	if (set_words.size() == size - 1)
	{
		set_words.clear();
	}

	while (true)
	{
		if (!in)
		{
			in.clear();
			in.seekg(0);
		}
		getline(in, word);
		if (set_words.find(word) == set_words.end())
		{
			in.close();
			set_words.insert(word);
			return word;
		}
	}
}

bool ToUpperCase(string& word)
{
	map <char, char> let =
	{
		{'а', 'А'},
		{'б', 'Б'},
		{'в', 'В'},
		{'г', 'Г'},
		{'д', 'Д'},
		{'ж', 'Ж'},
		{'е', 'Е'},
		{'ё', 'Ё'},
		{'ж', 'Ж'},
		{'з', 'З'},
		{'и', 'И'},
		{'й', 'Й'},
		{'к', 'К'},
		{'л', 'Л'},
		{'м', 'М'},
		{'н', 'Н'},
		{'о', 'О'},
		{'п', 'П'},
		{'р', 'Р'},
		{'с', 'С'},
		{'т', 'Т'},
		{'у', 'У'},
		{'ф', 'Ф'},
		{'х', 'Х'},
		{'ц', 'Ц'},
		{'ч', 'Ч'},
		{'ш', 'Ш'},
		{'щ', 'Щ'},
		{'ь', 'Ь'},
		{'ы', 'Ы'},
		{'ъ', 'Ъ'},
		{'э', 'Э'},
		{'ю', 'Ю'},
		{'я', 'Я'},
		{'А', 'А'},
		{'Б', 'Б'},
		{'В', 'В'},
		{'Г', 'Г'},
		{'Д', 'Д'},
		{'Ж', 'Ж'},
		{'Е', 'Е'},
		{'Ё', 'Ё'},
		{'Ж', 'Ж'},
		{'З', 'З'},
		{'И', 'И'},
		{'Й', 'Й'},
		{'К', 'К'},
		{'Л', 'Л'},
		{'М', 'М'},
		{'Н', 'Н'},
		{'О', 'О'},
		{'П', 'П'},
		{'Р', 'Р'},
		{'С', 'С'},
		{'Т', 'Т'},
		{'У', 'У'},
		{'Ф', 'Ф'},
		{'Х', 'Х'},
		{'Ц', 'Ц'},
		{'Ч', 'Ч'},
		{'Ш', 'Ш'},
		{'Щ', 'Щ'},
		{'Ь', 'Ь'},
		{'Ы', 'Ы'},
		{'Ъ', 'Ъ'},
		{'Э', 'Э'},
		{'Ю', 'Ю'},
		{'Я', 'Я'},
	};
	string result = "";
	for (int i = 0; i < word.length(); i++)
	{
		if (let.find(word[i]) == let.end())
			return 0;
		result += let[word[i]];
	}
	word = result;
	return 1;
}

void hangman()
{
	vector<char> letttt = {
'А',
'Б',
'В',
'Г',
'Д',
'Е',
'Ё',
'Ж',
'З',
'И',
'Й',
'К',
'Л',
'М',
'Н',
'О',
'П',
'Р',
'С',
'Т',
'У',
'Ф',
'Х',
'Ц',
'Ч',
'Ш',
'Щ',
'Ь',
'Ы',
'Ъ',
'Э',
'Ю',
'Я',
	};
	system("cls");
	while (_kbhit()) _getch();
	string word = TakeWord();
	string word_p = "";
	if (!ToUpperCase(word))
	{
		cout << endl << "  Проблема с выбранным словом.\n  Строка \"" << word << "\" должна быть составлена только из букв русского алфавита.\n  ";
		system("pause");
		return;
	}
	set <char> letters;
	set <char> cletters;
	set <char> mistakes;
	for (int i = 0; i < word.size(); i++)
	{
		letters.insert(word[i]);
		word_p += "_ ";
	}

	for (int i = 15; i > 0;)
	{
		system("cls");
		string text = "";
		int tp = 0;
		for (int j = 0; j < 13; j++)
		{
			text += "  " + hangpics[15 - i][j];
			cout << "  " << hangpics[15 - i][j];
			if (j >= 1 && j <= 3)
			{
				text += "\t";
				cout << "\t";
				for (int k = 0; k < 11; k++)
				{
					if (cletters.find(letttt[(j - 1) * 11 + k]) == cletters.end())
					{
						text = text + letttt[(j - 1) * 11 + k] + " ";
						cout << letttt[(j - 1) * 11 + k] << " ";
					}
					else
					{
						text += "_ ";
						cout << "_ ";
					}
				}
			}
			if (j != 12)
			{
				text += "\n";
				cout << endl;
			}

		}
		text += "\t\tСлово: " + word_p + "\n\n  Ошибки (" + to_string(15 - i) + "): ";
		cout << "\t\tСлово: " << word_p << endl;
		cout << "\n  Ошибки (" << 15 - i << "): ";
		for (auto i : mistakes)
		{
			cout << i << " ";
			text = text + i + " ";
		}
		text += "\n\n";
		cout << endl << endl;
		if (letters.size() == 0)
		{
			cout << "  ВЫ ПОБЕДИЛИ!\n  ";
			playsound("win.mp3", "gtwo");
			system("pause");
			while (_kbhit()) _getch();
			return;
		}


		string str = "";
		char ch;
		int vibor;
		int tmp = 0;
		while (_kbhit()) _getch();
		
		text += "  Введите букву, которая может входить в слово. Попыток осталось: " + to_string(i) + "\n";
		cout << "  Введите букву, которая может входить в слово. Попыток осталось: " << i << endl;
		string letterstr = "";
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
				if (!(!ToUpperCase(str) || str.size() != 1 || cletters.find(str[0]) != cletters.end()))

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
					
			cout << text;
			if (str.size() != 1)
				cout << "  Что-то пошло не так. Возможно вы ввели несколько символов. Введите букву еще разок." << endl;
			else if (cletters.find(str[0]) != cletters.end())
				cout << "  Что-то пошло не так. Возможно вы ввели букву, которую уже вводили. Введите букву еще разок." << endl;
			else if (!ToUpperCase(str))
				cout << "  Что-то пошло не так. Возможно вы ввели цифру, какой-нибудь знак или иной символ. Введите букву еще разок." << endl;
			playsound("negative.mp3", "");
			tmp++;
			str = "";
		}
		letterstr = str;
		char letter = letterstr[0];
		if (letters.find(letter) == letters.end())
		{
			cout << "  Данной буквы в слове нет. Увы." << endl;
			if (sounds)
			{
				Sleep(100);
				mciSendString(L"open \"audio/hangmanfalse.mp3\" alias st", NULL, 0, NULL);
				mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
				mciSendString(L"play st from 0 wait", NULL, 0, NULL);
				mciSendString(L"close st", NULL, 0, NULL);
			}
			
			i--;
			cletters.insert(letter);
			mistakes.insert(letter);
		}
		else
		{
			cout << "  Ура! Такая буква есть в слове." << endl;
			if (sounds)
			{
				Sleep(100);
				mciSendString(L"open \"audio/hangmantrue.mp3\" alias st", NULL, 0, NULL);
				mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
				mciSendString(L"play st from 0 wait", NULL, 0, NULL);
				mciSendString(L"close st", NULL, 0, NULL);
			}
			cletters.insert(letter);
			letters.erase(letter);
			for (int i = 0; i < word.size(); i++)
			{
				if (word[i] == letter)
					word_p = word_p.substr(0, i * 2) + letter + word_p.substr(i * 2 + 1);
			}
		}
		while (_kbhit()) _getch();
	}
	system("cls");
	for (int j = 0; j < 13; j++)
	{
		cout << "  " << hangpics[15][j];
		if (j >= 1 && j <= 3)
		{
			cout << "\t";
			for (int k = 0; k < 11; k++)
			{
				if (cletters.find(letttt[(j - 1) * 11 + k]) == cletters.end())
				{
					cout << letttt[(j - 1) * 11 + k] << " ";
				}
				else
				{
					cout << "_ ";
				}
			}
		}
		if (j != 12)
		{
			cout << endl;
		}

	}

	cout << "\t\tСлово: " << word_p << endl;
	cout << "\n  Ошибки (" << 15 << "): ";
	for (auto i : mistakes)
		cout << i << " ";
	cout << endl << endl;
	cout << "  ВЫ ПРОИГРАЛИ!(\n  ";
	playsound("sadtrom.mp3", "gtwo");
	system("pause");
	system("cls");
	while (_kbhit()) _getch();
	return;
}

void startgamehangman()
{
	if (music)
	{
		mciSendString(L"open \"audio/2.mp3\" alias gtwo", NULL, 0, NULL);
		mciSendString(L"play gtwo repeat", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");
		string text = namepichm + "\n\n\n  Игра \"ВИСЕЛИЦА\"\n\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		cout << namepichm;
		cout << "\n\n\n";
		cout << "  Игра \"ВИСЕЛИЦА\"\n" << endl;;
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			hangman();
		}

		else if (vibor == 2)
		{
			system("cls");
			cout << namepichm;
			cout << "\n\n\n";
			cout << "  Игра \"ВИСЕЛИЦА\"\n" << endl;
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  В игре Вам предстоит угдать загаданное слово.\n  После того, как Вы начнете игру, Вам будет предложено назвать букву, которая может входить в это слово.\n  Если такая буква есть в слове, то она появляется место соответствующими этой букве чертами — столько раз,\n    сколько она встречается в слове.\n  Если такой буквы нет, то к виселице добавляется часть.\n  Вы продолжает отгадывать буквы до тех пор, пока не отгадает всё слово.\n  За каждый неправильный ответ к виселице будет добавляться еще кусочек.\n  Всего у Вас есть 15 попыток.\n  Если у Вас закончились попытки и туловище в виселице нарисовано полностью, то Вы проигрываете.\n  Если Вы смогли угадать слово, то Вы выигрываете!\n  Все просто.\n  ";
			system("pause");
			system("cls");
			cout << namepichm;
			cout << "\n\n\n";
			cout << "  Игра \"ВИСЕЛИЦА\"\n" << endl;
			cout << "  ОТВЕТЫ НА ВОПРОСЫ. " << endl << endl;
			cout << "  1.\tЕсли Вы увидели такое оповещение: \"Проблема с открытием файла со словами. Отсутствует файл: words.txt\",\n    \tто программа не может получить доступ к файлу, где хранятся слова для игры.\n    \tЧтобы это исправить, необходимо в папку с игрой переместить файл со словами.\n    \tВАЖНО! ФАЙЛ ДОЛЖЕН НАХОДИТСЯ В ОДНОЙ ПАПКЕ С ИГРОЙ!" << endl;
			cout << "  2.\tЕсли вы потеряли файл word.txt, который поставляется вместе с игрой, то просто создайте его и наполните словами.\n    \tВАЖНО! КОДИРОВКА ФАЙЛА ДОЛЖНА БЫТЬ \"ANSI\".\n    \tСамый простой способ создать такой файл - встроенная в Windows программа \"Блокнот\".\n    \tВАЖНО! КОГДА СОХРАНЯЕТЕ ФАЙЛ СО СЛОВАМИ, ТО ВЫБЕРИТЕ НУЖНУЮ КОДИРОВКУ \"ANSI\"." << endl;
			cout << "  3.\tЕсли Вы увидели подобное оповещение: \"Проблема с выбранным словом. Строка \"РњСѓС„С‚Р°\" должна быть составлена\n    \tтолько из букв русского алфавита.\", но уверены, что правильно вводили слово в файл word.txt,\n    \tто скорее всего файл сохранен в другой кодировке.\n    \tДля того, чтобы это исправить, просто сохраните его в кодировке \"ANSI\".\n    \tЭто можно сделать также с помощью программы \"Блокнот\"\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gtwo", NULL, 0, NULL);
}