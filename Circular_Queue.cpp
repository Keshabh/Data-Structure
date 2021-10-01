//circular queue
#include<iostream>
using namespace std;
#define SIZE 5

//declare queue arr globally to be accessed in every function
int queue[SIZE];
//declare front and rear pointer and initialize with -1
int front=-1;
int rear=-1;

//declare the functions to be used
void enqueue();
void dequeue();
void display();

//main function
int main()
{
    //menu driven program
    int choice;
    while(1)
    {
        cout<<"\nPress\n1.To Enqueue.\n2.To Dequeue.\n3.To Display.\n4.To Exit\n\nEnter: ";
        cin>>choice;
        switch(choice)
        {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:exit(1);
            default:cout<<"invalid choice!";
        }
    }
}

//enqueue function
void enqueue()
{
    //check for overflow
    //case 1.(front<rear)happens if no element is deleted, and rear reaches the end
    //case 2.(front>rear) happens when front is just after rear.
    if((front==0 && rear==SIZE-1) || (front==rear+1))
      cout<<"\nOverflow occured!";
    else
    {
        //read a val from user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        
        //modify the positions of front and rear
        //if its a first element 
        if(front ==-1 && rear==-1)
        {
            front =0;
            rear=0;
        }
        //when front> rear
        else if(rear==SIZE-1 && front!=0)
        {
            rear=0;
            cout<<"abcde";
        }
        else 
         rear++;
        queue[rear]=val;
    }
}

//dequeue
void dequeue()
{
    //check for Underflow
    if (front==-1 && rear==-1)
      cout<<"\nUnderflow Occured!";
    else
    {
        //case 1: if there is just one element left, then take front and rear back to -1 state.
        if(front==rear)
        {
            cout<<"\nElement "<<queue[front]<<" deleted.";
            front=-1;
            rear=-1;
        }
        //case 2: when front is at SIZE-1 , it needs to jump to 0
        else if(front==SIZE-1)
        {
            cout<<"\nElement "<<queue[front]<<" deleted.";
            front=0;
        }
          //case 3: when fron<rear
        else if(front<rear || front>rear)
        {
            cout<<"\nElement "<<queue[front]<<" deleted.";
            front++;
        }
        
    }
}

//display
void display()
{
    //check if queue is empty or not
    if(front==-1 and rear==-1)
      cout<<"\nUnderflow occurs!";
    else
    {
    //display elements
    cout<<"Elements in queue are: ";
    //if front<rear then display elements from front till rear
    if(front<=rear)
      {
          for(int i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
      }
    //if front>rear, then display from start till rear and from front till end
    if(front>rear)
    {
        for(int i=front;i<=SIZE-1;i++)
          cout<<queue[i]<<" ";
        for(int i=0;i<=rear;i++)
          cout<<queue[i]<<" ";
    }
    }
}
