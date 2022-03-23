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

HANDLE hConsole;
bool music = true;
bool sounds = true;
string menuh =
R"(
  ##   ## ####### ####### ##     ##
  ##  ### ##      ##   ## ##     ## 
  ## # ## ##      ####### ###### ## 
  ###  ## ##      ##      ##  ## ## 
  ##   ## ##      ##      ###### ##)";
const auto biglogo =
R"(                                                               
                                 ,,,;;;;::::::;;;;,,                       
                            ,,;:ccllllllllllllllllllcc:;,                  
                ,,,,,,,  ,;:cllllllllllllllllllllllllllllc:;,  ,,,,,,,     
             ,:okO0K0kxl:cllllllllllllllllllllllllllllllllllc:oxO0K0Oxl;,  
            :xKWMMMMMMWNOollllllllllllllllllllllllllllllllllxKNMMMMMMMN0o, 
           :kNMMMMMMMMN0OkolllllllllllllllllllllllllllllllldOOKWMMMMMMMMXo,
           oXMMMMMMMWXc.  cllllllllllllllllllllllllllllllll;. .kMMMMMMMMWO:
           oXMMMMMMMMNo..;lllllllllllllllllllllllllllllllllc .;OMMMMMMMMWO:
           :kNMMMMMMMMWXKOollllllllllllllllllllllllllllllllxKXNMMMMMMMMWKl,
            :d0NWMMMMMWXkllllllllllllllccllllccllllllllllllld0NWMMMMMWXOl, 
             ,;lxOOOOkxolllllllllllllll;;cllc;;llllllllllllllldkOOOOkdc,   
               ,clcclllllllllllllllllllllllllllllllllllllllllllllccclc,    
                :llllllllllllllllllloooddddddoooollllllllllllllllllllc,    
                ;lllllllllllloxxkxdoollllllllllloodxkxdolllllllllllll:     
                ,cllllllllld0Kkc ..               ..,lOKOdclllllllllc,     
                 ;clllllllldOKkc ..               ..,lOKOoclllllllll;      
                  ;clllllllllodxxxooollclllccclloodxxxdolllllllllll;       
                   ,clllllllllllllllooooooooooooollclllllllllllllc,        
                     ;cllllllllllllllllllllllllllllllllllllllllc;,         
                      ,;cllllllllllllllllllllllllllllllllllllc;,           
                         ,:cllllllllllllllllllllllllllllllc:;              
                            ,;:cllllllllllllllllllllllc:;,                 
                                ,,;;:::cccccccc:::;;;,                     
                                         ,,,,                      
)";
const auto biglogoclose =
R"(                                                               
                                 ,,,;;;;::::::;;;;,,                       
                            ,,;:ccllllllllllllllllllcc:;,                  
                ,,,,,,,  ,;:cllllllllllllllllllllllllllllc:;,  ,,,,,,,     
             ,:okO0K0kxl:cllllllllllllllllllllllllllllllllllc:oxO0K0Oxl;,  
            :xKWMMMMMMWNOollllllllllllllllllllllllllllllllllxKNMMMMMMMN0o, 
           :kNMMMMMMMMN0OkolllllllllllllllllllllllllllllllldOOKWMMMMMMMMXo,
           oXMMMMMMMMMWNOkcllllllllllllllllllllllllllllllllckONWMMMMMMMMWO:
           oXMMMMMMMMMWXOklllllllllllllllllllllllllllllllllckOXOMMMMMMMMWO:
           :kNMMMMMMMMWXKOollllllllllllllllllllllllllllllllxKXNMMMMMMMMWKl,
            :d0NWMMMMMWXkllllllllllllllccllllccllllllllllllld0NWMMMMMWXOl, 
             ,;lxOOOOkxolllllllllllllll;;cllc;;llllllllllllllldkOOOOkdc,   
               ,clcclllllllllllllllllllllllllllllllllllllllllllllccclc,    
                :llllllllllllllllllloooddddddoooollllllllllllllllllllc,    
                ;lllllllllllloxxkxdoollllllllllloodxkxdolllllllllllll:     
                ,cllllllllld0Kkc ..               ..,lOKOdclllllllllc,     
                 ;clllllllldOKkc ..               ..,lOKOoclllllllll;      
                  ;clllllllllodxxxooollclllccclloodxxxdolllllllllll;       
                   ,clllllllllllllllooooooooooooollclllllllllllllc,        
                     ;cllllllllllllllllllllllllllllllllllllllllc;,         
                      ,;cllllllllllllllllllllllllllllllllllllc;,           
                         ,:cllllllllllllllllllllllllllllllc:;              
                            ,;:cllllllllllllllllllllllc:;,                 
                                ,,;;:::cccccccc:::;;;,                     
                                         ,,,,                        
)";
const char* gamename[12] =
{
    R"(
        ____ 
       / __ \
      / /_/ /
     / ____/ 
    /_/   
    )",
    R"(
        ____  ___ 
       / __ \/   |
      / /_/ / /| |
     / ____/ ___ |
    /_/   /_/  |_|
    )",
    R"(
        ____  ___    _   __
       / __ \/   |  / | / /
      / /_/ / /| | /  |/ / 
     / ____/ ___ |/ /|  /  
    /_/   /_/  |_/_/ |_/   
    )",
        R"(
        ____  ___    _   __   __ __
       / __ \/   |  / | / /  / //_/
      / /_/ / /| | /  |/ /  / ,<  
     / ____/ ___ |/ /|  /  / /| | 
    /_/   /_/  |_/_/ |_/  /_/ |_|
    )",
    R"(
        ____  ___    _   __   __ __ ___ 
       / __ \/   |  / | / /  / //_//   |
      / /_/ / /| | /  |/ /  / ,<  / /| |
     / ____/ ___ |/ /|  /  / /| |/ ___ |
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_|
    )",
    R"(
        ____  ___    _   __   __ __ ___    ____ 
       / __ \/   |  / | / /  / //_//   |  / __ \
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ /
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ 
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_|
    )",
        R"(
        ____  ___    _   __   __ __ ___    ____  ___ 
       / __ \/   |  / | / /  / //_//   |  / __ \/   |
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| |
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_|
    )",
    R"(
        ____  ___    _   __   __ __ ___    ____  ___   _____
       / __ \/   |  / | / /  / //_//   |  / __ \/   | / ___/
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| | \__ \ 
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |___/ /
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/
    )",
    R"(
        ____  ___    _   __   __ __ ___    ____  ___   _____ ____
       / __ \/   |  / | / /  / //_//   |  / __ \/   | / ___//  _/
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| | \__ \ / /
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |___/ // / 
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/___/
    )",
        R"(
        ____  ___    _   __   __ __ ___    ____  ___   _____ ________ 
       / __ \/   |  / | / /  / //_//   |  / __ \/   | / ___//  _/ __ \
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| | \__ \ / // / / /
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |___/ // // /_/ / 
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/___/\___\_|
    )",
    R"(
        ____  ___    _   __   __ __ ___    ____  ___   _____ ________  __  __
       / __ \/   |  / | / /  / //_//   |  / __ \/   | / ___//  _/ __ \/ / / /
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| | \__ \ / // / / / / / / 
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |___/ // // /_/ / /_/ / 
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/___/\___\_\____/
    )",
    R"(
        ____  ___    _   __   __ __ ___    ____  ___   _____ ________  __  ________
       / __ \/   |  / | / /  / //_//   |  / __ \/   | / ___//  _/ __ \/ / / / ____/
      / /_/ / /| | /  |/ /  / ,<  / /| | / /_/ / /| | \__ \ / // / / / / / / __/   
     / ____/ ___ |/ /|  /  / /| |/ ___ |/ _, _/ ___ |___/ // // /_/ / /_/ / /___   
    /_/   /_/  |_/_/ |_/  /_/ |_/_/  |_/_/ |_/_/  |_/____/___/\___\_\____/_____/   
    )"
                      };
class MyException : public exception
{
public:
    MyException()
    {

    }
};
void startgameygchislo();
void startttt();
void startgamemathes();
void startgamehangman();
void startdices();
void startgamefishki();
void startrf();

void playsound(string soundname, string musicalias)
{
    wstring s = wstring(soundname.begin(), soundname.end());
    wstring m = wstring(musicalias.begin(), musicalias.end());
    if (sounds)
    {
        Sleep(100);
        mciSendString((L"open \"audio/" + s + L"\" alias st").c_str(), NULL, 0, NULL);

        while (_kbhit()) _getch();
        if (music)
            mciSendString((L"setaudio " + m + L" volume to 10").c_str(), NULL, 0, NULL);
        mciSendString(L"setaudio st volume to 1000", NULL, 0, NULL);
        mciSendString(L"play st from 0 wait", NULL, 0, NULL);
        mciSendString(L"close st", NULL, 0, NULL);
        if (music)
            mciSendString((L"setaudio " + m + L" volume to 1000").c_str(), NULL, 0, NULL);
        while (_kbhit()) _getch();
    }
}
int read(string msg, int b, int e)
{
    
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
            if (vibor >= b && vibor <= e)
                return vibor;
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
        cout << msg;
        playsound("negative.mp3", "");
        tmp++;
        str = "";
    }
}
string readstr(string msg)
{
    string str = "";
    char ch;
    int tmp = 0;
    cout << "  ";
    while (_kbhit()) _getch();
    while (true)
    {

        while (cin.get(ch))
        {
            if (ch == '\n')
                break;
            str += ch;
        }
        if (str.length() != 0)
            return str;
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
        cout << msg;
        playsound("negative.mp3", "");
        tmp++;
        str = "";
    }
}
void selectgame()
{
    while (true)
    {
        system("cls");
        cout << menuh;
        cout << "\n\n\n\n";
        cout << "  ВЫБЕРИТЕ ИГРУ\n\n\t1 - \"Угадай число\"\n\t2 - \"Виселица\"\n\t3 - \"Спички\"\n\t4 - \"Кости\"\n\t5 - \"Фишки\"\n\t6 - \"Российский флаг\"\n\t7 - \"Крестики-нолики\"\n\n\t0 - назад\n";
        string text = "\n\n\n\n  ВЫБЕРИТЕ ИГРУ\n\n\t1 - \"Угадай число\"\n\t2 - \"Виселица\"\n\t3 - \"Спички\"\n\t4 - \"Кости\"\n\t5 - \"Фишки\"\n\t6 - \"Российский флаг\"\n\t7 - \"Крестики-нолики\"\n\n\t0 - назад\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
        int vibor;
        
        char result[300];
        try
        {
            vibor = read(menuh + text, 0, 8);
        }
        catch (...)
        {
            return;
            break;
        }
       
        if (vibor == 1)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startgameygchislo();
            }
            catch (...)
            {
                mciSendString(L"close gone", NULL, 0, NULL);
            }          
            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 2)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startgamehangman();
            }
            catch (...)
            {
                mciSendString(L"close gtwo", NULL, 0, NULL);
            }
            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 3)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startgamemathes();
            }
            catch (...)
            {
                mciSendString(L"close gthree", NULL, 0, NULL);
            }
            
            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 4)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startdices();
            }
            catch (...)
            {
                mciSendString(L"close gfour", NULL, 0, NULL);
            }

            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 5)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startgamefishki();
            }
            catch (...)
            {
                mciSendString(L"close gfive", NULL, 0, NULL);
            }

            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 6)
        {
            mciSendString(L"pause menumusic", NULL, 0, NULL);
            try
            {
                startrf();
            }
            catch (...)
            {
                mciSendString(L"close gseven", NULL, 0, NULL);
            }
            system("cls");
            if (music)
                mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }
        else if (vibor == 7)
        {
        mciSendString(L"pause menumusic", NULL, 0, NULL);
        try
        {
            startttt();
        }
        catch (...)
        {
            mciSendString(L"close geight", NULL, 0, NULL);
        }

        system("cls");
        if (music)
            mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
        }

        else if (vibor == 0)
            break;
    }
}

void main()
{
    int vibor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    SetConsoleTextAttribute(hConsole, 14);
    HWND hwnd;
    hwnd = GetConsoleWindow();
    MoveWindow(hwnd, 200, 50, 900, 650, TRUE);
    mciSendString(L"play \"audio/logo.mp3\"", NULL, 0, NULL);
    for (int i = 0; i < 12; i++)
    {
        system("cls");
        if (i % 4 == 2)
        {
            cout << biglogoclose;
            cout << gamename[i];
        }
        else
        {
            cout << biglogo;
            cout << gamename[i];
        }
        Sleep(250);
    }
    Sleep(5000);
    system("cls");
    mciSendString(L"open \"audio/0.mp3\" alias menumusic", NULL, 0, NULL);
    mciSendString(L"play menumusic repeat", NULL, 0, NULL);
    while (true)
    {
        system("cls");
        string text = menuh + "\n\n\n\n  МЕНЮ\n\n\t1 - выбрать игру\n\t2 - открыть настройки\n\t3 - информация о программе\n\t4 - выйти из программы\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";
        cout << menuh;
        cout << "\n\n\n\n";
        cout << "  МЕНЮ\n\n\t1 - выбрать игру\n\t2 - открыть настройки\n\t3 - информация о программе\n\t4 - выйти из программы\n";
        try
        {
            vibor = read(text, 1, 4);
        }
        catch (...)
        {
            return;
            break;
        }

        if (vibor == 1)
        {
            selectgame();
            system("cls");
        }
        else if (vibor == 2)
        {
            bool temmp = music;
            while (true)
            {
               
                system("cls");
                string t1 = music ? "ВКЛЮЧЕНА" : "ВЫКЛЮЧЕНА", t2 = sounds ? "ВКЛЮЧЕНЫ" : "ВЫКЛЮЧЕНЫ";
                string text = menuh + "\n\n\n\n  НАСТРОЙКИ.\n\n\tМузыка: " + t1 + "\n\tЗвуковые эффекты: " + t2 + "\n\n  ВВЕДИТЕ\n\n\t1 - включить/выключить музыку\n\t2 - включить/выключить звуковые эффекты\n\t3 - назад в меню\n\n  Похоже вы ввели что-то не то. Попробуйте еще разок.\n  ";

                cout << menuh + "\n\n\n\n  НАСТРОЙКИ. " << endl << endl;
                cout << "\tМузыка: " << (music ? "ВКЛЮЧЕНА" : "ВЫКЛЮЧЕНА") << endl;
                cout << "\tЗвуковые эффекты: " << (sounds ? "ВКЛЮЧЕНЫ" : "ВЫКЛЮЧЕНЫ") << endl << endl;
                cout << "  ВВЕДИТЕ\n\n\t1 - включить/выключить музыку\n\t2 - включить/выключить звуковые эффекты\n\t3 - назад в меню\n";
                try
                {
                    vibor = read(text, 1, 3);
                }
                catch (...)
                {
                    return;
                    break;
                }
                if (vibor == 1)
                {
                    music = !music;
                }
                else if (vibor == 2)
                {
                    sounds = !sounds;
                }
                else if (vibor == 3)
                {
                    if (!music)
                        mciSendString(L"pause menumusic", NULL, 0, NULL);
                    else if (temmp != 1)
                        mciSendString(L"play menumusic from 0 repeat", NULL, 0, NULL);
                    break;
                }
            }
        }

        else if (vibor == 3)
        {
            system("cls");

            cout << menuh + "\n\n\n\n  ИНФОРМАЦИЯ ОБ ИГРЕ. " << endl << endl;
            cout << "\tМузыка, используемая в игре не принадлежит автору.\n\tЕсли ее использование нарушает Ваши авторские права, то для урегулирования этого вопроса свяжитесь с автором." << endl;
            cout << "\n\tПо всем вопросам, а также при обнаружении ошибок, убедительная просьба обращаться по указаному e-mail адресу." << endl << endl;
            cout << "\te-mail для связи: semp21@mail.ru\n\n  ";
            system("pause");
        }
        else if (vibor == 4)
            break;
    }
}
