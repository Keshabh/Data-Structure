//circular linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

//all the operations 
void beginsert();
void randinsert();
void lastinsert();
void begdelete();
void randdelete();
void lastdelete();
void show();
void search();

//lets create a node
struct node{
    int data;
    struct node *next;
};

//lets create head pointer
struct node *head;

//lest create a allocate() function to allocate the node memory.
struct node *allocate()
{
    return (struct node*)malloc(sizeof(struct node*));
}

//main
int main()
{
    //menu driven program
    while(true)
    {
        int choice;
        cout<<"\nChoose one option from the following list ...\n";
        cout<<"\n1.Insert in begining.\n2.Insert in the last.\n3.Insert in the random position.\n";
        cout<<"4.Delete from begining.\n5.Delete from last.\n6.Delete from random position.\n";
        cout<<"7.Show.\n8.Search.\n9.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:beginsert();break;
            case 2:lastinsert();break;
            case 3:randinsert();break;
            case 4:begdelete();break;
            case 5:lastdelete();break;
            case 6:randdelete();break;
            case 7:show();break;
            case 8:search();break;
            case 9:exit(0);break;
            default:cout<<"Invalid Choice!";
        }
    }
}

void beginsert()
{
    //lets create a node first
    struct node *ptr=allocate();
    //check if ptr is allocated or not
    if(ptr==NULL)
      cout<<"\nMemory Overflow!";
    else
    {
        //read value from user
        int val;
        cout<<"Enter a value: ";
        cin>>val;
        //if list is empty
        if(head==NULL)
        {
            ptr->data=val;
            head=ptr;
            ptr->next=head;
        }
        else
        {
            struct node *temp;
            //we need to traverse till the end of a node to store the adderss of 1st node in the last node
            temp=head;
            while(temp->next!=head)
              temp=temp->next;
            ptr->data=val;
            temp->next=ptr;
            ptr->next=head;
            head=ptr;
        }
        cout<<"\nNode inserted.";
    }
}

void lastinsert()
{
    //allocate a memory to a node
    struct node *ptr=allocate();
    //check if it is allocated or not
    if(ptr==NULL)
      cout<<"\nMemory Overflow!";
    else
    {
        //reasd useer value
        int val;
        cout<<"Enter a value: ";
        cin>>val;
        //if list is empty
        if(head==NULL)
        {
            ptr->data=val;
            head=ptr;
            ptr->next=head;
        }
        else
        {
            //we will have to traverse back to put our node at the end.
            struct node *temp;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            ptr->data=val;
            temp->next=ptr;
            ptr->next=head;
        }
        cout<<"\nNode inserted.";
    }
}

void randinsert()
{
    //lets allocate a node memory
    struct node *ptr=allocate();
    if(ptr==NULL)
      cout<<"\nMemory Overflow.";
    else
    {
        int val,index;
        cout<<"Enter a value: ";
        cin>>val;
        cout<<"Enter a index(considering 1-order): ";
        cin>>index;
        //iterate in the loop n-1 times to reach n-1 th node
        struct node *temp;
        temp=head;
        for(int i=1;i<index-1;i++)
          temp=temp->next;
        //assign the value in the ptr
        ptr->data=val;
        ptr->next=temp->next;
        temp->next=ptr;
        cout<<"\nNode inserted.";
    }
}

void begdelete()
{
 //if i delete a node from begining, i will have to change the  last node->next to second node
 //if list is empty
 if(head==NULL)
   cout<<"\nList is empty.";
 else
 {
  //if single node is there, then
  if(head->next==head)
  {
      head=NULL;
      free(head);
      cout<<"\nNode deleted.";
  }
  else
  {
 //traverse till the end of list
 struct node *temp;
 temp=head;
 //traverse till i encounter head
 while(temp->next!=head)
   temp=temp->next;
 temp->next=head->next;
 free(head);
 head=temp->next;
 cout<<"\nNode deleted.";
 }
 }
}

void lastdelete()
{
    //check if list is empty or not
    if(head==NULL)
      cout<<"\nList is empty!";
    else if(head->next==head) //for single node
    {
        head=NULL;
        free(head);
        cout<<"\nNode deleted.";
    }
    else
    {
        //traverse till the end
        struct node *temp,*ptr;
        temp=head;
        while(temp->next!=head)
         {
             ptr=temp;
             temp=temp->next;
         }
        ptr->next=head;
        free(temp);
        cout<<"\nNode deleted.";
    }
}

void randdelete()
{
    //check if list is empty
    if(head==NULL)
     cout<<"\nList is empty.";
    else if(head->next==head)//for single node
    {
        head=NULL;
        free(head);
        cout<<"\nNode deleted.";
    }
    else
    {
        int index;
        cout<<"Enter index(considering 1-order): ";
        cin>>index;
        //traverse till the n-1 time in the loop to reach nth node
        struct node *temp,*ptr;
        temp=head;
        for(int i=1;i<index;i++)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
        free(temp);
        cout<<"\nNode deleted.";
    }
}

void show()
{
    //check if list is empty
    if(head==NULL)
      cout<<"\nList is empty!";
    else
    {
        //traverse till we encounter the value of head in node's next
        struct node *temp;
        temp=head;
        cout<<"\nElements in the list are: \n";
        while(temp->next!=head)
        {
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
        cout<<temp->data;
    }
}

void search()
{
    //if list is empty
    if(head==NULL)
      cout<<"\nList is empty.";
    else
    {
        int pos=1,key;
        cout<<"\nEnter key: ";
        cin>>key;
        struct node *temp;
        temp=head;
        while(temp->next!=head)
        {
            if(key==temp->data)
              cout<<"\nElement found at location "<<pos;
            temp=temp->next;
            pos++;
        }
        if(temp->data==key)
          cout<<"\nElement found at location "<<pos;
    }
}
