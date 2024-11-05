## toi8_maze
[problem statement](https://programming.in.th/tasks/toi8_maze)

<details>
  <summary>prerequisites</summary>
  <p>bfs (to find shortest path on unweighted graph)</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้ตำแหน่งที่เราอยู่ตอนเริ่มต้น และตำแหน่งที่เราต้องการจะไป โดยเราสามารถเดินได้สี่ทิศทาง ได้แก่ บน, ล่าง, ซ้าย, ขวา ใน grid ที่มีช่องที่ผ่านได้ (1) และไม่ได้ (0)</p>
  <p>โดยเราสามารถใช้ระเบิด ซึ่งมีอยู่ 1 ลูก ระเบิดช่องที่ผ่านไม่ได้ให้ผ่านได้ได้ โดยโจทย์ถามหาจำนวนช่องที่ระเบิดแล้วทำให้เราไปจุดม่งหมายได้ และจำนวนช่องที่ผ่านน้อยที่สุดในการเดิน</p>
  <p>เราสามารถมองโจทย์ข้อนี้เป็นปัญหา shortest path ใน unweighted graph ซึ่งสามารถแก้ด้วย bfs (breadth-first search) โดยเราจะทำการ bfs จากตำแหน่งเริ่มต้นและตำแหน่งเป้าหมาย โดยจะดูว่ามีเส้นทางมาบรรจบกันได้ไหมในแต่ละช่องที่เป็น 0 โดยในแต่ละเส้นทางที่เป็นไปได้เราจะเก็บจำนวนช่องน้อยสุดไว้. TC = $O(MN)$</p>
  <p align="center"><video src="https://github.com/user-attachments/assets/11af01ac-932b-4baa-a4ba-43095953ec92" width="600" autoplay></video></p>
</details>

[ac code](./toi08_maze.cpp)
