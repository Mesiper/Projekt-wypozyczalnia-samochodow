#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Samochody.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class samochod_dostawawczy: public Samochody{
public:
	int pojemnosc_samochodu;
	const static int ilosc_atrybutow = 5;
	
	
	void wczytywanie();
    void zapis_do_pliku();
    void wyswietl();
    void dodawanie();
    void dodawanie_auta();
    void wyswietlanie();
    int ile_aut_w_pliku();
    void raport();

};