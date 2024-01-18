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

    /* stala okreslajaca ilosc atrybutow, zeby nie trzeba bylo liczby wpisywac,
    * tylko mozna zmienna (przydatne bardziej przy testach)
    * static oznacza, ze wartosc zmiennej jest taka sama
    * dla wszystkich obiektow tej klasy */
    const static int ilosc_atrybutow = 4;

    void wczytywanie();
    void wyswietl();
    void dodawanie();
    void dodawanie_auta();
    void wyswietlanie();
    int ile_aut_w_pliku();
    void raport();
};

