#include <bits/stdc++.h>
using namespace std;
void next_move(int posr, int posc, vector <string> board) {
    int r1,c1;
    int cost = 11;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(board[i][j] == 'd')
            {
                
                int now_cost = abs(r1-posr)+abs(c1-posc);
                if(now_cost< cost)
                {
                    r1=i;c1=j;
                    cost=now_cost;
                }
            }  
        }    
    } 
    if(posc > c1)
    {
        cout<<"LEFT"<<endl;
    }
    else if(posc <  c1)
    {
        cout<<"RIGHT"<<endl;
    }
    else
    {
        if(posr < r1)
        {
            cout<<"DOWN"<<endl;
        }
        else if(posr > r1)
        {
            cout<<"UP"<<endl;
        }
      else
        {
        cout<<"CLEAN"<<endl;
      }
    }

}
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
