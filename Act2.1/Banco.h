#pragma once
#include <iostream>
#include "ListSE.h"
#include "NodoSE.h"
#include "ColaSE.h"
#include "Solicitud.h"

using namespace std;

template<class T> class Banco : public Solicitud<T>{
protected:
    ListSE<T>* lcuentas = new ListSE<T>();
    ColaSE<T>* cSolicitudes = new ColaSE<T>();

public:
    int verificarCuenta(){
        NodoSE<T>* solis = new NodoSE<T>();
        T* agregarSolis = cSolicitudes->add(solis);

        if(cSolicitudes->top())
    }

    void atenderTodasLasSolicitudes(){
        cout<<endl;
    }

    ListSE<T>* darBajaMillonarios(){
        return lcuentas;
    }

};