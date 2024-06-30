## toi19_phitsanulok
[problem statement](https://programming.in.th/tasks/toi19_phitsanulok)
<details>
  <summary>variable definition</summary>
  <ul><p></p>
  <p>N - จำนวนชนิดของผลไม้</p>
  <p>S - จำนวนขนานของพิษ / ยาถอนพิษ</p>
  <p>i - ตัวแปรแสดงชนิดผลไม้</p>
  <p>w<sub>i</sub> - น้ำหนักของผลไม้ชนิดที่ i</p>
  </ul>
</details>

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เนื่องจากจำนวนขนานของพิษมี ≤ 19 ทำให้เราสามารถเก็บสถานะการติดพิษตรงๆได้</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>เราสามารถมองโจทย์ข้อนี้เป็นปัญหา shortest path ได้?</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>เราสามารถ construct graph ใหม่ ? เพื่อลด TC ในการ transition จาก state เดิมไปสู่ state ใหม่</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>bitmask dynamic programming, Dijkstra's algorithm</ul>
</details>

<details>
  <summary>solution</summary>
  <p>เนื่องจากน้อนอุ้มจะหาวิธีเมื่อติดพิษใดๆในตอนแรกไปสู่สภาวะไม่ติดพิษที่ได้ผลรวมน้ำหนักน้อยสุดเสมอ ทำให้เรานึกถึง dynamic programming หรือ shortest path และเนื่องจากจำนวนขนานพิษมี ≤ 19 ซึ่งน้อยมากพอที่เราจะเก็บตรงๆได้ โดย เราจะ represent set ของพิษที่ติดอยู่โดยใช้ bitmask ซึ่งเราจะมี state ทั้งหมดไม่เกิน $2^{19}$ state</p>
  <ul>
    <details>
      <summary>Sol 1 (TLE)</summary>
      <p>กำหนดให้ <code>D[mask]</code> แทนผลรวมน้ำหนักที่น้อยที่สุดโดยเริ่มจากพิษเริ่มต้นที่เราเลือกโดยที่ปัจจุบันเราติดพิษประเภทที่แสดงอยู่ใน mask โดย mask จะ represent เป็นเลขฐานสอง เช่น mask = $(101011)_2$ แทนว่า เราติดพิษประเภทที่ 0, 1, 3, 5 โดย transition ของเราก็คือ <mark>$D[พิษ_i] = \min\{D[mask] + w_i\}$ โดย $i$</mark> คือประเภทของผลไม้ โดยการที่เราจะกินผลไม้ที่ $i$ ได้นั้นผลไม้ที่ $i$ จะต้องถอนพิษที่เรามีอยูได้ทั้งหมด พูดอีกอย่างก็คือ ถ้าเราสร้าง mask ของยาถอนพิษของผลไม้ที่ $i$ โดยที่ 1 แสดงสถานะการที่ผลไม้นี้สามารถถอนพิษประเภทนี้ได้, และ 0 คือถอนไม่ได้ เช่น $(101110)_2$ แทนว่า ผลไม้นี้สามารถถอนพิษประเภทที่ 1, 2, 3, 5 ได้ mask ของยาถอนพิษนี้ต้องเป็น superset (คือมี 1 อย่างน้อยอยู่ทุกตำแหน่งที่พิษที่ติดปัจจุบันมีอยู่) ของพิษที่เราติดอยู่ปัจจุบัน โดยเราจะทำการ loop ทุกผลไม้แล้วดูว่าเราสามารถกินได้ไหม ถ้าได้ (mask ยาเป็น superset ของพิษปัจจุบัน) ก็ลองกินดู โดยถ้าเราพิจารณา graph ดูแล้วกราฟของ state จะมี cycle ได้เนื่องจากอาจมีผลไม้ที่มี mask พิษเหมือนกัน ทำให้ไม่สามารถทำ topological sorting แล้วทำ dynamic programming ได้ เราจึงไปใช้ dijkstra แล้วเรายังต้อง run dijsktra ถึง $N$ รอบเนื่องจากเราต้องลองทุกๆพิษเริ่มต้นเพื่อหาผลรวมน้ำหนักที่มากสุด ทำให้เราต้องหาวิธีในการ optimize ต่อ</p>
      <p align="center">
        <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/5c65e721-edf8-4b81-8032-52339cc15302" alt="transition 1"/>
      </p>
    </details>
    <details>
      <summary>Sol 2 (Optimization of Sol 1)</summary>
      <p>จาก Sol 1 ปัญหาที่เราต้องแก้ได้แก่ <br>1. การที่เราต้อง run dijkstra ถึง N รอบ เพื่อลองหาพิษเริ่มต้นที่ดีที่สุด และ <br>2. การที่เราต้อง loop N รอบเพื่อหาผลไม้ที่กินได้ตรงๆ</p>
      <ul>
        <details>
          <summary>Solution to problem 1</summary>
          <p>เราต้องการไปสู่ state ที่ไม่ติดพิษเสมอ คือ <code>mask = 0</code>, เราเลยทำการ reverse graph แล้วเริ่มจาก state <code>mask = 0</code> ก่อนเพื่อที่จะ dijkstra เพียงรอบเดียว</p>
        </details>
        <details>
          <summary>Solution to problem 2</summary>
          <ul>
            <li>เราจะลดการ loop ในการหาผลไม้โดยที่เราจะ construct graph ใหม่เพื่อเพิ่มเงื่อนไขเข้าไปใน graph เลยโดยที่ตอนแรก transition ของเราจะเป็น <mark>$[พิษปัจจุบัน]$ — $loop$ $check$ $ผลไม้$ —> $[พิษของผลไม้ที่กิน]$</mark></li>
            <li>เราจะเปลี่ยนการ loop เป็นการใส่ผลไม้ไปใน graph โดย transition เป็น <br> <mark>$[พิษปัจจุบัน]$ —> $[ยาถอนพิษ_i (superset ของ พิษปัจจุบัน)]$ — $w_i$ —> $[พิษ_i]$</mark> </li>
            <li>และจากที่เราต้อง reverse graph จึงได้เป็น <br><mark>$[พิษ (subset ของ ยาถอนพิษ_i)]$ <— $[ยาถอนพิษ_i]$ <— $w_i$ — $พิษ_i$ </mark><br>ซึ่งตอนนี้ปัญหาของเราก็จะเหลือว่าเราจะหา subset ยังให้เร็วเพราะเราไม่สามารถไล่ subset ทุกตัวในการ transition ได้</li>
          </ul> <br>
          <p align="center">
            <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/340d4423-189d-48f3-a77d-54bcd26d3d42" alt="transition2"/>
          </p>
          <ul>
            <details>
              <summary>Solution to subset transition problem</summary>
              <p>เราไล่เฉพาะ subset ที่ปิดไปแค่ 1 bit ก็พอเพราะ weight ของ edge เป็น 0 สมมติ เราต้องการ transition จาก <br>$(10110)_2$ - $0$ -> $(10000)_2$ ก็มีค่าเท่ากับ <br>$(10110)_2$ - $0$ -> $(10100)_2$ - $0$ -> $(10000)_2$ เพราะสุดท้าย weight รวมก็คือ 0 อยูดี</p>
              <p align="center">
                <img width="600" src="https://github.com/packmani/toi-posn-com-guide/assets/40173086/44595aa1-4861-4837-abbc-0f570ded9056" alt="subset transition"/>
              </p>
            </details>
          <p>หลังจากเรา dijkstra เสร็จคำตอบของเราก็คือ $\max\{D[พิษ_i]\}$</p>
          <p>TC = $O(S*(N+2^S)\log 2^S) = O(S^2 * (N+2^S))$</p>
          </ul>
        </details>
      </ul>
    </details>
  </ul>
</details>
              
[ac code](./toi19_phitsanulok.cpp) 
