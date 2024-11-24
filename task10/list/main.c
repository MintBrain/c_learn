#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct list* mylist = list_node_create(3);
    list_add_front(&mylist, 2);
    list_add_front(&mylist, 1);
    list_print(mylist);
    print_int64(list_sum(mylist));
    printf("\n");
    print_int64(list_length(mylist));
    printf("\n\n");

    struct list *reversed_list = list_reverse(mylist);
    list_print(reversed_list);
    print_int64(list_sum(reversed_list));
    printf("\n");
    print_int64(list_length(mylist));
    printf("\n\n");

    list_destroy(mylist);
    mylist = NULL;
    list_print(mylist);
    print_int64(list_length(mylist));
    printf("\n\n");

    struct list * readed_list = list_read();
    list_print(readed_list);

    return 0;
}