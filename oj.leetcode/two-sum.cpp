#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
    	vector<int> ans;
        for (int i = 0; i < numbers.size(); ++i)
        {
       		for (int j = i+1; j <numbers.size() ; ++j)
       		{
       			if(numbers[i] + numbers[j] == target)
       			{
       				ans.push_back(i+1);
       				ans.push_back(j+1);
       				break;
       			}
       		}
        }
        return ans;
    }
};

int main()
{
	Solution s;
	int arr[5] = {2,7,11,15};
	vector<int> numbers(arr,arr+4);
	int target = 9;
	vector<int> k = s.twoSum(numbers,target);
	cout<<k[0]<<" "<<k[1]<<endl;
}