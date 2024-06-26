# toi20_bitstring
## problem statement
จากโจทย์ สิ่งที่เราต้องทำคือรับความยาวของ bitstring N และค่าน้ำหนักของแต่ละ state ที่เป็นไปได้ จากนั้นตอบคำถามจำนวน Q เป็น โดยรับเป็น state ต่างๆ เราต้องการเปลี่ยนจาก state นั้นไปเรื่อยๆ จนเป็น 0 ทุกตำแหน่ง โดยเราสามารถ 

1. เปลี่ยน 1 เป็น 0 ที่ละหนึ่งตำแหน่ง (เช่น 1111110 → 1101110)
2. เปลี่ยน 1 ที่ติดกันสองตัวเป็น 0 ทั้งคู่ (เช่น 1101110 → 110001000)

เมื่อเราเปลี่ยนแล้วเราต้องเพิ่มน้ำหนักของ state นั้นๆ เข้าไปในผลรวมของเรา โดยโจทย์ต้องการผลรวมของน้ำหนักที่มากที่สุด

<details>
  <summary>hints</summary>
  <ul>
  <details>
    <summary>hint 1</summary>
    <details>
      ในการหาคำตอบของ bitstring หนึ่ง คำตอบนั้นจะมาจากไหนได้บ้าง
    </details>
  </details>
  </ul>
</details>
<div>
  <details>
    <summary>prerequisites</summary>
    <p><ins>bitmask dp</ins>, binary numbers, bitwise operators, dynamic programming</p>
  </details>
</div>

# R U COOKING?

- **เนื้อหา**
  - **longest increasing subsequence**
    - **general problem statement**
      - ปัญหาของการหา longest increasing subsequence หรือเรียกย่อๆว่า LIS เป็นปัญหา classic ที่จะสอนให้เรามองปัญหาด้วยมุมมองที่หลากหลายได้ดี โดย problem statement คร่าวๆ คือ
      - กำหนดลำดับของตัวเลข N ตัว จงหาลำดับย่อยที่ยาวที่สุด ที่เลขเรียงจากน้อยไปมาก
      - ก่อนจะทำปัญหานี้ได้ต้องเข้าใจนิยามก่อน
        - **subsequence** หมายถึง ลำดับย่อย หรือพูดง่ายๆคือการเลือกสมาชิกกี่ตัวก็ได้มาโดยคงตำแหน่งเดิมอยู่ (สมาชิกจะติดหรือไม่ติดกันก็ได้) เช่น ลำดับ (2 1 3) มี subsequence ต่างๆ คือ (2), (1), (3), (2 1), (2 3), (1 3), (2 1 3)
        - **increasing subsequence** ก็คือ subsequence ที่เรียงลำดับเลขจากน้อยไปมาก หรือ ลำดับที่เลขใดๆต้องมีค่ามากกว่าเลขด้านซ้ายของมัน เช่น ลำดับ (2 1 3) มี increasing subsequence ต่างๆ คือ (2), (1), (3), (1 3)
        - ดังนั้นการหา longest increasing subsequence คือ การหา increasing subsequence ที่





