## toi2_word
[problem statement](https://programming.in.th/tasks/toi2_word)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Brute force</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เรา search หา string ในตาราง character ขนาด $mn$ โดยที่ string นั้นวางอยู่ได้ 8 ทิศทาง</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/b65ea8ee-da05-463f-b8a6-5c7263da083a" /></p>
  <p>สำหรับแต่ละ string ที่ให้หาเราจะสามารถไล่ดูจุดเริ่มต้น $(i, j)$ ทุกช่องได้เลย และสำหรับแต่ละจุดเริ่มต้น เราจะไล่ไปทุกทิศทาง 8 ทิศเพื่อ search หา string ตรงๆ</p>
  <p>$TC \approx O(n^3)$</p>
  <p>[ระวังเรื่องการออกนอกตารางและการที่ lowercase กับ uppercase เหมือนกัน]</p>
</details>

[ac code](./toi02_word.cpp)
