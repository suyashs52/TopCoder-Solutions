import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class CrossWordPuzzle
{
	public int countWords(String[] board, int size)
	{
		int count=0;
		for(int i = 0 ; i < board.length ; i++){
			for(int j = 0 ; j < board[i].length() ; j++){
				if(board[i].charAt(j)=='.' && board[i].length()-j >=size){
					int cur=0;
					for(;j<board[i].length() ; j++){
						if(board[i].charAt(j)=='.')
							cur++;
						else
							break;
					}
					if(cur==size)
						count++;
				}
			}
		}
		return count;
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, String[] p0, int p1, boolean hasAnswer, int p2) {
		System.out.print("Test " + testNum + ": [" + "{");
		for (int i = 0; p0.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print("\"" + p0[i] + "\"");
		}
		System.out.print("}" + "," + p1);
		System.out.println("]");
		CrossWordPuzzle obj;
		int answer;
		obj = new CrossWordPuzzle();
		long startTime = System.currentTimeMillis();
		answer = obj.countWords(p0, p1);
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
		
		String[] p0;
		int p1;
		int p2;
		
		// ----- test 0 -----
		p0 = new String[]{"X....X","X.XX.X","...X..","X.XX.X","..X..."};
		p1 = 3;
		p2 = 2;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = new String[]{"...X...",".X...X.","..X.X..","X..X..X","..X.X..",".X...X.","...X..."};
		p1 = 3;
		p2 = 6;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = new String[]{".....X....X....",".....X....X....","..........X....","....X....X.....","...X....X....XX","XXX...X....X...",".....X....X....",".......X.......","....X....X.....","...X....X...XXX","XX....X....X...",".....X....X....","....X..........","....X....X.....","....X....X....."};
		p1 = 5;
		p2 = 8;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = new String[]{"...","...","..."};
		p1 = 50;
		p2 = 0;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 4 -----
		p0 = new String[]{"....","....","...."};
		p1 = 3;
		p2 = 0;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
