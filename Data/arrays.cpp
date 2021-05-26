//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "arrays.h"

using namespace std;
//HALIZ
string stanica[20]={"Lowyn", "Jaroslawiec", "Podgaje", "Kosarzyska", "Gory Stolowe", "Lgnin", "Gorzewo", "Buk", "Imiolki", "Ostrow Wielkopolski", //10
"Branica", "Bukowina", "Polko", "Szczytno", "Gapowo", "Suchow", "Zacisze", "Solniki", "Mechlin", "Toczyska"}; //20

//Ewidencja
string imieM[50]={"Adam", "Adrian", "Andrzej", "Aleks", "Albert", "Aleksander", "Bartosz", "Cyprian", "Cyrus", "Damian",	//10
"Dariusz", "Daniel", "Dawid", "Dominik", "Emil", "Eryk", "Fryderyk", "Gerald", "Igor", "Iwan",	//20
"Ireneusz", "Jacek", "Janusz", "Jaroslaw", "Jerzy", "Julian", "Kajetan", "Kacper", "Konrad", "Michal",	//30
"Maksymilian", "Marcin", "Marek", "Mateteusz", "Mikolaj", "Oliwer", "Oskar", "Patryk", "Pawel", "Piotr",	//40
"Radoslaw", "Rafal", "Robert", "Ryszard", "Sebastian", "Slawomir", "Stefan", "Szymon", "Tadeusz", "Zenon"};	//50
string imieK[50]={"Ada", "Adriana", "Agata", "Agnieszka", "Aldona", "Aleksandra", "Barbara", "Beata", "Bozena", "Celina",	//10
"Celestyna", "Danuta", "Daria", "Dorota", "Doris", "Edyta", "Eliza", "Elzbieta", "Ewa", "Ewelina",	//20
"Ida", "Irena", "Iza", "Iwona", "Jagoda", "Justyna", "Julia", "Kaja", "Katarzyna", "Klaudia",	//30
"Lena", "Magda", "Magda", "Magdalena", "Maja", "Maria", "Marianna", "Martyna", "Monika", "Natalia",	//40
"Natasza", "Patrycja", "Paulina", "Renata", "Sabina", "Sandra", "Sara", "Sylwia", "Weronika", "Zofia"};	//50
string nazwiskoM[50]={"Antkowiak", "Adamczyk", "Andrzejewicz", "Bednarek", "Bielecki", "Borowski", "Cebula", "Czaja", "Cichy", "Debinski", //10
"Debski", "Dlugosz", "Dudek", "Fabianowicz", "Gajda", "Gajewicz", "Gapinski", "Harasimowicz", "Hildebrandt", "Iwanowski", //20
"Jachowicz", "Jaki", "Kaczmarski", "Kot", "Kowalski", "Kurek", "Lecki", "Mroz", "Niedziela", "Olejniczak", //30
"Paluszkiewicz", "Pawlak", "Piotrowicz", "Romanow", "Ruszkiewicz", "Rudkowski", "Ryba", "Sarnowski", "Sikora", "Stasiak", //40
"Stonoga", "Szura", "Tarnowicz", "Trzeciak", "Ulanowicz", "Walczak", "Wilk", "Zagozda", "Zeromski", "Zuchowicz"}; //50
string nazwiskoK[50]={"Antkowicz", "Adamkiewicz", "Andrzejewicz", "Bednarek", "Bielecka", "Borowska", "Czosnowska", "Czaja", "Cicha", "Debinska", //10
"Debska", "Dlugosz", "Dudek", "Fabianowicz", "Gajda", "Gajewicz", "Gapinska", "Gniazdowska", "Hildebrandt", "Iwanowska", //20
"Jakubiak", "Janiak", "Kaczmarska", "Kot", "Kowalska", "Lewandowska", "Lecka", "Mroz", "Niedziela", "Nowicka", //30
"Olesiak", "Okon", "Osuch", "Piasecka", "Raczka", "Rudkowska", "Ryba", "Sarnowska", "Sikora", "Slowik", //40
"Swoboda", "Tatarowicz", "Trojanek", "Trzeciak", "Urbaniak", "Wanczyk", "Wilk", "Zagozda", "Zeromska", "Zgoda"}; //50

//Stopnie
string stopienM[7]={"Brak", "Mlodzik", "Wywiadowca", "Odkrywca", "Cwik", "Harcerz Orli", "Harcerz Rzeczypospolitej"};
string stopienK[7]={"Brak", "Ochotniczka", "Tropicielka", "Pionierka", "Samarytanka", "Harcerka Orla", "Harcerka Rzeczypospolitej"};
string ins[3]={"Pwd.", "Phm.", "Hm."};
