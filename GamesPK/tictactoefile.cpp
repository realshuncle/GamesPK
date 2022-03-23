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

const string namepictt =
R"(
          88                                                              
    ,d    ""              ,d                            ,d                
    88                    88                            88                
  MM88MMM 88  ,adPPYba, MM88MMM ,adPPYYba,  ,adPPYba, MM88MMM ,adPPYba,   ,adPPYba,
    88    88 a8"     ""   88    ""     `Y8 a8"     ""   88   a8"     "8a a8P_____88
    88    88 8b           88    ,adPPPPP88 8b           88   8b       d8 8PP"""""""  
    88,   88 "8a,   ,aa   88,   88,    ,88 "8a,   ,aa   88,  "8a,   ,a8" "8b,   ,aa
    "Y888 88  `"Ybbd8"'   "Y888 `"8bbdP"Y8  `"Ybbd8"'   "Y888 `"YbbdP"'   `"Ybbd8"')";
const auto polepic =
R"(
   7 | 8 | 9
  ---|---|---
   4 | 5 | 6  
  ---|---|---
   1 | 2 | 3 )";

const string krestikpic[6] =
{
"             ",
"  XX     XX  ",
"   XX   XX   ",
"     XXX     ",
"   XX   XX   ",
"  XX     XX  "
};
const string nolikpic[6] =
{
"             ",
"    OOOOO    ",
"   OO   OO   ",
"  OO     OO  ",
"   OO   OO   ",
"    OOOOO    "
};
const string emptypic[6] =
{
"             ",
"             ",
"             ",
"             ",
"             ",
"             "
};
const string linepic = "  _____________|_____________|_____________";
const string comppictt =
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
int checkttt(set<int>& player, set<int>& comp)
{
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};
	set<int> tempp, tempc;
	if (player.size() + comp.size() == 9)
		return 0;
	for (int i = 0; i < 8; i++)
	{
		tempp.clear();
		tempc.clear();
		set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
		set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
		if (tempp.size() == 3)
			return 1;
		if (tempc.size() == 3)
			return -1;
	}
	return 2;
}
int playgtttt(set<int>& player, set<int>& comp)
{

	set<int> tempp, tempc;
	random_device rd;
	mt19937 mersenne(rd());
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};

	if (player.size() == 1 && player.find(5) != player.end() && comp.size() == 0)
	{
		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(5) == player.end() && comp.size() == 0 || player.size() == 0 && comp.size() == 0)
	{
		comp.insert(5);
		return 5;
	}
	else if (player.size() == 1 && player.find(2) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(8);
		return 8;
	}
	else if (player.size() == 1 && player.find(4) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(6);
		return 6;
	}
	else if (player.size() == 1 && player.find(6) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(4);
		return 4;
	}
	else if (player.size() == 1 && player.find(8) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(2);
		return 2;
	}
	else if (player.size() == 1 && player.find(1) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 4 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 6 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 2)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 4)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(7) != player.end() && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 8)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && comp.size() == 2 && comp.find(5) != comp.end())
	{
		int a[2] = { 0, 0 };
		int k = 0;
		int chet, nechet;
		for (auto j : player)
		{
			a[k] = j;
			k++;
		}
		if ((a[0] + a[1]) % 2 == 1)
		{
			if (a[0] % 2 == 0)
			{
				chet = a[0];
				nechet = a[1];
			}
			else
			{
				chet = a[1];
				nechet = a[0];
			}
			if (nechet == 1)
				if (chet == 2)
				{
					comp.insert(4);
					return 4;
				}
				else
				{
					comp.insert(2);
					return 2;
				}
			else if (nechet == 3)
				if (chet == 2)
				{
					comp.insert(6);
					return 6;
				}
				else
				{
					comp.insert(2);
					return 2;
				}
			else if (nechet == 7)
				if (chet == 4)
				{
					comp.insert(8);
					return 8;
				}
				else
				{
					comp.insert(4);
					return 4;
				}
			else if (nechet == 9)
				if (chet == 8)
				{
					comp.insert(6);
					return 6;
				}
				else
				{
					comp.insert(8);
					return 8;
				}
		}

	}
	if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else
	{

		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempc.size() == 2 && tempp.size() == 0)
			{
				tempp.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempc.begin(), tempc.end(), inserter(tempp, tempp.begin()));
				for (auto j : tempp)
				{
					comp.insert(j);
					return j;
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempp.size() == 2 && tempc.size() == 0)
			{
				tempc.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempp.begin(), tempp.end(), inserter(tempc, tempc.begin()));
				for (auto j : tempc)
				{
					comp.insert(j);
					return j;
				}
			}
		}

		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
		t1 = ((unsigned int)mersenne() % 5 + 1) * 2 - 1;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 9)
				t1 = 1;
			if (t1 == 5)
				t1 = 7;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	}
}
int playgttt(set<int>& player, set<int>& comp)
{

	set<int> tempp, tempc;
	random_device rd;
	mt19937 mersenne(rd());
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};

	if (player.size() == 1 && player.find(5) != player.end() && comp.size() == 0)
	{
		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(5) == player.end() && comp.size() == 0 || player.size() == 0 && comp.size() == 0)
	{
		comp.insert(5);
		return 5;
	}
	else if (player.size() == 1 && player.find(2) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(8);
		return 8;
	}
	else if (player.size() == 1 && player.find(4) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(6);
		return 6;
	}
	else if (player.size() == 1 && player.find(6) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(4);
		return 4;
	}
	else if (player.size() == 1 && player.find(8) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		comp.insert(2);
		return 2;
	}
	else if (player.size() == 1 && player.find(1) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 2 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 4 + ((unsigned int)mersenne() % 2) * 4;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 1 && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
	{
		int t1 = 6 + ((unsigned int)mersenne() % 2) * 2;
		comp.insert(t1);
		return t1;
	}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 2)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(1) != player.end() && player.find(7) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 4)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(7) != player.end() && player.find(9) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 8)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else if (player.size() == 2 && comp.size() == 2 && comp.find(5) != comp.end())
	{
		int a[2] = { 0, 0 };
		int k = 0;
		int chet, nechet;
		for (auto j : player)
		{
			a[k] = j;
			k++;
		}
		if ((a[0] + a[1]) % 2 == 1)
		{
			if (a[0] % 2 == 0)
			{
				chet = a[0];
				nechet = a[1];
			}
			else
			{
				chet = a[1];
				nechet = a[0];
			}
			if (nechet == 1)
				if (chet == 2 && comp.find(4) == comp.end())
				{
					comp.insert(4);
					return 4;
				}
				else if (chet == 4 && comp.find(2) == comp.end())
				{
					comp.insert(2);
					return 2;
				}
				else if (nechet == 3)
					if (chet == 2 && comp.find(6) == comp.end())
					{
						comp.insert(6);
						return 6;
					}
					else if (chet == 6 && comp.find(2) == comp.end())
					{
						comp.insert(2);
						return 2;
					}
					else if (nechet == 7)
						if (chet == 4 && comp.find(8) == comp.end())
						{
							comp.insert(8);
							return 8;
						}
						else if (chet == 8 && comp.find(4) == comp.end())
						{
							comp.insert(4);
							return 4;
						}
						else if (nechet == 9)
							if (chet == 8 && comp.find(6) == comp.end())
							{
								comp.insert(6);
								return 6;
							}
							else if (chet == 6 && comp.find(8) == comp.end())
							{
								comp.insert(8);
								return 8;
							}
		}

	}
	if (player.size() == 2 && player.find(9) != player.end() && player.find(3) != player.end() && comp.size() == 1 && comp.find(5) != comp.end())
		for (int i = 0; i < 4; i++)
		{
			int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end() && t1 != 6)
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	else
	{

		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempc.size() == 2 && tempp.size() == 0)
			{
				tempp.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempc.begin(), tempc.end(), inserter(tempp, tempp.begin()));
				for (auto j : tempp)
				{
					comp.insert(j);
					return j;
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));

			if (tempp.size() == 2 && tempc.size() == 0)
			{
				tempc.clear();
				set_difference(winpos[i].begin(), winpos[i].end(), tempp.begin(), tempp.end(), inserter(tempc, tempc.begin()));
				for (auto j : tempc)
				{
					comp.insert(j);
					return j;
				}
			}
		}

		int t1 = ((unsigned int)mersenne() % 4 + 1) * 2;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 8)
				t1 = 2;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
		t1 = ((unsigned int)mersenne() % 5 + 1) * 2 - 1;
		for (int i = 0; i < 4; i++)
		{
			if (t1 > 9)
				t1 = 1;
			if (t1 == 5)
				t1 = 7;
			if (player.find(t1) == player.end() && comp.find(t1) == comp.end())
			{
				comp.insert(t1);
				return t1;
			}
			t1 += 2;
		}
	}
}
void drawttt(set<int>& player, set<int>& comp, set<int> winthree = {})
{
	int positionsx[9] = { 2, 7, 6, 9, 5, 1, 4, 3, 8 };
	int num = 0;
	for (int i = 0; i < 6; i++)
	{
		cout << "  ";
		if (winthree.find(positionsx[num]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 1]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 1]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 1]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 2]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 2]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 2]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		cout << "\n";
		SetConsoleTextAttribute(hConsole, 14);
	}
	num += 3;
	cout << linepic << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "  ";
		if (winthree.find(positionsx[num]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 1]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 1]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 1]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 2]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 2]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 2]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		cout << "\n";
		SetConsoleTextAttribute(hConsole, 14);
	}
	num += 3;
	cout << linepic << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "  ";
		if (winthree.find(positionsx[num]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 1]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 1]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 1]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		SetConsoleTextAttribute(hConsole, 14);
		cout << "|";
		if (winthree.find(positionsx[num + 2]) != winthree.end())
			SetConsoleTextAttribute(hConsole, 10);
		if (player.find(positionsx[num + 2]) != player.end())
			cout << krestikpic[i];
		else if (comp.find(positionsx[num + 2]) != comp.end())
			cout << nolikpic[i];
		else
			cout << emptypic[i];
		cout << "\n";
		SetConsoleTextAttribute(hConsole, 14);
	}
}

void PVI4()
{
	system("cls");
	int i = 25;
	random_device rd;
	mt19937 mersenne(rd());
	set<int> winpos[8] =
	{
		{2, 4, 9},
		{3, 5, 7},
		{1, 6, 8},
		{2, 6, 7},
		{1, 5, 9},
		{3, 4, 8},
		{2, 5, 8},
		{4, 5, 6}
	};
	set<int> fishkibili = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, player, comp;
	cout << namepictt;
	cout << "\n\n\n\n";
	cout << "  Игра \"Крестики-нолики\"\n" << endl;
	cout << "  Сейчас случайным образом будет выбрано, кому повезло, и кто будет ходить первым. \n" << endl;
	int temp = (unsigned int)mersenne() % 2;
	bool hod = false, hh = false;
	int fishka;
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
		hod = true;
		hh = true;
	}
	int vibor;
	bool flag = false;
	while (true)
	{
		set<int> tempp, tempc;

		if (player.size() + comp.size() == 9)
		{
			system("cls");
			cout << endl;
			hh ? drawttt(comp, player) : drawttt(player, comp);
			cout << "\n  НИЧЬЯ\n\n  ";
			cout << endl;
			system("pause");
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			tempp.clear();
			tempc.clear();
			set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
			set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
			if (tempp.size() == 3)
			{
				system("cls");
				cout << endl;
				hh ? drawttt(comp, player, tempp) : drawttt(player, comp, tempp);
				cout << "\n  ПРИМИТЕ МОИ ПОЗДРАВЛЕНИЯ! ВЫ ВЫИГРАЛИ!\n  ";
				playsound("win.mp3", "geight");
				system("pause");
				flag = true;
				break;
			}
			if (tempc.size() == 3)
			{
				system("cls");
				cout << endl;
				hh ? drawttt(comp, player, tempc) : drawttt(player, comp, tempc);
				cout << "\n  Я ПОБЕДИЛ! НУ А ВЫ ПРОИГРАЛИ :(\n  ";
				playsound("sadtrom.mp3", "geight");
				system("pause");
				flag = true;
				break;
			}
		}

		if (flag)
			break;

		if (hod)
		{
			system("cls");
			cout << comppictt;
			cout << endl;
			Sleep(1000);
			fishka = playgttt(player, comp);
			fishkibili.erase(fishka);
			hod = false;
			continue;
		}
		system("cls");
		cout << endl;
		int positions[9] = { 6, 1, 8, 7, 5, 3, 2, 9, 4 };
		int positionsx[9] = { 4,3,8,9,5,1,2,7,6 };
		hh ? drawttt(comp, player) : drawttt(player, comp);
		cout << endl;
		cout << "  Ваша очередь. Вы ходите " << (!hh ? "крестиками" : "ноликами") << ". Введите номер поля, которое Вы хотите занять." << endl;
		cout << "  Поля нумеруются следующим образом:" << endl;
		cout << polepic;
		cout << endl;
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
				if (vibor >= 1 && vibor <= 9 && fishkibili.find(positionsx[vibor - 1]) != fishkibili.end())
					break;
			}
			catch (...)
			{
				vibor = 0;
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
			system("cls");
			cout << endl;
			hh ? drawttt(comp, player) : drawttt(player, comp);
			cout << endl;
			cout << "  Ваша очередь. Вы ходите " << (!hh ? "крестиками" : "ноликами") << ". Введите номер поля, которое Вы хотите занять." << endl;
			cout << "  Поля нумеруются следующим образом:" << endl;
			cout << polepic;
			cout << endl;
			if (vibor > 0 && vibor < 10 && fishkibili.find(positionsx[vibor - 1]) == fishkibili.end())
			{
				cout << "  Это поле уже занято. Выберите другое.\n";
			}
			cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
			tmp++;
			str = "";
			playsound("negative.mp3", "");
		}
		fishkibili.erase(positionsx[vibor - 1]);
		player.insert(positionsx[vibor - 1]);
		cout << "  Хорошо." << endl;
		hod = true;
		Sleep(1000);
	}
}
void PVP4()
{
	string voprosi = "";
	random_device rd;
	mt19937 mersenne(rd());
	system("cls");
	cout << namepictt;
	cout << "\n\n\n\n";
	cout << "  Игра \"Крестики-нолики\"\n" << endl;
	cout << "  Перед тем как начать игру, небоходимо выбрать, кто будет загадывать число.\n  Для этого вам нужно ввести ваши имена." << endl;
	string name1, name2;
	cout << endl << "  Первый игрок введите свое имя.\t";
	while (_kbhit()) _getch();
	name1 = readstr(namepictt + "\n\n\n\n  Игра \"Крестики-нолики\"\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Первый игрок введите свое имя.\t");
	cout << endl << "  Здравствуйте, " << name1 << ". Интересное имя.\n" << endl;
	Sleep(1000);
	system("cls");
	cout << namepictt;
	cout << "\n\n\n\n";
	cout << "  Игра \"Крестики-нолики\"\n" << endl;
	cout << "  Второй игрок введите свое имя!\t ";
	while (_kbhit()) _getch();
	name2 = readstr(namepictt + "\n\n\n\n  Игра \"Крестики-нолики\"\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n\n  Второй игрок введите свое имя.\t");
	cout << endl << "  Приветствую, " << name2 << ". Какое замечательно имя!\n\n";
	Sleep(1000);
	while (true)
	{
		set<int> winpos[8] =
		{
			{2, 4, 9},
			{3, 5, 7},
			{1, 6, 8},
			{2, 6, 7},
			{1, 5, 9},
			{3, 4, 8},
			{2, 5, 8},
			{4, 5, 6}
		};
		set<int> fishkibili = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, player, comp;
		bool hod = false;
		system("cls");
		cout << namepictt;
		cout << "\n\n\n\n";
		cout << "  Игра \"Крестики-нолики\"\n" << endl;
		cout << "  Игроки, сейчас случайным образом будет выбрано, кто будет ходить первым.\n\n  ";
		system("pause");
		unsigned int temp = (unsigned int)mersenne() % 2;
		int count = 0;
		system("cls");
		cout << namepictt;
		cout << "\n\n\n\n";
		cout << "  Игра \"Крестики-нолики\"\n" << endl;
		cout << "  Мои поздравления, игрок " << (temp ? name1 : name2) << ". Вы ходите первыми.\n  ";
		if (temp)
		{
			hod = true;
		}
		system("pause");
		int vibor;
		bool flag = false;
		while (true)
		{
			set<int> tempp, tempc;

			if (player.size() + comp.size() == 9)
			{
				system("cls");
				cout << endl;
				!temp ? drawttt(comp, player) : drawttt(player, comp);
				cout << "\n  НИЧЬЯ\n\n  ";
				cout << endl;
				system("pause");
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				tempp.clear();
				tempc.clear();
				set_intersection(player.begin(), player.end(), winpos[i].begin(), winpos[i].end(), inserter(tempp, tempp.begin()));
				set_intersection(comp.begin(), comp.end(), winpos[i].begin(), winpos[i].end(), inserter(tempc, tempc.begin()));
				if (tempp.size() == 3)
				{
					system("cls");
					cout << endl;
					!temp ? drawttt(comp, player, tempp) : drawttt(player, comp, tempp);
					cout << "\n  ПРИМИТЕ МОИ ПОЗДРАВЛЕНИЯ ИГРОК " << name1 << "! ВЫ ВЫИГРАЛИ!\n  ";
					playsound("win.mp3", "geight");
					system("pause");
					flag = true;
					break;
				}
				if (tempc.size() == 3)
				{
					system("cls");
					cout << endl;
					!temp ? drawttt(comp, player, tempc) : drawttt(player, comp, tempc);
					cout << "\n  ПРИМИТЕ МОИ ПОЗДРАВЛЕНИЯ ИГРОК " << name2 << "! ВЫ ВЫИГРАЛИ!\n  ";
					playsound("win.mp3", "geight");
					system("pause");
					flag = true;
					break;
				}
			}

			if (flag)
				break;

			system("cls");
			cout << endl;
			int positions[9] = { 6, 1, 8, 7, 5, 3, 2, 9, 4 };
			int positionsx[9] = { 4,3,8,9,5,1,2,7,6 };
			!temp ? drawttt(comp, player) : drawttt(player, comp);
			cout << endl;
			cout << " Игрок " << (hod ? name1 : name2) << ", Ваша очередь.\n  Вы ходите " << (hod ? temp ? "крестиками" : "ноликами" : !temp ? "крестиками" : "ноликами") << ". Введите номер поля, которое Вы хотите занять." << endl;
			cout << "  Поля нумеруются следующим образом:" << endl;
			cout << polepic;
			cout << endl;
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
					if (vibor >= 1 && vibor <= 9 && fishkibili.find(positionsx[vibor - 1]) != fishkibili.end())
						break;
				}
				catch (...)
				{
					vibor = 0;
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
				system("cls");
				cout << endl;
				!temp ? drawttt(comp, player) : drawttt(player, comp);
				cout << endl;
				cout << " Игрок " << (hod ? name1 : name2) << ", Ваша очередь.\n  Вы ходите " << (hod ? temp ? "крестиками" : "ноликами" : !temp ? "крестиками" : "ноликами") << ". Введите номер поля, которое Вы хотите занять." << endl;
				cout << "  Поля нумеруются следующим образом:" << endl;
				cout << polepic;
				cout << endl;
				if (vibor > 0 && vibor < 10 && fishkibili.find(positionsx[vibor - 1]) == fishkibili.end())
				{
					cout << "  Это поле уже занято. Выберите другое.\n";
				}
				cout << "  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
				tmp++;
				str = "";
				playsound("negative.mp3", "");
			}
			fishkibili.erase(positionsx[vibor - 1]);
			hod ? player.insert(positionsx[vibor - 1]) : comp.insert(positionsx[vibor - 1]);
			cout << "  Хорошо." << endl;
			if (hod)
				hod = false;
			else
				hod = true;
		}

		system("cls");
		cout << namepictt;
		cout << "\n\n\n\n";
		cout << "  Игра \"Крестики-нолики\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n";
		string text = namepictt + "\n\n\n\n  Игра \"Крестики-нолики\"\n\n  МЕНЮ\n\n\t1 - сыграть ещё раз\n\t2 - вернуться к выбору режима игры\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		vibor = read(text, 1, 2);
		if (vibor == 2)
			break;
	}
}

void startttt()
{
	if (music)
	{
		mciSendString(L"open \"audio/8.mp3\" alias geight", NULL, 0, NULL);
		mciSendString(L"play geight repeat", NULL, 0, NULL);
	}
	while (true)
	{
		system("cls");
		string text = namepictt + "\n\n\n\n  Игра \"Крестики-нолики\"\n  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
		cout << namepictt;
		cout << "\n\n\n\n";
		cout << "  Игра \"Крестики-нолики\"\n" << endl;
		cout << "  МЕНЮ\n\n\t1 - начать игру\n\t2 - помощь\n\t3 - в главное меню\n\n";
		int vibor = read(text, 1, 3);
		if (vibor == 1)
		{
			while (true)
			{
				system("cls");
				string text = namepictt + "\n\n\n\n  Игра \"Крестики-нолики\"\n\n  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
				cout << namepictt;
				cout << "\n\n\n\n";
				cout << "  Игра \"Крестики-нолики\"\n" << endl;
				cout << "  ВЫБЕРИТЕ РЕЖИМ ИГРЫ\n\n\t1 - с компьютером\n\t2 - вдвоем с другом (или не другом)\n\t3 - назад\n\n";
				int vibor = read(text, 1, 3);
				if (vibor == 1)
					PVI4();
				else if (vibor == 2)
					PVP4();
				else if (vibor == 3)
					break;
			}
		}

		else if (vibor == 2)
		{
			system("cls");
			cout << namepictt;
			cout << "\n\n\n\n";
			cout << "  Игра \"Крестики-нолики\"\n" << endl;
			cout << "  ПРАВИЛА. " << endl << endl;
			cout << "  Дано поле 3 на 3 клетки.\n  Два игрока, по очереди, делают ход и ставят в свободную клетку \"крестик\" или \"нолик\"\n  (один игрок ставит только \"крестики\", а другой - только \"нолики\").\n  Игрок, которому удастся разместить три своих знака в горизонтальном,\n  вертикальном или диагональном ряду, становится победителем.\n  Все просто.\n\n  ";
			system("pause");
		}

		else if (vibor == 3)
			break;
	}
	mciSendString(L"close geight", NULL, 0, NULL);
}