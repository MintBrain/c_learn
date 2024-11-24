#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 11

void print_array(int32_t *array, int32_t *lim)
{
    for (int32_t *i = array; i < lim; ++i)
    {
        printf("%d ", *i);
    }
    printf("\n");
}

void array_reverse(int32_t *array, size_t size)
{
    int32_t temp;
    for (size_t i = 0; i != size / 2; ++i)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void array_reverse_ptr(int32_t *array, int32_t *lim)
{
    int32_t temp;
    int32_t *oposite_el_ptr = 0;
    for (int32_t *i = array; i != array + ((lim - array) / 2); ++i)
    {
        temp = *i;
        oposite_el_ptr = (lim - (i - array) - 1);
        *i = *oposite_el_ptr;
        *oposite_el_ptr = temp;
    }
}

void reverse_task()
{
    int32_t array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    printf("Array to reverse  = ");
    print_array(array, array + SIZE);

    printf("Reverse array     = ");
    array_reverse(array, SIZE);
    print_array(array, array + SIZE);

    // Reverse back
    array_reverse(array, SIZE);

    printf("Reverse_ptr array = ");
    array_reverse_ptr(array, array + SIZE);
    print_array(array, array + SIZE);
}

void array_sort(int32_t *array, size_t size)
{
    for (size_t i = 0; i != size - 1; ++i)
    {
        for (size_t j = 0; j <= size - 2 - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int32_t temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void array_sort_ptr(int32_t *array, int32_t *lim)
{
    bool swapped = true;
    int32_t temp;
    int32_t *next_el_ptr = 0;

    while (swapped)
    {
        swapped = false;
        for (int32_t *i = array; i < lim - 1; ++i)
        {
            temp = *i;
            next_el_ptr = i + 1;
            if (temp > *next_el_ptr)
            {
                *i = *next_el_ptr;
                *next_el_ptr = temp;
                swapped = true;
            }
        }
    }
}

void sort_task()
{
    int32_t array[SIZE] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printf("Array to sort = ");
    print_array(array, array + SIZE);

    printf("Sorted array  = ");
    array_sort(array, SIZE);
    print_array(array, array + SIZE);

    printf("\n");
    int32_t array2[SIZE] = {5, 4, 1, 7, 10, 2, 9, 11, 6, 8, 3};
    printf("Array to sort_ptr = ");
    print_array(array2, array2 + SIZE);

    printf("Sorted_ptr array  = ");
    array_sort_ptr(array2, array2 + SIZE);
    print_array(array2, array2 + SIZE);
}

int main()
{
    reverse_task();
    printf("\n");
    sort_task();

    return 0;
}