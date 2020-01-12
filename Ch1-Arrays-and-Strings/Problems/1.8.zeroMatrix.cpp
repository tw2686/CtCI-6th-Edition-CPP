#include <iostream>
#include <vector>
#include <tuple>

/*
 * hints:
 * 51, 100
 *
 * ask:
 *
 * solutions:
 */

/* store seen zero (i, j) in bit vectors for row/col */
void zeroMatrix1(std::vector<std::vector<int> > &m)
{
	int M = m.size();
	int N = m[0].size();
	int row = 0, col = 0;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 0) {
				row |= 1 << i;
				col |= 1 << j;
			}	
		}
	}
	
	int i = 0, j = 0;

	while (row || col) {
		if (row) {
			if (row & 1) {
				for (int k = 0; k < N; ++k)
					m[i][k] = 0;
			}
			row >>= 1;
			++i;
		} 
		if (col) {
			if (col & 1) {
				for (int k = 0; k < M; ++k)
					m[k][j] = 0;
			}
			col >>= 1;
			++j;
		}
	}
}

/* O(1) space, use first row/col as replacement */
void zeroMatrix2(std::vector<std::vector<int> > &m)
{
	int M = m.size();
	int N = m[0].size();
	bool row = false;
	bool col = false;

	// check first row
	for (int j = 0; j < N; ++j) {
		if (m[0][j] == 0) {
			row = true;
			break;
		}
	}
	// check first col
	for (int i = 0; i < M; ++i) {
		if (m[i][0] == 0) {
			col = true;
			break;
		}
	}
	// check rest of matrix
	for (int i = 1; i < M; ++i) {
		for (int j = 1; j < N; ++j) {
			if (m[i][j] == 0) {
				m[i][0] = 0;
				m[0][j] = 0;
			}
		}
	}
	// nullify rows based on first col
	for (int i = 1; i < M; ++i) {
		if (m[i][0] == 0) {
			for (int j = 0; j < N; ++j)
				m[i][j] = 0;
		}
	}
	// nullify cols based on first row
	for (int j = 1; j < N; ++j) {
		if (m[0][j] == 0) {
			for (int i = 0; i < M; ++i)
				m[i][j] = 0;
		}
	}
	// nullify first row
	if (row) {
		for (int j = 0; j < N; ++j)
			m[0][j] = 0;
	}
	// nullify first col
	if (col) {
		for (int i = 0; i < M; ++i)
			m[i][0] = 0;
	}
}

/* function to print matrix */
void printMatrix(std::vector<std::vector<int> > &m)
{
	int M = m.size();
	int N = m[0].size();

	std::cout << "-----" << std::endl;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			std::cout << m[i][j] << " \n"[j == N-1];
	std::cout << "-----" << std::endl;
}

int main()
{
	int M = 6, N = 8;
	std::vector<std::vector<int> > mat(M, std::vector<int>(N));
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			mat[i][j] = 1;
	mat[1][1] = 0;
	mat[3][2] = 0;
	mat[5][5] = 0;

	printMatrix(mat);
	zeroMatrix2(mat);
	printMatrix(mat);

	return 0;
}
