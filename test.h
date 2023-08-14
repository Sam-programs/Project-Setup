#include <stdint.h>   //INT32_MAX
#include <stdio.h>    //printf
#include <sys/time.h> //gettimeofday
int failed = 0;
int testcount = 0;
struct timeval TestBegin;
struct timeval TestEnd;

// readabilty macros
#define COL_RED "\033[31m"
#define COL_GRN "\033[32m"
#define COL_YLW "\033[33m"
#define COL_CYN "\033[36m"
#define COL_BOLD_CLR "\033[0m"
#define COL_CLR "\033[39m"
#define BOLD "\033[1m"

void testfail(char *Expr, char *ErrMsg, int maxsecs) {
  gettimeofday(&TestEnd, NULL);
  printf("[" COL_RED "FAIL" COL_BOLD_CLR "] %s\n", ErrMsg);

  if (maxsecs != 0 && TestEnd.tv_sec - TestBegin.tv_sec > maxsecs)
    printf("[" COL_YLW "Warn" COL_BOLD_CLR
           "] Took more than the time limit(%d)\n",
           maxsecs);

  printf("[" COL_YLW "Expr" COL_BOLD_CLR "] %s\n", Expr);
  printf("[" COL_YLW "Took" COL_BOLD_CLR "] %ld.%lds\n",
         TestEnd.tv_sec - TestBegin.tv_sec,
         TestEnd.tv_usec - TestBegin.tv_usec);
  failed++;
}

void testpass(char *Expr, char *ErrMsg, int maxsecs) {
  if (!maxsecs)
    return;
  gettimeofday(&TestEnd, NULL);
  if (TestEnd.tv_sec - TestBegin.tv_sec > maxsecs) {
    printf("[" COL_YLW "Warn" COL_BOLD_CLR "] Took:%ld.%lds\n",
           TestEnd.tv_sec - TestBegin.tv_sec,
           TestEnd.tv_usec - TestBegin.tv_usec);
    printf("[" COL_YLW "Expr" COL_BOLD_CLR "] %s\n", Expr);
  }
}

// Expr expression to be tested
// ErrMsg message to be printed if Expr is false
// MaxTime unit is seconds if excution of a test took more than MaxTime prints a warning
// 0 means no time limit
#define Test(Expr, ErrMsg, MaxTime)                                            \
  gettimeofday(&TestBegin, NULL);                                              \
  if (!(Expr))                                                                 \
    testfail(#Expr, ErrMsg, MaxTime);                                          \
  else                                                                         \
    testpass(#Expr, ErrMsg, MaxTime);                                          \
  ++testcount


