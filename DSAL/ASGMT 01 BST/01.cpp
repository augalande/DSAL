/*
Beginning with an empty binary search tree. Construct the binary
search tree by inserting the values in given order. After constructing
binary search tree perform following operations 
1) Insert a new node 
2)Find numbers of node in longest path 
3) Minimum and maximum data value found in tree 
4) Change a tree so that the roles of the left and right pointers are swapped at every node 
5)Search an element

Initial Binary Search Tree implemented is as follows :-
                        20
                    /         \
                   10         30
                 /    \     /    \
                5     15   25    35
               /
              3
             /
            2                    
*/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d=0)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

class bst
{
    public:
    node* root;
    int leafnode;
    int leaf[10];

    bst()
    {
        node* t1=new node(20);
        root=t1;
        leafnode=0;
    }

    void insert_node(int d,node* &r);
    void display_inorder(node* &r);
    void display_preorder(node* &r);
    void display_postorder(node* &r);
    int min_value(node* &r);
    int max_value(node* &r);
    void traversal(node* &r);
    int search_node(int d, node* &r);
    void longest_path();
    void swap_tree(node* &r);
};

void bst::insert_node(int d,node* &r)
{
    if(r==NULL)
    {
        node* t1=new node(d);
        r=t1;
        return;
    }

    if(d>r->data)
    {
        insert_node(d,r->right);
    }
    else
    {
        insert_node(d,r->left);
    }
}

void bst::display_inorder(node* &r)
{
    if(r==NULL)
    {
        return;
    }

    display_inorder(r->left);
    cout<<r->data<<" ";
    display_inorder(r->right);
}

void bst::display_preorder(node* &r)
{
    if(r==NULL)
    {
        return;
    }

    cout<<r->data<<" ";
    display_preorder(r->left);
    display_preorder(r->right);
}

void bst::display_postorder(node* &r)
{
    if(r==NULL)
    {
        return;
    }

    display_postorder(r->left);
    display_postorder(r->right);
    cout<<r->data<<" ";
}

int bst::min_value(node* &r)
{
    node* t1=r;

    while(t1->left!=NULL)
    {
        t1=t1->left;
    }

    return t1->data;
}

int bst::max_value(node* &r)
{
    node* t1=r;

    while(t1->right!=NULL)
    {
        t1=t1->right;
    }

    return t1->data;
}

void bst::traversal(node* &r)
{
    if(r==NULL)
    {
        return;
    }

    if((r->left==NULL) && (r->right==NULL))
    {
        leaf[leafnode]=r->data;
        leafnode++;
    }

    traversal(r->left);
    traversal(r->right);

}

int bst::search_node(int d, node* &r)
{
    node* t1=r;
    int l=0;

    while(t1!=NULL)
    {
        if(t1->data==d)
        {
            return l;
        }
        else if(t1->data>d)
        {
            l++;
            t1=t1->left;
        }
        else
        {
            l++;
            t1=t1->right;
        }
    }

    return -1;
}

void bst::longest_path()
{
    traversal(root);

    int path[leafnode];

    for(int i=0;i<leafnode;i++)
    {
        path[i]=search_node(leaf[i],root);
    }

    int max_no=0;

    for(int i=0;i<leafnode;i++)
    {
        if(path[i]>max_no)
        {
            max_no=path[i];
        }
    }

    cout<<"Number of Nodes in the Longest Path in BST : "<<(max_no+1)<<endl;
}

void bst::swap_tree(node* &r)
{
    node* t1=r;

    if(t1!=NULL)
    {
        if(t1->left || t1->right)
        {
            node* temp=t1->left;
            t1->left=t1->right;
            t1->right=temp;
        }

        swap_tree(t1->left);
        swap_tree(t1->right);
    }
}

int main()
{
    bst b;
    b.insert_node(10,b.root);
    b.insert_node(30,b.root);
    b.insert_node(5,b.root);
    b.insert_node(15,b.root);
    b.insert_node(25,b.root);
    b.insert_node(35,b.root);
    b.insert_node(3,b.root);
    b.insert_node(2,b.root);

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Binary Search Tree"<<endl;
        cout<<"1) Insert Node in BST"<<endl;
        cout<<"2) Display Inorder Traversal"<<endl;
        cout<<"3) Display Preorder Traversal"<<endl;
        cout<<"4) Display Postorder Traversal"<<endl;
        cout<<"5) Minimum Value in BST"<<endl;
        cout<<"6) Maximum Value in BST"<<endl;
        cout<<"7) Search Node in BST"<<endl;
        cout<<"8) Number of Nodes in Longest Path in BST"<<endl;
        cout<<"9) Swap BST"<<endl;
        cout<<"10) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"Enter Data :"<<endl;
                int d;
                cin>>d;
                b.insert_node(d,b.root);
                cout<<"Node "<<d<<" sucessfully inserted !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                cout<<"Inorder Traversal :"<<endl;
                b.display_inorder(b.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 3:
            {
                cout<<"Preorder Traversal :"<<endl;
                b.display_preorder(b.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                cout<<"Postorder Traversal :"<<endl;
                b.display_postorder(b.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 5:
            {
                cout<<"Minimum Value in BST :"<<endl;
                int x=b.min_value(b.root);
                cout<<x<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 6:
            {
                cout<<"Maximum Value in BST :"<<endl;
                int y=b.max_value(b.root);
                cout<<y<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 7:
            {
                cout<<"Enter Node to be searched :"<<endl;
                int d;
                cin>>d;
                int z=b.search_node(d,b.root);
                if(z==-1)
                {
                    cout<<"Node "<<d<<" was not found !!"<<endl; 
                }
                else
                {
                    cout<<"Node "<<d<<" found at level "<<z<<endl;
                }
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 8:
            {
                b.longest_path();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 9:
            {
                b.swap_tree(b.root);
                cout<<"BST Swapped sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;

            }

            case 10:
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
