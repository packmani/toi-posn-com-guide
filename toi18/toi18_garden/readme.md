## toi18_garden

[problem statement](empty)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>precompute</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>คิดขวากับซ้ายแยกกัน</p>
    </details>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>สำหรับแต่ละตำแหน่ง $X$ ที่เราเลือกเป็นต้นไม้หลักเราจะคิดด้านซ้ายและด้านขวาแยกกัน โดยต้นไม้ที่เราเลือกมีลักษณะที่ความสูงลดลงเรื่อยๆและเราต้องเลือกให้มีจำนวนต้นที่เลือกมากสุดซึ่งก็คือปัญหา LIS (longest increasing subsequence), ทางด้านซ้ายจำนวนที่เลือกมากสุดคือ LIS จากหน้าไปหลัง สมมติให้เป็น $kl$ และทางด้านขวาจำนวนที่เลือกมากสุดก็คือ LIS จากด้านหลังมาหน้า สมมติให้เป็น $kr$, ดังนั้น $k$ สำหรับการเลือก $X$ เป็นต้นไม้หลักก็คือ $min(kl, kr)$</p>
  <p align="center">
    <img width="600" src="temp%20for%20export%203adf288633624a84a790fba4d78cb612/LIS_diagram.jpg" />
  </p>
  <p>ซึ่งเราสามารถ precompute คำตอบสำหรับทุก $X$ ได้โดยการหา LIS จากหน้ามาหลัง และ LIS จากหลังมาหน้าซึ่งถ้าเราใช้ binary search หรือ segment tree/fenwick tree จะสามารถ แก้ข้อนี้ใน TC = $O(N\log N + Q)$ เพราะเราสามารถตอบแต่ละ query ได้ใน $O(1)$ </p>
</details>

[ac code](empty)
