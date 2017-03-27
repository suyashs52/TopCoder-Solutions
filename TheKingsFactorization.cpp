#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class TheKingsFactorization {
public:
	vector <long long> getVector(long long N, vector <long long> primes) {
		vector<bool> prime_test(1000001,false);
		vector<long long> prime_numbers;
		for(int i = 2 ; i<=1000000 ; i++){
			if(prime_test[i]==false){
				prime_numbers.push_back(i);
				for(int j = i*2 ; j<=1000000 ; j+=i)
				prime_test[j]=true;
			}
		}
		
		for(int i = 0 ; i<primes.size() ; i++){
			if(primes[i]>1000000)
			prime_numbers.push_back(primes[i]);
		}
		
		vector<long long> xd;
		for(int i = 0 ; i < prime_numbers.size() ; i++){
			while(N%prime_numbers[i]==0){
				xd.push_back(prime_numbers[i]);
				N=N/prime_numbers[i];
			}
		}
		if(N>100)
		xd.push_back(N);
		sort(xd.begin(),xd.end())
		return xd;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, vector <long long> p1, bool hasAnswer, vector <long long> p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheKingsFactorization *obj;
	vector <long long> answer;
	obj = new TheKingsFactorization();
	clock_t startTime = clock();
	answer = obj->getVector(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	long long p0;
	vector <long long> p1;
	vector <long long> p2;
	
	{
	// ----- test 0 -----
	p0 = 12ll;
	long long t1[] = {2ll,3ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,2ll,3ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 7ll;
	long long t1[] = {7ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {7ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1764ll;
	long long t1[] = {2ll,3ll,7ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,2ll,3ll,3ll,7ll,7ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 49ll;
	long long t1[] = {7ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {7ll,7ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 210ll;
	long long t1[] = {2ll,5ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,3ll,5ll,7ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 100000ll;
	long long t1[] = {2ll,2ll,2ll,5ll,5ll};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	long long t2[] = {2ll,2ll,2ll,2ll,2ll,5ll,5ll,5ll,5ll,5ll};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
