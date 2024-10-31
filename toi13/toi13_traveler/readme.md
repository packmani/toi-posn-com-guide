## toi13_traveler
[problem statement](https://programming.in.th/tasks/toi13_traveler)

<details>
  <summary>hints</summary>
  <p>ใกล้สุด -> ระยะทางน้อยสุด</p>
</details>

<details>
  <summary>prerequisites</summary>
  <p>dijkstra‘s algorithm</p>
</details>

<details>
  <summary>variable definition</summary>
  <ul>
    <li>N - จำนวนเขตการปกครอง</li>
    <li>M - จำนวนเส้นทางรถไฟฟ้า</li>
    <li>X - หมายเลขของเขตการปกครองต้นทาง</li>
    <li>Y - หมายเลขของเขตการปกครองปลายทาง</li>
    <li>Z - ระยะทางที่เดินทางได้</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราไปหาเดินทางจาก X ไปหาเขตปกครอง W โดยที่ (ระยะทางจาก X ไป W) ≤ Z และ ระยะทางจาก W ไป Y น้อยที่สุด โดยการที่เราจะหาว่าระยะทางจาก X ไป W เป็นเท่าไหร่ เราสามารถทำได้โดยใช้ dijkstra‘s algorithm ในการหา single-source shortest path จาก X ไปทุกๆเขตการปกครอง แล้วส่วนการหาระยะทางจาก W ไป Y เราก็สามารถหาได้โดยการ run dijkstra‘s algorithm จาก Y ไปทุกๆเขตการปกครอง เราทำแบบนี้ได้เพราะว่า graph เป็น undirected graph ทำให้ (ระยะทางสั้นสุดจาก Y ไป W) = (ระยะทางสั้นสุดจาก W ไป Y). หลังจากเรา run dijkstra จากทั้ง X และ Y แล้วเราก็ check สำหรับทุก W ที่ (ระยะทางสั้นสุดจาก X) ≤ Z หา W ที่ระยะทางจาก Y น้อยสุดที่มีหลายเลขกำกับน้อยสุด. TC = O((M+N)logN)</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/c40e3e0c-ece2-4e10-8bac-e7524a309700" /></p>
</details>

[ac code](./toi13_traveler)
