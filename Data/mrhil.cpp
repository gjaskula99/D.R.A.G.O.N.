//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "mrhil.h"

void mrhil_grant::getnew_coolout()
{
	this->coolout--;
	if(this->coolout<0) this->coolout=0;
}

void mrhil_grant::set_time()
{
	this->time--;
	if(this->time<0) this->time=0;
}

int mrhil_grant::get_grant(int random, int zadowolenie)
{
	if( (random*zadowolenie ) > this->ammount ) return this->ammount;
	else return 0;
}
