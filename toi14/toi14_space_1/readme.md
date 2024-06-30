## toi14_space_1
[problem statement](https://api.otog.in.th/problem/doc/629)
<details>
  <summary>solution</summary>
  <p><ins>idea</ins>: </p>
  <ul>
    <li>DFS/BFS หารูปทรง</li>
    <li>หาสี่เหลี่ยมที่สามารถครอบรูปทรงได้พอดี แล้วนำมาคำนวนว่าเป็นรูปอะไร หากเป็นสี่เหลี่ยมจัตุรัส จำนวนเลข 1 ที่พบในก้อนนั้นๆจะเท่ากับขนาดของ boarder box พอดี แต่หากจำนวนเลข 1 น้อยกว่าขนาดของ boarder box ก็ต้องมาพิจารณาดูอีกทีว่าเป็นรูปทรงอะไร สังเกตว่ารูปสามเหลี่ยมจะมีขนาด 1+3+5+... ดังนั้น หากจำนวนเลข 1 ในก้อนนั้นๆเท่ากับ n+(n*(n-1)) แสดงว่าเป็นรูปสามเหลี่ยมหน้าจั่ว</li>
  </ul>
  <p><ins>time complexity:</ins></p>
  <ul>
    <li>มี array ขนาด n*m ต้อง traverse ทุก index อยู่แล้ว ดังนั้น time complexity O(nm)</li>
  </ul>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>traverse array ด้วย DFS/BFS</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>หา boarder ของรูปทรงและใช้ในการคำนวน</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>สังเกตว่ารูปสามเหลี่ยมหน้าจั่วจะมีขนาด 1+3+5+...</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>DFS/BFS, math</p>
</details>

<details>
  <summary>solution</summary>
  <p>จากโจทย์ สิ่งที่เราต้องทำคือรับความยาวของ bitstring N และค่าน้ำหนักของแต่ละ state ที่เป็นไปได้ จากนั้นตอบคำถามจำนวน Q เป็น โดยรับเป็น state ต่างๆ เราต้องการเปลี่ยนจาก state นั้นไปเรื่อยๆ จนเป็น 0 ทุกตำแหน่ง โดยเราสามารถ </p>
  <ol type="1" start="1">
    <li>เปลี่ยน 1 เป็น 0 ที่ละหนึ่งตำแหน่ง (เช่น 11<ins>1</ins>1110 → 11<ins>0</ins>1110)</li>
  </ol>
  <ol type="1" start="2">
    <li>เปลี่ยน 1 ที่ติดกันสองตัวเป็น 0 ทั้งคู่ (เช่น 1101<ins>11</ins>0 → 110001<ins>00</ins>0)</li>
  </ol>
  <p>เมื่อเราเปลี่ยนแล้วเราต้องเพิ่มน้ำหนักของ state นั้นๆ เข้าไปในผลรวมของเรา โดยโจทย์ต้องการผลรวมของน้ำหนักที่มากที่สุด </p>
  <p><strong><ins>idea</ins></strong><strong>: </strong></p>
  <ul>
    <li>เป็นโจทย์ <ins>bitmask dp</ins> ตรงๆ เลย ถ้าเคยเรียนน่าจะมองออก แต่ถ้าไม่เคยเรียนจะงงๆ หน่อย</li>
    <li>หากมองจาก brute force solution จะสังเกตได้ว่า<ins>คำตอบที่ state ใดๆ มาจากคำตอบที่ดีที่สุดของ state ก่อนหน้าบวกกับน้ำหนักของ state ปัจจุบันเสมอ (overlapping subproblem)</ins> ดังนั้นสามารถ optimize ได้โดย<ins>เก็บคำตอบของแต่ละ state ไว้ (memoization)</ins> เพื่อนำไปใช้หาคำตอบใน state ต่อไป</li>
    <li>โดยสามารถ define subproblem ได้เป็นการหาคำตอบที่ state ใดๆ <code>(dp[i] = น้ำหนักรวมที่มากที่สุดจาก state i ไปยัง state เริ่มต้น)</code> <br/>และ recurrence relation คร่าวๆว่า <code>dp[current state] = max(dp[all reachable past states]) + weight[current state]</code></li>
    <li>ในการแก้ปัญหาจอง array เกิน สังเกตว่า bitstring ประกอบด้วยเลขเพียง 0 หรือ 1 ซึ่งข้อมูลที่จำเป็นทั้งหมดสามารถเก็บได้ในเลขฐานสอง เราจึงมอง bitstring เป็นเลขฐานสองแล้วแปลงให้กลายเป็นเลขฐานสิบเมื่อเก็บใน array ทำให้ขนาด array ที่เราต้องเก็บมากที่สุดจะลดเหลือประมาณ $2^{20}$ ในการเก็บ state เช่น bitstring $1101 → 8+4+1 → 13$ เก็บที่ <code>dp[13]</code></li>
    <li>ใช้ bitwise operator &lt;&lt; (bitshift left), &amp; (bitwise and), ^ (bitwise xor) ในการทำงานกับเลขฐานสอง โดย<br/>ใช้ <code>(1&lt;&lt;i)</code> ในการสร้างเลข $2^i$ ไว้ชี้ที่ตำแหน่งต่างๆ <br/>ใช้ <code>state&amp;(1&lt;&lt;i)</code> ในการเช็คว่าตำแหน่งนั้นเป็น 1 หรือ 0<br/>ใช้ <code>state^(1&lt;&lt;i)</code> ในการแปลง 1 ที่ตำแหน่ง i เป็น 0<br/>(ถ้างงลองหาตัวอย่างแล้วทดดู)<br/></li>
  </ul>
  <p><strong><ins>implementation</ins></strong></p>
  <ul>
    <li>loop i = 1,2,3…..2^N (แทนแต่ละ state ถ้านำไปเขียนเป็นเลขฐานสอง)</li>
    <li>loop j = 0,1,2…..N (แทนแต่ละตำแหน่งที่ชี้)</li>
    <li>dp[i] = น้ำหนักรวมที่มากที่สุดจาก state i ไปยัง state เริ่มต้น (0)</li>
    <li>vals[i] = ค่าน้ำหนักของ state i ที่โจทย์กำหนดให้</li>
    <li>dp[0]=0 ตามที่โจทย์กำหนด</li>
    <li>dp[i] = $-\infty$ ในตอนเริ่มต้นเพราะเราต้องการหาค่ามากสุด (ใช้ <code>INT_MIN</code> เนื่องจาก constraint ไม่สูงมาก)</li>
  </ul>
  <p><ins>recurrence relation</ins></p>
  <ol type="1" start="1">
    <li>เปลี่ยนเลข 1 ทีละ 1 ตำแหน่ง</li>
  </ol>
  <p align="center">
    <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/66a820e5-b022-4e46-af4d-ed540f64fc6d" />
  </p>
  <ol type="1" start="2">
    <li> เปลี่ยนเลข 1 ทีละ 2 ตำแหน่งที่ติดกัน</li>
  </ol>
  <p align="center">
    <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/fe127335-ae20-41fd-94a8-6eb9db54a739" />
  </p>
  <ul>
    <li>โดยเราเริ่มจาก state ที่เป็น 0 ทั้งหมด และค่อยๆเปลี่ยน state โดยบวกไปทีละหนึ่ง เราสามารถเรียงลำดับการทำงานแบบนี้ได้เนื่องจากในการหาค่าแต่ละ state เราจะต้องใช้ค่าจาก state ก่อนหน้า ซึ่งมีค่าในเลขฐานสิบน้อยกว่าเสมอ เราจะเก็บค่าที่ดีที่สุดไว้ใน array <code>dp[]</code> เมื่อเราจะเปลี่ยนจาก state หนึ่งไปอีก state หนึ่งที่เราเคยคำนวณมาแล้ว เราก็สามารถเรียกค่าจากใน array ได้เลย (0 → 1 → 10 → 11 → 100 → …)</li>
    <li>คำตอบของ state ใดๆจะอยู่ที่ <code>dp[state]</code> โดยที่ state นั้นถูกแปลงเป็นเลขฐานสิบ</li>
  </ul>
  <p><ins>time complexity</ins>:</p>
  <ul>
    <li>$O(N*2^N)$ เนื่องจากในแต่ละ state ใช้เวลาคำนวณ N และมีทั้งหมด $2^N$ state </li>
  </ul>
</details>

[ac code](./toi14_space_1.cpp) 
