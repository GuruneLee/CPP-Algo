#include <bits/stdc++.h>
using namespace std;

// 야매
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX]; // 0으로 초기화
int unused = 1;

void insert(int addr, int num) {	//addr index다음에 num을 넣기
	dat[unused] = num;		//새로운 원소 생성
	pre[unused] = addr;		//새로운 원소의 이전은 addr
	nxt[unused] = nxt[addr];//새로운 원소의 다음은 addr의 다음꺼
	if(nxt[addr]!=-1) pre[nxt[addr]] = unused;//삽입할 위치의 nxt값과 다음원소의 pre값을 새원소로 변경  **if처리하기.
	nxt[addr] = unused;		
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if(nxt[addr]!=-1) pre[nxt[addr]] = pre[addr];
	pre[addr] = -1;
	nxt[addr] = -1;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre + MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}
