#include <stdio.h>    //printf
#include <sys/time.h> //gettimeofday
int failed = 0;
int testcount = 0;
struct timeval TestBegin;
struct timeval TestEnd;

int maxsecs = -1;
int maxusecs = 0;
// readabilty macros
#define COL_RED "\033[31m"
#define COL_GRN "\033[32m"
#define COL_YLW "\033[33m"
#define COL_CYN "\033[36m"
#define COL_CLR "\033[39m"
#define BOLD "\033[1m"
#define COL_BOLD_CLR "\033[0m"

//arguments 
//header text printed between brackets is bold and has the color of col 
//col a string from color escape code
//rest of arguments are passed into a new printf call
//then a new line is printed
#define printline(header, col, ...)                                      \
  printf("[" col BOLD header COL_BOLD_CLR "] ");                               \
  printf(__VA_ARGS__);\
  printf("\n")

void testfail(char *Expr, char *ErrMsg) {
  printline("FAIL",COL_RED,"%s",ErrMsg);
  printline("Expr",COL_YLW,"%s",Expr);

  if (maxsecs != -1 && TestEnd.tv_sec - TestBegin.tv_sec > maxsecs) {
    if (TestEnd.tv_usec - TestBegin.tv_usec > maxusecs) {
      printline("Warn",COL_YLW,"Took more than the time limit(%d.%ds)",
                maxsecs, maxusecs);
    }
  }
  printline("Took",COL_YLW,"%ld.%lds",
         TestEnd.tv_sec - TestBegin.tv_sec,
         TestEnd.tv_usec - TestBegin.tv_usec);
  failed++;
}

void testpass(char *Expr, char *ErrMsg) {
  if (maxsecs == -1)
    return;
  if (TestEnd.tv_sec - TestBegin.tv_sec > maxsecs) {
    if (TestEnd.tv_usec - TestBegin.tv_usec > maxusecs) {
      printline("Pass",COL_GRN,"");
      printline("Warn",COL_YLW,"Took: %ld.%lds",
             TestEnd.tv_sec - TestBegin.tv_sec,
             TestEnd.tv_usec - TestBegin.tv_usec);
      printline("Expr",COL_YLW,"%s",Expr);
    }
  }
}

// a warning is given if the test execution time takes more than sec seconds and
// usec miliseconds if sec is set to -1 no warning is given
#define TimeLimit(sec, usec)                                                   \
  maxsecs = sec;                                                               \
  maxusecs = usec
// Expr expression to be tested
// ErrMsg message to be printed if Expr is false
#define Test(Expr, ErrMsg)                                                     \
  gettimeofday(&TestBegin, NULL);                                              \
  if (!(Expr)) {                                                               \
    gettimeofday(&TestEnd, NULL);                                              \
    testfail(#Expr, ErrMsg);                                                   \
  } else {                                                                     \
    gettimeofday(&TestEnd, NULL);                                              \
    testpass(#Expr, ErrMsg);                                                   \
  }                                                                            \
  ++testcount
