## toi7_bomb
[problem statement](https://programming.in.th/tasks/toi7_bomb)

<details>
  <summary>prerequisites</summary>
  <p>sorting</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราหาจำนวนจุด $(x_i, y_i)$ โดยไม่มีจุด $(x_j, y_j)$ ใดๆที่ $x_i < x_j$ และ $y_i < y_j$</p>

  <p>เราสามารถแก้เงื่อนไข $x_i < x_j$ ได้จากการ sort ตามค่า $x$ จากมากมาน้อย เพื่อให้เรามั่นใจได้ว่าเราได้เจอจุดที่อาจจะมาบดบัง $(x_j, y_j)$ มาก่อนที่เราจะเจอจุด $(x_i, y_i)$ หมดแล้วแน่ๆ</p>

  <p>แต่การ sort แค่ตาม $x$ จากมากมาน้อย อาจมีจุดที่ไม่ได้ได้ตรงเงื่อนไขการบดบังอยู่ด้านหน้า หรือ $x_j = x_i$; $j < i$ หลังการ sort. โดยเราสามารถแก้ได้โดยการ sort ตาม $x$ จากมากมาน้อย แต่ถ้า $x$ เท่ากัน เราจะ sort ตาม $y$ จากน้อยมามาก เพื่อการันตีว่าเราจะไม่เจอ case ที่ $x_j = x_i$ และ $y_j > y_i$</p>

  <p>ทำให้สิ่งที่เราต้องทำก็เหลือแค่การนับจุดที่ไม่โดนบังก็คือ $y_i > y_j$ ;$ j < i$ หลัง sort. เราก็จะทำการเก็บ prefix maximum ค่า $y$ หลัง sort เพื่อมาเทียบกับจุดที่ $i$ ถ้า $y_i$ > prefix maximum จนถึง $i$ แสดงว่าจุดที่ $i$ ไม่โดนบดบัง</p>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/15cd4bea-f885-4eb6-a12f-12a8e8647d52" /></p>
</details>

[ac code](./toi07_bomb.cpp)
