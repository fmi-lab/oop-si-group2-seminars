#include <iostream>
#include <iomanip>

template <typename T>
T doubleUp (T a) {
    return a * 2;
}

template <typename T>
T tripleUp (T a) {
    return a * 3;
}

char upperCase(char symbol) {
    char result = symbol;
    if (symbol >= 'a' && symbol <= 'z') {
        result = (char) (result - 'a' + 'A');

    }
    return result;
}

char lowerCase(char symbol) {
    char result = symbol;
    if (symbol >= 'A' && symbol <= 'Z') {
        result = (char) (result - 'A' + 'a');

    }
    return result;
}

char* changeCase(const char* str, size_t size, char (*caseShift)(char)) {
    char* changeCaseString = new char[size];
    for (size_t i = 0; i < size - 1; i++) {
        changeCaseString[i] = caseShift(str[i]);
    }
    changeCaseString[size - 1] = '\0';

    return changeCaseString;
}


template <typename T>
T** initMatrix(size_t rows, size_t columns) {
    T** matrix = new T*[rows];
    for (size_t i = 0; i < rows; i++) {
        matrix[i] = new T[columns];
    }
    return matrix;
}

template <typename T>
void deleteMatrix(T** matrix, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
void inputMatrix(T** matrix, size_t rows, size_t columns) {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
void printMatrix(T** matrix, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void applyAltToMatrix(T** matrix, size_t rows, size_t columns, T (*f)(T), T (*g)(T)) {
    for(size_t i = 0; i < rows - 1; i += 2) {
        for(size_t j = 0; j < columns; j++) {
            matrix[i][j] = f(matrix[i][j]);
            matrix[i+1][j] = g(matrix[i+1][j]);
        }
    }

    if (rows % 2 != 0) {
        for (size_t j = 0; j < columns; j++) {
            matrix[rows-1][j] = f(matrix[rows-1][j]);
        }
    }
}

template <typename T>
void testMatrix(T (*f)(T), T (*g)(T)) {
    size_t n = 0;
    std::cin >> n;

    T** matrix = initMatrix<T>(n, n);

    inputMatrix(matrix, n, n);
    printMatrix(matrix, n, n);
    applyAltToMatrix(matrix, n, n,  f, g);
    printMatrix(matrix, n, n);
    deleteMatrix(matrix, n, n);

    std::cin.ignore();
}

int main() {
    
    testMatrix<int>(doubleUp, tripleUp);
    testMatrix<int>(doubleUp, tripleUp);
    testMatrix<double>(tripleUp, doubleUp);
    testMatrix<double>(tripleUp, doubleUp);
    testMatrix<char>(upperCase, lowerCase);
    testMatrix<char>(upperCase, lowerCase);

    return 0;
}
