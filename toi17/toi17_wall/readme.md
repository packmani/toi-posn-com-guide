## toi17_wall
[problem statement](https://programming.in.th/tasks/toi17_wall)

<details>
  <summary>prerequisite</summary>
  <p>bfs, flood fill</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ถือว่าเป็นโจทย์ flood fill ตรงๆเลยโดยจะแบ่งเป็น 2 ส่วน คือ 1. flood fill จากมุมเพื่อหาว่าช่องไหนมีน้ำไปถึงบ้าง และ 2. flood fill หาแต่ละ component ที่ติดกันโดยเราจะสร้างกำแพงได้ก็ต่อเมื่อสร้างระหว่าง ‘X’ กับช่องที่มีน้ำมาถึง โดยคำตอบของเราก็คือ maximum ของกำแพงที่สร้างได้ของแต่ละ component</p>
</details>

[ac code](./toi17_wall.cpp)
