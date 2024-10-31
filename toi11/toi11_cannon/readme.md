## toi11_cannon
[problem statement](empty)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>การนับจำนวน → หาผลบวก</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>prefix sum</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>prefix sum</li>
    <li>binary search</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <details>
    <summary><ins>Sol 1 (prefix sum)</ins></summary>
    <p>เราสามารถมองรางลำเลียงเป็นเหมือนช่วงบนเส้นจำนวนได้ที่ยาว $2L$ และมีจุดลำเลียงที่ตำแหน่ง $m_j$ เราสามารถมองเได้เป็นช่วง $[m_j - L, m_j + L]$ ในเป็นช่วง $I_J$ โดยถ้าเรามองปืนใหญ่เป็นจุดบนเส้นจำนวน โจทย์ถามว่าในแต่ละแบบของการวางจุดลำเลียง $I_1 \cup I_2 \cup I_3 \cup … \cup I_M$ จะมีจุดปืนใหญ่รวมอยู่ทั้งหมดกี่จุด</p>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/34311cba-6317-401a-a919-3d6ba0495a78" /></p>
    <p>โดยที่เรามองเป็นปัญหาของการหาผลบวกในช่วงได้ โดยที่เพื่อป้องกันการนับซ้ำเราจะมองช่วงที่ทับซ้อนกันรวมกันเป็นช่วงเดียว ทำให้เราสามารถหาผลบวกในแต่ละช่วงที่ไม่ทับซ้อนกันได้ด้วย prefix sum (เนื่องจาก $n_i \leq 9999999$ ทำให้เราใช้ array เก็บเป็น index ได้)</p>
    <p>กำหนดให้ $qs[i]$ เก็บจำนวนปืนใหญ่ในช่วง $[0, i]$</p>
    <ol>
      <li>นำปืนใหญ่ไปใส่ในเส้นจำนวน → $qs[i] += 1$</li>
      <li>ทำการ sweep จากซ้ายมาขวา → $qs[i] += qs[i-1]$</li>
      <li>ในแต่ละรูปแบบของการจัดเรียงรางปืนใหญ่
        <ul>
          <li>หาผลบวกของแต่ละช่วง</li>
          <li>ในกรณีที่ช่วงทับซ้อนกันเราจะป้องกันด้วยการแบ่งช่วง</li>
        </ul>
        <p align="center"><img width="600" src="https://github.com/user-attachments/assets/193b755b-6b6b-4506-9014-29030cbb910f" /></p>
      </li>
      <li>ตอบผลรวมทั้งหมด</li>
    </ol>
  </details>
  <details>
    <summary><ins>Sol 2 (binary search)</ins></summary>
    <p>เราจะทำคล้ายกับ <ins>Sol 1</ins> แต่แทนที่จะเป็นการหาผลบวกจะเป็นการ binary search หา index ที่อยู่ซ้ายที่สุดที่มีค่า $\geq m_j - l$ และ binary search หา index ที่อยู่ขวาที่สุดที่มีค่า $\leq m_j + l$ ส่วนในกรณีที่ช่วงซ้อนกันเราก็ใช้วิธีเดียวกันกับ <ins>Sol 1</ins> เลยคือการแบ่งเป็นช่วงย่อยๆ</p>
  </details>
</details>

[ac code sol1](./toi11_cannon_prefsum.cpp)<br>
[ac code sol2](./toi11_cannon_bsearch.cpp)
