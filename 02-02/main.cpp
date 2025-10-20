#include <stdio.h>

int Function(int x,int y){

	
	
	if (y == 1) {
	return x;
	} else {
		return Function(x * 2 - 50, y - 1);
	}
}

int main(){

	int result1{};
	int result2{};

	
	int input=1;

	printf("何時間働いたかを入力 : ");
	scanf_s("%d", &input);
	if (input > 26) {
		printf("数字が大きいため26に変更します\n\n");
		input = 26;
	}
	for (int i = 0; i < input; i++) {
		
		result1 = 1226*(i+1);
		result2 = Function(100, (i+1));

		printf("[%d時間目] 固定給 %d 円　: 再帰関数給　%d 円\n", i+1, result1, result2);
	
	}


	return 0;
}