#include <cstdio>

template<class T1, class T2> class MinValue {
public:
	// 2つの値のうち小さい方を返す
	auto Min(T1 a, T2 b) { return (a < b) ? a : b; }
};

int main() {
	// int, float, double の全組み合わせ (3C2 + 同型ペア含む 6パターン)
	MinValue<int, int> m1;
	MinValue<int, float> m2;
	MinValue<int, double> m3;
	MinValue<float, float> m4;
	MinValue<float, double> m5;
	MinValue<double, double> m6;

	printf("Min(int, int)       = %d\n", m1.Min(10, 5));
	printf("Min(int, float)     = %.2f\n", m2.Min(7, 3.5f));
	printf("Min(int, double)    = %.2f\n", m3.Min(15, 8.75));
	printf("Min(float, float)   = %.2f\n", m4.Min(4.2f, 9.1f));
	printf("Min(float, double)  = %.2f\n", m5.Min(6.3f, 6.2));
	printf("Min(double, double) = %.2f\n", m6.Min(2.5, 2.7));

	return 0;
}
