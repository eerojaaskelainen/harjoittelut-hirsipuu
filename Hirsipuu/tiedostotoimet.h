//#include <iostream>
#include <fstream>


class Tiedosto {
public:
	vector<string> NoudaSanat();
	bool TalletaSana(string);
	
private:
	const string tiedostoSijainti = "sanat.csv";
};