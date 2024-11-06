## toi19_explorer
[problem statement](empty)

<details>
  <summary>hint</summary>
  <p>การ traverse ของโจทย์เหมือน graph traversal algorithm ใด</p>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>dfs</ins>, dp, basic counting</p>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>จากโจทย์ เราจะเห็นว่าการสำรวจของเขาเหมือนกับการทำงานของ dfs ดังนั้นโจทย์จะกลายเป็นหาจำนวนวิธี dfs กราฟนี้ เราสามารถสร้างกราฟจาก input ของโจทย์ได้โดยการมองเลขที่ติดกันมี edge เชื่อมซึ่งกันและกัน</li>
    <li>เมื่อได้กราฟแล้ว จำนวนวิธีในการเดินเราหาได้ด้วยการนับเบื้องต้น คือ $$\text{{subtree1}} * \text{{subtree2}} * \ldots * \text{{subtreeK}} * K!$$
    <br>เมื่อ $$\text{{subtreeK}}$$ คือจำนวนวิธีเดินใน subtree ที่ $$K$$
    <br>$$K!$$ คือ permutation หรือการเรียงลำดับการเดินไป subtree $$K$$ อัน
    <br>แล้วเก็บจำนวนวิธีเดินเมื่อเริ่มที่ node $$i$$ สำหรับทุก node ไว้ใน <code>combi[i]</code></li>
    <li>ตัวอย่างเช่น ถ้า node 0 มี 3 child nodes คือ node 1,2,3 จะได้ว่า
    <code>combi[0] = 3! * (combi[1] * combi[2] * combi[3])</code>
    </li>
  </ul>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/a1476dc7-9261-49cd-8120-b6ec8c84c34a" /></p>

  <ul>
    <li>เราจะเริ่ม dfs ที่ node x ที่เขากำหนด แล้วเก็บค่าจำนวนวิธีเดินเมื่อเริ่มที่ node i ใด ๆ ไว้ใน <code>combi[i]</code> ทำจาก leaf node แล้วคำนวนขึ้นมาเรื่อย ๆ จนถึง root node x</li>
    <li>เพื่อความเร็วในการคำนวน ควรคิดค่า <code>M!</code> สำหรับทุก $$M \leq N$$ แล้วเก็บไว้ และอย่าลืม mod $$10^9+7$$ หลังทุก ๆ operation</li>
  </ul>
</details>

[ac code](empty)
