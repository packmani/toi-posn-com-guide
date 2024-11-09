## toi12_cablecar
[problem statement](https://programming.in.th/tasks/toi12_cablecar)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เราสามารถมองโจทย์เป็นโครงสร้างอะไรได้?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>Simple weighted undirected graph. จุดยอดคือยอดเขา, สายเคเบิลคือเส้นเชื่อม และ น้ำหนักของเส้นเชื่อมคือ จำนวนคนมากที่สุดที่กระเช้าจุได้</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <ul>
        <details><summary>เส้นเชื่อมที่อาจจะเป็นปัญหากับเราคือ?</summary>
          <p>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspเส้นเชื่อมที่มีน้ำหนักน้อยสุด (จุคนได้น้อยสุด)</p>
        </details>
      </ul>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>ใส่เส้นเชื่อมจากน้ำหนักมากมาน้อย</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>DSU (Union-Find data structure) <a href="https://cp-algorithms.com/data_structures/disjoint_set_union.html">Disjoint Set Union - Algorithms for Competitive Programming</a></p>
</details>

<details>
  <summary>solution</summary>
  <p>เราจะมองโจทย์ข้อนี้เป็น Simple weighted undirected graph. โจทย์ให้เราเลือกเส้นทางจากจุดเริ่ม $s$ ไปจุดจบ $d$ โดยเส้นทางนั้นจะดีเมื่อจุคนได้มากหรือพูดอีกอย่างก็คือมี minimum edge weight ระหว่าง path จาก $s$ ไป $t$ มากที่สุดเท่าที่เป็นไปได้. เพราะฉะนั้นเราจะลองค่อยๆเพิ่มเส้นเชื่อมจาก weight มากมาน้อยดู.</p>

  <p>ในตอนแรกเราจะคิดภาพว่าไปมีเส้นเชื่อมอยู่เลย แล้วเราจะค่อยๆใส่เส้นเชื่อมมาเรื่อยๆจาก weight มากมาน้อยจนกว่า $s$ และ $t$ จะไปหากันได้ (อยู่ใน component เดียวกัน) weight ในตอนที่เราหยุดเพิ่มเส้นเชื่อมคือความจุมากสุดที่เราจะจุคนได้ ที่เหลือก็แค่คิดว่าเราจะต้องไปกี่รอบ. โดยในแต่ละรอบจะต้องใช้ มัคคุเทศก์ 1 คน.</p>

  <p>สมมติว่า weight น้อยสุดที่มากที่สุดที่เราหาได้คือ $mn$ ในแต่ละรอบเราจะเหลือที่ $mn-1$ ที่เพราะฉะนั้น ถ้าเรามีนักท่องเที่ยว $p$ คน. เราจะต้องไปทั้งหมด $\lceil p/(mn-1) \rceil$.</p>

  <p>ในส่วนของการ check ว่า $s$ และ $d$ อยู่ใน component เดียวกันแล้วหรือยังสามารถทำได้อย่างรวดเร็วโดยการใช้ DSU (Disjoint set Union) หรือ Union find Data structure ที่สามารถ Union 2 component เข้าด้วยกันได้ใน $\\alpha(N)$. $TC = O(M(logM + \\alpha(N)))$. สามารถอ่านเพิ่มเติมเกี่ยวกับ DSU และ proof ได้ที่ <a href="https://usaco.guide/gold/dsu?lang=cpp">Disjoint Set Union · USACO Guide</a></p>

  <video src="https://github.com/user-attachments/assets/d389ae2f-e5bb-437e-9f4d-c371de8bf0c7" width="600" autoplay></video>
</details>

[ac code](./toi12_cablecar.cpp)
