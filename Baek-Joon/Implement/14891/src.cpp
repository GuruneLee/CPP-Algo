#include <string>
#include <iostream>
#include <vector>

using namespace std;
vector<string> g(4); //gear
vector<int> t(4); //top
int K;

char N = '0';
int cw = 1;
int cc = -1;

void rotate(int sg, int sd) {
    //각자 돌아갈지 안돌아갈지 결정 (-1 / 0)
    vector<int> isR(3,0);
    isR[0] = !(g[0][(t[0]+2)%8] == g[1][(t[1]+6)%8])?-1:0;
    isR[1] = !(g[1][(t[1]+2)%8] == g[2][(t[2]+6)%8])?-1:0;
    isR[2] = !(g[2][(t[2]+2)%8] == g[3][(t[3]+6)%8])?-1:0;

    //sg번째 기어가 sd방향으로 돌아갈 때, 각자 어느 방향으로 도는지 결정
    vector<int> RD(4,0); //-1,0,1 시계,안돌고,반시계
    if (sg == 0) {
        RD[0] = sd;
        RD[1] = sd*isR[0];
        RD[2] = sd*isR[0]*isR[1];
        RD[3] = sd*isR[0]*isR[1]*isR[2];
    } else if (sg == 1) {
        RD[1] = sd;
        RD[0] = sd*isR[0];
        RD[2] = sd*isR[1];
        RD[3] = sd*isR[1]*isR[2];
    } else if (sg == 2) {
        RD[2] = sd;
        RD[3] = sd*isR[2];
        RD[1] = sd*isR[1];
        RD[0] = sd*isR[0]*isR[1];
    } else if (sg == 3) {
        RD[3] = sd;
        RD[2] = sd*isR[2];
        RD[1] = sd*isR[2]*isR[1];
        RD[0] = sd*isR[2]*isR[1]*isR[0];
    }
		
		//각자 top계산
		t[0] = (t[0]+8-RD[0])%8;
		t[1] = (t[1]+8-RD[1])%8;
		t[2] = (t[2]+8-RD[2])%8;
		t[3] = (t[3]+8-RD[3])%8;

}

int main() {
    for (int i=0; i<4; i++) {
        cin >> g[i];
    }
    cin >> K;
    while (K--) {
        int simul_g, simul_dir;
        cin >> simul_g >> simul_dir;
        rotate(simul_g-1, simul_dir);
    }

    int sum = 0;
    sum += g[0][t[0]]==N ? 0:1;
    sum += g[1][t[1]]==N ? 0:2;
    sum += g[2][t[2]]==N ? 0:4;
    sum += g[3][t[3]]==N ? 0:8;

    cout << sum;
    return 0;
}