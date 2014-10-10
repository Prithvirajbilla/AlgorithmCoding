#line 5 "TaroGrid.cpp"
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class TaroGrid
        { 
        public: 
        int getNumber(vector <string> grid) 
        { 
            int max = 0;
            for (int i = 0; i < grid[0].length(); ++i)
            {
                int present = 1;
                for (int j = 0; j < grid.size()-1; ++j)
                {
                    if(grid[j][i] == grid[j+1][i])
                    {
                        present++;
                    }
                    else
                    {
                        if(present > max)
                        {
                            max = present;

                        }
                        present = 1;

                    }
                }
                if(present > max)
                {
                    max = present;
                    present = 1;
                }
            }
            return max;
        } 
        
 
        }; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
