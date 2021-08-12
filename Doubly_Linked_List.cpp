//doubly linked list
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
    struct node *prev;
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
    //lets create a node memory first
    struct node *ptr=allocate();
    if(ptr==NULL)
      cout<<"Memeory Overflow!";
    else
    {
        //read value from the user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        //if list is empty
        if(head==NULL)
        {
            ptr->data=val;
            ptr->next=ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            ptr->data=val;
            ptr->prev=NULL;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
        cout<<"\nNode inserted";
    }
}

void randinsert()
{
    struct node *ptr=allocate();
    if(ptr==NULL)
      cout<<"Memeory Overflow!";
    else
    {
        //read value from the user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        //if list is empty
        if(head==NULL)
        {
            ptr->data=val;
            ptr->next=ptr->prev=NULL;
            head=ptr;
            cout<<"\nSince list was empty, inserted in poistion 1.";
        }
        else
        {
          int index;
          cout<<"Enter index (considering 1-order indexing): ";
          cin>>index;
          //iterate through n-1 times to reach nth node
          struct node *temp=allocate();
          temp=head;
          for(int i=1;i<index-1;i++)
            temp=temp->next;
          //now i am at index positioned node
          //assign the value in ptr
          ptr->data=val;
          ptr->next=temp->next;
          ptr->prev=temp;
          temp->next=ptr;
          ptr->next->prev=ptr;
        }
        cout<<"\nNode inserted";
    }
    
}

void lastinsert()
{
    struct node *ptr=allocate();
    if(ptr==NULL)
      cout<<"Memeory Overflow!";
    else
    {
        //read value from the user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        //if list is empty
        if(head==NULL)
        {
            ptr->data=val;
            ptr->next=ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            //to insert the node in the last, traverse till the end node
            struct node *temp=allocate();
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            //assign the value in ptr
            ptr->data=val;
            ptr->next=NULL;
            ptr->prev=temp;
            temp->next=ptr;
        }
        cout<<"\nNode inserted";
    }
}

void begdelete()
{
  //if list is empty
  if(head==NULL)
    cout<<"\nUnderflow.";
  else if(head->next==NULL) //for single node in  the list
  {
      head=NULL;
      free(head);
      cout<<"\nNode deleted";
  }
  else
  {
      struct node *ptr;
      ptr=head;
      head=head->next;
      head->prev=NULL;
      free(ptr);
      cout<<"\nNode deleted";
  }
}

void randdelete()
{
   //if list is empty
  if(head==NULL)
    cout<<"\nUnderflow.";
  else if(head->next==NULL) //for single node in  the list
  {
      head=NULL;
      free(head);
      cout<<"\nNode deleted";
  }
  else
  {
      int index;
      cout<<"Enter index(considering 1-order indexing: ";
      cin>>index;
      //itertae through loop n-1 times to reach nth node
      struct node *temp;
      temp=head;
      for(int i=1;i<index;i++)
      {
          temp=temp->next;
      }
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      free(temp);
      cout<<"\nNode deleted.";
  }
  
}

void lastdelete()
{
     //if list is empty
  if(head==NULL)
    cout<<"\nUnderflow.";
  else if(head->next==NULL) //for single node in  the list
  {
      head=NULL;
      free(head);
      cout<<"\nNode deleted";
  }
  else
  {
    struct node *temp;
    //traverse till second last node of list
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
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
    //traverse through whole node
    struct node *ptr=allocate();
    ptr=head;
    cout<<"\nElements in List are:\n";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"\n";
        ptr=ptr->next;
    }
    }
}

void search()
{
    int key,i=1,flag=2;
    cout<<"Enter key value: ";
    cin>>key;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
         cout<<"\nElement found at location "<<i;
         flag=3;
        }
        i++;
        temp=temp->next;
    }
    if(flag==2)
     cout<<"\nElement not found.";
}
