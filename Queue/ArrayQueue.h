#pragma once
#include <iostream>
#include <cassert>

template <class T>
class Queue
{
	T* arr;
	int count, size;
	int front, back;
public:
	Queue();
	int getSize();
	void Enqueue(T);
	void Dequeue();
	T Front();
    T Back();
	bool isEmpty();
	bool isFull();
	~Queue();
};
