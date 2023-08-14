int failed = 0;
int testcount = 0;

#define Test(Expr,ErrMsg)\
  if(!(Expr)){\
   printf("[\033[31mFAIL\033[0m] %s\n",ErrMsg);\
   printf("[\033[31mExpr\033[0m] %s\n",#Expr);\
   failed++;\
  }\
  testcount++

