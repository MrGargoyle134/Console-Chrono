#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int seconds = 0;
int minutes = 0;
int heures = 0;

int numTour = 0;
bool tourT;
void tour(int ts, int tm, int th)
{
    cout << "TOUR " << numTour <<": "<<th<<":"<<tm<<":"<<ts<<endl;
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
    cout << "(C) Bilal Bouamer 2020.                               CHRONO v1.2\n\n";
    cout << "(L) LANCER    (P) PAUSE    (A) ARRETER    (T) TOUR    (Q) QUITTER\n";
    cout << "+---------------------------------------------------------------+\n";
    cout <<"                             "<<heures<<":"<<minutes<<":"<<seconds<<endl;
    cout << "+---------------------------------------------------------------+\n";
    if(GetAsyncKeyState('T')){tour(seconds, minutes, heures);}
    if(GetAsyncKeyState('Q')){return 0;}
    Sleep(1000);
    system("cls");
    }
}
