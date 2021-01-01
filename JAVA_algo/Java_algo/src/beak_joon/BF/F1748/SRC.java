package beak_joon.BF.F1748;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SRC {
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String num = br.readLine();
		int len = num.length();
		
		int N = Integer.parseInt(num);
		
		int tmp = 9;
		int result = 0;
		for (int i=1; i<len; i++) {
			result += i*tmp;
			tmp *= 10;
		}
		
		int last = (int)( N - Math.pow(10, len-1)+1) * len;
		result += last;
		System.out.println(result);
	}
}
