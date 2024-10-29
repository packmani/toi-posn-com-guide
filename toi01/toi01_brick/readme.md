## toi1_brick
[problem statement](https://programming.in.th/tasks/toi1_brick)

<details>
  <summary>prerequisites</summary>
  <p>bruteforce / simulation</p>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถทำโจทย์ข้อนี้โดยการทำ simulation ตรงๆได้เลย เราจะสังเกตได้ว่าการหล่นของแต่ละ column ไม่ได้เกี่ยวข้องกัน และก้อนอิฐไม่สามารถหล่นไปอยู่ล่างสิ่งกีดขวางได้. กำหนดให้ $ls_j$ เป็นตำแหน่งที่อยู่ด้านล่างของตำแหน่งแถวของก้อนอิฐที่จะหยุดถ้าเราปล่อยก้อนอิฐใน column ที่ $j$ โดยในตอนเริ่มต้น $ls_j$ ก็คือตำแหน่งของแถวของสิ่งกีดขวางที่อยู่บนที่สุด หรือถ้าไม่มีสิ่งกีดขวางก็คือตำแหน่งที่เลยตารางลงไป (ตำแหน่ง $N$ เป็นจำนวนแถว และ แถวอยู่ในช่วง [0, N)) เนื่องจากจำนวนของอิฐที่จะตกลงมาสำหรับแต่ละ column ≤ 20 เราจึงสามารถ simulate การตกของแต่ละอิฐได้ โดยที่เราสำหรับแต่ละ column $j$ เราก็วางอิฐในตำแหน่ง $ls_j - 1$ แล้วตำการเลื่อน $ls_j = ls_j - 1$ ขึ้น 1 ($ls_j = ls_j - 1$) เราก็ทำแบบที่กับทุก column แล้วก็ print ตารางคำตอบออกไป. TC = $O(MN)$ </p>
  <video src="https://github.com/user-attachments/assets/92a01f77-7a85-4f25-b5ef-d852e3d974e1"width="600" autoplay></video>
</details>

[ac code](./toi01_brick.cpp)
