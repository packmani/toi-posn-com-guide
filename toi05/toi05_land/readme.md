## toi5_land
[problem statement](https://programming.in.th/tasks/toi5_land)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Find all permutations</li>
    <li><code>std::next_permutation()</code> <a href="https://en.cppreference.com/w/cpp/algorithm/next_permutation">std::next_permutation - cppreference.com</a></li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้ตาราง $MN$ มาโดยที่มีค่าในตาราง เราจะต้องเลือกตารางมาทีละช่องแล้วหาผลบวกของแต่ละช่องที่เราเลือก แต่การที่เราเลือกช่องใด $(i,j)$ จะส่งผลให้ช่องที่ติดกับ $(i,j)$ ใน $8$ ทิศทางจะโดนเพิ่มค่าไป 10% ของค่าปัจจุบันของ $(i,j)$ สมมติ $(i, j)$ มีค่า $b_{ij}$ $\rightarrow b_{i \pm 1, j \pm 1} += \frac{b_{ij}}{10}$</p>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/935a95e0-f2b4-42e8-a734-2b2109db3109" alt="direction.jpg" /></p>

  <p>เนื่องจาก $M, N \leq 3 \rightarrow MN \leq 9$ ทำให้เราสามารถไล่ทุกลำดับการหยิบว่าจะหยิบช่องไหนก่อนหลังได้เลยแล้วในแต่ละแบบ เราก็สามารถไล่บวกตรงๆได้เลย โดยคำตอบของเราก็คือผลบวกรวมที่น้อยที่สุดของทุกๆแบบ</p>
  <p>$TC = O((MN)! \cdot (MN)^2)$</p>
</details>

[ac code](./toi05_land.cpp)
