## toi14_logistics
[problem statement](https://programming.in.th/tasks/toi14_logistics)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>Graph</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <ul>
        <li><details><summary>Construct new graph</summary>add states</details></li>
      </ul>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Dijkstra's algorithm</li>
    <li>dynamic programming</li>
  </ul>
</details>

<details>
  <summary>solution</summary><br>
  จากการสังเกตที่ constraint น้อยๆ ทำให้เรานึกถึง dynamic programming (เก็บ state ข้อมูลที่จำเป็น). การที่ให้หาค่าน้อยสุดบน graph ทำให้เรานึกถึง shortest path algorithm เนื่องจากโจทย์ให้ source มา 1 source ($S$) ทำให้เรานึกถึง Dijkstra’s algorithm. ยังรัน Dijkstra บนกราฟที่โจทย์ให้มาเลยไม่ได้ เพราะกราฟที่ให้มามีข้อมูลไม่มากพอ เพราะฉะนั้นเราจะทำการ construct กราฟใหม่โดยข้อมูลที่สำคัญกับเรามีได้แก่
  <ul>
    <li>จุดที่เราอยู่ปัจจุบัน ($u$)</li>
    <li>เชื้อเพลิงที่เหลือตอนนี้ ($uf$)</li>
    <li>ใช้บัตรกำนัลไปแล้วหรือยัง ($used$)</li>
  </ul>
  <hr>
  เราจะนำ $(u, uf, used)$ มาสร้างกราฟใหม่ โดยที่ให้ source เป็น $(S, 0, false)$. กำหนดให้
  <ul>
    <li>$d(u, uf, used)$ คือค่าใช้จ่ายที่น้อยที่สุดในการเดินทางจาก $(s, 0, false)$ มา $(u, f, used)$; $used = true$ เมื่อใช้บัตรกำนัลไปแล้ว, $used = false$ เมื่อยังไม่ใช้บัตรกำนัล</li>
    <li>$d(S, 0, false) = 0$ (source)</li>
  </ul>
  
  เราสามารถแบ่งการ transition เป็น 2 แบบคือ:
  <ol>
    <li>เติมเชื้อเพลิงที่เมือง $u$  
      <ol>
        <li>เติมแบบมีค่าใช้จ่ายตอนที่ยังเติมได้ ($f < F$)
          <ul>
            <li>$d(u, uf + x, used) = d(u, uf, used) + x \cdot p_u$</li>
            <li>แต่เราไม่จำเป็นต้องไล่ $x$ ทุกค่า เราใช้ $x = 1$ ก็พอ
              <ul>
                <li>สมมติเราจะเติม 3 หน่วย: $d(u, uf+3, used) = d(u, uf, used) + 3 \cdot p_u$</li>
                <li>เหมือนกับการที่เราไล่ $+1$ ไป 3 รอบ: $d(u, uf, used) \rightarrow d(u, uf+1, used) \rightarrow d(u, uf+2, used) \rightarrow d(u, uf+3, used)$</li>
              </ul>
            </li>
            <li>Transition: $d(u, uf+1, used) \leftarrow d(u, uf, used) + p_u$</li>
          </ul>
        </li>
        <li>เติมแบบใช้บัตรกำนัล ($used = false → used = true$)
          <ul>
            <li>เมื่อเราได้เติมฟรี ไม่มีเหตุผลที่เราจะเติมไม่เต็มถัง → เติมจน $F$</li>
            <li>$d(u, F, true) \leftarrow d(u, uf, false)$</li>
          </ul>
        </li>
      </ol>
    </li>
    <li>เคลื่อนจากเมือง $u$ ไป $v$ (เมื่อมีเส้นเชื่อมระหว่างเมือง $u$ และ $v$ และมีเชื้อเพลิงมากพอ, $W \leq F$)
      <ul>
        <li>เราจะเคลื่อนจาก $u$ ไป $v$ ได้เมื่อเชื้อเพลิงที่ใช้ในการเคลื่อนจาก $u$ ไป $v$ ($W$) $≤$ เชื้อเพลิงปัจจุบัน ($f$)</li>
        <li>$d(v, uf - w, used) \leftarrow d( u, uf, used)$</li>
      </ul>
    </li>
  </ol>

  ---

  <p>เนื่องจาก graph นี้อาจจะมี cycle ทำให้เราไม่สามารถทำ dynamic programming ตรงๆตาม <strong>topological order</strong> ได้ <a href="https://usaco.guide/gold/toposort">Topological Sort · USACO Guide</a> แต่เราถามหาค่าน้อยสุดทำให้เราสามารถ Run Dijkstra’s Algorithm เพื่อหา shortest path ได้ โดยที่เรามี:</p>

  <ul>
    <li><strong>source</strong> = $(S, 0, false), d(s, 0, false) = 0$</li>
    <li><strong>destination</strong> = $d(D, F, true), Ans = d(D, F, true)$</li>
      <ul>
        <li>ตอนจบเราต้องเติมเชื้อเพลิงให้เต็ม $F$</li>
        <li>คำตอบของการที่เราใช้บัตรกำนัลไม่แย่กว่าการที่เราไม่ใช้</li>
      </ul>
  </ul>
  <hr>
  <p>Time Complexity ของเราจะเทียบกับ $TC$ ของ Dijkstra’s algorithm ซึ่งเราคำนวณเป็น $O(MlogM)$ เมื่อ $M$ คือจำนวนเส้นเชื่อม. ซึ่งในกราฟใหม่ของเราจะมี edge เพิ่มเป็นจาก $E' = E \cdot 2(F+1)$ ทำให้ได้ $TC' = O(EF \cdot logEF)$</p>
</details>

[ac code ver1](./toi14_logistics.cpp)<br>[ac code ver2](./toi14_logistics2.cpp)
