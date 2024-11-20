## toi6_schedule
[problem statement](https://programming.in.th/tasks/toi6_schedule)
<details>
<summary>hints</summary>
<ul>
<details>
<summary>hint 1</summary>

เรียงตามเวลา
</details>

<details>
<summary>hint 1.5</summary>

sweep line
</details>
</ul>
</details>
<details>
<summary>prerequisites</summary>
<ul>
<li> sweep line [Line Sweep Algorithms and Coordinate Compression](https://www.youtube.com/watch?v=2noC-1bv5Kc&t=3477s) </li>
</ul>
</details>
<details>
<summary>solution</summary>

โจทย์คือมีช่วงอยู่ทั้งหมด $n$ ช่วงโดยที่ แต่ละช่วงจะกำหนดเวลาที่ขอใช้ช่องสัญญาณตั้งแต่ $s_i$ ถึง $f_i$ โดยที่คำขอที่ $i$ จะทำได้เมื่อมีช่องสัญญานที่ใช้อยู่ $< k$ โจทย์ถามหาว่าแต่ละคำขอมีคำขอไหนที่จองช่องสัญญาณสำเร็จ

เราสามารถแก้โดยการทำ *sweep line* ได้

- คำขอใช้ช่องสัญญานที่ $i$  มีผลในช่วง $[s_i, f_i]$
- เราจะ represent ช่วง  $[s_i, f_i]$ ด้วย event point ได้แก่
    - $s_i$ (จุดที่เราจะเพิ่มคำขอ  $i$)
    - $f_i$ (จุดที่เราจะนำคำขอ $i$ ออก)
- โดยที่เราจะไล่จากเวลาน้อยไปมาก
    - ถ้าเป็นจุดเริ่มต้น ($s_i$)
        - ดูว่ามีการใช้ช่องสัญญาณ $< k$ ?
            - ใช่ → คำขอ $i$ ถูกตอบรับ และ เพิ่ม การใช้ช่องสัญญานไป +1
    - ถ้าเป็นจุดจบ ($f_i$)
        - ดูว่าคำขอ  $i$  ถูกตอบรับ ?
            - ใช่ → นำคำขอ $i$ ออก (ลดการใช้ช่องสัญญานไป 1)
- เมื่อเราทำเสร็จเราก็สามารถตอบคำถามแต่ละคำถามได้  $O(1)$ เนื่องจากเราทำ sweep line precompute มาแล้ว

<p>$TC = O(nlogn + m)$ //<code>nlogn</code> มาจากการ sort event point</p> 
</details>
  <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
//toi6_schedule
//sweep line 
#include <cstdio>
#include <algorithm>
#define F first
#define S second
#define N 500000
std::pair<int,int> s[N], e[N]; //s -> starting of interval, e -> ending of interval
//s_i = e_i = {point, index}
int n, K, m, i, j, k, x, cur, ok[N]; //ok[i] check if did you insert i ?  
signed main(){
    scanf("%d %d %d", &n, &K, &m);
    for(i = 0; i<n; ++i) scanf("%d %d", &s[s[i].S = i].F, &e[e[i].S = i].F);
    std::sort(s, s+n); std::sort(e, e+n); // sort by time 
    //cur keeps current number slots used
    for(i = 0; i<n; i = j){
        for(x = s[i].F; k<n && e[k].F < x; ++k) cur -= (ok[e[k].S]); //remove eventpoint before x
        for(; j<n && s[j].F == x; ++j){
            if(cur < K) cur += (ok[s[j].S] = 1); //add
        }
        for(; k<n && e[k].F == x; ++k) cur -= (ok[e[k].S]); //remove only if we have inserted 
        //remove contribution of event that ended at x
    }
    while(m--){
        scanf("%d", &i); 
        ok[i-1] ? printf("Y ") : printf("N ");
    }
}
  ```
  </ul>
  </details>
