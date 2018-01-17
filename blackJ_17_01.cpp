// Karol Nowak
// I6X1N1

#include <iostream>
#include <cstdlib>
#include <ctime>

// ZROOBIC ZEBY KARTY NIE DUBLOWALY SIE, PRZYPISYWAC ZERA I DRUGA TALIE DOLOZYC


using namespace std;

int wybor=0;
char wybor2='0'; // wybor czy grac ponownie
char wybor3='0'; // wybor do dobierania
int j=0;	// licznik dla gracza
int k=0;  // licznik dla krupiera

class Gracz {
    public:
	string nazwa;
	int punkty;
	int k=0;
	string posiadane_karty[10];

	void wyswietl_pkt(){
	cout << "Suma punktow: " << punkty << endl << endl;
	}

	void wyswietl_karty(int j){
    cout << "Karty: ";
    for(k=0;k<j;k++) {
        cout << posiadane_karty[k] << " ";
	}
	cout << endl;
	}
};


class Karty {
    public:
    int temp;
    string wartosc[52]={"W2","W3","W4","W5","W6","W7","W8","W9","W10","WJ","WD","WK","WA","Z2","Z3","Z4","Z5","Z6","Z7","Z8","Z9","Z10","ZJ","ZD","ZK","ZA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DD","DK","DA","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CD","CK","CA"};
	int wartosc_karty[52] = {2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11,2,3,4,5,6,7,8,9,10,10,10,10,11};
	string karta;


	int ktora_karta;

	void rozdanie(){
	temp = rand()%52+2;
	karta = wartosc[temp];
	ktora_karta = wartosc_karty[temp];
	//wartosc_karty[temp]=0;	i dodac ifa w main ze jak ktora_karta = 0 to jeszcze raz rozdanie
	temp=0;
	}
};

class Gra {
	public:
	
	int sprawdzenie(int a, int b){			// DODAC ZE JAK KRUPIER MA PONAD 21 TO WYGRYWAM
		if(a==b){
		cout << "Remis" << endl;
		cout << "Jeszcze raz? (y/n)"<< endl;			// JESZCZE RAZ ROZBIC NA ODDZIELNA FUNKCJE2
		cin >> wybor2;
		} else if((a>b || b>21) && a<=21) {				// wygrana jak krupier ma wiecej niz 21 b>21
		  cout << "Wygrałeś" << endl;					// DODAC FUNKCJE JESZCZE RAZ
		  if (a==21) cout << "Blackjack!" << endl;	
		  cout << "Jeszcze raz? (y/n)"<< endl;			// JESZCZE RAZ ROZBIC NA ODDZIELNA FUNKCJE2
		  cin >> wybor2;								// DODAC FUNKCJE JESZCZE RAZ
		} else if(a>21 || a<b)  {
			cout << "Przegrales!"<< endl;
			cout << "Jeszcze raz? (y/n)"<< endl;			// JESZCZE RAZ ROZBIC NA ODDZIELNA FUNKCJE2
			cin >> wybor2;
		}															// DODAC FUNKCJE JESZCZE RAZ3
	
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
	cout << "Karta 1: " << talia1.karta << endl;
	gracz.posiadane_karty[j]=talia1.karta;
	j++;
	// cout << talia1.temp << endl;										// nr karty w tab string_warosc
	// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
    gracz.punkty+=talia1.ktora_karta;
	talia1.rozdanie();
	cout << "Karta 2: " << talia1.karta << endl;
	gracz.posiadane_karty[j]=talia1.karta;
	j++;
	// cout << talia1.temp << endl;										// nr karty w tab string_warosc
	// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
    gracz.punkty+=talia1.ktora_karta;
	gracz.wyswietl_pkt();


    cout << "KRUPIER" << endl;
    talia1.rozdanie();
    cout << "Karta 1: " << talia1.karta << endl;
	krupier.posiadane_karty[k]=talia1.karta;
	k++;
    krupier.punkty+=talia1.ktora_karta;
    talia1.rozdanie();
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
							cout << "Karta 1: " << talia1.karta << endl;
							gracz.posiadane_karty[j]=talia1.karta;
							j++;
							// cout << talia1.temp << endl;										// nr karty w tab string_warosc
							// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
							gracz.punkty+=talia1.ktora_karta;
							talia1.rozdanie();
							cout << "Karta 2: " << talia1.karta << endl;
							gracz.posiadane_karty[j]=talia1.karta;
							j++;
							// cout << talia1.temp << endl;										// nr karty w tab string_warosc
							// cout << "Punkty za karte: " << talia1.ktora_karta << endl;
							gracz.punkty+=talia1.ktora_karta;
							gracz.wyswietl_pkt();


							cout << "KRUPIER" << endl;
							talia1.rozdanie();
							cout << "Karta 1: " << talia1.karta << endl;
							krupier.posiadane_karty[k]=talia1.karta;
							k++;
							krupier.punkty+=talia1.ktora_karta;
							talia1.rozdanie();
							krupier.punkty+=talia1.ktora_karta;
							krupier.posiadane_karty[k]=talia1.karta;
							k++;
							//cout << talia1.karta << endl; // test
							krupier.wyswietl_pkt();
					
				}
			} else {
				cin >> wybor;
	
				if (wybor==1) {
					talia1.temp=0;
					talia1.rozdanie();
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
									cout << "Dobrac kolejna karte? (y/n)" << endl;
									cin >> wybor3;
								}
							if(wybor3!='n' || wybor3!='N') {
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
					cout << "Gracz nie dobiera karty, sprawdzenie wyniku" << endl;
					cout << endl << "GRACZ" << endl;
					gracz.wyswietl_karty(j);
					gracz.wyswietl_pkt();
					cout << "KRUPIER" << endl;						
					krupier.wyswietl_karty(k);
					krupier.wyswietl_pkt();
					
					// DOROBIC TUTAL ELMENT LOSOY, CZY KRUPIER DOPIERA CZY NIE, A JAK DOPIERA TO DO <=21 SUMY PKT
					
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


// system("pause");
}
