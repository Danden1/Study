#include <iostream>
#include "queue.h"
#include <cstdlib>		
using namespace std;


template <class Type>
Queue<Type>::Queue(int qs) : qsize(qs){
	front = rear = NULL;
	items = 0;
}

template <class Type>
Queue<Type>::~Queue(){
	Node * temp;
	while (front != NULL)	{
		temp = front;		
		front = front->next;	
		delete temp;		
	}
}

template <class Type>
bool Queue<Type>::isempty() const
	return items == 0;


template <class Type>
bool Queue<Type>::isfull() const
	return items == qsize;


template <class Type>
int Queue<Type>::queuecount() const
	return items;



template <class Type>
bool Queue<Type>::enqueue(const Type & item){
	if (isfull())
		return false;
	Node * add = new Node;	
	if (add == NULL)
		return false;		
	add->item = item;		
	add->next = NULL;
	items++;
	if (front == NULL)		
		front = add;		
	else
		rear->next = add;	
	rear = add;				
	return true;
}


template <class Type>
bool Queue<Type>::dequeue(Type & item){
	if (front == NULL)
		return false;
	item = front->item;		
	items--;
	Node * temp = front;	
	front = front->next; 	
	delete temp;			
	if (items == 0)
		rear = NULL;
	return true;
}



void Customer::set(long when){
	processtime = rand() % 3 + 1;
	arrive = when;
}