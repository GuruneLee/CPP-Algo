package beak_joon.BF.F9095;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
//import java.util.*;

public class SRC {

	//List<Integer> l = new Vector<Integer>();
	//※제네릭스는 선언할 수 있는 타입이 객체 타입입니다. int는 기본자료형이기 때문에 들어갈 수 없으므로 int를 객체화시킨 wrapper클래스를 사용해야 합니다.
		
	public static void main(String[] args) throws IOException {
		//InputStreamReader sr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n;
		int T;
		int[] d = new int[11]; //자료형[] 변수 = new 자료형[배열크기];
		//T = sr.read();
		T = Integer.parseInt(br.readLine());
		for (int t=0; t<T; t++) {
			//n = sr.read();
			n = Integer.parseInt(br.readLine());
			d[0] = 1;
			d[1] = 1;
			d[2] = 2;
			for (int i=3; i<=n; i++) {
				//d[i]를 채울거에여
				d[i] = d[i-1] + d[i-2] + d[i-3];
			}
			//System.out.println(d[n]);
			bw.write(String.valueOf(d[n]));
			bw.write('\n');
			bw.flush();
		}
	}
}
