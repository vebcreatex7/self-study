#include <iostream>
#include <algorithm>




int** create_matrix(int a, int b) {
    int** matrix = new int* [a];
    for (size_t i = 0; i != a; ++i) {
        matrix[i] = new int[b];
    }
    return matrix;
}


void free_matrix(int** matrix, size_t rows) {
    for (int i = 0; i != rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}





void swap (int** p, int** q, size_t cols) {

    int* tmp = new int [cols];
    int i = 0;
    for (int* z = *p; z != *p + cols; ++z, i++) {
        tmp[i] = *z;
    }

/*
    //PRINT
    std::cout << "tmp:\n";
    for (size_t j = 0; j != cols; ++j)
        std::cout << tmp[j] << ' ';
    std::cout << '\n';
*/
    
    
    for (int* z = *p, *k = *q; z!= *p + cols; ++z, ++k)
        *z = *k;



/*
    //PRINT
    std::cout << "NEW P\n";
    for (int* z = *p; z != *p + cols; ++z, i++)
        std::cout << *z << ' ';
    std::cout << '\n';
*/

    i = 0;
    for (int* z = *q; z != *q + cols; ++z, i++)
        *z = tmp[i];
/*
    //PRINT
    std::cout << "NEW Q\n";
    for (int* z = *q; z != *q + cols; ++z, i++)
        std::cout << *z << ' ';
    std::cout << '\n';
*/
    delete [] tmp;

    
}





void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0];
    size_t min_row = 0;
    for (size_t i = 0; i != rows; ++i) {
        for (int j = 0; j != cols; ++j) {
            if (m[i][j] < min) {
                min = m[i][j];
                min_row = i;
            }
        }
    }
    
    swap(m, m + min_row, cols);
    

}








int main() {
    size_t rows, cols;
    std::cin >> rows >> cols;
    int** matrix = create_matrix(rows, cols);

    
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j)
            std::cin >> matrix[i][j];
    }

    swap_min(matrix, rows, cols);

/*

    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }*/

    
    
    for (int** arr = matrix; arr != matrix + rows; ++arr) {
        for (int* p = *arr; p != *arr + cols; ++p) {
            std::cout << *p << ' ';
        }
        std::cout << '\n';
    } 

    
    free_matrix(matrix, rows);
  



}