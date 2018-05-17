SLR0 and LL1 Parsers
================
This is an implementation of two parsers of a toy programming language

Main phases :
--------
* Lexical Analysis (lexical.cpp)
* LL(1) Top Down Parser (LL1_parse.cpp)
* SLR(0) Bottom Up Parser (slr_parse.cpp)

Toy-language syntax:
--------
* If statements
* While statements
* Assignments

Grammar
--------
The grammar that defines the rules for our toy programming language 
* LL1 grammar (LL1_Grammar.txt)
* SLR0 grammar (SLR0_Grammar.txt)

Note
--------
An example for the language and also a test is in "test.txt".
The last block yields an error in parsing because of the assignment inside the if condition, "if ( x = 5 ) then"
