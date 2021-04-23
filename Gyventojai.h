//
// Created by Lenovo on 2021-04-07.
//

#ifndef UZDUOTIS_1_GYVENTOJAI_H
#define UZDUOTIS_1_GYVENTOJAI_H
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Gyventojai {
private:
    int amzius;
    string vardas;
    string pavarde;
    double pajamos;
    string miestas;
public:
    Gyventojai(int amzius, const string &vardas, const string &pavarde, double pajamos, const string &miestas);

    int getAmzius() const;

    const string &getVardas() const;

    const string &getPavarde() const;

    double getPajamos() const;

    const string &getMiestas() const;
};



#endif //UZDUOTIS_1_GYVENTOJAI_H
