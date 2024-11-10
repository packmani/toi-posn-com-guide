## toi4_logistics

[problem statement](https://programming.in.th/tasks/toi4_logistics)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Graph Transversal</li>
    <ul>
      <li>BFS (Breath-First Search)</li>
    </ul>
  </ul>
  <ul>
    <li>Sorting</li>
    <ul>
      <li><code>std::sort</code></li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary><br>
  <p>โจทย์ให้กราฟที่เป็นคล้ายกราฟเส้นตรงแต่มี multiple edge ได้โดยที่มีจุดเริ่มต้นที่ $X$ และจุดจบที่ $Y$ และอาจจมีจุดยอดระหว่างทาง $a - z$. โจทย์ให้หา median ของค่า weight ของ edge ที่เป็น multiple edge กัน และผลรวมของ median. ซึ่งเราก็จะทำตรงๆได้เลย ตามโจทย์</p>
  <p><strong><ins>implementation</ins></strong></p>
  <p>เนื่องจากเราต้องเก็บค่า median โดยที่มีจุดยอด ($u - v$) ที่เชื่อมเป็นเกณฑ์ (ถ้า $u - v$ เหมือนกันเอา weight มาหา median กัน) เราจึงต้องเก็บค่า median โดยที่มี map กับ $(u, v)$ ซึ่งก็สามารถ implement ได้โดยใช้ <code>std::map<std::pair<int,int>></code> ซึ่งก็โอเคสำหรับข้อนี้ แต่ถ้าโจทย์ที่มี constraint สูง เราควรหลีกเลี่ยงการใช้ map เพราะมีความเสี่ยงที่จะ TLE โดยเราสามารถทำการ map ได้โดยการทำ coordinate compression 
    <a href="https://www.youtube.com/watch?v=2noC-1bv5Kc">Line Sweep Algorithms and Coordinate Compression</a> ทำให้เราสามารถ hash จาก pair เป็น index ใน array ได้ (ใน code ใช้ชื่อ array ว่า cp) </p>
  <hr>
  <p>เนื่องจากเราต้อง check หา path จาก $X$ ไป $Y$ เราจึงต้อง transverse graph โดยในที่นี้เราจะใช้ BFS โดยการใช้ queue (<code>std::queue</code>) ที่เหลือเราก็แค่เก็บคำตอบเราไว้ส่งออกตอนท้าย</p>
  <p>$TC = O(NlogN)$</p>
</details>

[ac code](./toi04_logistics.cpp)
