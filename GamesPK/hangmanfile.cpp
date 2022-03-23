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
//void playwinmusic();
//void playSound(char ch, int time, int oct);
//void playfailsound();
//void playlosemusic();
//void playPUTIN();
//void playbegin()
//{
//	system("cls");
//	cout << endl << namepics[0];
//	playSound('a', 150, 2);
//	Sleep(100);
//	playSound('F', 300, 3);
//	Sleep(100);
//	system("cls");
//	cout << endl << namepics[1];
//	playSound('C', 150, 3);
//	Sleep(100);
//	playSound('G', 300, 3);
//	Sleep(100);
//	system("cls");
//	cout << endl << namepics[2];
//	playSound('G', 200, 3);
//	Sleep(100);
//	playSound('A', 200, 3);
//	system("cls");
//	cout << endl << namepics[3];
//	Sleep(100);
//	playSound('a', 300, 3);
//	Sleep(100);
//	playSound('a', 200, 3);
//	system("cls");
//	cout << endl << namepics[4];
//	Sleep(100);
//	playSound('A', 150, 3);
//	Sleep(100);
//	system("cls");
//	cout << endl << namepics[5];
//	playSound('F', 150, 3);
//	Sleep(100);
//	playSound('G', 300, 3);
//	system("cls");
//	cout << endl << namepics[6];
//	Sleep(500);
//}
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
		//in.close();
		//return ("�����");
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

//void PrintPic(int i)
//{
//	string path = "txt/" + to_string(i) + ".txt";
//	fstream pic(path);
//	if (!pic)
//		cout << "  �������� � ������������ ��������. ����������� ����: " << path << endl;
//	char ch;
//	pic.get(ch);
//	while (pic)
//	{
//		cout << ch;
//		pic.get(ch);
//	}
//	pic.close();
//}
//
//bool PrintPic(string path)
//{
//	fstream pic(path);
//	if (!pic)
//	{
//		cout << "�������� � ������������ ��������. ����������� ����: " << path << endl;
//		return 1;
//	}
//	char ch;
//	pic.get(ch);
//	while (pic)
//	{
//
//		cout << ch;
//		pic.get(ch);
//	}
//	pic.close();
//	return 0;
//}
//void splayWinSound()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		Beep(783.991, 150);
//		Sleep(100);
//		Beep(987.767, 150); Sleep(100);
//		Beep(1174.659, 150); Sleep(100);
//		Beep(987.767, 150);
//		Sleep(100);
//	}
//	Beep(783.991, 500); Sleep(100);
//	for (int j = 0; j < 3; j++)
//	{
//		Beep(523.251, 500);
//		Beep(587.33, 500);
//		for (int i = 0; i < 3; i++)
//		{
//			if (i != 0)
//			{
//				Beep(523.251, 300);
//				Beep(587.33, 300);
//			}
//			Beep(698.456, 300);
//			Beep(698.456, 150);
//			Beep(698.456, 300);
//			Beep(698.456, 150);
//			Beep(698.456, 300);
//			Beep(698.456, 300);
//			Beep(698.456, 300);
//		}
//		Beep(698.456, 300);
//		Beep(783.991, 300);
//		Beep(659.255, 800);
//		Sleep(500);
//	}
//}
//
//void playWinSound()
//{
//	for (int j = 0; j < 3; j++)
//	{
//		Beep(523.251, 300);
//		Beep(587.33, 300);
//		for (int i = 0; i < 3; i++)
//		{
//			if (i != 0)
//			{
//				Beep(523.251, 180);
//				Beep(587.33, 180);
//			}
//			Beep(698.456, 180);
//			Beep(698.456, 90);
//			Beep(698.456, 180);
//			Beep(698.456, 90);
//			Beep(698.456, 180);
//			Beep(698.456, 180);
//			Beep(698.456, 180);
//		}
//		Beep(698.456, 180);
//		Beep(783.991, 180);
//		Beep(659.255, 800);
//		Sleep(500);
//	}
//}
//
//void sleep(float seconds)
//{
//	clock_t startClock = clock();
//	float secondsAhead = seconds * CLOCKS_PER_SEC;
//	while (clock() < startClock + secondsAhead);
//	return;
//}
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
	//setlocale(LC_ALL, "Russian");
	system("cls");
	/*cout << startgamepic;
	Beep(1174.659, 100);
	Beep(1174.659, 100);
	Beep(1174.659, 100);
	Beep(1174.659, 700);
	Sleep(1300);*/
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
		 //= /*hangpics[15 - i]*/ 
		//cout << hangpics[15 - i];
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
			//for (int i = 0; i < 5; i++)
			/*{
				Beep(783.991, 100);
				Sleep(50);
				Beep(987.767, 100);
				Sleep(50);
				Beep(1174.659, 100);
				Sleep(50);
				Beep(987.767, 100);
				Sleep(50);
			}*/
			//Beep(783.991, 500);
			//Sleep(2000);
			playsound("win.mp3", "gtwo");
			//playfailsound();
			//Sleep(1200);
			system("pause");
			//system("cls");
			//if (word == "�����")
			//{
			//	cout << putinwin;
			//	//playPUTIN();
			//}
			//else
			//{
			//	cout << winpic;
			//	//playwinmusic();

			//}

			while (_kbhit()) _getch();
			return;
		}


		string str = "";
		char ch;
		int vibor;
		int tmp = 0;
		//cout << "  ";
		while (_kbhit()) _getch();
		
		text += "  ������� �����, ������� ����� ������� � �����. ������� ��������: " + to_string(i) + "\n";
		cout << "  ������� �����, ������� ����� ������� � �����. ������� ��������: " << i << endl;
		string letterstr = "";
		//cin >> letterstr;
		//int tmp = 0;
		while (true)
		{
			//letterstr = "";
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
				//vibor = stoi(str);
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
			//cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			if (str.size() != 1)
				cout << "  ���-�� ����� �� ���. �������� �� ����� ��������� ��������. ������� ����� ��� �����." << endl;
			else if (cletters.find(str[0]) != cletters.end())
				cout << "  ���-�� ����� �� ���. �������� �� ����� �����, ������� ��� �������. ������� ����� ��� �����." << endl;
			else if (!ToUpperCase(str))
				cout << "  ���-�� ����� �� ���. �������� �� ����� �����, �����-������ ���� ��� ���� ������. ������� ����� ��� �����." << endl;
			playsound("negative.mp3", "");
			//while (_kbhit()) _getch();
			tmp++;
			str = "";
		}
		letterstr = str;
		//while (!ToUpperCase(letterstr) || letterstr.size() != 1 || cletters.find(letterstr[0]) != cletters.end())
		//{
		//	if (tmp == 40)
		//		exit(0);
		//	if (tmp > 20)
		//		cout << "��� ��� �� �������! �� ���������: " << 40 - tmp << endl;
		//	else if (tmp > 5)
		//		cout << "�� ��� ���-��? �� ��� �� ������ ������� �� ������ ��� ������� ���: " << tmp << endl;
		//	cin.clear();
		//	cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		//	if (letterstr.size() != 1)
		//		cout << "���-�� ����� �� ���. �������� �� ����� ��������� ��������. ������� ����� ��� �����." << endl;
		//	else if (cletters.find(letterstr[0]) != cletters.end())
		//		cout << "���-�� ����� �� ���. �������� �� ����� �����, ������� ��� �������. ������� ����� ��� �����." << endl;
		//	else if (!ToUpperCase(letterstr))
		//		cout << "���-�� ����� �� ���. �������� �� ����� �����, �����-������ ���� ��� ���� ������. ������� ����� ��� �����." << endl;
		//	cin >> letterstr;
		//	tmp++;
		//}
		char letter = letterstr[0];
		if (letters.find(letter) == letters.end())
		{
			cout << "  ������ ����� � ����� ���. ���." << endl;
			//Beep(1174.659, 100);
			//Beep(783.991, 200);
			//playsound("hangmanfalse.mp3", "gtwo");
			if (sounds)
			{
				Sleep(100);
				mciSendString(L"open \"audio/hangmanfalse.mp3\" alias st", NULL, 0, NULL);
				mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
				//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
				mciSendString(L"play st from 0 wait", NULL, 0, NULL);
				mciSendString(L"close st", NULL, 0, NULL);
				//while (_kbhit()) _getch();
			}
			
			i--;
			cletters.insert(letter);
			mistakes.insert(letter);
			//Sleep(1500);
		}
		else
		{
			cout << "  ���! ����� ����� ���� � �����." << endl;
			//Beep(783.991, 100);
			//Beep(1174.659, 200);
			//playsound("hangmantrue.mp3", "gtwo");
			if (sounds)
			{
				Sleep(100);
				mciSendString(L"open \"audio/hangmantrue.mp3\" alias st", NULL, 0, NULL);
				mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
				//mciSendString(L"set st Speed 1500", NULL, 0, NULL);
				mciSendString(L"play st from 0 wait", NULL, 0, NULL);
				mciSendString(L"close st", NULL, 0, NULL);
				//while (_kbhit()) _getch();
			}
			cletters.insert(letter);
			letters.erase(letter);
			for (int i = 0; i < word.size(); i++)
			{
				if (word[i] == letter)
					word_p = word_p.substr(0, i * 2) + letter + word_p.substr(i * 2 + 1);
			}
			//Sleep(1500);
		}
		while (_kbhit()) _getch();
	}
	system("cls");
	for (int j = 0; j < 13; j++)
	{
		//text += "  " + hangpics[15 - i][j];
		cout << "  " << hangpics[15][j];
		if (j >= 1 && j <= 3)
		{
			//text += "\t";
			cout << "\t";
			for (int k = 0; k < 11; k++)
			{
				if (cletters.find(letttt[(j - 1) * 11 + k]) == cletters.end())
				{
					//text = text + letttt[(j - 1) * 11 + k] + " ";
					cout << letttt[(j - 1) * 11 + k] << " ";
				}
				else
				{
					//text += "_ ";
					cout << "_ ";
				}
			}
		}
		if (j != 12)
		{
			//text += "\n";
			cout << endl;
		}

	}
	//cout << hangpics[15];
	cout << "\t\t�����: " << word_p << endl;
	cout << "\n  ������ (" << 15 << "): ";
	for (auto i : mistakes)
		cout << i << " ";
	cout << endl << endl;
	cout << "  �� ���������!(\n  ";
	playsound("sadtrom.mp3", "gtwo");
	//playfailsound();
	//Sleep(1200);
	system("pause");
	system("cls");
	//cout << lossepic;
	//playlosemusic();
	while (_kbhit()) _getch();
	return;
}

void startgamehangman()
{
	if (music)
	{
		mciSendString(L"open \"audio/2.mp3\" alias gtwo", NULL, 0, NULL);
		mciSendString(L"play gtwo repeat", NULL, 0, NULL);
		//mciSendString(L"setaudio gthree volume to 100", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");
		string text = namepichm + "\n\n\n  ���� \"��������\"\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		cout << namepichm;
		cout << "\n\n\n";
		cout << "  ���� \"��������\"\n" << endl;
		//string temp = formnumber();
		//string text = namepic + "\n\n\n\n  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
		//cout << namepic;
		//cout << "\n\n\n\n";
		//cout << "  ���� \"������ �����\"\n" << endl;
		cout << "  ����\n\n\t1 - ������ ����\n\t2 - ������\n\t3 - � ������� ����\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			/*while (true)
			{*/
				hangman();
				/*system("cls");
				string text = namepichm + "\n\n\n\n  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n  ������ �� ����� ���-�� �� ��. ���������� ��� �����.\n  ";
				cout << namepichm;
				cout << "\n\n\n" << endl;
				cout << "  �������� ����� ����\n\n\t1 - � �����������\n\t2 - ������ � ������ (��� �� ������)\n\t3 - �����\n\n";
				int vibor = read(text, 1, 3);
				if (vibor == 1)
					hangman();
				else if (vibor == 2)
					hangman();
				else if (vibor == 3)
					break;*/
			//}
		}

		else if (vibor == 2)
		{
			system("cls");
			//string temp = formnumber();
			cout << namepichm;
			cout << "\n\n\n";
			cout << "  ���� \"��������\"\n" << endl;
			cout << "  �������. " << endl << endl;
			cout << "  � ���� ��� ��������� ������ ���������� �����.\n  ����� ����, ��� �� ������� ����, ��� ����� ���������� ������� �����, ������� ����� ������� � ��� �����.\n  ���� ����� ����� ���� � �����, �� ��� ���������� ����� ���������������� ���� ����� ������� � ������� ���,\n    ������� ��� ����������� � �����.\n  ���� ����� ����� ���, �� � �������� ����������� �����.\n  �� ���������� ���������� ����� �� ��� ���, ���� �� �������� �� �����.\n  �� ������ ������������ ����� � �������� ����� ����������� ��� �������.\n  ����� � ��� ���� 15 �������.\n  ���� � ��� ����������� ������� � �������� � �������� ���������� ���������, �� �� ������������.\n  ���� �� ������ ������� �����, �� �� �����������!\n  ��� ������.\n  ";
			system("pause");
			system("cls");
			//string temp = formnumber();
			cout << namepichm;
			cout << "\n\n\n";
			cout << "  ���� \"��������\"\n" << endl;
			cout << "  ������ �� �������. " << endl << endl;
			//cout << endl << endl << "  ������ �� �������." << endl << endl;
			cout << "  1.\t���� �� ������� ����� ����������: \"�������� � ��������� ����� �� �������. ����������� ����: words.txt\",\n    \t�� ��������� �� ����� �������� ������ � �����, ��� �������� ����� ��� ����.\n    \t����� ��� ���������, ���������� � ����� � ����� ����������� ���� �� �������.\n    \t�����! ���� ������ ��������� � ����� ����� � �����!" << endl;
			cout << "  2.\t���� �� �������� ���� word.txt, ������� ������������ ������ � �����, �� ������ �������� ��� � ��������� �������.\n    \t�����! ��������� ����� ������ ���� \"ANSI\".\n    \t����� ������� ������ ������� ����� ���� - ���������� � Windows ��������� \"�������\".\n    \t�����! ����� ���������� ���� �� �������, �� �������� ������ ��������� \"ANSI\"." << endl;
			cout << "  3.\t���� �� ������� �������� ����������: \"�������� � ��������� ������. ������ \"Муфта\" ������ ���� ����������\n    \t������ �� ���� �������� ��������.\", �� �������, ��� ��������� ������� ����� � ���� word.txt,\n    \t�� ������ ����� ���� �������� � ������ ���������.\n    \t��� ����, ����� ��� ���������, ������ ��������� ��� � ��������� \"ANSI\".\n    \t��� ����� ������� ����� � ������� ��������� \"�������\"\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close gtwo", NULL, 0, NULL);
	///*while (true)
	//{
	//	system("cls");
	//	cout << namepichm;
	//	cout << "\n\n���� \"��������\"\n" << endl;
	//	int vibor;
	//	cout << "������� �������: 1 - ������ ����, 2 - ������, 3 - �����" << endl;
	//	while (_kbhit()) _getch();

	//	cin >> vibor;
	//	int tmp = 0;
	//	while (!cin.good() || (vibor != 1 && vibor != 2 && vibor != 3))
	//	{
	//		if (tmp == 40)
	//			exit(0);
	//		if (tmp > 20)
	//			cout << "��� ��� �� �������! �� ���������: " << 40 - tmp << endl;
	//		else if (tmp > 5)
	//			cout << "�� ��� ���-��? �� ��� �� ������ ������� �� ������ ��� ������� ���: " << tmp << endl;

	//		cin.clear();
	//		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	//		cout << "�� ���������! ������� ���������� �������! ������� �������: 1 - � �����������, 2 - ������, 3 - �����" << endl;
	//		cin >> vibor;
	//		tmp++;
	//	}
	//	if (vibor == 1)
	//		hangman();
	//	else if (vibor == 2)
	//	{
	//		system("cls");
	//		cout << "�������. " << endl << endl;
	//		cout << "� ���� ��� ��������� ������ ���������� �����. ����� ����, ��� �� ������� ����, ��� ����� ���������� ������� �����, ������� ����� ������� � ��� �����. ���� ����� ����� ���� � �����, �� ��� ���������� ����� ���������������� ���� ����� ������� � ������� ���, ������� ��� ����������� � �����. ���� ����� ����� ���, �� � �������� ����������� �����. �� ���������� ���������� ����� �� ��� ���, ���� �� �������� �� �����. �� ������ ������������ ����� � �������� ����� ����������� ��� �������.\n����� � ��� ���� 15 �������.\n���� � ��� ����������� ������� � �������� � �������� ���������� ���������, �� �� ������������, �� ���� �� ���������� �����������. ���� �� ������ ������� �����, �� �� �����������! ��� ������." << endl;
	//		cout << endl << endl << "������ �� �������." << endl << endl;
	//		cout << "1.\t���� �� ������� ����� ����������: \"�������� � ��������� ����� �� �������. ����������� ����: words.txt\", �� ��������� �� ����� �������� ������ � �����, ��� �������� ����� ��� ����. ����� ��� ���������, ���������� � ����� � ����� ����������� ���� �� �������. �����! ���� ������ ��������� � ����� ����� � �����!" << endl;
	//		cout << "2.\t���� �� �������� ���� word.txt, ������� ������������ ������ � �����, �� ������ �������� ��� � ��������� ��� �������. �����! ��������� ����� ������ ���� \"ANSI\". ����� ������� ������ ������� ����� ���� - ���������� � Windows ��������� \"�������\". �����! ����� ���������� ���� �� �������, �� �������� ������ ��������� \"ANSI\"." << endl;
	//		cout << "3.\t���� �� ������� �������� ����������: \"�������� � ��������� ������. ������ \"Муфта\" ������ ���� ���������� ������ �� ���� �������� ��������.\", �� �������, ��� ��������� ������� ����� � ���� word.txt, �� ������ ����� ���� �������� � ������ ���������. ��� ����, ����� ��� ���������, ������ ��������� ��� � ��������� \"ANSI\". ��� ����� ������� ����� � ������� ��������� \"�������\"" << endl;
	//		system("pause");
	//	}


	//	else if (vibor == 3)
	//		break;
	//}*/
}