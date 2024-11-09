## toi13_cats
[problem statement](https://programming.in.th/tasks/toi13_cats)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เล็กที่สุดที่ใส่ใหญ่ที่สุดได้?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>binary search</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>binary search on answer</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ถามหาขนาดกรงที่เล็กที่สุดที่เป็นไปได้ที่ยังสามารถใช้ในการใส่แมวเพื่อสลับที่เพื่อให้สุดท้ายแล้วแมวที่ขนาดเท่ากันอยู่ติดกัน ซึ่งเราจะสังเกตได้ว่าหากกรงใหญ่ยิ่งใหญ่เรายิ่งมีอิสระในการจัดเรียงแมวมากขึ้น ก็คือถ้ากรงขนาด $x$ สามารถทำให้จัดแมวได้กรงขนาด $>x$ ก็ต้องทำได้เช่นกัน ทำให้เราสามารถ binary search หาค่า $x$ ที่น้อยที่สุดเท่าที่เป็นไปได้ได้.</p>
  <ins>-checker function-</ins>
  <p>ในการ check ว่า $x$ นี้จัดแมวได้ไหมเราจะสนใจเฉพาะแมวที่มีขนาด $>x$ เพราะแมวที่ขนาด $≤ x$ เราเคลื่อนย้ายได้อย่างอิสระทำให้เราไม่ต้องสนใจ. ถ้าลำดับของแมวที่ขนาด $> x$ มีแมวขนาดเดียวกันติดกันทั้งหมดก็ถือว่าทำได้ ถ้าทำได้เราก็จะลองลดค่า $x$, ส่วนถ้าไม่ได้ก็เพิ่มค่า $x$. $TC = O(NlogN)$</p>
</details>

[ac code](./toi13_cats.cpp)
