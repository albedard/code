//Amanda Bedard
//PA-1
//
//The header files for the program
//These are all the headers I have used for
//either testing my file or the final copy
//needs it to run
#include <stdio.h>
#include "pa-1.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//I used this for a lot of 'on the spot' testing of my logic
int main()
{
    return 0;
}

//The f_strings function that concatinates two strings together 3 times
void f_strings(char* s1, char* s2, char*s3)
{
    //The variables.
    //I used my length-finding function to determine the length of the
    //arrays and two counters
    int len1 = CharArrLen(s1);
    int len2 = CharArrLen(s2);
    int i = 0;
    int c = 0;

    //Measures which one is greater
    if (len1 > len2)
    {
        //Does the short one
        while(i < len2)
        {
            s3[c] = s2[i];

            //increments both counters
            i++;
            c++;
        }

        //Resets one of the counters
        i = 0;

        //Does the long one next
        while(i < len1)
        {

            s3[c] = s1[i];
            
            //Increments the counters again
            i++;
            c++;
        }

        //Resets the counter
        i = 0;

        //Does the short one a last time
        while(i < len2)
        {
            s3[c] = s2[i];

            //Increments the counters
            i++;
            c++;
        }
    }

    //This part basically does the same thing as the top part except
    //it is reversed because the other string must be greater to get here
    else
    {
        while(i < len1)
        {
            s3[c] = s1[i];
            i++;
            c++;
        }

        i = 0;

        while(i < len2)
        {
            s3[c] = s2[i];
            i++;
            c++;
        }

        i = 0;

        while(i < len1)
        {
            s3[c] = s1[i];
            i++;
            c++;
        }
    }
}

//Calculates two numbers that when added together after
//being cubed add up to number n
int* f_cubes_sum(int n)
{
    //The variables for the counter and its cube numbers
    int f1 = 0;
    int f2 = 0;
    int i = 1;

    //Puts aside two spots in memory for the pair
    int *pair = (int*) calloc(2 , sizeof(int));

    //While i is less than the number n
    while (i <= n)
    {
        //Set j to 1 for each time to go through all numbers
        int j = 1;

        //While J is less than the number n
        while (j <= n)
        {
            //Uses the power function I created to test if the two numbers cubed
            //add up to the initial number
            if (power(i, 3) + power(j, 3) == n)
            {
                //Stores the pair
                pair[0] = i;
                pair[1] = j;

                //If there is a pair to make a cube sum, it will return here
                return pair;
            }
            //Increment counter
            j++;
        }

        //Increment counter
        i++;
    }
    //If there is no cube sum, free up the memory location and return null
    free(pair);
    return NULL;
}

//The cottatz count function that figures out if the number
//is a collatz number or not
int f_collatz_count(int n)
{
    //The counter variable (really the only one that needs to be
    //declared in this function)
    int count = 0;

    //Loops while n is greater than 1 because I keep modding and
    //dividing by 10 to get each digit
    while (n > 1)
    {
        //If it is an even number
        if (n % 2 == 0)
        {
            //Divide by 2
            n = n/2;
        }

        //Otherwise,
        else if (n % 2 == 1)
        {
            //Multiply by 3 and add 1
            n = 3*n + 1;
        }

        //Increment the counter for the amount of times this
        //function has run
        count++;
    }

    //Return the variable holding the number of times this algorithm has run
    return count;
}

//Simple function I made to check any array length of characters
//because I couldn't find any that worked correctly on google
int CharArrLen(char*arr)
{
    //Counter and total characters
    int i = 0;
    int ttl = 0;

    //While the array does not have the end character
    while (arr[i] != '\0')
    {
        //Increment the counter and the total
        i ++;
        ttl ++;
    }
    //Return the total
    return ttl;
}

//The function to search a string for a pattern
int f_str_search(char*pattern, char*text)
{
    //The variables for measuring the string and comparing the characters
    int textlen  = CharArrLen(text);
    int strlen = CharArrLen(pattern);
    int ttlMatch = 0;

    //The counter
    int i = 0;

    //While the counter is less than the length of the entire string
    while (i < textlen)
    {
        //Defaults the 2nd counter to 0 and the boolean variable to true
        int j = 0;
        bool match = true;

        //The conditions for the loop to continue are set to default so it enters
        //once and then based on the input it will either continue or end the loop
        while(j < strlen && match == true)
        {
            //If the pattern does not match the area of the string it will change to false
            if (pattern[j] != text[i + j])
            {
                match = false;
            }

            //Increment the counter
            j++;
        }

        //Increment the other counter
        i++;

        //If after the loop all pieces match
        if(match == true)
        {
            //Add one to the total of matching spots
            ttlMatch++;
        }
    }
    
    //Returns the total of matches
    return ttlMatch;
}



// Rotates integer n  by r places
int f_rotate(int n, int r)
{
    //variable declarations
    //two counters (i and c), a number for manipulating n, array to store the numbers
    //a variable to convert the array to a single integer, and something to hold the
    //final rotated variable
    int aRotate[11];
    int i = 0;
    int c = 0;
    int num = n;
    int rotated = 0;
    int times = 1;

    //Loops through the integer to create an array of single numbers for manipulation
    while (num >= 1)
    {
        //populates the array by individually assigning the remainder (last digit)
        //to a spot in the array
        aRotate[i] = num % 10;
        //Subtracts the remainder to make sure there will definitely be an int returned
        //when divided by 10
        num = (num - aRotate[i])/10;
        //Increments the counter
        i ++;
    }

    //Loops through the array and rotates value
    while(c <  i)
    {
        //Adds the digit times a multiple of 10 to create a single integer
        rotated += aRotate[(c+r)%(i)]*times;
        //Increments the counter and the multiplier
        c ++;
        times *= 10;
    }
    
    //Returns the rotated number
    return rotated;
}

//The function to check if int x is a perfect number
bool f_perfect(int x)
{
    //Declares the variables needed for the function
    //It has variables for the counter, array length, array of factors, and sum of factors
    int i = 1;
    int len = 0;
    int factor[20];
    int sum = 0;

    //Loops while i is less than half the number because you are not concerned with 
    //any factors over half the number (even though the number itself is a factor
    //it is not necessary to see if it is a perfect number)
    while (i <= (x/2))
    {
        //Checks if the number divides evenly into the original integer
        if (x % i == 0)
        {
            //Adds i to the factor list and increments to keep track of the array length
            factor[len] = i;
            len ++;
        }

        //increments the counter
        i++;
    }

    //counter for loop
    int c = 0;

    //While loop to get the sum of the factors
    while (c <= len)
    {
        sum += factor[c];

        //Increments the counter
        c++;
    }

    //Conditional to check if the sum is the same as the integer
    if (sum == x)
    {
        //If so, return true
        return true;
    }
    else
    {
        //If they are not the same, return false
        return false;
    }

}

//This fuction checks and sees if the strig of brackets have a beginning and end one for each
bool f_brackets(char* e)
{
    //Variables for the length of array (string) e, counters for the forward facing
    //brackets and end brackets, and the loop counter
    int len = CharArrLen(e);
    int i = 0;
    int fwd = 0;
    int end = 0;

    //Loops through to count the brackets
    while (i < len)
    {
        if (e[i] == '[')
        {
            fwd++;
        }
        else if (e[i] == ']')
        {
            end++;
        }

        i++;
    }

    //If there are the same number of beginning and end brackets, return true
    if (fwd == end)
    {
        return true;
    }
    
    //Otherwise, return false
    else
    {
        return false;
    }
}




//The function that determines if it is an armstrong number and if it is, returns true
bool f_armstrong(int n)
{
    //The variables for the function, an array of the integers, a counter, a sum integer,
    //and a variable x for manipulating n without changing n
    int i = 0;
    int numList[11];
    int sum = 0;
    int x = n;

    //Loops through to separate the integer into single numbers
    while (x >= 1)
    {
        //Mods x by 10 then subtracts the result to get an int and divides
        //by 10
        numList[i] = x % 10;
        x = (x - numList[i]) /10;

        //Increments the counter
        i ++;

    }
    
    //Declares a new counter
    int j = 0;

    //While j is less than the number of values
    while (j < i)
    {
        //Adds the array value of j raised to the i power
        sum += power(numList[j], i);

        //Increments counter j
        j ++;
    }

    //If the sum of the numbers raised to power i is equal to the number
    //that means it is an armstrong number
    if (sum == n)
    {

        //so return true
        return true;
    }

    else
    {
        //otherwise return false
        return false;
    }

}


// Function that sorts three integers (x, y, z) and returns them in an array (list)
void f_sort(int x, int y, int z, int* list)
{

        // Sets the array values equal to the integers in the order they were received
        list[0] = x;
        list[1] = y;
        list[2] = z;

            // Checks to see if the variables are in the correct order.  If they are not,
            // It changes the order and calls the function again
            if (x > y)
            {
                f_sort(y, x, z, list);
            }

            else if (x > z)
            {
                f_sort (z, y, x, list);
            }

            else if (y > z)
            {
                f_sort(x, z, y, list);
            }

            //This statement is executed if all the other conditions are met
            //It will return the array of integers in ascending order
            else
            {
                
                list[0] = x;
                list[1] = y;
                list[2] = z;
            }
}

// This function manipulates values in an array
float f_array(int n)
{
    //All the variables for the function along with the random
    int A[n];
    int r;
    int i = 0;
    int h = 0;
    float sum = 0;
    srand(time(NULL));

    //Loop and randomly fill array with specified amount of random integers
    while (i < n)
    {
        r = rand() % 99 + 1;
        A[i] = r;
        i ++;
    }

    //Loop and randomly fill array with specified amount of random integers
    while (i < n)
    {
        r = rand() % 99 + 1;
        A[i] = r;
        i ++;
    }

    //Sets the counter to 0
    i = 0;

    //While counter i is less than number n
    while (i < n)
    {
        //Multiplies all elements by 2
        A[i] = A[i] * 2;

        //Determines if it is divisible by 3 and one of the first 5 that are
        if (h < 5 && A[i]%3 == 0)
        {
            //Adds together if divisible by 3 and of the first 5 that are
            sum += A[i];

            //Increment the counter
            h ++;
        }

        //Increment the counter
        i ++;
    }
    
    //Prevents division by zero if there are zero numbers that are
    //divisible by 3 by any chance
    if (h > 0)
    {
        //Sets the sum equal to the large sum divided by the number of values
        //divisible by 3 (no more than 5)
        sum = sum/h;

        //Returns the average of the first 5 numbers divisible by zero
        return sum;
    }
    else
    {
        //Returns 0 if there is 0 values divisible by 3
        return 0;
    }
}

//Function to raise a number to a power
//I felt this would be easier than typing -lm into the command line constantly
//when I compiled my code
int power (int n, int p)
{
    int pNum = n;
    int i = 1;

    while(i < p)
    {

        pNum = pNum*n;
        i ++;
    }
    return pNum;
}

