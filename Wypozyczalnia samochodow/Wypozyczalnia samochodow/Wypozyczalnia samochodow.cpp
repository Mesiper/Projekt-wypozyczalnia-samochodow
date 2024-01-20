// Wypozyczalnia samochodow.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include "Klienci.h"
#include "Samochody.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wyczysc_plik(string nazwa_pliku) {
    std::fstream plik;
    plik.open(nazwa_pliku, std::ios::out);
    plik.close();
}

int main()
{
    std::vector <Samochody> auta; // kontener (wektor) na samochody
    Samochody obiekt_pom_auta;
    
    /* zlicza ilosc aut w pliku tekstowym, zeby latwo w petli for wczytac
    * i wiedziec ktory to jest element do dodania do kontenera */
    int ile_aut = obiekt_pom_auta.ile_aut_w_pliku();
    //cout << ile_aut << endl;  // sprawdzenie czy dziala
    

    //auta.resize(3);

    // wczytywanie samochodow z pliku do wektora
    for (int i = 0; i < ile_aut; i++) {
        obiekt_pom_auta.ktory_samochod = i + 1;
        obiekt_pom_auta.wczytywanie();
        auta.push_back(obiekt_pom_auta);
        auta[i].wyswietl();
    }

    std::vector <Klienci> klienci; // kontener (wektor) na klientow
    Klienci obiekt_pom_klienci;

    /* zlicza ilosc klientow w pliku tekstowym, zeby latwo w petli for wczytac
    * i wiedziec ktory to jest element do dodania do kontenera */
    int ile_klientow = obiekt_pom_klienci.ile_klientow_w_pliku();
    //cout << ile_klientow << endl; // sprawdzenie czy dziala

    // wczytywanie klientow z pliku do wektora
    for (int i = 0; i < ile_klientow; i++) {
        obiekt_pom_klienci.ktory_klient = i + 1;
        obiekt_pom_klienci.wczytywanie();
        klienci.push_back(obiekt_pom_klienci);
        klienci[i].wyswietldane();
    }

    char wybor = 1;

    while (wybor != 3) {
        system("cls");  // czysci ekran, zeby na pustym ekranie wypisac menu glowne

        cout << "---- MENU GLOWNE ----" << endl;
        cout << "1. Samochody." << endl;
        cout << "2. Klienci." << endl;
        cout << "3. Wyjscie." << endl;
        cout << "Podaj liczbe: ";
        cin >> wybor;

        switch (wybor) {
        case '1':
            system("cls");  // czysci ekran, zeby na pustym ekranie wypisac menu samochodow a nie pod menu glownym

            char wybor_samochody;
            cout << "---- MENU SAMOCHODY ----" << endl;
            cout << "1. Wyswietl dane samochodu." << endl;
            cout << "2. Dodaj samochod." << endl;
            cout << "3. Policz samochody. " << endl;
            cout << "4. Wstecz." << endl;
            cin >> wybor_samochody;

            switch (wybor_samochody) {
            case '1':
                system("cls");

                string tablica;

                cout << "---- WYSWIETLANIE DANYCH SAMOCHODU ----" << endl;
                cout << "Podaj tablice samochodu: ";
                cin >> tablica;

                for (int i = 0; i < ile_aut; i++) {
                    if (tablica == auta[i].tablica) {
                        auta[i].wyswietl();
                    }
                }
            }
        case '2':
            system("cls");

            char wybor_klienci;

            cout << "---- MENU KLIENCI ----" << endl;
            cout << "1. Wyswietl dane klienta." << endl;
            cin >> wybor_klienci;

            switch (wybor_klienci) {
            case '1':
                string pesel;

                cout << "---- WYSWIETLANIE DANYCH KLIENTA ----" << endl;
                cout << "Podaj PESEL klienta: ";
                cin >> pesel;

                for (int i = 0; i < ile_klientow; i++) {
                    if (pesel == klienci[i].pesel) {
                        klienci[i].wyswietldane();
                    }
                }
            }
        }
    }
    
    /*
    obiekt.ktory_samochod = 1;
    obiekt.wczytywanie();
    auta.push_back(obiekt);
    auta[0].wyswietl();
    */


    /*
    Samochody obiekt;
    obiekt.wczytywanie();
    obiekt.wyswietl();
    */

    // zapis samochodow do pliku
    // czysci plik, do ktorego beda zapisywane dane
    wyczysc_plik("samochody1.txt");

    // zapisuje auta do uprzednio wyczyszczonego (pustego) pliku
    for (int i = 0; i < ile_aut; i++) {
        auta[i].zapis_do_pliku();
    }

    // zapis klientow do pliku
    // czysci plik, do ktorego beda zapisywane dane
    wyczysc_plik("klienci1.txt");

    // zapisuje klientow do uprzednio wyczyszczonego (pustego) pliku
    for (int i = 0; i < ile_aut; i++) {
        klienci[i].zapis_do_pliku();
    }

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
