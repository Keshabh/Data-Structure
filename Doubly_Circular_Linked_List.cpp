//doubly circular linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

//all the operations 
void beginsert();
void lastinsert();
void begdelete();
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
        cout<<"\n1.Insert in begining.\n2.Insert in the last.\n";
        cout<<"3.Delete from begining.\n4.Delete from last.\n";
        cout<<"5.Show.\n6.Search.\n7.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:beginsert();break;
            case 2:lastinsert();break;
            case 3:begdelete();break;
            case 4:lastdelete();break;
            case 5:show();break;
            case 6:search();break;
            case 7:exit(0);break;
            default:cout<<"Invalid Choice!";
        }
    }
}

void beginsert()
{
    //allocate a memory to node pointer
    struct node *ptr=allocate();
    //check if ptr is allocated or not
    if(ptr==NULL)
      cout<<"\nMemory Overflow";
    else
    {
        //read a val from user
        int val;
        cout<<"Enter a value: ";
        cin>>val;
        //if node is empty
        if(head==NULL)
          {
              head=ptr;
              ptr->data=val;
              ptr->next=ptr->prev=head;
              cout<<"\nNode inserted.";
          }
        else
        {
            //to put a node in beg, we have to trasverse till the end to assign the address 
            //of 1st node in the last node
            ptr->data=val;
            struct node *temp;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
            ptr->prev=temp;
            cout<<"\nNode inserted.";
        }
    }
}

void lastinsert()
{
    //allocate a memory ptr
    struct node *ptr=allocate();
    //read a val 
    int val;
    cout<<"Enter a value: ";
    cin>>val;
    ptr->data=val;
    //if list is empty
    if(head==NULL)
    {
        head=ptr;
        ptr->prev=head;
        ptr->next=head;
        cout<<"\nNode inserted.";
    }
    else
    {
    //traverse till the end
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
      temp=temp->next;   
    }
    ptr->prev=temp;
    ptr->next=head;
    temp->next=ptr;
    }
}

void begdelete()
{
    //if list is empty
    if(head==NULL)
      cout<<"\n List is empty!";
    else if(head->next==head)
    {
        head=NULL;
        free(head);
        cout<<"\nNode deleted.";
    }
    else
    {
        head->next->prev=head->prev;
        //travell till end of list to assign last node->next=head->next
        struct node *temp;
        temp=head;
        while(temp->next!=head)
          temp=temp->next;
        temp->next=head->next;
        free(head);
        head=temp->next;
        cout<<"\nNode deleted.";
    }
}

void lastdelete()
{
     //if list is empty
    if(head==NULL)
      cout<<"\n List is empty!";
    else if(head->next==head)
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
        ptr->next=temp->next;
        head->prev=ptr;
        free(temp);
    }
}

void show()
{
    //check if list is empty
    if(head==NULL)
      cout<<"\nList is empty.";
    else
    {
        struct node *temp;
        temp=head;
        cout<<"Elements in the list are: \n";
        while(temp->next!=head)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data;
    }
}

void search()
{
    int key,pos=1;
    cout<<"\nEnter a key: ";
    cin>>key;
    //traverse through each node and match the data
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
        if(key==temp->data)
        {
            cout<<"\nElement found at location "<<pos;
        }
        temp=temp->next;
        pos++;
    }
    if(key==temp->data)
        {
            cout<<"\nElement found at location "<<pos;
        }
        
}
