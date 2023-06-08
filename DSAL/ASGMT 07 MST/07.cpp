/*
You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of
money to connect different pairs of cities. You want a set of lines that connects all
your offices with a minimum total cost. Solve the problem by suggesting
appropriate data structures.
*/

#include<iostream>
#include<climits>
using namespace std;

class graph
{
    public:
    int ver;
    int edg;
    int** adjmat;
    int min_cost;

    graph(int v,int e)
    {
        ver=v;
        edg=e;
        adjmat=new int *[v];
        min_cost=0;

        for(int i=0;i<ver;i++)
        {
            adjmat[i]=new int [ver];
            for(int j=0;j<ver;j++)
            {
                adjmat[i][j]=0;
            }
        }
    }

    void add_edge(int u,int v,int wt);
    void display_adjmat();
    int min_weight( int* weight,bool* visited);
    void prims();
    void display_mst(int* parent);
    void display_mincost();
};

void graph::add_edge(int u,int v,int wt)
{
    adjmat[u][v]=wt;
    adjmat[v][u]=wt;
}

void graph::display_adjmat()
{
    for(int i=0;i<ver;i++)
    {
        cout<<"\t\t"<<i;
    }

    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;

    for(int i=0;i<ver;i++)
    {
        cout<<i<<"|\t\t";
        for(int j=0;j<ver;j++)
        {
            cout<<adjmat[i][j]<<"\t\t";
        }
        cout<<endl;
    }
}

void graph::prims()
{
    int* parent=new int (ver);
    int* weight=new int (ver);
    bool* visited=new bool (ver);

    for(int i=0;i<ver;i++)
    {
        parent[i]=-1;
        weight[i]=INT_MAX;
        visited[i]=false;
    }

    weight[0]=0; //Imp Step

    for(int i=0;i<ver-1;i++)
    {
        int u=min_weight(weight,visited);

        visited[u]=true;

        for(int v=0;v<ver;v++)
        {
            if(adjmat[u][v]!=0 && visited[v]==false && adjmat[u][v]<weight[v])
            {
                parent[v]=u;
                weight[v]=adjmat[u][v];
            }
        }
    }
    display_mst(parent);
}

int graph::min_weight(int* weight,bool* visited)
{
    int min=INT_MAX;
    int min_index=-1;

    for(int i=0;i<ver;i++)
    {
        if(visited[i]==false && weight[i]<min)
        {
            min=weight[i];
            min_index=i;
        }
    }
    return min_index;
}

void graph::display_mst(int* parent)
{
    int sum=0;
    cout<<"The Minimum Spanning Tree is as follows : "<<endl;
    for(int i=1;i<ver;i++)
    {
        cout<<i<<"-"<<parent[i]<<" :"<<adjmat[i][parent[i]]<<endl;
        sum+=adjmat[i][parent[i]];
    }
    min_cost=sum;
}

void graph::display_mincost()
{
    cout<<"Cost of Minimum Spanning Tree : "<<min_cost<<endl;
}

int main()
{
    int v,e;
    cout<<"Enter Number of Vertices :"<<endl;
    cin>>v;
    cout<<"Enter Number of Edges :"<<endl;
    cin>>e;
    graph g(v,e);

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"MINIMUM SPANNING TREE"<<endl;
        cout<<"1) Add Edge"<<endl;
        cout<<"2) Display Adjacency Matrix"<<endl;
        cout<<"3) Display Minimum Spanning Tree"<<endl;
        cout<<"4) Display Cost of Minimum Spanning Tree"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                int s,d,wt;
                for(int i=0;i<g.edg;i++)
                {
                    cout<<"Edge "<<i<<endl;
                    cout<<"Enter Source :"<<endl;
                    cin>>s;
                    cout<<"Enter Destination :"<<endl;
                    cin>>d;
                    cout<<"Enter Weight :"<<endl;
                    cin>>wt;
                    g.add_edge(s,d,wt);
                }
                cout<<"Sucessfully added Telephone Lines(Edges) !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                cout<<"Adjacency Matrix is as follows :"<<endl;
                g.display_adjmat();
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 3:
            {
                cout<<"Minimum Spanning Tree is as follows :"<<endl;
                g.prims();
                cout<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                g.display_mincost();
                cout<<endl;
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

 //0 1 3 0 2 2 0 3 4 3 2 4 1 2 2 
 /*
 Enter Number of Vertices :
4
Enter Number of Edges :
5
----------------------------------------------------
MINIMUM SPANNING TREE
1) Add Edge
2) Display Adjacency Matrix
3) Display Minimum Spanning Tree
4) Display Cost of Minimum Spanning Tree
5) Exit
----------------------------------------------------
Enter your choice :
1
Edge 0
Enter Source :
0 1 3 0 2 2 0 3 4 3 2 4 1 2 2 
Enter Destination :
Enter Weight :
Edge 1
Enter Source :
Enter Destination :
Enter Weight :
Edge 2
Enter Source :
Enter Destination :
Enter Weight :
Edge 3
Enter Source :
Enter Destination :
Enter Weight :
Edge 4
Enter Source :
Enter Destination :
Enter Weight :
Sucessfully added Telephone Lines(Edges) !!
----------------------------------------------------
----------------------------------------------------
MINIMUM SPANNING TREE
1) Add Edge
2) Display Adjacency Matrix
3) Display Minimum Spanning Tree
4) Display Cost of Minimum Spanning Tree
5) Exit
----------------------------------------------------
Enter your choice :
2
Adjacency Matrix is as follows :
                0               1               2               3
----------------------------------------------------
0|              0               3               2               4
1|              3               0               2               0
2|              2               2               0               4
3|              4               0               4               0

----------------------------------------------------
----------------------------------------------------
MINIMUM SPANNING TREE
1) Add Edge
2) Display Adjacency Matrix
3) Display Minimum Spanning Tree
4) Display Cost of Minimum Spanning Tree
5) Exit
----------------------------------------------------
Enter your choice :
3
Minimum Spanning Tree is as follows :
The Minimum Spanning Tree is as follows : 
1-2 :2
2-0 :2
3-0 :4

----------------------------------------------------
----------------------------------------------------
MINIMUM SPANNING TREE
1) Add Edge
2) Display Adjacency Matrix
3) Display Minimum Spanning Tree
4) Display Cost of Minimum Spanning Tree
5) Exit
----------------------------------------------------
Enter your choice :
4
Cost of Minimum Spanning Tree : 8

----------------------------------------------------
----------------------------------------------------
MINIMUM SPANNING TREE
1) Add Edge
2) Display Adjacency Matrix
3) Display Minimum Spanning Tree
4) Display Cost of Minimum Spanning Tree
5) Exit
----------------------------------------------------
Enter your choice :
5
Exited sucessfully !!
----------------------------------------------------
 */