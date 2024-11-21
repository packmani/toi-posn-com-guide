## toi14_technology

[problem statement](https://programming.in.th/tasks/toi14_technology)

<details>
  <summary>hints</summary>
  <ul>
    <details>
      <summary>hint 1</summary>
      <ul>ลองมองเป็น Graph</ul>
    </details>
    <details>
      <summary>hint 2</summary>
      <ul>
        <li>
          <details>
            <summary>Topological sort</summary>
            <ul>
              <li><a href="https://cses.fi/problemset/task/1679" target="_blank">CSES Course Schedule</a></li>
            </ul>
          </details>
        </li>
      </ul>
    </details>
    <details>
      <summary>hint 3</summary>
      <ul><details>
        <summary>Graph จะไม่มี topological order เมื่อใด?</summary>
          <ul>มี Cycle</ul>
      </details></ul>
    </details>
    <details>
    <summary>hint 4</summary>
    <ul>
      <details>
        <summary>จุดยอด $i$ จะใช้ไม่ได้เมื่อ?</summary>
        <ul>จุดยอด $i$ อยู่ใน cycle</ul>
      </details>
    </ul>
    </details>
    <details>
      <summary>hint 5</summary>
      <ul>Strongly Connected Components</ul>
    </details>
  </ul>
</details>

<details>
  <summary>prerequisites</summary>
  <ul>
    <li>Graph Transversal</li>
      <ul><li>BFS</li></ul>
    <li><a href="https://usaco.guide/adv/SCC?lang=cpp" target="_blank">Strongly Connected Components</a></li>
      <ul>
        <li><a href="https://www.youtube.com/watch?v=ZiM2-W1mI-0" target="_blank">Tarjan's</a></li>
        <li><a href="https://cp-algorithms.com/graph/strongly-connected-components.html" target="_blank">Kosaraju's</a></li>
      </ul>
  </ul>
</details>

<details>
  <summary>solution</summary>
  <ul>
    โจทย์ข้อนี้ทำให้นึกถึง <a href="https://cses.fi/problemset/task/1679" target="_blank">CSES Course Schedule</a> คือเรามีงานที่ต้องทำแต่ว่าแต่ละงานจะมีงานที่ต้องทำก่อน<br>
    ในโจทย์ข้อนี้เราสามารถสร้าง Graph มา represent โดยเราจะสร้าง edge $u \rightarrow v$ เมื่อ $v$ เป็นเทคโนโลยีที่ต้องพัฒนาก่อน $u$ 
    <details>
      <summary><code>ex.</code></summary>
      <ul>
        <strong>Sample testcase 1</strong><br>
        6 5 4 <br>
        1 0 <br>
        5 1 1 <br>
        2 1 2 <br>
        4 2 3 5 <br>
        3 1 6 <br>
        2 1 1 <br>
        <br>
        <img src="https://github.com/user-attachments/assets/c7c857a1-6d09-4cd2-85e7-14ad37467094" alt="Graph" width="250" />
      </ul>
    </details>
    โดยเนื่องจากโจทย์ถามว่าสามารถพัฒนาเทคโนโลยีได้ถึงระดับใด ($M$), ต้องพัฒนาทุกเทคโลโยลีทั้งหมดที่มีมีระดับ $\leq M$ แต่มีเงื่อนไขว่าเราพัฒนาเทคโนโลยีได้ $\leq T$ เทคโนโลยี หลังจากทีเราสร้าง Graph แล้ว
    เราจะทำการ Transverse โดยมีจุดเริ่มเป็นจุดยอดที่มีระดับเทคโนโลยีเรียงจากมากไปน้อย ในแต่ละรอบเราจะ Transverse จนกว่าจะ Transverse ต่อไม่ได้เพื่อการันตีว่าเราได้ทำงานที่ต้องทำก่อนหมดแล้ว แล้วเราจะเก็บด้วยว่า
    เราเจอจุดยอดไปทั้งหมดกี่จุดยอดแล้ว เราจะจบเมื่อจำนวนจุดยอด $>t$ <br><hr>
    แต่ว่าจุดยอดบางจุดยอดอาจจะไม่สามารถใช้ได้ (ไม่สามารถพัฒนาเทคโนโลยีได้) เนื่องจากลำดับการสร้างเกิด cycle ขึ้นเช่น <code>1->2->3->1</code> คือเราต้องใช้ <code>3</code> ในการพัฒนา <code>1</code> และใช้ <code>1</code> ในการพัฒนา <code>3</code> ซึ่งทำไม่ได้
    ทำให้เวลาเรา Tranverse เราจะ check เพิ่มว่าเป็นจุดยอดที่ใช้ได้ไหม คือไม่ได้อยู่ใน cycle ใดๆเลย ซึ่งก็คือการ check ว่า strongly connected component ที่อยู่นั้นมีขนาด = 1 หรือไม่? 
    <details>
      <summary><code>picture</code></summary>
      <ul>
        <img src="https://github.com/user-attachments/assets/16e95b5f-b216-44c4-9528-cfa6b6acde51" alt="Graph" width="333" />
      </ul>
    </details>
  <details>
  <summary>code Tarjan</summary>
  <ul>
    
  ```cpp 
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define N 100000
#define K 10000
std::vector<int> g[N];
std::set<int> V[K];
std::queue<int> q;
int l[N], stk[N], tin[N], low[N], vis[N], SZ[N], C[N], c, sz, ti = 1, ok = 1;
void dfs(int u){ //Tarjan
    vis[stk[sz++] = u] = 1; tin[u] = low[u] = ti++;
    for(int v: g[u]){
        if(!tin[v]){
        	dfs(v);
        	if(low[v] < low[u]) low[u] = low[v];
        }else if(vis[v] && tin[v] < low[u]) low[u] = tin[v]; 
    }
    if(low[u] == tin[u]){
        do{
            vis[stk[sz-1]] = 0; ++SZ[C[stk[--sz]] = c];
        }while(stk[sz] != u);
        ++c;
    }
}
signed main(){
	int n, k, t, Ans = -1; scanf("%d %d %d", &n, &k, &t);
	for(int i = 0, x; i<n; ++i){
		scanf("%d %d", l+i, &sz); V[--l[i]].insert(i);
		while(sz--) scanf("%d", &x), g[i].push_back(--x);
	}
	for(int i = sz = 0; i<n; ++i) if(!tin[i]) dfs(i);
	for(int i = 0; i<n; vis[i++] = 0);
	for(int i = 0, cnt = 0; i<k; Ans = ++i){
		for(int u: V[i]){
			if(SZ[C[u]] > 1 || (cnt += (vis[u] = 1)) > t){ ok = 0; break;} 
			q.push(u);
		}
		while(ok && !q.empty()){
			int u = q.front(); q.pop();
			for(int v: g[u]){
				if(!vis[v]){
					if(SZ[C[v]] > 1 || (cnt += (vis[v] = 1)) > t){ ok = 0; break;} 
					q.push(v); V[l[v]].erase(v);
				}
			}
		}
		if(!ok) break;
	}
	printf("%d", Ans);
}
  ```
  </details>
  <details>
  <summary>code Kosaraju</summary>
  <ul>
    
  ```cpp 
TGAT TPAT OH NO
  ```
  </ul>
  </ul>
  </details>
  </ul> 
</details>
