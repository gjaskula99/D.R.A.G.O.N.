//DRu�ynowa Aplikacja GOspodarowania ewideNcja - DRAGON
//T� cz�� planu ustalimy p�niej

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

//Dane Event�w
extern string event_title[];
extern string event_desc[];

#endif
