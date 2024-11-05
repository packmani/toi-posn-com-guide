## toi7_sewer
[problem statement](https://programming.in.th/tasks/toi7_sewer)

<details>
  <summary>prerequisites</summary>
  <p>bfs (to find single-source shortest path on unweighted graph)</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราหาเวลาที่น้อยที่สุดที่น้ำสองสายจะมาบรรจบกัน ทำให้เราสามารถใช้ bfs เพื่อหาระยะทางที่น้อยสุดไปแต่ละช่อง จากช่อง $(1, 1)$ โดยโจทย์จะระบุการเชื่อมของท่อมา. กำหนดให้ $D(i, j)$ แทนระยะทางที่สั้นสุดจาก $(1, 1)$ และ $D(1, 1) = 1$ โดยที่:
  <br>$D(i, j) = D(i-1, j) + 1$ เมื่อเรายังไม่เคยมา $(i, j)$ และมีท่อเชื่อมในทิศเหนือ
  <br>$D(i, j) = D(i, j-1) + 1$ เมื่อเรายังไม่เคยมา $(i, j)$ และมีท่อเชื่อมในทิศตะวันตก
  <br>$D(i, j) = D(i+1, j) + 1$ เมื่อเรายังไม่เคยมา $(i, j)$ และมีท่อเชื่อมในทิศใต้
  <br>$D(i, j) = D(i, j+1) + 1$ เมื่อเรายังไม่เคยมา $(i, j)$ และมีท่อเชื่อมในทิศตะวันออก</p>

  <p>การที่น้ำสองสายจะมาบรรจบกัน จะเกิดขึ้นเมื่อมีสองเส้นทางมาบรรจบกันที่เวลาเดียวกัน. โดยเราก็แค่ check ในตอนกำลังจะ transverse จาก $(i, j)$ ไป $(x, y)$ เราก็ดูว่าเราเคยไป $(x, y)$ หรือยัง ถ้าเคยไปแล้ว เรา check ว่า $D(i, j) = D(x, y)$ ไหม ถ้าใช่ก็ตอบเลย เพราะ bfs การันตี shortest path อยู่แล้ว</p>

  <p align="center"><video src="https://github.com/user-attachments/assets/fb8a3314-8a26-4df8-8b3a-dceaad3e1263" width="600" autoplay></video></p>
</details>

[ac code](./toi07_sewer.cpp)
