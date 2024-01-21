#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Samochody {
public:
    string marka;
    string model;
    string tablica;
    string typ_paliwa;

    int ktory_samochod;

    // Sta³a okreœlaj¹ca iloœæ atrybutów
    const static int ilosc_atrybutow;

    virtual void wczytywanie() = 0;
    virtual void zapis_do_pliku() = 0;
    virtual void wyswietl() = 0;
    virtual void dodawanie() = 0;
    //virtual void dodawanie_auta() = 0;
    //virtual void wyswietlanie() = 0;
    virtual int ile_aut_w_pliku() = 0;
};

