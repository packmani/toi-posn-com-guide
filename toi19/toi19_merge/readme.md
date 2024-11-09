## toi19_merge
[problem statement](https://programming.in.th/tasks/toi19_merge)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ลองคิดแบบมีแค่จุดชาร์จชนิดเดียว</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>เราหาได้ไหมว่าค่าๆหนึ่งจะอยู่ที่ช่องไหน</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>สำหรับค่า $y$ ที่ต้องแปลงเป็น $\bar{y}$, เราแปลงจาก $\bar{y}$ เป็น $y$ แทนได้ไหม</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>binary search</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>โจทย์ข้อนี้มีข้อมูลสองชุดมาให้ ประกอบด้วยความถี่ (s,t) และค่าของข้อมูล (x,y) ชุดหนึ่งต้องถูกแปลงด้วยสมการเส้นตรง ( $\bar{y}=\alpha y + \beta$) จากนั้นนำข้อมูลทั้งสองชุดมาเรียงเป็นเส้นตรงตามค่าของข้อมูลจากน้อยไปมาก โดยแต่ละค่าจะมีช่องเท่ากับความถี่ โจทย์ของเราคือหาว่า “ด้วยค่า $\alpha$ และ $\beta$ หนึ่ง ช่องที่ k มีค่าเป็นเท่าใด”</li>
    <li>เมื่อพิจารณาข้อมูลเพียงชุดเดียว หากเราเปลี่ยนคำถามจาก “ช่องนี้มีค่าเป็นเท่าไหร่” เป็น “ค่านี้อยู่ที่ช่องไหน” เราจะสามารถตอบคำถามได้โดยการเก็บความถี่ของแต่ละข้อมูลเป็น prefix sum ไว้ เมื่อเราจะหาว่าค่านี้อยู่ที่ช่องไหน เราก็เพียงหาค่า prefix sum ของค่า ๆ นั้นเพื่อหาว่าค่านี้อยู่ช่องสุดท้ายช่องไหน ซึ่งทำได้ใน $O(N)$</li>
    <li>หากพิจารณา prefix sum จะเห็นได้ว่า เมื่อค่ามากขึ้น ความถี่สะสมหรือช่องที่ค่านั่นอยู่ก็จะเพิ่มขึ้น ดังนั้นเราสามารถ binary search หาค่าของช่องที่ k ได้ ถ้าค่าที่เราเช็คไม่มีอยู่จริงเราก็จะใช้ค่าแรกที่น้อยกว่ามัน ในการเช็คหากค่าน้อยไปช่องที่ได้จะน้อยกว่า k และหากค่ามากไปช่องที่ได้จะมากกว่า k ทำให้เราสามารถปรับขอบซ้ายและขอบขวาได้ การหาค่าแรกที่น้อยกว่าสามารถหาได้ด้วยการ binary อีกทีบนค่าของข้อมูล ทำได้ใน $O(logN)$ รวมกับการ binary search หาค่าที่เป็นคำตอบเป็น $O(log^2N)$</li>
    <li>เมื่อพิจารณาข้อมูลสองชุด เราก็เพียง binary search แล้วนำความถี่ของทั้งสองชุดมารวมกัน โดยค่า $\\bar{y}$ ที่ต้องเปลี่ยนสามารถแปลงกลับเป็น $y$ ได้โดยการกลับข้างสมการ ได้เป็น $y = \frac{\bar{y}-\beta}{\alpha}$ แล้วนำไปใช้ search ในค่าเก่า ทำอย่างนี้สำหรับ $Q$ คำถาม จะได้ time complexity รวมเป็น $O(Qlog^2N)$</li>
  </ul>
</details>

[ac code](./toi19_merge.cpp)