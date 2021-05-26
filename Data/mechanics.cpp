//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "mechanics.hpp"//Nag³ówki mechaniki

using namespace std;

//Sta³e - Konsola Generatora Mocy 12-01
const string ver="1.1"; 	//Zmieniæ z now¹ wersj¹
const bool developer_active=false;		//Bloki Operacyjne - TYLKO DO U¯YTKU DLA DEWELOPERÓW!!!

//Funkcje istotne
void check_dev()	//Sprawdzenie czy opcje deweloperskie sa wlaczone
{
	if(developer_active==true)
	{
		setColor(11);
		cout << "!UWAGA! Opcje deweloperskie sa aktywne\n\n";
		setColor(7);
	}
}

bool dev_115()		//Konsola generatora mocy 12-01 zabezpieczona kodem
{
	if(developer_active==true) return true;
	else return false;
}

void anykey()		//Wcisnij Any Key'a
{
	cout << "Wcisnij dowolny klawisz aby kontynuowac...";
	system("pause>NUL");
	cout << "\n";
}

void title()		//Wyœwietlanie tytu³u
{
	PlaySound(TEXT("Data/Snd/start.wav"), NULL, SND_FILENAME | SND_ASYNC);
	string title ="DRuzynowa Aplikacja GOspodarowania ewideNcja- DRAGON";
	for(int i=0; i<title.length(); i++)
	{
		cout << title[i];
		usleep(50);
	}
	cout << "\nWersja ";
	for(int i=0; i<ver.length(); i++)
	{
		cout  << ver[i];
		usleep(50);
	}
	cout << "\n\n";
	//anykey();
	sleep(1);
	system("cls");
}

void lordgg()		//Zagramy w pewn¹ grê
{
	cout << "Zagramy\n";
	sleep(1);
	cout << "w pewna\n";
	sleep(1);
	cout << "gre...\n";
	sleep(1);
	system("cls");	
}

void pomoc()		//Licencja
{
	system("cls");
	system("type readme.txt");
	cout << "\n";
	anykey();
}

void manual()		//Instrukcja
{
	system("cls");
	system("type manual.txt");
	cout << "\n";
	anykey();
}

//Mechanika
string mies(int miesiac)	//Wyswietlanie nazwy miesiaca
{
	switch(miesiac)
	{
		case 1	:	return "Styczen";
		case 2	:	return "Luty";
		case 3	:	return "Marzec";
		case 4	:	return "Kwiecien";
		case 5	:	return "Maj";
		case 6	:	return "Czerwiec";
		case 7	:	return "Lipiec";
		case 8	:	return "Sierpien";
		case 9	:	return "Wrzesien";
		case 10	:	return "Pazdziernik";
		case 11	:	return "Listopad";
		case 12	:	return "Grudzien";
		default	:	return "MISSING STRING";
	}
}

void setColor(unsigned short color)	//KOLORKI
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

//Zakoñczenia
void ending_good()
{
	cout << "Minal rok - symulacja zostala zakonczona\n";
}

void ending_people()
{
	cout << "Z twojej druzyny odeszli wszyscy czlonkowie.\nJak mozna bylo do czegos takiego dopuscic?!\n";
}

void ending_hajs()
{
	cout << "Twoja druzyna osiagnela niewyplacalnosc.\nJak mozna bylo do czegos takiego dopuscic?!\n";
}

void ending_komisja()
{
	cout << "Sledztwo komisji rewizyjnej wykazalo powazne nieprawidlowosci.\nKomendant hufca odwolal Cie z funkcji.\nJak mozna bylo do czegos takiego dopuscic?!\n";
}

void ending_leader()
{
	cout << "W wyniku skrajnego przemeczenia druzynowy nie jest w stanie pelnic swojej funkcji.\nJak mozna bylo do czegos takiego dopuscic?!\n";
}
