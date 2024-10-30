## toi18_sausage
[problem statement](https://programming.in.th/tasks/toi18_sausage)

<details>
  <summary>Variable definition</summary>
  <p><ins>N</ins> - จำนวนชิ้นของไส้อั่วทั้งหมด</p>
  <p><ins>D_i</ins> - ค่าความอร่อยของไส้อั่วชิ้นที่ i</p>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>การหาค่าสูงสุดมี algorithm ไหนที่ใช่แก้ได้บ้าง ? </p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>$N \leq 5000$</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>ลองคิดกรณีที่เราไม่ตัดไส้อั่วก่อน?</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisite</summary>
  <p>dynamic programming</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้เป็นโจทย์ dynamic programming โดยโจทย์จะแบ่งเป็น 2 ส่วนคือ การตัดไส้อั่วออกเป็นหลายๆเส้นในตอนแรก และ การที่เราจะต้องกินแต่ละเส้นให้ได้ค่าความอร่อยรวมสูงสุด</p>
  <p>ถ้าเราพิจารณาแต่ละเส้นหลังจากที่ตัดแล้วเราสามารถหาค่าความอร่อยที่มากที่สุดที่ได้จากเส้นนี้โดยใช้ dynamic programming ได้ โดยเราจะนิยาม <code>dp(l, r)</code> แทนความอร่อยที่มากที่สุดที่เมื่อเรากินไส้อั่วทั้งหมดจากช่วง l ถึง r เนื่องจากเราสามารถกินได้แค่ชิ้นลำดับแรกและท้าย ทำให้มี transition เป็น <code>dp(l, r) =  max({max(dp(l+1, r) + D[l] + |D[l] - D[r]|, dp(l, r-1) + D[r] + |D[l] - D[r]|)}</code> โดยค่า <code>|D[l] - D[r]|</code> คือค่าความอร่อยทิพย์ส่วน base case ก็คือ <code>dp(i, i) = D[i]</code> </p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/d3bb73ab-2ad6-4852-877b-97c50495103f" /></p>
  <p>ปัญหาถัดมาคือเราจะตัดไส้อั่วเป็นเส้นหลายเส้นยังไง เราก็สามารถใช้ dynamic programming แก้ได้</p>
  <p>โดยเรานิยาม <code>DP(i)</code> = ค่าความอร่อยรวมที่มากที่สุดเมื่อเราตัดไส้อั่วอย่างไรก็ได้เมื่อเราพิจารณาไส้อั่วในช่วงตั้งแต่ลำดับแรกจนถึงลำดับ i, โดน transition ของเราก็คือ <code>DP(i) = max({DP(j) + dp(j+1, i)})</code>, 0 ≤ j &lt; i (ถ้าเราให้ไส้อั่วอยู่ในช่วง [0, N))  base case ของเราก็คือ <code>DP(0) = dp(0, 0)</code></p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/73d4b198-5b88-48c8-8688-b7727a5fa460" /></p>
</details>

[ac code](./toi18_sausage.cpp)
