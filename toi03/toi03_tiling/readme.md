## toi3_tiling
[problem statement](https://programming.in.th/tasks/toi3_tiling)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Graph transversal</li>
    <ul>
      <li>Flood fill (BFS) <a href="https://usaco.guide/silver/flood-fill">[Flood Fill · USACO Guide]</a></li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เรานำจำนวน <code>L</code> ที่อยู่ใน grid โดยที่เราจะแยกแต่ละชิ้น (component) ออกจากกันด้วยตัวเลข (component เดียวกันจะมีเลขเหมือนกัน) ซึ่งในการหา component นั้นเราจะใช้ Flood Fill ที่ implement โดยใช้ BFS (Breath-First Search) ขยายพื้นที่ไปเรื่อยๆเมื่อยังเป็นเลขเดียวกันอยู่</p>
  <video src="https://github.com/user-attachments/assets/1159a86c-32a7-4a0c-a2cd-bb6d1a3fdfa2" width="600" autoplay></video>
  <p>เมื่อเราหา component แล้วเราก็จะ check ว่า component ที่หาได้นั้นเป็นรูป <code>L</code> หรือไม่ โดยที่เราจะ fix ตำแหน่งมุมแล้วไล่ตัวช่องที่ติดกันแล้วประกอบกันเป็นมุมฉาก (<code>⅂  L  ⅃</code>)</p>
  <p>$TC = O(n^2)$</p>
</details>

[ac code](./toi03_tiling)
