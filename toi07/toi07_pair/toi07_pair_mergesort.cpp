//toi7_pair
//merge sort dnc
//count inversion
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
pair<int,int> A[100000];
int a[100000], b[100000];
ll tot = 0, suff[100000];
void ms(int low, int high){
    if(low == high){a[low] = A[low].second; return;}
    int mid = low + ((high-low)>>1), i, j, k;
    ms(low, mid); ms(mid+1, high);
    for(i = mid; i>=low; --i){
        suff[i] = a[i];
        if(i < mid) suff[i] += suff[i+1];
    }
    //merge
    i = low; j = mid+1; k = 0;
    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            b[k++] = a[i]; ++i;
        }else{
            b[k++] = a[j];
            tot += (mid-i+1ll) * a[j] + suff[i]; ++j; 
            //there is mid-i+1 (suffix till i in the left part array) elements > a[j]
            //suff[i] stores suffix sum till i in left part array
        }
    }
    while(i <= mid){b[k++] = a[i]; ++i;}
    while(j <= high){b[k++] = a[j]; ++j;}
    for(i = low; i<=high; ++i) a[i] = b[i-low];
}
signed main(){
    int n; scanf("%d", &n);
    for(int i = 0, a, b; i<n; ++i){scanf("%d %d", &a, &b); A[i] = make_pair(b, a);} 
    //after sort by b, it becomes similar to inversion counts in an array problem
    sort(A, A+n);
    ms(0, n-1);
    printf("%lld", tot);
}
