# 최단 경로 문제

## 다익스트라 알고리즘
| **Single Source Shortest Path Problem**  
초기화: dist[i] = INF at all i  
업데이트: dist[i] = min(dist[i], dist[j] + adj[i][j]), with i,j adjecent  
  
- 모든 가중치가 양수일 때만 사용가능  

### 힙 (우선순위 큐)를 사용한 구현
우선순위 큐 + dist배열  
1. 우선순위 큐에 node, INF로 초기화  
2. 우선순위 큐의 top값을 꺼내서, 해당 노드의 cost를 dist값과 비교  
-> cost가 dist보다 작거나 같으면 '연산'  
-> cost가 dist보다 크면 폐기 후 새로운 top  
3. '연산'  
-> 해당 노드(a)와 인접 노드(b),  
dist[b] = min(dist[b], dist[a] + adj[a][b]) //dist[b]와 dist[a]+weight 비교  
-> dist[b]가 업데이트가 되면 (if dist[b] = dist[a] + adj[a][b]), b와 dist[b]를 우선순위 큐에 삽입 (push)  
+어떤 노드에 의해 업데이트되었는지 p배열에 저장하면, 모든 노드에 대한 최소거리를 구할 수 있음 (**all-pairs shortest path problem**)  