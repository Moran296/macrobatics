#define COUNT_ARGS(...) SEQ_ARGS(__VA_ARGS__ __VA_OPT__(, ) 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define SEQ_ARGS(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N




int add_0() {
    return 0;
}

int add_1(int a) {
    return a + 1;
}

int add_2(int a, int b) {
    return a + b;
}

int add_3(int a, int b, int c) {
    return a + b + c;
}

int add_4(int a, int b, int c, int d) {
    return a + b + c + d;
}


// Who knows what ## stands for in macroism?


// What does this macro generates? why doesnt it work?
#define ADD_NOT_WORKING(...) add_##COUNT_ARGS(__VA_ARGS__)(__VA_ARGS__)

// Let's explain how ## is expanded:
// https://en.wikipedia.org/wiki/C_preprocessor#:~:text=to%20the%20division.-,Order%20of%20expansion,-%5Bedit%5D
// #define CAT_2_(a, b) a##b
// #define CAT_2(a, b) CAT_2_(a, b)
// #define ADD_WORKING(...) CAT_2(add_, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)


int main() {

    int a3 = ADD_NOT_WORKING(1, 2, 3);
    int a2 = ADD_NOT_WORKING(1, 2);
    int a1 = ADD_NOT_WORKING(1);
    int a0 = ADD_NOT_WORKING();
}


// what will happen here?
// #define HELLO "world"
// CAT_2_(HE, LLO)