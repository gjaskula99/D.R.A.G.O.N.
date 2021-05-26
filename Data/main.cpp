//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

using namespace std;	//Deklaracja przestrzeni nazw

//In Further Development
//1. Blad z komisja rewizyjna - On w ogóle jeszcze ¿yje?
//2. Poziomy trudnoœci - czesciowo wprowadzone przez stopieñ instruktorski

//Biblioteki w³asne
#include "simulation.h"			//G³ówny plik symulacji
//Zmienne globalne
int choice=0;					//Operator switchów
bool mode_unlimited;			//Tryb gry
unsigned int tury=1;			//Licznik tur gry nieskoñczonej
bool load_save=false;			//Wczytywanie gry

int main(int argc, char** argv)	//Main
{
	system("title D.R.A.G.O.N.");
	title();
	while(true)		//Menu startowe
	{
		check_dev();
		cout << "Witamy w DRuzynowej Aplikacji GOspodarowania ewideNcja - Kryptonim DRAGON\n\n";
		cout << "Wybierz jeden z nastepujacych trybow: \n";
		cout << "1. Tryb symulacji rocznej - prowadz druzyne przez 12 miesiecy\n";
		cout << "2. Tryb nieskonczony - przetrwaj jak najdluzej\n";
		cout << "3. Licencja i uwagi prawne\n4. Instrukcja Polowa\n5. Przelacz tryb pelnoekranowy\n6. Wczytaj zapisana gre\n";
		cout << "0. Wyjscie\n";
		cout << "\nTwoj wybor: ";
		cin >> choice;
		switch(choice)
		{
			case	1	:	mode_unlimited=false;
							break;
			case	2	:	mode_unlimited=true;
							break;
			case	3	:	pomoc();
							break;
			case	4	:	manual();
							break;
			case	5	:	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //Fullscreen
							break;
			case	6	:	load_save=true;
							break;
			case	0	:	cout << "Wylaczanie aplikacji...\n";
							sleep(1);
							exit(0);
							break;
			default		:	cout << "Wprowadzona opcja jest niepoprawna.\n";
							anykey();
							break;
		}
		system("cls");
		if(choice==1||choice==2||choice==6) break;
	}
	sim(choice, mode_unlimited, tury, load_save);
	return 0;
}

//int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
//	main(0, (char**) 0);
//}
