#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;


long long get_median(vector<long long> V)
{
	if (V.size() % 2 != 0)
	{
		if (V.size() != 1)
			return V[V.size() / 2];
		else
			return V[0];
	}
	return (V[V.size() / 2 - 1]  + V[V.size() / 2])/2;

}

int main()
{
	vector<long  long> V;
	vector<long long> VOutput;
	long long Temp;

	while (cin >> Temp)
	{
		V.push_back(Temp);
		sort(V.begin(), V.end());
		cout<< get_median(V)<<"\n";
	}

	/*for (int i = 0; i < VOutput.size(); i++)
	{
		cout << VOutput[i] << "\n";
	}*/



	return 0;
}