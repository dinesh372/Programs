#include<iostream>

using namespace std;

class node 
{
	private:
		int val;
		node *next;
	public:
		node()
		{
			val =-1;
			next = NULL;
		}
		int getVal()
		{
			return val;
		}
		void setVal(int val)
		{
			this->val = val;
		}
		node *getNext()
		{
			return next;
		}
		void setNext(node *next)
		{
			this->next = next;
		}
};

class Queue
{
	node *head, *tail;
	
	public:
	Queue()
	{
		head = tail = NULL; 
	}
	void enQueue(int val)
	{
		node * n = new node();
		n->setVal(val);
		if(head == NULL)
		{
			head = n;
			tail =n;
		}
		else
		{
			tail->setNext(n);
			tail = tail->getNext(); 
		}
	}
	// Just returns the value not the node 
	int deQueue()
	{
		if(head == NULL)
		{
			cout<<"can't deQueue from an empty Queue"<<endl;
			return -1;
		}
		int rVal = head->getVal();
		node *temp = head;
		head = head->getNext();
		if(head == NULL)
			tail = NULL;
		delete temp;
		return rVal;
	}
	
	bool isEmpty()
	{
	    if(head ==NULL)
		     return true;
		return false; 
	}
};
