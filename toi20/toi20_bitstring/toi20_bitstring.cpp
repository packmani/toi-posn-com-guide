#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,q;
int dp[(1<<20)+6]; //dp[i] = best way to get from state "i" to base state (0)
int vals[(1<<20)+6]; //vals[i] = weight given by input for each state "i"
string bitstring;
int val;

//function to turn bitstring into integer
int bitstring_to_int(string bitstring)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        //if this digit is a 1, find its digit value as a binary number and add it to the sum
        if(bitstring[i]=='1')
            num += (1<<(n-i-1)); 
    }
    return num;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for(int i=0;i<(1<<n);i++)
    {
        cin >> bitstring >> val;
        vals[bitstring_to_int(bitstring)] = val;
        dp[i]=INT_MIN; //base case
    }
    dp[0]=0; //base case

    //go through every possible state in ascending order
    for(int i=1;i<(1<<n);i++) 
    {
        //go through each digit
        for(int j=0;j<n;j++) 
        {
            //if this digit is a 1
            if((i&(1<<j))!=0) 
                //get past (state's value + current weight) and compare with current
                dp[i]=max(dp[i],dp[i^(1<<j)]+vals[i]); 
        }
        //go through each pair of adjacent digits
        for(int j=0;j<n-1;j++) 
        {
            //if digit j and j+1 are both 1s
            if( ((i&(1<<j))!=0) and ((i&(1<<(j+1))))!=0 ) 
                //get past (state's value + current weight) and compare with current
                dp[i]=max(dp[i],dp[i^((1<<j) + (1<<(j+1)))]+vals[i]); 
        }
    }
    
    while(q--)
    {
        //answer each query
        cin >> bitstring;
        cout << dp[bitstring_to_int(bitstring)] << '\n';
    }
    
}
