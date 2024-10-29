## toi1_roman
[problem statement](https://programming.in.th/tasks/toi1_roman)

<details>
  <summary>prerequisites</summary>
  <p><ins>brute force  / simulation</ins></p>
</details>

<details>
  <summary>solution</summary>
  <li> เนื่องจากจำนวนหน้า $d \leq 400$ ทำให้เราสามารถทำการคำนวนตรงๆได้เลย ซึ่งอาจทำได้หลายวิธี </li>
  <li> หนึ่งในวิธีคือการเก็บจำนวนเลขโรมันที่ใช้สำหรับเลขแต่ละหลัก เช่น เก็บเป็น tuple 5 ตัวเลข {i,v,x,l,c} แทนจำนวนเลขโรมันที่ใช้ <br>เช่น vii จะมี tuple เป็น {2,1,0,0,0} </li>
  <li> ทำอย่างนี้สำหรับเลขแต่ละหลัก โดยมี array of tuples แทนเลขโรมันเป็น {-,i,ii,iii,iv,v,vi,vii,viii,ix}, {-,x,xx,xxx,xl,l,lx,lxx,lxxx,xc}, และ {-,c,cc,ccc} ตามลำดับ</li>
  <li> จากนั้นทำการ loop ตั้งแต่เลข 1 ถึง d เพื่อคำนวนจำนวนเลขโรมันที่ใช้ประกอบกับการ mod เพื่อเอาค่าของแต่ละหลัก และหาผลรวมของเลขโรมันแต่ละเลข</li>
</details>

[ac code](./toi01_roman.cpp)
