package beak_joon.BF.F14889;

import java.io.*;
import java.util.StringTokenizer;
public class Main {
	static boolean next_permutation(int[] list) { //java에서 primitive variable이 아니면 싹다 reference variable.
		   //primitive variable: boolean , byte , char , short , int , long , float, double 
		int i = list.length-1;
		int j = list.length-1;
		
		while (i>0 && list[i-1]>=list[i])	i-=1;
		if (i == 0)	return false;
		
		while (list[i-1]>=list[j])	j-=1;
		
		int tmp = list[i-1];
		list[i-1] = list[j];
		list[j] = tmp;
		
		j = list.length-1;
		while(i<j) {
			tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i+=1;
			j-=1;
		}
		
		return true;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		//input
		int N = Integer.parseInt(br.readLine());
		int[][] S = new int[21][21];
		int[] list = new int[N];
		
		//static 때고 선언하면, 이렇게 인스턴스를 만들어서 사용해야함
		//Main m = new Main();
		//m.next_permutation(list);
		
		for (int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<N&&st.hasMoreTokens(); j++) {
				S[i][j] = Integer.parseInt(st.nextToken());
			}
			if (i < N/2)	list[i] = 0;
			else	list[i] = 1;
		}
		
		int min = Integer.MAX_VALUE;
		do {
			int sum1 = 0;
			int sum2 = 0;
			for (int i=0; i<N; i++) {
				for (int j=0; j<N; j++) {
					if (list[i] == list[j]) {
						if (list[i] == 1) {
							sum1 += S[i][j];
						} else {
							sum2 += S[i][j];
						}
					}
				}
			}
			int tmp = Math.abs(sum1-sum2);
			min = min>tmp?tmp:min;
			
		} while(next_permutation(list));
		
		bw.write(Integer.toString(min));
		bw.flush();
		br.close();
		bw.close();
		
	}
}