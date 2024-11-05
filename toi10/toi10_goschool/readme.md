## toi10_goschool
[problem statement](https://programming.in.th/tasks/toi10_goschool)

<details>
  <summary>hint</summary>
  <p>หาจำนวนวิธี?</p>
</details>

<details>
  <summary>prerequisites</summary>
  <p>dynamic programming</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราหาจำนวนวิธีจาก $(1, 1)$ ไป $(m, n)$ โดยที่บางจุดเราไม่สามารถไปได้ (มีหมาเจ้าพ่อ) โดยที่เราสามารถเดินขึ้นกับเดิมไปทางขวาได้. เราสามารถแก้โจทย์ข้อนี้ใช้ dynamic programming ได้. ให้ $dp(i, j)$ คือจำนวนวิธีการเดินจาก $(1,1)$ มา $(i, j)$. base case คือ $dp(1, 1) = 1$ และ transition มี 2 กรณี:</p>

  <ol>
    <li>$(i, j)$ มีหมาเจ้าพ่อ:
      <p><code>dp(i, j) = 0</code></p>
    </li>
    <li>$(i, j)$ ไม่มีหมาเจ้าพ่อ:
      <p><code>dp(i, j) = dp(i-1, j)</code> [ขึ้นบน] + <code>dp(i, j-1)</code> [ไปขวา]</p>
    </li>
  </ol>

  <p>คำตอบของเราก็คือ $dp(m, n)$</p>

  <p><strong>*ข้อควรระวัง:</strong> เนื่องจากจำนวนวิธีอาจ > $INT\_MAX$ เราจึงใช้ <code>long long</code> ในการเก็บคำตอบ</p>
</details>

[ac code](./toi10_goschool.cpp)
