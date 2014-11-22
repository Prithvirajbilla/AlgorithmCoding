#include <bits/stdc++.h>
using namespace std;

int hy,ay,dy,hm,am,dm,h,a,d;

int main()
{
	cin>>hy>>ay>>dy;
	cin>>hm>>am>>dm;
	cin>>h>>a>>d;
	int mi = 1000000;
	int mh,ma,md;float mah,madm;
	for (int i = 0; i <= 300; ++i)
	{
		for (int j = 0; j <= 300 ; ++j)
		{
			for (int k = 0; k <= 300 ; ++k)
			{
				int thy = hy+i;
				int tay = ay+j;
				int tdy = dy+k;
				float ady = 0;
				if(am-tdy > 0)
				{
					ady = thy;
					ady /= max(0,(am-tdy));
				}
				if(am -tdy <= 0 && tay-dm > 0)
				{
					mi = min(mi,h*i+a*j+d*k);
					continue;
				}
				float adm = 0;
				if(tay-dm > 0)
				{
					adm = hm;
					adm /= (tay-dm);
					bool is_real = false;
					for(int hh = ceil(adm);hh < ceil(ady);hh++)
					{
						if(thy - hh*(am-tdy) > 0 && hm - hh*(tay-dm)<=0)
						{
							is_real = true;
							break;
						}
					}
					if(is_real)
					{
						if(mi > h*i+a*j+d*k)
						{
							mah = ady;
							madm = adm;
							mi = min(mi,h*i+a*j+d*k);
							mh = i;
							ma = j;
							md = k;
						}
					}
				}
				// cout<<adm<<" "<<ady<<endl;
			}
		}
	}
	cout<<mi<<endl;
	// cout<<mh<<" "<<ma<<" "<<md<<endl;
	// cout<<mah<<" "<<madm<<endl;
}