#pragma once
using namespace std;

template<class T> class NodoSE
{
protected:
	T* valor;
	NodoSE<T>* siguiente;

public:
	NodoSE(T* valor)
	{
		this->valor = valor;
	}

	~NodoSE()
	{
		delete valor;
	}

	inline T* getValor()
	{
		return this->valor;
	}

	inline void setValor(T* valor)
	{
		this->valor = valor;
	}

	inline NodoSE<T>* getSiguiente()
	{
		return this->siguiente;
	}

	inline void setSiguiente(NodoSE<T>* siguiente)
	{
		this->siguiente = siguiente;
	}
};

