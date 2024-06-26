# toi20_bitstring
## problem statement
จากโจทย์ สิ่งที่เราต้องทำคือรับความยาวของ bitstring N และค่าน้ำหนักของแต่ละ state ที่เป็นไปได้ จากนั้นตอบคำถามจำนวน Q เป็น โดยรับเป็น state ต่างๆ เราต้องการเปลี่ยนจาก state นั้นไปเรื่อยๆ จนเป็น 0 ทุกตำแหน่ง โดยเราสามารถ 

1. เปลี่ยน 1 เป็น 0 ที่ละหนึ่งตำแหน่ง (เช่น 1111110 → 1101110)
2. เปลี่ยน 1 ที่ติดกันสองตัวเป็น 0 ทั้งคู่ (เช่น 1101110 → 110001000)

เมื่อเราเปลี่ยนแล้วเราต้องเพิ่มน้ำหนักของ state นั้นๆ เข้าไปในผลรวมของเรา โดยโจทย์ต้องการผลรวมของน้ำหนักที่มากที่สุด

<details style="margin-left: 20px;">
  <summary>hints</summary>
  <details>
    <summary>hint 1</summary>
    <details>
      test
    </details>
  </details>
</details>
<div style="margin-left: 20px;">
  <details>
    <summary>prerequisites</summary>
    <p><ins>bitmask dp</ins>, binary numbers, bitwise operators, dynamic programming</p>
  </details>
</div>






