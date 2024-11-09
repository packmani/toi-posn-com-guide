## toi11_observatory
[problem statement](https://programming.in.th/tasks/toi11_observatory)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เอาเข้าลบออก (inclusion-exclusion)</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>prefix sum</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>prefix sum</ins></p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราหาผลรวมรูป 3 เหลี่ยมขนาด $K$ ที่มากที่สุด โดยถ้าเราไล่ตรงๆจะทำได้ใน $TC = O(N^3)$ ซึ่งยังไม่ทัน เราสามารถ speed up ได้โดยการทำ prefix sum แล้วลบส่วนที่ไม่จำเป็นออกเวลาหาคำตอบ</p>
  <hr>
  <strong><ins>-Prefix Sum-</ins></strong>
  <p>เราจะมอง 3 เหลี่ยมเป็นการรวมกันของของผลบวกเส้นทแยงมุม</p>
  <p align="center">
    <img width="600" src="https://github.com/user-attachments/assets/87baf242-2d7c-47ef-9b4d-b35a293098c2" />
  </p>
  
  เราจะทำ prefix sum ($QS$) แนวทแยงโดยเราจะให้
  <ul>
    <li>$QS(i, j) \equiv \text{ผลบวกแนวทแยงที่เริ่มมาจาก column แรก}$</li>
    <li>$QS(i, j) = QS(i-1, j-1) + h_{ij}$</li>
  </ul>

  <p>แล้วเราจะทำ prefix sum แนวนอนเพื่อมรวมผลบวกแนวทแยงเป็นแถบ</p>
  <p>เราจะทำ prefix sum ($qs2$) แนวนอนจาก $QS(i, j)$ (เอาแนวทแยงมารวมกันเป็นแถบ)</p>
  <hr>
  <p align="center">
    <img width="600" src="https://github.com/user-attachments/assets/4706254d-98ae-4cdd-8894-5eb56235366b" />
  </p>
  <ul>
    <li>$qs2(i, j) \equiv \text{ผลบวกรวมเส้นทแยงรวมเป็นแถบที่มีขอบที่ column แรกและมีจุดขวาสุดที่ } (i, j)$</li>
    <li>$qs2(i, j) = qs2(i, j-1) + QS(i, j)$</li>
  </ul>
  <hr>
  <p>จะสังเกตว่าตอนนี้เรายังมีส่วน โดยเราต้องลบส่วนที่เกินออกมาโดยเราจะใช้ prefix sum เก็บ $QS(i, j)$ อีกแนวนึง (แนวตั้ง) ($qs1$) ในการช่วยคิด</p>
  
  <ul>
    <li>$qs1(i, j) = qs1(i-1, j) + QS(i, j)$</li>
  </ul>
  <hr>
  <p align="center">
    <img width="600" src="https://github.com/user-attachments/assets/075cfcdb-bb61-4fff-b509-b8bb2b4e9f27" />
  </p>

  <p>จากรูปเราจะหาพื้นที่ในรูปได้จาก</p>
  <ul>
    <li>$[\Delta] = qs2(i, j) - qs2(i, j-k) - qs1(i-1, j-k) + qs1(i-k-1, j-k)$</li>
  </ul>

  <p><strong><ins>[Inclusion - Exclusion]</ins></strong></p>
  <hr>
  <p>ส่วนการหาสามเหลี่ยมที่หันอีกด้านก็ทำคล้ายๆกัน. $TC = O(N^2)$</p>
</details>

[ac code](./toi11_observatory.cpp)
