## toi10_map
[problem statement](https://programming.in.th/tasks/toi10_map)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <p>เราสามารถมองโจทย์เป็น data structure อะไรได้?</p>
    </details>
    <details>
      <summary>hint 1.5</summary>
      <p>connected undirected graph</p>
    </details>
    <details>
      <summary>hint 2</summary>
      <p>เราไม่จำเป็นต้องรู้ตำแหน่งของแต่ละเลขจริงๆ ก็ได้ รู้ว่าเลขอะไรติดกับเลขอะไรก็พอแล้ว?</p>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <p>bfs, sorting</p>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ให้เราเรียงตัวเลขใน grid โดยบอกว่าตัวเลขเชื่อมกัน โดยบอกว่าความสัมพันธ์ว่า เลขใดอยู่ทางซ้ายเลขใด และ เลขใดอยู่ทางด้านบนเลขใด. เราสามารถความสัมพัทธ์ของโจทย์ข้อนี้เป็น connected undirected graph. เราจึงสามารถทำการ transverse graph โดยเริ่มที่ตำแหน่งใดก็ได้ ก็สามารถไปถึงตำแหน่งได้ทั้งหมด. สมมติเราเริ่มจากเลข 0 โดยกำหนดให้เป็นตำแหน่ง (0, 0) แล้วทำการ bfs ไปตาม graph ที่เราได้สร้างไว้ โดยหลังจากการ bfs เสร็จเราจะได้ตำแหน่งสำหรับทุกเลข. ตำแหน่งที่เราได้อาจจะไม่ได้เริ่มที่จุด (0, 0) และจบที่ (m-1, n-1) อาจจะมีมีเลขติดลบและ เกิน (m-1, n-1) แต่เราสามารถทำการ sort เพื่อให้เราสามารถเทียบกับ grid ที่เริ่ม (0, 0) ได้</p>
  <p align="center"><video src="https://github.com/user-attachments/assets/6ff2d4ac-898b-4d5a-ab23-f3b7b7b0ee91" width="600" autoplay></video></p>
</details>

[ac code](./toi10_map.cpp)
