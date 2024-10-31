## toi2_maxseq
[problem statement](https://programming.in.th/tasks/toi2_maxseq)

<details>
  <summary>hints</summary>
  <details>
    <summary>hint 1</summary>
    มี algorithm ไหนที่ใช้ represent ผลบวกของช่วงที่ติดกัน?
  </details>

  <details>
    <summary>hint 1.5</summary>
    prefix sum
  </details>
</details>

<details>
  <summary>prerequisites</summary>
  prefix sum
</details>

<details>
  <summary>solution</summary>
  โจทย์ข้อนี้ให้เราหา sequence ที่มีผลบวกมากที่สุดและอยู่ซ้ายสุดที่เป็นไปได้.
  เราสามารถ represent ผลบวกในช่วง $[l,r]$ ใดๆได้ด้วยการใช้ prefix sum กำหนดให้ $qs_i$ แทน prefix sum จนถึง $i$, ผลบวกในช่วง $[l,r]$ ก็คือ $qs_r - qs_{l-1}$ เราต้องการผลบวกที่มากที่สุด ดังนั้นเราจึงพยายามหา $qs_{l-1}$ ที่น้อยที่สุด ซึ่ง $min(\{qs_{l-1}\})$ ก็คือ prefix minimum ของ prefix sum จนถึง $r-1$. เราก็ทำการ run loop $r$ จาก 1 → $N$ เพื่อหาผลรวมที่มากที่สุดซึ่งคือ $max(\{qs_r - (prefix\_min)_{r-1}\})$ ในแต่รอบ $r$ ถ้าเราได้คำตอบที่ดีกว่า (ผลบวกมากกว่า หรือ ผลบวกเท่ากันแต่ $l$ น้อยกว่า[เริ่ม sequence ก่อน]) ก็ทำการ update ค่า mx_sum และเก็บตำแหน่งเริ่มต้น และ จบ sequence ไว้เพื่อจะได้เอาไว้ print ในภายหลัง.
  TC = $O(N)$

<video src="https://github.com/user-attachments/assets/166b649c-4f02-4b74-95e5-4f175d62d2ab" width="600" autoplay></video>

</details>

[ac code](./toi02_maxseq.cpp)
