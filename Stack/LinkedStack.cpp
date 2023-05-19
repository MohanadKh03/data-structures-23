#include "LinkedStack.h"

template<class T>
Stack<T>::Stack(){
    length = 0;
    head = NULL;
}

template<class T>
int Stack<T>::getSize(){
    return length;
}

template<class T>
void Stack<T>::Push(T val){
    Node<T>* newNode = new Node<T>(val);
  
    newNode->next = head;
    head = newNode;

    length++;
}

template<class T>
T Stack<T>::Top(){
    assert(length != 0);
    return head->val;
}


template<class T>
void Stack<T>::Pop(){
    assert(length != 0);
    Node<T>* temp = head;
    head = head->next; 
    delete temp;
    length--;
}

template<class T>
bool Stack<T>::isEmpty(){
    return length == 0;
}

template<class T>
Stack<T>::~Stack(){
    while(length){
        Pop();
    }
}
