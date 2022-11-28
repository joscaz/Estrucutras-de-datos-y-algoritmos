#pragma once
#include <iostream>
using namespace std;

template<class T> class NodoSE
{
protected:
	T* valor;
	NodoSE<T>* left;
    NodoSE<T>* right;

public:
	NodoSE(T* valor)
	{
		this->valor = valor;
		this->right = new NodoSE<T>();
        this->left = new NodoSE<T>();
	}

    NodoSE()
    {
        this->valor = NULL;
        this->right = new NodoSE<T>();
        this->left = new NodoSE<T>();
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

	inline NodoSE<T>* getRight()
	{
		return this->right;
	}

	inline void setRight(NodoSE<T>* right)
	{
		this->right = right;
	}

    inline NodoSE<T>* getLeft()
    {
        return this->right;
    }

    inline void setLeft(NodoSE<T>* left)
    {
        this->left = left;
    }
};

