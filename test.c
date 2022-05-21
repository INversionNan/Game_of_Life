#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <CUnit/TestDB.h>
#include <assert.h>

int suite_success_init(void){
    return 0;
}

int suite_success_clean(void){
    return 0;
}
void test_fun1(void){

}
void test_fun2(void){
    
}
CU_TestInfo test_cases1[] = {
        {"test1", test_fun1},
        {"test2", test_fun2},
        CU_TEST_INFO_NULL
};
CU_TestInfo test_cases2[] = {
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
#if 0
        /**** Automated Mode *****************/
		CU_set_output_filename("TestMax");
		CU_automated_run_tests();
		CU_list_tests_to_file();
#else
        //***** Basice Mode *******************
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
#endif
        CU_cleanup_registry();
        return CU_get_error();
    }
    return 0;
}


