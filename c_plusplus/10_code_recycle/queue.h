#ifndef QUEUE_H_
#define QUEUE_H_


class Customer
{
private:
	long arrive;		
	int processtime;	
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;
template <class Type>

class Queue{
	struct Node { Type item; struct Node * next; };
	enum { Q_SIZE = 10 };
private:
	Node * front;		
	Node * rear; 		
	int items;			
	const int qsize;	
	Queue(const Queue & q) : qsize(0) { }
	Queue & operator=(const Queue & q) { return *this; }
public:
	Queue(int qs = Q_SIZE);	
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Type & item);	
	bool dequeue(Type & item);		
};
#endif
