## Задача 1

Какво ще стане при изпълнението на следния код? Обяснете кратко защо.

```c++
#include <iostream>

class Base {
	double a;
public:
	Base(double a) : a(a) { }
};

class Der : public Base {
	double b;
public:
	Der(double a, double b) : Base(a), b(b) { }

	double getProduct() const {
		return a * b;
	}
};

int main() {
	Der der(11, 11);
	std::cout << der.getProduct() << std::endl;
	return 0;
}
```

## Задача 2
Кои извиквания на функции са правилни и кои ca грешни в следния код? Обяснете кратко защо.

```c++
#include <iostream>

class A {};
class B : A {};
struct C : B {};

void f1(A a);
void f2(const A &a);
void f3(const A *a);
void f4(B b);
void f5(const B &b);
void f6(const B *b);

int main() {
	A a;
	B b;
	C c;
	
	f1(b);  // 1
	f3(&b); // 2
	f1(c);  // 3
	f2(c);  // 4
	f3(&c); // 5
	f4(c);  // 6
	f5(c);  // 7
	f6(c);  // 8
	f5(a);  // 9
	f6(&a); // 10
	return 0;
}
```
## Задача 3
Има ли грешка в следния код? Обяснете кратко защо.

```c++
#include <iostream>

struct A { int a; };  
struct B : A { int b; };  
class C : B { int c; };  
  
int oops1(const B *ptr) {  
    return ptr->a * ptr->b;  
}  
  
int oops2(const C &ref) {  
    return ref.a + ref.b * ref.c;  
}  
  
int oops3(const A *b) {  
    return b->a * b->a * b->a;  
}  
  
int main() {  
    B b;  
    C c;  
    std::cout << oops1(&b) << std::endl  
              << oops2(c) << std::endl  
              << oops3(&b) << std::endl;  
    return 0;  
}
```
## Задача 4
Има ли грешка в следния код? Обяснете кратко защо.

```c++
class Base {
	char *blob;
	
	void free() { /* ... */ }
	void copyFrom(const Base& other) { /* ... */ }
	void moveFrom(Base&& other) { /* ... */ }
	
public:
	// правилно разписана голяма 6-ица (надяваме се)
	Base() = delete;
	Base(const Base& other) { /* ... */ }
	Base(Base&& other) { /* ... */ }
	Base& operator=(const Base& other) { /* ... */ }
	Base& operator=(Base&& other) { /* ... */ }
	~Base() { /* ... */ }
};

class Der : public Base {
	char *ptr;
	
	void free() { /* ... */ }
	void copyFrom(const Der& other) { /* ... */ }
	void moveFrom(Der&& other) { /* ... */ }
	
public:
	Der(const char* ptr) : ptr(ptr) {}
	
	Der(const Der& other) : Base(other) { /* ... */ }
	
	Der(Der&& other) : Base(other) { /* ... */ }
	
	Der& operator=(const Der& other) = delete;
	
	Der& operator=(Der&& other) : Base(other) {
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}
		return *this;
	}
	~Der() {
		Base::~Base();
	}
}
```
## Задача 5
Какъв ще е резултатът от изпълнението на следния код? Обяснете кратко защо.

```c++
#include <iostream>
struct A {
	int x;
};

struct B : A {
	int y;
}

long sumXs(const A* arr, size_t size) {
	long sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += arr[i].x;
	}
	
	return sum;
}

int main() {
    B arr[4] = {
            B(1, -1),
            B(2, 3),
            B(4, -5),
            B(8, 0)
    };

    std::cout << sumXs(arr, 4);
    return 0;
}
```

## Задача 6

Какво ще изведе следният код?
```c++
#include <iostream>
class A {  
    uint32_t a;  
    char b;  
};  
  
class B : protected A { char c; };  
  
int main() {  
    std::cout << sizeof(B);  
    return 0;  
}
```