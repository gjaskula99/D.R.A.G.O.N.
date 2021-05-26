//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON
//Tê czêœæ planu ustalimy póŸniej

#ifndef event_h
#define event_h

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class event	//In Further Development
{
	public:
	int id;
	string title;
	string desc;
	//Metody
	bool new_event(int rand);
};

//Dane Eventów
extern string event_title[];
extern string event_desc[];

#endif
