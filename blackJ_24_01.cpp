// Karol Nowak
// I6X1N1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int wybor=0;
char wybor2='0';	 // wybor czy grac ponownie
char wybor3='0';	 // wybor do dobierania
int j=0;			// licznik dla gracza
int k=0;  			// licznik dla krupiera


class Gracz {
    public:
	string nazwa;
	int punkty;
	string posiadane_karty[10];
	int temp2; 						// zmiena do obslugi losowosci dobierania krupiera

	void wyswietl_pkt(){
	cout << "Suma punktow: " << punkty << endl << endl;
	}

	void wyswietl_karty(int j){
    cout << "Karty: ";
    for(int k=0;k<j;k++) {
        cout << posiadane_karty[k] << " ";
	}
	cout << endl;
	}

	int losowe_dobieranie(){
	temp2 = rand()%5;
	cout << temp2 << endl;
	}
};


class Karty {
    public:
    int temp;
    string wartosc[104]={"1W2","1W3","1W4","1W5","1W6","1W7","1W8","1W9","1W10","1WJ","1WD","1WK","1WA","1Z2","1Z3","1Z4","1Z5","1Z6","1Z7","1Z8","1Z9","1Z10","1ZJ","1ZD","1ZK","1ZA","1D2","1D3","1D4","1D5","1D6","1D7","1D8","1D9","1D10","1DJ","1DD","1DK","1DA","1C2","1C3","1C4","1C5","1C6","1C7","1C8","1C9","1C10","1CJ","1CD","1CK","1CA","2W2","2W3","2W4","2W5","2W6","2W7","2W8","2W9","2W20","2WJ","2WD","2WK","2WA","2Z2","2Z3","2Z4","2Z5","2Z6","2Z7","2Z8","2Z9","2Z20","2ZJ","2ZD","2ZK","2ZA","2D2","2D3","2D4","2D5","2D6","2D7","2D8","2D9","2D20","2DJ","2DD","2DK","2DA","2C2","2C3","2C4","2C5","2C6","2C7","2C8","2C9","2C20","2CJ","2CD","2CK","2CA"};
	int wartosc_karty[104]={2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
	string karta;

	int ktora_karta;

	void rozdanie(){
	temp = rand()%104+2;
	karta = wartosc[temp];
	ktora_karta = wartosc_karty[temp];
	wartosc_karty[temp]=0;
	temp=0;
	}
};

class Gra {
	public:

	int sprawdzenie(int a, int b){			// DODAC ZE JAK KRUPIER MA PONAD 21 TO WYGRYWAM
		if(a==b){
		cout << "Remis" << endl << endl;
		cout << "Jeszcze raz? (y/n)"<< endl;			// JESZCZE RAZ ROZBIC NA ODDZIELNA FUNKCJE2
		cin >> wybor2;
		} else if((a>b || b>21) && a<=21) {				// wygrana jak krupier ma wiecej niz 21 b>21
		  cout << "Wygrales" << endl;
		  if (a==21) cout << "Blackjack!" << endl << endl;
		  cout << "Jeszcze raz? (y/n)"<< endl;
		  cin >> wybor2;
		} else if(a>21 || a<b)  {
			cout << "Przegrales!"<< endl << endl;
			cout << "Jeszcze raz? (y/n)"<< endl;
			cin >> wybor2;
		}
	}

	//int przegrana(){
	//cout << "Przegrales!"<< endl;
	//cout << "Jeszcze raz? (y/n)"<< endl;			// JESZCZE RAZ ROZBIC NA ODDZIELNA FUNKCJE2
	//cin >> wybor2;
	//}

};


void menu(){
	cout << "-------------";
	cout << "  BLACKJACK  ";
	cout << "-------------" << endl;
    cout << "   1 - dobranie karty" << endl;
    cout << "   2 - sprawdzenie wyniku" << endl;
	cout << "   3 - wylaczenie programu" << endl;
    cout << "---------------------------------------" << endl << endl;
}



int main(){
	srand(time(NULL));

	Gra gra;

	Gracz gracz;
	Gracz krupier;
	krupier.punkty=0;
	gracz.punkty=0;

	Karty talia1;
	// Karty talia2;
	talia1.temp=0;

	menu();

	cout << "Losowanie kart";
     //   _sleep(1000);

	cout << endl << endl << "GRACZ" << endl;
	talia1.rozdanie();
	while (talia1.ktora_karta==0)  talia1.rozdanie();
    cout << "Karta 1: " << talia1.karta << endl;
	gracz.posiadane_karty[j]=talia1.karta;
	j++;
	// cout << talia1.temp << endl;										// nr karty w tab string_warosc
	// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
    gracz.punkty+=talia1.ktora_karta;
	talia1.rozdanie();
	while (talia1.ktora_karta==0)  talia1.rozdanie();
	cout << "Karta 2: " << talia1.karta << endl;
	gracz.posiadane_karty[j]=talia1.karta;
	j++;
	// cout << talia1.temp << endl;										// nr karty w tab string_warosc
	// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
    gracz.punkty+=talia1.ktora_karta;
	gracz.wyswietl_pkt();


    cout << "KRUPIER" << endl;
    talia1.rozdanie();
    while (talia1.ktora_karta==0)  talia1.rozdanie();
    cout << "Karta 1: " << talia1.karta << endl;
	krupier.posiadane_karty[k]=talia1.karta;
	k++;
    krupier.punkty+=talia1.ktora_karta;
    talia1.rozdanie();
    while (talia1.ktora_karta==0)  talia1.rozdanie();
    krupier.punkty+=talia1.ktora_karta;
	krupier.posiadane_karty[k]=talia1.karta;
	k++;
    //cout << talia1.karta << endl; // test
	cout<< "TEST: ";
    krupier.wyswietl_pkt(); // TEST - USUNAC TO

		for(;;){

			if (gracz.punkty > 21) {

				//gra.sprawdzenie(gracz.punkty, krupier.punkty);			// TUTATJ PRZEJECHAC PETLA PRZEZ posiadane karty i wyzerowac?
				gracz.punkty=0;
				krupier.punkty=0;
				talia1.temp=0;
				j=0;
				k=0;
				if (wybor2=='n' || wybor2=='N'){
					return(0);
				} else if (wybor2=='y' || wybor2=='Y') {
					system("cls");

							menu();

							cout << "Losowanie kart";
							 //   _sleep(1000);

							cout << endl << endl << "GRACZ" << endl;
							talia1.rozdanie();
							while (talia1.ktora_karta==0)  talia1.rozdanie();
							cout << "Karta 1: " << talia1.karta << endl;
							gracz.posiadane_karty[j]=talia1.karta;
							j++;
							// cout << talia1.temp << endl;										// nr karty w tab string_warosc
							// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
							gracz.punkty+=talia1.ktora_karta;
							talia1.rozdanie();
							while (talia1.ktora_karta==0)  talia1.rozdanie();
							cout << "Karta 2: " << talia1.karta << endl;
							gracz.posiadane_karty[j]=talia1.karta;
							j++;
							// cout << talia1.temp << endl;										// nr karty w tab string_warosc
							// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
							gracz.punkty+=talia1.ktora_karta;
							gracz.wyswietl_pkt();


							cout << "KRUPIER" << endl;
							talia1.rozdanie();
							while (talia1.ktora_karta==0)  talia1.rozdanie();
							cout << "Karta 1: " << talia1.karta << endl;
							krupier.posiadane_karty[k]=talia1.karta;
							k++;
							krupier.punkty+=talia1.ktora_karta;
							talia1.rozdanie();
							while (talia1.ktora_karta==0)  talia1.rozdanie();
							krupier.punkty+=talia1.ktora_karta;
							krupier.posiadane_karty[k]=talia1.karta;
							k++;
							//cout << talia1.karta << endl; // test
							cout << "TEST: ";
							krupier.wyswietl_pkt();

				}
			} else {
                cin >> wybor;

				if (wybor==1) {
					talia1.temp=0;
					talia1.rozdanie();
					while (talia1.ktora_karta==0)  talia1.rozdanie();
					gracz.punkty+=talia1.ktora_karta;
					gracz.posiadane_karty[j]=talia1.karta;
					j++;
					system("cls");
					menu();
					cout << "Dobranie karty dla gracza" << endl;
					cout << talia1.karta << endl;
					//gracz.posiadane_karty[j]=talia1.karta;
					//j++;
					cout << endl << "GRACZ" << endl;
					gracz.wyswietl_karty(j);
					gracz.wyswietl_pkt();
					cout << "KRUPIER" << endl;
					krupier.posiadane_karty[0];
					krupier.wyswietl_pkt();

					if(gracz.punkty<21){
						cout << "Dobrac kolejna karte? (y/n)" << endl;
						cin >> wybor3;
							while(wybor3!='n' || wybor3!='N'){
								if(wybor3=='y' || wybor3=='Y') {
									talia1.temp=0;
									talia1.rozdanie();
									while (talia1.ktora_karta==0)  talia1.rozdanie();
									gracz.punkty+=talia1.ktora_karta;
									gracz.posiadane_karty[j]=talia1.karta;
									j++;
									system("cls");
									menu();
									cout << "Dobranie karty dla gracza" << endl;
									cout << talia1.karta << endl;
									cout << endl << "GRACZ" << endl;
									gracz.wyswietl_karty(j);
									gracz.wyswietl_pkt();
									cout << "KRUPIER" << endl;
									krupier.posiadane_karty[0];
									krupier.wyswietl_pkt();
									cout << "Dobrac kolejna karte? (y/n)" << endl << endl;          // TUTAJ POWINNIEN BYC ALGORYTM DOBIERANI PRZEZ KRUPIERA, TO SAMO CO NA DOLE JAK WCISNIE SIE 2
									cin >> wybor3;
								}
							if(wybor3!='n' || wybor3!='N') {
										
							if(krupier.punkty<20){
							krupier.losowe_dobieranie();
								if(krupier.temp2==1 || krupier.temp2==3) {
								cout << "Krupier dobiera karte" << endl;
									talia1.rozdanie();
									while (talia1.ktora_karta==0)  talia1.rozdanie();
									krupier.punkty+=talia1.ktora_karta;
									krupier.posiadane_karty[k]=talia1.karta;
									k++;
									krupier.wyswietl_karty(k);
									krupier.wyswietl_pkt();
								} else cout << "Krupier nie dobiera karty" << endl;
							}
							gra.sprawdzenie(gracz.punkty, krupier.punkty);
												
								
								break;
							}

						}
					}

					gra.sprawdzenie(gracz.punkty, krupier.punkty);

					if(wybor2=='y' || wybor2=='Y') {
						gracz.punkty=22;
					}
					if(wybor2=='n' || wybor2=='N') {
						cout<<"Wylaczenie programu"<<endl;
						return(0);
					}

                } else if (wybor==2) {
                    system("cls");
                    menu();
					cout << "Gracz nie dobiera karty, sprawdzenie wyniku" << endl;
					cout << endl << "GRACZ" << endl;
					gracz.wyswietl_karty(j);
					gracz.wyswietl_pkt();
					cout << "KRUPIER" << endl;
					krupier.wyswietl_karty(k);
					cout << "TEST: ";
					krupier.wyswietl_pkt();


					// DOROBIC TUTAL ELMENT LOSOY, CZY KRUPIER DOPIERA CZY NIE, A JAK DOPIERA TO DO <=21 SUMY PKT
                    if(krupier.punkty<20){
					krupier.losowe_dobieranie();
						if(krupier.temp2==1 || krupier.temp2==3) {
						cout << "Krupier dobiera karte" << endl;
							talia1.rozdanie();
							while (talia1.ktora_karta==0)  talia1.rozdanie();
							krupier.punkty+=talia1.ktora_karta;
							krupier.posiadane_karty[k]=talia1.karta;
							k++;
							krupier.wyswietl_karty(k);
							krupier.wyswietl_pkt();
						} else cout << "Krupier nie dobiera karty" << endl;
					}
					gra.sprawdzenie(gracz.punkty, krupier.punkty);
												// tuatj jak ktos da y to aby grac dalej
					if(wybor2=='y' || wybor2=='Y') {
						gracz.punkty=22;
					}
					if(wybor2=='n' || wybor2=='N') {
						cout<<"Wylaczenie programu"<<endl;
						return(0);
					}
                } else if (wybor==3) {
					cout<<"Wylaczenie programu"<<endl;
					return(0);
                } else {
					cout << "Wprowadz poprawna cyfre z MENU" << endl;
					cin >> wybor;

                }
			}

		   }


system("pause");
}
