#Coding convention

## Naming convention

 - **CamelCase**: Classes, , file names for compilation unit containining classes 
structs and namespaces.
 - **snake_case**: File names (general), static global variables, and sometimes namespaces, Functions, methods, variables.
 - **UPPER_SNAKE_CASE***: Constants, macros, and enum values.

Note that the camel case here refers to camel case with capitalised first letter. 

## Indentation style

Before submitting your pull request, you need to run your code through the
formatter. You need to enter your ``builddir``, then run:

    meson compile format
