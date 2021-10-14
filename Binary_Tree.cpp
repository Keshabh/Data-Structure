//binary tree node insertion
#include<iostream>
using namespace std;

//define a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
    
};

//root node
struct node *root=NULL;

//node function to allocate the val and null to its left and right and return address of node 
struct node *create_node(int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
}

//inorder traversal 
void inorder(struct node *Node)
{
   if(Node==NULL)
    return;
   inorder(Node->left);
   cout<<Node->data<<" ";
   inorder(Node->right);
}

//main
int main()
{
    //create node returns the adress of new node after assigning the data passed in it.
    // and we are assigning each and every root pointer the returned adress of node.
    root=create_node(11);
    root->left=create_node(22);
    root->right=create_node(33);
    root->left->left=create_node(44);
    root->left->right=create_node(55);
    root->right->left=create_node(66);
    root->right->right=create_node(77);
    inorder(root);
    
}
