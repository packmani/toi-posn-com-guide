## toi7_pair
[problem statement](https://programming.in.th/tasks/toi7_pair)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เราสามารถมองสมบัติที่ $b_i < b_j$ และ $a_i > a_j$ คล้ายกับปัญหาอะไร?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>Inversion count</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>inversion counting - merge sort (d&c) / fenwick tree / segment tree</p>
</details>

<details>
  <summary>solution</summary>
  <details>
  <summary><ins>sol 1 - merge sort</summary></p>
  <p>เราสามารถมองข้อนี้คล้ายๆกับปัญหา inversion counting เรามองค่า $b$ เป็นเหมือน index เราจึง sort $(a_i, b_i)$ ตาม $b$ ทำให้เราเหลือเงื่อนไขคือ $a_x > a_y$, $x < y$ โดยที่ $x$, $y$ คือ index หลังจาก sort ตาม $b$. สิ่งที่ต่างกับปัญหา inversion count คือ แทนที่จะให้หาจำนวนคู่ เราต้องหาผลบวก $a$ แทน, สมมติเราพิจารณา $a_x$ คำตอบที่เกิดจาก $a_x = (a_x + a_{y_1}) + (a_x + a_{y_2}) + (a_x + a_{y_3}) + ... + (a_x + a_{y_k})$</p>

  <p>โดยที่ $y_j < x$ และ $a_{y_j} > a_{x}$ ซึ่งเราสามารถจัดรูปได้เป็น $a_x \cdot k + (a_{y_1} + a_{y_2} + a_{y_3} + ... + a_{y_k})$ โดยที่ $k$ คือจำนวน $y_j$ ที่เข้าเงื่อนไข โดยเราจะหาคำตอบที่เกิดจาก $a_x$ นี้ได้ตอนที่เรา merge array ฝั่งซ้ายและฝั่งขวา โดยเรารู้ว่า $y_j < x$ เสมอเมื่อ $y_j$ เป็น index จากฝั่งซ้าย และ $x$ มาจากฝั่งขวา</p>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/7c8caf1e-e670-49bc-b22b-a41c38841a63" /></p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/2cf5a417-bc54-40cb-96e3-8e22fcd1990b" /></p>
  </details>
  <details>
  <summary><ins>sol 2 - Fenwick tree</ins></summary>
  <p>เราสามารถใช้ Segment tree / Fenwick tree ในการแก้ข้อนี้ได้ โดยที่ข้อนี้ประกอบด้วย 2 เงื่อนไข คือ $b_i < b_j$ และ $a_i > a_j$. เราจะแก้เงื่อนไข $a_i > a_j$ ด้วยการ sort ส่วนเงื่อนไข $b_i < b_j$ เราจะแก้ด้วย Fenwick tree โดยเราจะเก็บ Fenwick tree 2 ต้น โดยตั้งชื่อว่า $bit_0$, $bit_1$. โดย $bit_0$ จะเก็บผลรวมค่า $a$ และ $bit_1$ เก็บจำนวน ซึ่งการหาผลบวกได้อธิบายไว้ใน sol 1. ในแต่ละ $x$, $0 \leq x < n$ เราจะหาคำตอบที่เกิดจาก $x$ ได้จาก $qry_1(b[x] - 1) \cdot a[x] + qry_0(b[x] - 1)$ โดยที่ $qry_j(k)$ คือการหาผลบวกในช่วง $[1, k]$ ใน $bit_j$. หลังจากเรา qry หาคำตอบแล้วก็จะทำการ update ที่ตำแหน่ง $b_x$ (+1 ใน $bit_1$ และ + $a_x$ ใน $bit_0$)</p>
  </details>
</details>

[ac code sol1](./toi07_pair_mergesort.cpp) <br>
[ac code sol2](./toi07_pair_fenwick.cpp)

