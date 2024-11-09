## toi11_segitiga
[problem statement](https://programming.in.th/tasks/toi11_segitiga)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>operation เกิดขึ้นกับแค่ช่องที่ติดกัน</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>หากเก็บว่าแต่ละช่วงสามารถเป็นค่าไหนได้บ้าง สามารถนำคำตอบไปช่วยหาช่วงอื่นได้ไหม</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>$N \leq 255$</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p><ins>dp matrix chain multiplication (mcm) <br><a href="https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/">resource</a></ins></p>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>เนื่องจากโจทย์ข้อนี้ $N≤255$ แล้ว operation เกิดขึ้นเฉพาะกับช่องที่ติดกัน เราสามารถทำคล้ายการ brute force แล้วเก็บค่าเอาไว้ โดยเก็บสำหรับทุกช่วง $[l,r]$ ว่าช่วงนี้สามารถดำเนินการไปได้เลขอะไรบ้างใน เมื่อเราต้องการคำตอบของช่วงที่ใหญ่ขึ้น เราก็สามารถไล่ทุก $m$ ที่ $l \leq m < r$ แล้วเช็คช่วง $[l,m]$ operate กับ $[m+1,r]$ สำหรับทุกค่าที่ทั้งสองช่วงเป็นไปได้ เพื่อเก็บว่าช่วง $[l,r]$ เป็นค่าอะไรได้บ้าง (เหมือนเป็นการลองทุกลำดับการ operate ที่เป็นไปได้สำหรับช่วงนั้น ๆ)</li>
    <li>โดยเก็บค่าใน <code>dp[l][r][3]</code> เป็นค่า 0 หรือ 1 <br>คือ ช่วง $[l,r]$ สามารถเป็นค่า 0/1/2 ได้หรือไม่ ถ้าได้เก็บค่าเป็น 1 ถ้าไม่ได้เก็บค่าเป็น 0 <br>เช่น <code>dp[0][3][2]=1</code> แปลว่า ช่วง $[0,3]$ สามารถ operate เป็นค่า 2 ได้</li>
    <li>ในการเขียนจริงเนื่องจากเราต้องใช้คำตอบของช่วงเล็ก ๆ มาตอบช่วงที่ใหญ่กว่า เราจึงเริ่ม loop จากช่วงขนาดเล็กไปขนาดใหญ่ ใช้เวลา $O(N)$ แล้วพิจารณาช่วงที่เริ่มต้นที่ทุกจุด ใช้อีกเวลา $O(N)$ และพิจารณาการแบ่งช่วงนั้นในทุก ๆ จุดที่อยู่ระหว่างช่วง ใช้อีกเวลา $O(N)$ รวมเป็น $O(N^3)$</li>
  </ul>
</details>

[ac code ver1](./toi11_segitiga.cpp)<br>[ac code ver2](./toi11_segitiga2.cpp)
