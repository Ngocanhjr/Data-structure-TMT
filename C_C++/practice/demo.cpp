#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIGITS 1000 // Length of number can input

typedef struct
{
    char *numbers; // Pointer to store array of digit
    int length;    // Length of the number
} BigInt;

BigInt read();

void display(BigInt a);

BigInt initAdd(BigInt a, BigInt b);

int isNegativeNumber(BigInt a);

void reverse(BigInt &a);

void addSpace(BigInt &a);

void swap(BigInt *a, BigInt *b);
 
BigInt add(BigInt a, BigInt b); // handle addition normal logic

BigInt initSubtract(BigInt a, BigInt b);

BigInt subtract(BigInt a, BigInt b);

void updateSpace(BigInt &a, int &check);

BigInt copyBigInt(BigInt a);

int main()
{
    BigInt a = read();
    //    display(a);
    BigInt b = read();
    //    display(b);
    BigInt ad = initAdd(a, b);
    BigInt sub = initSubtract(a, b);
    //    printf("----------------------------------\n");
    printf("%s\n", ad.numbers);
    printf("%s\n", sub.numbers);
}

int isNegativeNumber(BigInt a)
{
    if (a.numbers[0] == '-')
        return 1;
    return 0;
}

void swap(BigInt *a, BigInt *b)
{
    BigInt temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(BigInt &a)
{
    for (int i = 1; i <= (a.length + 1) / 2; i++)
    {
        char temp = a.numbers[i];
        a.numbers[i] = a.numbers[a.length - i + 1];
        a.numbers[a.length - i + 1] = temp;
    }
    while (a.numbers[1] == '0'){
        for (int j = 1; j < a.length; j++)
        {
            a.numbers[j] = a.numbers[j+1];
        }
        a.numbers[a.length] = '\n';
        a.length--;
}
  
    
}

BigInt read()
{
    char numberArray[MAX_DIGITS]; // Array store number when input
                                  //    printf("Enter new numbers: ");
    scanf("%s", numberArray);
    int sizeOfNumberArray = strlen(numberArray);
    BigInt newBigNumber;
    newBigNumber.length = sizeOfNumberArray;
    newBigNumber.numbers = (char *)malloc(sizeOfNumberArray * sizeof(char));
    strcpy(newBigNumber.numbers, numberArray);
    return newBigNumber;
}

BigInt copyBigInt(BigInt a)
{
    BigInt copy;
    copy.numbers = (char *)malloc(strlen(a.numbers) + 1);
    strcpy(copy.numbers, a.numbers);
    copy.length = a.length;
    return copy;
}

void display(BigInt a)
{
    int len = a.length;
    printf("Number:%*s\n", 12 + len, a.numbers); // format when print (12 is length of "Number:            ")
}

BigInt initAdd(BigInt a, BigInt b)
{
    a = copyBigInt(a);
    b = copyBigInt(b);
    BigInt result;
    result.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1)); // 1 is store digit when length of result larger then origin a, b number
    // case: a or b is negative
    if ((!isNegativeNumber(a) && isNegativeNumber(b)) || (isNegativeNumber(a) && !isNegativeNumber(b)))
    {
        result = subtract(a, b);
        return result;
    }
    else
    { // case: a and b is positive or negative
        result = add(a, b);
        // case: a and b is negative
        if (isNegativeNumber(a) && isNegativeNumber(b))
        {
            result.numbers[0] = '-';
        }
    }
    return result;
}

BigInt add(BigInt a, BigInt b)
{
    BigInt newNumber;
    newNumber.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    newNumber.numbers[0] = ' '; // store sign of number
    int lenMax = a.length > b.length ? a.length : b.length;
    int carry = 0, idxNewNumber = 1;
    for (int i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--, idxNewNumber++)
    {
        int aDigit = (i >= 0) ? a.numbers[i] - 48 : 0; // -48 convert from ASCII to natural number
        if (a.numbers[i] == '-')
            aDigit = 0;
        int bDigit = (j >= 0) ? b.numbers[j] - 48 : 0;
        if (b.numbers[j] == '-')
            bDigit = 0;
        int sumOfDigit = aDigit + bDigit + carry;
        carry = sumOfDigit > 9 ? 1 : 0;
        newNumber.numbers[idxNewNumber] = sumOfDigit % 10 + 48; //+48 convert from natural number to ascii
    }
    if (carry)
    {
        newNumber.numbers[idxNewNumber] = '1';
        lenMax++;
    }
    // update array number
    newNumber.length = lenMax;
    newNumber.numbers[lenMax + 1] = '\0';
    reverse(newNumber);
    return newNumber;
}

BigInt initSubtract(BigInt a, BigInt b)
{
    a = copyBigInt(a);
    b = copyBigInt(b);
    BigInt result;
    result.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    // Case: a - (-b) = a + b
    if (!isNegativeNumber(a) && isNegativeNumber(b))
    {
        result = add(a, b);
        result.numbers[0] = ' ';
        return result;
    }
    // case: (-a) - b = -(a + b)
    if (isNegativeNumber(a) && !isNegativeNumber(b))
    {
        result = add(a, b);
        result.numbers[0] = '-';
        return result;
    }
    else //(-a) - (-b) = -a + b = b - a or a - b
    {
        result = subtract(a, b);
    }
    return result;
}
BigInt subtract(BigInt a, BigInt b)
{
    BigInt newNumber;
    newNumber.numbers = (char *)malloc(sizeof(char) * (a.length > b.length ? a.length + 1 : b.length + 1));
    int lenMax = a.length > b.length ? a.length : b.length;
    int borrow = 0, idxNewNumber = 1;
    int isNewNumberNegative = 0, aNegative = 0, bNegative = 0;
    updateSpace(a, aNegative);
    updateSpace(b, bNegative);
    if (a.length == b.length)
    {
        if (strcmp(a.numbers, b.numbers) < 0)
        {
            if (!aNegative)
                isNewNumberNegative = 1;
            swap(&a, &b);
        }
        else if (strcmp(a.numbers, b.numbers) > 0)
        {
            if (aNegative)
                isNewNumberNegative = 1;
        }
        else
        {
            strcpy(newNumber.numbers, " 0");
            newNumber.length = 1;
            return newNumber;
        }
    }
    else if (a.length < b.length)
    {
        if (!aNegative)
            isNewNumberNegative = 1;
        swap(&a, &b);
    }
    else
    {
        if (aNegative)
        {
            isNewNumberNegative = 1;
        }
    }

    for (int i = a.length - 1, j = b.length - 1; i >= 0 || j >= 0; i--, j--, idxNewNumber++)
    {
        int aDigit = i >= 0 ? a.numbers[i] - 48 : 0;
        if (a.numbers[i] == ' ')
            aDigit = 0;
        int bDigit = j >= 0 ? b.numbers[j] - 48 : 0;
        if (b.numbers[j] == ' ')
            bDigit = 0;
        int subOfNumber;
        bDigit += borrow;
        if (aDigit < bDigit)
        {
            subOfNumber = (aDigit + 10) - (bDigit);
            borrow = 1;
        }
        else
        {
            subOfNumber = aDigit - bDigit;
            borrow = 0;
        }
        newNumber.numbers[idxNewNumber] = subOfNumber + 48;
    }
    if (isNewNumberNegative)
    {
        newNumber.numbers[0] = '-';
    }
    else
    {
        newNumber.numbers[0] = ' ';
    }
    // update array number
    newNumber.length = lenMax;
    newNumber.numbers[lenMax + 1] = '\0';
    reverse(newNumber);
    return newNumber;
}
void updateSpace(BigInt &a, int &check)
{
    if (isNegativeNumber(a))
    {
        check = 1;
        a.numbers[0] = ' ';
    }
    else
    {
        for (int i = a.length + 1; i >= 0; i--)
            {
                a.numbers[i] = a.numbers[i - 1];
            }
        a.numbers[0] = ' ';
        a.numbers[a.length + 2] = '\0';
        a.length++;
    }
}

