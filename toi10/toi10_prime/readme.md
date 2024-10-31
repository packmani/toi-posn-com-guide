## toi10_prime
[problem statement](https://programming.in.th/tasks/toi10_prime)

<details>
  <summary>prerequisites</summary>
  <p>sieve of eratosthenes</p>
</details>

<details>
  <summary>solution</summary>
  <ul>
    <li>โจทย์ต้องการให้เราหาจำนวนเฉพาะลำดับที่ $N$ โดยที่ $N \leq 500000$</li>
    <li>ลองรันโปรแกรมหาค่าจำนวนเฉพาะตัวที่ 500000 จะได้เลข 7368787 ซึ่งน้อยพอที่เราจะไปใส่ในเป็น index ใน array ได้ ดังนั้นเราจึงสามารถหาจำนวนเฉพาะด้วยวิธี sieve of eratosthenes ได้</li>
    <li><ins>หลักการ sieve of Eratosthenes</ins>:
      <ul>
        <li>พหุคูณของจำนวนเฉพาะใดๆจะไม่เป็นจำนวนเฉพาะ จึงกำหนดให้ $s_i$ เก็บค่า $T/F$ ว่า $i$ เป็นจำนวนเฉพาะหรือไม่</li>
        <li>set $s_i = true$; $i$ เป็นเลขคี่ หรือ $i = 2$</li>
        <li>ถ้า $s_i = true$ ($i$ เป็นจำนวนเฉพาะ) เราจะ run loop $j$ โดยเริ่มจาก $i^2$ และเพิ่มทีละ $i$ ($j=j+i$) ไปเรื่อยๆจนหลุดเงื่อนไข $j \leq 7368787$ โดยที่ถ้าเป็นพหุคูณของ $i$ (คือ $j$) เราจะ set $s_j = false$</li>
        <li>เหตุผลที่เราสามารถเริ่ม $j$ ที่ $i^2$ เนื่องจากถ้า $x$ ที่เป็นพหุคูณของ $i$ ตัวที่น้อยกว่า $i^2$ เช่น $i=7, j=21$ เราจะเซตค่า set $s_{21} = false$ ไปก่อนแล้วจาก $i=3, j=21$)</li>
        <li>ในการหาจำนวนเฉพาะที่ $N$ เราก็แค่เก็บ counter ว่าเราเจอ $i$ ที่เป็นจำนวนเฉพาะมากี่ตัวแล้ว</li>
      </ul>
    </li>
  </ul>
  <p align="center"><video src="https://github.com/user-attachments/assets/eb03b238-f1fd-439d-b357-f418fa2ed1f0" width="600" autoplay></video></p>
</details>

[ac code](./toi10_prime.cpp)
