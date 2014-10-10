#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int root(int x,int* fa){
if(x==fa[x]) return x;
else return fa[x]=root(fa[x],fa);
} 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		int* S = new int[N+1];
		int* own = new int[N+1];
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d",&S[i]);
		}
		for (int i = 1; i <= N; ++i)
		{
			own[i] = i;
		}
		int Q;
		cin>>Q;
		for (int i = 0; i < Q; ++i)
		{
			int num;
			scanf("%d",&num);
			if(num == 0)
			{
				int x,y;
				 scanf("%d %d",&x,&y);
				 int tx = root(x,own);
				 int ty = root(y,own);
				if(tx == ty)
				{
					printf("Invalid query!\n");
				}
				else
				{
					if(S[tx] > S[ty])
					{
						own[ty] = tx;
					}
					else if(S[ty] > S[tx])
					{
						own[tx] = ty;
					}
				}
			}
			else
			{
				int x;
				 scanf("%d",&x);  
				printf("%d\n",root(x,own));
			}
		}

	}
}