## toi11_place
[problem statement](https://programming.in.th/tasks/toi11_place)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>K เป็นจำนวนเส้นทางที่น้อยที่สุดที่ยังสามารถเดินไปทุกที่ได้ครบ แสดงว่า K = ?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>$K = N-1$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>tree + ความยาวรวมมากสุด ?</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>maximum spanning tree</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>MST algorithm <a href="https://usaco.guide/gold/mst">Minimum Spanning Trees · USACO Guide</a>
      <ul>
        <li>Prim’s</li>
        <ul>
          <li>Dijkstra’s algorithm</li>
        </ul>
        <li>Kruskal’s</li>
        <ul>
          <li>DSU (Union-Find data structure)</li>
        </ul>
      </ul>
    </li>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>เราสามารถย่อยโจทย์ข้อนี้เหลือแค่ให้ค่าผลรวม weight ของ maximum spanning tree ของ graph ที่มีจุดยอดเป็นสถานที่ศักดิ์สิทธิ์ $N$ จุดและมีเส้นเชื่อม $M$ เส้น เชื่อมระหว่าง $s_i$ และ $d_i$ โดยที่มี weight ขนาด $l_i - 1$. เราสามารถแก้ปัญหานี้ได้ด้วย Prim’s algorithm หรือ Kruskal’s algorithm ใน $TC = O(M \log M)$</p>
  <p align="center">
    <img width="600" src="https://github.com/user-attachments/assets/cef28ed3-9d7a-400b-9897-9d4172685491" />
  </p>
</details>

[ac code ver1](./toi11_place_prims.cpp)<br>
[ac code ver2](./toi11_place_kruskal.cpp)
