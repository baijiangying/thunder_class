#include <iostream>
#include <vector>

int main() {
	std::vector<int> ans;
	freopen("test.wav", "r", stdin);

	unsigned char a;
	while(std::cin >> a) 
		ans.push_back((int)a);
	freopen("test.txt", "w", stdout);
	for (int i = 0; i != ans.size(); ++i)
		std::cout << ans[i] << ' ';
	std::cout << std::endl;

	return 0;
}