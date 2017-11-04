# if !defined(EVENEMENT_H)
# define _EVENEMENT_H

#include <iostream> 
#include <string>
#include "timing.h"
using namespace std;
namespace TIME {
	class Evt1j {
	private:
		Date date;
		string sujet;
	public:
		Evt1j(const Date& d, const string& s) : date(d), sujet(s) {}
		const string& getDescription() const { return sujet; }
		const Date& getDate() const { return date; }
		virtual void afficher(ostream& f = cout) const {
			f<<"***** Evt ********" << "\n" << "Date=" << date << " sujet=" << sujet << "\n";
		}
		virtual ~Evt1j() {}
	};

	class Evt1jDur : public Evt1j {
	private:
		Duree duree;
		Horaire horaireDebut;
	public:
		Evt1jDur(const Date& d, const string& s, Duree dur, Horaire h) : Evt1j(d, s), duree(dur), horaireDebut(h) {}
		const Duree& getDuree() { return duree; }
		const Horaire& getHoraireDebut() { return horaireDebut; }
		virtual void afficher(ostream& f = cout) const {
			Evt1j::afficher(f);
			f<< "Horaire de début=" << horaireDebut << "Durée=" << duree << "\n";
		}
		~Evt1jDur() {}

	};

	class Rdv : public Evt1jDur {
	private:
		string lieu;
		string personne;
	public:
		Rdv(const Date& d, const string& s, Duree dur, Horaire h, string l, string p) : Evt1jDur(d, s, dur, h), lieu(l), personne(p) {}
		const string& getLieu() { return lieu; }
		const string& getPersonne() { return personne; }
		virtual void afficher(ostream &f = cout) const {
			Evt1jDur::afficher();
			f << "Lieu=" << lieu << "Personne=" << personne << "\n";
		}
		~Rdv() {}
		Rdv& operator=(const Rdv& r) {
			
			Evt1jDur::operator=(r);
			lieu = r.lieu;
			personne = r.personne;

			return *this;
		}
	};

	class Agenda {
	private:
		Evt1j** agenda;
		unsigned int tailleMax;
		unsigned int tailleActuelle;
		Agenda& operator=(const Agenda& a);
		Agenda(const Agenda& a);
		void agrandissement();
	public:
		Agenda& operator<<(Evt1j& e);
		void afficher(ostream& f = cout);
	};
}

#endif