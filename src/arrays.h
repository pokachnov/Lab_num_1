#ifndef ARRAYS_H
#define ARRAYS_H

#define CAPACITY 20

/* Ввод */

/* Читает длину n и n элементов массива A (n должно быть от 1 до capacity).
   Возвращает n при успехе, 0 при ошибке ввода. */
int read_array(double A[], int capacity);

/* Читает длину m (от 1 до capacity).
   Возвращает m при успехе, 0 при ошибке ввода. */
int read_length(int capacity);

/* Читает параметры формулы a, x, h в p[0], p[1], p[2].
   Возвращает 1 при успехе, 0 при ошибке ввода. */
int read_params(double p[]);

/* ---------- Модификация (ничего не читают и не печатают) ---------- */

/* Заполняет B[0..m-1] по формуле B[i] = 1.25 * sin(3 * a * x - i * h). */
void build_b(double B[], int m, double a, double x, double h);

/* Ищет ориентир: индекс первого максимума в массиве длины n.
   Возвращает индекс или -1, если массив пуст. */
int find_first_max(const double B[], int n);

/* Удаляет из B на месте отрицательные элементы с индексами строго меньше pos
   (одним циклом, без вспомогательного массива).
   Возвращает новую длину массива (может быть 0). */
int remove_negative_before(double B[], int m, int pos);

/* Вставляет в конец A копию последнего элемента.
   Возвращает новую длину или -1, если нет места (n == CAPACITY). */
int insert_copy_last(double A[], int n);

/* Заменяет на 1 все элементы A, для которых fabs(A[i]) < 1.
   Длина массива не меняется. */
void replace_small_abs(double A[], int n);

/* Вывод */

/* Печатает n элементов через пробел с тремя знаками после запятой
   и переводом строки. */
void print_array(const double A[], int n);

#endif
