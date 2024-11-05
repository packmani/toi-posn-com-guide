## toi6_tree
[problem statement](https://programming.in.th/tasks/toi6_tree)

<details>
  <summary>solution</summary>
  โจทย์ข้อนี้ให้เราเปรียบเทียบต้นไม้ว่าเป็นต้นไม้เดียวกันไหม การที่ต้นไม้จะเหมือนกันได้จะต้องมีเซตของเส้นเชื่อม (u, v) เหมือนกัน. เราจะสามารถเปรียบเทียบกันได้โดยนำไปใส่ใน std::set โดยเราจะทำการใส่ (u, v) โดยที่กำหนดให้ u < v. หรือทำการ sort (std::sort) ซึ่งในทางปฏิบัติจะมี constant factor ที่ดีกว่าการใช้ set
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/02caaffa-adbb-43c7-8e24-d0c1671ab47d" /></p>
</details>

[ac code](./toi06_tree.cpp)
