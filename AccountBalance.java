import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class AccountBalance
{
	public int processTransactions(int startingBalance, String[] transactions)
	{
		for(int i = 0 ; i < transactions.length ; i++){
			if(transactions[i].charAt(0)=='D'){
				startingBalance-=Integer.parseInt(transactions[i].substring(2,transactions[i].length()));
			}
			else{
				startingBalance+=Integer.parseInt(transactions[i].substring(2,transactions[i].length()));
			}
		}
		return startingBalance;
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, int p0, String[] p1, boolean hasAnswer, int p2) {
		System.out.print("Test " + testNum + ": [" + p0 + "," + "{");
		for (int i = 0; p1.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print("\"" + p1[i] + "\"");
		}
		System.out.print("}");
		System.out.println("]");
		AccountBalance obj;
		int answer;
		obj = new AccountBalance();
		long startTime = System.currentTimeMillis();
		answer = obj.processTransactions(p0, p1);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			System.out.println("Desired answer:");
			System.out.println("\t" + p2);
		}
		System.out.println("Your answer:");
		System.out.println("\t" + answer);
		if (hasAnswer) {
			res = answer == p2;
		}
		if (!res) {
			System.out.println("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime) / 1000.0 >= 2) {
			System.out.println("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			System.out.println("Match :-)");
		} else {
			System.out.println("OK, but is it right?");
		}
		System.out.println("");
		return res;
	}
	public static void main(String[] args) {
		boolean all_right;
		all_right = true;
		
		int p0;
		String[] p1;
		int p2;
		
		// ----- test 0 -----
		p0 = 100;
		p1 = new String[]{"C 1000","D 500","D 350"};
		p2 = 250;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = 100;
		p1 = new String[]{};
		p2 = 100;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = 100;
		p1 = new String[]{"D 50","D 20","D 40"};
		p2 = -10;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = 53874;
		p1 = new String[]{"D 1234","C 987","D 2345","C 654","D 6789","D 34567"};
		p2 = 10580;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
		
		if (all_right) {
			System.out.println("You're a stud (at least on the example cases)!");
		} else {
			System.out.println("Some of the test cases had errors.");
		}
	}
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!