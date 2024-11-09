#include<bits/stdc++.h>
using namespace std;
int dice[6];
int temp[6];
void reset()
{
	dice[0]=1;
	dice[1]=2;
	dice[2]=3;
	dice[3]=5;
	dice[4]=4;
	dice[5]=6;
}
void forward()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[3];
	dice[1]=temp[0];
	dice[2]=temp[2];
	dice[3]=temp[5];
	dice[4]=temp[4];
	dice[5]=temp[1];
}
void backward()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[1];
	dice[1]=temp[5];
	dice[2]=temp[2];
	dice[3]=temp[0];
	dice[4]=temp[4];
	dice[5]=temp[3];
}
void left()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[4];
	dice[1]=temp[1];
	dice[2]=temp[0];
	dice[3]=temp[3];
	dice[4]=temp[5];
	dice[5]=temp[2];
}
void right()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[2];
	dice[1]=temp[1];
	dice[2]=temp[5];
	dice[3]=temp[3];
	dice[4]=temp[0];
	dice[5]=temp[4];
}
void clockwise()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[0];
	dice[1]=temp[4];
	dice[2]=temp[1];
	dice[3]=temp[2];
	dice[4]=temp[3];
	dice[5]=temp[5];
}
void counterclockwise()
{
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
	dice[0]=temp[0];
	dice[1]=temp[2];
	dice[2]=temp[3];
	dice[3]=temp[4];
	dice[4]=temp[1];
	dice[5]=temp[5];
}
int main()
{
	int n;
	cin >> n;
	string str;
	for(int i=0;i<n;i++)
	{
		cin >> str;
		reset();
		for(auto c:str)
		{
			if(c=='F')
				forward();
			else if(c=='B')
				backward();
			else if(c=='L')
				left();
			else if(c=='R')
				right();
			else if(c=='C')
				clockwise();
			else
				counterclockwise();
		}
		cout << dice[1] << ' ';
	}
}
