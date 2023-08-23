
#include <stdio.h>

// We could present a crazy kind of macro to branch according to the arg type
// but C11 already gave us a solution for that:

// wtf is _Generic?
#define ADD(PARAM) _Generic((PARAM), \
    int: add_int, \
    float: add_float, \
    double: add_double, \
    default: add_default \
)(PARAM)

/*
  _Generic is a compile-time operator in the same family as sizeof and _Alignof.
  It accepts two main parameters: an expression (which will not be evaluated at runtime),
  and a type/expression association list that looks a bit like a switch block.
  _Generic gets the overall type of the expression and then "switches" on it to
  select the end result expression in the list for its type:
*/

int add_int(int a) {
    printf("int\n");
    return a + 1;
}

float add_float(float a) {
    printf("float\n");
    return a + 1.0f;
}

double add_double(double a) {
    printf("double\n");
    return a + 1.0;
}

int add_default(void* a) {
    printf("something else\n");
    return 0;
}

int main() {
    float f = 1.0f;
    int a = ADD(1);
    float b = ADD(f);
    double c = ADD((double)1.0);
    int d = ADD("hello");
}






