cmake_minimum_required(VERSION 3.23)
project(BST)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BST
        ArbolBinario.h
        ArbolGeneral.h
        BST.h
        Cola.h
        ColaSE.h
        ListSE.h
        ListSEC.h
        main.cpp
        NodoSE.h
        Pila.h
        PilaSE.h List.h PriorityQueue.h)
