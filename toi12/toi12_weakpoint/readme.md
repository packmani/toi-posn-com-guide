## toi12_weakpoint
[problem statement](https://programming.in.th/tasks/toi12_weakpoint)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เรามีกราฟ $N$ จุดยอดและ $N$ เส้นเชื่อม และ connected แสดงว่ากราฟจะมีหน้าตาแบบไหน?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <ul>
        <li>ต้นไม้เป็นโครงสร้างที่มี $N$ จุดยอด $N-1$ เส้นเชื่อมและไม่มี cycle</li>
        <li>กราฟจะมี 1 cycle และอาจมีกิ่งแตกแขนงออกไปจากจุดบน cycle (คิดว่าเรามี tree แล้วเติมเพิ่ม 1 เส้นเชื่อม)</li>
      </ul>
      <p align="center">
        <img width="600" src="https://github.com/user-attachments/assets/4993f95e-9281-440a-aef9-45fccc8ccf2c" />
      </p>
      <ul>
        <li>interesting thing: <a href="https://usaco.guide/silver/func-graphs?lang=cpp">Introduction to Functional Graphs · USACO Guide</a></li>
      </ul>
    </details>
    <details>
      <summary>hint 2</summary>
      ลองคิดแยก case
      <ol>
        <li>แหล่งสำรองข้อมูลหลักอยู่บน cycle</li>
        <li>แหล่งสำรองข้อมูลหลักไม่อยู่บน cycle</li>
      </ol>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>basic graph + tree, cycle detection (dfs tree)</p>
</details>

<details>
  <summary>solution</summary> <br>
  <p>จากโจทย์ได้บอกว่ากราฟจะมีลักษณะเป็นกราฟที่มี 1 cycle และ 1 component เพราะฉะนั้นเราจะทำการหา cycle โดยการ detect backedge ระหว่างการ dfs. สามารถอ่านเพื่มเติมเรื่อง dfs tree ได้ใน <br><a href="https://codeforces.com/blog/entry/68138">Tutorial - The DFS tree and its applications: how I found out I really didn't understand bridges - Codeforces</a></p>
  <hr>
  <p>เราสามารถแยกเคสออกได้เป็น 2 เคส ได้แก่:</p>
  <ol>
    <li><ins>แหล่งสำรองข้อมูลหลัก ($m$) อยู่บน cycle</ins> จุดยอดที่เป็นจุดอ่อนเป็นได้แค่
      <ol>
        <li>จุดบน cycle อื่นที่มี <em>ขนาด subtree</em> มากสุด</li>
        <li>จุดที่ติดกับ $m$ ที่ไม่ได้อยู่ใน cycle ที่มี <em>ขนาด subtree</em> มากสุด</li>
      </ol>
      <details>
        <summary><strong>subtree?</strong></summary>
        <ul>
          <li>เราจะสามารถมองกราฟนี้เป็น forest ได้หากเราลบเส้นเชื่อมที่เส้นจุดยอดบน cycle ออก (forest คือมีหลายๆ tree) แล้วเราสามารถมองจุดบน cycle เป็น root ของ tree แต่ละต้นใน forest ได้</li>
        </ul>
        <p align="center">
          <img width="600" src="https://github.com/user-attachments/assets/db7be2cd-b746-419b-bda1-999abc59f512" />
        </p>
        <ul>
        <li>เราจะทำ dfs เพื่อหา subtree size ของแต่ละจุดยอดได้ด้วยการทำ dp on tree:</li>
          <ul>
            <li>$sz_u =$ size of subtree $u$</li>
            <li>$sz_u = \sum_{v \in c_u} sz_v ; \ c_u = \text{set of children of } u$</li>
          </ul>
        <li>ที่เราหา subtree size ก็เนื่องจากถ้าเราให้จุดยอด $u$ เป็นจุดอ่อน, จุดยอดที่อยู่ใน subtree ของ $u$ (ยกเว้น $u$) จะไม่สามารถรับข้อมูลได้ ซึ่งมีจำนวน = $sz_u - 1$</li>
        </ul>
      </details>
      คือ เราสามารถพูดอีกอย่างได้ว่า จุดยอดที่สามารถเป็นจุดอ่อนได้มี ได้แก่:
      <ul>
        <li>จุดที่เป็น root ที่มีขนาด subtree มากสุด</li>
        <li>จุดที่เป็น child ของ $m$ ที่มีขนาด subtree มากสุด</li>
      </ul>
    </li>
    <hr>
    <li><ins>แหล่งสำรองข้อมูลหลัก ($m$) ไม่อยู่บน cycle</ins>
      <ul>
        <li>หรือ พูดอีกอย่างคือเป็น $m$ จุดยอดบน tree ที่ไม่ใช่ root ในกรณีนี้จะมีจุดอ่อนที่เป็นไปได้ที่ต้อง check เพิ่มคือจุดยอดที่เป็น parent ของ $m$ ($p$). เนื่องจากถ้า $p$ เป็นจุดอ่อนจะตัดการเชื่อมต่อของ subtree ของ $m$ ออกจากกราฟที่เหลือ ทำให้ถ้า $p$ เป็นจุดอ่อนจะได้คำตอบเป็น $N - 1 - sz_m$ </li>
      </ul>
    </li>
  </ol>
</details>

[ac code](./toi12_weakpoint.cpp)
