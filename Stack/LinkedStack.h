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
class Stack
{
    int length;

    Node<T>* head;

public:
        Stack();

        int getSize();
        void Push(T val);
        void Pop();
        T Top();
        bool isEmpty();

        void Display();

        ~Stack();
};
