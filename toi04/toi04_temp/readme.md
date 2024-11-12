## toi4_temp
[problem statement](https://programming.in.th/tasks/toi4_temp)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Graph Transversal</li>
    <ul>
      <li>BFS <a href="https://usaco.guide/silver/flood-fill?lang=cpp">Flood Fill · USACO Guide</a></li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์มี grid และให้จุดเริ่มต้นมา โจทย์ให้เราเดินจากจุดเริ่มต้นไปหาช่องที่มีค่ามากสุดที่เราไปหาได้ โจทย์ถามหาว่าค่านั้นมีค่าเท่าไหร่ โดยที่เราห้ามผ่านช่องที่มีค่า = 100.</p>
  <p><ins>-BFS-</ins>:</p>
  <p>เราก็สามารถทำการ BFS จากจุดนั้นไปหาจุดที่ติดกันทั้งสี่ทิศทางโดยเราแค่ต้องเพิ่มเงื่อนไขจาก BFS ปกติคือการ check ว่าช่องที่จะไปมีค่า > ค่าที่เราอยู่ไหม</p>
</details>

[ac code](./toi04_temp.cpp)
