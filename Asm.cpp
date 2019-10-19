#include<iostream>
#include<conio.h>
#include<string>
#include <cstdlib>
#include<cstring>
#include<stdio.h>
#include<time.h>
using namespace std;
	char S1[250], S2[250];
	int f = 0, r = 0, t = 0, x;
	class Queue 
	{
		char buffer[250];
		public:
		void Enqueue(int a) 
		{
			f = 0;
			while (f != 250 && a != 0) 
			{
				buffer[f] = S1[r];
				f++;
				r++;
				a--;
			}
		}	
		char Dequeue() 
		{
			char buffer1;
			char result = buffer[0];
			for (int i = 1; i <= f; i++) 
			{
				buffer1 = buffer[i];
				buffer[i - 1] = buffer1;
			}
			return result;
		}
		void transfer() 
		{	
			int a = 250;
			int i = 1 ;
			
			while (x > 0)
			{
				Enqueue(x);
				while (a > 0) 
				{
					S2[t] = Dequeue();
					t++;
					a--;
					x--;
				}
				cout << "\n"<< i << " String S2 after transfer is : " << S2;
				i++;
				if (x > 250) 
				{
					a = 250;
				}
				else 
				{
					a = x;
				}
			}
		}
	};
int main() 
	{
		Queue Q;
		clock_t start = clock();// bat dau ham dem thoi gian
		cout << "Input Source String:\n";
		scanf("%[^\n]%*c", S1);
		x = strlen(S1);
		try 
		{
			if (x > 250) 
			{
				cout<< "Exceeded 250 characters\nx";
			}
			
			if (x > 0 && x <= 250) 
			{	
				Q.transfer();
			}
			else 
			{
				cout<<"Error.Please Enter Data\n";
			}				
		}
		catch (int x) 
		{
			cout << "Please Enter Data";
		}
		
		clock_t finish = clock();// ket thuc dem thoi gian
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;
		cout<<"\n";
		printf("Excution Time:  %.5f",duration);
		return 0;
	}
