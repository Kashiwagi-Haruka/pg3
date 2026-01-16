#define NOMINMAX
#include <algorithm>
#include <stdio.h>

template<typename Type>

Type min(Type a, Type b) {
	return static_cast<Type>(std::min(a, b));
}

int main() {

	int a = 5;
	int b = 9;
	float c = 3;
	float d = 7;
	double e = 10;
	double f = 4;

	printf("%d\n", min<int>(a, b));
	printf("%f\n", min<float>(c, d));
	printf("%lf\n", min<double>(e, f));

	return 0;
}
