//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : lab2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;

class student
{
	string usn,name,branch;
	int sem;
public:
	void pack();
	void read();
	void write();
	void unpack();
	void search(int);
	void delet();
	void modify();
};
fstream f1;
void student::read()
{
	cout<<"Enter the usn:"<<endl;
	cin>>usn;
	cout<<"Enter the name:"<<endl;
	cin>>name;
	cout<<"Enter the sem:"<<endl;
		cin>>sem;

	cout<<"Enter the branch:"<<endl;
	cin>>branch;
}
void student::pack()
{
	string buffer,sem1;
	int l;
	stringstream ss;
				ss<<sem;
				 sem1=ss.str();

	buffer=usn+"|"+name+"|"+sem1+"|"+branch;
	buffer.resize(100,'$');
	f1<<buffer<<endl;
}

void student::unpack()
{
	string extra;
	f1.open("file.txt",ios::in);
	getline(f1,usn,'|');
	getline(f1,name,'|');
	getline(f1,branch,'|');
	f1.close();
}
void student::search(string key)
{
int f;
	f1.open("file.txt",ios::in);
	while(!f1.eof())
	{
		getline(f1,buffer);
		unpack();
		if(usn==key)
		{ f=1;
		  cout<<"success"
		}
		else
		{
			cout<<"not found."<<endl;
		}
	}
}
int main()
{
	int ch,key;
	student s;
	while(1)
	{
	cout<<"Enter your choice:"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:s.read();
	f1.open("file.txt",ios::out|ios::app);
		if(!f1)
		{
			cout<<"File not opened."<<endl;
		}
		s.pack();
		f1.close();
	        break;
	case 2: cout<<"Enter the key:"<<endl;
	        cin>>key;
	        s.search(key);
	        break;
	default: cout<<"Wrong choice."<<endl;
	         exit(0);
	}
	}
	return 0;
}
