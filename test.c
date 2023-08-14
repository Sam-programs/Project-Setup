#include <stdlib.h>//exit
//provides the Test macro
#include "test.h"
//you just put Test(expression,error message,max time) to test if an expression is true 
//if expression is false the test fails
//error messages is a string and is printed when a test fails
//a warning is given if a test takes more than max time 
//0 max time gives no warnings
void run_tests(void){


}

__attribute__((constructor))
void testentry(int argc,char **argv){
  printf("[\033[1mTest\033[0m]\n");
  run_tests();
  printf(BOLD "[" COL_CYN "Done\033[39m] ");
  printf(COL_GRN "%d" COL_CLR " Tested | ",testcount);
  printf(COL_GRN "%d" COL_CLR " Passed | ",testcount - failed);
  printf(COL_RED "%d" COL_CLR " Failed   ",failed);
  printf("\n");
  exit(0);
}
