// Dynamic Programming Solution for
// Palindrome Partitioning Problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to get minimum of two integers
int min(int a, int b) { return (a < b) ? a : b; }

// Returns the minimum number of cuts needed to partition a string
// such that every part is a palindrome
int minPalPartion(char* str)
{
	// Get the length of the string
	int n = strlen(str);

	/* Create two arrays to build the solution in bottom up manner
	C[i][j] = Minimum number of cuts needed for palindrome partitioning
				of substring str[i..j]
	P[i][j] = true if substring str[i..j] is palindrome, else false
	Note that C[i][j] is 0 if P[i][j] is true */
	int C[n][n];
	bool P[n][n];

	int i, j, k, L; // different looping variables

	// Every substring of length 1 is a palindrome
	for (i = 0; i < n; i++)
	{
		P[i][i] = true;
		C[i][i] = 0;
	}

	for (L = 2; L <= n; L++)
	{
		// For substring of length L, set
		// different possible starting indexes
		for (i = 0; i < n - L + 1; i++)
		{
			j = i + L - 1; // Set ending index

			// If L is 2, then we just need to
			// compare two characters. Else
			// need to check two corner characters
			// and value of P[i+1][j-1]
			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

			// IF str[i..j] is palindrome, then C[i][j] is 0
			if (P[i][j] == true)
				C[i][j] = 0;
			else
			{
				// Make a cut at every possible
				// location starting from i to j,
				// and get the minimum cost cut.
				C[i][j] = INT_MAX;
				for (k = i; k <= j - 1; k++)
					C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
			}
		}
	}

	// Return the min cut value for
	// complete string. i.e., str[0..n-1]
	return C[0][n - 1];
}

// Driver code
int main()
{
	char str[] = "ababbbabbababa";
	cout<<"Min cuts needed for Palindrome Partitioning is "<<minPalPartion(str);
	return 0;
}