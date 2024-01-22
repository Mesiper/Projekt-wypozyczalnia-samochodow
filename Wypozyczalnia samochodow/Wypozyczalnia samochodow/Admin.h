#pragma once
#include "Klienci.h"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class Admin :
    public Klienci
{
    
    string login;
    string haslo;
    
    
    int ktory_klient;

    /* stala okreslajaca ilosc atrybutow, zeby nie trzeba bylo liczby wpisywac,
    * tylko mozna zmienna (przydatne bardziej przy testach)
    * static oznacza, ze wartosc zmiennej jest taka sama
    * dla wszystkich obiektow tej klasy */
    const static int ilosc_atrybutow = 2;

    void wczytywanie();
    void zapis_do_pliku();
    bool logowanie(string pesel, string haslo);
};

