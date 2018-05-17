# SLR0-And-LL1-Parsers
This is an implementation two parsers of a toy programming language 

This project consists of three parts:
  1. Lexical Analysis
  2. LL(1) Top Down Parser
  3. SLR(0) Bottom Up Parser
  
The toy language includes:
  1. If statements
  2. While statements
  3. Assignments
  
An example for the language and also a test is in "test.txt".
The last block yields an error in parsing because of the assignment inside the if condition, "if ( x = 5 ) then"
