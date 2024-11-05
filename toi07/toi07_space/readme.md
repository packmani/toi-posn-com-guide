## toi7_space
[problem statement](https://programming.in.th/tasks/toi7_space)

<details>
  <summary>prerequisites</summary>
  <p>bitmask, bitwise operators</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เรา print คู่ $(a, b)$ ทุกคู่ในรูปแบบเลขฐานสอง ที่ $b$ มีจำนวน on bit (1) มากกว่า $a$ อยู่ 1 ตำแหน่งในระบบเลขฐานสอง
  <br>เราจะ run เลขฐานสองทุกตัวที่มี $d$ หลักตรงๆ ในช่วง $[0, 2^n)$ แล้วทำการ loop เพื่อเพิ่มเลข 1 ไปอีกตำแหน่ง สำหรับแต่ละเลข ซึ่ง $d$ ≤ 8 ทำให้ภายใน 1 วินาที</p>
</details>

[ac code](./toi07_space.cpp)
