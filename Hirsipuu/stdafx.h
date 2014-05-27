// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <iostream>
#include <cassert>			//Virheet
#include <string>
#include <vector>
#include <cctype>		// Char uppercaseksi tai lowercaseksi

using namespace std;
#define debug false

#include "tiedostotoimet.h"
#include "SanaToiminnat.h"
#include "Grafiikat.h"

const int MAX_VIRHEMAARA = 6;			// Virheellisten arvausten enimm‰ism‰‰r‰. T‰‰ll‰ koska grafiikat -olion static_assert ei toimi.


class Hirsipuu {
private:
	int virheArvauksia = 0;					// Virhearvausten m‰‰r‰
	enum kirjainVirhe {						// Millainen oli k‰ytt‰j‰n antama merkki?
		EI_KELPAA = -1, 
		USER_HALUAA_LOPETTAA =0 , 
		SYOTE_OK = 1 };

	vector<char> arvaukset;					// Arvatut kirjaimet
	SanaToiminnat sanaT;

	void Alusta();												// Olion alustusmetodi:
	kirjainVirhe KysyKirjainta(char& ,Grafiikat*);				// Kysyt‰‰n k‰ytt‰j‰lt‰ kirjain ja testataan sen validius
	bool TestaaKirjainta(const char, int*, const string&);		// Tutkitaan, osuiko arvattu kirjain
	inline bool OnkoKirjainJoAnnettu(const char);
	bool OnkoSanaArvattu(const int*, const int);
	string KirjoitaPiilosana(const int*, const string&);
public:
	Hirsipuu();
	bool AloitaPeli();
};

//struct Sana { string sana; int merkkimaara; };