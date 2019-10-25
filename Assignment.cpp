#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<conio.h>

using namespace std;
char S1[250], S2[250];
int a = 0, b = 0, c = 0, t;

class Queues {
	char buffer[50];
	public:
	void enqueue(int x) 
	{
		a = 0;
		while (a != 50 && x != 0) 
		{
			buffer[a] = S1[b];
			a++;
			b++;
			x--;
		}
	}
	char dequeue()
	{
		char tmp;
		char result = buffer[0];
		for (int i = 1; i <= a; i++) 
		{
			tmp = buffer[i];
			buffer[i - 1] = tmp;
		}
		return result;
	}
	void transfer() {
		int x = 50;
		int i = 1;
		while (t > 0) 
		{
			enqueue(t);
			while (x > 0) {
				S2[c] = dequeue();
				c++;
				x--;
				t--;
			}
			cout << "\n" << i << "---Destination String S2:\n" << S2;
			i++;
			if (t > 50) {
				x = 50;
			}
			else {
				x = t;
			}
		}
	}
};

int main() {
	Queues Q;
	cout << "Insert Source String S1 (MAX 250 CHARACTERS): ";
	scanf("%[^\n]%*c", S1);
	t = strlen(S1);
	try 
	{
		if (t > 0) {
			Q.transfer();
		}
		else {
			cout << "\nERROR: Please Enter Data";
		}
	}
	catch (int e) 
	{
		cout << "\nERROR:"<< e;
	}
	return 0;
}
