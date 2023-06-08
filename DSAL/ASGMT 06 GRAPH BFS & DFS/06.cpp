/*
Represent a given graph using adjacency list to perform DFS and BFS. Use the
map of the area around the college as the graph. Identify the prominent land marks
as nodes and perform DFS and BFS on that.
*/

#include<iostream>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

class node
{
    public:
    string name;
    node* next;

    node(string s)
    {
        name=s;
        next=NULL;
    }
};

class graph
{
    public:
    int size;
    node** arr;

    graph(int s)
    {
        size=s;
        arr=new node *[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=NULL;
        }
    }

    void create_graph();
    void display_graph();
    node* search_node(string s);
    int search_index(node* n);
    void bfs(string s);
    void dfs(string s);
};

void graph::create_graph()
{
    cout<<"Enter Landmarks:"<<endl;
    for(int i=0;i<size;i++)
    {
        string s;
        cout<<"Enter Landmark "<<i<<" :"<<endl;
        cin>>s;
        node* newnode=new node(s);
        arr[i]=newnode;
    }

    cout<<"Enter Adjancent Landmarks:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter number of Adjancent Landmarks for Landmark "<<i<<" "<<arr[i]->name<<" :"<<endl;
        int j;
        cin>>j;

        for(int k=0;k<j;k++)
        {
            string s;
            cout<<"Enter Adjancent Landmark "<<k<<" :"<<endl;
            cin>>s;
            node* t1=new node(s);
            node* t2=arr[i];

            while(t2->next)
            {
                t2=t2->next;
            }
            t2->next=t1;
        }
    }
}

void graph::display_graph()
{
    cout<<"Graph is as follows :"<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<i<<" "<<arr[i]->name<<"-> ";

        node* temp=arr[i]->next;

        while(temp)
        {
            cout<<temp->name<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

node* graph::search_node(string s)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]->name==s)
        {
            return arr[i];
        }
    }
    return NULL;
}

int graph::search_index(node* n)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==n)
        {
            return i;
        }
    }
    return -1;
}

void graph::bfs(string s)
{
    cout<<"BFS Traversal : ";

    queue<node*> q;
    bool visited[size];
    visited[size]={false};
    node* start=search_node(s);
    q.push(start);
    visited[search_index(start)]=true;

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<temp->name<<" ";
        temp=temp->next;

        while(temp)
        {
            if(visited[search_index(search_node(temp->name))]==false)
            {
                visited[search_index(search_node(temp->name))]=true;
                q.push(search_node(temp->name));
            }
            temp=temp->next;
        }
    }
    cout<<endl;
}

void graph::dfs(string s)
{
    cout<<"DFS Traversal : ";

    stack<node*> stk;
    bool visited[size];
    visited[size]={false};
    node* start=search_node(s);
    stk.push(start);
    visited[search_index(start)]=true;

    while(!stk.empty())
    {
        node* temp=stk.top();
        stk.pop();
        cout<<temp->name<<" ";
        temp=temp->next;

        while(temp)
        {
            if(visited[search_index(search_node(temp->name))]==false)
            {
                visited[search_index(search_node(temp->name))]=true;
                stk.push(search_node(temp->name));
            }
            temp=temp->next;
        }
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter number of Landmarks :"<<endl;
    int n;
    cin>>n;
    graph g(n);

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"BFS and DFS Traversal of Graph"<<endl;
        cout<<"1) Create Graph"<<endl;
        cout<<"2) Display Graph"<<endl;
        cout<<"3) BFS Traversal"<<endl;
        cout<<"4) DFS Traversal"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                g.create_graph();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                g.display_graph();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 3:
            {
                string s;
                cout<<"Enter Starting Landmark :"<<endl;
                cin>>s;
                g.bfs(s);
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                string s;
                cout<<"Enter Starting Landmark :"<<endl;
                cin>>s;
                g.dfs(s);
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
Enter number of Landmarks :
7
----------------------------------------------------
BFS and DFS Traversal of Graph
1) Create Graph
2) Display Graph
3) BFS Traversal
4) DFS Traversal
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter Landmarks:
Enter Landmark 0 :
a
Enter Landmark 1 :
b
Enter Landmark 2 :
c
Enter Landmark 3 :
d
Enter Landmark 4 :
e
Enter Landmark 5 :
f
Enter Landmark 6 :
g
Enter Adjancent Landmarks:
Enter number of Adjancent Landmarks for Landmark 0 a :
2
Enter Adjancent Landmark 0 :
b
Enter Adjancent Landmark 1 :
c
Enter number of Adjancent Landmarks for Landmark 1 b :
2
Enter Adjancent Landmark 0 :
d
Enter Adjancent Landmark 1 :
e
Enter number of Adjancent Landmarks for Landmark 2 c :
2
Enter Adjancent Landmark 0 :
f
Enter Adjancent Landmark 1 :
g
Enter number of Adjancent Landmarks for Landmark 3 d :
0
Enter number of Adjancent Landmarks for Landmark 4 e :
0
Enter number of Adjancent Landmarks for Landmark 5 f :
0
Enter number of Adjancent Landmarks for Landmark 6 g :
0
----------------------------------------------------
----------------------------------------------------
BFS and DFS Traversal of Graph
1) Create Graph
2) Display Graph
3) BFS Traversal
4) DFS Traversal
5) Exit
----------------------------------------------------
Enter your choice :
2
Graph is as follows :
0 a-> b c 
1 b-> d e 
2 c-> f g 
3 d-> 
4 e-> 
5 f-> 
6 g-> 
----------------------------------------------------
----------------------------------------------------
BFS and DFS Traversal of Graph
1) Create Graph
2) Display Graph
3) BFS Traversal
4) DFS Traversal
5) Exit
----------------------------------------------------
Enter your choice :
3
Enter Starting Landmark :
a
BFS Traversal : a b c d e f g 
----------------------------------------------------
----------------------------------------------------
BFS and DFS Traversal of Graph
1) Create Graph
2) Display Graph
3) BFS Traversal
4) DFS Traversal
5) Exit
----------------------------------------------------
Enter your choice :
4
Enter Starting Landmark :
a
DFS Traversal : a c g f b e d 
----------------------------------------------------
----------------------------------------------------
BFS and DFS Traversal of Graph
1) Create Graph
2) Display Graph
3) BFS Traversal
4) DFS Traversal
5) Exit
----------------------------------------------------
Enter your choice :
5
Exited sucessfully !!
----------------------------------------------------
*/



