/* Alihan Demirel
*kayit.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include "kayit.h"

using namespace std;
int Kayit::boyut_al()
{
    return aciklama.size();
}
string Kayit::kelime_al() const
{
    return kelime;
}

void Kayit::domestos()
{
    aciklama.clear();
}

// Kelime ve o kelimeye ait tum aciklamalari satir satir ekrana yazar.
ostream &operator<<(ostream &outStream, const Kayit &kayit)
{
    outStream << "Kelime: " << endl;
    outStream << kayit.kelime << endl;
    for (int i = 0; i < kayit.aciklama.size(); i++)
    {
        outStream << "Aciklama:" << endl;
        outStream << kayit.aciklama[i] << endl;
    }

    return outStream;
}
// getline ile satır satır veri okunur. İlk satır kelimedir, diger her bir satır bir acıklamadır.
istream &operator>>(istream &inStream, Kayit &kayit)
{

    cout << "Eklemek istediginiz kelime" << endl;
    getline(inStream, kayit.kelime);
    kayit.aciklama.clear();
    cout << "aciklamalari giriniz" << endl;
    int i = 0;
    string x;
    while (true)
    {

        cout << i + 1 << ".aciklama" << endl;
        getline(inStream, x);
        if (x == "")
        {
            break;
        }

        kayit.aciklama.push_back(x);
        i++;
    }

    return inStream;
}
//Bu yapici(constructor) fonksiyon bir kelime icin tek bir aciklama metni alir
Kayit::Kayit(const string &kelime, const string &aciklama)
{
    this->kelime = kelime;

    this->aciklama.push_back(aciklama);
}
//Bu yapici aciklamalarin bir vektorunu alir.
Kayit::Kayit(const string &kelime, const vector<string> &aciklamalar)
{
    this->kelime = kelime;
    for (unsigned int i = 0; i < aciklamalar.size(); i++)
    {

        this->aciklama.push_back(aciklamalar[i]);
    }
}
// Bir kayit bossa (kelime == "" veya hic aciklamasi yoksa) dogru yoksa yanlis donderir
bool Kayit::operator!()
{
    if (this->kelime == "" || this->aciklama.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Bir kayita daha once o kayitta olmayan yeni bir anlam/aciklama eklenebilir.
const Kayit &Kayit::operator+(const string &aciklama)
{
    bool done = false;
    for (unsigned int i = 0; i < this->aciklama.size(); i++)
    {
        if (aciklama == this->aciklama[i])
        {

            done = true;
        }
    }
    if (!done)
    {
        this->aciklama.push_back(aciklama);
    }
    return *this;
}
// Eger iki kaydin kelimeleri ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
bool Kayit::operator==(const Kayit &digerKayit)
{
    bool done = true;
    for (int i = 0; i < this->aciklama.size(); i++)
    {
        for (int j = 0; j < this->aciklama[i].size(); j++)
        {

            if (this->aciklama[i][j] == ' ')
            {
                done = false;
            }
        }
    }

    bool done1 = true;
    for (int i = 0; i < digerKayit.aciklama.size(); i++)
    {
        for (int j = 0; j < digerKayit.aciklama[i].size(); j++)
        {
            if (digerKayit.aciklama[i][j] == ' ')
            {
                done1 = false;
            }
        }
    }
    if (this->kelime == digerKayit.kelime || !done || !done1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Eger kaydin kelimesi verilen kelime ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
bool Kayit::operator==(const string &digerKelime)
{
    bool done = true;
    for (int i = 0; i < this->aciklama.size(); i++)
    {
        for (int j = 0; j < this->aciklama[i].size(); j++)
        {
            if (this->aciklama[i][j] == ' ')
            {
                done = false;
            }
        }
    }
    if (this->kelime == digerKelime || !done)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Bir kayitta bulunan anlam/aciklama cikartilabilir.
const Kayit &Kayit::operator-(const string &aciklama)
{
    for (int i = 0; i < this->aciklama[i].size(); i++)
    {
        if (aciklama == this->aciklama[i])
        {
            this->aciklama.erase(this->aciklama.begin() + i);
        }
    }
    return *this;
}
// Eger iki kaydin kelime degerleri esit ise aciklama vektorlerinin birlesim kumesi olusturulur.
const Kayit &Kayit::operator+(const Kayit &digerKayit)
{

    bool done = false;

    if (this->kelime == digerKayit.kelime)
    {
        for (unsigned int i = 0; i < digerKayit.aciklama.size(); i++)
        {
            for (unsigned int j = 0; j < this->aciklama.size(); j++)
            {
                if (digerKayit.aciklama[i] == this->aciklama[j])
                {
                    done = true;
                }
            }
            if (!done)
                this->aciklama.push_back(digerKayit.aciklama[i]);
        }
    }
    return *this;
}
