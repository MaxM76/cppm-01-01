#include <iostream>
#include <fstream>

int* createIntArray(int size) {
    return new int[size];
}

bool readArrays(int*& array1, int& array1Size, int*& array2, int& array2Size) {
    bool result = false;
    std::ifstream fin("in.txt");
    if (fin.is_open()) {
        fin >> array1Size;

        if (array1Size > 0) {
            array1 = createIntArray(array1Size);
            for (int i = 0; i < array1Size; i++) {
                fin >> array1[i];
            }
            std::cout << "Прочитали массив M" << std::endl;
        }
        else {
            std::cout << "Размер массива M не положителен!" << std::endl;
            return result;
        }

        fin >> array2Size;
        if (array2Size > 0) {
            array2 = createIntArray(array2Size);

            for (int i = 0; i < array2Size; i++) {
                fin >> array2[i];
            }
            std::cout << "Прочитали массив N" << std::endl;
        }
        else {
            std::cout << "Размер массива N не положителен!" << std::endl;
            return result;
        }
        fin.close();
        result = true;
    }
    return result;
}

void writeArrays(int*& array1, int& array1Size, int*& array2, int& array2Size) {
    std::ofstream fout("out.txt");
    fout << array2Size << "\n";
    fout << array2[array2Size - 1];
    for (int i = 0; i < array2Size - 1; i++) {
        fout << "\t" << array2[i];
    }
    fout << "\n";

    fout << array1Size << "\n";
    for (int i = 1; i < array1Size; i++) {
        fout << array1[i] << "\t";
    }
    fout << array1[0] << "\n";

    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arrMSize;
    int arrNSize;
    int* arrayM;
    int* arrayN;

    if (readArrays(arrayM, arrMSize, arrayN, arrNSize)) {
        writeArrays(arrayM, arrMSize, arrayN, arrNSize);
        std::cout << "Массивы записаны" << std::endl;
        delete[] arrayM;
        delete[] arrayN;
    } else {
        std::cout << "Не получилось открыть файл и считать массивы!" << std::endl;
    }

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
