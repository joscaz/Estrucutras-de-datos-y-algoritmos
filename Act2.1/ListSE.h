#pragma once
#include "List.h"
#include "NodoSE.h"
#include <iostream>
using namespace std;

template<class T> class ListSE : public List<T>
{
private:
	NodoSE<T>* cabeza;

public:
	ListSE() : List<T>(0)
	{
		this->cabeza = NULL;
	}

	~ListSE()
	{
	
	}

	void add(T* element)
	{
		NodoSE<T>* nuevo = new NodoSE<T>(element);
		if (this->cabeza == NULL)
		{
			this->cabeza = nuevo;
		}
		else
		{
			NodoSE<T>* temp = this->cabeza;
			while (temp->getSiguiente() != NULL)
			{
				temp = temp->getSiguiente();
			}
			temp->setSiguiente(nuevo);
		}
		this->length++;
	}

	void insert(T* element, int pos)
	{
		if (pos < 0 || pos >= this->length)
		{
			throw "No se puede insertar el elemento porque la posicion es incorrecta";
		}

		NodoSE<T>* nuevo = new NodoSE<T>(element);
		if (pos == 0)
		{
			nuevo->setSiguiente(cabeza);
			cabeza = nuevo;
		}
		else
		{
			int posTemp = 0;
			NodoSE<T>* temp = this->cabeza;
			while (posTemp < pos - 1)
			{
				temp = temp->getSiguiente();
				posTemp++;
			}
			nuevo->setSiguiente(temp->getSiguiente());
			temp->setSiguiente(nuevo);
		}
		this->length++;
	}
};

