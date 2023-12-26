#include "HelperFn.h"
double StringToDouble(string s)
{
    double d = 0;
    switch (s[0])
    {
    case '-':
        for (int i = 0; i < s.size() - 1; ++i)
        {
            s[i] = s[i + 1];
        }
        s[s.size() - 1] = '\0';
        int indx;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == '.')
            {
                indx = i;
                break;
            }
        }
        for (int i = 0; i < indx; ++i)
        {
            d = (d * 10) + (s[i] - 48);
        }
        for (int i = indx + 1; i < s.size() - 1; ++i)
        {
            d = (d * 10) + (s[i] - 48);
        }
        d /= pow(10, s.size() - indx - 2) * -1;
        break;

    default:
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
int stringLen(string input)
{
    int count = 0, j = 0;
    while (input[j])
    {
        j++;
        count++;
    }
    return count;
}

bool IsValue(string input)
{
    bool check = true;
    if (input[stringLen(input)] == 46)
    {
        return false;
    }
    for (int i = 0; i < stringLen(input); ++i)
    {
        if (input[i] < 45 || input[i] > 57 || input[i] == 47 || (input[i] == 46 && i > 1))
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
    if (input[0] < 65 || (input[0] > 90 && input[0] < 95) || input[0] == 96 || input[0] > 122)
    {
        check = false;
    }
    for (int i = 1; i < stringLen(input); ++i)
    {
        if ((input[i] >= 32 && input[i] <= 46) || (input[i] >= 58 && input[i] <= 64) || (input[i] >= 91 && input[i] <= 94) || (input[i] >= 123 && input[i] <= 126) || input[i] == 96)
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
