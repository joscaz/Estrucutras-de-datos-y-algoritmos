#pragma once
#include <string>
#include <iostream>

using namespace std;

template<class T> class Cuenta{
protected:
    int noCuenta;
    string noID;
    float saldo;

public:

    cuenta(string id, int noCuenta){
        cout<<"El id de este cliente es "<<id<<" y su numero de cuenta es "<<noCuenta<<endl;
    }

    string getNoId(){
        return this->noID;
    }

    setSaldo(float saldo){
        this->saldo = saldo;
    }

    float getSaldo(){
        return this->saldo;
    }

};