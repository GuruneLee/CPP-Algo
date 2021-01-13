package beak_joon.CodeTest.IUPC.Q4;

import java.io.*;
import java.util.*;

public class Main {
	static int[][] H;
	static int[][] Bomb;
	static int N,M;
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		H = new int[N][N];
		Bomb = new int[N][N];
		
		//input
		for (int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j=0; j<N; j++) {
				H[i][j] = Integer.parseInt(st.nextToken());
				Bomb[i][j] = 0;
			}
		}
		
		//´äÃ£±â
		for (int i=0; i<N; i++) {
			//0,0
			//0,N-1
			//N-1,0
			//N-1,N-1
		}
	}
}
