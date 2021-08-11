#include<iostream>
#include<stdlib.h>
using namespace std;

//lets define all the functions we are going to perform on our linked list

void beginsert();
void lastinsert();
void randinsert();
void begdelete();
void lastdelete();
void randdelete();
void show();
void search();

//lets create a node
struct node{
    int data;
    struct node *next;
};

//lets create a head pointer to point my first node in linked list
struct node *head;

//main()
int main()
{
    int choice;
    //lets create a menue driven program
    while(true)
    {
        //choice to user
        cout<<"\nChoose one option from the following list ...\n\n";
        cout<<"1. Insert in the beginning\n2. Insert in the random position\n3. Insert in the last\n";
        cout<<"4. Delete in the beginning\n5. Delete in the random position\n6. Delete in the last\n";
        cout<<"7. Show\n8. Search\n9. Exit";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
       
        switch(choice)
        {
            case 1:beginsert();break;
            case 2:randinsert();break;
            case 3:lastinsert();break;
            case 4:begdelete();break;
            case 5:randdelete();break;
            case 6:lastdelete();break;
            case 7:show();break;
            case 8:search();break;
            case 9:exit(0);break;
            default:cout<<"\nInvalid choice!\n";
            
        }
    }
}

void beginsert()
{
    //lets allocate a node memory in ptr
    struct node *ptr= (struct node*)malloc(sizeof(struct node*));
    //lets check for overflow
    if(ptr==NULL)
      cout<<"Memory overflow";
    else
    {
        //read a value from user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        //assign value in ptr data
        ptr->data=val;
        //ptr->next is present in head
        ptr->next=head;
        //now head will point to ptr
        head=ptr;
        cout<<"\nNode inserted";
    }
}

void randinsert()
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
      cout<<"\nMemory Overflow!";
    else
    {
        int val,index;
        cout<<"\nEnter a value: ";
        cin>>val;
        //assign val in ptr->data
        ptr->data=val;
        //read index after which insertion of node will be done
        cout<<"Enter a index after which element will be inserted(considering 1-order indexing):";
        cin>>index;
        //traverse till index positioned node and put node->next in ptr->next
        struct node *temp=(struct node*)malloc(sizeof(struct node*));
        temp=head;
        //we can reach ith in i-1 times
        for(int i=1;i<index;i++)
        {
            temp=temp->next;
        }
        //assign temp->next in ptr->next
        ptr->next=temp->next;
        temp->next=ptr;
        cout<<"\nNode inserted!";
    }
}

void lastinsert()
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
      cout<<"\nMemory overflow";
    else
    {
        //read a value from user
        int val;
        cout<<"\nEnter a value: ";
        cin>>val;
        //assign val in data
        ptr->data=val;
        ptr->next=NULL;
        //i have to put the address of this node in the last node pointer
        //to perform this , i have to traverse till last of the linked list to insert ptr address
        //there are 2 conditions from here, 1. list is empty i.e head is null and 2. not empty
        //if list is empty
        if(head==NULL)
        {
          head=ptr;
          cout<<"\nNode inserted";
        }
        else
        {
            //traverse till the end of list
            //put ptr address in last node pointer
            struct node *temp=(struct node*)malloc(sizeof(struct node*));
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            //now i have the last node in temp, 
            //store ptr address in temp->next
            temp->next=ptr;
            cout<<"\nNode inserted";
        }
        
    }
}

void begdelete()
{
    //check if list is empty
    if(head==NULL)
      cout<<"\nList is empty!";
    else
    {
        struct node *ptr=(struct node*)malloc(sizeof(struct node*));
        ptr=head;
        head=ptr->next;
        free(ptr);
        cout<<"Element deleted from the begining";
    }
}

void randdelete()
{
    //check if list is empty
    if(head==NULL)
      cout<<"\nList is empty!";
     else{
         int index;
         cout<<"Enter the index of the element to be deleted(considering 1-order iindexing: ";
         cin>>index;
         //iterate till n-1 times to reach nth element
         struct node *ptr=(struct node*)malloc(sizeof(struct node*));
         struct node *temp=(struct node*)malloc(sizeof(struct node*));
         ptr=head;
         for(int i=1;i<index;i++)
         {
             temp=ptr;
             ptr=ptr->next;
         }
         //assign ptr->next in temp->next
         temp->next=ptr->next;
         //free the memory of ptr
         free(ptr);
         cout<<"Node deleted from "<<index<<" position.";
         
     }
}

void lastdelete()
{
    //check if list is empty
    if(head==NULL)
      cout<<"\nList is empty!";   
    else
    {
        struct node *ptr=(struct node*)malloc(sizeof(struct node*));
        struct node *temp=(struct node*)malloc(sizeof(struct node*));
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr; //temp is to store second last node.
            ptr=ptr->next;
        }
        //assign null in the pointer of second last node
        temp->next=NULL;
        free(ptr);
        cout<<"Element deleted from the last";
    }
}

void search()
{
    //if list is empty
    if (head==NULL)
     cout<<"List is empty!";
    else
    {
        int i=1,key;
        //traverse in the list
        struct node *temp=(struct node*)malloc(sizeof(struct node*));
        temp=head;
        cout<<"\nEnter a key value: ";
        cin>>key;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                cout<<"\nElement found at location "<<i;
            }
            i++;
            temp=temp->next;
        }
        
    }
}

void show()
{
    //check if list is empty 
    if(head==NULL)
      cout<<"\nList is empty.";
    else
    {
     struct node *temp=(struct node*)malloc(sizeof(struct node*));
     temp=head;
     cout<<"\nData in the list: ";
     while(temp!=NULL)
     {
         cout<<"\n"<<temp->data;
         temp=temp->next;
     }
    }

}
