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
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ORSolitaireDiv2 {
public:
	int getMinimum(vector <int> numbers, int goal) {
		for(int i = 0 ; i<numbers.size() ; i++){
			if(numbers[i]>goal)
			numbers.erase(numbers.begin()+i);
		}
		int n = numbers.size();
		int max = (1<<numbers.size())-1;
		vector< vector<int> > vec;
		for(int i = 1 ; i<=max ; i++){
			long long int temp = 0;
			for(int j = 0 ; j<n ; j++){
				if((i & (1<<j))!=0){
					temp|=numbers[n-j-1];
				}
			}
			if(temp==(long long int)goal){
				vector<int> xd;
				for(int j = 0 ; j<n ; j++){
					if((i & (1<<j))!=0){
					xd.push_back(numbers[n-j-1]);
					}
				}
				vec.push_back(xd);				
			}
		}
		if(vec.size()==0)
		return 0;
		else if(vec.size()==1)
		return 1;
		int ans = vec.size();
		for(int i =1 ; i<=max ; i++){
			int temp = __builtin_popcount(i);
			bool used[vec.size()];
			memset(used,false,sizeof(used));
			for(int j = 0 ; j< n ; j++){
				if((i & (1<<j))!=0){
					for(int k = 0 ; k< vec.size() ; k++){
						if(!used[k]){
							for(int l = 0 ; l<vec[k].size() ; l++){
								if(vec[k][l]==numbers[n-j-1]){
									used[k]=true;
									break;
								}
							}
						}
					}
				}
			}
			int p;
			for(p=0 ; p<vec.size() ; p++){
				if(!used[p])
				break;
			}
			if(p==vec.size()){
				ans=min(ans,temp);
			}
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	ORSolitaireDiv2 *obj;
	int answer;
	obj = new ORSolitaireDiv2();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <int> p0;
	int p1;
	int p2;


	
		{
	// ----- test 4 -----
	int t0[] = {503,505,152,435,491,512,1023,355,510,500,502,255,63,508,509,511,60,250,254,346};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 510;
	p2 = 5;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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