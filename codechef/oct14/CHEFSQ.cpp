#include <bits/stdc++.h>
using namespace std;
pair<int,int> A[2005];
map<int,vector<int> > onx,ony;
int main()
{
	int n;
	cin>>n;
	memset(A,0,sizeof(A));
	for (int i = 0; i < n; ++i)
	{
		int x,y;
		cin>>x>>y;
		A[i] = make_pair(x,y);
		map<int,vector<int> >::iterator it;
		it = onx.find(x);
		if(it != onx.end())
		{
			(it->second).push_back(y);
		}
		else
		{
			std::vector<int> v;
			v.push_back(y);
			onx.insert(make_pair(x,v));
		}
		it = ony.find(y);
		if(it != ony.end())
		{
			(it->second).push_back(x);
		}
		else
		{
			std::vector<int> v;
			v.push_back(x);
			ony.insert(make_pair(y,v));
		}
	}
	if(n <= 2)
	{
		cout<<4-n<<endl;
		return 0;
	}
	int max_points_found = 2;
	//ssup everything in maps
	for (map<int,vector<int> >::iterator it = onx.begin();it != onx.end();it++)
	{
		int x = it->first;
		vector<int> now = it->second;
		for (int i = 0; i < now.size(); ++i)
		{
			int fy = now[i];
			for (int j = i+1; j < now.size(); ++j)
			{
				int sy=now[j];
				int dist = abs(sy-fy);
				if(onx.find(x+dist) != onx.end())
				{
					map<int,vector<int> >::iterator it1 = onx.find(x+dist);
					vector<int> now1 = it1->second;
					int num1 = 0;
					for (int i = 0; i < now1.size(); ++i)
					{
						if(now1[i] == fy || now1[i] == sy)
							num1++;
					}
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}
				}
				if(onx.find(x-dist) != onx.end())
				{
					map<int,vector<int> >::iterator it1 = onx.find(x-dist);
					vector<int> now1 = it1->second;
					int num1 = 0;
					for (int i = 0; i < now1.size(); ++i)
					{
						if(now1[i] == fy || now1[i] == sy)
							num1++;
					}
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}

				}
				if(dist%2 == 0)
				{
					int num1 = 0;
					// cout<<x-(dist/2)<<endl;
					if(onx.find(x-(dist/2)) != onx.end())
					{
						// cout<<"there1"<<endl;
						map<int,vector<int> >::iterator it1 = onx.find(x-(dist/2));
						vector<int> now1 = it1->second;
						for (int i = 0; i < now1.size(); ++i)
						{
							if(now1[i] == min(fy,sy)+(dist/2)) 
							{
								num1++;
								break;
							}
						}
					}
					// cout<<x+(dist/2)<<endl;
					if(onx.find(x+(dist/2)) != onx.end())
					{
						// cout<<"there2"<<endl;
						map<int,vector<int> >::iterator it1 = onx.find(x+(dist/2));
						vector<int> now1 = it1->second;
						for (int i = 0; i < now1.size(); ++i)
						{
							if(now1[i] == min(fy,sy)+(dist/2))
							{
								num1++;
								break;
							}
						}
					}
					// cout<<"num1 "<<num1<<endl;
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}
				}

			}
		}
	}


//////////////ony
	for (map<int,vector<int> >::iterator it = ony.begin();it != ony.end();it++)
	{
		int y = it->first;
		vector<int> now = it->second;
		for (int i = 0; i < now.size(); ++i)
		{
			int fx = now[i];
			for (int j = i+1; j < now.size(); ++j)
			{
				int sx=now[j];
				int dist = abs(sx-fx);
				if(onx.find(y+dist) != ony.end())
				{
					map<int,vector<int> >::iterator it1 = ony.find(y+dist);
					vector<int> now1 = it1->second;
					int num1 = 0;
					for (int i = 0; i < now1.size(); ++i)
					{
						if(now1[i] == fx || now1[i] == sx)
							num1++;
					}
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}
				}
				if(ony.find(y-dist) != ony.end())
				{
					map<int,vector<int> >::iterator it1 = ony.find(y-dist);
					vector<int> now1 = it1->second;
					int num1 = 0;
					for (int i = 0; i < now1.size(); ++i)
					{
						if(now1[i] == fx || now1[i] == sx)
							num1++;
					}
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}

				}
				if(dist%2 == 0)
				{
					int num1 = 0;
					if(ony.find(y-dist/2) != ony.end())
					{
						map<int,vector<int> >::iterator it1 = ony.find(y-dist/2);
						vector<int> now1 = it1->second;
						for (int i = 0; i < now1.size(); ++i)
						{
							if(now1[i] == min(fx,sx)+dist/2)
							{
								num1++;
								break;
							}
						}
					}
					if(ony.find(y+dist/2) != onx.end())
					{
						map<int,vector<int> >::iterator it1 = ony.find(y+dist/2);
						vector<int> now1 = it1->second;
						for (int i = 0; i < now1.size(); ++i)
						{
							if(now1[i] == min(fx,sx)+dist/2)
							{
								num1++;
								break;
							}
						}
					}
					max_points_found=  max(max_points_found,num1+2);
					if(max_points_found == 4)
					{
						cout<<0<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<4-max_points_found<<endl;
	return 0;

}