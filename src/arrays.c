#include <stdio.h>
#include <math.h>
#include "arrays.h"

/* ---------- Ввод ---------- */

int read_array(double A[], int capacity)
{
    int n;
    int i;

    if (scanf("%d", &n) != 1)
        return 0;
    if (n < 1 || n > capacity)
        return 0;
    for (i = 0; i < n; i++) {
        if (scanf("%lf", &A[i]) != 1)
            return 0;
    }
    return n;
}

int read_length(int capacity)
{
    int m;

    if (scanf("%d", &m) != 1)
        return 0;
    if (m < 1 || m > capacity)
        return 0;
    return m;
}

int read_params(double p[])
{
    if (scanf("%lf %lf %lf", &p[0], &p[1], &p[2]) != 3)
        return 0;
    return 1;
}

/* ---------- Модификация ---------- */

void build_b(double B[], int m, double a, double x, double h)
{
    int i;

    for (i = 0; i < m; i++)
        B[i] = 1.25 * sin(3 * a * x - i * h);
}

int find_first_max(const double B[], int n)
{
    int i;
    int pos;

    if (n < 1)
        return -1;
    pos = 0;
    for (i = 1; i < n; i++) {
        if (B[i] > B[pos])      /* строгое сравнение: берется первый максимум */
            pos = i;
    }
    return pos;
}

int remove_negative_before(double B[], int m, int pos)
{
    int i;
    int k = 0;                  /* сколько элементов оставлено */

    for (i = 0; i < m; i++) {
        if (i < pos && B[i] < 0)
            continue;           /* элемент удаляется: не переписываем */
        B[k] = B[i];
        k++;
    }
    return k;
}

int insert_copy_last(double A[], int n)
{
    if (n >= CAPACITY)
        return -1;
    A[n] = A[n - 1];            /* вставка в конец: сдвигать нечего */
    return n + 1;
}

void replace_small_abs(double A[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (fabs(A[i]) < 1)
            A[i] = 1;
    }
}

/* ---------- Вывод ---------- */

void print_array(const double A[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%.3lf", A[i]);
    }
    printf("\n");
}
