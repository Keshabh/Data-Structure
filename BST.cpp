#include<iostream>
using namespace std;

//define node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//root node
struct node *root=NULL;

//create_node function
struct node *create_node(int val)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=ptr->right=NULL;
    return ptr;
}

//functions prototype
void insertion(struct node *root, int elem);
struct node *deletion(struct node *root, int elem);
void display(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *Find_max(struct node*);

//main
int main()
{
    while(1)
    {
        int choice,val;
        cout<<"\nPress:\n1.To insert.\n2.To delete.\n3.To display.\n4.To exit.\n\nEnter: ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter a value to be inserted: "; cin>>val; insertion(root,val); break;
            case 2: cout<<"Enter a value to be deleted: "; cin>>val; root=deletion(root,val); break;
            case 3: display(root); break;
            case 4: exit(1);
            default: cout<<"Invalid choice!";
        }
    }
}

//insertion function
void insertion(struct node *Node, int elem)
{
    //check if tree is empty
    if(root==NULL)
      root=create_node(elem);
    else
    {
        //if val<root->data, then go to left-subtree
        if(elem<Node->data)
        {
            //check if Node->left is empty
            if(Node->left==NULL)
            {
                Node->left=create_node(elem);
                return;
            }
            else //make a recursive call and go to left-subtree further
                insertion(Node->left, elem);
        }
        else
        {
            //check if Node->left is empty
            if(Node->right==NULL)
            {
                Node->right=create_node(elem);
                return;
            }
            else //make a recursive call and go to left-subtree further
                insertion(Node->right, elem);
        }
    }
}

//deletion function
struct node *deletion(struct node *Node, int elem)
{
    //first we need to search the elem in the tree, 
    // if we get it then it lies in 3 cases
    //case 1: if the node has 2  child nodes
    //case 2: if the node has 1 child nodes
    //case 3: if the node has no nodes.
    
    //temp pointer 
    struct node *temp;
    
    //check if tree is empty
    if(Node==NULL)
    {
        cout<<"No such element in the tree.";
    }
    //check if the elem is in the left-subtree, if yes then go to left-subtree
    else if(elem<Node->data)
        Node->left=deletion(root->left,elem);
    else if(elem>Node->data)
        Node->right=deletion(Node->right,elem);
    else // if elem is found
    {
        //for node with 2 child nodes
        if(Node->left && Node->right)
        {
            //find the max elem from Node->left., and assign that in the place of node.
            temp=Find_max(root->left);     
            Node->data=temp->data;
            //now i have to delete the max elem we returned from left
            Node->left=deletion(Node->left,root->data);
        }
        //for node with 1 or no child
        else
        {
            //check if nodes right is NULL, then assign nodes left val in node
            temp=Node;
            if(Node->right==NULL)
            {
                Node=Node->left;
            }
            else if(Node->left==NULL)
            {
                Node=Node->right;
            }
            free(temp);
        }
        
    }
    return (Node);
}

//display
void display(struct node *Node)
{
    int choice;
    cout<<"Press 1.Inorder   2.Preorder   3.Postorder.\nEnter: ";
    cin>>choice;
    switch(choice)
    {
        case 1:inorder(Node); break;
        case 2:preorder(Node); break;
        case 3:postorder(Node); break;
        default: cout<<"Invalid Choice!\n"; display(Node); break;
    }
}

//inorder
void inorder(struct node *Node)
{
    if(Node==NULL)
      return;
    inorder(Node->left);
    cout<<Node->data<<" ";
    inorder(Node->right);
}

//preorder
void preorder(struct node *Node)
{
    if(Node==NULL)
      return;
    cout<<Node->data<<" ";
    inorder(Node->left);
    inorder(Node->right);
}

//postorder
void postorder(struct node *Node)
{
    if(Node==NULL)
      return;
    inorder(Node->left);
    inorder(Node->right);
    cout<<Node->data<<" ";
}

//find_max function
struct node *Find_max(struct node *Node)
{
    if(Node->right!=NULL)
      Node=Node->right;
    return Node;
}
