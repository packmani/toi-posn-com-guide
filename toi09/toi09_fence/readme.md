## toi9_fence
### (แนะนำให้ใช้ light mode ในการอ่านเฉลยข้อนี้เนื่องจากในบางส่วนมีตัวอักษรเป็นสีดำ ขออภัยครับ)
[problem statement](https://programming.in.th/tasks/toi9_fence)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>$N \leq 500$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>เราไล่หาขนาดสี่เหลี่ยมทุกขนาดได้เลย?</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>prefix sum</li>
    <li>2D prefix sum</li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถมองโจทย์ข้อนี้เป็นการหาผลบวกได้ โดยถ้าเราใส่ค่าในตำแหน่งที่มีต้นไม้เป็น 1 ใน grid. สี่เหลี่ยมกลวงที่เราสร้างต้องมีผลบวกกรอบ = 0. เนื่องจาก $N \leq 500$ เราจึงต้องหาวิธีที่ทำในประมาณ $O(N^3)$ หรือเร็วกว่า</p>
  <details>
  <summary><ins>Sol 1 (prefix sum)</ins></summary>
  <p>เราสามารถแก้โจทย์ตระกูลที่ให้หาผลยวกได้ด้วย prefix sum แต่โจทย์ข้อนี้เป็น grid 2 มิติแต่เราสามารถแบ่งการหาผลบวกเป็น 1 มิติโดยคิดแยกแนวตั้งกับแนวนอน</p>
  <details>
    <summary><code>picture</code></summary>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/9cd3ae8d-0ea7-4f0f-b32d-5385537cac43" /></p>
    <p align="center"><video src="https://github.com/user-attachments/assets/5b15c7e9-80b8-4045-8571-2c5bd42ff608" width="600" autoplay></video></p>
  </details>
  <p>- ให้ $qs_0(i, j)$ ใช้เก็บ prefix sum แนวนอนจนถึง $j$ ในแถวที่ $i$</p>
  <ul>
     <li><img src="https://latex.codecogs.com/png.latex?\bg{white}\begin{bmatrix} (i,0) \rightarrow  (i, j) \end{bmatrix}\" alt="Matrix"></li>
  </ul>
  <p>- ให้ $qs_1(j, i)$ ใช้เก็บ prefix sum แนวตั้งจนถึง $i$ ใน column ที่ $j$</p>
  <ul>
    <li><img src="https://latex.codecogs.com/png.latex?\bg{white}\begin{bmatrix} (i,0) \\ \downarrow \\ (i, j) \end{bmatrix}\" alt="Matrix"></li>
  </ul>

  <p>จากใน <code>picture</code> เราจะสามารถกรอบเป็น 4 ส่วนได้ คือ $h_1, h_2, v_1, v_2$ โดยที่ให้ $k$ เป็นขนาดของกรอบ</p>

  <img src="https://latex.codecogs.com/png.latex?\bg{white}\cdot\\ h_1 = \sum\begin{bmatrix} (i, j-k+1) \rightarrow  (i, j) \end{bmatrix}\\= qs_0(i, j) - qs_0(i, j-k)" alt="Matrix">
  <br><br>
  <img src="https://latex.codecogs.com/png.latex?\bg{white}\cdot\\ h_2 = \sum\begin{bmatrix} (i-k+1, j-k+1) \rightarrow  (i-k+1, j) \end{bmatrix}\\= qs_0(i-k+1, j) - qs_0(i-k+1, j-k)" alt="Matrix">
  <br><br>
  <img src="https://latex.codecogs.com/png.latex?\bg{white}\cdot\\v_1 = \sum\begin{bmatrix} (i-k+1, j) \\ \downarrow \\ (i, j) \end{bmatrix}\\= qs_1(j, i) - qs_1(j, i-k)" alt="Matrix">
  <br><br>
  <img src="https://latex.codecogs.com/png.latex?\bg{white}\cdot\\v_2 = \sum\begin{bmatrix} (i-k+1, j-k+1) \\ \downarrow \\ (i, j-k+1) \end{bmatrix}\\= qs_1(j-k+1, i) - qs_1(j-k+1, i-k)" alt="Matrix">

  <p>เราจะสร้างกรอบได้ก็ต่อเมื่อ $h_1 \cup h_2 \cup v_1 \cup v_2 = 0$ ซึ่งแปลว่า $h_1 = h_2 = v_1 = v_2 = 0$. TC = $O(MN\cdot min(M, N))$ เนื่องจากเรา loop $j$ ซ้อน $i$ ซ้อน $k$ ซึ่ง $k$ มีได้มากสุด $min(M, N)$</p>
  </details>
  <details>
  <summary><ins>Sol 2 (2D prefix sum)</ins></summary>
  <p>เราสามารถสร้างรูปกรอบได้จากการลบรูปสี่เหลี่ยมรูปเล็กออกจากสี่เหลี่ยมรูปใหญ่</p>
  <details>
    <summary><code>image</code></summary>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/d33b6a87-9234-4c80-adf0-2f0ecb111d6a" /></p>
    <p align="center"><img width="600" src="https://github.com/user-attachments/assets/ff55a64e-251c-48ac-95e4-c0948fab9a2d" /></p>
    <p align="center"><video src="https://github.com/user-attachments/assets/a3f759b6-cd64-4afa-b282-5a0e458843b1" width="600" autoplay></video></p>
  </details>
  <p>โดยเราสามารถใช้ 2D prefix sum ในการหาผลบวกในรูปสี่เหลี่ยมได้</p>
  <ul>
    <li>$qs(i, j)$ เก็บผลบวก 4 เหลี่ยมที่มีมุมซ้ายบนอยู่ที่ $(0, 0)$ และมุมขวาล่างอยู่ที่ $(i, j)$</li>
    <li>$qs(i, j) = qs(i-1, j) + qs(i, j-1) - qs(i-1, j-1) + a_{ij}$  ; $a_{ij}$ เป็น 1 เมื่อ $(i, j)$ มีต้นไม้ และ 0 ถ้าไม่มี</li>
  </ul>

  <p>เราสามารถใช้หลักการ inclusion-exclusion ในการหาผลบวกในรูปสี่เหลี่ยมใดๆ ได้</p>

  <p>ให้ $k$ เป็นความยาวด้านของสี่เหลี่ยมรูปใหญ่ (outer) ทำให้เรารู้ว่าสี่เหลี่ยมด้านใน (inner) มีด้านยาว $k-2$</p>

  <ul>
    <li>$outer = qs(i, j) - qs(i-k, j) - qs(i, j-k) + qs(i-k, j-k)$</li>
    <li>$inner = qs(i-1, j-1) - qs(i-k+1, j) - qs(i, j-k+1) + qs(i-k+1, j-k+1)$</li>
  </ul>

  <p>เราจะสร้างกรอบได้เมื่อ $outer - inner = 0 \rightarrow outer = inner$</p>
  <p>TC = $O(MN \cdot min(M, N))$ เนื่องจากเรา loop $j$ ซ้อนใน $i$ และ $i$ ซ้อนใน $k$ ซึ่ง $k$ มีได้มากสุด $min(M, N)$</p>
</details>
</details>

[ac code sol1](./toi09_fence_1d.cpp) <br>
[ac code sol2](./toi09_fence_2d.cpp)
