//DRu�ynowa Aplikacja GOspodarowania ewideNcja - DRAGON

#ifndef simulation_h
#define simulation_h

#include "class.h"		//Klasy i struktury (odwo�anie do mechaniki w �rodku)
#include "mrhil.h"		//Ministerstwo Rozwoju Harcerstwa i Las�w

int sim(int choice, bool mode_unlimited, unsigned int tury, bool load_save);
void create_event(event r_event);
void event_result(druzyna &dragon, event r_event);

#endif
