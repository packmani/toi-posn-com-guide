//toi10_prime
//find prime numbers using sieve of eratosthenes
#include <cstdio>
const int M = 7368788;
bool s[M];
int m = 0, k;
signed main(){
    for(int i = 3; i<M; i+=2) s[i] = true;
    s[2] = true; m++;
    scanf("%d", &k); --k;
    if(!k){puts("2"); return 0;}
    for(long long i = 3; i<M; i+=2){
        if(s[i]){
            if(m++ == k){printf("%lld\n", i); return 0;}
            for(long long j = i*i; j<M; j+=i+i) s[j] = false; //multiple of i is not prime
        }
    }
}
