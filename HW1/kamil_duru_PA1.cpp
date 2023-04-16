#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/* Function to check is the value is integer or not*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/* Function to convert a string value with integer characters to an integer value*/
int	ft_atoi(const char *str)
{
	long	i; // index of str
	long	nbr; // nbr that converted from string
	int		isneg; // flag to check if the nbr is negative

	i = 0;
	nbr = 0;
	isneg = 0;
    /* loop that controls if there is any unprintable characters at the beginnig of string and ignores them */
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-') // if there is '-' sign, isneg turns to 1
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+') // if there is '+' sign ignores it
		i++;
    /* loop that converts number characters to integers */
	while (str[i] != '\0' && ft_isdigit(str[i])) 
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/* Function that produces random numbers, N parameter is how many digits will have the number */
int random_number(char N)
{
    int digit; // Variable to record digit count
    int count = 0; // count to end loop
    srand(time(0)); // randomize return value of rand() funcktion with time 
    char *number = new char [N - 48]; // str of number
    /* loop that produces an integer and puts to one digit of the number */
    while (count < N - 48) 
    {
        int flag = 0; // flag to check is there is any repeating number
        if (count == 0) // first number should not be 0
            digit = rand() % 9 + 1;
        else
            digit = rand() % 10;
            /* loop that controls ig there is any repeating number*/
        for (int j = 0; j < count; j++)
        {
            if (digit + 48 == number[j])
                flag = 1;
        }
        /* if flag is 0, number is ready to return */
        if (flag == 0)
        {
            number[count] = digit + 48;
            count++;
        }
    }
    /* returning with converting number to integer */
    return (ft_atoi(number));
}

/* Function to compute the digit count of a number */
int find_digit(int nb)
{
    int digit = 0; // count of digits
    while (nb)
    {
        nb /= 10;
        digit++;
    }
    return (digit);
}

/* String version of find_digit */
int find_digit_str(char *nb)
{
    int digit = 0; // count of digits
    while (nb[digit])
        digit++;
    return (digit);
}

/* Checks if there is a repeating number in integer */
int check_if_appears_again(int nb)
{
    int digit = find_digit(nb); //  digit count of the number
    /* loop that controls every single digit if there is repeating*/
    for (int i = 0; i < digit; i++)
    {
        int number = nb; // 2 temp variable to hold value of number
        int temp = nb;
        /* loop to divide the number by 10 until reaches the digit that we want*/
        for (int j = i + 1; j < digit; j++)
            number /= 10;
        number %= 10;
        /* loop that checks if holded number equals with any digit of our number */
        for (int j = i + 1; j < digit; j++)
        {
            if (temp % 10 == number)
                return (1);
            temp /= 10;
        }
    }
    return (0);
}

/* String version of check_if_appears_again*/
int check_if_appears_again_str(char *nb)
{
    int digit = find_digit_str(nb);
    /* loop to check is there any repeating number in string */
    for (int i = 0; i < digit; i++)
    {
        /* if there is any repeating, exits the program*/
        for (int j = i + 1; j < digit; j++)
        {
            if (nb[i] == nb[j])
                return (1);
        }
    }
    return (0);
}

/* Function that checks if the digit of input in between 0-9 */
int valid_digit_str(char *nb)
{
    int digits = 0;
    if (nb[0] == '0')
        return (0);
    while (nb[digits])
        digits++;
    return (digits <= 9);
}

/* Integer version of valid_digit */
int valid_digit_int(int nb)
{
    int digits = 0;
    while (nb)
    {
        nb /= 10;
        digits++;
    }
    return (digits <= 9);
}


int main(int argc, char *arg[])
{
    if (argc != 3 || (arg[1][1] != 'r' && arg[1][1] != 'u') || (arg[2][0] <= 48 && arg[2][0] > 57) || check_if_appears_again_str(arg[2]))
    {
        cout << "E0" << endl;
        exit(1);
    }
    int number; // our secret number
    int turn = 0; // turn count
    int c_exact = 0, c_misplaced = 0; // varibles of first and second count
    if (arg[1][1] == 'r')
    {
        number = random_number(arg[2][0]); // if the argument is -r, number is random
        if (find_digit(number) != (arg[2][0] - 48)) // if the digits of number is not equal with the argument input
        {
            cout << "E1" << endl;
            exit(1);
        }
        if (!ft_isdigit(arg[2][0])) // if the argument is not a number
        {
            cout << "E2" << endl;
            exit(1);
        }
    }
    else
    {
        int index = 0; // index of argument number
        /* loop to check if there is a charachter that is not number, ignores the whitespaces*/
        while (arg[2][index])
        {
            if (!ft_isdigit(arg[2][index]))
            {
                    cout << "E2" << endl;
                    exit(1);
            }
            index++;
        }
        number = ft_atoi(arg[2]); // at last converts to integer
    }
    int digit = find_digit(number); // digit count of number
    do
    {
        turn++; // turn increases in each turn
        int guess; // guessed number bu the user
        int temp_guess; // temp variable of guess
        int temp_number; // temp variable of the number
        int digit_of_guess = 0; // variable to record how many digits of the guess divided by 10
        int digit_of_number = 0; // variable to record how many digits of the guess divided by 10
        cin >> guess;
        c_exact = 0;
        c_misplaced = 0;
        /* loop that controls every single digit of the number with the guess */
        for (int i = 0; i < digit; i++)
        {
            temp_guess = guess;
            digit_of_guess = 0;
            /* loop to divide the guess to reach to digit that we want */
            for (int j = i + 1; j < digit; j++)
            {
                temp_guess /= 10;
                digit_of_guess++;
            }
            /* loop to controls if there is any number match with the digit that we attained from last loop */
            for (int j = 0; j < digit; j++)
            {
                temp_number = number;
                digit_of_number = 0;
                /* loop to divide the number to reach to digit that we want*/
                for (int k = j + 1; k < digit; k++)
                {
                    temp_number /= 10;
                    digit_of_number++;
                }
                /* if the digits are equal looks the position*/
                if (temp_guess % 10 == temp_number % 10)
                {
                    if (digit_of_guess == digit_of_number) // if they are in the same position increases the c_exact
                        c_exact++;
                    else
                        c_misplaced++;
                    break;
                }
            }
        }
        // if the c_exact is not the total digit of the number, prints them and continue
        if (c_exact != digit)
            cout << c_exact << " " << c_misplaced << endl;
        else
            cout << "FOUND " << turn << endl; // if the total digits are found, it breaks the loop
    }while (turn != 100 && c_exact != digit);
    if (turn == 100)
    {
        cout << "FAILED" << endl;
        exit(1);
    }
    return (0);
}