## toi8_schedule
[problem statement](https://programming.in.th/tasks/toi8_schedule)

<details>
  <summary>prerequisites</summary>
  <p>Dynamic programming</p>
</details>

<details>
  <summary>variable definition</summary>
  <p>$M$ - ระยะเวลามากสุดที่สามารถใช้เครื่องได้ในแต่ละวัน</p>
  <p>$N$ - จำนวนขั้นตอนขั้นในงานที่ 1 และ 2</p>
  <p>$J_i$ - เวลาที่ใช้ในการทำขั้นตอนที่ $i$ ในงานที่ 1 ; $1 ≤ i ≤ N$</p>
  <p>$K_i$ - เวลาที่ใช้ในการทำขั้นตอนที่ $i$ ในงานที่ 2; $1 ≤ i ≤ N$</p>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>หาค่าน้อยสุด และ $N ≤ 1000$</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>dynamic programming</p>
    </details>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ต้องการให้เราหาจำนวนวันที่น้อยที่สุดและจำนวนนาทีที่ใช้ในวันสุดท้ายในการทำงานทั้ง 2 ให้เสร็จ โดยในแต่ละงานเราต้องทำขั้นตอนเรียงไปที่ละอันดับ ซึ่งเราสามารถแก้โจทย์ข้อนี้ด้วย dynamic programming ได้ โดยเราจะนิยาม $dp(i, j)$ คือคำตอบที่ดีที่สุดที่ถ้าเราทำงานที่ 1 ไป $i$ งานแรกและ งานที่ 2 ไป $j$ งานแรก โดยเราจะเก็บ 2 ค่าจำนวนวันที่ใช้ ซึ่งจะใช้เป็น <code>dp(i, j).first</code> และจำนวนนาทีที่ใช้ในวันล่าสุด ซึ่งจะใช้เป็น <code>dp(i, j).second</code> (<code>dp(i, j)</code> return เป็น <code>std::pair<int,int></code> ซึ่งจะเปรียบเทียบตาม <code>.first</code> ก่อน ถ้าเท่ากันจะเทียบตาม <code>.second</code>)</p>
  <p>เราจะได้ transition แบ่งเป็น 2 กรณีคือ:</p>
  <ol>
    <li>ขึ้นวันใหม่ เกิดเมื่อ $K_i + dp(i-1, j).second > M$ หรือ $J_j + dp(i, j-1).second > M$ ซึ่งมี transition คือ:</p>
      <p>$dp(i, j) = min(\\{dp(i-1, j).first + 1, K_i\\}, \\{dp(i, j-1).first + 1, J_j\\})$</p>
    </li>
    <li>ทำวันเดิมต่อ เกิดเมื่อ $K_i + dp(i-1, j).second ≤ M \\ และ \\ J_j + dp(i, j-1).second ≤ M$ ซึ่งมี transition คือ:</p>
      <p>$dp(i, j) = min(\\{dp(i-1, j).first, dp(i-1, j).second + K_i\\}, \\{dp(i, j-1).first, dp(i, j-1).second + J_j\\})$</p>
    </li>
  </ol>

  <p>คำตอบที่โจทย์ถามก็คือ $dp(N, N).first$ และ $dp(N, N).second$ ตามลำดับ. TC = $O(N^2)$</p>
</details>

[ac code](./toi08_schedule.cpp)
