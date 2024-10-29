## toi1_chain
[problem statement](https://programming.in.th/tasks/toi1_chain)

<details>
  <summary>prerequisites</summary>
  <p>brute force</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราหาคำสุดท้ายก่อนที่โซ่คำแรกจะขาด เนื่องจาก constraint ในข้อที่ $N ≤ 30000$ และ $L ≤ 1000$ ทำให้เราสามารถทำตรงๆได้เลยใน โดยในเราก็ input แต่ละ string มาแล้วก็ check ความแตกต่างระหว่าง string นี้ กับ string ก่อนหน้า ถ้าพอว่าแตกต่างกันเกิน 2 ตำแหน่งก็ print string นี้ออกมาแล้วทำการจบ program เนื่องจากมีจำนวน string = $N$ และการทำการ check ความแตกต่างในแต่ละรอบต้องทำ $L$ รอบ จึงได้ TC = $O(NL)$</p>
  <video src="https://github.com/user-attachments/assets/5e0ce20e-6ea8-4ca3-8dd1-98f2e55d12e3" width="600" autoplay></video>
</details>

[ac code](./toi01_chain.cpp)
