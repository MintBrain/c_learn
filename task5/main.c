#include "string_functions.h"

int main()
{
    char s[] = "  abc  absc\tcasd\ndasd\n";
    printf("String: %s\n", s);
    printf("Words in string = %d\n\n", str_words(s));

    char s2[] = "asfbdksyb";
    char to_search = 's';
    printf("String: %s\n", s2);
    printf("Position of char \'%c\' = %d\n\n", to_search, str_pos(s2, to_search));

    char s3[] = "abc";
    char s3_1[] = "de";
    printf("String 1: %s\n", s3);
    printf("String 2: %s\n", s3_1);
    str_cat(s3, s3_1);
    printf("Concatenated strings = %s\n\n", s3);

    char s4[] = "adsasd";
    char s4_1[] = "dasd";
    printf("String 1: %s\n", s4);
    printf("String 2: %s\n", s4_1);
    str_cpy(s4, s4_1);
    printf("Copied string2 to string1 = %s\n\n", s4);

    char s5[] = "asdf";
    char s5_1[] = "asdf0";
    printf("String 1: %s\n", s5);
    printf("String 2: %s\n", s5_1);
    printf("Compared strings = %d\n\n", str_cmp(s5, s5_1));

    return 0;
}