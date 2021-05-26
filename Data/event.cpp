//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON
//Tê czêœæ planu ustalimy póŸniej

#include "event.h"

//Dane Eventów
string event_title[10] = {"Podwyzszenie skladek", "Obnizenie skladek", "Nowy narybek",
"Darowizna", "Swieto Narodowe", "Rozmowa wychowawcza",
"Nowa Fala", "Impreza Hufca",
"Blad w fakturach", "Rozkaz Komendanta"};
string event_desc[10] = {"Komenda Hufca podniosla skladki o 5 PLN", "Komenda Hufca obnizyla skladki o 5 PLN", "Do Twojej druzyny doszla nowa osoba",
"Twoja druzyna otrzymala darowizne w wysokosci 400 PLN", "Partia oglosila najblizszy piatek Swietem Narodowym.", "Rodzice dzieci odbyli wyczerpujaca rozmowe z instruktorem",
"Druzynowy znalazl nowa motywacje do dzialania", "Komenda Hufca zorganizowala impreze integracyjna dla wszystkich jednostek",
"Ksiegowosc Hufca wykryla bledy w rozliczeniu ostatniego biwaku", "Komendant Hufca wydal nowy rozkaz"};


bool event::new_event(int random)
{
	if(random>65)
	{
		int r = rand() % 10;
		this->id = r;
		this->title = event_title[this->id];
		this->desc = event_desc[this->id];
		return true;
	}
	return false;
}
