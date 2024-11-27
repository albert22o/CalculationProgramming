#include <bits/stdc++.h>

std::vector<long long> str(23,-1);

long long wordsCount(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 3;
	if (str[n] != -1) return str[n];

	return str[n] = 3 * wordsCount(n - 1) - wordsCount(n - 2);

}

int main()
{
	int n = 0;
	std::cin >> n;
	std::cout << wordsCount(n);
}