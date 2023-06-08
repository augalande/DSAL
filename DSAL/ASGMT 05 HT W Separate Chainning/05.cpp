/*
Implement all the functions of a dictionary (ADT) using hashing and handle
collisions using separate chaining using linked list
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, and Keys must be unique. Standard Operations: Insert(key, value),
Find(key), Delete(key)
*/
#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;

class node
{
    public:
    string key;
    string value;
    node* next;

    node(string k,string v)
    {
        key=k;
        value=v;
        next=NULL;
    }
};

class sll
{
    public:
    node* head;
    node* tail;

    sll()
    {
        head=NULL;
        tail=NULL;
    }

    void insert_sll(string k,string v);
    void display_sll();
    bool search_sll(string k);
    void delete_sll(string k);
    
};

void sll::insert_sll(string k,string v)
{
    node* temp=new node(k,v);
    if(head==NULL && tail==NULL)
    {
        head=tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void sll::display_sll()
{
    node* temp;
    temp=head;
    while(temp)
    {
        cout<<temp->key<<"-"<<temp->value<<" ";
        temp=temp->next;
    }
}

bool sll::search_sll(string k)
{
    node* temp;
    temp=head;
    while(temp)
    {
        if(temp->key==k)
        {
            cout<<temp->key<<"-"<<temp->value<<endl;
            return true;
        }
        temp=temp->next;
    }
    cout<<k<<" not found !!"<<endl;
    return false;
}

void sll::delete_sll(string k)
{
    if(search_sll(k))
    {
        if(head->key==k)  // If first node is to be deleted
        {
            node*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        else  // If last or any middle node is to be deleted
        {
            node* curr=head;
            node* prev=NULL;

            while(curr->key!=k)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            
        }

    }
    else
    {
        cout<<k<<" not found!!"<<endl;
    }

}

class HashTable
{
    public:
    sll s;

    void insert_HT(string k,string v);
    int Hash(string k);
    void display_HT();
    void search_HT(string k);
    void delete_HT(string k);
} HT[10];

void HashTable::insert_HT(string k,string v)
{
    int index=Hash(k);
    HT[index].s.insert_sll(k,v);
}

void HashTable::display_HT()
{
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Index"<<setw(25)<<"Word-Meaning"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<i<<"\t\t";
        HT[i].s.display_sll();
        cout<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}

void HashTable::search_HT(string k)
{
    int index=Hash(k);
    HT[index].s.search_sll(k);
}

void HashTable::delete_HT(string k)
{
    int index=Hash(k);
    HT[index].s.delete_sll(k);
}

int HashTable::Hash(string k)
{
    int ascii=0;
    for(int i=0;i<k.length();i++)
    {
        ascii+=(int)k[i];
    }
    return (ascii%10);
}


int main()
{
    HashTable HT;
    string word,meaning;


    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"DICTIONARY"<<endl;
        cout<<"1) Insert in Dictionary"<<endl;
        cout<<"2) Display Dictionary"<<endl;
        cout<<"3) Search in Dictionary"<<endl;
        cout<<"4) Delete in Dictionary"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"Enter Word :"<<endl;
                cin>>word;
                cout<<"Enter Meaning :"<<endl;
                cin>>meaning;
                HT.insert_HT(word,meaning);
                cout<<"Sucessfully inserted Word and Meaning in Dictionary !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                HT.display_HT();
                break;
            }

            case 3:
            {
                cout<<"Enter Word to be searched :"<<endl;
                cin>>word;
                HT.search_HT(word);
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                cout<<"Enter Word to be deleted :"<<endl;
                cin>>word;
                HT.delete_HT(word);  
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
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
1  
Enter Word :
abc
Enter Meaning :
x    
Sucessfully inserted Word and Meaning in Dictionary !!
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter Word :
bca
Enter Meaning :
y
Sucessfully inserted Word and Meaning in Dictionary !!
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter Word :
cab
Enter Meaning :
z
Sucessfully inserted Word and Meaning in Dictionary !!
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
2
----------------------------------------------------
Index             Word-Meaning
0
1
2
3
4               abc-x bca-y cab-z 
5
6
7
8
9
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter Word :
pqr
Enter Meaning :
w
Sucessfully inserted Word and Meaning in Dictionary !!
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
2
----------------------------------------------------
Index             Word-Meaning
0
1
2
3
4               abc-x bca-y cab-z 
5
6
7
8
9               pqr-w 
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
3
Enter Word to be searched :
bca
bca-y
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
3
Enter Word to be searched :
vfd
vfd not found !!
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Word to be deleted :
pqr
pqr-w
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
2
----------------------------------------------------
Index             Word-Meaning
0
1
2
3
4               abc-x bca-y cab-z 
5
6
7
8
9
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Word to be deleted :
bca
bca-y
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
2
----------------------------------------------------
Index             Word-Meaning
0
1
2
3
4               abc-x cab-z 
5
6
7
8
9
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Word to be deleted :
abc
abc-x
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
2
----------------------------------------------------
Index             Word-Meaning
0
1
2
3
4               cab-z 
5
6
7
8
9
----------------------------------------------------
----------------------------------------------------
DICTIONARY
1) Insert in Dictionary
2) Display Dictionary
3) Search in Dictionary
4) Delete in Dictionary
5) Exit
----------------------------------------------------
Enter your choice :
5
Exited sucessfully !!
----------------------------------------------------
*/