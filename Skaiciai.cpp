//
// Created by Lenovo on 2021-04-07.
//

#include "Skaiciai.h"
int TiesinePaieska(const vector<int>&sarasas,int raktinisZodis){
    for (int i = 0; i < sarasas.size(); ++i) {
        if(raktinisZodis == sarasas[i]){
            return i;
        }
    }
    return -1;
}
vector<int> TiesinePaieskaVisi(const vector<int>&sarasas,int raktinisZodis){
    vector<int>laikinasSarsas;
    for (int i = 0; i <sarasas.size() ; ++i) {
        if(raktinisZodis == sarasas[i]){
            laikinasSarsas.emplace_back(i);
        }
    }
    return laikinasSarsas;
}
int DvejetainePaieska(vector<int>&sarasas, int kaire, int desine, int raktinisZodis){
    std::sort(sarasas.begin(), sarasas.end());
    cout << " " << endl;
    cout <<"Skaiciu sarasas (surusiuotas):   "<<endl;
    cout << "_________________________________________________" << endl;
    for (auto it:sarasas){
        cout << it<<"  ";
    }
    while(kaire<=desine){
        int vidurioElementas = kaire +(desine -kaire)/2;
        if (sarasas[vidurioElementas] == raktinisZodis){
            return vidurioElementas;
        }
        if(sarasas[vidurioElementas]< raktinisZodis){
            kaire= vidurioElementas +1;
        }else{
            desine = vidurioElementas -1;
        }
    }
    return -1;
}
