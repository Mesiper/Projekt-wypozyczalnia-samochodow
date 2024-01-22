#include "Admin.h"
void Admin::wczytywanie() {
    std::fstream plik;

    plik.open("admin.txt", std::ios::in);

    if (plik.good() == true)
    {
        int nr_linii = (ktory_klient - 1) * ilosc_atrybutow;
        string linia;
        int licznik = 0;

        while (std::getline(plik, linia))
        {
            if (licznik == nr_linii) login = linia;
            if (licznik == nr_linii + 1) haslo = linia;
            licznik++;
        }
        plik.close();
    }
    else
    {
        cout << " Problem z plikiem! ";
    }
}