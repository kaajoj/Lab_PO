#include <iostream>
#include <cmath>                                                   // pow
#include <vector>                                                  // kontenery
#include <stdlib.h>

using namespace std;

class Kalkulator{
    public:
    string wyrazenie;                                               // przechowuje ciag liczb i symboli podanych przez uzytkownika

	vector <char> symbole;                                          // tablica przechowujaca symbole arytmeczyczne
	vector <double> liczby;                                         // tablica przechowujaca liczby

    void menu(){
        liczby.clear();                                             // wyczyszczenie
        symbole.clear();
        system("cls");
        cout << "KALKULATOR NAUKOWY" << endl << endl;
        cout << "Podaj ciag liczb i symboli (+,-,*,/,^,%)"<< endl;
        cout << "Aby zamknac wpisze  - e" << endl;
    }

    void przygotowanie(){
        int dlugosc=wyrazenie.length();                              // pobranie dlugosci wyrazenia
        int i=0;
        string pom;                                                  // pomocniczny string
        for (i=0;i<dlugosc;i++) {
            if (isdigit(wyrazenie[i]) || wyrazenie[i]=='.') {        // sprawdzenie czy wprowadzono cyfre lub kropke
                pom+=wyrazenie[i];
        // cout << pom << endl;                                   // TEST
            } else {
                liczby.push_back(atof(pom.c_str()));                // odlozenie liczby
                pom="";                                             // wyzerowanie
                symbole.push_back(wyrazenie[i]);                    // pobranie symbolu
            }
            if (i==(dlugosc-1)) {
                liczby.push_back(atof(pom.c_str()));                // odlozenie liczby
            }
        }
    }


    void obliczenia(){
        int j=0 ;                                                       // zmienna pomocniczna do przechodzenia po tablicach
        int ile_sym=symbole.size();                                     // liczba symboli
//      cout << ile_sym << endl;                                        // TEST
            while (j<ile_sym) {
                    if (symbole[j]=='^') {
                        liczby[j]=pow(liczby[j],liczby[j+1]);           // potegowanie
                        liczby.erase(liczby.begin()+j+1);               // usuniecie otatniego elementu, juz wykorzystanego w obliczeniach
                        symbole.erase(symbole.begin()+j);               // usuniecie wykorzystanego znaku
                        j--;                                            // pomniejzenie o 1 ilosci liczb wykorzystaych w obliczeniach, z 2 powstaje 1
                        ile_sym--;                                      // zmniejszenie o 1 liczby wykorzystaych symboli
                    } j++;                                              // inkrementacja w celu pozukiwania powtorzenia symbolu
                }j=0;                                                   // wyzerowanie zmiennej, aby wyszykwiac od pcozatku tablicy liczb i symboli

            while (j<ile_sym) {
                    if (symbole[j]=='*') {
                        liczby[j]*=liczby[j+1];                         // mnozenie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } else if (symbole[j]=='/') {
                        liczby[j]/=liczby[j+1];                         // dzielenie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } j++;
                } j=0;

            while (j<ile_sym) {
                    if (symbole[j]=='+') {
                        liczby[j]+=liczby[j+1];                         // dodawanie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } else if (symbole[j]=='-') {
                        liczby[j]-=liczby[j+1];                         // odejmowanie
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } j++;
                }   j=0;

            while (j<ile_sym) {
                    if (symbole[j]=='%') {
                        int lb1=liczby[j];
                        int lb2=liczby[j+1];
                        int wyn=lb1%lb2;                              // modulo
                        liczby[j]=wyn;
                        liczby.erase(liczby.begin()+j+1), symbole.erase(symbole.begin()+j);
                        j--, ile_sym--;
                    } j++;
                }
    }
};


int main() {
   Kalkulator kal;
   double wynik=0;

   kal.menu();
   cout << endl << "Wynik: 0" << endl << endl;
   cin >> kal.wyrazenie;

	while(kal.wyrazenie!="e"){
        kal.menu();
        kal.przygotowanie();
        kal.obliczenia();
        cout << endl << "Wynik: " << kal.liczby[0] << endl << endl;
        cin >> kal.wyrazenie;
        }

    return 0;
}
