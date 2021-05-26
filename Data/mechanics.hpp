//DRu�ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#ifndef mechanics_hpp
#define mechanics_hpp

//Biblioteki
#include <iostream>	//IO
#include <iomanip>	//Manipulacja IO
#include <string>	//Stringi
#include <ctime>	//Czas
#include <cstdlib>	//Standardy C
//#include <unistd.h>	//Usleep
#include <math.h>	//Funkcje matematyczne
#include <windows.h>//Funkcje Mikromi�kkich Okien
#include <fstream>	//Obs�uga plik�w
#pragma comment(lib, "winmm.lib")

#define sleep(n) (Sleep((n)*1000))
#define usleep(n) (Sleep(n))

using namespace std;

//Funkcje istotne
void check_dev();	//Sprawdzenie czy opcje deweloperskie sa wlaczone
bool dev_115();		//Konsola generatora mocy 12-01 zabezpieczona kodem
void anykey();		//Wcisnij Any Key'a
void title();		//Wy�wietlanie tytu�u
void lordgg();		//Zagramy w pewn� gr�
void pomoc();		//Licencja
void manual();		//Instrukcja
//Funkcje mechaniki
string mies(int miesiac);	//Wyswietlanie nazwy miesiaca
void setColor(unsigned short color);	//KOLORKI
//Zako�czenia
void ending_good();			//Dobre
void ending_people();		//Odej�cie ludzi
void ending_hajs();			//Niewyp�acalno��
void ending_komisja();		//Odwo�anie
void ending_leader();		//Przemeczenie

#endif
