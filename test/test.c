#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Daoqi.c"
//#include "../game.c"
#include "../initial.c"
//#include "../main.h"

#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestDB.h>
#include <SDL2/SDL.h>
#include <assert.h>

int suite_success_init(void){
    return 0;
}

int suite_success_clean(void){
    return 0;
}
void test_fun1(void){
    CU_ASSERT_EQUAL(cell_judge(1, 2),1);
    CU_ASSERT_EQUAL(cell_judge(1, 3),1);
    CU_ASSERT_EQUAL(cell_judge(1, 1),0);
    CU_ASSERT_EQUAL(cell_judge(1, 4),0);
    CU_ASSERT_EQUAL(cell_judge(0, 1),0);
    CU_ASSERT_EQUAL(cell_judge(0, 2),0);
    CU_ASSERT_EQUAL(cell_judge(0, 3),1);
    CU_ASSERT_EQUAL(cell_judge(0, 4),0);
}
void test_fun2(void){
    int length,width;
    initGrid(&length,&width,"test1.txt");
    CU_ASSERT_EQUAL(length,5);
    CU_ASSERT_EQUAL(width,5);
}

void test_fun3(void){
    int length,width;
    initGrid(&length,&width,"test2.txt");
    CU_ASSERT_EQUAL(length,3);
    CU_ASSERT_EQUAL(width,4);
}

void test_fun4(void){
    int length,width;
    initGrid(&length,&width,"test3.txt");
    CU_ASSERT_NOT_EQUAL(length,3);
    CU_ASSERT_NOT_EQUAL(width,4);
}

CU_TestInfo test_cases1[] = {
        {"The cell and its neighbour cell test", test_fun1},
        CU_TEST_INFO_NULL
};
CU_TestInfo test_cases2[] = {
        {"The initialize test", test_fun2},
        {"The initialize test", test_fun3},
        {"The initialize test", test_fun4},
        CU_TEST_INFO_NULL
};

CU_SuiteInfo suites[] = {
        {"test_cases1:", suite_success_init, suite_success_clean, NULL, NULL, test_cases1},
        {"test_cases2:", suite_success_init, suite_success_clean, NULL, NULL, test_cases2},
        CU_SUITE_INFO_NULL
};

int main(int argc, char **argv)
{
    if (CU_initialize_registry()) {
        fprintf(stderr, " Initialization of Test Registry failed. ");
        exit(EXIT_FAILURE);
    } else {
        assert(NULL != CU_get_registry());
        assert(!CU_is_test_running());
        if (CUE_SUCCESS != CU_register_suites(suites)) {
            exit(EXIT_FAILURE);
        }
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
    }
    return 0;
}