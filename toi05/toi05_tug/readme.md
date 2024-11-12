## toi5_tug
[problem statement](https://programming.in.th/tasks/toi5_tug)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ลองวาดออกมาบนเส้นจำนวนดู</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>greedy</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>sorting</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Greedy</li>
    <ul>
      <li>Sorting</li>
      <ul>
        <li><code>std::sort</code></li>
      </ul>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถแปลงโจทย์ได้เป็นคือเรามี set ของ จุดบนเส้นจำนวน 1 มิติ 2 set ให้เป็น set $A$ และ $B$ โดยที่ทั้ง 2 set ขนาด $N$ $(|A| = |B| = N)$ โจทย์ให้เราหาผลรวมความยาวเส้นที่ลากเชื่อมระหว่างจุดใน set $A$ เชื่อมกับ set $B$ แบบ 1 ต่อ 1 โดยที่ทุกจุดต้องโดนเชื่อม โดยที่เราสามารถแก้โจทย์ข้อนี้แบบ greedy ได้เลยโดยที่เราจะเรียงจุดจากน้อยมามาก แล้วเชื่อมจุดที่ $x$ น้อยสุดจาก $A$ กับ จุดที่ $x$ น้อยสุดจาก $B$, เชื่อมจุดที่ $x$ น้อยรองลงมาจาก $A$ กับจุดที่ $x$ น้อยรองลงมาจาก $B$...</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/ad1c7207-b122-4fbe-b05b-55849264dcbd" alt="number_line.jpg" /></p>
  <hr>
  <details>
    <summary>Why?</summary>
    <p>Algorithm ของเราให้คำตอบที่ดีที่สุดเสมอคือ $\sum_{i=1}^N |B_i - A_i|$; $(B_1 ≤ B_2 ≤ … ≤ B_n) \land (A_1 ≤ A_2 ≤ … ≤ A_n)$</p>
    <p>สมมติว่า Algorithm ของเราไม่ได้ให้คำตอบที่ดีสุดเสมอ</p>
    คือมี $\sum_{i=1}^N |B^\prime_i - A^\prime_i|$ ที่ $≤ \sum_{i=1}^N |B_i - A_i|; (A \neq A^\prime) \lor (B \neq B^\prime)$
    <ul>
      <li>เราสามารถสร้าง $B_i^\prime$ จาก $B$ ได้โดยการสลับ element ใน $B$</li>
      <li>เราสามารถสร้าง $A_i^\prime$ จาก $A$ ได้โดยการสลับ element ใน $A$ </li>
    </ul>
    <p>แต่เราสามารถพิสูจน์ได้ว่าการสลับไม่ทำให้ได้คำตอบที่ดีขึ้น</p>
    สมมติเราสลับคู่ $i$ และ $j$ คือเราจะเปรียบเทียบ
    <ul>
      <li>$|B_i - A_i| +  |B_j - A_j|$ กับ $|B_j - A_i| - |B_i - A_j|$ $(|B_i^\prime - A_i^\prime| -  |B_j^\prime - A_j^\prime|)$</li>
      <li>เราจะได้ว่า $|B_i - A_i| +  |B_j - A_j|  \leq  |B_j - A_i| - |B_i - A_j|$ เสมอ</li>
    </ul>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/8ba0229b-cdb3-4199-88af-dcda1bb20048"/></p>
    <p align="center">[ภาพตัวอย่าง case ที่อาจเกินขึ้นได้โดยที่ทุกเคสการสลับไม่ทำให้คำตอบดีขึ้น]</p>
  </details>
  <hr>
  <strong>Pseudocode</strong>
  <pre><code>
  sort A
  sort B
  Ans = 0
  for i in range [1 ... N] : 
	Ans = Ans + |A[i] - B[i]|
  output Ans
  </code></pre>
</details>

[ac code](./toi05_tug.cpp)
