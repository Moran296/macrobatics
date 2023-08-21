
# C/C++ Macrobatics - A talk about the preprocessor WIP

## Abstract
This is a talk about the C/C++ preprocessor. It will cover the basics of the preprocessor and some more advanced stuff. The goal is to show how the preprocessor can be used to do some cool stuff and what to expect when reading code that uses the preprocessor.

The talk will be given to embedded developers in the company I work for. The talk will be given in Hebrew.

## Presentation
1. Start with showing the [preprocessor iceberg](https://jadlevesque.github.io/PPMP-Iceberg/)
  - The preprcessor uses are wide and deep, we will only scratch the surface
  - A small quiz about the top of the iceberg
  - show the basics to make sure we are all on the same page
2. We can now start to advance slowly
    - Show named arguments, this demonstrates the power of the variadic macros
    - Show the arg_num, this starts to get tricky and shows the new __VA_OPT__ feature
3. Warning about # in macros
    - CAT and CAT2, why?
    - Phases of the preprocessor work
    - Find and show an example in real code?
4. Time to get a bit dirty
    -  Show X macros, this is a very powerful technique that can be used to generate code
    - Show real uses of X macros like: printing enum values, protobuf descriptors, etc.
5. Show the new _Generic feature, this is a very powerful feature that can be used to create generic code
6. Bonuses
    - [headerlessc](https://github.com/milgra/headerlessc) with #if __INCLUDE_LEVEL__ == 0















