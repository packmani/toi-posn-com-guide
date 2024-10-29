## toi1_nugget
[problem statement](https://programming.in.th/tasks/toi1_nugget)

<details>
  <summary>hint</summary>
  <p>ใช้ algo ที่ใช้ข้อมูลที่เก็บก่อนหน้ามาใช้</p>
</details>

<details>
  <summary>solution</summary>
  <ul>
      <summary>เราสามารถใช้ dynamic programming ในการหาว่าค่าๆหนึ่งสามารถถูกสร้างขึ้นจากผลบวกของเลข 6, 9, หรือ 20 ได้หรือไม่ โดยกำหนดให้ dp[X] = 1 ถ้า X สามารถถูกสร้างขึ้นได้ และ dp[X] = 0 ถ้า X ไม่สามารถถูกสร้างขึ้นได้ จากนิยามข้างต้น สามารถเขียน transition ได้ดังนี้<br/>dp[X]  = dp[X] | dp[X-6] | dp[X-9] | dp[X-20]<br/>นั่นคือการเช็คว่าค่า X-6, X-9, และ X-20 สามารถสร้างขึ้นได้หรือไม่ หากมีค่าใดค่าหนึ่งสร้างได้ X ก็จะสามารถสร้างได้ (อาจเขียนด้วย if ทั่วไป แต่สามารถใช้ bitwise operator or “|” แทนได้เช่นกัน)<br/>
  </ul>
</details>

[ac code](./toi01_nugget.cpp)
