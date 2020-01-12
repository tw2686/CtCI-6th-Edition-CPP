#include <iostream>
#include <vector>

/*
 * hints:
 * 51, 100
 *
 * ask:
 *
 * solutions:
 */

/* manual transpose and reverse */
void rotateMatrix1(std::vector<std::vector<int> > &m)
{
	int n = m.size();

	// transpose
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j) {
			int tmp = m[j][i];
			m[j][i] = m[i][j];
			m[i][j] = tmp;
		}

	// reverse
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n/2; ++j) {
			int tmp = m[i][n-1-j];
			m[i][n-1-j] = m[i][j];
			m[i][j] = tmp;
		}
}

/* circular rotatation of rectangles */
void rotateMatrix2(std::vector<std::vector<int> > &m)
{
	int N = m.size();
	
	for (int layer = 0; layer < N / 2; ++layer) {
		int first = layer;
		int last = N - 1 - layer;
		for (int i = first; i < last; ++i) {
			int offset = i - first;
			int top = m[first][i];
			m[first][i] = m[last - offset][first];
			m[last - offset][first] = m[last][last - offset];
			m[last][last - offset] = m[i][last];
			m[i][last] = top;
		}
	}
}

/* function to print matrix */
void printMatrix(std::vector<std::vector<int> > &m)
{
	int N = m.size();

	std::cout << "-----" << std::endl;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			std::cout << m[i][j] << " \n"[j == N-1];
	std::cout << "-----" << std::endl;
}

int main()
{
	int N = 3;
	std::vector<std::vector<int> > mat(N, std::vector<int>(N));
	int k = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mat[i][j] = ++k;

	printMatrix(mat);
	//rotateMatrix1(mat);
	rotateMatrix2(mat);
	printMatrix(mat);

	return 0;
}
