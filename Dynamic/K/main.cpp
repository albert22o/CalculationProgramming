#include <bits/stdc++.h>

int josephProblem(int boys,int k) {
	int res = 0;
	for (int i = 1; i <= boys; ++i)
		res = (res + k) % i;
	return res + 1;
}

int main() {
    std::ifstream in("joseph.in");
	int boys = 0;
	int k = 0;
	in >> boys >> k;
	std::ofstream out("joseph.out");
	out << josephProblem(boys, k);
}