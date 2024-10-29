## toi1_plate
[problem statement](https://programming.in.th/tasks/toi1_plate)

<details>
  <summary>hints</summary>
  <details>
    <summary>hint 1</summary>
    <p>simulation</p>
  </details>
  <details>
    <summary>hint 2</summary>
    <p>การเข้าแถวสามารถใช้ data structure อะไร represent ได้?</p>
  </details>
  <details>
    <summary>hint 2.5</summary>
    <p>queue (std::queue)</p>
  </details>
</details>

<details>
  <summary>solution</summary>
  <p>โจทย์ข้อนี้ให้เราทำการ simulate การเข้าแถวโดยการเข้าแถวจะเข้าแถวตามห้อง โดยนักเรียนที่จะมาเข้าแถวจะไปต่อหลังนักเรียนที่อห้องเดียวกันที่อยู่ในแถวอยู่แล้ว โดยการเข้าแถวทำให้เรานึกถึง data structure queue โดยเราจะใช้ queue 2 ประเภท ในการ simulate </p>
  <ol start="1">
    <li> $Q$ ใช้ในลำดับของห้อง โดยจะเก็บเป็นเลขประจำห้องไว้</li>
    <li> $q[cl]$ ใช้ในการเก็บลำดับของนักเรียนที่อยู่ห้อง $cl$ </li>
  </ol>
  <details>
    <summary>operation E (เอานักเรียน <ins>s</ins> เข้าแถว)</summary>
    <ul>
      <li>นำนักเรียน s เข้า $q[cl_s]$ เข้าใน $Q$</li>
      <li>ถ้า $cl_s$ ยังไม่อยู่ใน $Q$ (ก่อนหน้านี้ยังไม่มีนักเรียนจาก $cl_s$ อยู่ในแถว) → push $cl_s$ เข้าใน $Q$</li>
    </ul>
  </details>
  <details>
    <summary>operation D (เอานักเรียนคนหน้าสุดออก)</summary>
    <ul>
      <li>ถ้าไม่มีคนอยู่ในแถว ($Q$.empty() == true)
        <ul>
          <li>print “empty”</li>
        </ul>
      </li>
      <li>คนหน้าสุด = $q[Q.front()].front()$
        <ul>
          <li>$Q.front()$ เป็นห้องที่อยู่หน้าสุด และ $q[cl].front()$ เป็นนักเรียนห้อง $cl$ ที่อยู่หน้าสุด</li>
        </ul>
      </li>
      <li>นำคนหน้าสุดออก ($Q.front().pop())</li>
    </ul>
  </details>
  <video src="https://github.com/user-attachments/assets/350f8f56-c0c3-41e0-b06a-df96b309d41b" width="600" autoplay></video>
</details>


[ac code](./toi01_plate.cpp)
