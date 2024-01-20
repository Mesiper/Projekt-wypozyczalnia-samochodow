﻿// Wypozyczalnia samochodow.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include "Klienci.h"
#include "Samochody.h"
#include "samochody_dostawcze.h"

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

    // wczytywanie samochodow z pliku do wektora
    for (int i = 0; i < ile_aut; i++) {
        obiekt_pom_auta.ktory_samochod = i + 1;
        obiekt_pom_auta.wczytywanie();
        auta.push_back(obiekt_pom_auta);
        auta[i].wyswietl(); // do sprawdzenia
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
        klienci[i].wyswietldane();  // do sprawdzenia
    }

    std::vector <samochody_dostawcze> dostawczaki; // kontener (wektor) na samochody
    samochody_dostawcze obiekt_pom_dostawczaki;

    int ile_dostawczakow = obiekt_pom_dostawczaki.ile_aut_w_pliku();

    for (int i = 0; i < ile_dostawczakow; i++) {
        obiekt_pom_dostawczaki.ktory_samochod = i + 1;
        obiekt_pom_dostawczaki.wczytywanie();
        dostawczaki.push_back(obiekt_pom_dostawczaki);
        dostawczaki[i].wyswietl();  // do sprawdzenia
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
            cout << "1. Samochody osobowe." << endl;
            cout << "2. Samochody dostawcze." << endl;
            cout << "Podaj liczbe: ";
            cin >> wybor_samochody;

            switch (wybor_samochody) {
            case '1':
                system("cls");

                char wybor_sam_osobowe;

                cout << "---- MENU SAMOCHODY OSOBOWE ----" << endl;
                cout << "1. Wyswietl dane samochodu." << endl;
                cout << "2. Dodaj samochod." << endl;
                cout << "3. Usun samochod." << endl;
                cout << "4. Podaj ilosc samochodow." << endl;
                cout << "5. Wstecz." << endl;
                cin >> wybor_sam_osobowe;

                switch (wybor_sam_osobowe) {
                case '1': {
                    system("cls");

                    string tab;

                    cout << "---- WYSWIETLANIE DANYCH SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tab;

                    for (int i = 0; i < ile_aut; i++) {
                        if (tab == auta[i].tablica) {
                            auta[i].wyswietl();
                        }
                    }
                    break;
                }

                    case '2':
                        system("cls");

                        cout << "---- DODAWANIE SAMOCHODU ----" << endl;

                        obiekt_pom_auta.dodawanie();
                        auta.push_back(obiekt_pom_auta);
                        ile_aut++;
                        break;

                    case '3':
                        system("cls");

                        cout << "---- USUWANIE SAMOCHODU ----" << endl;

                        // funkcja usuwania z wektora
                        break;

                    case '4':
                        cout << "Ilosc samochodow: " << ile_aut;
                        break;
                }
                break;

            case '2':
                system("cls");

                char wybor_sam_dostawcze;

                cout << "---- MENU SAMOCHODY DOSTAWCZE ----" << endl;
                cout << "1. Wyswietl dane samochodu." << endl;
                cout << "2. Dodaj samochod." << endl;
                cout << "3. Usun samochod." << endl;
                cout << "4. Podaj ilosc samochodow." << endl;
                cout << "5. Wstecz." << endl;
                cin >> wybor_sam_dostawcze;

                switch (wybor_sam_dostawcze) {
                case '1': {
                    system("cls");

                    string tab1;

                    cout << "---- WYSWIETLANIE DANYCH SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tab1;

                    for (int i = 0; i < ile_dostawczakow; i++) {
                        if (tab1 == dostawczaki[i].tablica) {
                            dostawczaki[i].wyswietl();
                        }
                    }
                    break;
                }

                    case '2':
                        system("cls");

                        cout << "---- DODAWANIE SAMOCHODU ----" << endl;

                        obiekt_pom_dostawczaki.dodawanie();
                        dostawczaki.push_back(obiekt_pom_dostawczaki);
                        ile_aut++;
                        break;

                    case '3':
                        system("cls");

                        cout << "---- USUWANIE SAMOCHODU ----" << endl;

                        // funkcja usuwania z wektora
                        break;

                    case '4':
                        cout << "Ilosc samochodow: " << ile_aut;
                        break;
                }
            }
        case '2':
            system("cls");

            char wybor_klienci;

            cout << "---- MENU KLIENCI ----" << endl;
            cout << "1. Wyswietl dane klienta." << endl;
            cout << "2. Dodaj klienta." << endl;
            cout << "3. Usun klienta." << endl;
            cout << "4. Podaj ilosc klientow." << endl;
            cout << "5. Wypozycz samochod." << endl;
            cout << "6. Zwroc samochod." << endl;
            cin >> wybor_klienci;

            switch (wybor_klienci) {
            case '1': {
                system("cls");

                string pesel;

                cout << "---- WYSWIETLANIE DANYCH KLIENTA ----" << endl;
                cout << "Podaj PESEL klienta: ";
                cin >> pesel;

                for (int i = 0; i < ile_klientow; i++) {
                    if (pesel == klienci[i].pesel) {
                        klienci[i].wyswietldane();
                    }
                }
                break;
            }

                case '2':
                    system("cls");

                    cout << "---- DODAWANIE KLIENTA ----" << endl;

                    obiekt_pom_klienci.Dodawanie_klienta();
                    klienci.push_back(obiekt_pom_klienci);
                    ile_klientow++;
                    break;

                case '3':
                    system("cls");

                    cout << "---- USUWANIE KLIENTA ----" << endl;

                    // funkcja usuwania z wektora
                    break;

                case '4':
                    cout << "Ilosc klientow: " << ile_klientow;
                    break;

                case '5': {
                    string pesel;
                    
                    cout << "Podaj PESEL klienta: ";
                    cin >> pesel;

                    for (int i = 0; i < ile_klientow; i++) {
                        if (pesel == klienci[i].pesel) {
                            klienci[i].wypozyczenie();
                        }
                    }
                    break;
                }

                case '6': {
                    string pesel;
                    
                    cout << "Podaj PESEL klienta: ";
                    cin >> pesel;

                    for (int i = 0; i < ile_klientow; i++) {
                        if (pesel == klienci[i].pesel) {
                            klienci[i].oddanie();
                        }
                    }
                    break;
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

