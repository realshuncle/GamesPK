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
"�����",
"����������",
"�������������",
"����������",
"����������",
"��������",
"��������",
"����Ш������",
"������������",
"����������",
"������������",
"����������������",
"������������",
"��������",
"�������",
"�������������",
"����������",
"�������������" };

string TakeWord()
{
	string word;
	fstream in("words.txt");
	int size = 0;
	if (!in)
	{
		cout << endl << endl << "  �������� � ��������� ����� �� �������. ����������� ����: words.txt" << endl;
		cout << "  ����� �������������� ���������� �������.\n\n  ";
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
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
		{'�', '�'},
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
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
'�',
	};
	system("cls");
	while (_kbhit()) _getch();
	string word = TakeWord();
	string word_p = "";
	if (!ToUpperCase(word))
	{
		cout << endl << "  �������� � ��������� ������.\n  ������ \"" << word << "\" ������ ���� ���������� ������ �� ���� �������� ��������.\n  ";
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
		text += "\t\t�����: " + word_p + "\n\n  ������ (" + to_string(15 - i) + "): ";
		cout << "\t\t�����: " << word_p << endl;
		cout << "\n  ������ (" << 15 - i << "): ";
		for (auto i : mistakes)
		{
			cout << i << " ";
			text = text + i + " ";
		}
		text += "\n\n";
		cout << endl << endl;
		if (letters.size() == 0)
		{
			cout << "  �� ��������!\n  ";
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
		
		text += "  ������� �����, ������� ����� ������� � �����. ������� ��������: " + to_string(i) + "\n";
		cout << "  ������� �����, ������� ����� ������� � �����. ������� ��������: " << i << endl;
		string letterstr = "";
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
				cout << "��� �� �������! �� ���������: " << 40 - tmp << endl;
			else if (tmp > 5)
				cout << "�� ��� ���-��? �� �� ������ ������� �� ������ ��� ��� ������� ���: " << tmp << endl;
					
			cout << text;
			if (str.size() != 1)
				cout << "  ���-�� ����� �� ���. �������� �� ����� ��������� ��������. ������� ����� ��� �����." << endl;
			else if (cletters.find(str[0]) != cletters.end())
				cout << "  ���-�� ����� �� ���. �������� �� ����� �����, ������� ��� �������. ������� ����� ��� �����." << endl;
			else if (!ToUpperCase(str))
				cout << "  ���-�� ����� �� ���. �������� �� ����� �����, �����-������ ���� ��� ���� ������. ������� ����� ��� �����." << endl;
			playsound("negative.mp3", "");
			tmp++;
			str = "";
		}
		letterstr = str;
		char letter = letterstr[0];
		if (letters.find(letter) == letters.end())
		{
			cout << "  ������ ����� � ����� ���. ���." << endl;
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
			cout << "  ���! ����� ����� ���� � �����." << endl;
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

	cout << "\t\t�����: " << word_p << endl;
	cout << "\n  ������ (" << 15 << "): ";
	for (auto i : mistakes)
		cout << i << " ";
	cout << endl << endl;
	cout << "  �� ���������!(\n  ";
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
		string text = namepichm + "\n\n\n  ���� \"��������\"\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		cout << namepichm;
		cout << "\n\n\n";
		cout << "  ���� \"��������\"\n" << endl;;
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
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
			cout << "  ���� \"��������\"\n" << endl;
			cout << "  �������. " << endl << endl;
			cout << "  � ���� ��� ��������� ������ ���������� �����.\n  ����� ����, ��� �� ������� ����, ��� ����� ���������� ������� �����, ������� ����� ������� � ��� �����.\n  ���� ����� ����� ���� � �����, �� ��� ���������� ����� ���������������� ���� ����� ������� � ������� ���,\n    ������� ��� ����������� � �����.\n  ���� ����� ����� ���, �� � �������� ����������� �����.\n  �� ���������� ���������� ����� �� ��� ���, ���� �� �������� �� �����.\n  �� ������ ������������ ����� � �������� ����� ����������� ��� �������.\n  ����� � ��� ���� 15 �������.\n  ���� � ��� ����������� ������� � �������� � �������� ���������� ���������, �� �� ������������.\n  ���� �� ������ ������� �����, �� �� �����������!\n  ��� ������.\n  ";
			system("pause");
			system("cls");
			cout << namepichm;
			cout << "\n\n\n";
			cout << "  ���� \"��������\"\n" << endl;
			cout << "  ������ �� �������. " << endl << endl;
			cout << "  1.\t���� �� ������� ����� ����������: \"�������� � ��������� ����� �� �������. ����������� ����: words.txt\",\n    \t�� ��������� �� ����� �������� ������ � �����, ��� �������� ����� ��� ����.\n    \t����� ��� ���������, ���������� � ����� � ����� ����������� ���� �� �������.\n    \t�����! ���� ������ ��������� � ����� ����� � �����!" << endl;
			cout << "  2.\t���� �� �������� ���� word.txt, ������� ������������ ������ � �����, �� ������ �������� ��� � ��������� �������.\n    \t�����! ��������� ����� ������ ���� \"ANSI\".\n    \t����� ������� ������ ������� ����� ���� - ���������� � Windows ��������� \"�������\".\n    \t�����! ����� ���������� ���� �� �������, �� �������� ������ ��������� \"ANSI\"." << endl;
			cout << "  3.\t���� �� ������� �������� ����������: \"�������� � ��������� ������. ������ \"Муфта\" ������ ���� ����������\n    \t������ �� ���� �������� ��������.\", �� �������, ��� ��������� ������� ����� � ���� word.txt,\n    \t�� ������ ����� ���� �������� � ������ ���������.\n    \t��� ����, ����� ��� ���������, ������ ��������� ��� � ��������� \"ANSI\".\n    \t��� ����� ������� ����� � ������� ��������� \"�������\"\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gtwo", NULL, 0, NULL);
}