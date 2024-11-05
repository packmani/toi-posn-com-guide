## toi7_car
[problem statement](https://programming.in.th/tasks/toi7_car)

<details>
  <summary>prerequisites</summary>
  <p>Dynamic programming, backtracking</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราหาวิธีการขยับเลนโดยที่ไม่โดนสิ่งกีดขวาง (1) โดยโจทย์การันตีว่าจะมีวิธีเดียว โจทย์ให้ตำแหน่งเลนที่เราอยู่ใน ($t$ = 0) และเราต้องไปที่ ($t$ = t) โดยการขยับจาก $t$ ในเลน $x$ ไป $t + 1$ จะทำได้ 3 แบบคือ:
  <br>&nbsp&nbsp&nbsp1. ไปเลน $x - 1$
  <br>&nbsp&nbsp&nbsp2. ไปเลน $x$
  <br>&nbsp&nbsp&nbsp3. ไปเลน $x + 1$</p>
  <p>ซึ่งสามารถ run dynamic programming ได้ โดยให้ $dp(t, x)$ เก็บค่า T/F ว่าเราสามารถอยู่ที่เลน $x$ ณ เวลา $t$ ได้หรือไม่ <br>โดย base case คือ $dp(0, n) = true$; $n$ คือตำแหน่งเลนเริ่มต้น ณ $t = 0$. Transition จะเป็น:
  <br>1. cell (t, x) = 1 (มีสิ่งกีดขวาง):  
     <br>&nbsp&nbsp&nbsp $dp(t, x) = false$
  <br>2. cell (t, x) = 0:  
     <br>&nbsp&nbsp&nbsp $dp(t, x) = dp(t - 1, x - 1) \lor dp(t - 1, x) \lor dp(t - 1, x + 1)$</p>

  <p>โดยถ้าเรา run dynamic programming จนเสร็จแล้ว ณ $t$ = t จะมี $dp(t, x) = true$ อยู่เพียงตัวเดียว (เพราะโจทย์บอกว่ามีวิธีเดียวในการเลี้ยว) ดังนั้นเราจะทำการ backtracking โดยการดู $dp(t - 1, x - 1)$, $dp(t - 1, x)$, หรือ $dp(t - 1, x + 1)$ ว่าตัวไหนเป็น $true$ แล้วไปที่ตรงนั้น เพื่อหา sequence การเลี้ยวจากหลังไปหน้า ($t = t \to 0$) และทำการ reverse sequence เพื่อให้ได้การเลี้ยวจาก $t = 0 \to t$</p>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/ea4f462f-d2e4-4b50-984c-01221121a0fc" /></p>
</details>

[ac code](./toi07_car.cpp)
