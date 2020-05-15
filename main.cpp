#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Nº1
    int n, m, inp;
    // вводятся размеры двумерного массива, а затем сам массив
    cout << "Введите размеры матрицы (m, n)" << '\n';
    cin >> m >> n;
    vector<int> vec(n*m), row; // промежуточный вектор (flattened массив) и строчка для ввода
    vector<vector<int>> matrix, newMatrix(m);
    // объявляем итераторы
    vector<vector<int>>::iterator im, inew;
    vector<int>::iterator iv, irow;

    // вводим значения массива с клавиатуры
    cout << "Введите матрицу" << "\n";
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> inp;
            row.push_back(inp);
        }
        matrix.push_back(row);
        row.clear();
    }
    cout << "\n\n";
    // выводим исходную матрицу
    im = matrix.begin();
    while (im != matrix.end()) {
        irow = (*im).begin(); // рассматриваем построчно
        while (irow != (*im).end()) {
            cout << *irow << " ";
            ++irow;
        }
        cout << "\n";
        ++im;
    }
    cout << "\n\n";
    // считаем итераторы для flattened вектора b
    for (im = matrix.begin(); im != matrix.end(); im++) {
        for (irow = (*im).begin(); irow != (*im).end(); irow++) {
            iv = vec.begin() + (im - matrix.begin()) * n + (irow - (*im).begin());
            *iv=*irow;
        }
    }
    // выводим вектор
    iv = vec.begin();
    while (iv != vec.end()) {
        cout << *iv << " ";
        ++iv;
    }
    cout << "\n\n\n";

    for (inew = newMatrix.begin(); inew != newMatrix.end(); inew++)  (*inew).resize(n);
    // считаем итераторы новой матрицы (преобразование "обратно")
    inew = newMatrix.begin();
    irow = (*inew).begin();
    for (iv = vec.begin(); iv != vec.end(); iv++) {
        inew = newMatrix.begin() + (iv - vec.begin()) / n;
        irow = (*inew).begin() + (iv - vec.begin()) % n;
        *irow = *iv;
    }
    // выводим новую матрицу
    inew = newMatrix.begin();
    while (inew != newMatrix.end()){
        irow = (*inew).begin();
        while (irow != (*inew).end()) {
            cout << *irow << " ";
            ++irow;
        }
        cout << "\n";
        ++inew;
    }
    return 0;
}
