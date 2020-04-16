#include <iostream>
#include <windows.h>

int seconds = 0;
int minutes = 0;
int heures = 0;

int numTour = 0;
bool tourT;
void tour(int ts, int tm, int th)
{
    std::cout << "TOUR " << numTour <<": "<<th<<":"<<tm<<":"<<ts<<std::endl;
}

void ClearScreen()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hStdOut == INVALID_HANDLE_VALUE) return;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    COORD homeCoords = { 0, 0 };
    DWORD count;
    if(!FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count)) return;
    if(!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

    SetConsoleCursorPosition(hStdOut, homeCoords);
}

bool estLance = false;

int main()
{
    for(;;)
    {
    if(GetAsyncKeyState('L')){estLance = true;}
    if(GetAsyncKeyState('P')){estLance = false;}
    if(GetAsyncKeyState('A')){estLance = false; seconds = 0; minutes = 0; heures = 0;}
    if(estLance)
    {
    seconds++;
    if(seconds == 60){minutes++;seconds=0;}
    if(minutes == 60){heures++;minutes=0;}
    }
    std::cout << "(C) Bilal Bouamer 2020.                               CHRONO v1.4\n\n";
    std::cout << "(L) LANCER    (P) PAUSE    (A) ARRETER    (T) TOUR    (Q) QUITTER\n";
    std::cout << "+---------------------------------------------------------------+\n";
    std::cout <<"                             "<<heures<<":"<<minutes<<":"<<seconds<<std::endl;
    std::cout << "+---------------------------------------------------------------+\n";
    if(GetAsyncKeyState('T')){tour(seconds, minutes, heures);}
    if(GetAsyncKeyState('Q')){return 0;}
    Sleep(1000);
    ClearScreen();

    }
}
