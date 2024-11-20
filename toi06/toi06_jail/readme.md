## toi06_jail
[problem statement](https://programming.in.th/tasks/toi6_jail)

<details>
  <summary>hints</summary>
  <ul>
    <li>$m ≤ 5$</li>
    <li>brute force simulation</li>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>brute force simulation</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราหาเลขลำดับที่ $m$ โดยที่ลำดับเรียงเป็นวงกลม แล้วในแต่ละรอบหลังจากทีเราหาเลขลำดับที่ $m$ แล้วให้ลบเลขนั้นออก แล้วทำแบบนี้ไปทั้งหมด $n$ รอบ เนื่องจาก  $m ≤ 5$ เราจึงสามารถทำการ simulate ตรงๆได้เลย</p>
  
  <details>
    <summary>Brute force</summary>
    <p>เราสามารถไล่หาเลขลำดับที่ $m$ โดยการใช้ queue (<code>std::queue</code>) โดยที่ในแต่ละรอบเราจะ maintain ให้เลขลำดับที่ $m$ (ในลำดับปัจจุบัน) อยู่หัว queue</p>
    <p><strong>TC :</strong> $O(mn)$</p>
    <details>
    <summary><code>video</code></summary>
    <ul>
    <br>
    <video src="https://github.com/user-attachments/assets/34d9224b-6e60-49aa-984c-72d7b0fcfd34"width="400" autoplay></video>
    </ul>
    </details>
  <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
//toi6_jail
//brute force simulation
#include <cstdio>
#include <queue>
std::queue<int> q;
signed main(){
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; ++i) q.push(i);
    while(n--){
        for(int j = 0; j<m-1; ++j) q.push(q.front()), q.pop();
        printf("%d ", q.front()); q.pop();
    }
}
  ```
  </ul>
  </details>
  </details>

  <details>
    <summary>What if $m$ is huge?</summary>
    <ul>
      <li><strong>prerequisites:</strong> Binary indexed tree (Fenwick tree) - <a href="https://cp-algorithms.com/data_structures/fenwick.html">Fenwick Tree - Algorithms for Competitive Programming</a></li>
      <li>ถ้าขอบเขตของ $m$ มากกว่านั้น เช่น $m ≤ 10^9$</li>
    </ul>
    <p>เราของกำหนดลำดับให้เป็น base 0 $[0 … m-1]$. ในรอบแรกเราเลือกเลขลำดับที่ $m-1$, รอบที่ 2 เราเลือกเลขลำดับ $2m-1$ แต่เลขอาจจะเกินขนาด array ในปัจจุบัน เนื่องจากเป็นลำดับเรียงเป็นวงกลมเราสามารถเปลี่ยนเป็นตำแหน่ง $(2m-1) \mod \text{sz}$ ได้ โดยที่  $\text{sz}$ คือขนาดของ array ในรอบนี้</p>
    <p>หรือพูดอีกอย่างว่าถ้า $p$ เป็นตำแหน่งลำดับ $m$ ในรอบที่ $i$, $(p+m) \mod \text{sz}$ คือตำแหน่งของลำดับที่ $m$ ในรอบที่ $i+1$ (ใน array หลังจากเอาเลขจากรอบที่ $i$ ออก)</p>
    <details>
      <summary>kth element</summary>
      <p><strong>References:</strong></p>
      <ul>
        <li><a href="https://cses.fi/problemset/task/1749">CSES - List Removals</a></li>
        <li><a href="https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/">Ordered Set and GNU C++ PBDS - GeeksforGeeks</a></li>
      </ul>
      <p>เราสามารถแก้ได้โดย data structure เช่น segment tree, binary indexed tree, ordered set (policy-based data structure) แต่จาก constraint $n ≤ 10^6$ เราเลือก binary indexed tree (Memory complexity = O(N))</p>
      <p><ins>Binary search</ins></p>
      <p>เราสามารถหา 1 ลำดับที่ $k$ ได้ด้วยการ binary search โดยถ้าเราให้</p>
      <ul>
        <li>$\text{qry}(i)$ คือจำนวน 1 ในช่วง $[1…i]$ (prefix sum)</li>
      </ul>
      <p>สังเกตได้ว่า $\text{qry}(j) ≥ \text{qry}(i)$ ถ้า $j \geq i$</p>
      <p>ทำให้เราสามารถ binary search เพื่อหา $j$ ที่มี $\text{qry}(j) = k$ ได้</p>
      <p>ทำให้เราสามารถทำ operation การหา kth element ใน $O(\log^2 N)$ ทำให้ $TC = O(N\log^2 N)$</p>
      <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
    //toi6_jail
    //fenwick tree + binary search
    #include <stdio.h>
    int n, cnt, bit[1000001];
    void upd(int i, int v){ for(; i<=n; i+=i&-i) bit[i] += v;}
    int qry(int i){ int r = 0; for(; i; i-=i&-i) r += bit[i]; return r;}
    //qry(i+1) >= qry(i)
    int _find(int k){
        int low = 1, high = n, j;
        while(low <= high){
            int mid = low + ((high-low)>>1);
            if(qry(mid) >= k) high = (j = mid) - 1;
            else low = mid+1;
        }
        return j;
    }
    signed main(){
        int k, t; scanf("%d %d", &n, &k); --k;
        for(int i = 1; i<=n; ++i) upd(i, 1);
        int sz = n, p = k%n;
        while(1){
            printf("%d ", t = _find(p+1));
            if(++cnt == n) break;
            upd(t, -1);
            if((p += k) >= (--sz)) p %= sz;
        }
    }
  ```
  </ul>
  </details>
      <p><ins>Improved approach</ins></p>
      <p>มีวิธีทำให้หา kth element ได้ใน $O(\log N)$ โดยการทำ binary lifting on Fenwick tree ทำให้ได้ $TC = O(N \log N)$</p>
        <li><a href="https://codeforces.com/blog/entry/61364?mobile=true">[Tutorial] Searching Binary Indexed Tree in O(log(N)) using Binary Lifting - Codeforces</a></li>
              <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
//toi6_jail
//fenwick tree + binary lifing on fenwick tree (kth element)
#include <stdio.h>
int n, cnt, LG, bit[1000001];
void upd(int i, int v){ for(; i<=n; i+=i&-i) bit[i] += v;}
int _find(int k){ 
    int i = 0, sum = 0;
    for(int j = LG; ~j; --j) if(i+(1<<j) <= n && sum + bit[i+(1<<j)] < k) sum += bit[i+=(1<<j)];
    return i+1;
}
signed main(){
    int k, t; scanf("%d %d", &n, &k); 
    --k; LG = 32 - __builtin_clz(n);
    for(int i = 1; i<=n; ++i) upd(i, 1);
    int sz = n, p = k%n;
    while(1){
        printf("%d ", t = _find(p+1));
        if(++cnt == n) break;
        upd(t, -1);
        if((p += k) >= (--sz)) p %= sz;
    }
}
  ```
  </ul>
  </details>
      </ul>
    </details>
  </details>
</details>
