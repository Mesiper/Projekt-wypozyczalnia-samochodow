﻿#include <iostream>
#include <vector>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "Klienci.h"
#include "Samochody.h"
#include "samochody_dostawcze.h"
#include "samochody_osobowe.h"
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::ofstream raport;

void wyczysc_plik(string nazwa_pliku) {
    std::fstream plik;
    plik.open(nazwa_pliku, std::ios::out);
    plik.close();
}

std::string pobierzSformatowanyCzas() {
    // Pobranie aktualnego czasu
    auto teraz = std::chrono::system_clock::now();

    // Konwersja czasu na std::time_t
    auto czas_strukt = std::chrono::system_clock::to_time_t(teraz);

    // Bezpieczne użycie funkcji localtime_s
    std::tm czas_tm;
    localtime_s(&czas_tm, &czas_strukt);

    // Formatowanie daty i godziny
    char czas_sformatowany[20];
    std::strftime(czas_sformatowany, sizeof(czas_sformatowany), "%F %T", &czas_tm);

    return czas_sformatowany;
}
int main()
{

    raport.open("raport.txt", std::ios::app);
    string sformatowanyCzas = pobierzSformatowanyCzas();
    std::vector <samochody_osobowe> auta; // kontener (wektor) na samochody
    samochody_osobowe obiekt_pom_auta;

    /* zlicza ilosc aut w pliku tekstowym, zeby latwo w petli for wczytac
    * i wiedziec ktory to jest element do dodania do kontenera */
    int ile_aut = obiekt_pom_auta.ile_aut_w_pliku();
    //cout << ile_aut << endl;  // sprawdzenie czy dziala

    // wczytywanie samochodow z pliku do wektora
    for (int i = 0; i < ile_aut; i++) {
        obiekt_pom_auta.ktory_samochod = i + 1;
        obiekt_pom_auta.wczytywanie();
        auta.push_back(obiekt_pom_auta);
        //auta[i].wyswietl(); // do sprawdzenia
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
        //klienci[i].wyswietldane();  // do sprawdzenia
    }

    std::vector <samochody_dostawcze> dostawczaki; // kontener (wektor) na samochody
    samochody_dostawcze obiekt_pom_dostawczaki;

    int ile_dostawczakow = obiekt_pom_dostawczaki.ile_aut_w_pliku();

    for (int i = 0; i < ile_dostawczakow; i++) {
        obiekt_pom_dostawczaki.ktory_samochod = i + 1;
        obiekt_pom_dostawczaki.wczytywanie();
        dostawczaki.push_back(obiekt_pom_dostawczaki);
        //dostawczaki[i].wyswietl();  // do sprawdzenia
    }

    char wybor = 1;

    while (wybor != 3) {
        system("cls");  // czysci ekran, zeby na pustym ekranie wypisac menu glowne

        cout << "---- MENU GLOWNE ----" << endl;
        cout << "1. Admin." << endl;
        cout << "2. Klienci." << endl;
        cout << "3. Wyjscie." << endl;
        cout << "Podaj liczbe: ";
        wybor = _getch();

        switch (wybor) {
        // Admin -> MENU SAMOCHODY
        case '1': {
            system("cls");  // czysci ekran, zeby na pustym ekranie wypisac menu samochodow a nie pod menu glownym

            char wybor_samochody;
            cout << "---- MENU SAMOCHODY ----" << endl;
            cout << "1. Samochody osobowe." << endl;
            cout << "2. Samochody dostawcze." << endl;
            cout << "3. Dodaj klienta." << endl;
            cout << "4. Usun klienta." << endl;
            cout << "5. Dane klienta." << endl;
            cout << "6. Wyswietl liczbe klientow." << endl;
            cout << "7. Wstecz." << endl;
            cout << "Podaj liczbe: ";
            wybor_samochody = _getch();

            switch (wybor_samochody) {
            // Samochody osobowe -> MENU SAMOCHODY OSOBOWE
            case '1': {
                system("cls");

                char wybor_sam_osobowe;

                cout << "---- MENU SAMOCHODY OSOBOWE ----" << endl;
                cout << "1. Wyswietl dane samochodu." << endl;
                cout << "2. Dodaj samochod." << endl;
                cout << "3. Usun samochod." << endl;
                cout << "4. Wyswietl liczbe samochodow osobowych." << endl;
                cout << "5. Wstecz." << endl;
                cout << "Podaj liczbe: ";
                wybor_sam_osobowe = _getch();

                switch (wybor_sam_osobowe) {
                // Wyswietl dane samochodu
                case '1': {
                    system("cls");

                    string tablica;

                    cout << "---- WYSWIETLANIE DANYCH SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tablica;

                    bool czy_jest = false;

                    for (int i = 0; i < ile_aut; i++) {
                        if (tablica == auta[i].tablica) {
                            auta[i].wyswietl();
                            cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                            _getch();
                            czy_jest = true;
                            raport << "Wyswietlono dane samochodu osobowego! " << '\t' << "ID: " << tablica << '\t' << sformatowanyCzas << std::endl;
                        }
                    }

                    if (czy_jest == false) {
                        cout << "Brak samochodu w bazie! " << endl << endl;
                        cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                    }
                    break;
                }

                // Dodaj samochod
                case '2': {
                    system("cls");

                    cout << "---- DODAWANIE SAMOCHODU ----" << endl;
                    obiekt_pom_auta.dodawanie();
                    auta.push_back(obiekt_pom_auta);
                    ile_aut++;
                    cout << "Samochod dodany! " << "ID: " << auta[auta.size()-1].tablica << std::endl;
                    cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                    raport << "Admin dodal samochod! " << '\t' << "ID: " << auta[ile_aut-1].tablica <<'\t' << sformatowanyCzas << std::endl;
                    _getch();
                    break;
                }

                // Usun samochod
                case '3': {
                    system("cls");

                    string tablica;

                    cout << "---- USUWANIE SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tablica;
                    for (int i = 0; i < ile_aut; i++) {
                        if (tablica == auta[i].tablica) {
                            auta.erase(auta.begin()+i);
                            ile_aut--;
                            cout << "Pomyslnie usunieto samochod z bazy." << endl << endl;
                            cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                            _getch();
                            raport << "Admin usunal samochod! " << '\t' << "ID: " << tablica << '\t' << sformatowanyCzas << std::endl;
                        }
                    }
                    break;
                }

                // Podaj ilosc samochodow
                case '4': {
                    system("cls");
                    cout << "Ilosc samochodow: " << ile_aut << endl << endl;
                    raport << "Wyswietlono ilosc Samochodow! " << '\t' << sformatowanyCzas << std::endl;
                    cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                    _getch();
                    break;
                }

                // Wstecz
                case '5': {
                    break;
                }
                    default: {
                        system("cls");
                        cout << "Podano niepoprawna wartosc!" << endl << endl;
                        cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                        break;
                }
                }
                break;
            }

            // Samochody dostawcze -> MENU SAMOCHODY DOSTAWCZE
            case '2': {
                system("cls");

                char wybor_sam_dostawcze;

                cout << "---- MENU SAMOCHODY DOSTAWCZE ----" << endl;
                cout << "1. Wyswietl dane samochodu." << endl;
                cout << "2. Dodaj samochod." << endl;
                cout << "3. Usun samochod." << endl;
                cout << "4. Wyswietl liczbe samochodow dostawczych." << endl;
                cout << "5. Wstecz." << endl;
                cout << "Podaj liczbe: ";
                wybor_sam_dostawcze = _getch();

                switch (wybor_sam_dostawcze) {
                // Wyswietl dane samochodu
                case '1': {
                    system("cls");

                    string tab1;

                    bool czy_jest = false;

                    cout << "---- WYSWIETLANIE DANYCH SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tab1;
                    for (int i = 0; i < ile_dostawczakow; i++) {
                        if (tab1 == dostawczaki[i].tablica) {
                            dostawczaki[i].wyswietl();
                            cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                            _getch();
                            czy_jest = true;
                            raport << "Wyswietlono samochod dostawczy! " << '\t' << tab1 << sformatowanyCzas << std::endl;
                        }
                    }

                    if (czy_jest == false) {
                        cout << "Brak samochodu w bazie! " << endl << endl;
                        cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                    }

                    break;
                }

                // Dodaj samochod
                case '2': {
                    system("cls");

                    cout << "---- DODAWANIE SAMOCHODU ----" << endl;
                    obiekt_pom_dostawczaki.dodawanie();
                    dostawczaki.push_back(obiekt_pom_dostawczaki);
                    ile_dostawczakow++;
                    cout << "Samochod dodany! " << "ID: " << dostawczaki[ile_dostawczakow - 1].tablica << std::endl;
                    raport << "Admin dodal samochod dostawczy! " << '\t' << "ID: " << dostawczaki[ile_dostawczakow - 1].tablica << '\t' << sformatowanyCzas << std::endl;
                    cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                    _getch();
                    break;
                }

                // Usun samochod
                case '3': {
                    system("cls");

                    string tablica;

                    cout << "---- USUWANIE SAMOCHODU ----" << endl;
                    cout << "Podaj tablice samochodu: ";
                    cin >> tablica;
                    for (int i = 0; i < ile_dostawczakow; i++) {
                        if (tablica == dostawczaki[i].tablica) {
                            dostawczaki.erase(dostawczaki.begin()+i);
                            ile_dostawczakow--;
                            raport << "Admin usunal samochod dostawczy! " << '\t' << "ID: " << tablica << '\t' << sformatowanyCzas << std::endl;
                            cout << "Pomyslnie usunieto samochod z bazy." << endl << endl;
                            cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                            _getch();
                        }
                    }
                    
                    break;
                }

                // Podaj ilosc samochodow
                case '4': {
                    system("cls");
                    raport << "Wyswietlono ilosc samochodow dostawczych!" << '\t'<< sformatowanyCzas << std::endl;
                    cout << "Ilosc samochodow: " << ile_dostawczakow << endl << endl;
                    cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                    _getch();
                    break;
                }

                // Wstecz
                case '5': {
                    break;
                }
                default: {
                    cout << "Podano niepoprawna wartosc!" << endl << endl;
                    cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                    _getch();
                    break;
                }
                break;
                }
                break;
            }

            // Dodaj klienta
            case '3': {
                system("cls");

                cout << "---- DODAWANIE KLIENTA ----" << endl;

                obiekt_pom_klienci.Dodawanie_klienta();
                klienci.push_back(obiekt_pom_klienci);
                ile_klientow++;
                raport << "Dodano klienta! " << '\t' << "ID: " << klienci[ile_klientow - 1].pesel << '\t' << sformatowanyCzas << std::endl;
                cout << "Pomyslnie dodano klienta do bazy." << endl << endl;
                cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                _getch();
                break;
            }

            // Usun klienta
            case '4': {
                system("cls");

                string pesel;

                cout << "---- USUWANIE KLIENTA ----" << endl;
                cout << "Podaj pesel: ";
                cin >> pesel;
                for (int i = 0; i < ile_klientow; i++) {
                    if (pesel == klienci[i].pesel) {
                        klienci.erase(klienci.begin() + i);
                        ile_klientow--;
                        raport << "Usunieto klienta! " << '\t' << "ID: " << pesel << '\t' << sformatowanyCzas << std::endl;
                        cout << "Pomyslnie usunieto klienta z bazy." << endl << endl;
                        cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                    }
                }
                break;
            }

            // Dane klienta
            case '5': {
                system("cls");

                string pesel;

                cout << "---- WYSWIETLANIE DANYCH KLIENTA ----" << endl;
                cout << "Podaj PESEL klienta: ";
                cin >> pesel;
                
                for (int i = 0; i < ile_klientow; i++) {
                    if (pesel == klienci[i].pesel) {
                        klienci[i].wyswietldane();
                        cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                        raport << "Wyswietlono klienta! " << '\t' << "ID: " << pesel << '\t' << sformatowanyCzas << std::endl;
                    }
                }
                break;

            }

            // Wyswietl liczbe klientow
            case'6': {
                system("cls");
                cout << "Ilosc klientow: " << ile_klientow << endl << endl;
                raport << "Wyswietlono ilosc klientow! " << '\t' << sformatowanyCzas << std::endl;
                cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                _getch();
                break;
            }
            
            // Wstecz
            case '7': {
                break;
            }
            default: {
                cout << "Podano niepoprawna wartosc!" << endl;
                cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                _getch();
                break;
            }
            }
            break;
        }

        // Klienci -> LOGOWANIE -> MENU KLIENCI
        case '2': {
            system("cls");
            string pesel, haslo;
            bool udaneLogowanie = false;
            int proba = 0;

            while (!udaneLogowanie && proba < 3) {
                cout << "---- LOGOWANIE ----" << endl;
                cout << "Podaj PESEL: ";
                cin >> pesel;
                cout << "Podaj haslo: ";
                cin >> haslo;

                if (obiekt_pom_klienci.logowanie(pesel, haslo)) {
                    cout << "Logowanie udane!" << endl;
                    udaneLogowanie = true;

                    system("cls");

                    char wybor_klienci;

                    cout << "---- MENU KLIENCI ----" << endl;
                    
                    cout << "1. Wyswietl wszystkie samochody." << endl;
                    cout << "2. Wypozycz samochod." << endl;
                    cout << "3. Zwroc samochod." << endl;
                    cout << "4. Wstecz." << endl;
                    cout << "Podaj liczbe: ";
                    wybor_klienci = _getch();

                    switch (wybor_klienci) {
                    // Wyswietl wszystkie samochody
                    case '1': {
                        system("cls");

                        for (int i = 0; i < ile_aut; i++) {
                            auta[i].wyswietl();
                        }
                        for (int i = 0; i < ile_dostawczakow; i++) {
                            dostawczaki[i].wyswietl();
                        }
                        raport << "Wyswietlono wszystkie samochody! " << '\t' << sformatowanyCzas << std::endl;
                        cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                        break;
                    }

                    // Wypozycz samochod
                    case '2': {
                        system("cls");

                        for (int i = 0; i < ile_klientow; i++) {
                            if (pesel == klienci[i].pesel) {
                               int nr_klienta = i;
                                if (klienci[i].posiadanysamochod != "BRAK") {
                                    cout << "Oddaj samochod.";
                                }
                                else {
                                    int nr_klienta = i;
                                    string tablica_1;
                                    bool czy_jest1 = false; //czy jest posiadany ustawiamy recznie na nie, dla ulatwienia dzialania

                                    cout << "---- WYPOZYCZANIE ----" << endl;
                                    cout << "Podaj tablice: ";
                                    cin >> tablica_1;

                                    for (int j = 0; j < ile_aut; j++) {
                                        if (tablica_1 == auta[j].tablica) {
                                            if (auta[j].dostepnosc == "NIE") {
                                                cout << "Ten samochod jest juz wypozyczony.";
                                                czy_jest1 = true;
                                                break;
                                            }
                                            else {
                                                klienci[nr_klienta].posiadanysamochod = tablica_1;
                                                czy_jest1 = true;
                                                cout << "Wypozyczono samochod.";
                                                auta[j].dostepnosc = "NIE";
                                                raport << "Wypozyczono samochod! " << '\t' << "ID: " << '\t' << tablica_1 << "Przez: " << klienci[nr_klienta].pesel << sformatowanyCzas << std::endl;

                                            }
                                        }
                                    }

                                    if (czy_jest1 == false) {
                                        for (int j = 0; j < ile_dostawczakow; j++) {
                                            if (tablica_1 == dostawczaki[j].tablica) {
                                                klienci[nr_klienta].posiadanysamochod = tablica_1;
                                                czy_jest1 = true;
                                                cout << "Wypozyczono samochod.";
                                                dostawczaki[j].dostepnosc = "NIE";
                                                raport << "Wypozyczono samochod! " << '\t' << "ID: " << '\t' << tablica_1 << "Przez: " << klienci[nr_klienta].pesel << sformatowanyCzas << std::endl;
                                            }
                                        }
                                    }

                                    if (czy_jest1 == false) {
                                        cout << "Nie ma takiego samochodu w bazie!";
                                    }
                                }
                            }
                        }

                        cout << endl << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();

                        break;
                    }

                    // Zwroc samochod
                    case '3': {
                        system("cls");

                        for (int i = 0; i < ile_klientow; i++) {
                            if (pesel == klienci[i].pesel) {
                                int nr_klienta = i;
                                if (klienci[nr_klienta].posiadanysamochod == "BRAK") {
                                    cout << "Nie masz wypozyczonego samochodu. Zapraszamy do skorzystania z naszej oferty.";
                                }
                                else {
                                    string tablica_1;
                                    bool czy_jest1 = true;

                                    cout << "---- ZWRACANIE ----" << endl;
                                    cout << "Podaj tablice: ";
                                    cin >> tablica_1;

                                    for (int i = 0; i < ile_aut; i++) {
                                        if (tablica_1 == auta[i].tablica) {
                                            if (auta[i].dostepnosc == "NIE") {
                                                cout << "Pomyslnie zwrociles samochod.";
                                                klienci[nr_klienta].posiadanysamochod = "BRAK";
                                                czy_jest1 = false;
                                                auta[i].dostepnosc = "TAK";
                                                raport << "Zwrocono samochod dostawczy! " << '\t' << "ID: " << '\t' << tablica_1 << "Przez: " << klienci[nr_klienta].pesel << sformatowanyCzas << std::endl;
                                                break;
                                            } 
                                        }
                                    }

                                    if (czy_jest1 == false) {
                                        for (int i = 0; i < ile_dostawczakow; i++) {
                                            if (tablica_1 == dostawczaki[i].tablica) {
                                                if (dostawczaki[i].dostepnosc == "NIE") {
                                                    cout << "Pomyslnie zwrociles samochod.";
                                                    czy_jest1 = false;
                                                    dostawczaki[i].dostepnosc = "TAK";
                                                    raport << "Zwrocono samochod dostawczy! " << '\t' << "ID: " << '\t' << tablica_1 << "Przez: " << klienci[nr_klienta].pesel << sformatowanyCzas << std::endl;

                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    if (czy_jest1 == true) {
                                        cout << "Nie ma takiego samochodu w bazie!";
                                    }
                                }
                            }
                        }
                        cout << endl << endl << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                        break;
                    }

                    // Wstecz
                    case '4': {
                        break;
                    }
                    default: {
                        cout << "Podano niepoprawna wartosc!" << endl << endl;
                        cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                        _getch();
                        break;
                    }
                    break;
                    }
                }
                else {
                    cout << "Nieudane logowanie. Sprawdz PESEL i haslo, a nastepnie sprobuj ponownie." << endl;
                    proba++;
                    if (proba < 3) {
                        cout << "Pozostale proby: " << 3 - proba << '\n';
                    }
                }                 

                // Czyszczenie ekranu
                system("cls");
            }
            break;
        }

        // Wyjscie -> Potwierdzenie
        case '3': {
            system("cls");

            char wybor_wyjscie;

            cout << "Czy na pewno chcesz zamknac program?" << endl;
            cout << "1. Tak." << endl;
            cout << "2. Nie." << endl;
            cout << "Podaj liczbe: ";
            wybor_wyjscie = _getch();

            switch (wybor_wyjscie) {
            case '1': {
                wybor = 3;
                break;
            }
            case '2': {
                wybor = 1;
                break;
            }
            default: {
                cout << "Podano niepoprawny numer!" << endl << endl;
                cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                _getch();
                wybor = 1;
                break;
            }
            }
            break;
        }
        default: {
                cout << "Podano niepoprawny numer!" << endl << endl;
                cout << "Nacisnij dowolny klawisz, aby kontynuowac.";
                _getch();
                break;
        }
        }
    }
    
    // zapis samochodow do pliku
    // czysci plik, do ktorego beda zapisywane dane
    wyczysc_plik("samochody_osobowe.txt");

    // zapisuje auta do uprzednio wyczyszczonego (pustego) pliku
    for (int i = 0; i < ile_aut; i++) {
        auta[i].zapis_do_pliku();
    }

    // zapis klientow do pliku
    // czysci plik, do ktorego beda zapisywane dane
    wyczysc_plik("klienci.txt");

    // zapisuje klientow do uprzednio wyczyszczonego (pustego) pliku
    for (int i = 0; i < ile_klientow; i++) {
        klienci[i].zapis_do_pliku();
    }

    // zapis samochodow do pliku
// czysci plik, do ktorego beda zapisywane dane
    wyczysc_plik("samochodydostawcze.txt");

    // zapisuje auta do uprzednio wyczyszczonego (pustego) pliku
    for (int i = 0; i < ile_dostawczakow; i++) {
        dostawczaki[i].zapis_do_pliku();
    }
    
    return 0;
}
 