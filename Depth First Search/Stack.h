#include<stdio.h>
class node
{
public:
	int val;
	node *next;
};
class stack
{
	node *head;
	int size; // As of now just keep for bookkeeping
	
	public:
		stack()
		{
			head = NULL;
			size =0;
		}
		
		void push(int x)
		{
			node *n = new node;
			n->val =x;
			n->next = head;
			head =n;
			size++;
		}
		
		/* for our purpose we just wants to return the value. 
		 * If a call is made on empty stack -1 is returned, though user should always check for stack empty status before calling pop.*/ 
		int pop()
		{
			if(head == NULL)
				return -1; 
			node *p = head;
			int val = p->val;
			head = head->next;
			delete p;
			size--;
			return val;
		}
		
		bool isEmpty()
		{
			if(head == NULL)
				return true;
			return false;
		}
		
};