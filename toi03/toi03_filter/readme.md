## toi3_filter
[problem statement](https://programming.in.th/tasks/toi3_filter)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Difference Array <a href="https://codeforces.com/blog/entry/78762">[An Introduction To Difference Arrays - Codeforces]</a></li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถมองโจทย์เป็นการทำ Range update คือ $+H$ ในช่วง $[x, x+a)$</p>
  <p>เนื่องจากข้อนี้ constraint ไม่สูงทำให้เราสามารถ brute force ไล่ตรงๆได้เลย แต่ถ้า $W ≤ 10^6$ เราจะทำอย่างไร?</p>
  <hr>
  <p><strong>-Difference array-</strong> (See toi13_art hints)</p>
  <ul>
    <li>เราจะใช้ array $d$ เก็บการค่าที่เปลี่ยนแปง</li>
    <li>เราจะมองการ update $+H$ เป็นการทำ 2 operation</li>
    <ol>
      <li>$d[x] = d[x] + H$</li>
      <li>$d[x+a] = d[x+a] - H$</li>
    </ol>
  </ul>
  <p>แล้วในตอนสุดท้ายเราทำการ sweep ค่าจากซ้ายมาขวา ($d[x] = d[x] + d[x-1]$) เพื่อให้เราได้ค่าในแต่ละช่อง</p>
  เมื่อเราได้ค่าแต่ละช่องแล้วเราก็แค่ดูว่าเป็นช่องที่แสงผ่าน 100% หรือ 50%
  <ul>
    <li>$d[i] = 0$  → ผ่าน 100 %</li>
    <li>$d[i] = H$ → ผ่าน 50 %</li>
  </ul>
  <p>$TC = O(W + n)$</p>
  <hr/>
  <p>Bonus : ถ้า $W ≤ 10^9$ เรายังทำได้ไหม? (See toi13_art)</p>
</details>

[ac code](./toi03_filter.cpp)
