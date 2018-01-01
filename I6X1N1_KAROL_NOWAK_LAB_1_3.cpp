// Karol Nowak
// I6X1N1

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <math.h>


using namespace std;

class Kalkulator{
    public:
	double wynik;
	double wynik2;
	char znak;

	void dodawanie(){
		double b;
		cin>>b;
		wynik=wynik+b;
		menu();
    }

    void odejmowanie(){
        double b;
        cin>>b;
        wynik=wynik-b;
        menu();
    }

    void mnozenie(){
        double b;
        cin>>b;
        wynik=wynik*b;
        menu();
    }

    void dzielenie(){
        double b;
        cin>>b;
        if (b!=0) {
            wynik=wynik/b;
            menu();
        }
        else {
            cout<< "Nie mozna dzielic przez 0"<<endl;
        }
    }

    void pierwiastkowanie(){
        wynik=sqrt(wynik);
        menu();
    }

    void procenty(){
        char znak2;
		double b;
        cin>>b;

        wynik2=(b/100)*wynik;

		cout<<"Wpisz + aby dodac "<<b<<"%"<<endl;
		cout<<"Wpisz - aby odjac "<<b<<"%"<<endl;
		cout<<"Wpisz * aby pomnozyc przez "<<b<<"%"<<endl;
		cout<<"Wpisz / aby podzielic przez "<<b<<"%"<<endl;

		cin>>znak2;

		switch(znak2){
            case '+': {
                wynik=wynik+wynik2;
                break;
            }
            case '-': {
                wynik=wynik-wynik2;
                break;
            }
            case '*': {
                wynik=wynik*wynik2;
                break;
            }
            case '/': {
                wynik=wynik/wynik2;
              break;
            }
		}
		menu();
    }

    void menu(){
    system("cls");
    cout<<"KALKULATOR +,-,*,/,%"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"MENU"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"Zapisanie do pamieci:         m"<<endl;
	cout<<"Wyczyszczenie pamieci:        c"<<endl;
	cout<<"Wyswietlenie pamiec:          p"<<endl;
	cout<<"Wyczyscic wyniku:             w"<<endl;
	cout<<"Pierwiastkowanie:             s"<<endl;
	cout<<"Wyjscie z programu:           q"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"Wynik: "<<wynik<<endl;
	cout<<"-------------------------"<<endl;
    }
};

int main(){
    Kalkulator kal;
	double pamiec = 0;
	kal.wynik=0;
	kal.wynik2=0;
    kal.menu();

    cin>>kal.wynik;
    kal.menu();
    cin >> kal.znak;

	for(;;){
        switch(kal.znak){
            case '+': {
                kal.dodawanie();
                break;
            }
            case '-': {
                kal.odejmowanie();
                break;
            }
            case '*': {
                kal.mnozenie();
                break;
            }
            case '/': {
                kal.dzielenie();
                break;
            }
            case 's': {
                kal.pierwiastkowanie();
              break;
            }
            case '%': {
                kal.procenty();
                break;
            }
           case 'c': {
               pamiec = 0;
               cout<<"Reset pamieci"<<endl;
               break;
            }
            case 'w': {
               kal.wynik = 0;
               kal.menu();
               break;
            }
            case 'q': {
                cout<<"Wylaczenie programu"<<endl;
                return(0);
            }
            case 'm': {
                pamiec = kal.wynik;
                cout<<"Zapisano do pamieci"<<endl;
                break;
            }
            case 'p': {
                kal.wynik=pamiec;
                kal.menu();
                cout<<"Liczba w pamieci to: "<<pamiec<<endl;
                cout<<"Przekazano pamiec do wyniku"<<endl;
                break;
            }
            default: {
                cin.sync();
                kal.menu();
                cout<<"Podana liczba nadpisze wynik: ";
                cin>>kal.wynik;
                kal.menu();
            }

        }
    cin >> kal.znak;
    }
system("pause");
}
