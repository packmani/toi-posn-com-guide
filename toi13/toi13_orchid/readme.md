## toi13_orchid
[problem statement](empty)

<details>
  <summary>hints</summary>
  <p>แทนที่เราจะไปหาจำนวนที่ต้องมาเปลี่ยนน้อยที่สุดเราสามารถหาจำนวนที่ไม่ต้องมาเปลี่ยนที่มากสุด?</p>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>LIS - (binary search / range query data structure) <a href="https://cp-algorithms.com/sequences/longest_increasing_subsequence.html">Longest increasing subsequence - Algorithms for Competitive Programming (cp-algorithms.com)</a></li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราหาจำนวนต้นกล้วยไม้ที่ต้องมาเปลี่ยนที่น้อยที่สุดที่ทำให้ต้นไม้ทั้งหมดเป็น non-decreasing sequence ทำให้เรานึกถึงปัญหา LIS (longest increasing subsequence). แทนที่เราจะหาจำนวนที่เอาออกน้อยสุดเราไปหาจำนวนของที่ไม่ต้องเอาของมากสุดซึ่งนั่นก็คือ ความยาวของ LIS ของต้นกล้วยไม้ทั้งหมด ซึ่งคำตอบของเราก็คือ (จำนวนต้นกล้วยไม้ทั้งหมด) - (ความยาว LIS) เพราะเราสามารถหาต้นไม้มาแทนที่ตำแหน่งที่เอาออก (ไม่ได้อยู่ใน LIS ที่เราเลือก) มาแทนได้เสมอซึ่งก็คือ ความสูงของต้นกล้วยไม้ด้านหน้า</p>
  <details>
  <summary><ins>Sol 1 - dynamic programming (TLE)</ins></summary>
  <p>เราจะนิยาม $dp[i]$ = ความยาวของ LIS ในช่วงตั้งแต่เริ่มต้นจนถึง $i$ (prefix) โดยเราสามารถคิด $dp[i]$ ได้จาก $dp[i] = max({dp[j] + 1}), h[j] \leq h[i]$ และ $0 \leq j < i$ (0-based indexed). โดย base case คือ $dp[0] = 1$ แต่ปัญหาของเราก็คือในการของคำตอบของ $dp[i]$ ในแต่ละรอบเราต้อง loop เพื่อหาค่า $j$ ที่ $h[j] \leq h[i]$ ทำให้ $TC$ เป็น $O(N^2)$ ซึ่งไม่เร็วพอ</p>
  </details>
  <details>
  <summary><ins>Sol 2 - binary search</ins></summary>
  <p>เราสามารถหา LIS ได้โดยการทำ patience sorting (see more in toi18_garden). $TC = O(NlogN)$</p>
  </details>
  <details>
  <summary><ins>Sol 3 - range query</ins></summary>
  <ul>
  <li>จาก Sol 1 เราจะทำการ optimize การไล่หา $j$ ที่เหมาะสมโดยใช้ range query data structure (segment tree/fenwick tree). โดยเราจะแก้เงื่อนไขที่ว่า $h[j] \leq h[i]$ โดยการนำแต่ละตำแหน่งของ $h[i]$ ของแต่ละต้นกล้วยไม้ไปใส่ใน range query data structure ในที่นี้เราจะใช้เป็น fenwick tree โดยการที่เราจะนำ $h[i]$ ไปใส่ได้เราต้องทำการ coordinate compress ก่อนเพื่อให้เราสามารถใส่ใน array ได้ เช่น เรามี $h = \\{100, 300, 350, 400\\}$ หลัง compress จะได้ $h’ = {1, 2, 3, 4}$ โดยขอเรียกตำแหน่งหลังการ compress ว่า $pos(h[i])$.</li>
  <li>เราจะ loop จากซ้ายในแต่ละรอบ $i$, เราจะหา $dp[i]$ ได้จาก $max$ ในช่วง $[1, pos(h[i])] + 1$ โดยการ query ใน fenwick tree และทำการ update ค่าตำแหน่ง $pos(h[i])$ ด้วย $dp[i]$. โดย LIS ของเราก็คือ $max(\\{dp[i]\\})$</li>
  <li>$TC = O(NlogN)$</li>
  </ul>
  </details>
</details>

[ac code sol2](./toi13_orchid_bsearch.cpp)<br>
[ac code sol3](./toi13_orchid_fenwick.cpp)
