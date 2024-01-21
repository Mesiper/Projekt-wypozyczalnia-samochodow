#pragma once
#include <iostream>
#include <fstream>
#include <string>

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
    string haslo;
    string id_samochodu;
    bool posiadanysamochod = 0;
    int ktory_klient;

    /* stala okreslajaca ilosc atrybutow, zeby nie trzeba bylo liczby wpisywac,
    * tylko mozna zmienna (przydatne bardziej przy testach)
    * static oznacza, ze wartosc zmiennej jest taka sama
    * dla wszystkich obiektow tej klasy */
    const static int ilosc_atrybutow = 4;

    void wczytywanie();
    void zapis_do_pliku();
    void Dodawanie_klienta();
    void wyswietldane();
    void czyposiadasamochod();
    void wypozyczenie();
    void oddanie();
    int ile_klientow_w_pliku();
    bool logowanie(string pesel, string haslo);
};

