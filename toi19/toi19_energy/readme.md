## toi19_energy

[problem statement](https://programming.in.th/tasks/toi19_energy)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>N ≤ 300 และ ให้หาจำนวนวิธี?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>$N^3$</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisite</summary>
  <p>dynamic programming, MCM</p>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถแก้โจทย์ข้อนี้ด้วย dynamic programming ได้โดยที่เราเราจะกำหนด $dp(lv, i, j)$ คือจำนวนวิธีในการสร้างแบ่ง array เมื่อเราสร้างขึ้นมาจนถึง level ที่ $lv$ และพิจารณาช่วง $[i, j]$ โดยเราจะค่อยๆสร้างคำตอบจากล่างขึ้นมาด้านบนคือไล่ $lv$ จาก $k, k-1, \ldots, 1$. transition คือ $dp(lv, i, j) = \sum(dp(lv+1, i, x) \cdot dp(lv+1, x+1, j) \mod 1e9 + 7)$; ผลต่างผลบวก $A$ ในช่วง $[i, x]$ และ $[x+1, j] \leq d$ และ $i \leq x < j$ และ base case ก็คือ $dp(k, i, j) = 1, i \leq j$</p>
  <p align="center">
    <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/8e4f005f-d665-48e5-b7e8-7bdaed223d8d" />
  </p>
</details>

[ac code](empty)
