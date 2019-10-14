	#include<iostream>
	#include<string>
	#include<cstring>
	#define MAX 50
	using namespace std;
	class queue
	{
		char Q[MAX];
		int f,r;
		public:
		// khoi tao queue
		queue()
		{
			f = 0;
			r = 0;
		}
		int ENum() // dem so phan tu trong queue
		{
			if(f==r)
		{
			return 0;
		}
		else
		{
			return (MAX- f +r)% MAX; // so phan tu trong queue
		}
		}
	void enqueue(char x)
	{
		try
		{
				if(ENum() == MAX)
			{
				cout <<"Error : Queue is Full";
			}
			else
			{
				Q[r] = x;
				r = (r+1)% MAX;
			}
		}
		catch (int a)
		{
			cout<<"Co loi xay ra. Loi so:"<<a;
		}
	}
		char dequeue()
		{
			int tmp;
			if(f==r)
		{
			cout<<"Error: Queue is Empty";
		}
		else
		{
			tmp = Q[f];
			f = (f+1)% MAX;
		}
			return tmp;
		}
	void input()
	{
		char x;
		cout<<"Nhap ky tu x : ";
		cin>>x;
		while(x != '0')
		{
			enqueue(x);
			cout<<"Nhap ky tu x : ";
			cin>>x;
		}
	}
	void output()
	{
		while (f!= r)
		{
			cout << dequeue();
		}
	}
	void transfer()
	{
		string StrQueue;
		//cin.ignore();
		cout<<"\nEnter String Source :\n "<<endl;
		getline(cin,StrQueue);
		cout<<"\nSource String S1 :\n"<<StrQueue;
		char CharQueue[250];
		
		int i = 0;
		int j = 0;
		try
		{
			while(i<StrQueue.length())// doc ky tu trong chuoi
			{
				while(ENum()<MAX-1)//the queue is not full
				{
					char x = StrQueue[i];// doc 1 gia tri tu chuoi dden x;
					enqueue(x);//add x to queue
					i++;
				}
				while(ENum()>0)
				{
					CharQueue[j]= dequeue();
					j++;
				}
			}
		}
			catch (int a)
			{
				cout<<"Co loi xay ra. Loi so:"<< a;
			}
		cout<< "\nString of Destination S2:\n"<<CharQueue;
	}
	};
	int main (){
	queue Q;
	//Q.input();
	//cout<<"\nInput Queue:\n";
	//Q.output();
	Q.transfer();
	Q.output();
	return 0;
	}

