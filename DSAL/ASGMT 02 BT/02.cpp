/*
Beginning with an empty binary tree, Construct binary tree by inserting
the values in the order given. After constructing a binary tree perform
following operations on it-
 Perform in order / pre order and post order traversal
 Change a tree so that the roles of the left and right pointers are
swapped at every node
 Find the height of tree
 Copy this tree to another [operator=]
 Count number of leaves, number of internal nodes.
 Erase all nodes in a binary tree.
(implement both recursive and non-recursive methods)f
*/

#include<iostream>
#include<stack>
using namespace std;

class node
{
    public :
    int data;
    node* right;
    node* left;

    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};

class bt
{
    public:

    node* root;

    bt()
    {
        root=create_bt(root);
    }

    node* create_bt(node* root);

    void rinorder(node* root);
    void rpreorder(node* root);
    void rpostorder(node* root);

    void iinorder(node* root);
    void ipreorder(node* root);
    void ipostorder(node* root);

    int maxDepth(node* root);
    int getLeaf(node* root);
    int getInternal(node* root);

    void swap(node* root);
    node* clone(node* root);
    void delete_bt(node* root);
};

node* bt::create_bt(node* root)
{
    int d;
    cout<<"Enter Data (-1 to stop) :"<<endl;
    cin>>d;
    root=new node(d);

    if(d==-1)
    {
        return NULL;
    }

    cout<<"Enter Data to left of "<<d<<endl;
    root->left=create_bt(root->left);
    cout<<"Enter Data to right of "<<d<<endl;
    root->right=create_bt(root->right);

    return root;
}

void bt::rinorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    rinorder(root->left);
    cout<<root->data<<" ";
    rinorder(root->right);
}

void bt::rpreorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    rpreorder(root->left);
    rpreorder(root->right);
}

void bt::rpostorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    rpostorder(root->left);
    rpostorder(root->right);
    cout<<root->data<<" "; 
}

int bt::maxDepth(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int ldepth=maxDepth(root->left);
        int rdepth=maxDepth(root->right);

        if(ldepth>rdepth)
        {
            return (ldepth+1);
        }
        else
        {
            return (rdepth+1);
        }
    }
}

void bt::swap(node* root)
{
    if(root)
    {
        if(root->left||root->right)
        {
            node* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        swap(root->left);
        swap(root->right);
    }
}

int bt::getLeaf(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        return getLeaf(root->left)+getLeaf(root->right);
    }
}

int bt::getInternal(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return 0;
    }
    else
    {
        return (1+getInternal(root->left)+getInternal(root->right));
    }
}

node* bt::clone(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    node* root_copy=new node(root->data);

    root_copy->left=clone(root->left);
    root_copy->right=clone(root->right);

    return root_copy;
}

void bt::delete_bt(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    delete_bt(root->left);
    delete_bt(root->right);

    cout<<"Deleting Node : "<<root->data<<" ";
    delete root;
}

void bt::iinorder(node *root)
{
    if(root==NULL)
    {
        return;
    }

    stack<node*> s;
    node* curr=root;

    while(!s.empty() or curr!=NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }

        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}

void bt::ipreorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*> s;
    node* curr=root;
    s.push(curr);

    while(!s.empty())
    {
        curr=s.top();
        cout<<curr->data<<" ";
        s.pop();

        if(curr->right)
        {
            s.push(curr->right);
        }
        if(curr->left)
        {
            s.push(curr->left);
        }
    }
}

void bt::ipostorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    stack<node*> s1,s2;
    node* curr=root;
    s1.push(curr);

    while(!s1.empty())
    {
        curr=s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left)
        {
            s1.push(curr->left);
        }
        if(curr->right)
        {
            s1.push(curr->right);
        }
    }

    while(!s2.empty())
    {
        curr=s2.top();
        cout<<curr->data<<" ";
        s2.pop();
    }
}

int main()
{
    bt b;

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Binary Tree"<<endl;
        cout<<"1) Recursive Traversals"<<endl;
        cout<<"2) Iterative Traversals"<<endl;
        cout<<"3) Swap BT"<<endl;
        cout<<"4) Maximum Depth of BT"<<endl;
        cout<<"5) Number of Leaf Nodes"<<endl;
        cout<<"6) Number of Internal Nodes"<<endl;
        cout<<"7) Delete All Nodes in BT"<<endl;
        cout<<"8) Clone BT"<<endl;
        cout<<"9) Exit"<<endl;
       
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"RPreorder Traversal :"<<endl;
                b.rpreorder(b.root);
                cout<<endl;
                cout<<"RInorder Traversal :"<<endl;
                b.rinorder(b.root);
                cout<<endl;
                cout<<"RPostorder Traversal :"<<endl;
                b.rpostorder(b.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                cout<<"IPreorder Traversal :"<<endl;
                b.ipreorder(b.root);
                cout<<endl;
                cout<<"IInorder Traversal :"<<endl;
                b.iinorder(b.root);
                cout<<endl;
                cout<<"IPostorder Traversal :"<<endl;
                b.ipostorder(b.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 3:
            {
                b.swap(b.root);
                cout<<"BT Swapped sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                cout<<"Maximum Depth of BT :"<<endl;
                int d=b.maxDepth(b.root);
                cout<<d;
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 5:
            {
                cout<<"Number of Leaf Nodes in BT :"<<endl;
                int l=b.getLeaf(b.root);
                cout<<l;
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 6:
            {
                cout<<"Number of Internal Nodes in BT :"<<endl;
                int i=b.getLeaf(b.root);
                cout<<i;
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 7:
            {
                b.delete_bt(b.root);
                cout<<"All Nodes in BT deleted sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 8:
            {
                node* new_root=b.clone(b.root);

                cout<<"RPreorder Traversal :"<<endl;
                b.rpreorder(new_root);
                cout<<endl;
                cout<<"RInorder Traversal :"<<endl;
                b.rinorder(new_root);
                cout<<endl;
                cout<<"RPostorder Traversal :"<<endl;
                b.rpostorder(new_root);
                cout<<endl;
               
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 9:
            {
                cout<<"Exited sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                exit(0);
                break;
            }
            
            default:
            {
                cout<<"Enter valid choice !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
            }
        }  
    }
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

/*
                        1
                    /         \
                   3          5
                 /    \     /    
                7     11   17    
                       
*/


/*
Enter Data (-1 to stop) :
1
Enter Data to left of 1
Enter Data (-1 to stop) :
3
Enter Data to left of 3
Enter Data (-1 to stop) :
7
Enter Data to left of 7
Enter Data (-1 to stop) :
-1
Enter Data to right of 7
Enter Data (-1 to stop) :
-1
Enter Data to right of 3
Enter Data (-1 to stop) :
11
Enter Data to left of 11
Enter Data (-1 to stop) :
-1
Enter Data to right of 11
Enter Data (-1 to stop) :
-1
Enter Data to right of 1
Enter Data (-1 to stop) :
5
Enter Data to left of 5
Enter Data (-1 to stop) :
17
Enter Data to left of 17
Enter Data (-1 to stop) :
-1
Enter Data to right of 17
Enter Data (-1 to stop) :
-1
Enter Data to right of 5
Enter Data (-1 to stop) :
-1
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
1
RPreorder Traversal :
1 3 7 11 5 17 
RInorder Traversal :
7 3 11 1 17 5 
RPostorder Traversal :
7 11 3 17 5 1 
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
2
IPreorder Traversal :
1 3 7 11 5 17 
IInorder Traversal :
7 3 11 1 17 5 
IPostorder Traversal :
7 11 3 17 5 1 
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
4
Maximum Depth of BT :
3
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
5
Number of Leaf Nodes in BT :
3
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
6
Number of Internal Nodes in BT :
3
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
8
RPreorder Traversal :
1 3 7 11 5 17 
RInorder Traversal :
7 3 11 1 17 5 
RPostorder Traversal :
7 11 3 17 5 1 
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
3
BT Swapped sucessfully !!
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
1
RPreorder Traversal :
1 5 17 3 11 7 
RInorder Traversal :
5 17 1 11 3 7 
RPostorder Traversal :
17 5 11 7 3 1 
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
7
Deleting Node : 17 Deleting Node : 5 Deleting Node : 11 Deleting Node : 7 Deleting Node : 3 Deleting Node : 1 All Nodes in BT deleted sucessfully !!
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
1
RPreorder Traversal :
0 
RInorder Traversal :
0 
RPostorder Traversal :
0 
----------------------------------------------------
----------------------------------------------------
Binary Tree
1) Recursive Traversals
2) Iterative Traversals
3) Swap BT
4) Maximum Depth of BT
5) Number of Leaf Nodes
6) Number of Internal Nodes
7) Delete All Nodes in BT
8) Clone BT
9) Exit
----------------------------------------------------
Enter your choice :
9
Exited sucessfully !!
----------------------------------------------------
*/
