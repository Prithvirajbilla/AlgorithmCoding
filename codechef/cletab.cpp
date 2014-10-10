#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1000000000;
int n,m;
int tables[205];
int customer[405];
int ctables[405];
int answer;
struct next_customer
{
	int customer_id;
	int time;
	next_customer(int i,int j)
	{
		customer_id = i;
		time = j;
	}
};
map<int,list<int> > schedule;
set<next_customer> qu;
bool operator<(const next_customer& left,const next_customer& right)
{
	if(left.time != right.time) return left.time > right.time;
	else return left.customer_id < right.customer_id;
}
void clr()
{
	schedule.clear();
	qu.clear();
	fill(tables,tables+205,0);
	fill(customer,customer+405,0);
	fill(ctables,ctables+405,-1);

}
void addto(int a,int b)
{
	if(schedule.find(a) != schedule.end())
	{
/*		cout<<"found"<<endl;
		//found
*/		schedule[a].push_back(b);
	}
	else
	{	
/*		cout<<"as"<<endl;
*/
		list<int> v;
		v.push_back(b);
		schedule.insert(pair<int,list<int> >(a,v));
	}
}
void do_stuff()
{
	int number = 0;
	answer = 0;
	while(number < n)
	{
		int customer_number = customer[number+1];
		if(ctables[customer_number] == -1)
		{
			tables[number+1] = customer_number;
			ctables[customer_number] = number+1;
/*			cout<<schedule[customer_number].size()<<endl;
*/			schedule[customer_number].pop_front();
			if(schedule[customer_number].size() == 0)
				qu.insert(next_customer(customer_number,MAXINT));
			else
				qu.insert(next_customer(customer_number,schedule[customer_number].front()));

			answer++;
		}

		number++;
		if(number == m)
			break;
	}
	while(number < m)
	{
		int customer_number = customer[number+1];
		if(ctables[customer_number] == -1)
		{
			next_customer nn = *(qu.begin());
			qu.erase(nn);
			//deleting the first element
			ctables[nn.customer_id] = -1;
			ctables[customer_number] = 0;
			schedule[customer_number].pop_front();
			qu.erase(next_customer(customer_number,number+1));
			if(schedule[customer_number].size() == 0)
				qu.insert(next_customer(customer_number,MAXINT));
			else
				qu.insert(next_customer(customer_number,schedule[customer_number].front()));

			answer++;
		}
		else
		{
			//already sat customer came
			qu.erase(next_customer(customer_number,number+1));
			schedule[customer_number].pop_front();
			qu.insert(next_customer(customer_number,schedule[customer_number].front()));
		}

		number++;
	}


}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		clr();
		for (int i = 1; i <= m; ++i)
		{
			int c;
			cin>>c;
			addto(c,i);
			customer[i] = c;
		}
		do_stuff();
		cout<<answer<<endl;
	}
	return 0;
}