## toi20_route
[problem statement](https://api.otog.in.th/problem/doc/1014)

<p>*โจทย์ข้อนี้มีรูปแบบการเขียนที่แตกต่างจากปกติ โดยให้เขียนเป็น function แล้ว return output ผ่าน function นั้นเลย ไม่ต้องเรียกใช้เอง ไม่ต้องรับ input</p>
<details>
  <summary>hint</summary>
  <p>ในการหา mst เราทำอย่างไร? → สร้างกราฟอย่างไรเพื่อบังคับให้หยิบ edge ที่มี weight มากๆ ?</p>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>greedy</ins>, minimum spanning tree</p>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>โจทย์ข้อนี้จะให้น้ำหนักและจำนวน edge มา แล้วให้เรา return กลับว่าแต่ละ edge เชื่อมกับ node ใดให้ได้ mst ที่มีค่ามากที่สุด</li>
    <li>สังเกตว่าในการหา mst ปกติ algorithm ที่เราใช้จะมีแนวคิด greedy คือหยิบ edge ที่มี weight น้อยที่สุดที่ไม่ทำให้เกิด cycle ก่อนไปเรื่อย ๆ จนเกิด mst</li>
    <li>ดังนั้น เราจะพยายามเชื่อม edge ที่มี weight มากที่สุดกับ node ที่ไม่มี edge อื่นเลย (ทำให้เกิด structure คล้าย tree) แล้วเชื่อม edge ที่มี weight น้อย ๆ เข้ากับกลุ่ม node เดียวกันให้ได้มากที่สุด (greedy) การทำอย่างนี้จะบังคับให้ edge ที่มี weight มากต้องถูกเลือก ไม่อย่างนั้นจะไม่สามารถเกิด mst ได้</li>
  </ul>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/7df4b34a-09d7-473b-a335-a1dcc1760b3e" /></p>
  <ul>
    <li>หมายเลข node ไม่มีความสำคัญ เราจะเชื่อมอย่างไรก็ได้ และเนื่องจากโจทย์เรียง weight จากน้อยไปมากมาให้เราแล้ว เราก็สามารถเชื่อมไปเรื่อย ๆ จนเหลือ node และ edge พอดีที่จะสร้าง tree</li>
    <li><ins>time complexity:</ins> $$O(N)$$</li>
  </ul>
</details>

[ac code](./toi20_route.cpp)
