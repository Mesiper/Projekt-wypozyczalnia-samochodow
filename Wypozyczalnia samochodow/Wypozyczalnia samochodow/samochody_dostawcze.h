#pragma once
#include "Samochody.h"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class samochody_dostawcze :
    public Samochody
{
public:
    string pojemnosc_samochodu;
    const static int ilosc_atrybutow = 5;


    void wczytywanie();
    void zapis_do_pliku();
    void wyswietl();
    void dodawanie();
    //void dodawanie_auta();
    //void wyswietlanie();
    int ile_aut_w_pliku();
    //void raport();

};

