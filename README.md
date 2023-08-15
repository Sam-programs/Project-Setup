# Project-Setup
every .c file in src gets compiled and linked  
tests also link to all .c files  
put your tests in run_tests in test.c  

the default compiler is clang and debugger lldb  
default compile flags:  
-g -Wall -Wextra -Werror -pedantic -Wshadow -Wno-unused-parameter -Wno-error=unused-variable  
u can change them in the Makefile

