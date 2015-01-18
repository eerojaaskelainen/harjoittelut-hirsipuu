// Hirsipuu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Finnish");		// Asetetaan ‰‰kkˆset konsolille toimimaan

	// Hirsipuu: Peli jossa arvataan tietokoneen arpoma sana.
	Hirsipuu peli;								//Peliolion instanssi
	string syote = "";
	cout << "Kirjoita 1 jos haluat lis‰t‰ sanoja: ";
	getline(cin, syote);
	
	if (syote != "") {
		SanaToiminnat *st = new SanaToiminnat();
		st->SyotaSanoja();
		delete st;
	}

	bool uudestaan = false;						// Pelataanko uudelleen?
	do {
		uudestaan = peli.AloitaPeli();			//Pelataan kunnes k‰ytt‰j‰ haluaa lopettaa.
	} while (uudestaan == true);

	return 0;
}

Hirsipuu::Hirsipuu() {
	
}

void Hirsipuu::Alusta(){
	// Nollataan globaalit muuttujat
	virheArvauksia = 0;
	arvaukset.clear();
	
}
bool Hirsipuu::AloitaPeli() {
	
	//Pelin p‰‰funktio.



	Alusta();								// Nollataan pelin alussa globaalit muuttujat

	SanaToiminnat sanaT;					// Sis‰lt‰‰ arvattavat sanat
	string sana = sanaT.PoimiSana();		// Pelikierroksella arvattava sana
	int sananPituus = sana.length();		// Montako merkki‰ sanassa on. K‰ytet‰‰n maskin luonnissa

	char arvattuKirjain = NULL;				// K‰ytt‰j‰lt‰ kysytty kirjain
	
	Grafiikat grafiikka;					// Grafiikan (konsolille) muodostavat metodit
	string viesti = "";						// Mahdollinen virhe/infoviesti joka toimitetaan ruudun piirt‰j‰lle
	

	if (sana.size() == 0) {
		return false;
	}

	// Peli alkaa: Tulostetaan otsikko
	grafiikka.TulostaAlku();	
	
	// Luodaan sanalle maski, jota n‰ytet‰‰n k‰ytt‰j‰lle:
	int* maski = new int[sananPituus];		//Array maski, johon talletetaan sanasta arvatut kirjaimet (1). Arvaamattomat kirjaimet ovat 0.
	for (int i = 0; i < sananPituus; i++) {	//Alustetaan maski
		*(maski+i) = 0;
	}



	

	do {
		if (debug) { viesti.append("\tDEBUG: Sanana on "); viesti.append(sana); viesti.append("\n"); };

		// Tulostetaan mahdollinen hirsipuu (v‰hint‰‰n tulostetaan sanan paikkamerkit):
		grafiikka.TulostaHirsipuu(KirjoitaPiilosana(maski,sana),virheArvauksia,viesti);
		viesti = "";		//Nollataan viesti, uusi kierros kun alkaa.

		if (OnkoSanaArvattu(maski, sananPituus)) {
			// K‰ytt‰j‰ on saanut kaikki kirjaimet auki => Arvannut sanan.
			grafiikka.TulostaOikein(sana, virheArvauksia);
			break;
		}
		

		if (virheArvauksia < MAX_VIRHEMAARA) {
			// Jos pelaajalla on viel‰ arvauksia j‰ljell‰, kysyt‰‰n merkki‰ ja tutkitaan osuiko:

			kirjainVirhe eKirjainVirhe = KysyKirjainta(arvattuKirjain,&grafiikka);		// Kysyt‰‰n kirjainta k‰ytt‰j‰lt‰.

			if (eKirjainVirhe == kirjainVirhe::USER_HALUAA_LOPETTAA) { break; }	// K‰ytt‰j‰ haluaa lopettaa.
			else if (eKirjainVirhe == kirjainVirhe::EI_KELPAA) { 	// Merkki ei kelpaa.
				viesti = "Merkki ei kelpaa! Anna kirjain tai 0 lopettaaksesi.";
				continue;
			}


			// Merkki kelpaa ja k‰ytt‰j‰ haluaa pelata: Jatketaan

			if (!OnkoKirjainJoAnnettu(arvattuKirjain)) {	// K‰ytt‰j‰ ei ole antanut samaa kirjainta aiemmin.
				if (!TestaaKirjainta(arvattuKirjain, maski, sana)){
					// Kirjainta ei lˆytynyt sanasta: Jalostetaan hirsipuuta:
					virheArvauksia++;
					if (debug) { cout << "DEBUG: Vaarin arvattu." << endl; }
				}
			}
			else { // K‰ytt‰j‰ on antanut saman kirjaimen aiemmin...
				viesti = "Olet antanut jo saman kirjaimen. Kokeileppa uudestaan.";
			}


		}
		
		else {		// Yritysten m‰‰r‰ ylittyi: Game OVER!
			grafiikka.TulostaGameOver(sana, virheArvauksia);
			break;
		}
	} while (arvattuKirjain != 0);

	//Tuhotaan dynaaminen maski:
	delete[] maski;
	maski = 0;

	//Kysyt‰‰n k‰ytt‰j‰lt‰, haluaako pelata uudelleen:
	return grafiikka.KysyJatketaanko();
}




Hirsipuu::kirjainVirhe Hirsipuu::KysyKirjainta(char &kirjain, Grafiikat *grafiikka) {
	//Funktio kysyy k‰ytt‰j‰lt‰ kirjainta jota sanasta etsit‰‰n.
	// Kirjain talletetaan &kirjain -argumenttiin. Palautetaan kyselyn tulos (ok, ei kelpaa, tai k‰ytt‰j‰ haluaa lopettaa.
	// Palauttaa joko kelvollisen merkin, tai 0:n (lopetus).

	char vastaus = NULL;
	bool kelpasi = false;

		grafiikka->TulostaKirjainkysely();
		cin >> vastaus;

		if (vastaus >= 65 && vastaus <= 90) {
			// K‰ytt‰j‰ antoi kelvollisen ISON kirjaimen
			kelpasi = true;
		}
		else if (vastaus >= 97 && vastaus <= 122) {
			// K‰ytt‰j‰ antoi kelvollisen pienen kirjaimen
			kelpasi = true;
		}
		else if (vastaus == -124 || vastaus ==(-108)) {
			// K‰ytt‰j‰ antoi kelvollisen erikoismerkin (Â‰ˆ)
			kelpasi = true;
		}
		else if (vastaus == 48) {
			// K‰ytt‰j‰ ei halua en‰‰ pelata. (ASCII 48 on '0')
			return USER_HALUAA_LOPETTAA;
		}


		if (kelpasi == true) {
			vastaus = tolower(vastaus);		// Pakotetaan merkki lowercaseksi.
			kirjain = vastaus;
			return SYOTE_OK;
		}
		else
			kirjain = -1;
			return EI_KELPAA;				// Annettu merkki ei kelpaa.


}

bool Hirsipuu::TestaaKirjainta(const char kirjain, int* maski, const string &sana) {

	// Testataan, onko arvattavassa sanassa annettuja kirjaimia.
	// palauttaa boolean-arvon, sek‰ muokkaa argumenttina annettua maskia muuttaen arvatun merkin kohdasta kahvan p‰‰lle

	bool loytyi = false;
	int sananPituus = sana.length();

	
	
		

		arvaukset.push_back(kirjain);					// Lis‰t‰‰n k‰ytt‰j‰n syˆtt‰m‰ kirjain arvauksiin.

		// K‰ymme sanan merkki merkilt‰ l‰pi: Jos merkki lˆytyy, lippu loytyi trueksi ja sama kohta maskista p‰‰lle:

		for (int i = 0; i < sananPituus; i++) {	//K‰ymme sanan merkki merkilt‰ l‰pi
			if (debug) cout << "DEBUG: Maskissa " << i<< " on "<< *(maski+i) << endl;
			if (*(maski + i) == 0) {	//K‰ymme vain arvaamattomat kirjaimet l‰pi.

				if (tolower(sana.at(i)) == tolower(kirjain)) {	// Kirjain (pakotettuna pieniksi) osui!
					loytyi = true;
					*(maski + i) = 1;		// Merkkaamme maskiin merkin lˆytyneeksi.
				}
			}
		}
		return loytyi;

}

inline bool Hirsipuu::OnkoKirjainJoAnnettu(const char kirjain) {
	//Funktio tarkastaa, onko k‰ytt‰j‰ jo arvannut kirjaimen ja nyt yritt‰‰ arvata kirjainta uudelleen.
	bool palautus = false;

	for (vector<char>::size_type i = 0; i < arvaukset.size(); i++) {				//http://www.mochima.com/tutorials/vectors.html
		if (arvaukset[i] == kirjain) {
			// Kirjain on jo sanottu!
			palautus = true;
			break;
		}
	}

	return palautus;
}

bool Hirsipuu::OnkoSanaArvattu(const int* maski, const int kirjaintenLkm) {
	// Tutkitaan maski, jos kaikki solut ovat 1:si‰, on sana arvattu ja peli voitettu.
	// Jos yksikin kirjain on piilossa, ei sanaa ole arvattu.
	bool vastaus = true;

	for (int i = 0; i < kirjaintenLkm; i++) {
		if (*(maski + i) == 0) {
			vastaus = false;
			break;
		}
	}

	return vastaus;
}
string Hirsipuu::KirjoitaPiilosana(const int* maski, const string &sana) {
	//funktio avaa sanan, eli palauttaa sanan, mutta j‰tt‰‰ arvaamattomat kirjaimet n‰ytt‰m‰tt‰.
	//Palauttaa sanan, jossa arvaamattomien kirjainten tilalla piste.

	string palauta = sana;
	int sananPituus = sana.length();

	// K‰ymme sanan merkki merkilt‰ l‰pi: Jos merkki lˆytyy, lippu loytyi trueksi ja sama kohta maskista p‰‰lle:

	for (int i = 0; i < sananPituus; i++) {	//K‰ymme sanan merkki merkilt‰ l‰pi
		if (*(maski + i) == 0) {
			palauta.at(i) = '.';		// Arvaamattomien kirjainten paikalle laitetaan tyhj‰ merkki.
		}
	}
	return palauta;
}

