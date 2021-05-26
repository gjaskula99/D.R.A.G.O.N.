//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#ifndef mrhil_h
#define mrhil_h

#include <string>
using namespace std;

class mrhil_sys
{
	public:
	string login;
	string haslo;
};

class mrhil_grant
{
	public:
	bool active;
	int ammount;
	int coolout;
	int time;
	//Metody
	void getnew_coolout();
	void set_time();
	int get_grant(int random, int zadowolenie);
};

#endif
