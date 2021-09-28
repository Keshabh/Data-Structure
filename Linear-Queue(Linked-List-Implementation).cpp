//linear queue using linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

//lets create a node
struct node
{
	int data;
	struct node *next=NULL;
};
//lets make a front and rear pointer, which is initially null
struct node *front = NULL;
struct node *rear  = NULL;

//function to allocate the node memory
struct node *allocate()
{
	return (struct node*)malloc(sizeof(struct node));
}

//lets declare our functions
void insertion();
void deletion();
void display();

//main 
int main()
{
	while(1)
	{
	int choice;
	cout<<"\nPress.\n1.To Insert.\n2.To Delete.\n3.To Display.\n4.To Exit.\n\nEnter: ";
	cin>>choice;
	switch(choice)
	{
		case 1:insertion();break;
		case 2:deletion();break;
		case 3:display();break;
		case 4:exit(1);
		default:cout<<"\nINVALID CHOICE!";
	}
   }
}

//enqueue
void insertion()
{
	struct node *ptr=allocate();
	//overflow occurs if the memory is full
	if(ptr==NULL)
	  cout<<"Memory not allocated or overflow occured!";
	else
	{
		//read a value from the user
		int val;
		cout<<"\nEnter a value: ";
		cin>>val;
		ptr->data=val;
		//if its the first element in the queue then
		if(front==NULL)
		{
		  front=ptr;
		  rear=ptr;
		  rear->next=NULL;
		  front->next=NULL;
	    }
		else
		{
			rear->next=ptr;
			rear=ptr;
			rear->next=NULL;
		}
	}
}

//dequeue
void deletion()
{
	struct node *tmp;
	//check if queue is empty
	if(front==NULL)
	  cout<<"\nQueue is empty!";
	else
	{
		//free front and move front to front->next
		cout<<"\nNode "<<front->data<<" deleted.";
		tmp=front;
		front=front->next;
		free(tmp);
	}
}

//display
void display()
{
	//check if queue is empty
	if(front==NULL)
	  cout<<"Queue is empty!";
	else
	{
		//traverse from front
		struct node *temp=front;
		cout<<"\nElements in the queue are: ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}
