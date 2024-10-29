## toi1_pattern
[problem statement](https://programming.in.th/tasks/toi1_pattern)

<details>
  <summary>prerequisites</summary>
  <p><ins>brute force  / simulation</ins></p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ก็เป็นโจทย์ที่เราสามารถทำตรงๆได้เลยเนื่องจากจำนวน operation $N \leq 50000$ และความกว้างของผ้ามีไม่เกิน 70 <br> ทำให้เราสามารถเปลี่ยน grid เป็น ‘x‘ ได้ใน TC = $O(70N)$ และส่วนของการ print grid ก็สามารถทำได้ใน TC = $O(70N)$ เนื่องจากจำนวนแถวของผ้ามี $\leq N$. TC = $O(70N)$</p>
</details>

[ac code](./toi01_pattern.cpp)
