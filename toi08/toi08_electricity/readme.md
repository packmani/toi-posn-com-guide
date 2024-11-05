## toi8_electricity
[problem statement](https://programming.in.th/tasks/toi8_electricity)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>minimize ค่าใช้จ่ายรวม</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>dynamic programming</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>range minimum</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Dynamic programming</li>
    <li>multiset</li>
    <li>segment tree</li>
    <li>sliding window minimum
      <ul>
        <li>deque</li>
      </ul>
    </li>
  </ul>
</details>

<details>
  <summary>variable definition</summary>
  <p>$N$ - จำนวนแปลงที่ดิน</p>
  <p>$P_i$ - ราคาที่ของแปลง $i$</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราในซื้อที่ดินเพื่อใช้ส่งกระแสไฟ้าจากที่ดิน 1 ไป ที่ดิน $N$ โดยมีเงื่อนไขว่าสถานีที่ติดกันต้องห่างกันไม่เกิน $k$ โดยเราสามารถแก้ด้วย dynamic programming ได้
  <ins>โดยเราจะนิยาม $dp(i)$ เป็นค่าใช้จ่ายน้อยที่สุดในการทำการส่งกระแสไฟฟ้าจากสถานีในที่ดิน 1 ไป สถานีในที่ดิน $i$ โดยระหว่างสถานีใดๆที่ติดกันมีระยะห่าง ≤ $k$</ins> <br>โดย base case ของเราก็คือ $dp(1) = P_1$ และมี recurrence คือ $dp(i) = min(\{dp(j) + P_i\}); \ max(1, \ i-k) ≤ j  < i$ <br>และคำตอบก็คือ $dp(n)$. ซึ่งถ้าเราทำการ loop ปกติจะมี $TC = O(N^2)$ ซึ่งยังไม่ทันภายในเวลาที่กำหนด</p>
  <p align="center"><video src="https://github.com/user-attachments/assets/eb408c30-fded-416b-a4f6-cc40c4880a3b" width="600" autoplay></video></p>
  <details>
    <summary>Deque Sol $(O(N))$</summary>
    <p>เราสามารถ simulate sliding window ได้ด้วย double-ended queue (<code>std::deque</code>) เนื่องจากการ slide ก็เหมือนกับการลบตัวหัว queue แล้วเพิ่มตัวใหม่ เราก็สามารถทำการ <code>pop_front</code> และ <code>push_back</code> ได้ปัญหาก็เหลือว่าเราจะหา minimum ใน deque ยังไงให้เร็ว ซึ่งเราทำได้โดยทำให้ deque เป็น monotonic deque ที่เก็บค่าเรียงจากน้อยไปมาก โดยเราจะทำการ check จากหลังมาหน้าโดยการเปรียบเทียบตัวใน deque กับตัวที่เราจะใส่ ($x$) ถ้า <code>dq.back() >= x</code> เราจะ  <code>pop_back</code> ทำไปเรื่อยจนกว่า <code>dq.back() < x</code> หรือ deque ว่าง. ถ้าเราทำแบบนี้เราจะทำให้ deque เรียงจากน้อยมามาก </p>
    <details>
      <summary>เหตุผลที่เราทำแบบนี้ได้</summary>
      <p>เราอยู่อยู่แล้วว่า element ที่อยู่ใน deque ($x_j$)  มาจาก index $j$ โดยที่ $j < i$ เมื่อให้ $x_i$ เป็น element ที่มาจาก index $i$. ถ้าค่าของ $x_j ≥ x_i$ ก็ไม่มีประโยชน์ที่จะเก็บ $x_j$ ไว้ใน deque เนื่องจาก $x_i$ น้อยกว่า แล้วถ้าในอนาคตมีช่วงที่อาจใช้คำตอบจาก $j$ เราก็สามารถใช้คำตอบจาก $i$ ได้เพราะว่าถ้าช่วงครอบ $j$ ยังไงก็ต้องครอบ $i$ เนื่องจาก $i > j$</p>
    </details>
    <p>TC = $O(N)$ เนื่องจาก element แต่ละตัวถูกใส่เข้า deque และนำออกไม่เกินอย่างละ 1 ครั้ง</p>
    <p>เราจะใช้ monotonic deque นี้ในการช่วยหา $dp(j)$ โดยที่ $i-k ≤ j < i$ เพื่อหาคำตอบ $dp(i)$ โดยเราจะใช้ deque เก็บ indices</p>
    <ol>
      <li>ลบตัวที่ออกนอก window: <br><code>while(!DQ.empty() && DQ.front() < i-k) DQ.pop_front();</code></li>
      <li>หาคำตอบ: <br><code>dp[i] = P_i + ((DQ.empty()) ? 0 : dp[DQ.front()]);</code></li>
      <li>เอาตัวที่ไม่มีประโยชน์ออกเพื่อรักษา monotone: <br><code>while(!DQ.empty() && dp[DQ.back()] >= dp[i]) DQ.pop_back();</code></li>
      <li>update ค่าเข้า deque: <br><code>DQ.push_back(i);</code></li>
    </ol>
  </details>

  <details>
    <summary>Multiset Sol</summary>
    <p>เราสามารถ simulate การทำ sliding window (มองว่าเป็นการลบออก 1 ตัว แล้ว เพิ่ม 1 ตัวใหม่) พร้อมกับการเก็บค่าน้อยที่สุดได้ด้วย std::multiset.  multiset จะใช้เก็บ $dp(j)$ ที่เป็นไปได้ ($j ≥ i-k$) เพื่อใช้ในการหา $dp(i)$. ในแต่ละรอบ $i$ เราจะทำ </p> 
   <ol>
      <li>ลบตัวเก่า: ลบ $dp(j)$ ที่ $j < i-k$ ออก โดนที่เราจะลบ $dp(i-k-1)$ ออกจาก multiset <br><code>ms.erase(ms.find(dp[i-k-1]));</code></li>
      <li>หาคำตอบ: $dp(i) = minimum \ element \ in \ multiset + P_i$  <br><code>dp[i] = *ms.begin() + P[i];</code></li>
      <li>ใส่ตัวใหม่: insert $dp(i)$ เข้า multiset <br><code>ms.insert(dp[i]);</code></li>
    </ol>
    <p>เราทำแบบนี้กับทุก $i$; $1 ≤ i ≤ N$ ทำให้มี TC = $O(NlogN)$</p>
  </details>
</details>

[ac code](empty)
