/*
    X-Macros are a way to define a list of items in one place
     and then use that list in multiple places.

    It is a super useful technique that is used in many places for code generation.

    There are a lot of differnt ways to implement X macros, I show my favorite way.

    The most common example is an enum with a string representation:
*/

// Without X-Macros
enum color
{
    RED,
    GREEN,
    BLUE,
    NUM_COLORS
};

const char *to_string(enum color c)
{
    switch (c)
    {
    case RED:
        return "RED";
    case GREEN:
        return "GREEN";
    case BLUE:
        return "BLUE";
    default:
        return "INVALID";
    }
}

// I cannot do #define ColorToSting(...) because I cannot iterate over the variadic arguments (yet)

// With X-Macros
// We ask the user to define the enum that way
#define eColor(X) \
    X(RED)        \
    X(GREEN)      \
    X(BLUE)

// Take this line to the end of the file before copiling!!
STRINGED_ENUM(eColor);

// We need to define our macros, that can be used with the user's x macro (eColor)
#define STRINGED_ENUM(ENUM_LIST)                                \
    /*ENUM LIST will not be expanded as it got no arguments..*/ \
    enum ENUM_LIST                                              \
    {                                                           \
        ENUM_LIST(JUST_ENUM)                                    \
            NUM                                                 \
    };                                                          \
    /* now let's define the to_string function */               \
    const char *to_string(enum ENUM_LIST c)                     \
    {                                                           \
        switch (c)                                              \
        {                                                       \
            ENUM_LIST(CASE_AND_STRINGIFY)                       \
        default:                                                \
            return "INVALID";                                   \
        }                                                       \
    }

#define JUST_ENUM(X) X,
#define CASE_AND_STRINGIFY(X) \
    case X:                   \
        return #X;

// lets try to add const hex value to each enum!!
