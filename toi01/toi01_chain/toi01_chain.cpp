//toi1_chain
//brute force
#include <iostream>
std::string ps, s;
signed main(){
    int L, n; std::cin>>L>>n>>ps; --n;
    while(n--){
        std::cin>>s; int cnt = 0;
        for(int i = 0; i<L; ++i) if(s[i] != ps[i]) ++cnt;
        if(cnt > 2){std::cout<<ps; return 0;}
        ps = s;
    }
    std::cout<<ps;
}
