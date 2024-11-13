## toi4_school
[problem statement](https://programming.in.th/tasks/toi4_school)

<details>
  <summary>prerequisites</summary>
  <p>bfs/dfs, dynamic programming/binary search + 2d prefix sum</p>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ลองคิดแค่เพียง การหาสี่เหลี่ยมจตุรัสที่มีพื้นที่ใหญ่ที่สุดในตารางที่มีแค่ที่ว่างกับต้นไม้(S,T)</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>ทำได้หลายวิธี อาจมองว่า “ถ้าเรามีขนาด ๆ หนึ่ง เราสามารถหาว่ามีสี่หลี่ยมจตุรัสที่มีขนาดมากกว่าหรือเท่ากับขนาดนี้ได้ไหม” หรือ “สี่เหลี่ยมจตุรัสขนาดหนึ่งถูกสร้างมาจากอะไร”</p>
    </details>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <details>
    <summary>dynamic programming</summary>
    <ul>
      <li>ในการหาสี่เหลี่ยมจตุรัสที่ใหญ่ที่สุดที่ไม่ทับต้นไม้ เราสามารถทำได้ด้วย dynamic programming โดยสังเกตว่า สี่เหลี่ยมจตุรัสขนาดใด ๆ มาจากสี่เหลี่ยมจตุรัสที่ขนาดเล็กกว่า 4 อันมาซ้อนทับกัน</li>
      <p align="center"><img width="600" src="https://github.com/user-attachments/assets/86275595-766a-4af3-8ea9-fa726fb2be70" /></p>
      <li>ทำให้เราสามารถเก็บค่าสำหรับทุก ๆ ตำแหน่งบนตารางได้ว่า สี่เหลี่ยมจตุรัสที่ใหญ่ที่สุดที่มีมุมขวาล่างอยู่ที่ตำแหน่งนี้คือเท่าใด (กำหนดให้ <code>dp[i][j]</code> เก็บค่านี้สำหรับตำแหน่ง $(i,j)$ )</li>
      <li>เราสามารถหาค่าของตำแหน่งใด ๆ โดยการพิจารณาค่าของตำแหน่ง ด้านบน ด้านซ้าย และด้านบนซ้ายว่า “สามารถนำมาต่อกันเป็นสี่เหลี่ยมใหม่ได้ขนาดเท่าไหร่” ขนาดที่ได้จะเป็นขนาดของด้านที่เล็กที่สุด + 1 ทำให้ได้ recurrence relation เป็น <code>dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1</code></li>
      <li>Base case คือ <code>dp[i][j]=1</code> ถ้าเป็นตำแหน่งว่าง และ <code>dp[i][j]=0</code> ถ้าเป็นต้นไม้</li>
      <li>ขนาดของสี่เหลี่ยมจตุรัสที่ใหญ่ที่สุดคือ ค่าที่มากที่สดของ <code>dp[i][j]</code> สำหรับทุก ๆ $(i,j)$</li>
      <br>
      <p align="center"><img width="600" src="https://github.com/user-attachments/assets/a9b7774c-f1db-49de-9dfd-f3df2dc691a9" /></p>
      <li>สำหรับบ่อน้ำเราก็พิจารณาเป็นแบบเดียวกับพื้นที่ว่างก่อน จากนั้น bfs/dfs หาช่องที่ติดกันเป็น component แล้ว mark component เดียวกันให้เป็นค่าเดียวกัน </li>
      <li>หากมีสี่เหลี่ยมหลายตำแหน่งที่ขนาดมากที่สุดเท่ากัน เราก็ไล่เช็คบ่อน้ำในแต่ละสี่เหลี่ยมเพื่อหาตำแหน่งที่มีบ่อน้ำน้อยที่สุด</li>
      <li>time complexity ที่ได้คือ $O(NM)$ เมื่อ $N,M$ คือความกว้างและยาวของตาราง</li>
    </ul>
  </details>
  <details>
    <summary>binary search</summary>
    <ul>
      <li>เนื่องจากโจทย์ข้อนี้ constraint ค่อนข้างต่ำ ($N,M ≤ 64$) และหากเราทำสี่เหลี่ยมจตุรัสขนาดหนึ่งได้ สี่เหลี่ยมจตุรัสที่เล็กกว่านั้นก็สามารถได้เช่นกัน (ถ้าขนาด $N^2$ ทำได้ แล้วขนาด $(N-1)^2$ ก็จะทำได้เช่นกัน) เราจึงสามารถ binary search หาขนาดของสี่เหลี่ยมจตุรัสที่ใหญ่ที่สุดที่เป็นไปได้ได้ และหาจำนวนบ่อน้ำที่อยู่ในสี่เหลี่ยมนั้น ใช้เวลา $$O(\log_2{max(N,M)})$$</li>
      <li>อาจใช้ประกอบกับ prefix sum 2d (อ่านได้เพิ่มเติมใน <a href="https://github.com/packmani/toi-posn-com-guide/blob/main/toi09/toi09_fence/readme.md">เฉลย 2d prefix sum</a> ข้อนี้) เพื่อหาจำนวนต้นไม้สำหรับสี่เหลี่ยมใด ๆ อย่างรวดเร็วมากขึ้นใน $O(1)$ กับเวลาที่ใช้ในการ preprocess $O(NM)$</li>
      <li>time complexity ที่ได้คือ $$O(NM\log_2{max(N,M)})$$</li>
    </ul>
  </details>
</details>

[ac code 1](./toi04_school_dp.cpp)<br>
[ac code 2](./toi04_school_bsearch.cpp)
