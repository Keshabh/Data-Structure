//stack implementation using array
#include<iostream>
using namespace std;
#define SIZE 100

//define a global array
int stack[SIZE];
int n;
//initialize global top pointer with -1(initially empty)
int top=-1;
//declare all operations 
void push();
void pop();
void show();

//main
int main()
{
    //read stack size from user
    cout<<"Enter the size of your Stack: ";
    cin>>n;
    //menu driven program
    int choice;
    while(true)
    {
        cout<<"\nPress \n1.To PUSH.\n2.To POP.\n3.To SHOW.\n\nEnter: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:show();break;
            default:cout<<"Invalid choice!";
        }
    }
}


//enter a element in the top
void push()
{
    //check if stack is full or not
    if(top==n-1)
      cout<<"Overflow occured!\n";
    else
    {
        int data;
        //read val from user
        cout<<"Enter a value to enter in the stack: ";
        cin>>data;
        top=top+1;
        stack[top]=data;
        cout<<"Element Inserted\n";
    }
}

//delete an element from the top 
void pop()
{
    if(top==-1)
      cout<<"Underflow occured!\n";
    else
    {
        cout<<"Element "<<stack[top]<<" deleted.\n";
        top=top-1;
    }
}

//display all the values in the stack
void show()
{   if(top==-1)
      cout<<"Stack is empty!\n";
    else
    {
    cout<<"Elements in the stack are: ";
    for(int i=top;i>-1;i--)
      cout<<stack[i]<<" ";
    cout<<"\n";
    }
}
