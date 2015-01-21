#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;


inline int Get_Max_Power(long long int n, long long int k)
{

	set<long long> s;
	int Max = -1;
	if (Max < k)
		Max = k;
	while (true)
	{
		
		k = k*k;
		ostringstream ss;
		ss << k;
		string S = ss.str();
		k = atoi(S.substr(0, n).c_str());
		if (Max < k)
			Max = k;
		if (s.find(k) != s.end())
			break;
		s.insert(k);
	}
	return Max;
}

int main()
{

	long long int n, k, t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		if (k < 2)
			cout << k<<"\n";
		else	
			cout << Get_Max_Power(n, k) << "\n";
	}
	return 0;
}