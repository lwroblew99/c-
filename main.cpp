#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Okrag
{
private:
	string nazwa;
	float promien;
public:
	Okrag()
	{
		nazwa = "";
		promien = 0.0;
	}
	Okrag(string n, float r) :nazwa(n), promien(r) {}
	float obwod()
	{
		return 2 * 3.14 * promien;
	}
	void wyswietl()
	{
		cout << nazwa<<" "<<obwod()<<" ";
	}
	void wpisz()
	{
		cin >> nazwa >> promien;
	}
};
/*bool operator > (Okrag zm1, Okrag zm2)
{
	if (zm1.obwod() > zm2.obwod())
		return true;
	else return false;
}*/

class Ksztalt
{
public:
	//Ksztalt() {}
	virtual float obwod() { return 0.0; }
	virtual void wyswietl() {}
	virtual void wpisz() {}
};

class Kolo:public Ksztalt
{
private:
	string nazwa;
	float promien;
public:
	Kolo()
	{
		this->wpisz();
	}
	//Kolo(string n, float r) :nazwa(n), promien(r) {}
	float obwod()
	{
		return 2 * 3.14 * promien;
	}
	float pole()
	{
		return promien * promien * 3.14;
	}
	void wyswietl()
	{
		cout << nazwa << " " << promien << " ";
	}
	void wpisz()
	{
		cin >> nazwa >> promien;
	}
};

class Prostokat :public Ksztalt
{
private:
	string nazwa;
	float a, b;
public:
	Prostokat() {
		this->wpisz();
	}
	//Prostokat(string n, float a_, float b_) :nazwa(n), a(a_), b(b_) {}
	float obwod()
	{
		return a + a + b + b;
	}
	float pole()
	{
		return a * b;
	}
	void wyswietl()
	{
		cout << nazwa << " " << a << " " << b << " ";
	}
	void wpisz()
	{
		cin >> nazwa >> a >> b;
	}
};

int main()
{
	int zm;
	cin >> zm;
	//zm = 1;
	switch (zm)
	{
	case 1:
	{
		int rozmiar;
		cin >> rozmiar;

		Okrag* tablica = new Okrag[rozmiar];

		for (int i = 0; i < rozmiar; i++)
		{
			tablica[i].wpisz();
		}
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar - 1; j++)
			{
				if (tablica[j].obwod() < tablica[j+1].obwod())
				{
					swap(tablica[j], tablica[j+1]);
				}
			}
		}
		for (int i = 0; i < rozmiar; i++)
		{
			tablica[i].wyswietl();
		}
		delete[] tablica;
		break;
	}
	case 2:
	{
		int wiersze;
		int kolumny;
		cin >> wiersze >> kolumny;
		//wiersze = 2; kolumny = 2;
		//Kolo kolo;
		//Prostokat prostokat;
		Ksztalt*** tablica = new Ksztalt**[wiersze];
		for (int i = 0; i < wiersze; i++)
		{
			tablica[i] = new Ksztalt*[kolumny];
			for (int j = 0; j < kolumny; j++)
			{
				if (i % 2 == 0)
				{
					tablica[i][j] = new Kolo();
				}
				else
				{
					tablica[i][j] = new Prostokat();
				}
			}
		}

		int wier, kol;
		cin>>wier>>kol;

		tablica[wier][kol]->wyswietl();


		for (int i = 0; i < wiersze; i++)
		{
			delete[] tablica[i];
		}
		delete[] tablica;
		break;
	}
	}
}