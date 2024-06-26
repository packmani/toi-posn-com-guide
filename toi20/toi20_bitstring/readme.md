## toi20_bitstring

<details>
  <summary>subtask 1,2 solution</summary>
  <p></p>&emsp;<span style="border-bottom:0.05em solid">idea</span>:
  <ul>
    <li>brute force คำนวณทุกความเป็นไปได้</li>
    <li>ในทุกๆคำถาม เราลองเปลี่ยนทุกๆตำแหน่งที่เป็นไปได้เรื่อยๆ จนไปถึง state ที่ต้องการ (หรือจะทำจาก state ที่ต้องการมายัง state เริ่มต้นก็ได้) คำตอบของเราคือผลบวกของน้ำหนักในแต่ละ state ที่ผ่านที่มากที่สุดในทุกๆความเป็นไปได้ เราสามารถเขียนได้ด้วย recursion ตรงๆ</li>
    <li>ถ้ามองเป็นต้นไม้ คำตอบของเราจะอยู่ที่กิ่งที่มีค่ามากที่สุด</li>
  </ul>
  <p></p>&emsp;<span style="border-bottom:0.05em solid">time compexity:</span>
  <ul>
    <li>ในแต่ละคำถาม เนื่องจากเราต้องคำนวณทุกความเป็นไปได้ เราต้องใช้เวลา N! เรามี Q คำถาม จึงต้องใช้ time complexity O(N!*Q) ซึ่งจะใช้เวลาเกินขอบเขตของโจทย์</li>
  </ul>
  <p></p>&emsp;![test](https://github.com/packmani/toi-posn-com-guide/assets/40173086/66a820e5-b022-4e46-af4d-ed540f64fc6d)

)
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p></p>&emsp;ในการหาคำตอบของ bitstring หนึ่ง คำตอบนั้นจะมาจากไหนได้บ้าง
    </details>
    <details>
      <summary>hint 2</summary>
      <p></p>&emsp;สังเกตได้ว่าอาจมีการถาม state เดิมหลายๆครั้งได้ ซึ่งเราไม่จำเป็นต้องคำนวณใหม่สำหรับ state ไหนที่เราเคยคำนวณแล้วก็ได้
    </details>
    <details>
      <summary>hint 3</summary>
      <ul>
        <li>การเก็บคำตอบของแต่ละ state ใน array เพื่อเรียกใช้ตรงๆ เป็นไปไม่ได้ เนื่องจากต้องจองขนาด array มากสุดถึง 11,111,111,111,111,111,111 (1, 20 ตัว)</li>
        <li>สังเกตได้ว่ามีพื้นที่เหลือเยอะมาก เช่น ในเลข 2 หลักใช้แค่ช่อง 10,11 เหลือช่อง 12,13,14…….99 ที่เราไม่ใช้เลย แปลว่าเราสามารถลดพื้นที่ที่ต้องใช้ได้</li>
      </ul>
    </details>
    <details>
      <summary>hint 4</summary>
      <p></p>&emsp;ในการเปลี่ยน 1 เป็น 0 แต่ละตำแหน่ง อาจทำได้ด้วยการประยุกต์ความรู้ตรรกศาสตร์ (and, or, xor) และใช้ความรู้ bitwise operator ประกอบกับเลขฐานสองเพื่อความง่าย
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p></p>&emsp;<span style="border-bottom:0.05em solid">bitmask dp</span>, binary numbers, bitwise operators, dynamic programming,
</details>

<details>
  <summary>solution</summary>
  <p></p>&emsp;จากโจทย์ สิ่งที่เราต้องทำคือรับความยาวของ bitstring N และค่าน้ำหนักของแต่ละ state ที่เป็นไปได้ จากนั้นตอบคำถามจำนวน Q เป็น โดยรับเป็น state ต่างๆ เราต้องการเปลี่ยนจาก state นั้นไปเรื่อยๆ จนเป็น 0 ทุกตำแหน่ง โดยเราสามารถ 
  <ol type="1" start="1">
    <li>เปลี่ยน 1 เป็น 0 ที่ละหนึ่งตำแหน่ง (เช่น 11<span style="border-bottom:0.05em solid">1</span>1110 → 11<span style="border-bottom:0.05em solid">0</span>1110)</li>
  </ol>
  <ol type="1" start="2">
    <li>เปลี่ยน 1 ที่ติดกันสองตัวเป็น 0 ทั้งคู่ (เช่น 1101<span style="border-bottom:0.05em solid">11</span>0 → 110001<span style="border-bottom:0.05em solid">00</span>0)</li>
  </ol>
  <p></p>&emsp;เมื่อเราเปลี่ยนแล้วเราต้องเพิ่มน้ำหนักของ state นั้นๆ เข้าไปในผลรวมของเรา โดยโจทย์ต้องการผลรวมของน้ำหนักที่มากที่สุด 
  <p></p>&emsp;<strong><span style="border-bottom:0.05em solid">idea</span></strong><strong>: </strong>
  <ul>
    <li>เป็นโจทย์ <span style="border-bottom:0.05em solid">bitmask dp</span> ตรงๆ เลย ถ้าเคยเรียนน่าจะมองออก แต่ถ้าไม่เคยเรียนจะงงๆ หน่อย</li>
    <li>หากมองจาก brute force solution จะสังเกตได้ว่า<span style="border-bottom:0.05em solid">คำตอบที่ state ใดๆ มาจากคำตอบที่ดีที่สุดของ state ก่อนหน้าบวกกับน้ำหนักของ state ปัจจุบันเสมอ (overlapping subproblem)</span> ดังนั้นสามารถ optimize ได้โดย<span style="border-bottom:0.05em solid">เก็บคำตอบของแต่ละ state ไว้ (memoization)</span> เพื่อนำไปใช้หาคำตอบใน state ต่อไป</li>
    <li>โดยสามารถ define subproblem ได้เป็นการหาคำตอบที่ state ใดๆ <br/>&emsp;และ recurrence relation คร่าวๆว่า <br/>&emsp;<em>dp[current state] = max(dp[all reachable past states]) + weight[current state]</em></li>
    <li>ในการแก้ปัญหาจอง array เกิน สังเกตว่า bitstring ประกอบด้วยเลขเพียง 0 หรือ 1 ซึ่งข้อมูลที่จำเป็นทั้งหมดสามารถเก็บได้ในเลขฐานสอง เราจึงมอง bitstring เป็นเลขฐานสองแล้วแปลงให้กลายเป็นเลขฐานสิบเมื่อเก็บใน array ทำให้ขนาด array ที่เราต้องเก็บมากที่สุดจะลดเหลือประมาณ 2^20 ในการเก็บ state <br/>&emsp;เช่น bitstring <br/>&emsp;<em>1101</em> → 8+4+1 → 13 เก็บที่ dp[13]</li>
    <li>ใช้ bitwise operator &lt;&lt; (bitshift left), &amp; (bitwise and), ^ (bitwise xor) ในการทำงานกับเลขฐานสอง โดย<br/>&emsp;ใช้ <br/><em>(1&lt;&lt;i)</em> ในการสร้างเลข 2^i ไว้ชี้ที่ตำแหน่งต่างๆ <br/>&emsp;ใช้ <br/><em>state&amp;(1&lt;&lt;i)</em> ในการเช็คว่าตำแหน่งนั้นเป็น 1 หรือ 0<br/>&emsp;ใช้ <br/><em>state^(1&lt;&lt;i)</em> ในการแปลง 1 ที่ตำแหน่ง i เป็น 0<br/>(ถ้างงลองหาตัวอย่างแล้วทดดู)<br/><br/></li>
  </ul>
  <p></p>&emsp;<strong><span style="border-bottom:0.05em solid">implementation</span></strong>
  <ul>
    <li>ให้ loop i = 1,2,3…..2^N (แทนแต่ละ state)</li>
    <li>loop j = 0,1,2…..N (แทนแต่ละตำแหน่ง)</li>
    <li>dp[i] = น้ำหนักรวมที่มากที่สุดจาก state i ไปยัง state เริ่มต้น (0)</li>
    <li>vals[i] = ค่าน้ำหนักของ state i ที่โจทย์กำหนดให้</li>
    <li><em>dp[0]=0</em> ตามที่โจทย์กำหนด</li>
    <li><em>dp[i] = -INF</em> ในตอนเริ่มต้นเพราะเราต้องการหาค่ามากสุด (ใช้ <em>INT_MIN</em> เนื่องจาก constraint ไม่สูงมาก)</li>
  </ul>
  <p></p>&emsp;<span style="border-bottom:0.05em solid">recurrence relation</span>
  <ol type="1" start="1">
    <li>เปลี่ยนเลข 1 ทีละ 1 ตำแหน่ง</li>
  </ol>
  <p></p>&emsp;Insert photo
  <ol type="1" start="2">
    <li> เปลี่ยนเลข 1 ทีละ 2 ตำแหน่งที่ติดกัน</li>
  </ol>
  <ul>
    <li>โดยเราเริ่มจาก state ที่เป็น 0 ทั้งหมด และค่อยๆเปลี่ยน state โดยบวกไปทีละหนึ่ง เราสามารถเรียงลำดับการทำงานแบบนี้ได้เนื่องจากในการหาค่าแต่ละ state เราจะต้องใช้ค่าจาก state ก่อนหน้า ซึ่งมีค่าในเลขฐานสิบน้อยกว่าเสมอ เราจะเก็บค่าที่ดีที่สุดไว้ใน array “dp[]” เมื่อเราจะเปลี่ยนจาก state หนึ่งไปอีก state หนึ่งที่เราเคยคำนวณมาแล้ว เราก็สามารถเรียกค่าจากใน array ได้เลย (0 → 1 → 10 → 11 → 100 → …)</li>
    <li>คำตอบของ state ใดๆจะอยู่ที่ dp[state] โดยที่ state นั้นถูกแปลงเป็นเลขฐานสิบ</li>
  </ul>
  <p></p>&emsp;<span style="border-bottom:0.05em solid">time complexity</span>:
  <ul>
    <li>O(N*2^N) เนื่องจากในแต่ละ state ใช้เวลาคำนวณ N และมีทั้งหมด 2^N state </li>
  </ul>
</details>
