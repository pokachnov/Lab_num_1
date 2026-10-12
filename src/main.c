#include <stdio.h>
#include "arrays.h"
#include "arrays.c"
#include <windows.h>

int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double A[CAPACITY];
    double B[CAPACITY];
    double p[3];
    int n, m, pos, res;

    n = read_array(A, CAPACITY);
    if (n == 0) {
        printf("ошибка ввода\n");
        return 1;
    }
    m = read_length(CAPACITY);
    if (m == 0) {
        printf("ошибка ввода\n");
        return 1;
    }
    if (!read_params(p)) {
        printf("ошибка ввода\n");
        return 1;
    }
    build_b(B, m, p[0], p[1], p[2]);

    printf("A:\n");
    print_array(A, n);
    printf("B:\n");
    print_array(B, m);

    printf("B после удаления:\n");
    pos = find_first_max(B, m);
    if (pos < 0) {
        printf("операция невозможна\n");
    } else {
        m = remove_negative_before(B, m, pos);
        if (m == 0)
            printf("массив пуст\n");
        else
            print_array(B, m);
    }

    printf("A после вставки:\n");
    res = insert_copy_last(A, n);
    if (res < 0) {
        printf("нет места для вставки\n");
    } else {
        n = res;
        print_array(A, n);
    }

    printf("A после изменения:\n");
    replace_small_abs(A, n);
    print_array(A, n);

    return 0;
}
