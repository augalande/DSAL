/*
Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client’s telephone number.
Make use of two collision handling techniques and compare them using
number of comparisons required to find a set of telephone numbers
(Note: Use linear probing with replacement and without replacement)
*/

#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;

class HashTable
{
    private:
    string cname;
    int ctelno;

    public:
    void create_HT();
    void display_HT();
    int Hash(string s);
    void insert_HT1();
    void insert_HT2();
    void search_HT1();
    void search_HT2();
} HT1[10],HT2[10];

void HashTable::create_HT()
{
    for(int i=0;i<10;i++)
    {
        HT1[i].cname="-----";
        HT1[i].ctelno=0;

        HT2[i].cname="-----";
        HT2[i].ctelno=0;
    }
}

void HashTable::display_HT()
{
    cout<<"-----Hash Table 1-----"<<setw(50)<<"-----Hash Table 2-----"<<endl;
    cout<<"Index"<<setw(10)<<"CName"<<setw(10)<<"CTelno"<<setw(30)<<"Index"<<setw(10)<<"CName"<<setw(10)<<"CTelno"<<endl;

    for(int i=0;i<10;i++)
    {
        cout<<i<<setw(10)<<HT1[i].cname<<setw(10)<<HT1[i].ctelno<<setw(30)<<i<<setw(10)<<HT2[i].cname<<setw(10)<<HT2[i].ctelno<<endl;
    }
}

int HashTable::Hash(string s)
{
    int ascii=0;
    for(int i=0;i<s.length();i++)
    {
        ascii+=(int)s[i];
    }
    return (ascii%10);
}

void HashTable::insert_HT1()
{
    cout<<"How many records do you want to insert?"<<endl;
    int count;
    cin>>count;

    for(int i=0;i<count;i++)
    {
        cout<<"Enter Customer Name :"<<endl;
        string name;
        cin>>name;

        cout<<"Enter Customer Telno :"<<endl;
        int telno;
        cin>>telno;

        int index=Hash(name);

        if(HT1[index].ctelno==0)
        {
            HT1[index].cname=name;
            HT1[index].ctelno=telno;
        }
        else
        {
            do
            {
                index=(index+1)%10;
            }while(HT1[index].ctelno!=0);

            HT1[index].cname=name;
            HT1[index].ctelno=telno;

        }
    }
}

void HashTable::insert_HT2()
{
    cout<<"How many records do you want to insert?"<<endl;
    int count;
    cin>>count;

    for(int i=0;i<count;i++)
    {
        cout<<"Enter Customer Name :"<<endl;
        string name;
        cin>>name;

        cout<<"Enter Customer Telno :"<<endl;
        int telno;
        cin>>telno;

        int index=Hash(name);
        int cur_index=index;

        if(HT2[cur_index].ctelno==0)
        {
            HT2[cur_index].cname=name;
            HT2[cur_index].ctelno=telno;
        }
        else
        {
            int act_index=Hash(HT2[cur_index].cname);
            int new_index;

            do
            {
                index=(index+1)%10;
            }while(HT2[index].ctelno!=0);

            new_index=index;

            if(cur_index==act_index)
            {
                HT2[new_index].cname=name;
                HT2[new_index].ctelno=telno;

            }
            else
            {
                HT2[new_index].cname=HT2[cur_index].cname;
                HT2[new_index].ctelno=HT2[cur_index].ctelno;

                HT2[cur_index].cname=name;
                HT2[cur_index].ctelno=telno;
            }
        }
    }
}

void HashTable::search_HT1()
{
    cout<<"How many records do you want to search?"<<endl;
    int count;
    cin>>count;

    int comp=0;

    for(int i=0;i<count;i++)
    {
        int cmp=0;

        cout<<"Enter Customer Name :"<<endl;
        string name;
        cin>>name;

        int index=Hash(name);

        if(HT1[index].cname==name)
        {
            cmp++;
            cout<<"Customer Telno :"<<HT1[index].ctelno<<endl;
        }
        else
        {
            do
            {
                index=(index+1)%10;
                cmp++;
            }while(HT1[index].cname!=name);

            cout<<"Customer Telno :"<<HT1[index].ctelno<<endl;
        }
        cout<<"Needed Comparisons :"<<cmp<<endl;
        comp+=cmp;
    }
    cout<<"Total Needed Comparisons :"<<comp<<endl;
}

void HashTable::search_HT2()
{
    cout<<"How many records do you want to search?"<<endl;
    int count;
    cin>>count;

    int comp=0;

    for(int i=0;i<count;i++)
    {
        int cmp=0;

        cout<<"Enter Customer Name :"<<endl;
        string name;
        cin>>name;

        int index=Hash(name);

        if(HT2[index].cname==name)
        {
            cmp++;
            cout<<"Customer Telno :"<<HT2[index].ctelno<<endl;
        }
        else
        {
            do
            {
                index=(index+1)%10;
                cmp++;
            }while(HT2[index].cname!=name);

            cout<<"Customer Telno :"<<HT2[index].ctelno<<endl;
        }
        cout<<"Needed Comparisons :"<<cmp<<endl;
        comp+=cmp;
    }
    cout<<"Total Needed Comparisons :"<<comp<<endl;
}


int main()
{
    HashTable HT;

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Hash Table"<<endl;
        cout<<"1) Create Hash Tables"<<endl;
        cout<<"2) Insert in Hash Table 1"<<endl;
        cout<<"3) Insert in Hash Table 2"<<endl;
        cout<<"4) Display Hash Tables"<<endl;
        cout<<"5) Search in Hash Table 1"<<endl;
        cout<<"6) Search in Hash Table 2"<<endl;
        cout<<"7) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                HT.create_HT();
                cout<<"Hash Tables created sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                HT.insert_HT1();
                cout<<"Insertion in Hash Table 1 done sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 3:
            {
                HT.insert_HT2();
                cout<<"Insertion in Hash Table 2 done sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                HT.display_HT();
                cout<<"Hash Tables displayed sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 5:
            {
                HT.search_HT1();
                cout<<"Searching in Hash Table 1 done sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 6:
            {
                HT.search_HT2();
                cout<<"Searching in Hash Table 2 done sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 7:
            {
                cout<<"Exited sucessfully !!"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                exit(0);
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
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
1
Hash Tables created sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
2
How many records do you want to insert?
5
Enter Customer Name :
abc
Enter Customer Telno :
111
Enter Customer Name :
bca
Enter Customer Telno :
222
Enter Customer Name :
xyz
Enter Customer Telno :
333
Enter Customer Name :
yzx
Enter Customer Telno :
444
Enter Customer Name :
abd
Enter Customer Telno :
555
Insertion in Hash Table 1 done sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
3
How many records do you want to insert?
5
Enter Customer Name :
abc
Enter Customer Telno :
111
Enter Customer Name :
bca
Enter Customer Telno :
222
Enter Customer Name :
xyz
Enter Customer Telno :
333
Enter Customer Name :
yzx
Enter Customer Telno :
444
Enter Customer Name :
abd
Enter Customer Telno :
555
Insertion in Hash Table 2 done sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
4
-----Hash Table 1-----                            -----Hash Table 2-----
Index     CName    CTelno                         Index     CName    CTelno
0     -----         0                             0     -----         0
1     -----         0                             1     -----         0
2     -----         0                             2     -----         0
3       xyz       333                             3       xyz       333
4       abc       111                             4       abc       111
5       bca       222                             5       abd       555
6       yzx       444                             6       yzx       444
7       abd       555                             7       bca       222
8     -----         0                             8     -----         0
9     -----         0                             9     -----         0
Hash Tables displayed sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
5
How many records do you want to search?
3
Enter Customer Name :
abc
Customer Telno :111
Needed Comparisons :1
Enter Customer Name :
yzx
Customer Telno :444
Needed Comparisons :3
Enter Customer Name :
abd
Customer Telno :555
Needed Comparisons :2
Total Needed Comparisons :6
Searching in Hash Table 1 done sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
6
How many records do you want to search?
3
Enter Customer Name :
abc
Customer Telno :111
Needed Comparisons :1
Enter Customer Name :
yzx
Customer Telno :444
Needed Comparisons :3
Enter Customer Name :
abd
Customer Telno :555
Needed Comparisons :1
Total Needed Comparisons :5
Searching in Hash Table 2 done sucessfully !!
----------------------------------------------------
----------------------------------------------------
Hash Table
1) Create Hash Tables
2) Insert in Hash Table 1
3) Insert in Hash Table 2
4) Display Hash Tables
5) Search in Hash Table 1
6) Search in Hash Table 2
7) Exit
----------------------------------------------------
Enter your choice :
7
Exited sucessfully !!
----------------------------------------------------
*/