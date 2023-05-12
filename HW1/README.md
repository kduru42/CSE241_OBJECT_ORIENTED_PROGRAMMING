﻿<a name="br1"></a>CSE 241 Programming Assignment 1

DUE

March 25, 2023, 23:55

Description

• This is an individual assignment. Please do not collaborate.

• If you think that this document does not clearly describes the assignment, ask questions before its too late.

This is the ﬁrst assignment of the semester. This will get you ready for the upcoming assignments. Carefully execute

You are going to implement an interactive program which enables user to play the game mastermind. The idea of

The Rules of The Mastermind

• A digit is an integer in the range [0,9]

• A valid number is deﬁned to be an N digit number (N ≤ 9) where the high-most (leftmost) digit cannot be 0

• Your program chooses a valid number (secret number).

` `– First option is to generate a random number (it must be a valid number)

– Second count (Cmisplaced): The count of digits of the proposed number which do exist in the secret

number but are not in place.

• A Cexact value of N stops the game and the turn-count is recorded; otherwise the game continues with accepting

user proposals.

Expectations

Input

• Your program will take command-line arguments.

– The ﬁrst argument is either -r or -u.

– If the ﬁrst argument is -r, user has to provide another argument N: The number of digits. Your program

` `– If the ﬁrst argument is -u, user has to provide another argument which will be used as a secret number.

Output

• At each iteration, print hints.

• If the user input perfectly matches with the secret number, print the FOUND message and number of iterations

and exit.

Example Run

Suppose that your source ﬁle is student\_name\_PA1.cpp.

First, it will be compiled:

g++ -std=c++11 student\_name\_PA1.cpp -o mastermind

1




<a name="br2"></a>Then your program can be called like the following:

mastermind.exe -r 6

or like the following if you are using a unix-like OS

./mastermind -r 6

With this call, user is expected to enter a 6 digit number. If user enters a number which has more or less than 6

digits, your program should print the following error message and exit.

E1

If the user enters something but not an integer, your program should print the following error:

E2

If the user enters a valid number your program should return the hints in the following format:

mastermind -r 6 ------> Assume that your program generates secret 130456

4 1 ------> First count is 4, Second count is 1 (separated by a space)

5 0 ------> First count is 5, Second count is 0 (separated by a space)

FOUND 3 ------> User found the number in 3 iterations, program exits. (separated by a space)

If the user cannot ﬁnd in 100 iterations, print the following message and exit the program:

FAILED

Your program can also be called like the following:

mastermind -u 12345

If this happens, your program will use 12345 (the given argument) as the secret number. The rest of your code will

Error Checking

Check for any errors in program call. If there is any error, print the following and exit:

E0

Errors in program call include the following:

• Missing parameters. • Wrong parameters.

• Undeﬁned parameters.

` `• Negative value or 0 value following the -r option.

The other errors are speciﬁed in the Example section.

Remarks

• Error checking is important.

• Your program should be immune to the whitespace before any user input.

• Do not use #Define and deﬁne macros. Instead use constant keyword and deﬁne constant variables. If you

• Do not create an output ﬁle. Everything happens through stdin and stdout.

• Be very careful about the input and output format. Don’t print anything extra(including spaces).

2




<a name="br3"></a>Turn in:

• Source code of a complete C++ program. Name of the ﬁle should be in this format: <full\_name>\_PA1.cpp.

• Example: student\_name\_PA1.cpp. Please do not use any Turkish special characters.

• Provide comments unless you are not interested in partial credit. (If I cannot easily understand your design,

you may loose points.)

• You may not get full credit if your implementation contradicts with the statements in this document.

3




<a name="br4"></a>Late Submission

• Not accepted.

Grading (Tentative)

• Max Grade : 100.

• Multiple tests will be performed.

All of the followings are possible deductions from Max Grade.

• Do NOT use hard-coded values. If you use you will loose 10pts.

• No submission: -100. (be consistent in doing this and your overall grade will converge to N/A) (To be speciﬁc:

• Compile errors: -100.

• Irrelevant code: -100.

• Major parts are missing: -100.

• Unnecessarily long code: -30.

• Ineﬃcient implementation: -20.

• Using language elements and libraries which are not allowed: -100.

• Not caring about the structure and eﬃciency: -30. (avoid using hard-coded values, avoid hard-to-follow

expressions, avoid code repetition, avoid unnecessary loops).

• Signiﬁcant number of compiler warnings: -10.

• Not commented enough: -10. (Comments are in English. Turkish comments are not accepted).

• Source code encoding is not UTF-8 and characters are not properly displayed: -5. (You can use ‘Visual Studio

• Missing or wrong output values: Fails the test.

• Cannot produce numbers with unique digits: Fails the test.

• Output format is wrong: -30.

• Inﬁnite loop: Fails the test.

• Segmentation fault: Fails the test.

• Fails 5 or more random tests: -100.

• Fails the test: deduction up to 20.

• Prints anything extra: -30.

• Unwanted chars and spaces in output: -30.

• Submission includes ﬁles other than the expected: -10.

• Submission does not follow the ﬁle naming convention: -10.

• Sharing or inheriting code: -200.

4