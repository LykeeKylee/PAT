#include <iostream>
using namespace std;

int step = 0;

int cmp_less(int &x, int &y) {
    return x < y;
}

int cmp_more(int &x, int &y) {
    return x > y;
}

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

void display(int array[], int size) {
    for(int i = 0; i < size; ++i) cout << array[i] << (i != size - 1 ? ' ' : '\n');
}

void bubble_sort(int array[], int size, int(*cmp)(int &, int &)) {
    cout << "Bubble Sort" << endl;
    for(int i = 0; i < size; ++i) {
        cout << "Step " << ++step << endl;
        for(int j = 0; j < size - i - 1; ++j) {
            if(!cmp(array[j], array[j + 1])) {
                swap(array[j], array[j + 1]);
            }
            display(array, size);
        }
    }
}

void selection_sort(int array[], int size, int(*cmp)(int &, int &)) {
    cout << "Selection Sort" << endl;
    for(int i = 0; i < size; ++i) {
        cout << "Step " << ++step << ": ";
        int ptr = i;
        for(int j = i + 1; j < size; ++j) {
            if(cmp_less(array[j], array[ptr]))
                ptr = j;
        }
        if(ptr != i) swap(array[ptr], array[i]);
        display(array, size);
    }
}

void insert_sort(int array[], int size, int(*cmp)(int &, int &)) {
    cout << "Insert Sort" << endl;
    for(int i = 1; i < size; ++i) {
        cout << "Step " << ++step << ": ";
        int value = array[i], j;
        for(j = i - 1; j >= 0; --j) {
            if(cmp(value, array[j]))
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = value;
        display(array, size);
    }
}

int main() {
    int a[10] = {5, 9, 3, 4, 2, 1, 6, 8, 0, 7};
    int size = 10;
    cout << "Array: ";
    display(a, size);
//    bubble_sort(a, size, cmp_less);
//    selection_sort(a, size, cmp_less);
    insert_sort(a, size, cmp_less);
    return 0;
}