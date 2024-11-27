#include <bits/stdc++.h>

int hillDescending(std::vector<std::vector<int>>& hill) {
	auto canMoveFromLeftTop = [](int i, int j) -> bool {
		if (i < 1 || j < 1) return false;
		else return true; 
	};

	auto canMoveFromRightTop = [](int i,int j, int levelWidth) -> bool {
		if (i < 1 || j == levelWidth - 1) return false;
		else return true;
	};

	for (int i = 0; i < hill.size(); i++) {
		for (int j = 0; j < hill[i].size(); j++) {
			if (canMoveFromLeftTop(i, j) && canMoveFromRightTop(i,j,hill[i].size())) {
				hill[i][j] += std::max(hill[i - 1][j - 1], hill[i - 1][j]);
				continue;
			}

			if (canMoveFromLeftTop(i, j)) {
				hill[i][j] += hill[i - 1][j - 1];
				continue;
			}

			if (canMoveFromRightTop(i, j, hill[i].size())) {
				hill[i][j] += hill[i - 1][j];
				continue;
			}
		}
	}

	return (*std::max_element(hill[hill.size() - 1].begin(), hill[hill.size() - 1].end()));
}

int main(){
	int n = 0;
	std::cin >> n;
	std::vector<std::vector<int>> hill(n);
	
	for (size_t i = 0; i < n; i++) {
		hill[i].resize(i + 1);
	}
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < hill[i].size(); j++) {
			std::cin >> hill[i][j];
		}
	}

	std::cout << hillDescending(hill);
}