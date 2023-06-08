/*
Department maintains a student information. The file contains roll
number, name, division and address. Allow user to add, delete
information of student. Display information of particular student. If
record of student does not exist an appropriate message is displayed. If
it is, then the system displays the student details. Use Sequential File
to maintain the data.
*/

#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

class MyFile
{
    public:
    string rno,name,div,add;
    char fname[40],buffer[40];

    fstream file;

    MyFile()
    {
        cout<<"Enter File Name :"<<endl;
        cin>>fname;
        rno="";
        name="";
        div="";
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
            cout<<"Enter Roll No :"<<endl;
            cin>>rno;
            cout<<"Enter Name :"<<endl;
            cin>>name;
            cout<<"Enter Divison :"<<endl;
            cin>>div;
            cout<<"Enter Address :"<<endl;
            cin>>add;

            file<<rno<<" "<<name<<" "<<div<<" "<<add<<endl;
        }
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
    cout<<"Enter Roll No to be searched :"<<endl;
    string temp;
    cin>>temp;

    file.open(fname,ios::in);

    if(!file)
    {
        cout<<"Error while opening File"<<endl;
    }
    else
    {
        string a;
        while(!file.eof())
        {
            file.getline(buffer,40);
            a+=buffer[0];
            a+=buffer[1];

            if(temp==a)
            {
                cout<<"Record Found !!"<<endl;
                cout<<buffer<<endl;
                file.close();
                return;
            }
        }
        cout<<"Record Not Found !!"<<endl;
        file.close();
        return;
    }

}

void MyFile::delete_file()
{
    cout<<"Enter Roll No to be deleted :"<<endl;
    string temp;
    cin>>temp;

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

            if(temp==a)
            {
                cout<<"Record : "<<buffer<<" Deleted !!"<<endl;
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
        cout<<"SEQUENTIAL FILE"<<endl;
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