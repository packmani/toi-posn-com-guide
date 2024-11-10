## toi20_lover
[problem statement](https://api.otog.in.th/problem/doc/1018)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>$N \leq 10^4$</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>$O(N^2)$</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>Minimize ?</p>
    </details>
    <details>
      <summary>hint 2.5</summary>
      <p>Dynamic programming</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Dynamic programming</li>
    <li>Prefix sum</li>
  </ul>
</details>

<details>
  <summary>solution</summary><br>
  โจทย์ข้อนี้ให้เราหาค่าที่น้อยที่สุดทำให้นึกถึง dynamic programming โดยเราจะกำหนดให้
  <ul>
    <li>$dp(i) \equiv \text{\small จำนวนช่วงที่น้อยที่สุดในการที่จะทำให้เงื่อนไข} \ max(a_1, a_2, \ldots, a_{dp(i)}) \leq V  \ \land \max(b_1, b_2, \ldots, b_{dp(i)}) \leq W$ โดยที่เราจะพิจารณาไปแค่ร้านที่ $[1 \ldots i]$</li>
    <li>$\text{\small Base case} : dp(0) = 0$</li>
    <li>$\text{\small Transition} :$</li>
    <ul>
      <li>$dp(i) = min_{j=1}^{i-1}(\{dp(j-1) + 1\}) ; [j, \ldots i]$ ถูกต้องตามเงื่อนไข</li>
      <li>เงื่อนไข</li>
      <ul>
        <li>ผลบวก <strong>เลขคี่</strong> ในช่วงครึ่งแรก $[\ j \ldots \lfloor(i+j)/2\rfloor \ ] \leq V$</li>
        <li>ผลบวก <strong>เลขคู่</strong> ในช่วงครึ่งหลัง $[\ \lfloor {(i+j)/2} \rfloor + 1 \ldots i\ ] \leq W$</li>
        <li>ช่วงมีขนาดยาวเป็น <strong>จำนวนคู่</strong>  $(\ i - j - 1 \in 2\mathbb{Z}	)$</li>
      </ul>
    </ul>
    <li>ในการหาผลบวกช่วงโดยพิจารณาเลขคู่หรือเลขคี่เท่านั้นเราสามารถทำได้โดยใช้ prefix sum</li>
    <ul>
      <li>$qs_0(i) \equiv$ ผลบวกเลขคู่ในช่วง $[1 \ldots i]$</li>
      <ul>
        <li>$qs_0(i) = qs_0(i-1)$</li>
        <li>$\text{if} \ (x_i \in 2\mathbb{Z} ) \ qs_0(i) = qs_0(i) + x_i$</li>
      </ul>
      <li>$qs_1(i) \equiv$ ผลบวกเลขคี่ในช่วง $[1 \ldots i]$</li>
      <ul>
        <li>$qs_1(i) = qs_1(i-1)$</li>
        <li>$\text{if} \ (x_i \in 2\mathbb{Z}-1) \ qs_1(i) = qs_1(i) + x_i$</li>
      </ul>
    </ul>
    <p>ในการหาผลบวกในช่วง  $[l \ldots r]$ เราก็สามารถหาได้ จาก $qs_j(r) - qs_j(l-1)$</p>
    เนื่องจาก $N \leq 10^4$ ทำให้เราสำหรับแต่ละ $i$ เราสามารถไล่หา $\ j$;  $0 < j < i$ ตรงๆได้เลย ทำให้ได้ $TC = O(N^2)$
  </ul>
</details>

[ac code](./toi20_lover.cpp)
