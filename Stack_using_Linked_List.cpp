//implement stack using linked list
#include<iostream>
#include<stdio.h>
using namespace std;

//head pointer
struct node *head=NULL;

//push element 
void push();
//pop element
void pop();
//display all the elements
void show();

//create a node
struct node{
    int data;
    struct node *next=NULL;
};

//menu driven program
int main()
{
    int choice;
    while (true)
    {
        cout<<"\nPress:\n1.To PUSH.\n2.To POP.\n3.To SHOW.\n4.To EXIT\n\nEnter: ";
        cin>>choice;
        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:show();break;
            case 4:exit(1);
            default:cout<<"Invalid choice!\n";
        }
    }
}

//push
void push()
{
    //create a node and allocate memory to it
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    
    //check if memory is full for overlfow condition
    if(ptr==NULL)
      cout<<"Overflow occured!\n";
    else
    {
        //read value from user
        int val;
        cout<<"Enter a value: ";
        cin>>val;
        ptr->data=val;
        ptr->next=head;
        head=ptr;
        cout<<"Element Inserted.\n";
    }
    
}

//pop
void pop()
{
    //delete a node from the begining
    //check if node is already empty for underflow condition
    if(head==NULL)
      cout<<"Underflow occured!\n";
    else
    {
        struct node *temp;
        temp=head->next;
        free(head);
        head=temp;
        cout<<"Element deleted.\n";
    }
}

//SHOW
void show()
{
    //display all the elements 
    //first check if list is empty
    if(head==NULL)
      cout<<"Stack is empty!\n";
    else
    {
        struct node *temp;
        temp=head;
        cout<<"Elements in the Stack are: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
