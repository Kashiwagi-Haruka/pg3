#include <stdio.h>
#include <list>
using namespace std;


int main(){

	list<int> stationList;
	for (int i = 0; i < 30; i++) {
		stationList.push_back(i+1);
	}



	list<int>::iterator itr;
	itr = stationList.begin();
	
	for (int i = 0; i < stationList.size(); i++) {
		printf("%d\n", *itr);
		itr++;
	}




	return 0;
}