package beak_joon.BF.F1806;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static long S;
	static long[] arr;
	static int len = Integer.MAX_VALUE;
	
	//이 코드는 시간초과가 납니다...!
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		S = Long.parseLong(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		arr = new long[N+1];
		arr[0] = 0;
		for (int i=1; i<=N; i++) {
			arr[i] = Long.parseLong(st.nextToken());
			arr[i] += arr[i-1];
		}
		
		for (int i=1; i<=N; i++) {
			for (int j=0; j<i; j++) {
				if (arr[i]-arr[j] < S) {
					break;
				}
				len = len>i-j?i-j:len;
			}
		}

		System.out.println(len);
	}
	
}
