## toi14_space_1
[problem statement](https://api.otog.in.th/problem/doc/629)
<details>
  <summary>solution</summary>
  <p><ins>idea</ins>: </p>
  <ul>
    <li>DFS/BFS หารูปทรง</li>
    <li>หาสี่เหลี่ยมที่สามารถครอบรูปทรงได้พอดี แล้วนำมาคำนวนว่าเป็นรูปอะไร หากเป็นสี่เหลี่ยมจัตุรัส จำนวนเลข 1 ที่พบในก้อนนั้นๆจะเท่ากับขนาดของ boarder box พอดี แต่หากจำนวนเลข 1 น้อยกว่าขนาดของ boarder box ก็ต้องมาพิจารณาดูอีกทีว่าเป็นรูปทรงอะไร สังเกตว่ารูปสามเหลี่ยมจะมีขนาด 1+3+5+... ดังนั้น หากจำนวนเลข 1 ในก้อนนั้นๆเท่ากับ n+(n*(n-1)) โดยที่ n คือความกว้างของ boarder box แสดงว่าเป็นรูปสามเหลี่ยมหน้าจั่ว</li>
    <p align="center">
      <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/111132208/7b40dba4-145d-4614-878c-51e693194044"/>
    </p>
  </ul>
  <p><ins>time complexity:</ins></p>
  <ul>
    <li>มี array ขนาด n*m ต้อง traverse ทุก index อยู่แล้ว ดังนั้น time complexity O(nm)</li>
  </ul>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>traverse array ด้วย DFS/BFS</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>หา boarder ของรูปทรงและใช้ในการคำนวน</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>สังเกตว่ารูปสามเหลี่ยมหน้าจั่วจะมีขนาด 1+3+5+...</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>DFS/BFS, math</p>
</details>

[ac code](./toi14_space_1.cpp) 
