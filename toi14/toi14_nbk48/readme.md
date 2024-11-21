## toi14_nbk48
<details>
    <summary>hints</summary>
        <ul>
        <details>
        <summary>hint 1</summary>
            <ul><details>
            <summary>ลองคิดแบบที่ $p_i ≥ 0$</summary>
                <ul>ถ้าเราสามารถซื้อ $[1…x]$  ได้ แสดงว่าเราก็สามารถซื้อ $[1…y]$ ได้โดยที่ $y ≤ x$</ul>
            </details></ul>
        </details>
        <details>
        <summary>hint 1.5</summary>
            <ul><deatails>
            <summary>Monotone</summary>
                <ul><li>Binary Search</li></ul>
            </deatails></ul>
        </details>
        <details>
        <summary>hint 2</summary>
            <ul>สมมติ $x ≥ y$ และ $\sum_{i=1}^x p_i ≤ \sum_{j=1}^y p_j$  เราก็ควรจะซื้อจนถึง $x$ ?</ul>
        </details>
        </ul>
</details>   
<details>
    <summary>prerequisites</summary>
        <ul><li>Binary Search</li></ul>
</details>
<details>
    <summary>solution</summary>
        <ul>
        โจทย์ให้เราหา $x_j$ ที่มากที่สุดที่ $\sum_{i=1}^{x_j}p_i ≤ q_j$ สำหรับแต่ละคำถาม, $1 ≤ j ≤ Q$
        <br><br>
        <p><strong>    -Binary Search-</strong></p>
        เราสามารถทำการ binary serach on answer ได้. ให้ $f(x)$ เป็น function ที่จะ return ค่า boolean $(T/F)$ โดยที่
        <p>return true เมื่อ</p>
        <ul>
        <li>คำตอบอยู่ในช่วง $[x…n]$</li>
        <li>เราสามารถซื้อ $[1…y]$ ได้โดยที่ $y  ≥ x$</li>
        <li>$\sum_{i=1}^yp_i ≤ q_j; \  y ≥ x$</li>
        </ul><hr>
        <p>เราจะสังเกตได้ว่า function $f(x)$ นี้เป็น function ลด คือถ้าเรานำ $f(x)$ มาเขียนเรียงตั้งแต่ $1$ ถึง $n$ จะได้อยู่ในรูป <code>1111111110000000</code> โดยที่ $x_j$ คือตำแหน่งของ 1 ตัวสุดท้าย</p>
        <p>ในการ implement เราสามารถทำได้โดยการทำ prefix sum เพื่อหาผลบวกตั้งแต่ $1$ ถึง $i$ สำหรับทุก $i; 1 \leq i \leq n$ แล้วก็ทำ suffix minimum ส่วนสำหรับแต่ละ query เราจะ binary search หา $x_j$ ที่ไกลที่สุด</p>
        <p>$TC = O(N + QlogN)$</p>
              <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
//toi14_nbk48
//binary search
#include <cstdio>
#include <algorithm>
int qs[100000];
signed main(){
	int n, q, x; scanf("%d %d", &n, &q);
	for(int i = 0; i<n; ++i){
		scanf("%d", qs+i); 
		qs[i] += (i? qs[i-1] : 0);
	}
	for(int i = n-2; ~i; --i) if(qs[i+1] < qs[i]) qs[i] = qs[i+1];
	while(q--){
		scanf("%d", &x);
		printf("%d\n", (int)(std::upper_bound(qs, qs+n, x) - qs));
	}	
}
  ```
  </ul>
  </details>
</ul></details>
