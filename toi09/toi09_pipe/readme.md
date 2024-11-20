## toi09_pipe
[problem statement](https://programming.in.th/tasks/toi9_pipe)
<details>
    <summary>prerequisites</summary>
    <ul>
        <li>Graph transversal</li>
            <ul>
            <li>Dfs (recursion)</li>
            </ul>
    </ul>
</details>

<details>
    <summary>solution</summary>
        <p>เราสามารถแก้โจทย์ข้อนี้โดยการทำตรงๆได้เลยเพื่อความง่ายในการเขียนเราสามารถใช้ DFS โดยการเขียน recursive function</p>
        <p><strong>-Implementation-</strong></p>
        <p><code>int pipe(int x, int y, int k)</code> เป็น function (recursive) ที่จะ return ค่าความยาวท่อตั้งแต่จุดจบต่อจนถึง $(x, y)$ โดยที่เพื่อความง่ายเราจะ pass $k$ ไปใน function ด้วยโดย $k$ คือทิศทางที่เราหันไปอยู่ (ทำการขยับต่อทางไหน)</p>
        <li>$(k = 1) \equiv  \text{right}$</li>
        <li>$(k = 2) \equiv \text{down}$</li>
        <li>$(k = 3) \equiv \text{left}$</li>
        <li>$(k = 4) \equiv \text{up}$</li>
        <p>โดยที่ในแต่ละช่องจะมีท่อแต่ละแบบที่ทำให้เราต้องเปลี่ยนทิศ</p>
        <hr>
        <li><code>11</code></li>
        <ul><br> 
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/42d94e34-5b1d-4dff-a0fa-a72d019d8cc3" /></p>
            <li>$k = 1$ (right)</li>
                <ul><li>$k^{\prime} = 4$  (up)</li></ul>
            <li>$k = 2$ (down)</li>
                <ul><li>$k^{\prime}  = 3$ (left)</li></ul>
        </ul><hr>
        <li><code>12</code></li> 
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/0543cbda-9f96-4939-9e77-2a26b523d5c7" /></p>
            <li>$k = 3$ (left)</li> 
                <ul><li>$k^{\prime} = 4$ (up)</li></ul>
            <li>$k = 2$ (down)</li>
                <ul><li>$k^{\prime} = 1$  (right)</li></ul>
        </ul><hr>
        <li><code>13</code></li>
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/f7ef4e0e-0d97-43ec-a5a1-c2493a3c09df" /></p>
            <li>$k = 1$ (right)</li>
                <ul><li>$k^\prime = 2$ (down)</li></ul>
            <li>$k = 4$ (up)</li>
                <ul><li>$k^\prime = 3$ (left)</li></ul>
        </ul><hr>
        <li><code>14</code></li>
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/798e0aa8-4040-40db-8a2e-a01b064b59be" /></p>
            <li>$k = 3$ (left)</li>
                <ul><li>$k^\prime = 2$ (down)</li></ul>
            <li>$k = 5$ (up)</li>
                <ul><li>$k^\prime = 1$ (right)</li></ul>
        </ul><hr>
        <li><code>21</code></li>
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/07e42294-1e20-4d2a-8b03-ceaa21d08143" /></p>
            <li>$k = k^\prime = 4$ (up)</li>
            <li>$k = k^\prime = 2$ (down)</li>
        </ul><hr>
        <li><code>22</code></li> 
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/d1443b0e-bff6-4f29-bbd4-a4225f0c56e1" /></p>
            <li>$k= k^\prime = 3$ (left)</li>
            <li>$k = k^\prime = 1$ (right)</li>
        </ul><hr>
        <li><code>31</code></li>
        <ul><br>
            <p align="left"><img width="70" src="https://github.com/user-attachments/assets/ae459e8c-ee94-409f-bac9-fa9abb263718" /></p>
            <li>31 เหมือน 21 กับ 22</li>
            <li>เราจะใช้เป็น 21 หรือ 22 ขึ้นอยู่กับกับทิศทางที่เราไป  $(k)$</li>
                <ul>
                <li>ไปทางแนวนอน $(k = 1 \lor k = 3)$</li>
                    <ul>
                    <li>ใช้ 21</li>
                    <li>set ช่องเป็น 22 (สำหรับอีกครั้งในอนาคตที่เป็นแนวนอน)</li>
                    </ul>
                <li>ไปทางแนวตั้ง $(k = 2 \lor k = 4)$</li>
                    <ul>
                    <li>ใช้ 22</li>
                    <li>set ช่องเป็น 21 (สำหรับอีกครั้งในอนาคตที่เป็นแนวตั้ง)</li>
                    </ul>
                </ul>
        </ul><hr>
        <p>$TC \leq O(mn \cdot max(m,n))$</p>
          <details>
  <summary>code</summary>
  <ul>
    
  ```cpp
//credit : Blackslex
//toi9_pipe
//brute force dfs
#include<bits/stdc++.h>

using namespace std;

int n, m, a[305][305];
vector<int> v;
// 1 -> right (R)
// 2 -> down (D)
// 3 -> left (L)
// 4 -> up (U)
int pipe (int x, int y, int k) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    int o;
    if (a[x][y] == 31) { // 31 = 21 + 22
        if (k == 1 || k == 3) o = 22, a[x][y] = 21; //horizontal 
        else o = 21, a[x][y] = 22; //vertical  (a[x][y] to another one for future dfs)
    } else o = a[x][y], a[x][y] = 0;
    if (o == 11) { 
        if (k == 1) return pipe(x - 1, y, 4) + 1; //R -> U
        else if (k == 2) return pipe(x, y - 1, 3) + 1; //D -> L
    } else if (o == 12) {
        if (k == 3) return pipe(x - 1, y, 4) + 1; //L -> U
        else if (k == 2) return pipe(x, y + 1, 1) + 1; //D -> R
    } else if (o == 13) {
        if (k == 1) return pipe(x + 1, y, 2) + 1; //R -> D
        else if (k == 4) return pipe(x, y - 1, 3) + 1; //U -> L
    } else if (o == 14) {
        if (k == 3) return pipe(x + 1, y, 2) + 1; //L -> D
        else if (k == 4) return pipe(x, y + 1, 1) + 1; //U - > R
    } else if (o == 21) {
        if (k == 4) return pipe(x - 1, y, 4) + 1; //U -> U
        else if (k == 2) return pipe(x + 1, y, 2) + 1; //D -> D
    } else if (o == 22) {
        if (k == 3) return pipe(x, y - 1, 3) + 1; //L -> L
        else if (k == 1) return pipe(x, y + 1, 1) + 1; //R -> R
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) { //down
        if (a[0][i] == 11 || a[0][i] == 12 || a[0][i] == 21 || a[0][i] == 31) v.emplace_back(pipe(0, i, 2));
    }
    for (int i = 0; i < m; i++) { //up
        if (a[n - 1][i] == 13 || a[n - 1][i] == 14 || a[n - 1][i] == 21 || a[n - 1][i] == 31) v.emplace_back(pipe(n - 1, i, 4));
    }
    for (int i = 0; i < n; i++) { //right
        if (a[i][0] == 11 || a[i][0] == 13 || a[i][0] == 22 || a[i][0] == 31) v.emplace_back(pipe(i, 0, 1));
    }
    for (int i = 0; i < n; i++) { //left
        if (a[i][m - 1] == 12 || a[i][m - 1] == 14 || a[i][m - 1] == 22 || a[i][m - 1] == 31) v.emplace_back(pipe(i, m - 1, 3));
    }
    printf("%d\n", v.size());
    for (auto e: v) printf("%d ", e);
}
  ```
  </ul>
  </details>
</details>
