
#ifndef SANATOIMINNAT
	#define SANATOIMINNAT 1
	#ifndef TIMELUOKKA
		#define TIMELUOKKA 1
		#include <ctime>
	#endif

class SanaToiminnat {
	
	int ArvoNumero(int maksimi);				//Arpoo satunnaisluvun jonka mukaan haetaan sana.
	vector<string> sanat;

public:
	SanaToiminnat();							// Luokan alustus ja suoritettavat komennot kun luokkaa luodaan.
	int SyotaSanoja();							// Funktio, jonka avulla voidaan syöttää peliin lisää arvattavia sanoja
	string PoimiSana();							// Funktio joka palauttaa sanan pelimoottorille

};




#endif
