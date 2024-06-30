## toi19_range
[problem statement](https://programming.in.th/tasks/toi19_range)
<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ข้อนี้มีการดึงคำตอบมาจากช่วงที่อยู่ภายใน ทำให้เรานึกถึง algorithm อะไร?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>dynamic programming</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>ถ้าช่วง $[L_j, R_j]$ อยู่ภายในช่วง $[L_i, R_i]$ แสดงว่า $L_i ≤ L_j$ และ $R_j ≤ R_i$ เราสามารถแก้อย่างน้อย 1 เงื่อนไขด้วยการ?</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>sorting</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>dynamic programming, LIS - binary search / Range query data structure (Segment tree / Binary indexed tree) <br><a href="https://cp-algorithms.com/sequences/longest_increasing_subsequence.html">Longest increasing subsequence - Algorithms for Competitive Programming (cp-algorithms.com)</a></p>
</details>

<details>
  <summary>solution</summary>
  <p>เงื่อนไขของการที่ช่วง j จะอยู่ภายในช่วง i แบ่งได้เป็นสองส่วนคือ $L_i ≤ L_j$ และ $R_j ≤ R_i$ เราสามารถแก้เงื่อนไข $R_j ≤ R_i$ ได้โดยการ sort โดยเราจะ sort ให้ช่วงที่อยู่ภายในมาก่อนช่วงที่ครอบเสมอโดยเราจะ sort ตามเงื่อนไขว่าถ้า $R_j ≠ R_i$ เราจะเลือกตัวที่มีค่า R น้อยกว่าอยู่ด้านหน้า ส่วนถ้า $R_j = R_i$ เราจะเลือกตัวที่มีค่า L มากกว่าอยู่ด้านหน้า</p>
  <p align="center">
    <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/4dd25d0d-eafe-403f-af77-5bfcb6c7a3b0" alt="range covering" />
  </p>
  <p>ตอนนี้เราเหลือแค่เงื่อนไขที่ว่า $L_i ≤ L_j$ คะแนนของช่วง $(i)$ คือ maximum ของคะแนนของช่วงที่อยู่ภายใน $(j)+1$ โดยการคิดคะแนนนี้ก็เหมือนกับการหาความยาวของ longest non-increasing subsequence โดยเราจะนำ array $L$ หลัง sort ตาม $R$ มาทำ longest non-increasing subsequence</p>
  <ul>
    <details>
      <summary>Sol 1 - binary search</summary>
      <ul>
      <li>เราจะใช้หลักการของ patience sorting มาใช้ในการหา ความยาวของ longest non-decreasing subsequence (คล้ายๆกับ LIS แต่ element ซ้ำกันได้) โดยทำการ loop จากซ้ายมาขวาแล้วนำตัวเลข x ไปใส่บนกองซ้อน ที่มี <mark>element ด้านบนสุด > x</mark> ที่อยู่ซ้ายที่สุด ถ้าไม่มีเลขด้านบนที่ว่า ก็สร้าง stack ใหม่ที่มีแค่ x </li>
      <li>จากการสังเกตเราจะพบว่าเราสามารถนำ x ไปต่อกับตัวเลขที่อยู่ด้านบนสุดที่อยู่ในกองซ้อนด้านหน้ากองซ้อนของ x ได้ <br>เพราะฉะนั้นถ้าเรา run algorithm นี้จนจบเราจะได้ความยาวของ longest non-decreasing subsequence เป็นจำนวนของกองซ้อนทั้งหมด </li>
      <li>ในการหาตำแหน่งของกองซ้อนที่เราจะใส่ x เราสามารถใช้ binary search ได้, binary search บน array ของ element ที่อยู่บนสุดของแต่ละกองซ้อนเพื่อหา <mark>ตำแหน่งแรกที่ > x (upper_bound)</mark> เนื่องจาก array ของ element บนสุด sort จากน้อยไปมากเสมอ</li>
          <video src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/da727dac-05a0-46b7-a3bf-6977f3b81688" 
            width="600" autoplay></video>                  
      <li>แต่เราต้องการหาความยาวของ longest non-increasing subsequence ซึ่งก็สามารถทำได้โดยการ flip เลขจากจำนวนบวกไปเป็นจำนวนลบแล้วทำการ binary search N รอบ เพื่อหาความยาวของ longest non-decreasing subsequence ทำให้มี TC = $O(N\log N)$</li>
      </ul>
    </details>
    <details>
      <summary>Sol 2 - Fenwick tree</summary>
      <ul>
      <li>เราสามารถแก้ปัญหา longest non-decreasing subsequence ได้ด้วยการใช้ dynamic programming</li>
      <li>กำหนดให้ $dp_i$ แทนความยาวของ longest non-decreasing sequence โดยจบที่ element ตำแหน่ง $i$ โดยมี recurrence คือ <br>$dp_i = max(\{dp_j + 1\}); j < i$ และ $element_j ≤ element_i$</li>
      <li>แต่ปัญหาอยู่เราต้อง loop หา $j$ ทำให้มี $TC = O(N^2)$ เราสามารถใช้ binary indexed tree มาลดเวลาในการ loop $j$ ได้ เพราะ BIT สามารถทำ point update และ prefix query ได้ใน $O(\log N)$ ทำให้เราสามารถหาค่า maximum ของ $dp_j$ ในช่วง $[1, element_i]$ ได้ใน $O(\log N)$ แล้วเราก็ทำการ update $dp_i$ ไว้ในตำแหน่งของ $element_i$ ไปเรื่อยๆ</li> 
      <li>โดยคำตอบของเราก็คือ $max(\{dp(i)\})$ แต่ติดปัญหาคือการที่ $element_i$ อาจมีค่ามากถึง $10^9$ ทำให้เราไม่สามารถนำค่าไปใส่ใน array ได้ตรงๆ แต่เราสามารถแก้ได้โดยการทำ coordinate compression</li>
      <br>
      <details>
        <summary>coordinate compression</summary>
        <p>สมมติ $element = \{100, 1, 23, 23\}$ เราสามารถเปลี่ยนเป็น $element' = \{3, 1, 2, 2\}$ ซึ่งทำให้เราสามารถ map ค่า element จริงๆ ไปเป็น index ใน array ได้ เพราะเรามี element แค่ N ตัว เราสามารถทำได้โดยการ sort แล้ว unique (อาจมีเลขซ้ำ) แล้วทำการ binary search เพื่อหาตำแหน่งสำหรับแต่ละเลข (upper_bound)</p>
      </details>
      <p>แต่ปัญหาของเราคือต้องหาความยาวของ longest non-increasing subsequence ซึ่งสามารถทำได้โดย flip index ของแต่ละ element เช่น $element' = \{3, 1, 2, 2\}$ → $element'' = \{1, 3, 2, 2\}$ ทำให้ query prefix ของเราจะเปลี่ยนไปเป็นการหา maximum ในช่วงที่ $≥ element_i$ แทน</p>
      <p align="center">
        <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/3376b647-ce60-4c2f-a351-ae8ad7aaa9ab" />
      </p>
      </ul>
    </details>
  </ul>
</details>


[ac code (binary search)](./toi19_range_bsearch.cpp) 

[ac code (fenwick tree)](./toi19_range_fenwick.cpp) 
