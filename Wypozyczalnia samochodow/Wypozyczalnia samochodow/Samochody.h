#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Samochody
{
public:
    string marka;
    string model;
    string tablica;
    string typ_paliwa;
    /*
    string kolor;
    string rodzaj_skrzyni;
    int moc;
    int rocznik;
    int ilosc_miejsc;
    bool dostepnosc;
    */
    int ktory_samochod;

    void wczytywanie();
    void wyswietl();
    void dodawanie();
    void dodawanie_auta();
    void wyswietlanie();
    void raport();
};

