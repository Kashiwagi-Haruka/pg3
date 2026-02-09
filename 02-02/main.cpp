#include <stdio.h>

int RecursiveHourlyWage(int previousHourlyWage, int currentHour) {
	if (currentHour == 1) {
		return previousHourlyWage;
	}
	return RecursiveHourlyWage(previousHourlyWage * 2 - 50, currentHour - 1);
}

int main() {
	int inputHours = 1;
	printf("何時間働いたかを入力 : ");
	scanf("%d", &inputHours);

	if (inputHours > 26) {
		printf("数字が大きいため26に変更します\n\n");
		inputHours = 26;
	}

	int totalFixedWage = 0;
	int totalRecursiveWage = 0;
	int profitableHour = -1;

	for (int hour = 1; hour <= inputHours; hour++) {
		const int fixedHourlyWage = 1226;
		const int recursiveHourlyWage = RecursiveHourlyWage(100, hour);

		totalFixedWage += fixedHourlyWage;
		totalRecursiveWage += recursiveHourlyWage;

		printf("[%d時間目] 固定給累計 %d 円 : 再帰給累計 %d 円\n", hour, totalFixedWage, totalRecursiveWage);

		if (profitableHour == -1 && totalRecursiveWage > totalFixedWage) {
			profitableHour = hour;
		}
	}

	if (profitableHour == -1) {
		printf("\n%d時間以内では固定給のほうが高いです。\n", inputHours);
	} else {
		printf("\n%d時間以上働くと再帰的な賃金体系のほうが儲かります。\n", profitableHour);
	}

	return 0;
}