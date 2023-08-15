# Project-Setup
every .c file in src gets compiled and linked  
tests also link to all .c files  
put your tests in run_tests in test.c  

the default compiler is clang and debugger lldb  
default compile flags:  
-g -Wall -Wextra -Werror -pedantic -Wshadow -Wno-unused-parameter -Wno-error=unused-variable  
u can change them in the Makefile  

# Testing Function
## Test(expression,error message) test if an expression is true 
if expression is false the test fails  
error messages is a string and is printed when a test fails  

## TimeLimit(sec,milsec)
if a test takes more than sec seconds and milsec milliseconds a warning is given   
if sec is set to -1 no warning is given  

