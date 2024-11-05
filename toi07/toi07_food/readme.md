## toi7_food
[problem statement](https://programming.in.th/tasks/toi7_food)

<details>
  <summary>prerequisites</summary>
  <p>std::next_permutation() / recursion</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราหา configuration ทั้งหมดโดยที่เขากำหนดตัวที่ห้ามเป็นตำแหน่งแรกไว้ ซึ่ง $n$ ในข้อนี้ ≤ 8 ทำให้เราสามารถหา permutation ตรงๆ ได้เลย</p>
  <details>
  <summary><ins>Sol1 - std::next_permutation()</ins></summary>
  <p>ใน C++ จะมี function std::next_permutation() ทำหน้าที่หา lexicographically greater permutation โดยเราจะหาทุกแบบ เพราะฉะนั้น array ที่เราจะใส่เข้าไปต้อง sort ก่อน แล้วเราก็แค่ check สำหรับแต่ละ configuration ว่าตัวด้านหน้าเป็นตัวต้องห้ามหรือไม่</p>
  </details>
  <details>
  <summary><ins>Sol2 - recursion</ins></summary>
  <p>เราจะทำการเขียน recursive function เพื่อแทนค่าแต่ละตำแหน่งทุกตัวเลขที่เป็นไปได้ โดยถ้าเป็นตำแหน่งแรกเราจะข้ามตัวที่ห้ามไป</p>
  </details>
</details>

[ac code sol1](./toi07_food_nextperm.cpp)<br>
[ac code sol2](./toi07_food_recur.cpp)
