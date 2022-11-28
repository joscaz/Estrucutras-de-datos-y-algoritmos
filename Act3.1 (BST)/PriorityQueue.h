#pragma once
#include <iostream>
using namespace std;

template <class T> class PriorityQueue
{
protected:
    int priority;
    int info;
    int len;
    PriorityQueue<T>* next;
    PriorityQueue<T>* front;

public:
    PriorityQueue(){
        this->len = 0;
        this->priority = 0;
        this->info = 0;
        this->next = NULL;
        this->front = NULL;
    }

    void push(int i, int p){
        PriorityQueue<T> *t, *q;
        t = new PriorityQueue<T>;
        t->info = i;
        t->priority = p;
        if(front == NULL || p > front->priority){
            t->next = front;
            front = t;
        }
        else {
            q = front;
            while (q->next != NULL && q->next->priority >= p)
                q = q->next;
            t->next = q->next;
            q->next = t;
        }
        len++;
    }

    void pop(){
        PriorityQueue<T>* t;
        if(front == NULL){
            cout<<"Queue underflow\n";
        }
        else{
            t = front;
            cout<<"Deleted item is: "<<t->info<<endl;
            front = front->next;
        }
    }
    void show(){
        PriorityQueue<T>* ptr;
        ptr = front;
        if(front == NULL){
            cout<<"Queue is empty\n";
        }
        else{
            cout<<"Queue is :\n";
            cout<<"Priority item\n";
            while(ptr != NULL){
                cout<<ptr->priority<<" "<<ptr->info<<endl;
                ptr = ptr->next;
            }
            len--;
        }
    }

    bool empty(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return true;
        }
        else{
            cout<<"Queue is NOT empty"<<endl;
            return false;
        }
    }

    int top(){
        cout<<front->info<<"\n";
        return front->info;
    }

    int size(){
        cout<<"The size of the queue is: "<<len<<endl;
        return len;
    }
};