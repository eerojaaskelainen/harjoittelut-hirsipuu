// Sis‰lt‰‰ konsolin grafiikanmuodostuksen
#include "stdafx.h"


void Grafiikat::TulostaAlku() {
	//Tulostaa konsolille pelin aloitusgrafiikat

	cout << " ------------------------------------------------ " << endl
		<< "|                                                |" << endl
		<< "|          H   I   R   S   I   P   U   U         |" << endl
		<< "|                                                |" << endl
		<< " ------------------------------------------------" << endl;
}



void Grafiikat::TulostaKirjainkysely() {
	// Tulostaa konsolille kirjaimen kyselyn
	cout << "Arvaa kirjain: " << flush;
}

void Grafiikat::TulostaOikein(string sana, int arvaustenMaara) {
	string viesti = "     ------------------------------------\n                VOITIT PELIN!!!\n     ------------------------------------";
	TulostaHirsipuu(sana,arvaustenMaara,viesti);

}
void Grafiikat::TulostaGameOver(string piilosana, int arvaustenMaara) {
	string viesti = "\n  ------------------------------------------------------\n";
	viesti.append("            G  A  M  E    O  V  E  R  !  !  !  ! \n");
	viesti.append("  ------------------------------------------------------\n");

	TulostaHirsipuu(piilosana, arvaustenMaara, viesti);

}

void Grafiikat::TulostaHirsipuu(const string &piilosana, const int arvaustenMaara,string viesti) {

	static_assert(MAX_VIRHEMAARA == 6, "Grafiikat:TulostaHirsipuu:: Maksimi virhemaara poikkeaa grafiikassa maaritetysta");
	int m = arvaustenMaara;
	system("CLS");
	TulostaAlku();
	cout << endl << endl << endl;

	switch (m) {
	case 6:
		cout <<endl
			<< "       -----------------" << endl
			<< "       |               |" << endl
			<< "       |               |                  Arvattava sana:" << endl
			<< "       |               __" << endl
			<< "       |              |  |                " << piilosana << endl
			<< "       |               --" << endl
			<< "       |                |          " << endl
			<< "       |              -- --        " << endl
			<< "       |                |" << endl
			<< "       |               / \\" << endl
			<< "       |              /   \\" << endl
			<< "       |" << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;

	case 5:
		cout << endl
			<< "       -----------------" << endl
			<< "       |               |" << endl
			<< "       |               |                  Arvattava sana:" << endl
			<< "       |               __" << endl
			<< "       |              |  |                " << piilosana << endl
			<< "       |               --" << endl
			<< "       |                |" << endl
			<< "       |              -- --" << endl
			<< "       |                |" << endl
			<< "       |               / " << endl
			<< "       |              /   " << endl
			<< "       |" << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;
	


	case 4:
		cout << endl
			<< "       -----------------" << endl
			<< "       |               |" << endl
			<< "       |               |                  Arvattava sana:" << endl
			<< "       |               __" << endl
			<< "       |              |  |                " << piilosana << endl
			<< "       |               --" << endl
			<< "       |                |" << endl
			<< "       |              -- --" << endl
			<< "       |                " << endl
			<< "       |              " << endl
			<< "       |              " << endl
			<< "       |" << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;

	case 3:
		cout << endl
			<< "       -----------------" << endl
			<< "       |               |" << endl
			<< "       |               |                  Arvattava sana:" << endl
			<< "       |               __" << endl
			<< "       |              |  |                " << piilosana << endl
			<< "       |               --" << endl
			<< "       |                " << endl
			<< "       |             " << endl
			<< "       |                " << endl
			<< "       |              " << endl
			<< "       |              " << endl
			<< "       |" << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;



	case 2:
		cout << endl
			<< "       -----------------" << endl
			<< "       |               |" << endl
			<< "       |               |                  Arvattava sana:" << endl
			<< "       |               " << endl
			<< "       |                                  " << piilosana << endl
			<< "       |              " << endl
			<< "       |                " << endl
			<< "       |              " << endl
			<< "       |                " << endl
			<< "       |              " << endl
			<< "       |              " << endl
			<< "       |" << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;


	case 1:
		cout << endl
			<< "       " << endl
			<< "                      " << endl
			<< "                                          Arvattava sana:" << endl
			<< "                      " << endl
			<< "                                          " << piilosana << endl
			<< "                     " << endl
			<< "                       " << endl
			<< "                     " << endl
			<< "                       " << endl
			<< "                     " << endl
			<< "                     " << endl
			<< "       " << endl
			<< "  ------------------------------" << endl
			<< " |                              |" << endl
			<< " |                              |" << endl;
		break;

	case 0:
		cout << endl
			<< "       " << endl
			<< "                      " << endl
			<< "                                          Arvattava sana:" << endl
			<< "                      " << endl
			<< "                                          " << piilosana << endl
			<< "                     " << endl
			<< "                       " << endl
			<< "                     " << endl
			<< "                       " << endl
			<< "                     " << endl
			<< "                     " << endl
			<< "       " << endl
			<< "  " << endl
			<< "" << endl
			<< "" << endl;
		break;

	}
	cout << endl << viesti <<endl;
}

bool Grafiikat::KysyJatketaanko() {
	char vastaus = 0;

	cout << "Haluatko pelata uudelleen (Y/N)? ";
	cin >> vastaus;

	if (vastaus == 'Y' || vastaus == 'y') {
		return true;
	}
	else {
		return false;
	}

}