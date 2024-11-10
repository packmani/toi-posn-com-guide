## toi3_treasure
[problem statement](https://programming.in.th/tasks/toi3_treasure)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Brute force</li>
    <li>Basic Geometry</li>
    <ul>
      <li>Pythagorean Theorem</li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary><br>
  เราสามารถ simulate การเดินตรงๆได้เลยโดยที่เราสามารถเก็บพิกัด $(x, y)$ ที่เราอยู่หลังจากทำตามแต่ละคำสั่ง โดยจะแบ่งการเดินเป็น 2 ประเภทคือ
  <ol>
    <li>เดินตรง</li>
    <ol type="a">
      <li>$kN: y \leftarrow y + k$</li>
      <li>$kS : y \leftarrow y - k$</li>
      <li>$kE : x \leftarrow x + k$</li>
      <li>$kW : x \leftarrow x - k$</li>
    </ol><br>
    <li>เดินเฉียง</li>
    <ol type="a">
      <br>
      <p align="left"><img width="100" src="https://github.com/user-attachments/assets/76e1fe44-531c-46b4-8d6c-4d87c1c86ea3" /></p>
      <li>$kNE : y \leftarrow y + \frac{k}{\sqrt2} , x \leftarrow x + \frac{k}{\sqrt2}$</li>
      <li>$kNW : y \leftarrow y + \frac{k}{\sqrt2} , x \leftarrow x - \frac{k}{\sqrt2}$</li>
      <li>$kSE : y \leftarrow y - \frac{k}{\sqrt2} , x \leftarrow x + \frac{k}{\sqrt2}$</li>
      <li>$kSW : y \leftarrow y - \frac{k}{\sqrt2} , x \leftarrow x - \frac{k}{\sqrt2}$</li>
    </ol>
  </ol>
  <p>หลังจากเราทำจบแล้วเราก็แค่หา Euclidean distance ด้วย $\sqrt{x^2 + y^2}$</p>
  <p>$TC = O(n)$</p>
</details>

[ac code](./toi03_treasure.cpp)
