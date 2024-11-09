## toi12_peak
[problem statement](https://programming.in.th/tasks/toi12_peak)

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>STL</li>
    <ul>
      <li><code>std::unique()</code></li>
      <li><code>std::sort()</code></li>
    </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราหา local ความสูงที่เป็น local maximum แล้วนำมาเรืยงจากมากมาน้อย แล้วทำการหา $k$ ลำดับแรกหลังการนำเลขที่ซ้ำออก เราสามารถตรงๆได้เลย โดยใน C++ มี function <code>std::sort</code> และ <code>std::unique</code> ให้เราใช้</p>
</details>

[ac code](./toi12_peak.cpp)
