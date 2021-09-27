//linear queue using array
#include<iostream>
using namespace std;
//defined the global size of queue
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;

//functions declaration to be performed.
void insertion();
void deletion();
void display();

//main function
int main()
{
    //menu driven
    while(1)
    {
        int choice;
        cout<<"\nPress\n1.To Insert.\n2.To Delete.\n3.To Display.\n4.To Exit.\n\nEnter: ";
        cin>>choice;
        switch(choice)
        {
            case 1:insertion();break;
            case 2:deletion();break;
            case 3:display();break;
            case 4:exit(1);
            default:cout<<"\nINVALID CHOICE!\n";
        }
    }
    
}

//enqueue
void insertion()
{
    //check for overflow
    if(rear>=SIZE-1)
      cout<<"\noverflow occured!";
    else
    {
        //if its a first element insertion, update front to 0
        if(front==-1 && rear==-1)
        {
            front=0;
        }
        //otherwise increment rear and put the value in it.
        //read the value from the user
        int val;
        cout<<"\nEnter a value to enter in the Queue: ";
        cin>>val;
        rear++;
        queue[rear]=val;
        cout<<"\nElement Inserted.";
        
    }
}

//dequeue
void deletion()
{
    //check for underflow
    if(front==-1 || front >rear)
      cout<<"\nunderflow occured!";
    else
    {
        cout<<"\nElement "<<queue[front]<<" deleted.";
        //increment front pointer to point to the next element
        front++;
    }
}

//display
void display()
{
    //check if queue is empty
    if(front==-1 || front>rear)
      cout<<"\nQueue is empty!";
    else
    {
        //travese from the front till rear to delete the element
        cout<<"\nElements in the Queue are: ";
        for(int i=front;i<=rear;i++)
          cout<<queue[i]<<" ";
    }

}
