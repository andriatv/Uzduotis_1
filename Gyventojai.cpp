//
// Created by Lenovo on 2021-04-07.
//

#include "Gyventojai.h"

Gyventojai::Gyventojai(int amzius, const string &vardas, const string &pavarde, double pajamos, const string &miestas)
        : amzius(amzius), vardas(vardas), pavarde(pavarde), pajamos(pajamos), miestas(miestas) {}

int Gyventojai::getAmzius() const {
    return amzius;
}

const string &Gyventojai::getVardas() const {
    return vardas;
}

const string &Gyventojai::getPavarde() const {
    return pavarde;
}

double Gyventojai::getPajamos() const {
    return pajamos;
}

const string &Gyventojai::getMiestas() const {
    return miestas;
}
vector<int> GyventojoPaieskaPagalAmziu (const
                                        vector<Gyventojai>&sarasas, int amzius){
    vector<int>laikinasSarasas;
    for(int i=0; i <sarasas.size();++i) {
        if (amzius ==sarasas[i].getAmzius()){
            laikinasSarasas.emplace_back(i);
        }
    }
    return laikinasSarasas;
}
vector<int>GyventojoPaieskaPagalVarda (const
vector<Gyventojai>&sarasas, string vardas){
    vector<int>laikinasSarasas;
    for (int i = 0; i <sarasas.size() ; ++i) {
        if(vardas == sarasas[i].getVardas()){
            laikinasSarasas.emplace_back(i);
        }
    }
    return laikinasSarasas;

}
vector<int> GyventojoPaieskaPagalMiesta(const vector<Gyventojai>&sarasas, string miestas) {
    vector<int> laikinasSarasas;
    for (int i = 0; i < sarasas.size(); ++i) {
        if (miestas == sarasas[i].getMiestas()) {
            laikinasSarasas.emplace_back(i);
        }
    }
    return laikinasSarasas;
}
vector<int> GynetojoPaieskaPagalPajamas (const vector<Gyventojai>&sarasas, double pajamos){
    vector<int>laikinasSarasas;
    for (int i = 0; i <sarasas.size() ; ++i) {
        if(pajamos == sarasas[i].getPajamos()){
            laikinasSarasas.emplace_back(i);
        }
    }
    return laikinasSarasas;
}
