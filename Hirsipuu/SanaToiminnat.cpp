// SanaToiminnat:
// Sis�lt�� sanojen k�sittelyyn osallistuvat funktiot
#include "stdafx.h"



SanaToiminnat::SanaToiminnat() {
	// Luokan alustus ja suoritettavat komennot kun luokkaa luodaan:
	srand(int(time(0)) );					// Generoidaan randomisaattori ajan mukaan. Vaatii ctime-kirjaston.
	
	// Noudetaan sanat tiedostosta:
	Tiedosto* t = new Tiedosto();

	sanat = t->NoudaSanat();

	delete t;
}
int SanaToiminnat::SyotaSanoja() {
	// Funktio, jonka avulla voidaan sy�tt�� peliin lis�� arvattavia sanoja
	system("cls");
	cout << " Lis�� sanoja:" << endl
		<< "==============" << endl;
	string syote = "";
	
	Tiedosto *t = new Tiedosto();

	do {
		cout << endl << "Lis�� uusi sana: ";
		getline(cin, syote);

		if (syote != "") {
			bool onJo = false;
			for each(auto sana in sanat) {
				if (sana == syote) {
					cout << "Sana on jo!" << endl;
					onJo = true;
					break;
				}
			}
			if (onJo == false) {
				if (t->TalletaSana(syote) == true) {
					this->sanat.push_back(syote);
					cout << endl << syote << " tallennettu!" << endl;
				}
				else {
					cout << "Tallennusvirhe..." << endl;
				}
			}

		}
	} while (syote != "");

	delete t;
	return 0;
}
int SanaToiminnat::ArvoNumero(int maksimi) {
	// Arvotaan numero, jonka perusteella poimitaan sana peliin.
	int randomi = 0;
	randomi = rand() % maksimi ;

	return randomi;

}

string SanaToiminnat::PoimiSana() {
	// Funktio joka palauttaa sanan pelimoottorille

	

	if (sanat.size() == 0) {
		cout << "Peliin ei ole tallennettu sanoja!!! Lis�� uusia sanoja ja aloita peli";
		return "";
	}

	/*string sanat[] = {
		"Turkinpippuri",
		"Hattukauppias",
		"Transistoriradio",
		"Keilarata",
		"Tietojenk\204sittely"
	};*/
	int sanojenLukum = sanat.size();							// Kuinka monta sanaa on, eli milt� v�lilt� voidaan poimia sana.
	int poimintaNumero = 0;							// Satunnaisluku, jonka mukaan poimitaan sana.


	
	poimintaNumero = ArvoNumero(sanojenLukum );		// K�yd��n poimimassa satunnaisluku.
	
	//return sanat[4];
	return sanat[poimintaNumero];

}