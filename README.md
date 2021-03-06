#Delimiter Checker

1. Identifying Information
    * Name:  Dan Haub
    * Student ID#:  2315346
    * Chapman Email:  haub@chapman.edu
    * Course Number and Section:  CPSC 350-01
    * Assignment:  3 - Delimiter Checker

2. Source Files
    * main.cpp
    * Makefile
    * GenStack.h
    * SyntaxChecker.h
    * SyntaxChecker.cpp
    * StackException.h
    * StackException.cpp
    * DelimException.h
    * DelimException.cpp

3. Description of any known compile/runtime errors, or bugs.
    * RUNTIME: If there is an unclosed quotation character (either " or ') it will give inaccurate readings.
      * This issue will most likely come about when a comment has a word with an apostrophe
      * This is because the syntax checker accounts for string and character literals that would allow for incorrect delimiters.
         * For example the string literal: "this is an incorrect delimiter sequence: [})" 
          * Or the character literal: ')'
      * Additionally, becuase the language being checked is ambiguous, it is impossible to know what comment style is being used, meaning that comments will be checked for correct delimiters and quotation.
      * Quotes are kept track of using a boolean flag that is thrown off by an unclosed quotation character (see SyntaxChecker.cpp lines 74-77)

4. References used to complete the assignment
    * http://www.cplusplus.com/reference/string/string/find/
    * Absolute c++ 5th Edition (Walter Savitch)

5. Instructions for running the assignment
    * git clone from repository
    * cd to DelimiterChecker folder
    * input "make"
    * input "./assignment3.exe [file path]"
    * follow onscreen prompts
