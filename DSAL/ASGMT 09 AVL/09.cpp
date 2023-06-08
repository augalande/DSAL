/*
A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to
display whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Height balance
tree and find the complexity for finding a keyword.
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class node
{
    public:
    string key;
    string mean;
    int ht;
    node* right;
    node* left;

    node(string k,string m)
    {
        key=k;
        mean=m;
        ht=1;
        right=NULL;
        left=NULL;
    }
};

class avl
{
    public:
    node* root;

    avl()
    {
        root=NULL;
    }

    int height(node* n)
    {
        if(n==NULL)
        {
            return 0;
        }
        return n->ht;
    }

    int balanceFactor(node* n)
    {
        if(n==NULL)
        {
            return 0;
        }
        return (height(n->left)-height(n->right));
    }

    node* Rrotate(node* r)
    {
        node* newr=r->left;
        r->left=newr->right;
        newr->right=r;

        r->ht=max(height(r->left),height(r->right))+1;
        newr->ht=max(height(newr->left),height(newr->right))+1;

        return newr;
    }

    node* Lrotate(node* r)
    {
        node* newr=r->right;
        r->right=newr->left;
        newr->left=r;

        r->ht=max(height(r->left),height(r->right))+1;
        newr->ht=max(height(newr->left),height(newr->right))+1;

        return newr;
    }

    node* insert(node* r,string k,string m)
    {
        if(r==NULL)
        {
            node* newnode=new node(k,m);
            return newnode;
        }
        if(k<r->key)
        {
            r->left=insert(r->left,k,m);
        }
        else
        {
            r->right=insert(r->right,k,m);
        }

        r->ht=max(height(r->left),height(r->right))+1;
        int bf=balanceFactor(r);

        //LL
        if(bf==2 && k<r->left->key)
        {
            return Rrotate(r);
        }

        //RR
        if(bf==-2 && r->right->key<k)
        {
            return Lrotate(r);
        }

        //LR
        if(bf==2 && k>r->left->key)
        {
            r->left=Lrotate(r->left);
            return Rrotate(r);
        }

        //RL
        if(bf==-2 && r->right->key>k)
        {
            r->right=Rrotate(r->right);
            return Lrotate(r);
        }

        return r;
    }

    node* search(string s)
    {
        node* temp=root;
        while(temp)
        {
            if(temp->key==s)
            {
                return temp;
            }
            else if(s<temp->key)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        return NULL;
    }

    int comparisons(string s)
    {
        int count=0;
        node* temp=root;

        while(temp)
        {
            count++;

            if(temp->key==s)
            {
                return count;
            }
            else if(s<temp->key)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        return -1;
    }

        void display_inorder(node* r)
    {
        if(r==NULL)
        {
            return;
        }

        display_inorder(r->left);
        cout<<r->key<<"-"<<r->mean<<" ";
        display_inorder(r->right);
    }

    void display_preorder(node* r)
    {
        if(r==NULL)
        {
            return;
        }

        cout<<r->key<<"-"<<r->mean<<" ";
        display_preorder(r->left);
        display_preorder(r->right);
    }

    void display_postorder(node* r)
    {
        if(r==NULL)
        {
            return;
        }

        display_postorder(r->left);
        display_postorder(r->right);
        cout<<r->key<<"-"<<r->mean<<" ";
    }

    void display_ascending(node* r)
    {
        if(r==NULL)
        {
            return;
        }

        display_inorder(r->left);
        cout<<r->key<<"-"<<r->mean<<" ";
        display_inorder(r->right);
    }

    void display_descending(node* r)
    {
        if(r==NULL)
        {
            return;
        }

        display_inorder(r->right);
        cout<<r->key<<"-"<<r->mean<<" ";
        display_inorder(r->left);
    }

    void update(string k,string newm)
    {
        node* temp=search(k);
        if(temp)
        {
            temp->mean=newm;
        }
        else
        {
            cout<<"Key "<<k<<" not found !!"<<endl;
        }
    }

    void add_node(string k,string m)
    {
        root=insert(root,k,m);
    }
};

int main()
{
    avl a;

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"AVL Tree"<<endl;
        cout<<"1) Insert Key-Meaning in AVL"<<endl;
        cout<<"2) Update Key-Meaning in AVL"<<endl;
        cout<<"3) Display AVL"<<endl;
        cout<<"4) Search in AVL"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                int n;
                cout<<"Enter number of Key-Meaning you want to enter: "<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    string key,mean;
                    cout<<"Enter Key :"<<endl;
                    cin>>key;
                    cout<<"Enter Meaning :"<<endl;
                    cin>>mean;
                    a.add_node(key,mean);
                }
                cout<<"Sucessfully inserted Key-Meaning in AVL !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                cout<<"Enter Key to be updated :"<<endl;
                string key;
                cin>>key;
                cout<<"Enter New Meaning :"<<endl;
                string newm;
                cin>>newm;

                a.update(key,newm);

                cout<<"Sucessfully updated Key-Meaning in AVL !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;

                break;
            }

            case 3:
            {
                cout<<"Inorder Traversal :"<<endl;
                a.display_inorder(a.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;

                cout<<"Preorder Traversal :"<<endl;
                a.display_preorder(a.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;

                cout<<"Postorder Traversal :"<<endl;
                a.display_postorder(a.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;

                cout<<"Ascending Order :"<<endl;
                a.display_ascending(a.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;

                cout<<"Descending Order :"<<endl;
                a.display_descending(a.root);
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;

                break;
            }

            case 4:
            {
                string key;
                cout<<"Enter Key to be searched : "<<endl;
                cin>>key;
                node* temp=a.search(key);
                int x=a.comparisons(key);

                if(temp)
                cout<<temp->key<<"-"<<temp->mean<<endl;
                else
                cout<<"Key "<<key<<" not found !!"<<endl;

                if(x!=-1)
                cout<<"Comparisons required to search key : "<<x<<endl;
                else
                cout<<"Key "<<key<<" not found !!"<<endl;

                cout<<"----------------------------------------------------"<<endl;              
                break;
            }

            case 5:
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

/*
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter number of Key-Meaning you want to enter: 
3
Enter Key :
30
Enter Meaning :
f
Enter Key :
20
Enter Meaning :
d
Enter Key :
10
Enter Meaning :
a
Sucessfully inserted Key-Meaning in AVL !!
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
3
Inorder Traversal :
10-a 20-d 30-f 
----------------------------------------------------
Preorder Traversal :
20-d 10-a 30-f 
----------------------------------------------------
Postorder Traversal :
10-a 30-f 20-d 
----------------------------------------------------
Ascending Order :
10-a 20-d 30-f 
----------------------------------------------------
Descending Order :
30-f 20-d 10-a 
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
2
Enter Key to be updated :
10
Enter New Meaning :
b
Sucessfully updated Key-Meaning in AVL !!
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
3
Inorder Traversal :
10-b 20-d 30-f 
----------------------------------------------------
Preorder Traversal :
20-d 10-b 30-f 
----------------------------------------------------
Postorder Traversal :
10-b 30-f 20-d 
----------------------------------------------------
Ascending Order :
10-b 20-d 30-f 
----------------------------------------------------
Descending Order :
30-f 20-d 10-b 
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Key to be searched : 
20
20-d
Comparisons required to search key : 1
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Key to be searched : 
10
10-b
Comparisons required to search key : 2
----------------------------------------------------
----------------------------------------------------
AVL Tree
1) Insert Key-Meaning in AVL
2) Update Key-Meaning in AVL
3) Display AVL
4) Search in AVL
5) Exit
----------------------------------------------------
Enter your choice :
5
Exited sucessfully !!
----------------------------------------------------
*/

/*
#include <iostream>
#include <string>
using namespace std;

class node
{
    string key;
    string mean;
    node *right;
    node *left;
    int ht;
    friend class AVLtree;

public:
    node(string k, string m)
    {
        this->key = k;
        this->mean = m;
        this->right = NULL;
        this->left = NULL;
        this->ht = 1;
    }
};

class AVLtree
{

public:
    node *root;
    AVLtree()
    {
        this->root = NULL;
    }

    int height(node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        return n->ht;
    }

    node *Rrotate(node *r)
    {
        node *newr = r->left;
        r->left = newr->right;
        newr->right = r;
        r->ht = max(height(r->left), height(r->right)) + 1;
        newr->ht = max(height(newr->left), height(newr->right)) + 1;
        return newr;
    }

    node *Lrotate(node *r)
    {
        node *newr = r->right;
        r->right = newr->left;
        newr->left = r;
        r->ht = max(height(r->left), height(r->right)) + 1;
        newr->ht = max(height(newr->left), height(newr->right)) + 1;
        return newr;
    }

    int BalanceFactor(node *r)
    {
        if (r == NULL)
        {
            return 0;
        }
        return height(r->left) - height(r->right);
    }

    node *insert(node *r, string k, string m)
    {
        if (r == NULL)
        {
            node *newnode = new node(k, m);
            return newnode;
        }
        if (k < r->key)
        {
            r->left = insert(r->left, k, m);
        }
        else if (k > r->key)
        {
            r->right = insert(r->right, k, m);
        }
        else
        {
            return r;
        }

        r->ht = max(height(r->left), height(r->right)) + 1;
        int bf = BalanceFactor(r);

        // LL
        if (bf == 2 && k < r->left->key)
        {
            return Rrotate(r);
        }

        // RR
        if (bf == -2 && k > r->right->key)
        {
            return Lrotate(r);
        }

        // LR
        if (bf == 2 && k > r->left->key)
        {
            r->left = Lrotate(r->left);
            return Rrotate(r);
        }

        // RL
        if (bf == -2 && k < r->right->key)
        {
            r->right = Rrotate(r->right);
            return Lrotate(r);
        }

        return r;
    }

    node *minNode(node *r)
    {
        node *temp = r;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    node *deletion(node *r, string k)
    {
        if (r == NULL)
        {
            return r;
        }
        if (k < r->key)
        {
            r->left = deletion(r->left, k);
        }
        else if (k > r->key)
        {
            r->right = deletion(r->right, k);
        }
        else
        {
            if (r->left == NULL || r->right == NULL)
            {
                node *temp;
                if (r->left)
                {
                    temp = r->left;
                }
                else
                {
                    temp = r->right;
                }
                if (temp == NULL)
                {
                    temp = r;
                    r = NULL;
                }
                else
                {
                    root->key = temp->key;
                }
                delete temp;
            }
            else
            {
                node *min = minNode(r->right);
                r->key = min->key;
                r->mean = min->mean;
                r->right = deletion(r->right, min->key);
            }
        }

        if (r == NULL)
        {
            return r;
        }

        r->ht = max(height(r->left), height(r->right)) + 1;
        int bf = BalanceFactor(r);

        // LL
        if (bf == 2 && BalanceFactor(r->left) > 0)
        {
            return Rrotate(r);
        }

        // RR
        if (bf == -2 && BalanceFactor(r->right) <= 0)
        {
            return Lrotate(r);
        }

        // LR
        if (bf == 2 && BalanceFactor(r->right) < 0)
        {
            r->left = Lrotate(r->left);
            return Rrotate(r);
        }

        // RL
        if (bf == -2 && BalanceFactor(r->right) > 0)
        {
            r->right = Rrotate(r->right);
            return Lrotate(r);
        }

        return r;
    }

    node *search(string s)
    {
        node *temp = root;
        while (temp != NULL)
        {
            if (temp->key == s)
            {
                return temp;
            }
            else if (temp->key > s)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }

    int cmp(string s)
    {
        node *temp = root;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            if (temp->key == s)
            {
                return count;
            }
            else if (temp->key > s)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        return -1;
    }

    void update(string k, string newm)
    {
        node *temp = search(k);
        temp->mean = newm;
    }

    void inorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        inorder(r->left);
        cout << r->key << "   :" << r->mean << endl;
        inorder(r->right);
    }

    void descending(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        descending(r->right);
        cout << r->key << "   :" << r->mean << endl;
        descending(r->left);
    }

    void preorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->key << "   :" << r->mean << endl;
        preorder(r->left);
        preorder(r->right);
    }
    void postorder(node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->key << "   :" << r->mean << endl;
        postorder(r->left);
        postorder(r->right);
    }
    void addNode(string k, string m)
    {
        root = insert(root, k, m);
    }
    void deleNode(string n)
    {
        root = deletion(root, n);
    }
};

int main()
{
    AVLtree a;
    int n;
    string k, m;
    while (true)
    {
        cout << "Choose the following" << endl;
        cout << "1. Add word" << endl;
        cout << "2. Delete word" << endl;
        cout << "3. Update meaning" << endl;
        cout << "4. Display" << endl;
        cout << "5. Search a word" << endl;
        cout << "6. Exit" << endl;
        int opt;
        cout << "Enter your choice : ";
        cin >> opt;
        cout << endl;
        switch (opt)
        {
        case 1:
            cout << "Enter the no. of words to add :";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                string word, meaning;
                cout << "Enter the word : ";
                cin >> word;
                cout << "Enter it's meaning : ";
                cin >> meaning;
                a.addNode(word, meaning);
            }
            cout << endl;
            break;
        case 2:
            cout << "Enter the word to delete : ";
            cin >> k;
            a.deleNode(k);
            cout << endl;
            cout << "Word deleted " << endl;
            cout << endl;
            break;
        case 3:
            cout << "Enter the word to update : ";
            cin >> k;
            cout << "Entet it's new meaning : ";
            cin >> m;
            a.update(k, m);
            cout << endl;
            break;
        case 4:
            cout << "a. Ascending " << endl;
            cout << "b. Descending " << endl;
            cout << "c .Preorder" << endl;
            cout << "d. Postorder " << endl;
            cout << "Enter your choice : ";
            cin >> k;

            if (k == "a")
            {
                cout << "Ascending : " << endl;
                cout << "Word "
                     << "Meaning " << endl;
                a.inorder(a.root);
            }
            else if (k == "b")
            {
                cout << "Descending : " << endl;
                cout << "Word "
                     << "Meaning " << endl;
                a.descending(a.root);
            }
            else if (k == "c")
            {
                cout << "Preorder : " << endl;
                cout << "Word "
                     << "Meaning " << endl;
                a.preorder(a.root);
            }
            else if (k == "d")
            {
                cout << "Postorder :" << endl;
                cout << "Word "
                     << "Meaning " << endl;
                a.postorder(a.root);
            }
            cout << endl;
            break;
        case 5:
            cout << "Enter the word to search :";
            cin >> k;
            n = a.cmp(k);
            if (n == -1)
            {
                cout << "Word is not present" << endl;
            }
            else
            {
                cout << "No. of comparisons required : " << n << endl;
                cout << endl;
            }
            cout<<endl;
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}
*/