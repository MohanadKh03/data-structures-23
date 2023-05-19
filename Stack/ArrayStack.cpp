#include "ArrayStack.h"

/*
  Same logic as ArrayList but Push/Pop from one end 
*/


template<class T>
void Stack<T>::Expand()
{
	MaxSize *= 2;
	T* temp = new T[MaxSize];
	for (int i = 0; i < CurrSize; i++)
		temp[i] = arr[i];
	delete[] arr;
	arr = temp;
}

template<class T>
Stack<T>::Stack() {
	MaxSize = 10;
	CurrSize = 0;
	arr = new T[MaxSize];
}

template<class T>
void Stack<T>::Push(T val)
{
	if (CurrSize == MaxSize)
		Expand();
	arr[CurrSize] = val;
	CurrSize++;
}

template<class T>
void Stack<T>::Pop()
{
	  assert(!IsEmpty());
		CurrSize--;
}

template<class T>
T Stack<T>::Top()
{
    assert(!IsEmpty());
    return arr[CurrSize - 1];
}

template<class T>
int Stack<T>::GetSize()
{
	return CurrSize;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return CurrSize == 0;
}

template<class T>
Stack<T>::~Stack()
{
	if (arr != NULL) {
		delete[] arr;
		arr = NULL;
	}
}
