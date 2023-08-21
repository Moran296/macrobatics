
//============================================
// a good idea would be to put parentheses around the macro replacement list...
//============================================
#define SOME_CALC 10 - 5

#define SOME_ADVANCED_CALC 60 * SOME_CALC // ???

static int some_advanced_calc = SOME_ADVANCED_CALC;

//============================================
// a good idea is to use the do { ... } while(0) trick
//============================================
#define SEVERAL_PRINTS \
    printf("hello\n"); \
    printf("world\n");

#define SEVERAL_PRINTS_BETTER \
    do                        \
    {                         \
        printf("hello\n");    \
        printf("world\n");    \
    } while (0)

int main()
{

    // naive
    if (1)
        SEVERAL_PRINTS;
    else
        printf("no prints\n");

    // better
    if (1)
        SEVERAL_PRINTS_BETTER;
    else
        printf("no prints\n");
}