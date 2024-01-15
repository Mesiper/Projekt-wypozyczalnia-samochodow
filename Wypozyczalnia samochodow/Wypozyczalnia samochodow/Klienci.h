#pragma once
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Klienci
{
public:
    string imie;
    string nazwisko;
    string pesel;
    string dataurodzenia;
    string obywatelstwo;
    string dokument;
    string nrdokumentu;
    string datawaznoscidokument;
    string wazneprawojazdy; //czy to nie powinien byc bool?
    string id_samochodu;
    bool posiadanysamochod = 0;

    void Dodawanie_klienta();

    void wyswietldane();
    void czyposiadasamochod();
    void wypozyczenie();
    void oddanie();

};

