﻿<a name="br1"></a>CSE 241 Programming Assignment 2

DUE

April 3, 2023, 23:55

Description

• This is an individual assignment. Please do not collaborate.

• If you think that this document does not clearly describes the assignment, ask questions before its too late.

This assignment is the ﬁrst in a series of assignments which are all going to be about classes. In the end, you will

Your should utilize object oriented principles as much as possible. Your submission may not be accepted if you

Image Editor

` `• You can create a class which represents the whole image editor program. Your program won’t have a GUI yet

• Implement member functions for reading image ﬁles and writing image data to ﬁles.

• Implement grayscale conversion function.

Image File Format

Your program will basically work on PPM format(Ascii format). Particularly P3 format. Read the description here:

Many image editors can read and write ppm ﬁles. I advise you to use GIMP. Use Ascii format while exporting, otherwise you cannot read it.

Menu Of Your Program

The initial version of your program will have the following main menu structure:

Main Menu

0 - Exit -----> Exits the program without saving the image data

OPEN AN IMAGE MENU 0 - UP

1 - Enter The Name Of The Image File

SAVE IMAGE DATA MENU

1 - Enter A File Name

SCRIPTS MENU 0 - UP

1 - Convert To Grayscale(D)

CONVERT TO GRAYSCALE MENU 0 - UP

1 - Enter Coefficients For RED GREEN And BLUE Channels.

1




<a name="br2"></a>If a menu item has a (D) at the end, that means it is a dialog. If user enter the particular menu number, A new menu dialog will be shown.

Example

Suppose that you have the following ﬁle.

• test.ppm

P3 4 4

255

0 0 0 100 0 0 0 0 0 255 0 255

NOTE: > is a part of the terminal environment. DO NOT PRINT IT

Start your program

\> ./myprogram > MAIN MENU

\> 0 - Exit

\> 1 - Open An Image(D)

\> 2 - Save Image Data(D) > 3 - Scripts(D)

\> 1 --------> User inputs 1 and presses RETURN > OPEN AN IMAGE MENU

\> 0 - UP --------> If user enters 0, MAIN MENU will be printed. > 1 - Enter The Name Of The Image File

\> 1 --------> User inputs 1 and presses RETURN

\> test.ppm --------> User inputs test.ppm and presses RETURN

\> OPEN AN IMAGE MENU --------> Your program reads test.ppm and prints the current dialog menu > 0 - UP --------> If user enters 0, MAIN MENU will be printed.

\> 1 - Enter The Name Of The Image File

\> 0 --------> User inputs 0 and presses RETURN > MAIN MENU --------> MAIN MENU is printed again

\> 0 - Exit

\> 1 - Open An Image(D)

\> 2 - Save Image Data(D) > 3 - Scripts(D)

.

Script: Convert To Grayscale

This script creates the following dialog:

CONVERT TO GRAYSCALE MENU 0 - UP

1 - Enter Coefficients For RED GREEN And BLUE Channels.

If user enters 1, then user can enter three ﬂoat numbers which are in the range [0,1). You should check for any errors. If there is an error, ask user to re-enter the coeﬃcients. Example input:

0\.33 0.10 0.2

These numbers are coeﬃcients (c\_r, c\_g, c\_b) for RED, GREEN and BLUE channels. After getting the coeﬃcients (c\_r,

2




<a name="br3"></a>RED = (c\_r \* RED) + (c\_g \* GREEN) + (c\_b \* BLUE)

You just need to update the values in the image representation these new values. If the new values are greater than

255, then that means they are saturated. Leave them as 255.

Saving Image Data

SAVE IMAGE DATA MENU

1 - Enter A File Name

If user enters 1, then user can enter a ﬁlename. Example: Assume user enters output.ppm. In this case, image data

Remarks

• Error checking is important.

• Your program should be immune to the whitespace before any user input.

• Do not use #Define and deﬁne macros. Instead use constant keyword and deﬁne constant variables. If you

• Everything happens through stdin and stdout.

` `• Be very careful about the input and output format. Don’t print anything extra(including spaces).

Turn in:

• Source code of a complete C++ program. Name of the ﬁle should be in this format: <full\_name>\_PA2.cpp.

• Example: albert\_einstein\_PA2.cpp. Please do not use any Turkish special characters.

• Provide comments unless you are not interested in partial credit. (If I cannot easily understand your design,

you may loose points.)

• You may not get full credit if your implementation contradicts with the statements in this document.

3




<a name="br4"></a>Start

||Exit||<p>` `Main Menu</p><p>0 - Exit</p><p>1 - Open An Image(D)</p><p>2 - Save Image Data(D)</p><p>3 - Scripts(D)</p>|
| :- | :- | :- | :- |
OPEN AN IMAGE MENU SCRIPTS MENU

SAVE IMAGE DATA MENU

||<p>0 - UP</p><p>1 - Enter The Name Of</p><p>The Image File</p>||<p>0 - UP</p><p>1 - Enter A File Name</p>||<p>0 - UP</p><p>1 - Convert To Grayscale(D)</p>|
| :- | :- | :- | :- | :- | :- |
|<p>- create an image object</p><p>- read ppm image data</p>||<p>- save image object</p><p>data as ppm</p>||<p>CONVERT TO GRAYSCALE MENU</p><p>0 - UP</p><p>1 - Enter Coefficients For</p><p>` `RED GREEN And BLUE Channels.</p>|
` `- user enters R G B coefficients

Figure 1: Program Flow

4




<a name="br5"></a>Late Submission

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

• Cannot properly print the menu: -5 for each test.

• Cannot execute menu commands: Fails the test.

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

5