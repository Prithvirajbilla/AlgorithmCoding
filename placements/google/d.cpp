#include <bits/stdc++.h>
using namespace std;
int cas = 1;
char board[8][8] = {'.'};
int kills_bishop(int i,int j)
{
	int res = 0;
		for(int a=i+1,b=j+1;a < 8 && b< 8;a++,b++)
		{
			if(board[a][b] != '.')
			{
				res++;
				break;
			}
		}
		for(int a=i-1,b=j-1;a >= 0 && b>= 0;a--,b--)
		{
			if(board[a][b] != '.')
			{
				res++;
				break;
			}
		}
		for(int a=i+1,b=j-1;a <8 && b>=0;a++,b--)
		{
			if(board[a][b] != '.')
			{
				res++;
				break;
			}
		}
		for(int a=i-1,b=j+1;a >=0 && b<8;a--,b++)
		{
			if(board[a][b] != '.')
			{
				res++;
				break;
			}
		}
		return res;
}
int kills_rook(int i,int j)
{
	int res=0;
	for(int a=i+1;a< 8;a++)
	{
		if(board[a][j] != '.')
		{
			res++;
			break;
		}
	}
	for(int a=j+1;a< 8;a++)
	{
		if(board[i][a] != '.')
		{
			res++;
			break;
		}
	}
	for(int a=i-1;a>=0;a--)
	{
		if(board[a][j] != '.')
		{
			res++;
			break;
		}
	}
	for(int a=j-1;a>= 0;a--)
	{
		if(board[i][a] != '.')
		{
			res++;
			break;
		}
	}
	return res;
}
int kills(int i,int j)
{
	int res = 0;
	if(board[i][j] == 'K')
	{
		if(j+1 < 8 && board[i][j+1] != '.')
			res++;
		if(i+1 < 8 && board[i+1][j] != '.')
			res++;
		if(i-1 >= 0 && board[i-1][j] != '.')
			res++;
		if(j-1>= 0 && board[i][j-1] != '.')
			res++;
		if(j+1 < 8 && i+1 < 8 && board[i+1][j+1] != '.')
			res++;
		if(j-1>=0 && i-1>= 0 && board[i-1][j-1] != '.')
			res++;
		if(j+1 <8 && i-1>=0 && board[i-1][j+1] != '.')
			res++;
		if(j-1>=0 && i+1<8 && board[i+1][j-1] != '.')
			res++;
		return res;
	}
	else if(board[i][j] == 'Q')
	{
		res+= kills_bishop(i,j)+kills_rook(i,j);
		return res;
	}
	else if(board[i][j] == 'R')
	{
		return kills_rook(i,j);
	}
	else if(board[i][j] == 'B')
	{
		return kills_bishop(i,j);
	}
	else if(board[i][j] == 'N')
	{
		if(i+2 < 8 && j+1 < 8 && board[i+2][j+1] != '.')
			res++;
		if(i+2 < 8 && j-1 >= 0 && board[i+2][j-1] != '.')
			res++;
		if(i-2 >= 0 && j+1 < 8 && board[i-2][j+1] != '.')
			res++;
		if(i-2 >= 0 && j-1 >= 0 && board[i-2][j-1] != '.')
			res++;
	
		if(j+2 < 8 && i+1 < 8 && board[i+1][j+2] != '.')
			res++;

		if(j+2 < 8 && i-1 >= 0 && board[i-1][j+2] != '.')
			res++;
		if(j-2 >=0 && i+1 < 8 && board[i+1][j-2] != '.')
			res++;
		if(j-2 >= 0 && i-1 >= 0 && board[i-1][j-2] != '.')
			res++;

		return res;
	}
	else if(board[i][j] == 'P')
	{
		if(j-1 >=0 && i+1 < 8 && board[i+1][j-1] != '.')
			res++;
		if(j-1 >= 0 && i-1 >= 0 && board[i-1][j-1] != '.')
			res++;

		return res;
	}
	else if(board[i][j] == '.')
		return 0;
}

int main()
{
	int T;
	cin>>T;
	for(cas = 1;cas <= T;cas++)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				board[i][j] = '.';
			}
		}
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			char a,c,type;int b;
			cin>>a>>b>>c>>type;
			board[b-1][7-(a-'A')] = type;
		}
		// for (int i = 0; i < 8; ++i)
		// {
		// 	for (int j = 0; j < 8; ++j)
		// 	{
		// 		cout<<board[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int ans = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				// cout<<kills(i,j)<<" ";
				ans+=kills(i,j);
			}
			// cout<<endl;
		}
		printf("Case #%d: %d\n",cas,ans);
	}
}