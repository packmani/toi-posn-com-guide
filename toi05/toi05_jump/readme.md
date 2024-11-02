## toi5_jump
[problem statement](https://programming.in.th/tasks/toi5_jump)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>binary search</li>
    <li>prefix sum</li>
    <li>sliding window</li>
    <li>two pointer</li>
  </ul>
</details>

<details>
  <summary>solution</summary>

  <p>การที่จุด $x_i$ จะกระโดดไปถึง $x_j$ ได้แสดงว่าจุดทั้งสองจุดนั้นอยู่ในช่วง $[L, R]$ โดยที่ $R - L \leq k$ และการกระโดดต้องเริ่มจาก $x_i$ แล้วไปจบที่ $x_j$ (ข้อมูลจาก input) ทำให้เราสามารถ fix $x_i$ แล้วทำการหา $x_j$ ที่ไกลสุดที่ $\leq x_i + k$ หรือ fix $x_j$ แล้วทำการหา $x_i$ ที่ไกลสุดที่ $\geq x_j - k$</p>

  <details>
    <summary>solution 1 (binary search)</summary>
    <p>สมมติเรา fix $x_j$; $0 \leq j < N$ เราสามารถหา $x_i$ สำหรับแต่ละ $j$ ได้ด้วยการ binary search หา $x_i$ ที่น้อยที่สุดยัง $\geq x_j - k$ ซึ่งสามารถทำได้โดยการใช้ฟังก์ชัน $\texttt{std::lower\_bound}(x, x+j, x_j - k)$ ใช้หาตำแหน่ง $i$ ซ้ายสุดที่ยังคง $\geq x_j - k$ ในช่วง $[0, j)$. เราสามารถทำการ binary search พร้อมกันกับรับข้อมูลแต่ละรอบได้เลย เพราะโจทย์การันตีว่า $x$ ถูก sort แล้ว ($x_i < x_j$). คำตอบของเราก็คือ $\max(\{i - j\})$. TC = $O(N \log N)$ จากการที่ binary search $N$ รอบ</p>
  </details>

  <details>
    <summary>solution 2 (prefix sum)</summary>
    <p>แทนที่เราจะหาตำแหน่งที่ไกลที่สุดที่มีระยะห่างไม่เกิน $k$ เราสามารถมองเป็นการหาจำนวนของ $x_j$ ในช่วง $[L, R]$; $R - L \leq k$. เราจะทำการ fix $x_i$ แล้วหาจำนวนของ $x_j$ ที่อยู่ในช่วง $(x_i, x_i + k]$ ซึ่งเราสามารถทำได้โดยการใช้ prefix sum ในหาผลบวกในช่วงใดๆ. ในตอนแรกเราจะทำการเพิ่มจุด $x_j$ จาก input เข้าใน prefix sum array ($qs$): ($qs[x_j] += 1$). หลังจากนั้นก็ทำการ sweep ค่าจากซ้ายมาขวาเพื่อทำ prefix sum ($qs_X += qs_{X-1}$) แล้วสำหรับแต่ละ $i$ เราก็ค่าหาผลบวกในช่วง $(x_i, x_i + k]$ ซึ่งสามารถแปลงได้เป็น $qs_{x_i + k} - qs_{x_i}$. ทำให้คำตอบของเราคือ $\max(\{qs_{x_i + k} - qs_{x_i}\}); 0 \leq i < N$. TC = $O(N)$</p>
    <video src="https://github.com/user-attachments/assets/76d9423d-2ac1-49fc-bded-38c33b71e969" width="600" autoplay></video>
  </details>

  <details>
    <summary>solution 3 (sliding window)</summary>
    <p>เราสามารถมองโจทย์เป็นเหมือนการทำ sliding window ได้โดยเรามี window ขนาด $k+1$ แล้วก็ทำการเลื่อนไปตาม $x$ จากซ้ายไปขวา โดยที่คำตอบของเราก็คือ (จำนวนของ $x_i$ ที่อยู่ใน window ณ ขณะใดขณะหนึ่ง) - 1. แต่เราไม่จำเป็นต้องเลื่อน window ไปทีละหนึ่งตามเส้นจำนวน เราสามารถเลื่อนไปตาม $x_i$ ได้เลยเนื่องจากการกระโดดต้องเริ่มและจบที่ $x_i$ ตามที่ให้มาใน input อยู่แล้ว ซึ่งเราสามารถ simulate การเลื่อนนี้ด้วยการใช้ <code>std::deque</code> ได้เพราะว่าเราสามารถทำ operation ได้จากทั้งหน้าและหลัง. โดยในแต่ละรอบ $i$ เราจะทำการ <code>pop_front</code> ตำแหน่งที่เลย window $(< x_i - k)$ ออก แล้วก็ทำการใส่ $x_i$. คำตอบของเราก็คือ $\max(\{\texttt{dq.size()} - 1\})$. TC = $O(N)$ เนื่องจากเรา run ตาม $x_i$ ซึ่งมี $N$ ตัว และ operation การ push เข้า deque และ การ pop ออกจาก deque มีได้มากสุดอย่างละหนึ่งครั้งสำหรับแต่ละ $x_i$</p>
    <video src="https://github.com/user-attachments/assets/3b2e2edf-3311-4d27-8793-bd6e5b8d3075" width="600" autoplay></video>
  </details>

  <details>
    <summary>solution 4 (two pointers)</summary>
    <p>จากการที่ $x$ ถูก sort จากน้อยไปมาก ถ้าเราพิจารณา index $l_i$ และ $l_j$ โดยที่ $l_i < l_j$ เรารู้ได้ว่า $r_i \leq r_j$ โดยที่ $r_i - l_i \leq k$ และ $r_j - l_j \leq k$ ซึ่งทำให้เราสรุปได้ว่า ถ้า $i_0 < i_1 < i_2 < \dots < i_{n-1} \rightarrow r_{i_0} \leq r_{i_1} \leq r_{i_2} \leq \dots \leq r_{n-1}$. ทำให้เราสามารถแก้ข้อนี้ด้วยการใช้ two pointers ได้ โดยเราจะมี pointer 2 ตัว คือ $l$ และ $r$. $l$ จะ run จาก $0$ ถึง $N - 1$ และในแต่ละรอบ $l$ จะ run $r$ ไปจนกว่า $x_r - x_l > k$ หรือ $r = N$ แต่เราไม่ต้องเริ่ม reset $r$ ใหม่ทุกรอบเนื่องจากเงื่อนไขที่ $i < j \rightarrow r_i \leq r_j$. ทำให้เราสามารถแก้ได้ใน TC = $O(N + N) = O(N)$. คำตอบของเราก็คือ $\max(\{(r_l - 1) - l\})$ เมื่อ $r_l$ คือตำแหน่งของ $r$ ในรอบที่ $l$ และที่ $r_l$ ต้อง -1 ก็เพราะ $r$ เป็นตำแหน่งแรกที่เงื่อนไข $x_r - x_l \leq k$ ถูก break</p>
    <video src="https://github.com/user-attachments/assets/346beb54-998a-412a-9675-c66d622acf26" width="600" autoplay></video>
  </details>

</details>

[ac code sol1](./toi05_jump_bsearch.cpp)
[ac code sol2](./toi05_jump_prefsum.cpp)
[ac code sol3](./toi05_jump_slidingwindow.cpp)
[ac code sol4](./toi05_jump_twopointer.cpp)
