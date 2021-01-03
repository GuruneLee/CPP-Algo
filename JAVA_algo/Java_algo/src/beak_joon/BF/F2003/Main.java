package beak_joon.BF.F2003;

//import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static long M;
	static long[] A;
	public static void main(String[] args) throws IOException, NumberFormatException {
		//Scanner sc = new Scanner(System.in);
		//N = sc.nextInt();
		//M = sc.nextLong();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Long.parseLong(st.nextToken());
		
		A = new long[N+1];
		st = new StringTokenizer(br.readLine());
		A[0] = 0;
		
		int cnt = 0;
		for (int i=1; i<=N; i++) {
			A[i] = Long.parseLong(st.nextToken());
			A[i] += A[i-1];
			for (int j=0; j<=i; j++) {
				if (A[i] - A[j] == M)	cnt++;
			}
		}
		
		System.out.println(cnt);	
	}
}
