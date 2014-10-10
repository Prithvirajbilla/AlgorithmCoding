#include <bits/stdc++.h>
using namespace std;
void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
    int r1,c1;
    int cost = dimw+dimh;
    for (int i = 0; i < dimw; i++)
    {
        for (int j = 0; j < dimh; j++)
        {
            if(board[i][j] == 'd')
            {
                
                int now_cost = abs(i-posr)+abs(j-posc);
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
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
