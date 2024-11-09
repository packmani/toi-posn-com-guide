## toi11_labor
[problem statement](https://programming.in.th/tasks/toi11_labor)

<details>
  <summary>hint</summary>
  <p>ยิ่งเวลามากขึ้น ก็สามารถขนได้มากขึ้น</p>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>binary search</ins></p>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>เราสามารถสังเกตได้ว่า ยิ่งเวลามากขึ้น ก็สามารถขนของได้มากขึ้น (monotonic) และเนื่องจากจำนวนคนงานกับความสามารถในการทำงานเท่าเดิม เราจึงสามารถ binary search หาเวลาน้อยสุดที่สามารถทำงานเสร็จได้</li>
    <li>หากกำหนดเวลา ๆ หนึ่ง สามารถหาจำนวนสินค้าที่ขนย้ายได้โดยนำเวลามาหารกับความสามารถในการทำงานของแต่ละคน ทำให้ได้จำนวนสินค้าที่แต่ละคนเคลื่อนย้ายได้ และนำทั้งหมดมารวมกัน เทียบกับจำนวนสินค้าที่กำหนดมา</li>
    <li>ถ้าสินค้ามากไปเราก็ลดขอบขวาในการ search ของเรา ถ้าสินค้าน้อยไปเราก็เพิ่มขอบซ้ายในการ search ของเรา ทำอย่างนี้ ๆ ไปเรื่อย ๆ จนได้คำตอบ</li>
    <li><a href="https://programming.in.th/tasks/toi11_labor/solution">solution ละเอียดใน programming.in.th</a></li>
  </ul>
</details>

[ac code](./toi11_labor.cpp)
