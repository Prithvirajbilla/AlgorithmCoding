// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroCoins.cpp"
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class TaroCoins
        { 
        public: 
        long long getNumber(long long N) 
            { 
            $CARETPOSITION$ 
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 3LL; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { long long Arg0 = 47LL; long long Arg1 = 2LL; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { long long Arg0 = 256LL; long long Arg1 = 9LL; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { long long Arg0 = 8489289LL; long long Arg1 = 6853LL; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000LL; long long Arg1 = 73411LL; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        TaroCoins ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
