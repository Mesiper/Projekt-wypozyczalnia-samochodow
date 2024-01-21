#include "samochody_dostawcze.h"

void samochody_dostawcze::wczytywanie()
{
    std::fstream plik;
    //test
    plik.open("samochodydostawcze.txt", std::ios::in);

    if (plik.good() == true)
    {
        int nr_linii = (ktory_samochod - 1) * ilosc_atrybutow;
        string linia;
        int licznik = 0;
        while (std::getline(plik, linia))
        {
            if (licznik == nr_linii) marka = linia;
            if (licznik == nr_linii + 1) model = linia;
            if (licznik == nr_linii + 2) tablica = linia;
            if (licznik == nr_linii + 3) typ_paliwa = linia;
            if (licznik == nr_linii + 4) pojemnosc_samochodu = linia;
            licznik++;
        }
    }
    else
    {
        cout << " Problem z plikiem! ";
    }
    plik.close();
}

void samochody_dostawcze::zapis_do_pliku() {
    std::fstream plik;
    plik.open("samochodydostawcze.txt", std::ios::out | std::ios::app);

    plik << marka << std::endl;
    plik << model << std::endl;
    plik << tablica << std::endl;
    plik << typ_paliwa << std::endl;
    plik << pojemnosc_samochodu << std::endl;

    plik.close();
}

void samochody_dostawcze::wyswietl()
{
    cout << "-----------------------------------" << '\n';
    cout << marka << '\n';
    cout << "Model: " << model << '\n';
    cout << "Tablia: " << tablica << '\n';
    cout << "Typ paliwa: " << typ_paliwa << '\n';
    cout << "Pojemnosc auta w litrach: " << pojemnosc_samochodu << '\n';
}

void samochody_dostawcze::dodawanie()
{
    std::fstream plik;

    cout << "Podaj marke: ";
    cin >> marka;
    cout << "Podaj model: ";
    cin >> model;
    cout << "Podaj tablice: ";
    cin >> tablica;
    cout << "Podaj typ paliwa: ";
    cin >> typ_paliwa;
    cout << "Podaj pojemnosc samochodu w litrach: ";
    cin >> pojemnosc_samochodu;

    plik.open("samochodydostawcze.txt", std::ios::out | std::ios::app);

    plik << marka << '\n';
    plik << model << '\n';
    plik << tablica << '\n';
    plik << typ_paliwa << '\n';
    plik << pojemnosc_samochodu << '\n';

    plik.close();
}

int samochody_dostawcze::ile_aut_w_pliku() {
    std::fstream plik;
    plik.open("samochodydostawcze.txt", std::ios::in);

    int licznik = 0;
    string linia;

    // petla tylko zlicza ilosc samochodow, wczytywane dane sa niewykorzystywane
    while (!plik.eof()) {
        std::getline(plik, linia);
        licznik++;
    }

    /* dzielenie calkowite daje liczbe calkowita zaokraglona w dol,
    * wiec jesli jakis samochod nie ma wpisanych wszystkich danych
    * funkcja zwroci za malo samochodow */
    return licznik / ilosc_atrybutow;
}
