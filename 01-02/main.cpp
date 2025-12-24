#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> StudentNum{"k024g1017@g.neec.ac.jp", "k024g0033@g.neec.ac.jp", "k024g0057@g.neec.ac.jp", "k024g0020@g.neec.ac.jp", "k024g0109@g.neec.ac.jp", "k024g1031@g.neec.ac.jp",
	                          "k024g0004@g.neec.ac.jp", "k024g0027@g.neec.ac.jp", "k024g0058@g.neec.ac.jp", "k022g0113@g.neec.ac.jp", "k024g0007@g.neec.ac.jp", "k024g0083@g.neec.ac.jp",
	                          "k024g0110@g.neec.ac.jp", "k024g0066@g.neec.ac.jp", "k023g0029@g.neec.ac.jp", "k024g1030@g.neec.ac.jp"};

	// 並び替え
	sort(StudentNum.begin(), StudentNum.end());

	// ソート後のみ表示
	for (const auto& s : StudentNum) {
		cout << s << endl;
	}

	return 0;
}
