# SLR0-And-LL1-Parsers
This is an implementation of two parsers of a toy programming language 

This project consists of three parts:
  1. Lexical Analysis (lexical.cpp)
  2. LL(1) Top Down Parser (LL1_parse.cpp)
  3. SLR(0) Bottom Up Parser (slr_parse.cpp)
  
The toy programming language includes:
  1. If statements
  2. While statements
  3. Assignments
  
An example for the language and also a test is in "test.txt".
The last block yields an error in parsing because of the assignment inside the if condition, "if ( x = 5 ) then"
