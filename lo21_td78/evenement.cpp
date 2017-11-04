#include<ostream>
#include<string>
#include"evenement.h"

using namespace std;
using namespace TIME;

void Agenda::agrandissement() {
	Evt1j** oldAgenda = agenda;
	Evt1j** newAgenda = new Evt1j*[(tailleMax * 2) + 1];
	tailleMax = (2 * tailleMax) + 1;
	memcpy(newAgenda, oldAgenda, tailleMax * sizeof(Evt1j*));
	delete[](oldAgenda);
}

Agenda& Agenda::operator<<(Evt1j& e) {
	if (tailleActuelle == tailleMax) {
		agrandissement();
	}
	agenda[++tailleActuelle] = &e;
	return *this;
}

void Agenda::afficher(ostream& f = cout) {
	for (unsigned int i = 0; i < tailleActuelle; i++) {
		agenda[i]->afficher();
	}
}


