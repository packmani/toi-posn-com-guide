## toi9_wizards
[problem statement](https://programming.in.th/tasks/toi9_wizards)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>$N \leq 5000 \approx O(N^2)$?</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>$4 \to 2$</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>Meet in the Middle</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Meet in the Middle</li>
    <li><code>std::lower_bound</code> (to search in sorted array/vector)</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p><br>โจทย์คือให้เราเลือก $i, j, k, l$ โดยที่ $(x_a^i + x_b^j + x_c^k + x_d^l = x_t) \land (y_a^i + y_b^j + y_c^k + y_d^l = y_t)$</p>
  <p><ins>Brute force</ins></p>
  <ul>
    <li>ถ้าเราทำตรงๆก็คือ loop $i$ ซ้อน $j$ ซ้อน $k$ ซ้อน $l$ ทำให้ได้ TC = $O(N^4)$ ซึ่งยังไม่ทัน</li>
  </ul>
  <p><ins>Meet in the Middle</ins></p>
  <ul>
    <li>เราจะแบ่ง $x_a^i + x_b^j + x_c^k + x_d^l$ เป็น $(x_a^i + x_b^j) + (x_c^k + x_d^l)$ และกับ $y$ ก็เช่นเดียวกันเพื่อเราจะได้คิด $(a, b)$ และ $(c, d)$ แยกกันทำให้เหลือ loop ซ้อนกันแค่ 2 ชั้น ปัญหาของเราตอนนี้เหลือว่าเราจะเชื่อมระหว่าง $(a, b)$ และ $(c, d)$ ยังไง ซึ่งเราสามารถ search ใน sorted array/vector ได้ด้วย <code>std::lower_bound</code> ซึ่งในทางปฏิบัติจะเร็วกว่าการใช้ <code>std::set</code></li>
    <li>ใน $(a, b)$ เราจะทำการใส่ pair $\{x_a^i + x_b^j, y_a^i + y_b^j\}$ ใน array $v$ แล้ว sort เพื่อเราจะได้ทำการ search เมื่อเรา loop $(c, d)$ โดยที่เราจะ search หา $\{x_t - (x_c^k + x_d^l), y_t - (y_c^k + y_d^l)\}$ ใน $v$ เราจะใช้ function <code>std::lower_bound</code> ในการ search หาใน array $v$ ซึ่งถ้า element ที่เรา search ตรงกับ $\{x_t - (x_c^k + x_d^l), y_t - (y_c^k + y_d^l)\}$ แสดงว่าเราหาคำตอบได้แล้ว เราก็ทำการ print คำตอบแล้วจบโปรแกรม</li>
    <li>TC = $O(N^2 + N^2\log N^2) = O(N^2\log N^2)$ เนื่องจาก array $v$ มีได้มากสุด $N^2$ ตัวทำให้เรา search ใช้เวลา $\log N^2$ ต่อครั้ง</li>
    <li><em>เราอาจเพิ่มความเร็วในการ search ให้เป็น O(1) ได้ด้วยการ hash</em></li>
  </ul>
</details>

[ac code sol1](./toi19_wizards.cpp) <br>
[ac code sol2](./toi19_wizards_2.cpp)

