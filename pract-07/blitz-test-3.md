 # Блиц тест 3
 За задачи 1, 2 и 3 са дадени следните структури и функции:
 
 ```c++
 struct A {  
    A() {  
        std::cout << "A()" << std::endl;  
    }  
  
    A(const A& other) {  
        std::cout << "CC A" << std::endl;  
    }  
  
    A& operator=(const A& other) {  
        std::cout << "op= A" << std::endl;  
        return *this;  
    }  
  
    ~A() {  
        std::cout << "~A()" << std::endl;  
    }  
};  
  
struct B {  
    A a;  
    B() {  
        std::cout << "B()" << std::endl;  
    }  
  
    B(const B& other) : a(other.a) {  
        std::cout << "CC B" << std::endl;  
    }  
  
    B& operator=(const B& other) {  
        std::cout << "op= B" << std::endl;
		a = other.a;    
        return *this;  
    }  
  
    ~B() {  
        std::cout << "~B()" << std::endl;  
    }  
};

void f1(const B& b) {};  
void f2(B b) {};  
void f3(B* ptr) {};
```
## Задача 1
Какво ще изведе на конзолата следният код при извикване на функцията?

```c++
void task1() {  
    A a;  
    A copy = a;  
    A aa;  
    aa = a;  
}
```

## Задача 2
Какво ще изведе на конзолата следният код при извикване на функцията?
```c++
void task2 () {  
    B b;  
    f1(b);  
  
    f2(b);  
    A a;  
}
```

## Задача 3
Какво ще изведе на конзолата следният код при извикване на функцията?
```c++
void task3 () {  
    f2(B());  
    B b;  
    f3(&b);  
}
```
## Задача 4
Има ли проблеми в следния фрагмент код? Обосновете се и поправете кода.
```c++
#include <iostream>
#include <fstream>

class Meat {  
private:  
    double price;
    
public:  
    double getPrice() {  
        return price;  
    }  
    void setPrice(double price) {  
        this->price = price;  
    }  
};  
  
class Lunch {  
private:  
    const Meat* steak;  
  
public:  
    Lunch(const Meat* steak) {  
        this->steak = steak;  
    }  
  
    double getSteakPrice() const {  
        return steak->getPrice();  
    }  
  
    std::ostream& operator<<(std::ostream& os) const {  
        return os << getSteakPrice();  
    }  
  
    ~Lunch() {  
        delete steak;  
    }  
};

const Meat* makeSteak() {  
    Meat bestSteak;  
    bestSteak.setPrice(999);  
    return &bestSteak;  
}  
  
int main() {  
    const Meat* steak = makeSteak();  
    Lunch lunch(steak);  
    std::cout << lunch;  
    return 0;  
}
```
