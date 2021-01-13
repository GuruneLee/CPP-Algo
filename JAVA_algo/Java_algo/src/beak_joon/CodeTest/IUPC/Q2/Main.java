package beak_joon.CodeTest.IUPC.Q2;

import java.io.*;
import java.util.*;

//시간초과
public class Main {
	static int N,M;
	static int[] A;
	static int[] key;
	static StringTokenizer st;
	static HashMap<Integer, Integer> m = new HashMap<>();
	
/*
	static int Search( int arr[], int iKey ) {
		int fi = -1; //first index
		
		int mid;
        int left = 0;
        int right = arr.length - 1;
 
        while (right >= left) {
            mid = (right + left) / 2;
 
            if (iKey == arr[mid]) {
                fi = mid;
                while (fi>=0 && arr[fi] == iKey) {
                	fi --;
                }
                fi ++;
                break;
            }
 
            if (iKey < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
 
        }

		return fi;
	}
*/
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = new int[N];

		for (int i=0; i<N; i++) {
			A[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(A);
		
		for (int i=0; i<N; i++) {
			if (!m.containsKey(A[i])) {
				m.put(A[i],i);
			}
		}
		
		for (int i=0; i<M; i++) {
			int wanna = Integer.parseInt(br.readLine());
			int ans = -1;
			if (m.containsKey(wanna)) {
				ans = m.get(wanna);
			}
			System.out.println(ans);
			//System.out.println( Search(A, wanna) );
		}
		
	}
}
