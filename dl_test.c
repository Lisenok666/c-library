#include <assert.h>
#include <stdio.h>
#include "color.h"
#include "dl_test.h"


int test_create(void)
{
    printf("%s: Create list\n", __FUNCTION__);
    work_list* listok = list_new();
    if (NULL == listok)
    {
        printf("%s: Fail to create list\n", __FUNCTION__);
        return -1;
    }


    if (NULL != listok->head)
    {      
        printf("%s: First element is not NULL\n", __FUNCTION__);
        return -2;
    }

    if (listok->list_size != 0) 
    {
        printf("%s: Size of list is not 0\n", __FUNCTION__);
        return -3;
    }
    printf("%s: Delete list\n", __FUNCTION__);
    list_delete(listok);
    return 0;
}

/* Info about all tests of function unishift

 !!!!  If programm return -1, then you have problem with creation of list   !!!!

Errors witch return values more then -7  heppend, when we add element in  empety list
Other happend in not empety list
Programm check
Work with pointer of elements
With size of list
With pointer of list
*/
int test_unishift(void)
{
    work_list* listok = list_new();
    if (test_create != 0)
    {
        printf("%s: Fail to create list\n", __FUNCTION__);
        return -1;
    }
    int size_list = listok->list_size;
    unishift(listok, 7);
    size_list++;
    if (NULL == listok->head)
    {
        printf("%s: Fail to add element\n", __FUNCTION__);
        return -2;
    }
    if (size_list != listok->list_size)
    {
        printf("%s: Fail size of list don't change or change uncorrect\n", __FUNCTION__);
        return -3;
    }
    if (NULL != listok->head->next )
    {
        printf("%s: Fail with pointer next of element that you add\n", __FUNCTION__);
        return -4;
    }
    if (NULL != listok->head->prev)
    {
        printf("%s: Fail with pointer prev of element that you add\n", __FUNCTION__);
        return -5;
    }
    if (listok->head->value != 7)
    {
        printf("%s: Fail with value of element that you add\n", __FUNCTION__);
        return -6;
    }
    unishift(listok, 7);
    size_list++;
    if (NULL == listok->head)
    {
        printf("%s: Fail to create list\n", __FUNCTION__);
        return -7;
    }
    if (listok->head->value != 7) 
    {
        printf("%s: Fail with value of element that you add, when in list more then 2 elements\n", __FUNCTION__);
        return -8;
    }
    if (size_list != listok->list_size)
    {
        printf("%s: Fail to create list\n", __FUNCTION__);
        return -9;
    }
    if (NULL != listok->head->next)
    {
        printf("%s: Fail with pointer of element that you add, when in list more then 2 elements\n", __FUNCTION__);
        return -10;
    }
    if (listok->head->next->prev == listok->head)
    {
        printf("%s: Fail with  prev_pointer of second element which is different topointer to first, when in list more then 2 elements\n", __FUNCTION__);
        return -11;
    }
    if (NULL != listok->head->prev)
    {
        printf("%s: Fail with prev_pointer of element that you add, when in list more then 2 elements\n", __FUNCTION__);
        return -12;
    }
    if (NULL == listok->head->next->next)
    {
        printf("%s: Fail with pointer of  second element, when in list more then 2 elements\n", __FUNCTION__);
        return -13;
    }
    return 0;
}

int test_remove(void)
{
    return 0;
}

// Test using assert
/*void test_assert(void)
{
    work_list* listok = list_new();
    //assert(NULL != list);
    printf("%s: Create list\n", __FUNCTION__);

    //assert(NULL == listok->first);

    printf("%s: Delete list\n", __FUNCTION__);
    list_delete(listok);
}

void init_tests()
{
    init_color();
}

void deinit_tests()
{
    deinit_color();
}*/

void run_test(int num, char* description, TEST test)
{
    printf("TEST #%d %s:\t\tExecution\n", num, description);
    int result = test();
    printf("TEST #%d %s:\t\tExecution completed with code 0x%08x\n", num, description, result);
    printf("TEST #%d %s:\t\t", num, description);
    (result == 0) ? print_color(COLOR_GREEN, "PASS\n") : print_color(COLOR_RED, "FAIL\n");
}

int run_all_tests()
{
    printf("Run all tests:\n");
    int test_num = 0;

    run_test(++test_num, "Create list", test_create);
    run_test(++test_num, "Add element", test_add);
    run_test(++test_num, "Remove element", test_remove);
}
#include <stdio.h>
#include <malloc.h>
#include "Header.h"

int  main(int argc, char** argv)
{
    run_all_tests();
    return 0;

}