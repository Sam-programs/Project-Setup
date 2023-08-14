#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
//provides the Test macro
#include "test.h"
//you just put Test(expression) to test if an expression is true 
//and include headers from src/*
void run_tests(void){
 //Test(true, "should pass");
 //Test(false,"should fail");
}

__attribute__((constructor))
void testentry(int argc,char **argv){
  printf("[\033[1mTest\033[0m]\n");
  run_tests();
  printf("\033[1m[\033[36mDone\033[39m] ");
  printf("\033[32m%d\033[39m Tested | ",testcount);
  printf("\033[32m%d\033[39m Passed | ",testcount - failed);
  printf("\033[31m%d\033[39m Failed   ",failed);
  printf("\n");
  exit(0);
}
