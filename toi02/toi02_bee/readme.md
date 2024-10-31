## toi2_bee
[problem statement](https://programming.in.th/tasks/toi2_bee)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Dynamic programming</li>
    <li>Matrix exponentiation (optional)
      <ul>
        <li>Binary exponentiation</li>
      </ul>
    </li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้มีลักษณะของการที่นำคำตอบในอดีตมาคิดสู่ปัจจุบันทำให้เราสามารถแก้ด้วย dynamic programming ได้.</p>
  <p>กำหนดให้ $f(i)$ แทนจำนวนของผึ้งงานในวันที่ $i$ และ $g(i)$ แทนจำนวนของผึ้งทหาร โจทย์ให้ $f(0) = 1$ และเราก็รู้ได้ว่า $f(1) = 2$ ซึ่งถือว่าเป็น base case และมี recurrence คือ:</p>
  <p>$f(i) = f(i-1) + g(i-1) + 1$</p>
  <p>เนื่องจากผึ้งงานวันที่ $i$ เกิดได้จาก ทั้งผึ้งงานและผึ้งทหารวันที่ $i-1$ และ +1 เกิดจากนางพญา, $g(i) = f(i-1)$ เนื่องจากผึ้งทหารวันที่ $i$ เกิดได้จากแค่ผึ้งงานวันที่ $i-1$.</p>
  <p>เนื่องจาก $g(i) = f(i-1) \rightarrow g(i-1) = f(i-2) \rightarrow f(i) = f(i-1) + f(i-2) + 1$. เราสามารถหาจำนวนของผึ้งแต่ละชนิดในแต่ละวันได้โดย precompute หาคำตอบสำหรับทุกวัน.</p>
  <p>สมมติให้จำนวนวันคือ $D$ ($D \leq 24$) ทำให้มี TC = $O(D)$. สมมติเราต้องการหาคำตอบวันที่ $x$, จำนวนผึ้งงานก็คือ $f(x)$ และจำนวนผึ้งทั้งหมดก็คือ:</p>
  <p>$f(x) + g(x) + 1 = f(x) + f(x-1) + 1$</p>
  <p>Bonus: find $n^{th}$ Fibonacci number using Matrix exponentiation: https://usaco.guide/plat/matrix-expo?lang=cpp</p>
</details>

[ac code](./toi02_dp.cpp)<br>
[ac code bonus sol](./toi02_matrix_expo.cpp)
