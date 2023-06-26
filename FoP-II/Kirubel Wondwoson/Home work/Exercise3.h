using namespace std;
int findLength(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int countVowel(string str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
    }
    return count;
}
int countConsonant(string str)
{
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            count2++;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                count1++;
            }
        }
    }
    return count2 - count1;
}
string reverseStr(string str)
{
    int length;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return str;
}
int compareStr(string str1, string str2)
{
    int length1 = 0, length2 = 0;
    // length of str1
    for (int i = 0; str1[i] != '\0'; i++)
    {
        length1++;
    }
    // length of str2
    for (int i = 0; str2[i] != '\0'; i++)
    {
        length2++;
    }
    for (int i = 0; str1[i] != '\0', str2[i] != '\0'; i++)
    {
        if (str1[i] == str2[i])
        {
            return 0;
        }
        else if (length1 > length2)
        {
            return 1;
        }
        return -1;
    }
}
string mytolower(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (char temp = 'A', temp2 = 'a'; temp <= 'Z' && temp2 <= 'z'; temp++, temp2++)
        {
            if (str[i] == temp)
            {
                str[i] = temp2;
            }
        }
    }
    return str;
}
string mytoupper(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (char temp1 = 'a', temp2 = 'A'; temp2 < 'z', temp2 < 'Z'; temp1++, temp2++)
        {
            if (str[i] == temp1)
            {
                str[i] = temp2;
            }
        }
    }
    return str;
}