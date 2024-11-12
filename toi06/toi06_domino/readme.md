## toi6_domino
[problem statement](https://programming.in.th/tasks/toi6_domino)

<details>
  <summary>hints</summary>
  <ul>
  <details>
    <summary>$n \leq 13$</summary>
    <ul>
    <details>
      <summary>Brute force</summary>
      <ul>
        Recursion
      </ul>
    </details>
    </ul>
  </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Recursion + Backtracking</li>
  </ul>
</details>

<details>
  <summary>solution</summary> 
  <br>
  <p>โจทย์ข้อนี้ให้เราหาทุก configuration ในการ fill ตาราง $2 \times n$ โดยที่ใช้ domino ขนาด $1 \times 2$ และ $2 \times 1$ ซึ่งเราจำเป็นต้อง print ทุกแบบ ทำให้เราต้องทำตรงๆเลยคือใช้ recursion brute force</p>
  <p>$f(i)$ แทน state ว่าเราอยู่แถวที่ $i-1$ (0-based index)</p>
  เราสามารถทำ transition ได้ 2 แบบคือ:
  <ol type="1">
    <li>ใส่ $2 \times 1$ <code>--</code></li>
    <ul>
      <li>$f(i) \rightarrow f(i+1)$ (ใช้ 1 แถว)</li>
    </ul>
    <li>ใส่ $1 \times 2$ <code>||</code> (2 แท่งแนวตั้ง)</li>
    <ul>
      <li>$f(i) \rightarrow f(i+2)$ (ใช้ 2 แถว)</li>
    </ul>
  </ol>
  <ins>Base case:</ins>
  <ul>
    <li>เมื่อ $i \geq n$</li>
    <ul>
      <li>กรณี $i = n$</li>
      <ul>
        <li>เราใส่ domino ครบตารางพอดี</li>
        <li>พิมพ์คำตอบ</li>
      </ul>
      <li>กรณี $i > n$</li>
      <ul>
        <li>เราใส่เกินตาราง</li>
      </ul>
    </ul>
  </ul>
  <p>โดยที่ function ตั้งต้นในการ search คือ $f(0)$</p>

  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/97c45a9d-9641-4095-8fdc-f8f8ae39687f" alt="IMG_2054.jpeg" /></p>
  <details>
    <summary><ins>Time complexity:</ins></summary>
    <p>$TC < O(2^n)$</p>
    <p>ให้ $T(n)$ แทน function เวลา ที่เปลี่ยนตาม $n$ ($n$ คือขนาดปัญหา)</p>
    <ul>
      <li>$T(n) = T(n-1) + T(n-2) + O(1)$</li>
    </ul>
    <p>เราจะแก้มาได้ $T(n) = O(\phi^n); \; \phi \approx 1.618$</p>
    <details>
      <summary><strong>-TC-</strong></summary>
      <ul>
        <li>$T(n) = T(n-1) + T(n-2)$</li>
        <li>$x^n = x^{n-1} + x^{n-2}$</li>
        <li>$x^2 - x - 1 = 0$</li>
        <li>$x = \frac{1+\sqrt5}{2}, \; \frac{1 - \sqrt5}{2}$</li>
        <li>เราจะพิจารณาแค่ $x = \phi = \frac{1+\sqrt5}{2}$ ($\frac{1-\sqrt5}{2}$ ทำให้ $x^n$ ลดลงเนื่องจาก $|\frac{1-\sqrt5}{2}| < 1)$</li>
        <li>$T(n) = A \cdot \phi^n = O(\phi^n)$</li>
      </ul>
    </details>
  </details>
</details>

[ac code](./toi06_domino.cpp)
