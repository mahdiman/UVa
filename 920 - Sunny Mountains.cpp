#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;



struct point
{
	float x, y;
	point()
	{
		x = y = 0;
	}
	void operator = (point B)
	{
		x = B.x;
		y = B.y;
	}

	bool operator < (point B) const
	{
		if (x > B.x)
			return true;
		return false;
	}
};


point _Sort(point A, point B)
{
	if (A.x > B.x)
		return A;
	return B;
}

float GetSlope(point A, point B)
{
	return((A.y - B.y) / (A.x - B.x));
}



float GetDist(point A, point B)
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}


float Getx(point A, point B, float M)
{

	return (B.y - (A.y - M*A.x)) / M;
}


int main()
{

	int C, N;
	float Sum = 0;
	point Temp,MaxPeak;
	vector<point> V;


	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> Temp.x >> Temp.y;
			V.push_back(Temp);
		}
		sort(V.begin(), V.end());
		Sum += GetDist(V[0], V[1]);
		MaxPeak = V[1];
		for (int j = 1; j < V.size() - 1; j += 2)
		{
			for (int k = j + 2; k < V.size(); k+=2)
			{
				if (V[k].y > MaxPeak.y)
				{
					point P;
					P.y = MaxPeak.y;
					P.x = Getx(V[k], MaxPeak, GetSlope(V[k], V[k - 1]));
					Sum += GetDist(P, V[k]);
					MaxPeak = V[k];
					j = k;
					j -= 2;
					break;
				}
			}
		}
		cout << setprecision(2) << fixed << Sum << "\n";
		Sum = 0; V.clear();
	}







	return 0;
}
