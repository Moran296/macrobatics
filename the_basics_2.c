// We can have variadic macros!
#define PRINT(...) printf(__VA_ARGS__)

// We can stringify a macro!
#define STRINGIFY(x) #x

// We can concatenate tokens!
#define CONCAT(x, y) x##y

int main()
{
    PRINT("hello %s\n", "world");

    PRINT("hello %s\n", STRINGIFY(world));

    PRINT(CONCAT("hello ", "world"));
}