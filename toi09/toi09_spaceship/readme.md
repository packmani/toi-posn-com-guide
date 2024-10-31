## toi9_spaceship
[problem statement](https://programming.in.th/tasks/toi9_spaceship)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>m &lt;= 10</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>bitmask</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>bitmask dynamic programming</ins></p>
</details>

<details>
  <summary>variable definition</summary>
  <ul>
    <li>$(x, y)$ - พิกัดจุดเริ่มต้น</li>
    <li>$m$ - จำนวนร้านค้า</li>
    <li>$n$ - จำนวนชุดของคอมพิวเตอร์อย่างน้อยที่ต้องการประกอบ</li>
    <li>$M_i$ - จำนวนมอนืเตอร์ในร้านที่ $i$</li>
    <li>$K_i$ - จำนวนคีย์บอร์ดในร้านที่ $i$</li>
    <li>$C_i$ - จำนวนตัวเครื่องในร้านที่ $i$</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p><br>โจทย์ให้เราหาระยะทางรวมที่น้อยที่สุด ในการไปร้านค้าเพื่อหาชิ้นส่วนมาประกอบเป็นคอมพิวเตอร์ได้อย่างน้อย $n$ เครื่อง ก็คือ $\text{min}(\{ \sum M_i, \sum K_i, \sum C_i \}) \geq n$. เนื่องจาก $m \leq 10$ ทำให้เราสามารถเลือก subset ร้านค้าที่เราจะไปได้โดยมีจำนวนทั้งหมด $2^{m+1}$ subset (เราเอาจุดเริ่มต้นไว้ใน set ด้วย) และเขาให้เราหาระยะทางสั้นสุดทำให้เรานึกถึง dynamic programming.</p>
  <p>เราจะนิยาม $dp(\text{mask}, u)$ แทนระยะทางที่ทางในการเดินทางจากจุดเริ่มต้นไปร้านค้าที่อยู่ใน $\text{mask}$ โดยที่ร้านสุดท้ายที่ไป (ที่เราอยู่ตอนนี้) คือ ร้านที่ $u$. เราจะ represent $\text{mask}$ เป็นเหมือน set โดยที่ใช้ระบบเลขฐานสอง โดยถ้า $\text{mask} = (1001011)_2 = \{ 0, 1, 3, 6 \}$ (เราให้เสมือนให้จุดเริ่มต้นเราเป็นร้านที่ 0).</p>
  <ul>
  <li>Base case ของเราคือ $dp(\{0\}, 0) = 0 \rightarrow dp(1, 0) = 0$.</li>
  <li>แล้วมี transition ก็คือ $dp(S, u) = \min(\{ dp(S - \{ u \}, v) + \text{dist}(u, v) \}) \forall v \in (S - \{ u \}), \text{dist}(u, v)$เป็นกำลังสองของ Euclidean distance ระหว่าง $u$ และ $v$, และ $S$ เป็น set ที่เก็บร้านค้าที่ไปมาแล้ว</li>
  <li>หรือในรูป bitmask ก็ได้เป็น $dp(\text{mask}, u) = \min(\{ dp(\text{mask} \oplus 2^u, v) + \text{dist}(u, v) \}) \oplus$ คือ bitwise XOR</li>
  </ul>
  <p>คำตอบของเราก็คือค่า $\min(\{ dp(\text{mask}, u) \})$ โดยที่ $\text{min}(\{ \sum M_i, \sum K_i, \sum C_i \}) \geq n$; $i \in \text{mask}$ (สามารถสร้างคอมพิวเตอร์ได้อย่างน้อย $n$ เครื่อง).</p>
  
  <p><ins>Time Complexity:</ins> $O(m^2 * 2^m)$</p>

  <video src="https://github.com/user-attachments/assets/0ffc32ca-db83-4c69-b370-4355623fc483" width="600" autoplay></video>
</details>

[ac code](./toi09_spaceship.cpp)
