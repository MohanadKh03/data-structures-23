#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Stack
{
	T* arr;
	int MaxSize;
	int CurrSize;

	void Expand();
public:
	Stack();

	void Push(T val);
	void Pop();
	T Top();
	int GetSize();
	bool IsEmpty();

	~Stack();
};
