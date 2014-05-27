

class Grafiikat {
	const char auml = '\204';
	const char ouml = '\366';

public:
	void TulostaAlku();
	void TulostaOikein(string, int);
	void TulostaGameOver(string, int);
	void TulostaKirjainkysely();
	void TulostaHirsipuu(const string&, int, string = "");
	bool KysyJatketaanko();
};