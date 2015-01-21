#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;



struct point
{
	float x, y;
	point(){ x = y = 0; };
};


struct Circle
{
	point Centre;
	float raduis;
	int number;
};

struct Rectangle
{
	point UpperLeft, LowerRight;
	int number;
};



bool IsInCircle(Circle C , point P)
{
	if (pow(P.x - C.Centre.x, 2) + pow(P.y - C.Centre.y, 2) <= C.raduis*C.raduis)
		return true;
	return false;
}

bool IsInRect(Rectangle R, point P)
{
	if (P.x >= R.UpperLeft.x && P.y <= R.UpperLeft.y && P.x <= R.LowerRight.x && P.y >= R.LowerRight.y)
		return true;
	return false;
}

int main()
{
	char TempC;
	float TempI;
	Circle TempCir;
	Rectangle TempRect;
	point TempP;
	vector<Circle> VC;
	vector<Rectangle> VR;
	vector<string> OutPut;
	int counter = 1;
	while (true)
	{
		cin >> TempC;
		if (TempC == 'c')
		{
			cin >> TempCir.Centre.x >> TempCir.Centre.y >> TempCir.raduis;
			TempCir.number = counter;
			VC.push_back(TempCir);
		}

		else if (TempC == 'r')
		{
			cin >> TempRect.UpperLeft.x >> TempRect.UpperLeft.y >> TempRect.LowerRight.x >> TempRect.LowerRight.y;
			TempRect.number = counter;
			VR.push_back(TempRect);
		}

		else
			break;


		counter++;

	}
	counter = 1;
	bool Is = false;
	while (true)
	{
		cin>>TempP.x;
		cin>>TempP.y;
		ostringstream OS1;
		ostringstream OS2;
		OS1 << TempP.x;  OS2 << TempP.y;
		if (OS1.str() == "9999.9" && OS2.str() == "9999.9")
			break;


		for (int i = 0; i < VR.size(); i++)
		{
			if (IsInRect(VR[i], TempP))
			{
				ostringstream SS;
				ostringstream SS1;
				SS << counter;
				string S = "Point " + SS.str() + " is contained in figure";
				SS1 << VR[i].number;
				S += " "+SS1.str();
				OutPut.push_back(S);
				Is = true;

			}
		}


		for (int i = 0; i < VC.size(); i++)
		{
			if (IsInCircle(VC[i], TempP))
			{
				ostringstream SS;
				ostringstream SS1;
				SS << counter;
				string S = "Point " + SS.str() + " is contained in figure";
				SS1 << VC[i].number;
				S +=" "+ SS1.str();
				OutPut.push_back(S);
				Is = true;
			}
		}

		if (!Is)
		{
			ostringstream SS1;
			SS1 << counter;
			string S = "Point " + SS1.str() + " is not contained in any figure";
			OutPut.push_back(S);
		}
		else
			Is = false;

		

		counter++;
	}



	for (int i = 0; i < OutPut.size(); i++)
	{
		cout << OutPut[i] << "\n";
	}



	return 0;
}
