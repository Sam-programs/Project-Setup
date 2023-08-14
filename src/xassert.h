#ifdef DEBUG
#define xassert(Expr, ErrMsg)                                                  \
  if (!(Expr)) {                                                               \
    printf("[\033[31mFAIL\033[0m] %s\n", ErrMsg);                              \
    printf("[\033[34mFile\033[0m] %s\n", __FILE__);                            \
    printf("[\033[34mLine\033[0m] %d\n", __LINE__);                            \
    printf("[\033[34mExpr\033[0m] %s\n", #Expr);                               \
    abort();                                                                   \
  }                                                                            
#else
#define xassert(Expr, ErrMsg) ;
#endif
