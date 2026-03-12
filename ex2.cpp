#include <iostream>
#include <cstdlib>

using namespace std;

// Структура для упакованных данных
struct PackedData {
    int counts[18];  // счетчики для чисел 0-17
    int total;       // общее количество элементов
};

// Функция упаковки - подсчитываем количество каждого числа
PackedData* pack_array(int a[], int n) {
    PackedData* data = new PackedData;
    data->total = n;
    
    for (int i = 0; i < 18; i++) {
        data->counts[i] = 0;
    }
    
    // Подсчитываем каждое число
    for (int i = 0; i < n; i++) {
        int value = a[i];
        data->counts[value]++;  // увеличиваем счетчик для этого числа
    }
    
    return data;
}

// Функция распаковки - восстанавливаем массив по счетчикам
void unpack_array(PackedData* data, int result[]) {
    int index = 0;
    
    // Для каждого числа от 0 до 17
    for (int value = 0; value < 18; value++) {
        // Записываем число столько раз, сколько оно встретилось
        for (int j = 0; j < data->counts[value]; j++) {
            result[index] = value;
            index++;
        }
    }
}



int main(){
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    
    // исходный массив
    int* a = new int[size];
    
    
    for (int i = 0; i < size; i++){
        a[i] = rand() % 18;
    }
   
    
    
    cout << "\nИсходный массив (первые 20): ";
    for (int i = 0; i < min(20, size); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    // Упаковываем
    PackedData* packed = pack_array(a, size);
    

    cout << "Исходный размер: " << size * sizeof(int) << " байт" << endl;
    cout << "Упакованный размер: " << sizeof(PackedData) << " байт" << endl;
    
    // Распаковываем
    int* b = new int[size];
    unpack_array(packed, b);
    
    cout << "\nРаспакованный массив (первые 20): ";
    for (int i = 0; i < min(20, size); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    
    

    
    delete[] a;
    delete[] b;
    delete packed;
    
    return 0;
}