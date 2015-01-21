#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_C 25
#define MAX_M 210

int A[MAX_M][MAX_C];
int Prices[25][25];
int N, M, C;


int get_max(int money, int g){

	if (money < 0)
		return -2;
	else if (g == C)
		return M - money;
	else if (A[money][g] != -1)
		return A[money][g];
	
	int max_ans = -2;
	
	for (int i = 1; i <= Prices[g][0]; i++)
	{
		max_ans =  max(max_ans, get_max(money - Prices[g][i], g + 1));
	}
	
	return A[money][g] = max_ans;
}

void set_A(){
	for (int i = 0; i < MAX_M; i++)
	for (int j = 0; j < MAX_C; j++)
		A[i][j] = -1;
}

int main(){

	cin >> N;
	while (N--){
		cin >> M >> C;
		for (int i = 0; i < C; i++){
			cin >> Prices[i][0];
			for (int j = 1; j <= Prices[i][0]; j++){
				cin >> Prices[i][j];
			}
		}

		set_A();
		int result = get_max(M, 0);
		if (result != -2)
			cout << result << "\n";
		else
			cout << "no solution\n";
	}

	return 0;
}