#include "Klienci.h"

void Klienci::wczytywanie() {
    std::fstream plik;

    plik.open("klienci.txt", std::ios::in);

    if (plik.good() == true)
    {
        int nr_linii = (ktory_klient - 1) * ilosc_atrybutow;
        string linia;
        int licznik = 0;

        while (std::getline(plik, linia))
        {
            if (licznik == nr_linii) imie = linia;
            if (licznik == nr_linii + 1) nazwisko = linia;
            if (licznik == nr_linii + 2) pesel = linia;
            if (licznik == nr_linii + 3) haslo = linia;
            licznik++;
        }
        plik.close();
    }
    else
    {
        cout << " Problem z plikiem! ";
    }
}

void Klienci::zapis_do_pliku() {
    std::fstream plik;
    plik.open("klienci1.txt", std::ios::out | std::ios::app);

    plik << imie << std::endl;
    plik << nazwisko << std::endl;
    plik << pesel << std::endl;
    plik << haslo << std::endl;

    plik.close();
}

void Klienci::Dodawanie_klienta() {
    cout << "Podaj imie\n";
    cin >> imie;
    cout << "Podaj nazwisko\n";
    cin >> nazwisko;
    cout << "Podaj pesel\n";
    cin >> pesel;
    cout << "Podaj haslo\n";
    cin >> haslo;
    std::fstream plik;
    plik.open("klienci.txt", std::ios::out | std::ios::app);
    plik << imie << '\n';
    plik << nazwisko << '\n';
    plik << pesel << '\n';
    plik << haslo << '\n';
  
    plik.close();

}
void Klienci::wyswietldane() {
    cout << imie << '\n';
    cout << nazwisko << '\n';
    cout << pesel << '\n';
}
void Klienci::czyposiadasamochod() {
    if (posiadanysamochod) {
        cout << "gotowy oddac samochod?" << '\n';
    }
}
void Klienci::wypozyczenie() {
    if (posiadanysamochod) {
        cout << "gotowy oddac samochod?" << '\n';
    }
    else {
        cout << "podaj id wypozycznego samochodu" << '\n';
        cin >> id_samochodu;
        posiadanysamochod = 1;
    }





}
void Klienci::oddanie() {
    if (posiadanysamochod) {
        cout << "gotowy oddac samochod?" << '\n';
        posiadanysamochod = 0;
    }
}

int Klienci::ile_klientow_w_pliku() {
    std::fstream plik;
    plik.open("klienci.txt", std::ios::in);

    int licznik = 0;
    string linia;

    // petla tylko zlicza ilosc klientow, wczytywane dane sa niewykorzystywane
    while (!plik.eof()) {
        std::getline(plik, linia);
        licznik++;
    }

    /* dzielenie calkowite daje liczbe calkowita zaokraglona w dol,
    * wiec jesli jakis klient nie ma wpisanych wszystkich danych
    * funkcja zwroci za malo klientow */
    return licznik / ilosc_atrybutow;
}
bool Klienci::logowanie(string pesel, string haslo) {
    std::fstream plik;
    plik.open("klienci.txt", std::ios::in);

    if (plik.good() == true) {
        string linia;
        int licznik = 0;
        bool zalogowany = false;

        while (std::getline(plik, linia)) {
            if (licznik % ilosc_atrybutow == 2) {
                // We are processing the line containing PESEL
                if (linia == pesel) {
                    // Znaleziono klienta o podanym PESELu
                    // Move to the next line (line containing the password)
                    std::getline(plik, linia);
                    if (linia == haslo) {
                        zalogowany = true;
                        break;
                    }
                }
            }
            licznik++;
        }
        plik.close();
        return zalogowany;
    }
    return false; 
}
