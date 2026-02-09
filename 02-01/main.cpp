#define NOMINMAX
#include <algorithm>
#include <stdio.h>

template<typename Type>

Type Min(Type a, Type b) {
	return static_cast<Type>(std::min(a, b));
}

int main() {

	int a = 5;
	int b = 9;
	float c = 3.0f;
	float d = 7.0f;
	double e = 10.0;
	double f = 4.0;

	printf("%d\n", Min(a, b));
	printf("%f\n", Min(c, d));
	printf("%lf\n", Min(e, f));

	return 0;
}
