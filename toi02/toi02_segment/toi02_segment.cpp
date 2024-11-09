//credits: https://programming.in.th/tasks/toi2_segment/submissions
//unknown who was the original
#include<bits/stdc++.h>
using namespace std;

int convert(string s) {
    if (s=="     |  |") return 1;
    else if (s==" _  _||_ ") return 2;
    else if (s==" _  _| _|") return 3;
    else if (s=="   |_|  |") return 4;
    else if (s==" _ |_  _|") return 5;
    else if (s==" _ |_ |_|") return 6;
    else if (s==" _   |  |") return 7;
    else if (s==" _ |_||_|") return 8;
    else if (s==" _ |_| _|") return 9;
    else if (s==" _ | ||_|") return 0;
}

long long a,b,n1,n2;
int main() {
    string top,mid,bot,num;
    cin>>a>>b;
    cin.ignore();
    getline(cin,top);
    getline(cin,mid);
    getline(cin,bot);
    for (int i=0;i<a*4;i+=4) {
        num=top.substr(i,3)+mid.substr(i,3)+bot.substr(i,3);
        n1=n1*10+convert(num);
    }
    getline(cin,top);
    getline(cin,mid);
    getline(cin,bot);
    for (int i=0;i<b*4;i+=4) {
        num=top.substr(i,3)+mid.substr(i,3)+bot.substr(i,3);
        n2=n2*10+convert(num);
    }
    cout<<n1+n2;
    return 0;
}
