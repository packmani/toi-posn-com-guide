## toi11_candle
[problem statement](https://programming.in.th/tasks/toi11_candle)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เรามากตารางที่โจทย์ให้มาเป็น data structure อะไรได้</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>undirected graph</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>flood fill (BFS)</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถสรุปโจทย์ข้อนี้ได้เป็นการนับจำนวน connected component โดยเรามอง cell $(i, j)$ ที่มี ‘1‘ เป็น node ที่จะเชื่อม node อีก node ใน 8 ทิศทาง (บน, ล่าง, ซ้าย, ขวา และ ทแยง)</p>
  <p>เรารู้ว่าสำหรับ connected component ใดๆ ไม่ว่าเราจะเริ่ม transverse จาก node ใดก็ตาม ก็สามารถไปหาทุก node ใน component เดียวกันได้ เราจะให้คุณสมบัตินี้ในการนับจำนวน component ซี่งก็เท่ากับจำนวนของการเริ่ม transverse graph</p>
  <ul>
    <details>
      <summary><ins>BFS (Flood Fill)</ins></summary>
      <ol>
        <li>เราไล่ตารางจากแถวบนลงล่าง ซ้ายมาขวา</li>
        <li>ถ้าเราเจอ cell $(i, j)$ แล้วเรายังไม่เคยมา $(i, j)$. เราจะทำการเริ่ม transverse graph ด้วย BFS เพื่อไปหาทุกๆ $(x, y)$ ที่อยู่ใน connected component เดียวกันกับ $(i, j)$ แล้วเราก็ทำการเพิ่ม จำนวน component +1</li>
        <li>ทำแบบนี้ไปจนจบตารางแล้วเราก็จะได้จำนวน component ทั้งหมด</li>
      </ol>
      <p>TC = $O(MN)$</p>
      <p align="center"><video src="https://github.com/user-attachments/assets/87173514-d867-4dc3-b74a-7b45ce64e9da" width="600" autoplay></video></p>
    </details>
    <details>
      <summary><ins>DSU (Union-Find)</ins></summary>
      <p>อีกหนี่งวิธีในการหาจำนวน component คือการใช้ DSU (ซี่งจะเป็น forest) ซี่งเป็นมี function ให้ใช้ 2 function คือ <br>1. การหา root  <br>2. การ Union 2 set เข้าด้วยกัน<br>เราก็แค่เชื่อม node ที่เป็น ‘1‘ ใน 8 ทิศทาง ทำไปจนครบแล้วเราก็นับจำนวน root ที่แตกต่างกันทั้งหมด</p>
    </details>
  </ul>
</details>

[ac code sol1](./toi11_candle_bfs.cpp)<br>
[ac code sol2](./toi11_candle_dsu.cpp)

