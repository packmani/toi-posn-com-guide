## toi20_orbs
[problem statement](empty)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เนื่องจากจำนวน operation L มีไม่เกิน 2000000 เราสามารถทำ simulation หรือ maintain array หลังจากแต่ละ operation ได้ไหม?</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>ตำแหน่งที่เอาออกมัน fixed คือ a และ b เราสามารถใช้ data structure อะไรมา maintain array ได้บ้าง?</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisite </summary>
  <p>std::multiset / sparse segment tree / ordered set (pbds)</p>
</details>

<details>
  <summary>solution </summary>
  <p>โจทย์ข้อนี้มีการใส่เข้าและนำออกของสมาชิกใน array อยู่หลายรอบโดยยังคงไว้ซึ่งสมบัติการเรียงจากน้อยไปมากอยู่ ทำให้เรานึกถึงการใช้ std::multiset </p>
  <ul>
    <details>
      <summary>Sol1 - brute force using 1 multiset (TLE)</summary>
      <p>ในแต่ละรอบ operation เราก็แค่ loop หาสมาชิกที่น้อยสุดเป็นลำดับ a และ b ตรงๆ ให้สมาชิก ณ ตำแหน่ง a คือ x, b คือ y เราก็แค่ insert (x+y)/2 และ y-x เข้าไปใน multiset แล้วลบ x และ y ออก แต่วิธีก็ยังไม่ทันเพราะ เราต้อง loop หา x และ y ใน multiset</p>
    </details>
    <details>
      <summary>Sol2 - 3 multisets</summary>
      <p>จาก idea ใน sol 1 ปัญหาที่เราต้องแก้คือการหา x และ yให้เร็วขึ้น โดยเรารู้อยู่แล้วว่า x จะอยู่ในตำแหน่ง a เสมอ และ y จะอยู่ในตำแหน่ง b เสมอ ทำให้เราว่าสามารถแบ่งช่วง array ของเราเป็น 3 ช่วง คือ [1, a], (a, b), [b, n] โดยในแต่ละช่วงเราจะเก็บใส่แต่ละ multiset กำหนดให้ A, B, C เป็น multiset โดย A เก็บช่วงแรก, B เก็บช่วง 2, และ C  เก็บช่วงสุดท้ายโดยการที่เราแบ่งเป็นช่วงจะทำให้เรา หา x และ y ได้ใน constant time โดยที่ x ก็คือสมาชิกที่มากที่สุดใน A และ y คือ สมาชิกที่น้อยที่สุดใน C เราลบ x ออกจาก A และ y ออกจาก B แล้วใส่ (x+y)/2 และ y-x ใน B เพราะเรารู้อยู่แล้วว่า (x+y)/2 และ y-x มีค่าอยู่ระหว่าง x และ y เสมอ ตอนนี้ B จะมีสมาชิกเกินมา 2 ตัว และ A ขาด 1 ตัว และ C ขาด 1 ตัว เราก็จะทำการย้ายสมาชิกที่น้อยที่สุดใน B ไปใส่ใน A และย้ายสมาชิกที่มากที่สุดใน B ไปใส่ใน C โดยแต่ละ operation จะใช้เวลา O(logn) ซึ่งทำให้ TC เป็น O(L logn) ซึ่งเพียงพอต่อการผ่านข้อนี้</p>
    </details>
    <details>
      <summary>Sol3 - pbds</summary>
      <p>pbds มี function ในการหาตำแหน่งที่น้อยเป็นลำดับใดๆได้ใน O(logn) โดยในแต่ละ operation เราก็ ใช้ function find_by_order ในการหา x และ y<br><a href="https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/">https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/</a></p>
    </details>
  </ul>
</details>

[ac code](empty)
