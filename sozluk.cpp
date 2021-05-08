/* Alihan Demirel
*sozluk.cpp
*/

#include "sozluk.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

Sozluk::Sozluk()
{
	kayitlar = nullptr;
	toplamKayitSayisi = 0;
}
Sozluk::Sozluk(const Kayit &kayit)
{
	kayitlar = new Kayit[1];
	if (kayitlar != nullptr)
	{
		kayitlar[0] = kayit;
		toplamKayitSayisi = 1;
	}
}
Sozluk::Sozluk(const Sozluk &diger)
{
	if (kayitlar != nullptr)
	{
		delete[] kayitlar;
	}
	kayitlar = nullptr;
	toplamKayitSayisi = diger.toplamKayitSayisi;
	kayitlar = new Kayit[toplamKayitSayisi];

	if (kayitlar == nullptr)
	{
		exit(-1);
	}
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		kayitlar[i] = diger.kayitlar[i];
	}
}

Sozluk::~Sozluk()
{
	if (kayitlar != nullptr)
		delete[] kayitlar;
}

Sozluk::Sozluk(const vector<Kayit> &kayitlar)
{
	toplamKayitSayisi = kayitlar.size();
	vector<Kayit> temp;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i)
	{
		temp.push_back(kayitlar[i]);
	}

	toplamKayitSayisi = temp.size();
	this->kayitlar = nullptr;
	this->kayitlar = new Kayit[toplamKayitSayisi];
	if (this->kayitlar == nullptr)
		exit(-1);

	for (unsigned i = 0; i < toplamKayitSayisi; ++i)
	{
		this->kayitlar[i] = temp[i];
	}
}

Kayit &Sozluk::operator[](const string &kelime)
{
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		if (kayitlar[i].kelime_al() == kelime)
			return kayitlar[i];
	}
	cout << "ERROR" << endl;
	cout << "bulunamadi" << endl;
	exit(-1);
}

Sozluk &Sozluk::operator=(const Sozluk &other)
{
	if (this == &other)
		return *this;
	if (kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = new Kayit[toplamKayitSayisi];
	if (kayitlar == nullptr)
		exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		kayitlar[i] = other.kayitlar[i];
	}

	return *this;
}
ostream &operator<<(ostream &o, const Sozluk &s)
{
	int toplamAciklama = 0;
	o << "Toplam bulunun kayitlarin sayisi ->" << s.toplamKayitSayisi << endl;
	for (unsigned i = 0; i < s.toplamKayitSayisi; i++)
		toplamAciklama = toplamAciklama + s.kayitlar[i].boyut_al();
	o << "Toplam bulunan aciklamalarin sayisi ->" << toplamAciklama << endl;
	return o;
}
bool Sozluk::operator<(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	}
	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
	{
		digertoplamaciklama += other.kayitlar[i].boyut_al();
	}
	if (thistoplamaciklama > digertoplamaciklama)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Sozluk::operator>(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	}
	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
	{

		digertoplamaciklama += other.kayitlar[i].boyut_al();
	}
	if (thistoplamaciklama > digertoplamaciklama)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Sozluk::operator<=(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	}
	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
	{
		digertoplamaciklama += other.kayitlar[i].boyut_al();
	}
	if (thistoplamaciklama >= digertoplamaciklama)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Sozluk::operator>=(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	}
	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
	{
		digertoplamaciklama += other.kayitlar[i].boyut_al();
	}
	if (thistoplamaciklama >= digertoplamaciklama)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Sozluk::operator==(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;

	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	}

	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
	{
		digertoplamaciklama += other.kayitlar[i].boyut_al();
	}
	if (thistoplamaciklama == digertoplamaciklama)
	{
		return true;
	}
	else
	{

		return false;
	}
}
bool Sozluk::operator!=(const Sozluk &other)
{
	int thistoplamaciklama = 0;
	int digertoplamaciklama = 0;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
		thistoplamaciklama += this->kayitlar[i].boyut_al();
	for (unsigned i = 0; i < other.toplamKayitSayisi; i++)
		digertoplamaciklama += other.kayitlar[i].boyut_al();
	if (thistoplamaciklama != digertoplamaciklama)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Sozluk Sozluk::operator+(const Sozluk &digerSozluk)
{

	Sozluk gecici;
	gecici.toplamKayitSayisi = toplamKayitSayisi + digerSozluk.toplamKayitSayisi;

	gecici.kayitlar = new Kayit[gecici.toplamKayitSayisi];
	if (gecici.kayitlar == nullptr)
		exit(-1);

	for (int i = 0; i < toplamKayitSayisi; i++)
	{
		gecici.kayitlar[i] = this->kayitlar[i];
	}

	for (int j = 0; j < digerSozluk.toplamKayitSayisi; j++)
	{
		gecici.kayitlar[j + toplamKayitSayisi] = digerSozluk.kayitlar[j];
	}

	return gecici;
}

Sozluk &Sozluk::operator+=(const Sozluk &digerSozluk)
{
	Sozluk gecici;

	gecici.kayitlar = this->kayitlar;
	gecici.toplamKayitSayisi = this->toplamKayitSayisi;
	delete this;

	this->toplamKayitSayisi = gecici.toplamKayitSayisi + digerSozluk.toplamKayitSayisi;

	kayitlar = new Kayit[this->toplamKayitSayisi];

	if (this->kayitlar != nullptr)
	{
		delete[] kayitlar;
	}

	for (int i = 0; i < this->toplamKayitSayisi; i++)
	{
		this->kayitlar[i] = gecici.kayitlar[i];
	}

	for (int j = 0; j < this->toplamKayitSayisi; j++)
	{
		this->kayitlar[j + toplamKayitSayisi] = digerSozluk.kayitlar[j];
	}

	return *this;
}

Sozluk &Sozluk::operator-=(const Kayit &kayit)
{
	for (int i = 0; i < toplamKayitSayisi; i++)
	{
		if (kayit.kelime_al() == kayitlar[i].kelime_al())
		{
			kayitlar[i].domestos();
		}
	}
	return *this;
}

Sozluk &Sozluk::operator-=(const string &kelime)
{
	for (int i = 0; i < toplamKayitSayisi; i++)
	{
		if (kayitlar[i].kelime_al() == kelime)
		{
			kayitlar[i].domestos();
		}
	}
	return *this;
}
ofstream &operator<<(ofstream &out, const Sozluk &s)
{

	for (unsigned int i = 0; i < s.toplamKayitSayisi; i++)
	{

		out << s.kayitlar[i] << endl;
	}

	return out;
}
ifstream &operator>>(ifstream &in, Sozluk &s)
{
	string next, kelime, aciklama, next2;
	vector<string> pencil;
	vector<Kayit> book;
	while (getline(in, next))
	{
		getline(in, kelime);
		getline(in, next2);
		if (next2 == "Aciklama:")
		{
			while (getline(in, aciklama))
			{
				pencil.push_back(aciklama);
			}
		}
		Kayit yeni(kelime, pencil);
		book.push_back(yeni);
	}
	Sozluk s2(book);
	s = s2;

	return in;
}
