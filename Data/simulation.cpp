//DRu¿ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#include "simulation.h"

//TO JEST G£ÓWNY PLIK SYMULACJI
//NIE TYKAÆ BO 23

//Uruchamianie symulacji
int sim(int choice, bool mode_unlimited, unsigned int tury, bool load_save)
{
	check_dev();
	if(mode_unlimited==true) cout << "Wybrano nieskonczony tryb gry.\n";
	else cout << "Wybrano roczny tryb gry.\n";
	//Input
	druzyna dragon;
	cout << "\nPodaj numer druzyny: ";
	cin >> dragon.numer;
	cout << "Podaj nazwe druzyny: ";
	cin >> dragon.nazwa;
	if(dragon.nazwa.empty()) dragon.nazwa = "DRAGON";
	cout << "Imie Druzynowego: ";
	cin >> dragon.druzynowy.name;
	//Konfiguracja
	cout << "\nKonfigurowanie systemu zdarzen losowych... ";
	srand(time(NULL));
	int los=(rand() % 100);
	int random, random2, random3, random4, random5, random6;
	cout << "zrobione\n";
	cout << "Zakladanie druzyny... ";
	dragon.saldo=round(los)*25;
	dragon.czlonkowie=los/5;
	while(dragon.czlonkowie<6)
	{
		los=(rand() % 100);
		dragon.saldo=round(los)*15;
		dragon.czlonkowie=los/5;
	}
	dragon.zadowolenie=50;
	dragon.wys_skladki=20;
	dragon.skladka_hufiec=15;
	dragon.weekendy=4;
	dragon.druzynowy.hp=100;
	dragon.druzynowy.level=0;
	ewidencja harcerz[40];
	for(int i=0; i<40; i++)
	{
		harcerz[i].reset_zalegle_skladki(i);
		random=(rand() % 100);
		random2=(rand() % 100);
		harcerz[i].insertdata(random, random2);
	}
	cout << "zrobione\n";
	cout << "Wprowadzanie ustawien czasu... ";
	int miesiacgry=9;
	bool koniectury=true;
	cout << "zrobione\n";
	cout << "Inicjalizacja parametrow mechaniki gry... ";
	cout << setprecision(2) << fixed;
	unsigned long int points=0;	//Punkty
	haliz opcja[3]; //HALIZ
	//MRHIL
	mrhil_sys user;
	user.login=dragon.druzynowy.name;
	user.haslo="****************";
	mrhil_grant wniosek;
	wniosek.active=false;
	wniosek.coolout=0;
	wniosek.time=0;
	//Mechanika
	int kwota, ludzie_z_akcji, skladki_zalegle=0;
	float modifier=1;
	bool zaplacone_skladki=false, biwak_active=false, beeper=false, endgame_good=true, komisja_rewizyjna=false, haliz_active=false, haliz_organize=false, event_is_shown=false, zbiorka=false, zarobkowa=false, bieg=false, course=false;
	event r_event;
	cout << "zrobione\n";
	fstream save ("save.txt");
	if(load_save==true)
	{
		cout << "Wczytywanie zapisu gry... ";
		//save.open("save.txt", ios::in);
		if(save.good()==true)
		{
			int mode_temp;
			save >> dragon.saldo >> dragon.zadowolenie >> dragon.czlonkowie >> dragon.wys_skladki >> dragon.skladka_hufiec >> dragon.weekendy >> skladki_zalegle >> tury >> miesiacgry >> mode_temp;
			if(mode_temp==1) mode_unlimited=true;
			else mode_unlimited=false;
			cout << "zrobione\n";
			save.close();
		}
		else cout << "niepowodzenie\n";
		save.close();
	}
	cout << "\n";
	anykey();
	system("cls");
	lordgg();
	//Symulacja
	while(true)		//Panel sterowania
	{
		//Opcje mechaniki
		beeper=false;
		int main_random=(rand() % 100);
		if(koniectury==true)
		{
			random=main_random;
			usleep(1);
			random2=(rand() % 10) + 1;
			usleep(1);
			random4=(rand() % 100) + 1;
			ludzie_z_akcji=0;
		}
		koniectury=false;
		if(miesiacgry>12) miesiacgry=1;
		if(skladki_zalegle<0) skladki_zalegle=0;
		if(dragon.zadowolenie>100) dragon.zadowolenie=100;
		if(dragon.zadowolenie<0) dragon.zadowolenie=0;
		if(dragon.saldo<0)	dragon.saldo=0;
		if(dragon.zadowolenie<=30||skladki_zalegle==3) komisja_rewizyjna=true;
		if(dragon.zadowolenie>30&&skladki_zalegle<=0) komisja_rewizyjna=false;
		if(dragon.druzynowy.hp>100) dragon.druzynowy.hp=100;
		if(dragon.druzynowy.hp<0) dragon.druzynowy.hp=0;
		if(miesiacgry==7||miesiacgry==12) haliz_organize=true;
		if(miesiacgry==9||miesiacgry==2) 
		{
			haliz_organize=false;
			haliz_active=false;
		}
		//Zdarzenia losowe
		if (r_event.new_event(random) == true && event_is_shown==false)
		{
			create_event(r_event);
			event_result(dragon, r_event);
			anykey();
			event_is_shown = true;
			system("cls");
		}
		//Panel G³ówny
		cout << dragon.numer << " PDH " << dragon.nazwa;
		cout << "\t" << dragon.druzynowy.showLevel(dragon.druzynowy.level) << " " << dragon.druzynowy.name;
		if(dragon.druzynowy.hp<40)
		{
			if(dragon.druzynowy.hp<10) setColor(12);
			else setColor(14);
		}
		cout << "\tSila: " << dragon.druzynowy.hp << "%";
		setColor(7);
		cout << "\nMiesiac: " << mies(miesiacgry) << "\tTura: " << tury << endl << endl;
		//Komunikaty
		check_dev();
		if(komisja_rewizyjna==true)
		{
			setColor(12);
			cout << "Komenda hufca nakazala kontrole ze strony komisji rewizyjnej!\n";
			beeper=true;
		}
		if(dragon.druzynowy.hp<40)
		{
			if(dragon.druzynowy.hp<10)
			{
				setColor(12);
				cout << "Instruktor jest skrajnie zmeczony!\n";
				beeper=true;
			}
			else
			{
				setColor(14);
				cout << "Instruktor jest zmeczony!\n";
				beeper=true;
			}
		}
		if(skladki_zalegle>0) 
		{
			setColor(14);
			if(skladki_zalegle>2) setColor(12);
			cout << "Nie zaplacono skladek od " << skladki_zalegle << " miesiecy!\n";
			beeper=true;
		}
		if(dragon.zadowolenie<50)
		{
			if(dragon.zadowolenie<=30)
			{
				setColor(12);
				cout << "Poziom zadowolenia krytycznie niski!\n";
				beeper=true;
			}
			else
			{
				setColor(14);
				cout << "Poziom zadowolenia jest niski!\n";
				beeper=true;
			}
		}
		if(dragon.saldo<=300)
		{
			if(dragon.saldo<=100)
			{
				setColor(12);
				cout << "Krytyczne braki w finansach!\n";
				beeper=true;
			}
			else
			{
				setColor(14);
				cout << "Braki w finansach!\n";
				beeper=true;
			}
		}
		if(dragon.czlonkowie<=5)
		{
			if(dragon.czlonkowie==0)
			{
				setColor(12);
				cout << "Krytyczne braki kadrowe!\n";
				beeper=true;
			}
			else
			{
				setColor(14);
				cout << "Braki kadrowe!\n";
				beeper=true;
			}
		}
		
		if( (wniosek.active==true)&&(wniosek.time==0) )
		{
			random6=(rand() % 100);
			int dofinansowanie=wniosek.get_grant(random6, dragon.zadowolenie);
			if(dofinansowanie==0)
			{
				setColor(12);
				cout << "Ministerstwo odrzucilo twoj wniosek o dofinansowanie.\n";
				PlaySound(TEXT("Data/Snd/grant_bad.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			else
			{
				setColor(10);
				cout << "Ministerstwo zatwierdzilo twoj wniosek o dofinansowanie.\nOtrzymane fundusze: " << dofinansowanie << " PLN\n";
				dragon.saldo+=dofinansowanie;
				PlaySound(TEXT("Data/Snd/grant_good.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
			wniosek.active=false;
		}
		setColor(10);
		if(miesiacgry==12||miesiacgry==1) cout << "Mozna organizowac Harcerska Akcje Zimowa\n";
		if(miesiacgry==7||miesiacgry==8) cout << "Mozna organizowac Harcerska Akcje Letnia\n";
		setColor(7);
		if(beeper==true) PlaySound(TEXT("Data/Snd/beep.wav"), NULL, SND_FILENAME | SND_ASYNC);
		//Lista zasobow
		if(dragon.saldo<=300) setColor(14);
		if(dragon.saldo<=100) setColor(12);
		cout << "Srodki:  " << dragon.saldo << " PLN";
		setColor(7);
		cout << "\tWysokosc skladki: " << dragon.wys_skladki << endl;
		if(dragon.czlonkowie<=5) setColor(14);
		if(dragon.czlonkowie==0) setColor(12);
		cout << "Czlonkowie: " << dragon.czlonkowie;
		setColor(7);
		if(dragon.zadowolenie<50) setColor(14);
		if(dragon.zadowolenie<=30) setColor(12);
		cout << "\t\tZadowolenie: " << dragon.zadowolenie << " %" << endl;
		setColor(7);
		if(dragon.weekendy!=0) setColor(10);
		cout << "Wolne weekendy: " << dragon.weekendy << endl;
		setColor(7);
		//Decyzja gracza
		cout << "\n1. Zarzadzaj finansami\t\t2. Zarzadzaj zbiorkami\n";
		cout << "3. Organizuj HALIZ\t\t4. Lista czlonkow\n";
		cout << "5. Ministerstwo Rozwoju\t\t6. Instruktor\n";
		cout << "8. Instrukcja\t\t\t9. Zapisz gre\t\t\t0. Zakoncz ture\n";
		cout << "\nTwoja decyzja: ";
		cin >> choice;
		switch(choice)
		{
			case	0	:	cout << "Tura zostala zakonczona.\n";	//Koniec tury
							koniectury=true;
							anykey();
							break;
			case	1	:	system("cls");	//Finanse
							cout << "Zarzadzanie finansami\n";
							cout << "Stan konta: " << dragon.saldo << " PLN\n";
							cout << "Aktualna wysokosc skladki: " << dragon.wys_skladki << " PLN\n";
							cout << "Wysokosc skladki dla hufca: " << dragon.skladka_hufiec << " PLN\n";
							cout << "1. Zaplac skladki do hufca.\t\t2. Zmien wysokosc skladki.\t\t0. Powrot\n\nTwoja decyzja: ";
							cin >> choice;
							switch(choice)
							{
								case	1	:	if(zaplacone_skladki==true)
												{
													cout << "Juz zaplacono skladki za ten miesiac :)\n";
													anykey();
												}
												else
												{
													if(dragon.saldo<dragon.skladka_hufiec*dragon.czlonkowie)
													{
														cout << "Brak dostatecznych funduszy!\n";
														anykey();
													}
													else
													{
														dragon.saldo-=dragon.skladka_hufiec*dragon.czlonkowie;
														cout << "Zaplacono skladki za " << dragon.czlonkowie << " osob w wysokosci " << dragon.skladka_hufiec*dragon.czlonkowie << " PLN";
														cout << "\nPozostalo " << dragon.saldo << " PLN\n";
														if(skladki_zalegle==0) zaplacone_skladki=true;
														--skladki_zalegle;
														anykey();
													}
												}
												break;
								case	2	:	cout << "Podaj nowa wysokosc skladek: ";
												cin >> kwota;
												if(kwota<=0)
												{
													while(kwota<=0)
													{
														cout << "Blad danych. Podaj wartosc wieksza od zera: ";
														cin >> kwota;
													}
												}
												else
												{
													if(kwota>dragon.wys_skladki) dragon.zadowolenie-=kwota-dragon.wys_skladki;
													else	dragon.zadowolenie+=(dragon.wys_skladki-kwota)/2;
													dragon.wys_skladki=kwota;
												}
												break;
								default		:	break;
												
							}
							break;
			case	2	:	system("cls");	//Zbiórki i biwaki
							if(dragon.weekendy==0)
							{
								cout << "Wszystkie wolne terminy zostaly juz zagospodarowane.\n";
								anykey();
								break;
							}
							cout << "Zarzadzanie zbiorkami\n";
							cout << "Stan konta: " << dragon.saldo << " PLN\tSila: " << dragon.druzynowy.hp <<"%\tWspolczynnik: " << modifier;
							cout << "\nIlosc czlonkow: " << dragon.czlonkowie << "\t\tPozostaly " << dragon.weekendy << " wolne weekendy\n\n";
							cout << "1. Organizuj zbiorke.\t\t2. Organizuj biwak.\t\t0. Powrot\n\nTwoja decyzja: ";
							cin >> choice;
							switch(choice)
							{
								case	1	:	cout << "Wybierz rodzaj zbiorki: \n1. Zbiorka w harcowce (koszt 30 PLN, 3 SI)\n2. Zbiorka terenowa (koszt 50 PLN, 5 SI)\n"; 
												cout << "3. Zbiorka z pierwszej pomocy (koszt 100 PLN, 10 SI)\n4. Akcja naborowa (koszt 80 PLN, 10 SI)\n";
												cout << "5. Biego po stopien (koszt 120 PLN, 12 SI)\n0. Powrot\n\nTwoja decyzja: ";
												cin >> choice;
												switch(choice)
												{
													case	1	:	if(dragon.saldo<30)
																	{
																		cout << "Brak dostatecznych funduszy!\n";
																		anykey();
																		break;
																	}
																	if(dragon.druzynowy.hp<3)
																	{
																		cout << "Instruktor jest zbyt zmeczony!\n";
																		anykey();
																		break;
																	}
																	dragon.saldo-=30;
																	dragon.zadowolenie+=4;
																	--dragon.weekendy;
																	dragon.druzynowy.hp-=3*modifier;
																	zbiorka=true;
																	break;
													case	2	:	if(dragon.saldo<50)
																	{
																		cout << "Brak dostatecznych funduszy!\n";
																		anykey();
																		break;
																	}
																	if(dragon.druzynowy.hp<5)
																	{
																		cout << "Instruktor jest zbyt zmeczony!\n";
																		anykey();
																		break;
																	}
																	dragon.saldo-=50;
																	dragon.zadowolenie+=5;
																	--dragon.weekendy;
																	dragon.druzynowy.hp-=5*modifier;
																	zbiorka=true;
																	break;
													case	3	:	if(dragon.saldo<100)
																	{
																		cout << "Brak dostatecznych funduszy!\n";
																		anykey();
																		break;
																	}
																	if(dragon.druzynowy.hp<10)
																	{
																		cout << "Instruktor jest zbyt zmeczony!\n";
																		anykey();
																		break;
																	}
																	dragon.saldo-=100;
																	dragon.zadowolenie+=7;
																	--dragon.weekendy;
																	dragon.druzynowy.hp-=10*modifier;
																	zbiorka=true;
																	break;
													case	4	:	if(zarobkowa==true)
																	{
																		cout << "Juz organizowano akcje naborowa\n";
																		anykey();
																		break;
																	}
																	if(dragon.saldo<80)
																	{
																		cout << "Brak dostatecznych funduszy!\n";
																		anykey();
																		break;
																	}
																	if(dragon.druzynowy.hp<10)
																	{
																		cout << "Instruktor jest zbyt zmeczony!\n";
																		anykey();
																		break;
																	}
																	dragon.saldo-=80;
																	dragon.zadowolenie+=6;
																	ludzie_z_akcji=random/35;
																	--dragon.weekendy;
																	dragon.druzynowy.hp-=10*modifier;
																	zbiorka=true;
																	zarobkowa=true;
																	break;
													case	5	:	if(bieg==true)
																	{
																		cout << "Juz organizowano bieg po stopien\n";
																		anykey();
																		break;
																	}
																	if(dragon.druzynowy.hp<12)
																	{
																		cout << "Instruktor jest zbyt zmeczony!\n";
																		anykey();
																		break;
																	}
																	if(dragon.saldo<120)
																	{
																		cout << "Brak dostatecznych funduszy!\n";
																		anykey();
																		break;
																	}
																	else
																	{
																		for(int i=0; i<dragon.czlonkowie; i++)
																		{
																			int random5=(rand() % 100);
																			harcerz[i].getnew_stopien(dragon.zadowolenie, random5);
																		}
																		--dragon.weekendy;
																		dragon.druzynowy.hp-=12*modifier;
																		zbiorka=true;
																		bieg=true;
																		dragon.zadowolenie+10;
																	}
																	break;
													case	0	:	break;
													default		:	break;
												}
												break;
								case	2	:	if(biwak_active==true)
												{
													cout << "Juz mamy biwak w tym miesiacu.\n";
													anykey();
													break;
												}
												if(dragon.druzynowy.hp<15)
												{
													cout << "Instruktor jest zbyt zmeczony!\n";
													anykey();
													break;
												}
												cout << "Znaleziono potencjalne miejsce na biwak. Szacowany koszt od osoby to " << random << " PLN. Wymaga minimum 15 SI.\nBiwak zajmie jeden weeekend.\n";
												cout << "1. Zatwierdz\t\t2. Odrzuc\n\nTwoja decyzja: ";
												cin >> choice;
												if(choice==1)
												{
													cout << "Laczny koszt biwaku: " << random << " PLN";
													cout << "\nPodaj koszt od uczestnika: ";
													cin >> kwota;
													while(kwota<=0)
													{
														cout << "Blad danych. Podaj wartosc wieksza od zera: ";
														cin >> kwota;
													}
													cout << "Koszty ze srodkow druzyny: " << (random-kwota)*dragon.czlonkowie << " PLN\n";
													cout << "1. Zatwierdz\t\t2. Odrzuc\n\nTwoja decyzja: ";
													cin >> choice;
													if(choice==1)
													{
														int liczbaosob=0;
														for(int i=0; i<dragon.czlonkowie; i++)
														{
															random3=(rand() % 100);
															harcerz[i].set_frekwencja(random3, dragon.zadowolenie);
															if(random3+dragon.zadowolenie>100) liczbaosob++;
														}
														dragon.saldo-=(random-kwota)*liczbaosob;
														dragon.zadowolenie+=20;
														if(kwota>random) dragon.zadowolenie-=(kwota-random);
														if(kwota>50) dragon.zadowolenie-=(kwota/4);
														--dragon.weekendy;
														dragon.druzynowy.hp-=15*modifier;
														biwak_active=true;
													}
												}
												break;
								case	0	:	break;
								default		:	break;
							}
							break;
			case	3	:	if(haliz_active==false&&haliz_organize==true)	//HALIZ
							{
								cout << "Przyboczny przygotowal potencjalna liste akcji: \n";
								cout << "\nOpcja 1: \n";
								opcja[0].lokalizacja=stanica[random4/5];
								opcja[0].dlugosc=random4/5;
								opcja[0].koszt=random4*10;
								cout << "Stanica harcerska " << opcja[0].lokalizacja << "\tDlugosc: " << opcja[0].dlugosc << "\tKoszt na uczestnika: " << opcja[0].koszt << " PLN\n";
								cout << "\nOpcja 2: \n";
								opcja[1].lokalizacja=stanica[random2*2];
								opcja[1].dlugosc=random2*1.4;
								opcja[1].koszt=random2*120;
								cout << "Stanica harcerska " << opcja[1].lokalizacja << "\tDlugosc: " << opcja[1].dlugosc << "\tKoszt na uczestnika: " << opcja[1].koszt << " PLN\n";
								cout << "\nTwoja decyzja: ";
								cin >> choice;
								if( (choice==1)||(choice==2) )
								{
									if(dragon.weekendy<4)
									{
										cout << "Brak wolnych weekendow!\n";
										anykey();
										break;
									}
									if(dragon.druzynowy.hp<30)
									{
										cout << "Instruktor jest zbyt zmeczony!\n";
										anykey();
										break;
									}
									opcja[2].lokalizacja=opcja[choice-1].lokalizacja;
									opcja[2].dlugosc=opcja[choice-1].dlugosc;
									opcja[2].koszt=opcja[choice-1].koszt;
									cout << "Podaj koszt od uczestnika za HALIZ: ";
									cin >> kwota;
									while(kwota<=0)
									{
										cout << "Blad danych. Podaj wartosc wieksza od zera: ";
										cin >> kwota;
									}
									cout << "Koszty ze srodkow druzyny: " << (opcja[2].koszt-kwota)*dragon.czlonkowie << " PLN\n";
									dragon.zadowolenie+=(10*opcja[2].dlugosc)/(opcja[2].koszt/100);
									dragon.zadowolenie+=( (opcja[2].koszt-kwota)/4 );
									//dragon.saldo+=kwota*dragon.czlonkowie;
									int liczbaosob=0;
									for(int i=0; i<dragon.czlonkowie; i++)
									{
										random3=(rand() % 100);
										harcerz[i].set_frekwencja(random3, dragon.zadowolenie);
										if(random3+dragon.zadowolenie>100) 
										{
											liczbaosob++;
											random3=(rand() % 100);
											harcerz[i].getnew_stopien(dragon.zadowolenie, random3);
										}
									}
									cout << "Udzial bierze " << liczbaosob << " osob\n";
									cout << "Dodano " << kwota*liczbaosob << " PLN do stanu konta\n";
									dragon.saldo+=kwota*liczbaosob;
									dragon.saldo-=opcja[2].koszt*liczbaosob;
									cout << "Wydano " << opcja[2].koszt*liczbaosob << " PLN\n";
									haliz_active=true;
									dragon.weekendy=0;
									dragon.druzynowy.hp-=30;
									anykey();
								}
								else break;
							}
							else
							{
								if(haliz_active==true&&haliz_organize==true)
								{
									cout << "Zaplanowana akcja:\n";
									cout << "Stanica harcerska: " << opcja[2].lokalizacja << "\tDlugosc: " << opcja[2].dlugosc << "\tKoszt na uczestnika: " << opcja[2].koszt << " PLN\n";
									anykey();
									break;
								}
								cout << "Nie mozna teraz organizowac akcji HALIZ\n";
								anykey();
								break;
							}
							break;
			case	4	:	system("cls");	//Ewidencja
							cout << "Numer\tImie\t\tNazwisko\t\tZalegle skladki (miesiace)\tFrekwencja\t\t\t\tStopien\n";
							for(int i=0; i<dragon.czlonkowie; i++)
							{
								if(harcerz[i].zalegle_skladki>0||harcerz[i].frekwencja<50) setColor(14);
								if(harcerz[i].zalegle_skladki>2||harcerz[i].frekwencja<30) setColor(12);
								if(i<9) cout << left << i+1 << ".  " << setw(20);
								else cout << left << i+1 << ". " << setw(20);
								cout << right << harcerz[i].imie << setw(20);
								cout << right << harcerz[i].nazwisko << setw(20);
								cout << right << harcerz[i].zalegle_skladki << setw(22);
								cout << right << harcerz[i].frekwencja << " %"<< setw(31);
								//cout << right << harcerz[i].udzial << " " << harcerz[i].akcje << setw(25);
								cout << right << harcerz[i].show_stopien(harcerz[i].stopien , harcerz[i].plec) << endl;
								//cout << right << harcerz[i].stopien_cooldown << endl;
								setColor(7);
							}
							cout << "\n\n1. Usun osobe z ewidencji\t0. Powrot\n\n";
							cout << "Twoja decyzja: ";
							cin >> choice;
							if(choice==1)
							{
								cout << "Podaj numer osoby do usuniecia (0 - anuluj): ";
								cin >> choice;
								if(choice==0) break;
								else
								{
									dragon.czlonkowie--;
									harcerz[choice-1].del_selected();
									for(int i=choice-1; i<dragon.czlonkowie; i++)
									{
										harcerz[i].akcje=harcerz[i+1].akcje;
										harcerz[i].frekwencja=harcerz[i+1].frekwencja;
										harcerz[i].imie=harcerz[i+1].imie;
										harcerz[i].nazwisko=harcerz[i+1].nazwisko;
										harcerz[i].plec=harcerz[i+1].plec;
										harcerz[i].stopien=harcerz[i+1].stopien;
										harcerz[i].udzial=harcerz[i+1].udzial;
										harcerz[i].zalegle_skladki=harcerz[i+1].zalegle_skladki;
									}
								}
							}
							else break;
							break;
			case	5	:	system("cls");	//Ministerstwo Rozwoju Harcerstwa i Lasów
							cout << "Aplikacja Mobilna Ministerstwa Rozwoju Harcerstwa i Lasow v1.4\n\n";
							cout << "Login: ";
							for(int i=0; i<user.login.length(); i++)
							{
								cout  << user.login[i];
								usleep(50);
							}
							cout << "\nHaslo: ";
							for(int i=0; i<user.haslo.length(); i++)
							{
								cout  << user.haslo[i];
								usleep(50);
							}
							cout << "\nTrwa uwierzytelnianie...";
							sleep(1);
							cout << " sukces\n\n1. Zloz wniosek o dofinansowanie\n2. Skontaktuj sie z konsultantem\n0. Wyjdz z aplikacji\n\n";
							cout << "Twoja decyzja: ";
							cin >> choice;
							if(choice==1)
							{
								if(wniosek.coolout!=0)
								{
									cout << "Osiagnieto limit wnioskow na najblizsze " << wniosek.coolout << " miesiece.\n";
									anykey();
									break;
								}
								cout << "Kreator nowego wniosku - Zapraszamy!\nPodaj proponowana kwote dofinansowania: ";
								cin >> wniosek.ammount;
								while(wniosek.ammount<=0)
								{
									cout << "Wprowadzono bledna wartosc.";
									cin >> wniosek.ammount;
								}
								cout << "Wybierz 1 aby zatwierdzic wyslanie wniosku: ";
								cin >> choice;
								if(choice==1)
								{
									random6=(rand() % 3) + 1;
									wniosek.coolout=random6*2;
									wniosek.time=random6;
									wniosek.active=true;
									cout << "Wniosek zostal wyslany. Odpowiedz otrzymasz w ciagu " << wniosek.time << " miesiecy.\n";
								}
								else
								{
									cout << "Anulowano.\n";
								}
							}
							if(choice==2) cout << "Niestety wszyscy nasi konsultanci sa w tej chwili zajeci. Prosimy sprobowac ponownie pozniej.\n";
							anykey();
							break;
			case	6	:	system("cls");	//Instruktor
							cout << dragon.druzynowy.showLevel(dragon.druzynowy.level) << " " << dragon.druzynowy.name << endl;
							cout << dragon.numer << " PDH " << dragon.nazwa << "\tSila: " << dragon.druzynowy.hp << "%\t" << "Wspolczynnik: " << modifier << "\n\n";
							cout << "Opcje rozwoju instruktora:\n1. Kurs instruktorski (1000 PLN)\n-awansuj instruktora na kolejny stopien\n-zapewnia dodatkowe punkty\n-pozwala nieznacznie zredukowac zmeczenie\n";
							cout << "2. Kurs druzynowych (400 PLN)\n-pozwala na doskonalenie umiejetnosci kierowania druzyna\n-natychmiast odnawia 20 SI\n0. Powrot\n\nTwoja decyzja: ";
							cin >> choice;
							switch(choice)
							{
								case 1	:	if(dragon.druzynowy.level==2)
											{
												cout << "Instrukto ma juz stopien harcmistrza.\n";
												break;
											}
											if(course==true)
											{
												cout << "Juz byles w tym miesiacu na kursie. Wystarczy.\n";
												break;
											}
											if(dragon.weekendy==0)
											{
												cout << "Brak wolnych terminow!\n";
												break;
											}
											if(dragon.saldo<1000)
											{
												cout << "Brak dostatecznych funduszy!\n";
												break;
											}
											else
											{
												cout << "Kurs zostal ukonczony\n";
												dragon.weekendy--;
												dragon.saldo-=1000;
												course=true;
												modifier-=0.15;
												dragon.druzynowy.level++;
											}
											break;
								case 2	:	if(course==true)
											{
												cout << "Juz byles w tym miesiacu na kursie. Wystarczy.\n";
												break;
											}
											if(dragon.weekendy==0)
											{
												cout << "Brak wolnych terminow!\n";
												break;
											}
											if(dragon.saldo<400)
											{
												cout << "Brak dostatecznych funduszy!\n";
												break;
											}
											else
											{
												cout << "Kurs zostal ukonczony\n";
												dragon.weekendy--;
												dragon.saldo-=400;
												course=true;
												dragon.druzynowy.hp+=20;
											}
											break;
								default	:	break;
							}
							anykey();
							//TO DO
							break;
			case	8	:	manual();
							break;
			case	9	:	cout << "Zapisywanie stanu gry... ";
							save.open("save.txt", ios::out);
							if(save.is_open()==true)
							{
								save << dragon.saldo << endl;
								save << dragon.zadowolenie << endl;
								save << dragon.czlonkowie << endl;
								save << dragon.wys_skladki << endl;
								save << dragon.skladka_hufiec << endl;
								save << dragon.weekendy << endl;
								save << skladki_zalegle << endl;
								save << tury << endl;
								save << miesiacgry << endl;
								if(mode_unlimited==true) save << 1 << endl;
								else	save << 0 << endl;
								cout << "zrobione\n";
							}
							else cout << "niepowodzenie\n";
							save.close();
							anykey();
							break;
			case	88	:	system("cls");	//To w ogole nie jest zaden easter egg
							cout << "No ja wiem, ze Dragon jest super druzyna.\n";
							cout << "Ale ten numerek nic tutaj nie robi.\n";
							cout << "Nie ma zadnych tu cheatow ani easter eggow.\n";
							sleep(5);
							cout << "W ogole :P\n";
							anykey();
							break;
			case	115	:	system("cls");	//Developer Menu
							if(dev_115()==false)
							{
								cout << "Konsola generatora mocy 12-01 zabezpieczona kodem.\nZglosic pracownikowi ochrony.\nOtworzyc bloki operacyjne.\n";
								PlaySound(TEXT("Data/Snd/dev115_dis.wav"), NULL, SND_FILENAME | SND_ASYNC);
								anykey();
							}
							else
							{
								cout << "Otwarto blok C12.\nZglosic pracownikowi ochrony.\n";
								cout << "Aktualna ilosc punktow: " << points << endl;
								PlaySound(TEXT("Data/Snd/dev115_en.wav"), NULL, SND_FILENAME | SND_ASYNC);
								cout << "\nPodaj nowe saldo: ";
								cin >> dragon.saldo;
								cout << "Podaj nowa wysokosc skladki: ";
								cin >> dragon.wys_skladki;
								cout << "Podaj nowa ilosc czlonkow: ";
								cin >> dragon.czlonkowie;
								cout << "Podaj nowy poziom zadowolenia: ";
								cin >> dragon.zadowolenie;
								cout << "Podaj nowy stan instruktora: ";
								cin >> dragon.druzynowy.hp;
								cout << "Podja nowa ture: ";
								cin >> tury;
								cout << "Podaj nowy miesiac (1-12): ";
								cin >> miesiacgry;
								cout << "Zresetowac ewidencje? (1. Tak): ";
								cin >> choice;
								if(choice==1)
								{
									for(int i=0; i<40; i++)
									{
										harcerz[i].reset_zalegle_skladki(i);
										random=(rand() % 100);
										random3=(rand() % 100);
										harcerz[i].insertdata(random, random3);
									}
								}
								cout << "Ladnie tak oszukiwac?\n";
								sleep(2);
								system("cls");
							}
							break;
			case	116:	system("cls");	//Wymuœ zdarzenie losowe
				if (dev_115() == false)
				{
					cout << "Konsola generatora mocy 12-01 zabezpieczona kodem.\nZglosic pracownikowi ochrony.\nOtworzyc bloki operacyjne.\n";
					PlaySound(TEXT("Data/Snd/dev115_dis.wav"), NULL, SND_FILENAME | SND_ASYNC);
					anykey();
				}
				else
				{
					int choice;
					cout << "Wywolac zdarzneie losowe? (1=TAK)\n";
					cout << "Twoja decyzja: ";
					cin >> choice;
					if (choice == 1)
					{
						r_event.new_event(100);
						create_event(r_event);
						event_result(dragon, r_event);
						event_is_shown = true;
					}
					anykey();
					system("cls");
				}
				break;
			default		:	cout << "Wprowadzona opcja jest niepoprawna.\n";
							anykey();
							break;
		}
		//Frekwencja
		if(zbiorka==true)
		{
			for(int i=0; i<dragon.czlonkowie; i++)
			{
				random3=(rand() % 100);
				harcerz[i].set_frekwencja(random3, dragon.zadowolenie);
			}
			zbiorka=false;
		}
		if(dragon.czlonkowie<0) dragon.czlonkowie=0;
		system("cls");
		//Sprawdzanie koñca tury
		if(koniectury==true)
		{
			//Punkty
			points+=dragon.zadowolenie+dragon.czlonkowie-(dragon.weekendy*10)+dragon.wys_skladki;
			if(biwak_active==true) points+=10;
			if(haliz_active==true) points+=100;
			if(zarobkowa==true) points+=5;
			if(bieg==true) points+=10;
			points+=dragon.druzynowy.hp;
			points+=dragon.druzynowy.level*50;
			//Zakoñczenia
			if(komisja_rewizyjna==true)
			{
				PlaySound(TEXT("Data/Snd/cichutkim_krokiem.wav"), NULL, SND_FILENAME | SND_ASYNC);
				ending_komisja();
				endgame_good=false;
				break;
			}
			if(dragon.czlonkowie<=0)
			{
				PlaySound(TEXT("Data/Snd/cichutkim_krokiem.wav"), NULL, SND_FILENAME | SND_ASYNC);
				ending_people();
				endgame_good=false;
				break;
			}
			if(dragon.saldo<=100)
			{
				PlaySound(TEXT("Data/Snd/cichutkim_krokiem.wav"), NULL, SND_FILENAME | SND_ASYNC);
				ending_hajs();
				endgame_good=false;
				break;
			}
			if(dragon.druzynowy.hp<=10)
			{
				PlaySound(TEXT("Data/Snd/cichutkim_krokiem.wav"), NULL, SND_FILENAME | SND_ASYNC);
				ending_leader();
				endgame_good=false;
				break;
			}
			//MRHIL
			wniosek.getnew_coolout();
			wniosek.set_time();
			//Czas
			++miesiacgry;
			++tury;
			if(mode_unlimited==false)
			{
				if(tury>12) break;
			}
			//Instruktor
			dragon.druzynowy.hp+=10;
			dragon.druzynowy.hp += dragon.weekendy*5;
			if(dragon.druzynowy.level>2) dragon.druzynowy.level=2;
			if(dragon.druzynowy.level<0) dragon.druzynowy.level=0;
			course=false;
			//Zbiórki
			biwak_active=false;
			zarobkowa=false;
			bieg=false;
			dragon.czlonkowie+=ludzie_z_akcji;
			if(dragon.czlonkowie>40) dragon.czlonkowie=40;
			if(dragon.czlonkowie<0) dragon.czlonkowie=0;
			//Zadowolenie
			if( (miesiacgry==8 || miesiacgry==9))
			{
				//Brak obowi¹zku zbiórek w wakacje
			}
			else
			{
				if(dragon.weekendy!=0)	dragon.zadowolenie-=dragon.weekendy*5;
			}
			//Weekendy i zadowolenie
			dragon.weekendy=4;
			dragon.zadowolenie-=10;
			//Ewidencja
			if(dragon.zadowolenie<30)
			{
				if(dragon.zadowolenie!=0) dragon.czlonkowie-=random/(dragon.zadowolenie*2);
				else	dragon.czlonkowie-=random;
			}
			for(int i=0; i<dragon.czlonkowie; i++)
			{
				harcerz[i].stopien_cooldown--;
			}
			for(int i=dragon.czlonkowie; i<40; i++)
			{
				harcerz[i].reset_zalegle_skladki(i);
				random=(rand() % 100);
				random2=(rand() % 100);
				harcerz[i].insertdata(random, random2);
				harcerz[i].stopien=0;
			}
			//Sk³adki
			//dragon.saldo=dragon.skladki(dragon.saldo);
			for(int i=0; i<dragon.czlonkowie; i++)
			{
				random=(rand() % 100);
				dragon.saldo+=harcerz[i].rand_skladki(random, dragon.zadowolenie, dragon.wys_skladki);
			}
			if(zaplacone_skladki==false) skladki_zalegle++;
			zaplacone_skladki=false;
			//Resetowanie zdarzeñ losowych
			event_is_shown = false;
		}
		system("cls");
	}
	if(endgame_good==true)
	{
		PlaySound(TEXT("Data/Snd/cichutkim_krokiem.wav"), NULL, SND_FILENAME | SND_ASYNC);
		ending_good();
	}
	//Finalne podliczenia punktów
	for(int i=0; i<dragon.czlonkowie; i++)
	{
		points+=harcerz[i].stopien*5;
	}
	points+=dragon.saldo;
	cout << "Zdobyta ilosc punktow: " << points << endl;
	anykey();
	return 0;
}

//POZOSTA£E FUNKCJE
void create_event(event r_event)
{
	PlaySound(TEXT("Data/Snd/event_print.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout << "UWAGA! ZDARZENIE LOSOWE\n";
	sleep(1);
	cout << r_event.title << endl;
	sleep(1);
	cout << r_event.desc << endl;
	sleep(1);
	cout << "\nREZULTATY:\n";
}

void event_result(druzyna &dragon, event r_event)
{
	int id = r_event.id;
	switch (id)
	{
	case 0: 
		dragon.skladka_hufiec += 5;
		cout << "-Skladki do hufca zwiekszone o 5 PLN\n";
		break;
	case 1:
		dragon.skladka_hufiec -= 5;
		cout << "-Skladki do hufca zmienjszone o 5 PLN\n";
		break;
	case 2:
		dragon.czlonkowie += 1;
		cout << "-Do Druzyny dodano 1 osobe\n";
		break;
	case 3:
		dragon.saldo += 400;
		cout << "-Dodano 400 PLN do salda Druzyny\n";
		break;
	case 4:
		dragon.weekendy -= 1;
		cout << "-Ilosc wolnych weekendow zmiejszona o 1\n";
		break;
	case 5:
		dragon.druzynowy.hp -= 10;
		cout << "-Sila Druzynowego zostaje zmniejszona o 10%\n";
		break;
	case 6:
		dragon.weekendy += 15;
		cout << "-Sila Druzynowego zostaje zwiekszona o 15%\n";
		break;
	case 7:
		dragon.weekendy -= 1;
		cout << "-Ilosc wolnych weekendow zmiejszona o 1\n";
		dragon.zadowolenie += 10;
		cout << "-Zadowolenie w Druzynie wzrasta o 10%\n";
		break;
	case 8:
		dragon.druzynowy.hp -= 5;
		cout << "-Sila Druzynowego zostaje zmniejszona o 5%\n";
		dragon.saldo -= 100;
		cout << "-Z konta Druzyny pobrano 100 PLN\n";
		break;
	case 9:
		cout << "-Druzynowemu zaliczono sluzbe instrukorska\n";
		break;
	default:
		cout << "B£AD - wywolano zdarzenie spoza zakresu!\n";
	}
}

//Tu ju¿ nic nie ma. Wracaj na górê :P
