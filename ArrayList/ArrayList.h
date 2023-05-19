#pragma once

#include <iostream>
using namespace std;

template<class T>
class ArrayList {
	T* arr;
	int MaxSize;
	int CurrSize;//the size of the actual array

	void Expand();

public:
	ArrayList();
	ArrayList(int size);

	void Append(T value);
	T At(int index);
	int GetSize();
	void Insert(int index,T value);
	void Delete(int index);

	void Display();

	~ArrayList();
};
