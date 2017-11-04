#include<iostream>
#include<string>
#include"evenement.h"

using namespace std;
using namespace TIME;

int main() {

	/*Evt1j e1(Date(4, 10, 1957), "Spoutnik");
	Evt1j e2(Date(11, 6, 2013), "Shenzhou");
	Evt1jDur e3(Date(11, 6, 2013), "Lancement de Longue Marche", Duree(0, 10), Horaire(17, 38));
	Rdv e4(Date(11, 4, 2013), "reunion UV", Duree(60), Horaire(17, 30), "Intervenants UV", " bureau");*/
	//e1.afficher(); e2.afficher(); e3.afficher(); e4.afficher();
	//cout << e1;
	/*Evt1j* pt1 = &e1; Evt1j* pt2 = &e2; Evt1j* pt3 = &e3; Evt1j* pt4 = &e4;
	pt1->afficher(); pt2->afficher(); pt3->afficher(); pt4->afficher();*/
	// Ici on a le problème soulevé par le binding static des méthodes overridées dans les classes filles
	// La méthode appelée est appelée en fonction du type officiel de l'objet
	// le binding est fait lors de la compilation
	// pour avoir un binding dynamque réalisé pendant l'exécution, utiliser une méthode virtuelle

	system("pause");
	return 0;
}