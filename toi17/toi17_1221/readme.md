## toi17_1221
[problem statement](https://programming.in.th/tasks/toi17_1221)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>ลองพิจารณาโจทย์ ราคาของของแพคคู่ เราจะเก็บยังไงดี</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>สมมติเราจะต้องซื้อของดังนี้ $(a,x), (x,y), (y,z), (z,b)$ การหาคู่ๆมาต่อกันแบบนี้ ให้ราคารวมน้อยที่สุด คล้ายกับ algorithm ที่ใช้แก้อะไร</p>
    </details>
    <details>
      <summary>hint 3</summary>
      <p>โจทย์ต้องการถามหลายๆรอบ เราต้องทำซ้ำๆ หรือเราสามารถ compute ไว้ก่อนก็ได้ เพื่อประหยัดเวลา ลองหา algorithm ที่หาคำตอบของทุกคำถามในเวลาเดียวกัน</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>shortest path algorithms</p>
</details>

<details>
  <summary>main idea</summary>
  <p>โจทย์ข้อนี้เราจะต้องพยายามซื้อของราคาถูกที่สุดก่อน และจำนวนมากที่สุดถ้าหากว่าราคารวมเท่ากัน โดยทุก item ที่เราซื้อจะต้องซื้อเป็นคู่ ยกเว้นของ $P_{q,a}$ และ $P_{q,b}$</p>
  <p>แต่ละโปรโมชั่นจะประกอบด้วยของ 2 ชิ้น และราคาซื้อคู่ ซึ่งโจทย์รับรองว่าถูกกว่าซื้อแยก</p>
  <p>constraints ของข้อนี้ n≤500 สามารถทำ algorithm ที่ O(n^3) ทัน แต่เนื่องจากจะถามไม่เกิน 10,000 ครั้ง เราจะต้องหาวิธีทำให้ออกครั้งเดียว ไม่งั้นเราจะต้องทำภายในเวลา O(nlogn) </p>
  <p>เราจะ represent ข้อมูลทั้งหมดด้วยกราฟ โดยให้ node แทนแต่ละ item และ edge ที่เชื่อม u,v แทนราคาของการซื้อ item u และ v  ซี่งที่ไม่มีแพคคู่ weight จะเท่ากับ ราคารวมของ u และ v แต่ถ้ามีแพคคู่ weight ของ edge นั้นจะลดลง เมื่อทำครบ เราจะได้กราฟที่มีราคาของทุก node ไปทุก node</p>
  <p>ถัดมา การจะหาวิธีซื้อที่ถูกที่สุด จะเทียบเท่าการหา shortest path จาก a ไป b และถ้าผ่าน node อื่นๆ เช่น c การที่เส้นทางเราเข้าและออกจาก node c ทำให้ c  ถูกซื้อ 2 รอบ ซึ่งคือตรงกับที่โจทย์ต้องการ</p>
  <p>ส่วนจำนวนของที่มากที่สุดที่ได้ เราจะหาไปพร้อมกัน shortest path เลย โดยเมื่อเราคิด shortest path จาก a→x→y <br>จะได้ว่า จำนวนitem a→y = จำนวนitem a→x + จำนวนitem x→y</p>
</details>

<details>
  <summary>solution</summary>
  <p>อย่างแรกเราจะสร้างกราฟ ในข้อนี้ เนื่องจากมี edge จากทุก node ไปทุก node เราจะใช้ adjacency matrix ที่ e[i][j] = price[i] + price[j] และ c[i][j] แทนจำนวนitem ที่ได้จากการซื้อ i to j ซื่งเท่ากับ 2</p>
  <p>ถัดมารับเมื่อรับแพคซื้อคู่(a,b) เราจะอัพเดต e[a][b] = promotion price</p>
  <p>สุดท้าย สำหรับแต่ละ q เราจะหา shortest path จาก node 1 ไป node n</p>
  <ul>
    <details>
      <summary>solution 1</summary>
      <p>basic algorithm เพื่อแก้ shortest path คือ dijkstra โดยแต่ละ q(a,b) จะหาเส้นทางจาก a→b โดยเมื่อเพิ่ม edge ที่ผ่าน c[a][x] จะเพิ่มขึ้น 2 ชิ้น ทำไปเรื่อยๆจนเจอ b และเอาท์พุตมาเป็น distance[b] และ c[a][b] แต่เนื่องจากเราำต้องทำ Q ครั้ง วิธีนี้จะทำงานได้ในเวลา O(Q*(V+ElogV)) เนื่องจาก Q≤10,000 และ E≤100,000 ทำให้หาคำตอบไม่ทัน</p>
    </details>
    <details>
      <summary>solution 2</summary>
      <p>สังเกตว่าเราจะหา shortest path จากหลายๆ node ไปหลายๆ node วิธีแก้ที่สามารถคิดรวมไปเลยคือ floyd-warshall’s algorithm และเพิ่ม c[i][j] = c[i][k] + c[k][j] ซึ่งสามารถ compute เส้นทางสั้นที่สุดหรือราคารวม จากทุก node ไปทุก node ได้ในเวลา O(n^3) แต่แลกมาด้วยการที่ลดเวลาของแต่ละ query เป็น O(1) เลย เพราะรับค่า และเอาท์พุต e[x][y] ทำให้ใช้เวลารวม O(n^3) ซึ่งสามารถทำใน 1 วินาทีได้</p>
    </details>
  </ul>
</details>

[ac code](./toi17_1221.cpp)
