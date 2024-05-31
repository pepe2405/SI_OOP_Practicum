# Задача 1

Реализирайте темплейтна функция sort. Ако темплейтния аргумент са числа от тип int числата се сортират чрез алгоритъма bubble sort, double - selection sort, unsigned - insertion sort.

# Задача 2

Използвайки Pair, приемаме че първия елемент е обект, а втория число - приоритет. Направете динамичен масив, такъв че всеки път като се добави елемент се сортира по приоритет. Използвайте наготово (https://github.com/stoychoX/Object-oriented-programming-FMI/tree/main/Seminar-SE/Seminar13/pair) и (https://github.com/Angeld55/Object-oriented_programming_FMI/tree/master/Week%2009/DynamicArrayOfA%20(with%20move)), като той ще приема Pair


# Sorts

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;

}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
       swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```
