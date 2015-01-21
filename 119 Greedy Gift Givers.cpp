#include<iostream>
#include<vector>
#include<string>
using namespace std;


struct Person
{
	string Name;
	int Money;
	Person()
	{
		Money = 0;
	}
};


int Search(vector<Person> P, string N)
{
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i].Name == N)
			return i;
	}
	return -1;
}


int main()
{
	int N, Given_Money, Num, Taken_Money, count = 0 ;
	string Temp;
	Person TempP;
	vector<Person> PVec;

	while (cin>>N)
	{
		count++;
		for (int i = 0; i < N; i++)
		{
			cin >> TempP.Name;
			PVec.push_back(TempP);
		}

		for (int i = 0; i < N; i++)
		{
			cin >> Temp;
			cin >> Given_Money >> Num;
			if (Num>0 || Given_Money > 0)
			{
				if (Num > 0 && Given_Money > 0)
					Taken_Money = Given_Money / Num;
				else
					Taken_Money = 0;
				PVec[Search(PVec, Temp)].Money -= Taken_Money*Num;

				for (int i = 0; i < Num; i++)
				{
					cin >> Temp;
					PVec[Search(PVec, Temp)].Money += Taken_Money;
				}
			}
		}

		if (count!=1)
			cout << "\n";
		for (int i = 0; i < N; i++)
		{
			cout << PVec[i].Name << " " << PVec[i].Money << "\n";
		}
		PVec.clear();
		
	}
}