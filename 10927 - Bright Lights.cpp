#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;



struct point
{
	double x, y, z;
	bool IsVisible;
	point()
	{
		x = y = z = 0;
		IsVisible = true;
	}

	bool operator < (point B) const
	{
		if (x < B.x)
			return true;
		else if (x == B.x)
		{
			if (y < B.y)
				return true;
			else
				return false;
		}
		return false;
	}
	

};


double GetSlope(point A)
{
	if (A.x == 0)
		return 100000000000;
	else if (A.y == 0)
		return 0;
	else
		return (A.y / A.x);
}


double GetDistance(point A)
{
	return sqrt(A.x*A.x + A.y*A.y);
}



int main()
{
	long long int N;
	vector<point> VOP;
	map<double, vector<point> > MP;
	set<double> SP;
	double a;
	point TempP;

	long long int counter = 1;
	while (true)
	{
		
		cin >> N;
		if (!N)
			break;

		for (int i = 0; i < N; i++)
		{
			cin >> TempP.x >> TempP.y >> TempP.z;
			MP[GetSlope(TempP)].push_back(TempP);
			SP.insert(GetSlope(TempP));
		}

		

		for (set<double>::iterator it = SP.begin(); it != SP.end(); it++)
		{
			for (int i = 0; i < MP[*it].size()-1; i++)
			{
				for (int j = i + 1; j < MP[*it].size(); j++)
				{
					if ((GetDistance(MP[*it][i]) > GetDistance(MP[*it][j])) && MP[*it][j].z >= MP[*it][i].z && MP[*it][i].x*MP[*it][j].x >= 0 )
					{
						if (MP[*it][i].IsVisible == true)
						{
							MP[*it][i].IsVisible = false;
							VOP.push_back(MP[*it][i]);
						}
					}

					else if ((GetDistance(MP[*it][j]) > GetDistance(MP[*it][i])) && MP[*it][i].z >= MP[*it][j].z && MP[*it][i].x*MP[*it][j].x >= 0)
					{
						if (MP[*it][j].IsVisible == true)
						{
							MP[*it][j].IsVisible = false;
							VOP.push_back(MP[*it][j]);
						}
					}

				}
			}
		}


		ostringstream SS;
		SS << counter;

		if (!VOP.size())
		{
			cout << "Data set " + SS.str() + ":" << "\n" << "All the lights are visible.\n";
		}
		else
		{
			sort(VOP.begin(), VOP.end());
			cout << "Data set " + SS.str() + ":" << "\n" << "Some lights are not visible:\n";
			for (int i = 0; i < VOP.size(); i++)
			{
				cout << "x = " << VOP[i].x << ", y = " << VOP[i].y;
				if (i == VOP.size() - 1)
					cout << ".";
				else
					cout << ";\n";
			}
			cout << "\n";
		}


		counter++;
		MP.clear();
		SP.clear();
		VOP.clear();

	}

	return 0;

}
