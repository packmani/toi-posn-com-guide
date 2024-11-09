## toi14_plantation
[problem statement](https://programming.in.th/tasks/toi14_plantation)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>การจะ check ว่าได้มาตรฐานไหมเราแค่ต้อง check ว่าระยะปลายกิ่งที่ <em>น้อยสุด</em> ระหว่าง 2 คู่ต้นไม้ใดๆ นั้น $≥d$ ?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>closest pair of points</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>closest pair of points <a href="https://www.youtube.com/watch?v=l8ANAELnbPg">(200) Closest Pair of Points | Coding Live! - YouTube</a></li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราไม่จำเป็นต้อง check ระยะทางทุกคู่ แค่หาระยะที่น้อยที่สุดแล้ว check ก็เพียงพอแล้ว. ทำให้เราได้ปัญหาก็คือการหา closest pair of point ซึ่งในที่นี้เราจะแก้โดยใช้ divide and conquer ใน $\leq O(Nlog^2N)$</p>
  <ins>-Divide and conquer-</ins>
  <p>เราจะแบ่งแยกย่อยปัญหาไปเรื่อยๆ จนกว่าเราจะรู้คำตอบย่อยของปัญหานั้น (base case) โดยเราจะใช้ recursive function ในตอนแรกเรามีพิกัด $(x, y)$ อยู่ทั้งหมด $N$ จุด เราจะแบ่งเป็นปัญหาย่อยที่มีขนาด $N/2$ เป็น 2 ปัญหาแบ่งเป็นฝั่งซ้ายและฝั่งขวา แต่ละปัญหาขนาด $N/2$ ก็จะแบ่งเป็นปัญหาขนาด $N/4$ แล้วก็แบ่งไปเรื่อยๆจนกว่าจะรู้คำตอบได้เลย ในที่นี้เราให้คือมีจุดแค่สองจุดหรือจุดเดียว แล้วหลังจากที่ได้คำตอบเราจะนำปัญหาย่อยมารวมเป็นปัญหาใหญ่ที่แยกมาจาก เช่น หากเราได้คำตอบของปัญหาขนาด $X$ เราจะนำมาใช้เพื่อหาคำตอบของปัญหาขนาด $2X$.</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/33d7fd3e-8dc8-4231-b12e-171974cb4168" /></p> <!-- IMG_2043.jpeg -->
  <p>ในการแบ่งจุดเราจะแบ่งตามพิกัดแกน $X$ โดยแบ่งทางซ้ายไปครึ่งนึง และทางขวาอีกครึ่ง. ดังนั้นตอนเริ่มเราจะ sort พิกัด $(x, y)$ ตาม $x$ จากน้อยมามาก (แต่ถ้า $x$ เท่า เราเรียงตาม $y$ จากน้อยมามาก). โดยให้ $l$ และ $r$ เป็น parameter ที่ระบุปัญหาย่อย $cl(l, r)$ = ระยะ Euclidean ที่ใกล้ที่สุดระหว่างจุดที่มี index อยู่ในช่วง $[l, r]$ (หลัง sort).</p>
  <ul>
    <li>คำตอบ = min({คำตอบซ้าย, คำตอบขวา, [ระยะระหว่าง (จุดจากฝั่งซ้าย) และ (จุดจากฝั่งขวา) ที่น้อยที่สุด]})</li>
    <li>$cl(l, r) = min(\{cl(l, \lfloor (l+r)/2 \rfloor), \ cl(\lfloor (l+r)/2 \rfloor + 1, r), \ d(l, r)\})$</li>
    <li>$d(l, r) \equiv$ [ระยะระหว่าง (จุดจากฝั่งซ้าย) และ (จุดจากฝั่งขวา) ที่น้อยที่สุด]</li>
  </ul><hr>
  <ins>-fast enough?-</ins>
  <p>สิ่งที่อาจจะทำให้ช้าได้คือการหา $d(l, r)$. ถ้าเราไล่ทุกคู่จะทำให้ขั้นตอนการหามี $TC$ $O((r-l+1)^2)$ ซึ่งช้าเกิน. แต่เราไม่ต้องไล่ทุกจุด เราแค่ไล่เฉพาะจุดที่อยู่ใน *แถบตรงกลาง* ก็พอ และแต่ละจุดที่อยู่ในแถบ จะมีจุดที่ระยะทางห่างจากจุดนั้นที่ $≤ \delta$ เป็น constant $$(O(1))$$ จุดเสมอ ทำให้เราสามารถหาได้ใน $O(r-l+1)$. , $\delta \equiv min(\{cl(l, \lfloor (l+r)/2 \rfloor), \ cl(\lfloor (l+r)/2 \rfloor + 1, r)\})$</p>
  <p>[การที่เราไล่จุดนอกแถบกลางทำให้ได้ระยะ $≥ \delta$ ซึ่งไม่ทำให้ได้คำตอบที่ดีขึ้น]</p>
  <p align="center"><img width="600" src="https://github.com/user-attachments/assets/faa62f98-e3db-48b5-8024-21c5373c1ce3" /></p> <!-- IMG_2049.jpeg -->
  <p>จากรูปเราได้พิสูจน์ว่าในกล่องขนาด $\delta/2 \times \delta/2$ จะมีจุดได้อย่างมากแค่ 1 จุด เพราะถ้ามีมากกว่า 1 จุดจะทำให้ $\delta$ ไม่ใช่คำตอบที่ดีที่สุดจากฝั่งซ้ายหรือขวาซึ่งจะขัดแย้งกับการที่เราหา $\delta$ มาได้. ทำให้เราสามารถไล่ check ตรงๆได้เลย โดยเราจะ sort จุดที่อยู่ใน *แถบกลาง* เรียงตามพิกัดแกน $Y$ จากน้อยมามาก (ไล่จุดจากล่างขึ้นบน) จากการพิสูจน์, แต่ละจุดจะมีจุดที่ต้อง check $≤$ 8 จุด ซึ่งเป็น constant $(O(1))$.</p>
  <p>ทำให้เราได้ $TC$ รวมเป็น $O(Nlog^2N)$</p>
  <hr>
  <details><summary><ins>Why?</ins></summary>
  <ul>
    <li>ให้ $T(N)$ เป็น function เวลาที่ขึ้นอยู่กับ $N$</li>
    <li>$base \\ case : T(1) = c$</li>
    <li>$T(N) = 2 T(N/2) + O(NlogN)$</li>
    <li>$T(N) = 2 T(N/2) + c NlogN$</li>
    <li>$T(N) = 2^2 T(N/4) + 2c (N/2)log(N/2) + c NlogN$</li>
    <li>$T(N) = 2^3 T(N/8) + 2^2 c (N/4)log(N/4) + 2c (N/2)log(N/2) + c NlogN$</li>
    <li>$T(N) = 2^{k} T(N/2^k) + 2^{k-1} c (N/2^{k-1})log(N/2^{k-1}) + \ldots + c NlogN$</li>
    <li>$k = log_2{N};$<br> $T(N) ≤ c \cdot N + (log_2{N}) \cdot c \cdot Nlog_2N$<br> $T(N) \leq O(Nlog^2N)$</li>
  </ul>
  </details>
  <p>ในตอนนี้เราสามารถหา Euclidean distance ระหว่างจุดคู่ที่สั้นสุดได้ $= cl(1, N)$. เนื่องจากมีรัศมีพุ่มไม้ $(r)$ ด้วยทำให้ระยะทางจริงๆเป็น $cl(1,N) - 2r$. หากระยะนี้ $≥ d$ ตอบ YES, หากไม่ตอบ NO</p>

  <p><strong>Bonus:</strong> ลองแก้ปัญหานี้โดยใช้ $TC ≤ O(NlogN)$ ดูครับ</p>
</details>

[ac code](./toi14_plantation.cpp)
