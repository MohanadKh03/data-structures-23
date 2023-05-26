#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Node{
public:
    T val;
    Node<T>*left;
    Node<T>*right;
    Node(){
        this->val = 0;
        left = right = nullptr;
    }
    Node(T val){
        this->val = val;
        left = right = nullptr;
    }
};

template<class T>
class BST
{
    Node<T>* root;
    Node<T>* Find(T val);
    Node<T>* findParent(T val);

    void InOrder(Node<T>* root);
    void PreOrder(Node<T>* root);
    void PostOrder(Node<T>* root);

    Node<T>* findMin(Node<T>* root);

    void deleteAll(Node<T>*root);

public:
    BST();
    void Insert(T val);
    bool Contains(T val);
    void Traverse(int traversalWay);
    void Remove(T val);
    ~BST();
};
