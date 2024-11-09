## toi12_barrier
[problem statement](https://programming.in.th/tasks/toi12_barrier)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>โจทย์ให้หา maximum subarray sum ที่มีขนาดช่วงยาวไม่เกิน $w$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>prefix sum</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>$qs_r - qs_{l-1}$</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <details>
        <summary>greedy</summary>
        <p>For each $r$, choose the minimum $qs_{l-1}$, Range minimum?</p>
      </details>
    </details>
    <details>
      <summary>hint 3.5</summary>
      <p>sliding window minimum</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>prefix sum</li>
    <li><a href="https://usaco.guide/gold/sliding-window">sliding window maximum</a></li>
    <ul>
      <li>monotonic deque</li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถแปลงโจทย์ข้อนี้เป็นการหา maximum subarray sum ที่มีขนาดช่วง $0 \leq [l,r] \leq w$. ถ้าเราหาตรงๆเลยก็จะได้ $TC = O(wN^2)$ เนื่องจาก constraint ที่สูง $N \leq 6 \cdot 10^6$ ทำให้เราสามารถคาดเดาได้ว่าจะต้องออกแบบ algorithm ที่รันใน $\approx O(N)$.</p>
  
  <p>เราจะใช้ prefix sum ในการช่วยในการหาคำตอบให้ง่ายขึ้น</p>
  
  <ul>
    <li>$qs_0 = v_0 = 0$</li>
    <li>$qs_i = \sum_{i=0}^{N} v_i = qs_{i-1} + v_i$</li>
    <li>$\sum [l \ldots r] = qs_r - qs_{l-1}$</li>
  </ul>

  <p>ทำให้เราสามารถ fix $r$ ได้ (ไล่ $r \in [1, n]$) และสำหรับแต่ละ $r$ เราจะหา $qs_r -  qs_{l-1}$ ที่มากที่สุดหรือพูดอีกอย่างคือหา $qs_{l-1}$ ที่น้อยที่สุด; $max(1, r-w+1) \leq l \leq r$ ซึ่งเราสามารถหาโดยการทำ RMQ (Range mininum query) โดยใช้ segment tree/sparse table แต่เนื่องจาก constraint ที่สูงจึงไม่ทัน แต่เนื่องจากช่วงที่เราต้องการหา minimum ทึ่ช่วงที่หามีขนาดคงที่ $= w$ เราสามารถแก้ได้ด้วยการทำ sliding window โดยการ maintain monotonic deque ทำให้เราสามารถแก้ข้อนี้ได้ใน $O(N)$</p>
</details>

[ac code](./toi12_barrier.cpp)
