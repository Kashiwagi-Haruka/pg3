#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> StudentNum{"k024g1017@g.neec.ac.jp", "k024g0033@g.neec.ac.jp", "k024g0057@g.neec.ac.jp", "k024g0020@g.neec.ac.jp", "k024g0109@g.neec.ac.jp", "k024g1031@g.neec.ac.jp",
	                          "k024g0004@g.neec.ac.jp", "k024g0027@g.neec.ac.jp", "k024g0058@g.neec.ac.jp", "k022g0113@g.neec.ac.jp", "k024g0007@g.neec.ac.jp", "k024g0083@g.neec.ac.jp",
	                          "k024g0110@g.neec.ac.jp", "k024g0066@g.neec.ac.jp", "k023g0029@g.neec.ac.jp", "k024g1030@g.neec.ac.jp"};

	const string startmail = "k024g";
	int midNum = 0;
	const string endmail = "@g.neec.ac.jp";

	for (int i = 0; i < 10000; i++) {
		
		char buf[16];
		sprintf_s(buf, sizeof(buf), "%04d", midNum); 
		string mail = startmail + buf + endmail;


		
		auto itr = find(StudentNum.begin(), StudentNum.end(), mail);

		if (itr != StudentNum.end()) {
			
			printf("%s\n", mail.c_str());
		}

		midNum++;
	}

	return 0;
}
