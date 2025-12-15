#include<stdio.h>
#include <string.h>
#define TEST_BUILD
#include "custode.c"   /* your full code above, but wrap its main/start in #ifndef TEST_BUILD */

/* Helper to reset in-memory data for tests */
void resetData() {
    categoryCount = 0;
    itemCount = 0;
}


/* Category + Item CRUD */

int test4_addCategory_increments_count() {
    resetData();

    /* For manual run, type: Electronics */
    printf("\n[Member2] Type: Electronics⏎ when asked\n");
    addCategory();

    int actual   = (categoryCount == 1 &&
                    categories[0].id == 1 &&
                    strcmp(categories[0].name, "Electronics") == 0);
    int expected = 1;
    int success  = (actual == expected);

    printf("Member2_test4_addCategory -> expected:%d actual:%d success:%d\n",
           expected, actual, success);
    return success;
}

int test5_findItemIndexById() {
    resetData();
    items[0].id = 1;
    strcpy(items[0].name, "Keyboard");
    items[1].id = 2;
    strcpy(items[1].name, "Mouse");
    itemCount = 2;

    int idx1 = findItemIndexById(1);
    int idx2 = findItemIndexById(2);
    int idx3 = findItemIndexById(99);

    int actual   = (idx1 == 0 && idx2 == 1 && idx3 == -1);
    int expected = 1;
    int success  = (actual == expected);

    printf("Member2_test5_findItemIndexById -> expected:%d actual:%d success:%d\n",
           expected, actual, success);
    return success;
}

int test6_deleteItem_shifts_array() {
    resetData();
    items[0].id = 1; strcpy(items[0].name, "A");
    items[1].id = 2; strcpy(items[1].name, "B");
    items[2].id = 3; strcpy(items[2].name, "C");
    itemCount = 3;

    /* simulate delete ID=2 using your deleteItem logic core */
    int idx = findItemIndexById(2);
    for (int i = idx; i < itemCount-1; i++)
        items[i] = items[i+1];
    itemCount--;

    int actual   = (itemCount == 2 &&
                    items[0].id == 1 &&
                    items[1].id == 3);
    int expected = 1;
    int success  = (actual == expected);
printf("Member2_test6_deleteItem_shifts_array -> expected:%d actual:%d success:%d\n",
           expected, actual, success);
    return success;
}

int main(){
test4_addCategory_increments_count();
    test5_findItemIndexById();
    test6_deleteItem_shifts_array();


return 0;



}
