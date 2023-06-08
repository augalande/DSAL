/*
Implementation of a direct access file -Insertion and deletion of a
record from a Direct Access File.
*/

#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

class HashTable
{
    public:
    int empid;
    int location;

    HashTable()
    {
        empid=0;
        location=0;
    }


    void create_ht();
    void display_ht();
    void insert_ht(int,int);
    int Hash(int);
    int search_ht(int);
    void delete_ht(int);
} HT[10];

void HashTable::create_ht()
{
    for(int i=0;i<10;i++)
    {
        HT[i].empid=0;
        HT[i].location=0;

    }
}

void HashTable::display_ht()
{
    cout<<"EmployeeID-Location"<<endl;
    for(int i=0;i<10;i++)
    {
       cout<<HT[i].empid<<"-"<<HT[i].location<<endl;

    }
}

int HashTable::Hash(int e)
{
    return (e%10);
}

void HashTable::insert_ht(int e,int l)
{
    int index=Hash(e);

    if(HT[index].location==0)
    {
        HT[index].empid=e;
        HT[index].location=l;
    }
    else
    {
        do
        {
            index=(index+1)%10;
        }while(HT[index].location!=0);

        HT[index].empid=e;
        HT[index].location=l;

    }
}

int HashTable::search_ht(int e)
{
    int index=Hash(e);

    if(HT[index].empid==e)
    {
        return HT[index].location;
    }
    else
    {
        do
        {
            index=(index+1)%10;
        }while(HT[index].empid!=e);

        return HT[index].location;
    }
    return -1;
}

void HashTable::delete_ht(int e)
{
    int index=Hash(e);

    if(HT[index].empid==e)
    {
        HT[index].empid=0;
        HT[index].location=0;
    }
    else
    {
        do
        {
            index=(index+1)%10;
        }while(HT[index].empid!=e);

        HT[index].empid=0;
        HT[index].location=0;
    }
}

class MyFile
{
    public:
    int empid;
    string name,add;
    char buffer[40],fname[40];
    HashTable HT;
    fstream file;

    MyFile()
    {
        cout<<"Enter File Name :"<<endl;
        cin>>fname;
        name="";
        add="";
    }

    void write_file();
    void read_file();
    void search_file();
    void delete_file();
};

void MyFile::write_file()
{
    cout<<"Enter number of records to be written : "<<endl;
    int count;
    cin>>count;

    file.open(fname,ios::out);

    if(!file)
    {
        cout<<"Error while opening File"<<endl;
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            cout<<"Enter EmpID :"<<endl;
            cin>>empid;
            cout<<"Enter Name :"<<endl;
            cin>>name;
            cout<<"Enter Address :"<<endl;
            cin>>add;
            cout<<"Location :"<<file.tellp()<<endl;
            HT.insert_ht(empid,file.tellp());

            file<<empid<<" "<<name<<" "<<add<<endl;
        }
        HT.display_ht();
    }
    file.close();
}

void MyFile::read_file()
{
    file.open(fname,ios::in);

    if(!file)
    {
        cout<<"Error while opening File"<<endl;
    }
    else
    {
        while(!file.eof())
        {
            file.getline(buffer,40);
            cout<<buffer<<endl;
        }
    }
    file.close();
}

void MyFile::search_file()
{
    int e;
    cout<<"Enter EmpID to be searched :"<<endl;
    cin>>e;

    int loc=HT.search_ht(e);

    file.open(fname,ios::in);

    if(!file)
    {
        cout<<"Error while opening File"<<endl;
    }
    else
    {
        file.seekg(loc,ios::beg);
        file.getline(buffer,40);

        if(loc!=-1)
        {
            cout<<"Record Found !!"<<endl;
            cout<<buffer<<endl;
        }
        else
        {
            cout<<"Record Not Found !!"<<endl;
        }
    }
    file.close();
}

void MyFile::delete_file()
{
    int e;
    cout<<"Enter EmpID to be deleted :"<<endl;
    cin>>e;

    string e1=to_string(e);

    fstream tempfile;
    tempfile.open("TempFile",ios::out);
    file.open(fname,ios::in);

    if(!file || !tempfile)
    {
        cout<<"Error while opening File"<<endl;
    }
    else
    {
        string a;
        while(!file.eof())
        {
            a="";
            file.getline(buffer,40);
            a+=buffer[0];
            a+=buffer[1];

            if(e1==a)
            {
                cout<<"Record : "<<buffer<<" Deleted !!"<<endl;
                HT.delete_ht(e);
                HT.display_ht();
            }
            else
            {
                tempfile<<buffer<<endl;
            }
        }
        tempfile.close();
        file.close();

        tempfile.open("TempFile",ios::in);
        file.open(fname,ios::out);

        if(!file || !tempfile)
            {
                cout<<"Error while opening File"<<endl;
            }
        else
            {
                while(!tempfile.eof())
                    {
                        tempfile.getline(buffer,40);
                        file<<buffer<<endl;
                    }
                tempfile.close();
                remove("tempfile");
                file.close();
            }
    }
}

int main()
{
    MyFile f;

    while(1)
    {
        cout<<"----------------------------------------------------"<<endl;
        cout<<"DIRECT ACCESS FILE"<<endl;
        cout<<"1) Write in File"<<endl;
        cout<<"2) Read in File"<<endl;
        cout<<"3) Search in File"<<endl;
        cout<<"4) Delete in File"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"Enter your choice :"<<endl;
        int ch;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                f.write_file();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 2:
            {
                f.read_file();
                break;
            }

            case 3:
            {
                f.search_file();
                cout<<"----------------------------------------------------"<<endl;
                break;
            }

            case 4:
            {
                f.delete_file();
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