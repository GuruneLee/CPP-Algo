package beak_joon.CodeTest.IUPC.Q1;

import java.util.Scanner;

public class Main {
	static String mm;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		mm = sc.next();
		if (mm.charAt(0) == 'E') {
			System.out.print('I');
		} else {
			System.out.print('E');
		}
		if (mm.charAt(1) == 'S') {
			System.out.print('N');
		} else {
			System.out.print('S');
		}
		if (mm.charAt(2) == 'T') {
			System.out.print('F');
		} else {
			System.out.print('T');
		}
		if (mm.charAt(3) == 'J') {
			System.out.print('P');
		} else {
			System.out.print('J');
		}
		System.out.println();
		sc.close();
	}
}
