#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int,int,int> sum = {0,0,0,0,0};
void addtuple(tuple<int,int,int,int,int> temp) //add tuple to sum
{
	get<0>(sum) += get<0>(temp);
	get<1>(sum) += get<1>(temp);
	get<2>(sum) += get<2>(temp);
	get<3>(sum) += get<3>(temp);
	get<4>(sum) += get<4>(temp);
	return;
}
int main()
{
	//t1 {-,i,ii,iii,iv,v,vi,vii,viii,ix} first slot mod 10
	//t2 {x,xx,xxx,xl,l,lx,lxx,lxxx,xc} second slot
	//t3 {c,cc,ccc}; third slot
	//i,v,x,l,c
	int num;
	cin >> num;
	tuple<int,int,int,int,int> t1[] =
	{{0,0,0,0,0},{1,0,0,0,0},{2,0,0,0,0},{3,0,0,0,0},{1,1,0,0,0},
	{0,1,0,0,0},{1,1,0,0,0},{2,1,0,0,0},{3,1,0,0,0},{1,0,1,0,0}};
	tuple<int,int,int,int,int> t2[] =
	{{0,0,0,0,0},{0,0,1,0,0},{0,0,2,0,0},{0,0,3,0,0},{0,0,1,1,0}
	,{0,0,0,1,0},{0,0,1,1,0},{0,0,2,1,0},{0,0,3,1,0},{0,0,1,0,1}};
	tuple<int,int,int,int,int> t3[] = 
	{{0,0,0,0,0},{0,0,0,0,1},{0,0,0,0,2},{0,0,0,0,3}};

	for(int i=1;i<=num;i++)
	{
		addtuple(t1[i%10]);
		addtuple(t2[(i/10)%10]);
		addtuple(t3[(i/100)%4]);
	}
	cout << get<0>(sum) << ' ' << get<1>(sum) << ' ' <<
	get<2>(sum) << ' ' << get<3>(sum) << ' ' << get<4>(sum);
}
