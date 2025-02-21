#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

void FillInc(int arr[], int size) { // заполныет массив возрастающими значениями
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void FillDec(int arr[], int size) { // заполныет массив убыаающими значениями
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

void FillRand(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

int CheckSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int RunNumber(int arr[], int size) {
    int series = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            series += 1;
        }
    }
    return series;
}

void SelectSort(int arr[], int size, int& M, int& C) {
    M = 0;
    C = 0;

    for (int i = 0; i < size - 1; i++) {
        int k = i;

        for (int j = i + 1; j < size; j++) {
            C++;
            if (arr[j] < arr[k]) {
                k = j;
            }
        }

        std::swap(arr[i], arr[k]);
        // M++;
        M += 3;        
    }
}

void SelectSort_opti(int arr[], int size, int& M, int& C) {
    M = 0;
    C = 0;

    for (int i = 0; i < size - 1; i++) {
        int k = i;

        for (int j = i + 1; j < size; j++) {
            C++;
            if (arr[j] < arr[k]) {
                k = j;
            }
        }

        if (k != i) {
            std::swap(arr[i], arr[k]);
            // M++;
            M += 3;
        }
    }
}



void BubbleSort(int arr[], int size, int& M, int& C) {
    M = 0;
    C = 0;

    int i;
    int j;
    
    for (i = 0; i < size - 1; i++) {
        for (j = size -1; j > i; j--) {
            C++;
            if (arr[j] < arr[j - 1]) {
                M += 3;
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }

}


void BubbleSort_opti(int arr[], int size, int& M, int& C) {
    M = 0;
    C = 0;

    int i;
    int j;
    bool swapped;
    for (i = 0; i < size - 2; i++) {
        swapped = false;
        for (j = size-1; j > i; j--) {
            C++;
            if (arr[j] < arr[j - 1]) {
                M += 3;
                std::swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}


void PrintMas(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void castom_print(std::string str, int arr[], int size) {
    std::cout << str << ":\n";
    PrintMas(arr, size);
    std::cout << "CheckSum: " << CheckSum(arr, size) << "     RunNumber: " << RunNumber(arr, size) << "\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    const int size = 500;
    int arr[size];
    int r_min = 1;
    int r_max = 100;
    int M = 0; // пересылки
    int C = 0; // сравнения


    // BubbleSort на убывающих
    FillDec(arr, size);
    castom_print("До BubbleSort на убывающих", arr, size);
    BubbleSort(arr, size, M, C);
    castom_print("После BubbleSort на убывающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "   T = " << M+C << "\n\n";

    // BubbleSort на возрастающих
    FillInc(arr, size);
    castom_print("До BubbleSort на возрастающих", arr, size);
    BubbleSort(arr, size, M, C);
    castom_print("После BubbleSort на возрастающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "    T = " << M+C << "\n\n";

    // BubbleSort на рандоме
    FillRand(arr, size, r_min, r_max);
    castom_print("До BubbleSort на рандоме", arr, size);
    BubbleSort(arr, size, M, C);
    castom_print("После BubbleSort на рандоме", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "    T = " << M+C<< "\n\n";





    // SelectSort на убывающих
    FillDec(arr, size);
    castom_print("До SelectSort на убывающих", arr, size);
    SelectSort(arr, size, M, C);
    castom_print("После SelectSort на убывающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";
    

    // SelectSort на возрастающих
    FillInc(arr, size);
    castom_print("До SelectSort на возрастающих", arr, size);
    SelectSort(arr, size, M, C);
    castom_print("После SelectSort на возрастающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";


    // SelectSort на рандоме
    FillRand(arr, size, r_min, r_max);
    castom_print("До SelectSort на рандоме", arr, size);
    SelectSort(arr, size, M, C);
    castom_print("После SelectSort на рандоме", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";


    // оптимизированный SelectSort на убывающих
    FillDec(arr, size);
    castom_print("До оптимизированного SelectSort на убывающих", arr, size);
    SelectSort_opti(arr, size, M, C);
    castom_print("После оптимизированного SelectSort на убывающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";

    // оптимизированный SelectSort на возрастающих
    
    FillInc(arr, size);
    castom_print("До оптимизированного SelectSort на возрастающих", arr, size);
    SelectSort_opti(arr, size, M, C);
    castom_print("После оптимизированного SelectSort на возрастающих", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";

    // оптимизированный SelectSort на рандоме
    FillRand(arr, size, r_min, r_max);
    castom_print("До оптимизированного SelectSort на рандоме", arr, size);
    SelectSort_opti(arr, size, M, C);
    castom_print("После оптимизированного SelectSort на рандоме", arr, size);
    std::cout << "Кол-во пересылок: " << M << "   Кол-во сравнений: " << C << "     T = " << M+C<< "\n\n";


    return 0;
}