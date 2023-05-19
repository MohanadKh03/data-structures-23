#pragma once


#include <iostream>
#include <cassert>
using namespace std;

template<class N>
class Node{
public:
    N val;
    Node<N>*next;
    Node(N val){
        this->val = val;
        next = nullptr;
    }
};

template<class T>
class LinkedList
{
    int length;

    Node<T>* head;
    Node<T>* tail;

public:
        LinkedList();
        LinkedList(T val);
        int getSize();
        void Append(T val);
        T At(int pos);
        //bool isEmpty();
        void InsertAt(T val,int pos);
        void DeleteAt(int pos);

        void Display();

        ~LinkedList();
};
