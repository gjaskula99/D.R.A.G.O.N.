//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

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
#include <windows.h>//Funkcje Mikromiêkkich Okien
#include <fstream>	//Obs³uga plików
#pragma comment(lib, "winmm.lib")

#define sleep(n) (Sleep((n)*1000))
#define usleep(n) (Sleep(n))

using namespace std;

//Funkcje istotne
void check_dev();	//Sprawdzenie czy opcje deweloperskie sa wlaczone
bool dev_115();		//Konsola generatora mocy 12-01 zabezpieczona kodem
void anykey();		//Wcisnij Any Key'a
void title();		//Wyœwietlanie tytu³u
void lordgg();		//Zagramy w pewn¹ grê
void pomoc();		//Licencja
void manual();		//Instrukcja
//Funkcje mechaniki
string mies(int miesiac);	//Wyswietlanie nazwy miesiaca
void setColor(unsigned short color);	//KOLORKI
//Zakoñczenia
void ending_good();			//Dobre
void ending_people();		//Odejœcie ludzi
void ending_hajs();			//Niewyp³acalnoœæ
void ending_komisja();		//Odwo³anie
void ending_leader();		//Przemeczenie

#endif
