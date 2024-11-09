## toi13_art
[problem statement](https://programming.in.th/tasks/toi13_art)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ลองเปลี่ยนจากตาราง 2D ไปเป็น 1D ก่อน เรามีคำถามหลายๆคำถามในการบวกเพิ่มค่าในช่วง $[l \ldots r]$ เราทำอย่างไรได้ ? บวกเข้าแล้วลบออก? event point?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      การที่เราบวกเพิ่มค่า $+o$ ในช่วง $[l…r]$ เราสามารถแบ่งเป็น 2 event point (จุดที่เปลี่ยนค่า) คือ
      <ol>
        <li>$l$ คือจุดที่เราเพิ่มค่า $+o$ เป็นช่องแรก</li>
        <li>$r+1$ คือจุดที่เราเลิกทำการ $+o$ เป็นช่องแรก</li>
      </ol><br>
      สมมติเราต้องการหาค่าของตารางหลังจาก update ทั้งหมด. สมมติเราสร้าง array $D$ ขึ้นมาเพื่อเก็บค่าที่เปลี่ยนแปลง เราสามารถเปลี่ยนจากการไล่บวก เป็นการทำ
      <ol>
        <li>$D[l] = D[l] + o$</li>
        <li>$D[r+1] = D[r+1] - o$</li>
      </ol><br>
      <p>หลังจากจบการ update เราจะทำการ sweep จากซ้ายมาขวา ($1 \rightarrow N$) คือบวกไล่มาเรื่อยๆ หรือทำ prefix sum นั่นเอง ($D[i] = D[i] + D[i-1]$). จะสังเกตได้ว่าค่า $+o$ ที่เราใส่ไว้ใน $D[l]$ จะถูกเพิ่มมาที่ $D[l+1], D[l+2], D[l+3], …, D[r]$ และในช่อง $D[r+1]$ จะถูกลบออก (เพราะเราใส่ค่า $-o$ เอาไว้).</p>
      <p>[จะสังเกตได้ว่าค่าจะเปลี่ยนค่าที่ event point จุดอื่นๆจะมีค่าเหมือนกับค่าเดิม]</p>
      <video src="https://github.com/user-attachments/assets/ae9585a3-b3ac-45b1-b2fa-51a1caa0679d" width="600" autoplay></video> <!-- difference_array.mp4 -->
      <p>แต่ปัญหาของการทำแบบนี้คือเรา sweep แค่ตอนท้าย แต่ถ้าเราอยาก sweep แบบ online (ทำทันทีหลังจากได้รับคำสั่งการ update) เราต้องทำอย่างไร</p>
      <details> <summary>prefix sum (offline) → …. (online)?</summary> BIT (Fenwick tree)</details>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>simple sweep line (event points) + difference array technique</li>
    <ul>
      <li><a href="https://codeforces.com/blog/entry/78762">An Introduction To Difference Arrays - Codeforces</a></li>
    </ul>
    <li>Range query data structure</li>
    <ul>
      <li>BIT (Fenwick tree) <a href="https://cp-algorithms.com/data_structures/fenwick.html">Fenwick Tree - Algorithms for Competitive Programming</a></li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์คือเรามีตารางขนาด $H \cdot W$ ; $H = 10^6, W = 4 \cdot 10^6$. เรามีคำสั่ง $N$ คำสั่งในรูป $(s_i, h_i, w_i, o_i)$ คือเพิ่ม $+o_i$ เป็นรูปสี่เหลี่ยมที่มีจุดยอดทั้ง 4 อยู่ที่ $(h, w)$ = $(1, s_i), (1, s_i+w_i-1), (h_i, s_i), (h_i, s_i+w_i-1)$. ถ้าเราทำตรงๆ คือไล่บวกตารางเลย แต่มันจะช้าเกิน เพราะฉะนั้นเราจะใช้วิธีอื่น ซึ่งก็คือการทำ sweep line</p>
  <hr>
  <ins>-Sweep Line-</ins>
  <p>เราจะมองการเพิ่มเป็นสี่เหลี่ยมเป็นการเพิ่มเป็นแท่ง ที่ลอกค่าของแท่งทางซ้ายมา และจะหยุดเมื่อถึงขอบของสี่เหลี่ยม</p>
  <video src="https://github.com/user-attachments/assets/3df9c333-7b03-4383-a594-fcf9b832c639" width="600" autoplay></video> <!-- rectangle.mp4 -->
  
  ถ้ามีคำสั่ง $(s_i, h_i, w_i, o_i)$ เราสามารถมองเป็นการทำ sweep line ได้ โดยมี event point ที่สำคัญคือ
  <ol>
    <li>$s_i$ เป็นจุดเริ่มต้นที่เราจะสร้างแท่งสูง $h_i$ [update $+o_i$ สูง $h_i$]</li>
    <li>$s_i + w_i$ เป็นจุดแรกที่เราจะเลิกลอกค่าของแท่งก่อนหน้า (สี่เหลี่ยม $i$ จบแล้ว) [update $-o_i$ สูง $h_i$]</li>
  </ol>
  
  <p>[จะสังเกตว่าแท่งที่อยู่ในช่วง $[s_i+1, s_i+w_i-1]$ จะไม่มีการเปลี่ยนแปลงค่าอะไรเลยแค่ลอกมาทำให้เราเก็บแค่จุด event point ที่มีการเปลี่ยนแปลงซึ่งคือ $s_i$ และ $s_i+w_i$ ได้]</p>
  ในตอนนี้เราได้แก้ปัญหาของแกนนอนโดยการใช้ sweep line เหลือแกนตั้ง (แท่ง) ที่เราต้องทำการ update เป็นช่วงเป็นความสูง $h_i$ ด้วย $+o_i$ หรือ $-o_i$. ซึ่งถ้าเราไล่ตรงๆ บวกตรงๆ ตั้งแต่ $1$ ถึง $h_i$ จะช้าเกิน แต่เราสามารถทำ range update แบบ online ได้ด้วย Fenwick tree ใน $O(logH)$ โดยเราจะมองเป็นเหมือน difference array (see hint1.5) แล้วทำการ
  <ul>
    <li><code>update(1, +o); update(h + 1, -o); //ในกรณีที่เป็นจุด event point ประเภท 1.</code></li>
    <li><code>update(1, -o); update(h + 1, +o); //ในกรณีที่เป็นจุด event point ประเภท 2.</code></li>
  </ul>
  <p>ในตอนนี้เราสามารถ maintain แท่งในเมื่ออยู่ตำแหน่งต่างๆ ได้แล้ว (ซึ่งก็เหมือนการ maintain ตาราง 2 มิติแต่เราเก็บค่าสิ่งที่เป็นปัจจุบัน) แต่เราจะนับจำนวนช่องที่มีผลบวก $T$ อยู่ได้อย่างไร?</p>
  <hr>
  <ins>-Monotonicity-</ins>
  <p>เนื่องจากเราแบ่งสี่เหลี่ยมออกเป็นแท่ง เราจะพิจารณาแท่งๆ หนึ่ง ให้เป็นแท่ง $S$. สมมติว่าแท่ง $S$ มีคำสั่งให้ update เป็น $(h_1, +o_1), (h_2, +o_2), (h_3, +o_3)$. หลังจาก update เสร็จ เราจะสังเกตได้ว่าช่องด้านล่างจะมีผลรวมมากกว่าด้านบนเสมอเพราะเราไล่บวกจาก $1$ ไป $h$ เสมอทำให้ถ้าเรามองแท่งจากล่างขึ้นบน เราจะสังเกตได้ว่าจะได้ array ที่มีค่าเรียงจากมากมาน้อยทำให้เราสามารถทำ **binary search** เพื่อหาช่วงที่มีผลรวม $T$ อยู่ได้ โดยเราจะทำการ binary search 2 รอบเพื่อหาตำแหน่งล่างสุด ($lb$) ที่มีผลรวม $T$ และตำแหน่งบนสุดที่มีผลรวม $T$ ($rb$)</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/22500794-6fd1-458c-a900-3a12c1cfc11b" /></p> <!-- image.png -->
  <p>ซึ่งจำนวน $T$ ในแท่ง $S$ จะมีจำนวนเท่ากับ $rb-lb+1$</p>
  <p>[ซึ่งเราจะทำ binary search หา $T$ บนแท่งเฉพาะที่เป็น event point เท่านั้น]</p>
  <hr>
  <p>เราสังเกตได้ว่าช่วง $[x, nx)$ จะมีจำนวน $T$ เท่ากัน ทำให้เราสามารถหาได้ด้วย $(nx - x) \cdot (rb - lb + 1)$ จากการ binary search บนแท่งที่ $x$. ทำให้คำตอบของเราคือผลรวมสำหรับทุกช่วงที่เราแบ่ง. $TC = O(Nlog^2H + NlogN)$ จากการทำ Fenwick tree query ซ้อน binary search และ sort event point ตามแกนนอน</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/965d25cf-1c0f-4363-86d4-db7647172581" /></p> <!-- partition.jpg -->
</details>

[ac code](./toi13_art.cpp)
