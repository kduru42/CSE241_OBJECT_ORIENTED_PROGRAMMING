<a name="br1"></a>CSE 241 Programming Assignment 3

DUE

April 16, 2023, 23:55

Description

• This is an individual assignment. Please do not collaborate.

• If you think that this document does not clearly describes the assignment, ask questions before its too late.

In this assignment, you are going to extend the implementation in PA2.

ppmImage class

If you didn’t implement a class for a ppm image (this was a requirement of PA2), you have to ﬁrst create a class forppm data. You can use the following guideline:

ppmImage class will have the following methods:

• Necessary constructors.

` `– A constructor which takes a ppm ﬁle name as argument and creates object form ﬁle.– A constructor which creates an object according to the given dimensions. The image data should be allocated an initialized in a way to represent a blank (white) image.– The default constructor

– Your constructors should check for the validity of the image data.

• Accessor and mutator functions for private member data• A member function in order to save ppm image to a ﬁle.• A member function to read ppm image from a ﬁle.

• A member function which prints dimensions of the ppm image.

• A Member function which returns individual pixel information. This function will take some index value and return information about the pixel pointed by that index for each color. (it basically takes a parameter and according to that parameter, it returns red, green or blue value of that particular pixel)

• A member function which changes individual pixel values.

• You can overload these functions if you need to.

• Any other member function you want your class to have.

• Check for validity of the data if you modify the members.

• Try to use const parameter modiﬁer if the parameter shouldn’t be modiﬁed.

• Divide your deﬁnition in public and private sections.

• Member data:

– Dimension information

– Image data: you can use std::vector. each element can be about a pixel. You can deﬁne a struct which

represents a pixel.

– Any other member data you want your class to have

Additional Functionality of ppmImage class

Implement the following (you can use friend functions or you can implement them as member functions if possible)

• operator +: Adds two ppmImage objects. Adds them pixel-by-pixel. They have to be the same size otherwise

it returns an empty ppmImage object. (empty objects represents an image which has 0 number of pixels.).

1




<a name="br2"></a>Color channels may reach to saturation. Don’t go beyond the max value written in the image data. You canassume that both images will have the same max value.

• operator -: Similar to operator +. subtracts one image from the other. Color data cannot go below 0. • operator <<: Prints image details and image data to stdout. This is similar to saving the image to a ﬁle. Allows cascading.

• operator (): Function-call operator. This operator takes three parameters. The ﬁrst parameter is the index of the row number. The second parameter is the index of the column number. The third parameter is the color channel. It can either 1, 2 or 3. The upper left corner is (0,0). This operator returns a reference to the pixel value.

Test Your Class

Write a main function and test all of the functions of your class. Create objects, read from ﬁle, write to a ﬁle. change individual pixels, read individual pixels etc. . .

Implement the following functions in order to test your class implementation

Although you can deﬁne and use other class internally in ppmImage class, for the following functions,you are not allowed to use those classes you deﬁned. You can only use ppmImage class in thesefunctions.

Standalone Functions

// returns 1 if the operation is successful. otherwise, returns 0.

// reads ppm data from file named as source\_ppm\_file\_name. stores data in destination\_object

,→

which is already created outside of the function.

int read\_ppm(const string source\_ppm\_file\_name, ppmImage& destination\_object);

// returns 1 if the operation is successful. otherwise, returns 0.

// writes ppm data from source\_object to the file named destination\_ppm\_file\_name. int write\_ppm(const string destination\_ppm\_file\_name, const ppmImage& source\_object);

// returns 1 if the operation is successful. otherwise, returns 0.

// reads images from filename\_image1 and filename\_image2. Adds them and saves the resulting

,→

image to filename\_image3

int test\_addition(const string filename\_image1, const string filename\_image2, const string

,→

filename\_image3);

// returns 1 if the operation is successful. otherwise, returns 0.

// reads images from filename\_image1 and filename\_image2. Subtracts filename\_image2 from

,→

filename\_image1 saves the resulting image to filename\_image3

int test\_subtraction(const string filename\_image1, const string filename\_image2, const string

,→

filename\_image3);

// returns 1 if the operation is successful. otherwise, returns 0.// reads images from filename\_image1 and prints it to stdoutint test\_print(const string filename\_image1);

// implement this using the function-call operator overloaded.// this function swaps the color values of every pixel in a given ppm image.// this function does not create a new object but modifies the given one.// if swap\_choice is 1: swaps red and green // if swap\_choice is 2: swaps red and blue // if swap\_choice is 3: swaps green and blue

// if swap\_choice is not 1, 2 or 3: no swaps (this does not mean that the operation is not

,→

successful. the function should return 1 in this case if everything is normal) // returns 1 if the operation is successful. otherwise, returns 0.

int swap\_channels(ppmImage& image\_object\_to\_be\_modified, int swap\_choice);

2




<a name="br3"></a>// implement this using the function-call operator overloaded.

// creates and returns a copy of a new ppmImage object which stores only one color at each

,→

pixel. This simply takes the source and copies only one color information and stores it in

,→

a new object. The other color channels are simply going to be zeros. //if color\_choice is 1: red channel is preserved

//if color\_choice is 2: green channel is preserved//if color\_choice is 3: blue channel is preserved

ppmImage single\_color(const ppmImage& source, int color\_choice);

Main Function

// Use this main function skeleton otherwise you will get zero

int main(int argc, char\*\* argv) {

// check for number of command line arguments

// the first argument is going to be choice number

// the second argument is going to be a ppm\_file\_name1

// the third argument is going to be ppm\_file\_name2 (this is optional)// the third argument is going to be ppm\_file\_name3 (this is optional)

// if choice number is 1

// check the existence of the optional arguments. If they are not given, exit int test\_addition(ppm\_file\_name1, ppm\_file\_name2, ppm\_file\_name3);

// if choice number is 2

// check the existence of the optional arguments. If they are not given, exit int test\_subtraction(ppm\_file\_name1, ppm\_file\_name2, ppm\_file\_name3);

// if choice number is 3

// read ppm\_file\_name1 using function read\_ppm// swap red and blue channels

// write the updated data to a file named "ppm\_file\_name2". use write\_ppm function.

// if choice number is 4

// read ppm\_file\_name1 using function read\_ppm

// swap green and blue channels. use swap\_channels function

// write the updated data to a file named "ppm\_file\_name2". use write\_ppm function.

// if choice number is 5

// read ppm\_file\_name1 using function read\_ppm

// create a new object which only contains red channel data of the file read. use single\_color

,→

function

// write the data of the new object to a file named "ppm\_file\_name2". use write\_ppm function.

// if choice number is 6

// read ppm\_file\_name1 using function read\_ppm

// create a new object which only contains green channel data of the file read. use

,→

single\_color function

// write the data of the new object to a file named "ppm\_file\_name2". use write\_ppm function.

// if choice number is 7

// read ppm\_file\_name1 using function read\_ppm

// create a new object which only contains blue channel data of the file read. use

,→

single\_color function

3




<a name="br4"></a>// write the data of the new object to a file named "ppm\_file\_name2". use write\_ppm function.

}

Remarks

• Error checking is important.

• Your program should be immune to the whitespace before any user input.• Do not submit your code without testing it with several diﬀerent scenarios.• Write comments in your code. Extensive commenting is required. Comment on every variable, constant, function and loop. (10pts)

• Do not use #Define and deﬁne macros. Instead use constant keyword and deﬁne constant variables. If you use macros, you will loose 5 points for each of them.

• Be very careful about the input and output format. Don’t print anything extra(including spaces).

Turn in:

• Source code of a complete C++ program. Name of the ﬁle should be in this format: <full\_name>\_PA3.cpp. If you do not follow this naming convention you will loose -10 points.

• Example: desmond hume\_PA3.cpp. Please do not use any Turkish special characters.• You don’t need to use an IDE for this assignment. Your code will be compiled and run in a command window. • Your code will be compiled and tested on a Linux machine(Ubuntu). GCC will be used. • Make sure you don’t get compile errors when you issue this command : g++ -std=c++11 <full\_name>\_PA3.cpp. • A script will be used in order to check the correctness of your results. So, be careful not to violate the expected output format.

• Provide comments unless you are not interested in partial credit. (If I cannot easily understand your design,

you may loose points.)

• You may not get full credit if your implementation contradicts with the statements in this document.

4




<a name="br5"></a>Late Submission

• Not accepted.

Grading (Tentative)

• Max Grade : 100.

• Multiple tests will be performed.

All of the followings are possible deductions from Max Grade.

• Do NOT use hard-coded values. If you use you will loose 10pts.

• No submission: -100. (be consistent in doing this and your overall grade will converge to N/A) (To be speciﬁc: if you miss 3 assignments you’ll get N/A)

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

• Source code encoding is not UTF-8 and characters are not properly displayed: -5. (You can use ‘Visual Studio Code’, ‘Sublime Text’, ‘Atom’ etc. . . Check the character encoding of your text editor and set it to UTF-8).

• Missing or wrong output values: Fails the test.

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
