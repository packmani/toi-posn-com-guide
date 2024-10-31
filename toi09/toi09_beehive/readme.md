## toi9_beehive
[problem statement](https://programming.in.th/tasks/toi9_beehive)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>หา maximum ? นับจำนวนวิธี ?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>dynamic programming</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
    <ul>dynamic programming</ul>
</details>

<details>
  <summary>solution</summary>
  <p><br>โจทย์ข้อนี้ให้หา maximum path sum แล้วก็หาจำนวนเดินที่ทำให้ได้ maximum sum โดยที่เราเริ่มเดินจาก cell ไหนก็ได้ในแถวที่ 0 ซึ่งสามารถแก้ได้ด้วย dynamic programming.</p>
  <p>กำหนดให้ $dp(i, j)$ คือผลบวกของค่าใน cell มากที่สุดในระหว่างทางเดินจากแถวที่ 0 มาถึง cell $(i, j)$ เมื่อ $i$ บอกแถว และ $j$ บอก column</p>
  <p><ins>Base case</ins> (แถวที่ 0)</p>
  <ul>
    <li>$dp(0, j) = x_{0j}$</li>
  </ul>
  <p><ins>Transition</ins></p>
  <ul>
    <li>กรณีแถวเลขคี่:</li>
    <p>$dp(i, j) = \max(dp(i-1, j) + x_{ij}, \ dp(i-1, j+1) + x_{ij})$</p>
    <li>กรณีแถวเลขคู่:</li>
    <p>$dp(i, j) = \max(dp(i-1, j) + x_{ij}, \ dp(i-1, j-1) + x_{ij})$</p>
  </ul>
  <p><ins>เราจะได้ maximum path sum เป็นค่า maximum ของ $dp$ ในแถวที่ $m-1$: $max(\{dp(m-1, j)\})$</ins> ตอนนี้เราเหลือปัญหาของการนับจำนวนวิธีซึ่งก็สามารถแก้ด้วย dynamic programming ได้</p>
  <p>กำหนดให้ $ways(i, j)$ เป็นจำนวนวิธีในการเดินจาก cell ไหนก็ได้ในแถวที่ 0 จนมาถึง cell $(i, j)$ โดยเดินให้ได้ maximum path sum จนถึง $(i, j)$</p>
  <p><ins>Base case</ins></p>
  <ul>
    <li>$ways(0, j) = 1$</li>
  </ul>
  <p><ins>Transition</ins></p>
  <ul>
    <li>กรณีแถวเลขคี่:</li>
    <p>การเดินมา $(i, j)$ มาได้จาก $(i-1, j)$ และ $(i-1, j+1)$. $ways(i, j)$ เก็บจำนวนวิธีที่ทำ maximum path sum ได้ ทำให้แบ่งได้ 3 กรณี:</p>
    <ol>
      <li>$dp(i-1, j) > dp(i-1, j+1)$</li>
      <p>$ways(i, j) = ways(i-1, j)$</p>
      <li>$dp(i-1, j+1) > dp(i-1, j)$</li>
      <p>$ways(i, j) = ways(i-1, j+1)$</p>
      <li>$dp(i-1, j) = dp(i-1, j+1)$</li>
      <p>$ways(i, j) = ways(i-1, j) + ways(i-1, j+1)$</p>
    </ol>
    <li>กรณีแถวเลขคู่:</li>
    <p>การเดินมา $(i, j)$ มาได้จาก $(i-1, j)$ และ $(i-1, j-1)$. $ways(i, j)$ เก็บจำนวนวิธีที่ทำ maximum path sum ได้ ทำให้แบ่งได้ 3 กรณี:</p>
    <ol>
      <li>$dp(i-1, j) > dp(i-1, j-1)$</li>
      <p>$ways(i, j) = ways(i-1, j)$</p>
      <li>$dp(i-1, j-1) > dp(i-1, j)$</li>
      <p>$ways(i, j) = ways(i-1, j-1)$</p>
      <li>$dp(i-1, j) = dp(i-1, j-1)$</li>
      <p>$ways(i, j) = ways(i-1, j) + ways(i-1, j-1)$</p>
    </ol>
  </ul>
  <p><ins>ทำให้คำตอบของจำนวนวิธีก็คือ $\sum ways(m-1, j)$ ที่มี $dp(m-1, j)$ มากที่สุด</ins></p>
  <details>
  <summary>Memory optimization</summary>
  <p>ถ้าเราทำ $dp$ ปกติจะทำให้เราต้องสร้างตารางขนาด $NM$ ซึ่งเกินจำเป็นเนื่องจาก transition $dp$ ที่เราใช้ในการคิดค่า $dp$ ในแถว $i$ มาจากค่าแถวที่ $i-1$. ทำให้เราเก็บจาก $dp[M][N]$ เหลือแค่ $dp[2][N]$ ได้ โดยเราจะให้<ins>แถวที่ 0 ใช้เก็บค่า $dp$ ในแถวเลขคู่ และแถวที่ 1 ใช้เก็บค่า $dp$ ในแถวเลขคี่</ins> ซึ่งสามารถหาแถวที่ใช้เก็บได้ด้วยการหาเศษจากการหารด้วยสอง หรือทำการ bitwise & กับ 1</p>
  </details>
</details>

[ac code](./toi09_beehive.cpp)
