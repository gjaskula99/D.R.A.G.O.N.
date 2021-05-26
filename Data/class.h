//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "mechanics.hpp"//Mechanika
#include "arrays.h"		//Tablice
#include "event.h"		//Zdarzenia losowe

#ifndef class_h
#define class_h

using namespace std;

//Klasy
class instruktor
{
	public:
	string name;
	float hp;
	int level;
	//Metody
	string showLevel(float level);
};

class druzyna
{
	public:
	int numer;
	string nazwa;
	instruktor druzynowy;
	//Mechanika
	float saldo;
	float zadowolenie;
	int czlonkowie;
	int wys_skladki;
	int skladka_hufiec;
	int weekendy;
	//Metody
	float skladki(float saldo);
};

class ewidencja
{
	public:
	string imie;
	string nazwisko;
	char plec;
	int zalegle_skladki;
	int stopien;
	int stopien_cooldown;
	//Frekwencja
	float akcje;
	float udzial;
	float frekwencja;
	//Metody
	void getnew_stopien(int zadowolenie, int los);
	//Sk³adki
	void reset_zalegle_skladki(int i);
	int set_zalegle_skladki(int zalegle, float zadowolenie, int los);	//Wycofane
	int rand_skladki(int los, float zadowolenie, int skladka);
	//Ewidencja
	void insertdata(int los, int los2);
	string show_stopien(int stopien, char plec);
	void set_frekwencja(int random, float zadowolenie);
	void del_selected();
};

//Dane losowañ HALIZ
struct haliz
{
	string lokalizacja;
	int koszt;
	int dlugosc;	
};

#endif
