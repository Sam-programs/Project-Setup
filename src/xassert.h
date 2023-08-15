#define COL_RED "\033[31m"
#define COL_GRN "\033[32m"
#define COL_YLW "\033[33m"
#define COL_CYN "\033[36m"
#define COL_BLU "\033[34m"
#define COL_CLR "\033[39m"
#define BOLD "\033[1m"
#define COL_BOLD_CLR "\033[0m"

// arguments
// header text printed between brackets is bold and has the color of col
// col a string from color escape code
// rest of arguments are passed into a new printf call
// then a new line is printed
#define printline(header, col, ...)                                            \
  printf("[" col BOLD header COL_BOLD_CLR "] ");                               \
  printf(__VA_ARGS__);                                                         \
  printf("\n")
#ifdef DEBUG
#define xassert(Expr, ErrMsg)                                                  \
  if (!(Expr)) {                                                               \
    printline("ASSERT", COL_RED, "%s", ErrMsg);                                \
    printline("File", COL_BLU, "%s", __FILE__);                                \
    printline("Line", COL_BLU, "%d", __LINE__);                                \
    printline("Expr", COL_YLW, "%s", #Expr);                                   \
    abort();\
}
#else
#define xassert(Expr, ErrMsg) ;
#endif
