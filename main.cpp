#include <iostream>
#include <vector>
#include <algorithm>
#include "Gyventojai.h"
#include "Skaiciai.h"
#include "Meniu.h"

using namespace std;
int TiesinePaieska( const vector<int>&sarasas, int raktinisZodis);
vector<int>TiesinePaieskaVisi(const vector<int>&sarasas,int raktinisZodis);
int DvejetainePaieska(vector<int>&sarasas, int kaire, int desine, int raktinisZodis);
vector<int> GyventojoPaieskaPagalAmziu (const
                                        vector<Gyventojai>&sarasas, int amzius);
vector<int>GyventojoPaieskaPagalVarda (const
                                       vector<Gyventojai>&sarasas, string vardas);
vector<int> GyventojoPaieskaPagalMiesta(const vector<Gyventojai>&sarasas, string miestas);
vector<int> GynetojoPaieskaPagalPajamas (const vector<Gyventojai>&sarasas, double pajamos);

void Meniu();
void MeniuSkaiciai ();
void MeniuGyventojai();
void TiesinePaieskaVisi();
void TeisinePaieska();
void DvejetainePaieska();


int main() {
    vector<Gyventojai> gyventojai{
            Gyventojai(31, "Tomas","Saltenis", 1650.45, "Vilnius"),
            Gyventojai(38, "Viktorija","Markelyte", 2150.75, "Siauliai"),
            Gyventojai(25, "Gitanas","Pakarklis", 1575.65,"Kaunas"),
            Gyventojai(32, "Simona","Naujokaite", 1850.25, "Klaipeda"),
            Gyventojai(29, "Vilija","Kasperaviciute", 1350.95, "Siauliai"),
            Gyventojai(32, "Tomas","Penkas", 1779.46, "Kaunas"),
            Gyventojai(22, "Monika","Kaseva", 2479.77, "Siauliai"),
            Gyventojai(45, "Rita","Bringa", 2399.64, "Kaunas"),
            Gyventojai(25, "Toma","Kauryte", 2679.46, "Vilnius"),
            Gyventojai(31, "Tautvydas","Vidurskis", 2879.33, "Klaipeda"),
    };
int stop=1;
while (stop!=0){
        Meniu();

        cin>> stop;

    switch (stop) {
        case 1: {
            int stop = 1;

            while (stop != 0) {
                MeniuSkaiciai();
                cin >> stop;
                switch (stop) {
                    case 1: {
                        TeisinePaieska();
                        break;
                    }
                    case 2: {
                        TiesinePaieskaVisi();
                        break;
                    }
                    case 3: {
                        DvejetainePaieska();
                        break;
                    }
                    default:
                break;
            }
        }
            break;
        }
            case 2: {
                int amzius;
                cout << "Iveskite kokio amziaus Gyventojas jus domina:";

                cin >> amzius;

                vector<int> visiResultatai = GyventojoPaieskaPagalAmziu(gyventojai, amzius);
                if (!visiResultatai.empty()) {
                    cout << "---------------------------------------------" << endl;
                    cout << "Gyventoju sarasas, kuriu amzius " << amzius << endl;
                    int nr= 1;
                    for (int it: visiResultatai) {
                        cout << nr << ". " << gyventojai[it].getVardas() << ". Gyeventojo miestas: "
                             << gyventojai[it].getMiestas()<<endl;
                        ++nr;
                    }
                    cout << "---------------------------------------------" << endl;
                    cout << " " << endl;

                        }
                else {
                    cout << amzius << " amziaus gyvenoju nera." << endl;
                    cout << "---------------------------------------------" << endl;
                    cout << " " << endl;

                }
                break;
                    }
        case 3: {
            int stop = 1;
            while (stop != 0) {
                MeniuGyventojai();
                cin >> stop;
                switch (stop) {
                    case 1: {
                        basic_string<char> miestas;
                        cout << "Iveskite miesta kurio gyventojai domina:";
                        cin >> miestas;
                        vector<int> visiResultatai = GyventojoPaieskaPagalMiesta(gyventojai, miestas);
                        if (!visiResultatai.empty()) {
                            cout << "---------------------------------------------" << endl;
                            cout << "Gyentoju sarasas, kurie is " << miestas << " miesto:" << endl;
                            cout << "  " << endl;
                            int nr = 1;
                            for (int it: visiResultatai) {
                                cout << nr << ". " << gyventojai[it].getVardas() << ". Gyventojo miestas:  "
                                     << gyventojai[it].getMiestas() << ". Gyevnotjo kodas:" << it << "." << endl;
                                ++nr;
                            }

                        } else {
                            cout << "---------------------------------------------" << endl;
                            cout << miestas << " mieste gyevntoju nera." << endl;
                            cout << " " << endl;
                        }
                        break;
                    }
                    case 2: {
                        string vardas;
                        cout << "Iveskite gyventojo varda : ";

                        cin >> vardas;

                        vector<int> visiResultatai = GyventojoPaieskaPagalVarda(gyventojai, vardas);
                        if (!visiResultatai.empty()) {
                            cout << "---------------------------------------------" << endl;
                            cout << "Gyventoju sarasas, kuriu vardas " << vardas << " :" << endl;
                            cout << " " << endl;
                            int nr = 1;
                            for (int it: visiResultatai) {
                                cout << nr << ". " << gyventojai[it].getVardas() << ". Gyventojo miestas: "
                                     << gyventojai[it].getMiestas() <<"  Jo pajamos " <<gyventojai[it].getPajamos()<<". Gyventojo kodas:" << it << "." << endl;
                                ++nr;
                            }
                            cout << "---------------------------------------------" << endl;
                            cout << " " << endl;
                        } else {
                            cout << "---------------------------------------------" << endl;
                            cout << vardas << " vardu gyventoju nera." << endl;
                            cout << " " << endl;
                            break;
                        }
                    }


                }
            }
            break;
        }
        default:
            cout << "Tokios funkcijos nera." << endl;
            cout << "---------------------------------------------" << endl;
            break;

                        }

                }


    return 0;
}
vector<int> skaiciuSeka{11,44, 22, 12, 14, 12, 55, 44, 65,55, 24, 21, 11, 12,15,16,17,66,58,59,60};
void TiesinePaieskaVisi(){
    cout<<"Iveskite skaiciu nuo 10 iki 70: ";
    int raktinisZodis;
    cin>>raktinisZodis;
    vector<int> visiRezultatai=TiesinePaieskaVisi(skaiciuSeka,raktinisZodis);
    if(!visiRezultatai.empty()){
        cout<< "----------------------------------------------------" <<endl;
        cout<<"Jus ivedete skaiciu "<<raktinisZodis<<endl;
        for (int it:visiRezultatai) {
            cout<<"skaicius ("<<skaiciuSeka[it] <<") sekoje yra. Jo pozicija masyve:"<<it<<endl;

        } }
    else {
            cout << "Jusu ivestas skaicius " << raktinisZodis << " nera sekoje." << endl;
        }
    }

void DvejetainePaieska() {
    cout<<"Iveskite skaiciu nuo 10 iki 70: ";
    int raktinisZodis;
    cin>>raktinisZodis;
    int indeksas =DvejetainePaieska(skaiciuSeka,0,skaiciuSeka.size()-1, raktinisZodis);
    if (indeksas!=-1) {
        cout<<endl;
        cout << "Jusu ivestas skaicius " << raktinisZodis << " (" << skaiciuSeka[indeksas]<<") Yra. Jo pozicija mayve yra "<<indeksas<<"."<<endl;
        cout << " " << endl;
    }
    else {
        cout << endl;
        cout << "Jusu ivestas skaiciaus " << raktinisZodis << " sekoje neegzistuoja." << endl;
        cout << endl;
        cout << "---------------------------------------------" << endl;
        cout << " " << endl;
    }

}
void TeisinePaieska(){
    cout << "Iveskite skaiciu nuo 10 iki 70:  ";
    int raktinisZodis;
    cin >> raktinisZodis;

    int indeksas = TiesinePaieska(skaiciuSeka, raktinisZodis);
    if (indeksas != -1) {
        cout << "---------------------------------------------" << endl;
        cout << "Jusu ivestas skaicius " << raktinisZodis << " yra. Jo pozicija masyve: " << indeksas
             << "." << endl;
        cout << " " << endl;
    } else {
        cout << "Jusu ivestas skaicius " << raktinisZodis << " nera." << endl;
        cout << " " << endl;
    }
}
