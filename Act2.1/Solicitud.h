#pragma once
#include <string>
#include <iostream>

using namespace std;

template<class T> class Solicitud{
protected:
    string nombre;
    string noID;
    float cantidadDepositar;

public:
    setNoID(string noID){
        this->noID = noID;
    }

    string getNoID(){
        return this->noID
    }
};