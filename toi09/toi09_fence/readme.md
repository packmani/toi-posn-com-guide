## toi9_fence
[problem statement](empty)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>$N \leq 500$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>เราไล่หาขนาดสี่เหลี่ยมทุกขนาดได้เลย?</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>prefix sum</li>
    <li>2D prefix sum</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถมองโจทย์ข้อนี้เป็นการหาผลบวกได้ โดยถ้าเราใส่ค่าในตำแหน่งที่มีต้นไม้เป็น 1 ใน grid. สี่เหลี่ยมกลวงที่เราสร้างต้องมีผลบวกกรอบ = 0. เนื่องจาก $N \leq 500$, เราจึงต้องหาวิธีที่ทำในประมาณ $O(N^3)$ หรือเร็วกว่า</p>

  <details>
    <summary>Solution 1 (prefix sum)</summary>
    <p>เราสามารถแก้โจทย์นี้ได้ด้วยการใช้ prefix sum แบบ 2 มิติ เพื่อคำนวณผลรวมของสี่เหลี่ยมได้อย่างรวดเร็ว</p>
    <p>เราจะใช้ $qs_0(i, j)$ เป็น prefix sum แนวนอนจนถึง $j$ ในแถวที่ $i$:</p>
    <ul>
      <li>จาก $(i, 0)$ ไปจนถึง $(i, j)$</li>
    </ul>
    <p>และใช้ $qs_1(j, i)$ เป็น prefix sum แนวตั้งจนถึง $i$ ในคอลัมน์ที่ $j$:</p>
    <ul>
      <li>\[
      \begin{array}{c}
      (0, j) \\
      \downarrow \\
      (i, j)
      \end{array}
      \]</li>
    </ul>
    <p>จากภาพ เราจะสามารถแบ่งกรอบเป็น 4 ส่วนได้คือ $h_1, h_2, v_1, v_2$ โดยที่ $k$ เป็นขนาดของกรอบ</p>
    <p>∙ $h_1 = \sum[(i, j-k+1) \rightarrow (i, j)] = qs_0(i, j) - qs_0(i, j-k)$</p>
    <p>∙ $h_2 = \sum[(i-k+1, j-k+1) \rightarrow (i-k+1, j)] = qs_0(i-k+1, j) - qs_0(i-k+1, j-k)$</p>
    <p>∙ $v_1 = \sum \begin{array}{c} (i-k+1, j) \\ \downarrow \\ (i, j) \end{array} = qs_1(j, i) - qs_1(j, i-k)$</p>
  </details>

  <details>
    <summary>Solution 2 (2D prefix sum)</summary>
    <p>ในวิธีนี้ เราจะสร้าง 2D prefix sum $qs(i, j)$ ที่เก็บผลรวมของพื้นที่จาก $(0, 0)$ ไปจนถึง $(i, j)$</p>
    <p>คำนวณ 2D prefix sum ได้จาก:</p>
    <p>$$
    qs(i, j) = a_{ij} + qs(i-1, j) + qs(i, j-1) - qs(i-1, j-1)
    $$</p>
    <p>จากนั้นเราสามารถหาผลรวมของพื้นที่สี่เหลี่ยมจาก $(x_1, y_1)$ ไป $(x_2, y_2)$ ได้ในเวลา $O(1)$:</p>
    <p>$$
    \text{sum} = qs(x_2, y_2) - qs(x_1-1, y_2) - qs(x_2, y_1-1) + qs(x_1-1, y_1-1)
    $$</p>
  </details>
</details>

[ac code](empty)
