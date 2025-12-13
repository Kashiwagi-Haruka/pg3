#include <cstring>
#include <list>
#include <stdio.h>
using namespace std;

int main() {

	list<const char*> stationList = {"Tokyo",  "Kanda",     "Akihabara", "Okachimachi",  "Ueno",       "Uguisudani",   "Nippori",   "Tabata",   "Komagome", "Sugamo",
	                                 "Otsuka", "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo", "Shinjuku",     "Yoyogi",    "Harajuku", "Shibuya",  "Ebisu",
	                                 "Meguro", "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",    "Hamamatsucho", "Shimbashi", "Yurakucho"};

	list<const char*>::iterator itr = stationList.begin();

	printf("山手線の駅名一覧\n");
	printf("----------------\n");
	printf("1970年版\n\n");

	for (int i = 0; itr != stationList.end(); i++) {
		printf("JY%d : %s\n", i + 1, *itr);
		++itr;
	}

	printf("----------------\n");
	printf("2019年版\n\n");

	itr = stationList.begin();
	for (int i = 0; itr != stationList.end(); i++) {

		printf("JY%d : %s\n", i + 1, *itr);

		if (strcmp(*itr, "Nippori") == 0) {
			++itr;
			itr = stationList.insert(itr, "Nishi-Nippori");
		} else {
			++itr;
		}
	}

	printf("----------------\n");
	printf("2022年版\n\n");

	itr = stationList.begin();
	for (int i = 0; itr != stationList.end(); i++) {

		printf("JY%d : %s\n", i + 1, *itr);

		if (strcmp(*itr, "Shinagawa") == 0) {
			++itr;
			itr = stationList.insert(itr, "Takanawa Gateway");
		} else {
			++itr;
		}
	}

	return 0;
}
