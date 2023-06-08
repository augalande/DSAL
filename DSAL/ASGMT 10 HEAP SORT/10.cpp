/*
Implement the Heap sort algorithm demonstrating heap data structure with
modularity of programming language
*/

#include<iostream>
using namespace std;

class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        size=-1;
    }

    void input();
    void display();
    void heapify(int n,int i);
    void heapsort();
};

void heap::input()
{
    cout<<"Enter size of Heap :"<<endl;
    cin>>size;

    arr[0]=-1;
    cout<<"Enter elements in Heap :"<<endl;

    for(int i=1;i<=size;i++)
    {
        cin>>arr[i];
    }
}

void heap::display()
{
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heap::heapify(int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=(2*i)+1;

    if(left<=n && arr[largest]<arr[left]) // check bounds
    {
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])  // check bounds
    {
        largest=right;
    }

    if(largest!=i)
    {
        int temp;
        temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;

        heapify(n,largest);
    }
}

void heap::heapsort()
{
    int t=size;

    while(t>1)
    {
        int temp=arr[t];
        arr[t]=arr[1];
        arr[1]=temp;
        
        t--;

        heapify(t,1);
   }
}

int main()
{
    heap h;
    
     while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"HEAP SORT ALGORITHM USING MAX HEAP"<<endl;
        cout<<"1) Input Heap"<<endl;
        cout<<"2) Display Heap"<<endl;
        cout<<"3) Heapify"<<endl;
        cout<<"4) Heap Sort Algorithm"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                h.input();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                cout<<"Heap is as follows :"<<endl;
                h.display();
                break;
            }

            case 3:
            {
                for(int i=h.size/2;i>=1;i--)
                    {
                        h.heapify(h.size,i);
                    }
                cout<<"Heapified Heap is as follows :"<<endl;
                h.display();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                cout<<"Sorted Heap is as follows :"<<endl;
                h.heapsort();
                h.display();                                                                                                                                                                                 
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


// 5
// 54 53 55 52 50

/*
----------------------------------------------------
HEAP SORT ALGORITHM USING MAX HEAP
1) Input Heap
2) Display Heap
3) Heapify
4) Heap Sort Algorithm
5) Exit
----------------------------------------------------
Enter your choice :
1
Enter size of Heap :
5
Enter elements in Heap :
54 53 55 52 50
----------------------------------------------------
----------------------------------------------------
HEAP SORT ALGORITHM USING MAX HEAP
1) Input Heap
2) Display Heap
3) Heapify
4) Heap Sort Algorithm
5) Exit
----------------------------------------------------
Enter your choice :
2
Heap is as follows :
54 53 55 52 50 
----------------------------------------------------
HEAP SORT ALGORITHM USING MAX HEAP
1) Input Heap
2) Display Heap
3) Heapify
4) Heap Sort Algorithm
5) Exit
----------------------------------------------------
Enter your choice :
3
Heapified Heap is as follows :
55 53 54 52 50 
----------------------------------------------------
----------------------------------------------------
HEAP SORT ALGORITHM USING MAX HEAP
1) Input Heap
2) Display Heap
3) Heapify
4) Heap Sort Algorithm
5) Exit
----------------------------------------------------
Enter your choice :
4
Sorted Heap is as follows :
50 52 53 54 55 
----------------------------------------------------
----------------------------------------------------
HEAP SORT ALGORITHM USING MAX HEAP
1) Input Heap
2) Display Heap
3) Heapify
4) Heap Sort Algorithm
5) Exit
----------------------------------------------------
Enter your choice :
5
Exited sucessfully !!
----------------------------------------------------
*/