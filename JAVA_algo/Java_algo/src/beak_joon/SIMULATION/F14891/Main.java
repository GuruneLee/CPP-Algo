package beak_joon.SIMULATION.F14891;

import java.io.*;
import java.util.*;

public class Main {
	static String[] g = new String[4];
	static int[] t = new int[]{0,0,0,0};
	
	static int K;
	
	static char N = '0';
	static int cw = 1;
	static int cc = -1;
	
	static void rotate(int sg, int sd) {
		//각자 돌아갈지 안돌아갈지 결정 (-1/0)
		int[] isR = new int[] {0,0,0};
		isR[0] = !(g[0].charAt((t[0]+2)%8) == g[1].charAt((t[1]+6)%8))?-1:0;
		isR[1] = !(g[1].charAt((t[1]+2)%8) == g[2].charAt((t[2]+6)%8))?-1:0;
		isR[2] = !(g[2].charAt((t[2]+2)%8) == g[3].charAt((t[3]+6)%8))?-1:0;
		
		//sg번째 기어가 sd방향으로 돌아갈때, 각자 어느방향으로 도는지 결정
		int[] RD = new int[] {0,0,0,0}; //-1,0,1 - 시계,안돌고,반시계
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
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		g[0] = br.readLine();
		g[1] = br.readLine();
		g[2] = br.readLine();
		g[3] = br.readLine();
		K = Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		for (int i=0; i<K; i++) {
			st = new StringTokenizer(br.readLine());
			int simul_g = Integer.parseInt(st.nextToken()) - 1;
			int simul_dir = Integer.parseInt(st.nextToken());
			rotate(simul_g, simul_dir);
		}
		int sum = 0;
		sum += g[0].charAt(t[0])==N ? 0:1;
		sum += g[1].charAt(t[1])==N ? 0:2;
		sum += g[2].charAt(t[2])==N ? 0:4;
		sum += g[3].charAt(t[3])==N ? 0:8;
		System.out.println(sum);
	}
}
