/*
 * Problem:
 * Write a method to print the last K lines of an input file using C++
 *
 * hints:
 * 449, 459
 *
 * solution:
 * Brute Force: read twice, first read counts N, second reads N - K to N
 * Circular: circular array of size k, update accordingly
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void lastKLines(string inName, int k)
{
	ifstream inFile(inName);
	string line;
	string L[k];
	int size = 0;

	while (inFile.peek() != EOF) {
		getline(inFile, L[size % k]);
		++size;
	}

	inFile.close();

	// compute start of circular array, and size of it
	int start = size > k ? (size % k) : 0;
	int end = min(k, size);
	
	for (int i = 0; i < end; ++i)
		cout << L[(start + i) % k] << ' ';
	cout << '\n';
}

int main()
{
	lastKLines("input.txt", 3);

	return 0;
}
