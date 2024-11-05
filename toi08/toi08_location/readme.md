## toi8_location
[problem statement](https://programming.in.th/tasks/toi8_location)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>inclusion exclusion (ทั้งหมด - ไม่เอา)</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>2D prefix sum</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>2D prefix sum</p>
</details>

<details>
  <summary>variable definition</summary>
  <p>$M$ - จำนวนแถว</p>
  <p>$N$ - จำนวน column</p>
  <p>$a_{ij}$ - จำนวนประชากรในช่อง $(i, j)$</p>
</details>

<details>
  <summary>solution</summary>
  <p>เราสรุปโจทย์ได้ว่ามีตารางขนาด $M \cdot N$ เราต้องการหาว่าผลบวกในตารางขนาด $K \\cdot K$ ที่อยู่ในตารางขนาด $M \cdot N$ ที่มากที่สุดมีค่าเท่าไหร่</p>

  <p>เราจะทำการ fix ตำแหน่งขวาล่างของตารางเป็น $(i, j)$ แล้วทำการหาผลบวกในตารางย่อยที่มีขนาด $K \cdot K$ ที่มีช่องซ้ายบนอยู่ที่ตำแหน่ง $(i-k+1, \\ j-k+1)$ และ ช่องขวาล่างอยู่ที่ $(i, j)$ ทำแบบนี้กับทุก $(i, j)$. ถ้าเรา loop ตรงๆ จะได้ TC = $O(MNK^2)$ ซึ่งยังไม่ทัน</p>

  <p>เราสามารถใช้ 2D prefix sum ในการลดเวลา loop หาผลบวกได้ โดยเราจะนิยาม $qs(i, j)$ เป็นผลบวกของ $a_{xy}$ โดยที่ $0 ≤ x ≤ i$ และ $0 ≤ y ≤ j$ (ตารางที่มีช่องซ้ายบนที่ $(0, 0)$ และมีช่องขวาล่างที่ $(i, j)$). เราสามารถใช้ตาราง $qs$ นี้ในการหาผลบวกของตารางย่อยได้โดยใช้หลักการ inclusion exclusion</p>
  <ul>
  <li>เตรียม $qs(i, j)$:<br>
  $qs(i, j) = qs(i-1, j) + qs(i, j-1) - qs(i-1, j-1) + a_{ij}$</li>

  <p align="center"><img src="https://github.com/user-attachments/assets/55cc70f3-4e54-4302-9383-fdb52fa9bef1"/></p>

  <li>ผลบวก $a_{xy}$ ในตารางย่อยขนาด $K \\cdot K$ ที่มีช่องขวาล่างที่ $(i, j)$ หาได้จาก:<br>
  $qs(i, j) - qs(i-k, j) - qs(i, j-k) + qs(i-k, j-k)$</li>

  <p align="center"><video src="https://github.com/user-attachments/assets/262ba85b-d64b-4f7a-82a8-fe0338a4f139" width="600" autoplay></video></p>
  </ul>
  <p>เราทำแบบนี้กับทุก $(i, j)$ ทำให้มี TC = $O(N^2)$</p>
</details>

[ac code](./toi08_location.cpp)
