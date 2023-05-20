#include "ArrayQueue.h"

template <class T>
Queue<T>::Queue()
{
	size=5;
	count=0;
	front=back=-1;
	arr=new T[size];
}

template <class T>
int Queue<T>::length()
{
	return count;
}

template <class T>
void Queue<T>::Enqueue(T val)
{
	assert(!full());
	if(count==0)
		front=0;
    //circular queue so you have to return back to the mod of the size IF it was dequed
    //FIXED SIZE QUEUE
    //enqueue(6)
    //[] 2 3 4 5
    //   f     b

    //6 2 3 4 5
    //b f
	back=(back+1)%size;
	arr[back]=val;
	count++;
}

template <class T>
void Queue<T>::Dequeue()
{
	assert(!empty());
    //circular queue so you have to return back to the mod of the size IF it was dequed
    //FIXED SIZE QUEUE
    //1 2 3 4 5
    //f       b

    //dequeue()
    //[] 2 3 4 5
    //   f     b
	if(count==1)
		front=back=-1;
	else
		front=(front+1)%size;
	count--;
}

template <class T>
T Queue<T>::Front()
{
	assert(!empty());
  	return arr[front];
}

template <class T>
T Queue<T>::Back()
{
	assert(!empty());
  	return arr[back];
}

template <class T>
bool Queue<T>::isFull()
{
	return (count==size);
}

template <class T>
bool Queue<T>::isEmpty()
{
	return (count==0);
}


template <class T>
Queue<T>::~Queue()
{
	delete[] arr;
}
