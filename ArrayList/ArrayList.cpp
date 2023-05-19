#include "ArrayList.h"

template<class T>
void ArrayList<T>::Expand()
{
	MaxSize = MaxSize * 2;
	T* temp = new T[MaxSize];
	//1 2 3 4 5 -----> [] [] [] [] [] [] [] [] [] []
	//old arr   ----->            temp
	//we need to shift elements from old arr to temp
	for (int i = 0; i < CurrSize; i++)
		temp[i] = arr[i];
	//1 2 3 4 5 ---> 1 2 3 4 5 [] [] [] [] []
	
	//release the old arr and let it point at the new temp instead
	delete[] arr;
	arr = temp;
}

template<class T>
ArrayList<T>::ArrayList() {
	MaxSize = 10;
	CurrSize = 0;
	arr = new T[MaxSize];
}

template<class T>
ArrayList<T>::ArrayList(int size)
{
	MaxSize = size * 2;
	CurrSize = 0;
	arr = new T[MaxSize];
}


template<class T>
void ArrayList<T>::Append(T value)
{
	if (CurrSize == MaxSize)
		Expand();
	arr[CurrSize] = value;
	CurrSize++;
}

template<class T>
T ArrayList<T>::At(int index)
{
	return arr[index];
}

template<class T>
int ArrayList<T>::GetSize()
{
	return CurrSize;
}

template<class T>
void ArrayList<T>::Insert(int index, T value)
{
	if (CurrSize + 1 == MaxSize)
		Expand();
	//shift elements after the index to their right then insert at index 2 value 2
	//0 1  3  4
	//0 1 (2) 3 4
	for (int i = CurrSize; i > index; i--)
		arr[i] = arr[i - 1];
	arr[index] = value;
	CurrSize++;
}

template<class T>
void ArrayList<T>::Delete(int index)
{
	//shift elements after the index to rheir left then just decrement the size .. delete at index 1
	//2 4 5 6
	//2 5 6 [6] <--- this 6 hasnt been shifted/deleted BUT it is not accesible so we can consider it deleted
	for (int i = index; i < CurrSize - 1; i++)
		arr[i] = arr[i + 1];
	CurrSize--;
}

template<class T>
void ArrayList<T>::Display()
{
	for (int i = 0; i < CurrSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template<class T>
ArrayList<T>::~ArrayList(){
	if (arr != NULL) {
		delete[] arr;//release the memory
		arr = NULL;
	}
}
