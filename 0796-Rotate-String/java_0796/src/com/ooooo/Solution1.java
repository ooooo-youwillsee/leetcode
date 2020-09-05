package com.ooooo;

class Solution1 {
	
	public boolean rotateString(String A, String B) {
		return A.length() == B.length() && (A + A).contains(B);
	}
	
	
	private static void test(String A, String B) {
		Solution1 solution = new Solution1();
		boolean b = solution.rotateString(A, B);
		System.out.println(b);
	}
	
	public static void main(String[] args) {
		test("aa", "a"); // false
		test("abcde", "cdeab"); // true
		test("abcde", "abced"); // false
		
	}
}