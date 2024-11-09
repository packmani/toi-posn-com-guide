## toi13_robot
[problem statement](https://programming.in.th/tasks/toi13_robot)

<details>
  <summary>hint</summary>
  <ul>
      <details><summary>ทำพร้อมกัน?</summary> Multi-source bfs</details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Multi-source bfs</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <ul>
  <li>เราสามารถมองโจทย์ข้อนี้เป็นโจทย์กราฟได้โดยที่ช่องที่เป็น 'X' แสดงถึง source และ ช่องที่เป็น 'A' ถือเป็น destination. ถ้าเราอยู่ช่อง $(i, j)$ เราจะไปหาได้ 4 ทิศทางคือ $(i-1, j), (i, j-1), (i+1, j), (i, j+1)$ ได้เมื่อช่องเหล่านี้ไม่ใช่ 'W' และอยู่ในตาราง.</li>
  <li>โดยเราต้องการหา shortest path จากช่อง 'X' ใดๆ ไปหาแต่ละช่อง 'A' แล้วกลับมาที่เดิมเนื่องจากกราฟนี้เป็น unweighted graph (คือมี weight 1 ทั้งหมด) เราสามารถทำการ bfs จากทุกจุด source พร้อมกันเพื่อไปหาช่อง 'X' ทั้งหมด.</li>
  <li>สมมติให้ shortest path จาก source ใดๆ มา $(i, j) = d[i][j]$, และ $d[i][j] = 0$ เมื่อ $(i, j) = X$ (source). คำตอบของเราก็คือ $2 \sum_{(x, y) = A} d[x][y]$ (x2 เนื่องจากต้องไปและกลับด้วย) $TC = O(MN)$</li>
  </ul>
</details>

[ac code](./toi13_robot.cpp)
