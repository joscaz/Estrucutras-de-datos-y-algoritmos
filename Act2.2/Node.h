#pragma once
#include <iostream>

using namespace std;

class Node{
public:
    int key;
    int data;
    Node* next;
    Node* prev;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int k, int d){
        key = k;
        data = d;
    }
};