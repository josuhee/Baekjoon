//[백준] 1541 : 잃어버린 괄호

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;

	int result = 0, minus = 0, size;
	size = str.size();
	string tmp;
	for (int i = 0; i <= size; i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) {
				result -= stoi(tmp);
			}
			else {
				result += stoi(tmp);
			}
			if (str[i] == '-') minus = 1;
			tmp = "";
		}
		else tmp += str[i];
	}

	cout << result << "\n";
	return 0;
}