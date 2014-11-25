#include <bits/stdc++.h>
using namespace std;
multimap<string,vector<string> > execution_paths;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

void print()
{
	for(multimap<string,vector<string> >::iterator it = execution_paths.begin();
		it!=execution_paths.end();it++)
	{
		cout<<it->first<<" ";
		for(int i=0; i< it->second.size();i++)
		{
			cout<<it->second[i]<<", ";
		}
		cout<<endl;
	}
}


int main()
{
	set<string> results;
	//taking input
	int number_of_paths = 0;
	while (!cin.eof())
	{
		string path,locks;
		cin >> path>>locks;
		vector<string> all_locks = split(locks,',');
		execution_paths.insert(make_pair(path,all_locks));
		number_of_paths++; 
	}

	int ind = 0;
	
	for (multimap<string,vector<string> >::iterator uit=execution_paths.begin();
		uit!= execution_paths.end();uit++)
	{
		for (multimap<string,vector<string> >::iterator lit = execution_paths.begin();
			lit!=execution_paths.end();lit++)
		{
			bool is_found = false;
			for(int i=0; i< uit->second.size();i++)
			{
				int lower_index = -1;
				for(int j=0; j<lit->second.size();j++)
				{
					if(uit->second[i].compare(lit->second[j]) == 0)
					{
						lower_index = j;
					}
				}
				int lower_index2= -1;
				int upper_index2 = -1;
				if(lower_index != -1)
				{
					for(int k=i+1; k<uit->second.size();k++)
					{
						for(int m=0; m < lower_index;m++)
						{
							if(uit->second[k].compare(lit->second[m]) == 0)
							{
								lower_index2 = m;
								break;
							}
							
						}
						if(lower_index2 != -1)
						{
							upper_index2 = k;
							break;
						}
					}
					if(lower_index2 != -1)
					{
						vector<string> as;
						as.push_back(uit->first);
						as.push_back(lit->first);
						sort(as.begin(),as.end());
						if(as[0].compare(as[1]) != 0)
						results.insert(as[0]+","+as[1]);
						is_found = true;
						break;
					}
				}
			}
		}
		ind++;
		if(ind == number_of_paths)
			break;
	}

	for(set<string>::iterator it = results.begin();it!=results.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}