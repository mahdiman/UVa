#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>


#define MAX_COL 100
#define MAX_ROW 12

long long Matrix[MAX_ROW][MAX_COL];
long long       Paths[MAX_ROW][MAX_COL];
int       axis[MAX_ROW][MAX_COL];
bool      mark[MAX_ROW][MAX_COL];

int N, M;

using namespace std;


long long min_3(long long A, long long B, long long C){

	A = min(A, B);
	return min(A, C);
}


long long min_path(int row, int col){



	if (col == M - 1){
		return Matrix[row][col];
	}

	else if (mark[row][col])
		return Paths[row][col];

	int new_col = col + 1;
	int pre_row, post_row;

	post_row = row + 1 == N ? 0 : row + 1;
	pre_row = row - 1 == -1 ? N - 1 : row - 1;

	long long mini_path1 = 10000000000, mini_path2 = 10000000000, mini_path3 = 10000000000;

	mini_path1 = min(mini_path1, min_path(row, new_col));
	mini_path2 = min(mini_path2, min_path(pre_row, new_col));
	mini_path3 = min(mini_path3, min_path(post_row, new_col));

	long long mini_path = min_3(mini_path1, mini_path2, mini_path3);

	if (mini_path == mini_path3 && post_row == 0)
		axis[row][col] = post_row;
	else if (mini_path == mini_path2 && pre_row != N - 1)
		axis[row][col] = pre_row;
	else if (mini_path == mini_path1)
		axis[row][col] = row;
	else if (mini_path == mini_path3)
		axis[row][col] = post_row;
	else
		axis[row][col] = pre_row;


	mark[row][col] = true;
	return Paths[row][col] = Matrix[row][col] + mini_path;
}


void reset(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
		{
			mark[i][j] = false;
		}
	}
}




int main(){

	//freopen("input.txt", "r", stdin);
	while (cin >> N){
		cin >> M;
		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Matrix[i][j];
		reset();

		vector<long long> inds(N);
		long long min_index, minimum = 10000000000;

		for (int i = 0; i < N; i++){
			inds[i] = min_path(i, 0);
			if (minimum > inds[i])
			{
				minimum = inds[i];
				min_index = i;
			}
		}

		cout << min_index + 1;
		for (int i = 0; i < M - 1; i++)
		{
			cout << " " << axis[min_index][i] + 1;
			min_index = axis[min_index][i];
		}
		cout << endl;

		cout << minimum << "\n";
	}

	return 0;
}