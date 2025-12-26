#include <cstdio>

// 抽象クラス (インターフェース)
class IShape {
public:
	virtual double Size() = 0;
	virtual void Draw() = 0;
	virtual ~IShape() {} // 仮想デストラクタ（派生クラス破棄用）
};

// Circle（円）
class Circle : public IShape {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double Size() override { return 3.141592 * radius * radius; }

	void Draw() override { printf("Circle: 半径=%.2f, 面積=%.2f\n", radius, Size()); }
};

// Rectangle（矩形）
class Rectangle : public IShape {
private:
	double width;
	double height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}

	double Size() override { return width * height; }

	void Draw() override { printf("Rectangle: 幅=%.2f, 高さ=%.2f, 面積=%.2f\n", width, height, Size()); }
};

// メイン (コンソールアプリ)
int main() {
	IShape* shapes[2];

	shapes[0] = new Circle(5.0);         // 半径5
	shapes[1] = new Rectangle(4.0, 3.0); // 4 x 3

	for (int i = 0; i < 2; i++) {
		shapes[i]->Draw();
	}

	// 後始末
	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}

	return 0;
}
