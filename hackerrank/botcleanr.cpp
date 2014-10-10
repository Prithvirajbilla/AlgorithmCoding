#include<iostream>
#include<vector>
using namespace std;
void nextMove(int posr, int posc, vector <string> board) {
    int r1,c1;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if(board[i][j] == 'd')
            {
                r1=i;c1=j;
                break;
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
    nextMove(pos[0], pos[1], board);
    return 0;
}
