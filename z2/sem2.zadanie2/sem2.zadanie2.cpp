#include "MOJE_FUNKJCE_HPP.h"

const char* efektMagiczny1(int mana)
{
	const int indeksy[] = { 0, 1, 2, 3 };
	const char* opisy[] = { "Ognisty pocisk", "Blyskawiczna eksplozja", "Ognista kula", "Ogniste tornado" };
	if (mana > 3)
	{
		mana = 3;
	}
	return opisy[indeksy[mana]];
	
}
const char* efektMagiczny2(int mana)
{
	const int indeksy[] = { 0, 1, 2, 3 };
	const char* opisy[] = { "Wodny pocisk", "Wodna eksplozja", "Wodna kula", "Wodne tornado" };
	if (mana > 3)
	{
		mana = 3;
	}
	return opisy[indeksy[mana]];

}

Przedmiot wypelnijPrzedmiot(const char* nazwa, sztukiZlota wartosc, TypRzadkosci typ, const char* efekt)
{
	Przedmiot nowy;
	strncpy(nowy.nazwa, nazwa, ROZMIAR_TXT);
	nowy.nazwa[ROZMIAR_TXT] = '\0';
	nowy.wartosc = wartosc;
	nowy.rzadkosc = typ;
	nowy.efekt = efekt;

	return nowy;
}

ostream& operator<<(ostream& str, const Przedmiot& p)
{
	static const char* NAZWY_TYPOW_RZADKOSCI[] = { "Pospolity","Niecodzienny","Rzadki","Unikatowy" };
	str << "\"" << p.nazwa << "\"" << " [" << p.wartosc << "]" << " {"
		<< NAZWY_TYPOW_RZADKOSCI[(int)p.rzadkosc] << "} Efekt: " << p.efekt;
	return str;
}

int main()
{
	Przedmiot wisiorek = wypelnijPrzedmiot("Amulet zaliczenia warunkowego ;)", 100, TypRzadkosci::unikatowa, efektMagiczny1(1));
	Przedmiot sygnet = wypelnijPrzedmiot("Sygnet poprawki ;)", 50, TypRzadkosci::popspolita, efektMagiczny2(2));
	cout << wisiorek << endl;
	cout << sygnet << endl;

	Przedmiot tablicaPrzedmiotow[] = { wisiorek, sygnet };
	int rozmiarTablicy = sizeof(tablicaPrzedmiotow) / sizeof(tablicaPrzedmiotow[0]); 


}

