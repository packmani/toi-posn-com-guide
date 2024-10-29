//toi1_plate
//brute force / simulation
#include <cstdio>
#include <queue>
using namespace std;
int cl[1001]; // keep class no. for each student
bool inQ[11]; // check if there is student from this class in Q
queue<int> q[11]/*q[x] is q of student in class x*/, Q; /*Q is queue for class no.*/
signed main(){
    int N_c, N_s; scanf("%d %d", &N_c, &N_s);
    for(int i = 0, c, s; i<N_s; ++i){scanf("%d %d", &c, &s); cl[s] = c;}
    while(true){
        char op; scanf(" %c", &op); if(op == 'X'){puts("0"); break;}
        if(op == 'E'){
            int s; scanf("%d", &s);
            q[cl[s]].push(s); //push student s to his class queue (q[cl[s]])
            if(!inQ[cl[s]])/*if there is no student from cl[s] in Q before -> push to Q*/{Q.push(cl[s]); inQ[cl[s]] = true;}
        }else if(op == 'D'){
            if(Q.empty()){puts("empty"); continue;} /*there is no one in queue*/
            int s = q[Q.front()].front();/*first student in queue*/
            printf("%d\\n", s); q[cl[s]].pop();/*he walks out of queue*/
            if(q[cl[s]].empty()){Q.pop(); inQ[cl[s]] = false;}/*if he was the only student from cl[s] -> remove cl[s] from Q*/
        }
    }
}
