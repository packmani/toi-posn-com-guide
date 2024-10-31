## toi15_budget
[problem statement](https://programming.in.th/tasks/toi15_budget)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เราสามารถแบ่งโจทย์ข้อนี้ได้เป็น 2 ส่วนหลักๆ คือ ส่วนของการเลือกทางที่ยังไม่มีหลังคาที่เหมาะสมมาสร้างหลังคา และ ส่วนของการเลือก package ที่เหมาะสมมาใช้สร้างแต่ละหลังคา</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>โจทย์ต้องการให้เราเชื่อมให้ทุกอาคารไปหากันได้ เราสามารถใช้ data structure อะไรที่สามารถ check คุณสมบัตินี้ได้ ?</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>DSU (Union-find data structure)</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>DSU, Kruskal’s MST algo, binary search / Range query data structure</p>
</details>

<details>
  <summary>solution</summary>
  <p>Part 1 → เลือก edge ที่จะสร้างให้เหมาะสม</p>
  <ul>
    <li>เราสามารถมองโจทย์ข้อนี้เป็นกราฟได้ โดยแต่ละอาคารเป็น node และทางเชื่อมเป็น undirected weighted edge โดยมี edge 2 ประเภทที่ edge ที่อยู่ใน graph แล้ว และ edge ที่อาจจะสร้าง โดยเราสามารถ greedy เลือก edge ที่ยังไม่ได้สร้างได้โดยเลือก edge ที่มี weight น้อยและเป็นการเชื่อม 2 component ที่ไม่ได้อยู่เชื่อมกันให้เชื่อมกันตาม Kruskal’s algorithm </li>
  </ul>
  <p>Part 2 → เลือก package มาสร้างแต่ละ edge ให้ cost รวมน้อยสุด</p>
  <ul>
    <li>พิจารณา edge ที่เราจะสร้างที่มี weight = w, การที่จะหา package ที่เหมาะสมก็คือ package ที่มีระยะการสร้างรับเหมา ≥ w และมีราคาการสร้างน้อยที่สุด</li>
  </ul>
  <p>Sol 1 - Brute force (TLE)</p>
  <ul>
    <li>ไล่หาแต่ละ package ที่ระยะรับเหมา ≥ w โดยเก็บ package ที่ราคาน้อยสุด สำหรับแต่ละ edge</li>
  </ul>
  <p>Sol 2 - Binary Search</p>
  <ul>
    <li>เราสามารถมองระยะรับเหมาเป็นเหมือนเส้นจำนวนได้และแต่ละจุดจะเป็นราคาไว้ โดยที่เราก็แค่หาวิธีที่สามารถหา ค่าน้อยที่สุดใน ช่วง ≥ w ซึ่งสามารถแก้ได้โดยการใช้ dynamic programming โดยที่เราจะ sort package ตามระยะรับเหมาจากน้อยไปมาก และกำหนดให้ <code>dp(i) = ราคาการสร้างที่น้อยที่สุด</code> ถ้าสร้างหลังคา ≥ ระยะ i <br>โดยที่เราจะได้ recurrence คือ <code>dp(i) = min(ราคา i, dp(i+1))</code> โดยที่ base case คือ <code>dp(P-1) = ราคา P-1</code> พอเราต้องการหาคำตอบของแต่ละ edge เราก็ binary search หาตำแหน่งแรกที่มีระยะที่ ≥ w แล้วคำตอบก็คือ dp ของ ณ ตำแหน่งนั้น. คำตอบของโจทย์ก็คือผลรวมค่าใช้จ่ายสำหรับแต่ละ edge ที่สร้าง TC = O(ElogE + PlogP)</li>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/f67a3e44-c924-43fc-b4f0-1fe625dd15d5" /></p>
  </ul>
  <p>Sol 3 - Range query</p>
  <ul>
    <li>เราสามารถใช้ fenwick tree (ประหยัด memory กว่า segment tree)  ในการหา ค่า minimum ในช่วงได้ โดยในแต่ละ edge เราก็ query หาราคาที่น้อยที่สุดในช่วงระยะ ≥ w. TC = O(ElogE + PlogP)</li>
  </ul>
</details>

[ac code sol2](./toi15_budget_bsearch.cpp) <br>
[ac code sol3](./toi15_budget_fenwick.cpp)
