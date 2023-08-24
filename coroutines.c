#define coroutine_begin static int state = 0; switch (state) { case 0:
#define coroutine_yield(x) do { state = __LINE__; return x; case __LINE__:; } while (0)
#define coroutine_end } state = 0;

#include <stdio.h>
#include <unistd.h>

int producer()
{
    for (int i = 0; i < 10; i++)
    {
        yield i;
    }

    printf("done producing\n");
    return -1;
}

int producer()
{
    static int state = 0;
    switch(state) {
    static int i = 0;
    for (; i < 10; i++)
    {
        state = 1;
        return i;
        case 1:;
    }

    i = 0;

    }

    state = 0;
    printf("done producing\n");
    return -1;
}

int producer()
{
    coroutine_begin
    static int i = 0;
    for (; i < 10; i++)
    {
        coroutine_yield(i);
    }
    printf("done producing\n");
    i = 0;

    coroutine_end
    return -1;
}


int main() {
    while (1)
    {
        int x = producer();
        printf("got %d\n", x);
        sleep(1);
    }

    return 0;
}









