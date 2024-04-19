## Задача 1:
Какво ще се изпише на конзолата при изпълнението на следния фрагмент код?

```c++
try {  
    throw std::invalid_argument("invalid argument");  
    throw std::runtime_error("runtime error");  
} catch (const std::invalid_argument &е) {  
    std::cout << е.what() << std::endl;  
}  
catch (const std::runtime_error &е) {  
    std::cout << е.what() << std::endl;  
}  
  
try {  
    throw std::invalid_argument("ERROR");  
}  
catch (const std::runtime_error &) {  
    std::cout << "Runtime error" << std::endl;  
}  
catch (const std::exception &) {  
    std::cout << "Exception" << std::endl;  
}  
catch (const std::invalid_argument &) {  
    std::cout << "Invalid argument" << std::endl;  
}
```

## Задача 2:
Какво ще се изпише на конзолата при изпълнението на main-функцията?

```c++
class A {
public:
	A() {
		std::cout << "A()" << std::endl;
	}

	~A() {
		std::cout << "~A()" << std::endl;
	}
};

class B {
public:
	B() {
		std::cout << "B()" << std::endl;
		throw std::exception();
	}

	~B() {
		std::cout << "~B()" << std::endl;
	}
};

class C {
public:
	C() {
		std::cout << "C()" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

class X {
public:
	A a;
	B b;
	C c;
	
	X() : b(), c(), a() {
		std::cout << "X()";
	}

	~X() {
		std::cout << "~X()";
	}
};

int main() {
    try {
        X x;
    }
    catch(...) {
        std::cout << "Ooops" << std::endl;
    }
    
    return 0;
}
```

## Задача 3
Обяснете защо не се хвърлят грешки в деструкторите.

## Задача 4
Какво ще се отпечата на конзолата след изпълнението на следния фрагмент код?

```c++
class A {  
public:  
    A() {  
        static int counter = 0;  
        std::cout << "A()" << std::endl;  
  
        if (counter == 4) {  
            throw std::exception();  
        }  
  
        counter++;  
    }  
  
    ~A() {  
        std::cout << "~A()" << std::endl;  
    }  
};  
  
  
int main() {  
     try {  
         A aa[7];  
     } catch (...) {  
           
     }  
    return 0;  
}
```

В main-функцията се създава масив от обекти А с размер 5, като четвърият обект при създаването си хвърля грешка. Какви конструктори и деструктори ще се извикат?

## Задача 5
Какво ще се изпише на конзолата при изпълнението на следния фрагмент код?

```c++
class A {  
public:  
    A() {  
        std::cout << "A()" << std::endl;  
    }  
  
    A(const A& other) {  
        std::cout << "CC A()" << std::endl;  
    }

	~A() {
		std::cout << "~A()" << std::endl; 
	}
};  
  
A&& func() {  
    return std::move(A());  
}  
  
  
int main() {  
    A a = func();
    return 0;  
}
```
