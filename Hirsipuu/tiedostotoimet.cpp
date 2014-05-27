
#include "stdafx.h"

vector<string> Tiedosto::NoudaSanat() {

	vector<string> sanat;

	ifstream sanasto(tiedostoSijainti);
	string rivi;

	if (sanasto.is_open())
	{
		while (getline(sanasto, rivi))
		{
			sanat.push_back(rivi);
		}
		sanasto.close();
	}
	

	return sanat;
}

bool Tiedosto::TalletaSana(string sana) {
	ofstream sanasto(tiedostoSijainti,ios::app | ios::out);

	if (sanasto.is_open()) {
		sanasto << sana << endl;
		sanasto.close();
		return true;
	}
	else
		return false;
}
