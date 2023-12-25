
#include "HelperFn.h"
double StringToDouble(string s) //Functions that converts a string to double
{
    double d = 0;
    switch (s[0])
    {
    case '-': //if the first element is negative
        for (int i = 0; i < s.size() - 1; ++i)
        {
            s[i] = s[i + 1]; //shifting the array to the left to remove the neagtive
        }
        s[s.size() - 1] = '\0';// Making the last element Null
        int indx;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == '.') //Getting the position of the dot in the string
            {
                indx = i;
                break;
            }
        }
        for (int i = 0; i < indx; ++i) //adding the digits before the decimal part to d
        {
            d = (d * 10) + (s[i] - 48); //in each itteration we multiply d by 10 and adding it to value of the string - "48" to get the character as an integer
        }
        for (int i = indx + 1; i < s.size() - 1; ++i)//adding the digits after the decimal part to d
        {
            d = (d * 10) + (s[i] - 48);
        }
        d /= pow(10, s.size() - indx - 2) * -1; //dividing d by 10^number of elements after the decimal part and multiplying -1 because it is the case that the number is negative
        break;

    default:// repeating the same process but the case is that the number is positive
        int idx;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '.')
            {
                idx = i;
                break;
            }
        }
        for (int i = 0; i < idx; ++i)
        {
            d = (d * 10) + (s[i] - 48);
        }
        for (int i = idx + 1; i < s.size(); ++i)
        {
            d = (d * 10) + (s[i] - 48);
        }
        d /= pow(10, s.size() - idx - 1);
        break;
    }
    return d;
}
int stringLen(string input) // Function to get the length of the string 
{
    int count = 0, j = 0;
    while (input[j]) // checking that the character is not empty
    {
        j++;// string array index
        count++;// incrementing the count until there is an empty character
    }
    return count;
}

bool IsValue(string input)
{
    bool check = true;
    if (input == "") //Checking for empty string
    {
        return false;
    }

    int idx;
    for (int i = 0; i < stringLen(input); ++i)  //Checking the position of the dot in the string
    {
        if (input[i] == '.')
        {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < stringLen(input); ++i)
    {
        if (input[i] < 45 || input[i] > 57 || input[i] == 47 || (input[i] == 46 && i > idx) || (input[i] == '-' && i > 0)) // checking the invalid condtions using ASCII values and for empty string
        {
            check = false;
            break;
        }
    }
    return check;
}

bool IsVariable(string input)
{
    bool check = true;
    if (input[0] < 65 || (input[0] > 90 && input[0] < 95) || input[0] == 96 || input[0] > 122 || input == "") //Checking the first character condtions
    {
        check = false;
    }
    for (int i = 1; i < stringLen(input); ++i)
    {
        if ((input[i] >= 32 && input[i] <= 46) || (input[i] >= 58 && input[i] <= 64) || (input[i] >= 91 && input[i] <= 94) || (input[i] >= 123 && input[i] <= 126) || input[i] == 96)// checking the invalid condtions using ASCII values
        {
            check = false;
            break;
        }
    }
    return check;
}

OpType ValueOrVariable(string input)
{
    if (IsValue(input)) {
        return VALUE_OP;
    }
    else if (IsVariable(input)) {
        return VARIABLE_OP;
    }

    return INVALID_OP;
}