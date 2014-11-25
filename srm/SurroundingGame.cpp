#include <bits/stdc++.h>
using namespace std;	
class SurroundingGame
{ 
	public: 
	int maxScore(vector <string> cost, vector <string> benefit) 
	{ 

	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"21","12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"21","12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ZZ","ZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11","11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"XXX","XXX","XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaa","aZa","aaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"asam","atik"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"123A","45BC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71; verify_case(3, Arg2, maxScore(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"IIIIIIII",
 "IIWWWWII",
 "IIWIIIII",
 "IIWIIIII",
 "IIWWWWII",
 "IIIIIWII",
 "IIIIIWII",
 "IIWWWWII",
 "IIIIIIII"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"IIIIIIII",
 "II0000II",
 "II0II0II",
 "II0II0II",
 "II0000II",
 "II0II0II",
 "II0II0II",
 "II0000II",
 "IIIIIIII"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 606; verify_case(4, Arg2, maxScore(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	SurroundingGame ___test; 
	___test.run_test(-1); 
}
// END CUT HERE 
