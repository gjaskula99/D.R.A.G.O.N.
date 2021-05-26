//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "mechanics.hpp"
#include "class.h"

using namespace std;

//Metody
void ewidencja::getnew_stopien(int zadowolenie, int los)
{
	if(this->stopien_cooldown==0)
	{
		if(zadowolenie+los>140) 
		{
			this->stopien++;
			this->stopien_cooldown=los/20;
		}
		if(this->stopien>7) this->stopien=7;
	}
}
//Sk³adki
float druzyna::skladki(float saldo)	//Usun¹æ po wdro¿eniu losowoœci wp³at sk³¹dek
{
	saldo+=czlonkowie*wys_skladki;
	return saldo;
}

void ewidencja::reset_zalegle_skladki(int i)
{
	this->zalegle_skladki=0;
}

int ewidencja::set_zalegle_skladki(int zalegle, float zadowolenie, int los) //Wycofane
{
	if(zadowolenie>70) return zalegle;
	else
	{
		if(zadowolenie<=30)
		{
			if(2*los>50) return zalegle++;
		}
		else
		{
			if(los>50) return zalegle++;
		}
	}
}

int ewidencja::rand_skladki(int los, float zadowolenie, int skladka)
{
	this->zalegle_skladki++;
	if( (los*zadowolenie)/100<30) 
	{
		return 0;
	}
	else
	{
		int wplata=this->zalegle_skladki*skladka;
		this->zalegle_skladki=0;
		return wplata;
	}
}

//Ewidencja
void ewidencja::insertdata(int los, int los2)	//Wpisanie danych na starcie
{
	if(los>50) this->plec='K';
	else	this->plec='M';
	if(this->plec=='K')
	{
		this->imie=imieK[los/2];
		this->nazwisko=nazwiskoK[los2/2];
		this->stopien=los2/25;
	}
	else 
	{
		this->imie=imieM[los/2];
		this->nazwisko=nazwiskoM[los2/2];
		this->stopien=los2/25;
	}
	this->stopien_cooldown=los/20;
	this->akcje=0;
	this->udzial=0;
	this->frekwencja=100;
}

string ewidencja::show_stopien(int stopien, char plec)
{
	if(plec=='K')
	{
		switch(stopien)
		{
			case 0	:	return stopienK[0];
			case 1	:	return stopienK[1];
			case 2	:	return stopienK[2];
			case 3	:	return stopienK[3];
			case 4	:	return stopienK[4];
			case 5	:	return stopienK[5];
			case 6	:	return stopienK[6];
		}
	}
	else
	{
		switch(stopien)
		{
			case 0	:	return stopienM[0];
			case 1	:	return stopienM[1];
			case 2	:	return stopienM[2];
			case 3	:	return stopienM[3];
			case 4	:	return stopienM[4];
			case 5	:	return stopienM[5];
			case 6	:	return stopienM[6];
		}
	}
}

void ewidencja::set_frekwencja(int random, float zadowolenie)
{
	this->akcje++;
	if(random+zadowolenie>100) this->udzial++;
	this->frekwencja=(this->udzial/this->akcje)*100;
}

void ewidencja::del_selected()
{
	this->imie="";
	this->nazwisko="";
	this->plec='X';
	this->zalegle_skladki=0;
	this->stopien=0;
	this->akcje=0;
	this->udzial=0;
	this->frekwencja=0;
}

string instruktor::showLevel(float level)
{
	switch( (int)level )
	{
		case 0	:	return ins[0];
		case 1	:	return ins[1];
		case 2	:	return ins[2];
		default	:	return ins[0];
	}
}

