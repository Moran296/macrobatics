
# C/C++ Macrobatics - A talk about the preprocessor WIP

## Abstract
This is a talk about the C/C++ preprocessor. It will cover the basics of the preprocessor and some more advanced stuff. The goal is to show how the preprocessor can be used to do some cool stuff and what to expect when reading code that uses the preprocessor.

The examples are all relevant and inspired from real life code.

The talk will be given to embedded developers in the company I work for. The talk will be given in Hebrew.

- [C/C++ Macrobatics - A talk about the preprocessor WIP](#cc-macrobatics---a-talk-about-the-preprocessor-wip)
  - [Abstract](#abstract)
  - [Introduction](#introduction)
    - [the\_basics\_1.c](#the_basics_1c)
    - [the\_basics\_2.c](#the_basics_2c)
  - [First steps - variadic macros](#first-steps---variadic-macros)
  - [Overloading functions](#overloading-functions)
    - [Overloading by number of arguments](#overloading-by-number-of-arguments)
    - [Overloading by type of argument](#overloading-by-type-of-argument)
  - [Code generation with X macros](#code-generation-with-x-macros)
  - [Bonus](#bonus)


## Introduction
- Show the [preprocessor iceberg](https://jadlevesque.github.io/PPMP-Iceberg/)
- The preprcessor uses are wide and deep, we will only scratch the surface!
- A small quiz about the top of the iceberg!
- Show the basics to make sure we are all on the same page
*  **Don't forget to explain how to compile only in the preprocessor with -P -E**
### the_basics_1.c
 - macro traps, paranthesis, do while(0)
### the_basics_2.c
 - stringification, token pasting, variadic macros


---
## First steps - variadic macros
Let's create a nice macro to make our lives easier when dealing with multi arguments functions.

* I wish I was writing python... I would just use named arguments!!!
* I would like to be able to call a function like this:
```c
connect_to_server(.host = "google.com", .port = 80);
```
* I would also like to have default args, so I can call the function like this:
```c
connect_to_server(.host = "google.com");
```

* Show named_params.c to demonstrate the power of the variadic macros

---
## Overloading functions

### Overloading by number of arguments

I would like to be able to call different functions based on the number of arguments I pass to the macro.
```c
    Add(1, 2) ==> Add_2(int a, int b)
    Add(1, 2, 3) ==> Add_3(int a, int b, int c)
```
* first step let's look at count_args.c to see how we can count the number of arguments
    - Here we will learn about the __VA_OPT__ feature
* second step let's look at overload_by_arg_num.c to see how we can use the number of arguments to call different functions
    - Here we will learn about the phases of the preprocessor work
* Bonus - show real example of this technique in nrf log?

### Overloading by type of argument
WIP
- talk about _Generic in C11

## Code generation with X macros
WIP
- talk about X macros
- show real examples of X macros
    - ShoobyDB
    - Protobuf

## Bonus
If we have time we can also show the following:
- [headerlessc](https://github.com/milgra/headerlessc) with #if __INCLUDE_LEVEL__ == 0
- #line
- default args with ... (show shoobyDB limits)







