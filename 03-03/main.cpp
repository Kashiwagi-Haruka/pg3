#include <cstdio>

class Animal {
public:
	virtual void Speak() { printf("動物が何か声を出した。\n"); }
};

class Dog : public Animal {
public:
	void Speak() override { printf("犬は「ワン！」と鳴いた。\n"); }
};

class Cat : public Animal {
public:
	void Speak() override { printf("猫は「ニャー」と鳴いた。\n"); }
};

class Bird : public Animal {
public:
	void Speak() override { printf("鳥は「ピヨピヨ」と鳴いた。\n"); }
};

int main() {
	Animal* animals[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Bird();

	for (int i = 0; i < 3; i++) {
		animals[i]->Speak();
	}

	for (int i = 0; i < 3; i++) {
		delete animals[i];
	}

	return 0;
}
