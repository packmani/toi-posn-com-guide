## toi12_key
[problem statement](https://programming.in.th/tasks/toi12_key)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>$n ≤ 1000$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>dynamic programming</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>dynamic programming</li>
  </ul>
</details>

<details>
  <summary>variable definition</summary>
  <ul>
    <li>$a$ - string คนแรก</li>
    <li>$m$ - ความยาว string a</li>
    <li>$b$ - string คนสอง</li>
    <li>$n$ - ความยาว string b</li>
    <li>$s$ - string คำถาม</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถแก้ข้อนี้ได้ด้วย dynamic programming</p>
  
  <p>ให้ $dp(i, j)$ เป็น function ที่ return $T/F$ ว่าเราสามารถสร้าง string ความยาว $i+j$ ที่เป็น <ins>prefix</ins> ของ $s$ ($i + j$ ตัวแรกของ $s$) ได้ไหม โดยที่เราใช้ $i$ ตัวอักษรแรกของ $a$ และ $j$ ตัวอักษรแรกของ $b$ ในการสร้าง </p>

  <p>$\text{base case : }dp(0, 0) = true$ (string ว่างสร้างได้เสมอ)</p>
  เราจะทำ transition ได้ 2 ประเภทคือ
  <ol type="1">
    <li>เราใส่ตัวอักษรจาก $a$ (ตัวสุดท้ายของ string ที่สร้างมาจาก $a$)
      <ul>
        <li>เราจะใส่ได้เมื่อตัวอักษรตัวที่ $i$ ของ $a$ เหมือนกับตัวอักษรตัวที่ $i+j$ ของ $s$</li>
        <li>$dp(i, j) \leftarrow dp(i,j) \lor dp(i-1, j); \ a_i = s_{i+j}$</li>
        <li><code>if(dp[i-1][j] && (a[i-1] == s[i+j-1]))) dp[i][j] = true;</code> (base 0 indexed)</li>
      </ul>
    </li>
    <li>เราใส่ตัวอักษรจาก $b$ (ตัวสุดท้ายของ string ที่สร้างมาจาก $b$)
      <ul>
        <li>เราจะใส่ได้เมื่อตัวอักษรตัวที่ $j$ ของ $b$ เหมือนกับตัวอักษรตัวที่ $i+j$ ของ $s$</li>
        <li>$dp(i, j) \leftarrow dp(i,j) \lor dp(i, j-1); \ b_i = s_{i+j}$</li>
        <li><code>if(dp[i-1][j] && (a[i-1] == s[i+j-1]))) dp[i][j] = true;</code> (base 0 indexed)</li>
      </ul>
    </li>
  </ol>

  <p>คำตอบของเราก็คือ $dp(m, n)$ ซึ่งก็คือเมื่อเราใช้ตัวอักษรจนหมดเพื่อสร้าง $s$</p>
  <ul>
    <li>$dp(m, n) = true \rightarrow Yes$</li>
    <li>$dp(m, n) = false \rightarrow No$</li>
  </ul>
  <hr>
  <p><ins>time complexity</ins>: $TC = O(kmn)$</p>

  <p>[เนื่องจากข้อนี้มีหลาย testcase อย่าลืม reset ค่านะครับ]</p>
</details>

[ac code](./toi12_key.cpp)
