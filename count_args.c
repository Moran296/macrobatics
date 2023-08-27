// https://embeddedartistry.com/blog/2020/07/27/exploiting-the-preprocessor-for-fun-and-profit/#:~:text=Variadic%20Macros%20and%20Overloading

#define COUNT_ARGS(...) SEQ_ARGS(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define SEQ_ARGS(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N

int x1 = COUNT_ARGS(x);
int x2 = COUNT_ARGS(x, y);
int x3 = COUNT_ARGS(x, y, z);

// what happened here? how do we solve this?..
int x0 = COUNT_ARGS();
/* __VA_ARGS__ is empty but we still have a comma
 that is unrelated to __VA_ARGS__ and is considered as one argument */

/*








solution:
use the new __VA_OPT__ macro!
*/

// #define COUNT_ARGS_WITH_OPT(...) SEQ_ARGS(__VA_ARGS__ __VA_OPT__(, ) 8, 7, 6, 5, 4, 3, 2, 1, 0)
// int real_x0 = COUNT_ARGS_WITH_OPT();
