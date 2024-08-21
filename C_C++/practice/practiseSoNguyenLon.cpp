#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIGITS 1000


typedef struct
{
    char *digits; // Pointer to store digits
    int length;   // Length of the number
} BigInt;

void nhap(BigInt *number, char c)
{
    char num[MAX_DIGITS];
    printf("Enter %c:\t", c);
    fgets(num, MAX_DIGITS, stdin);
    if (num[strlen(num) - 1] == '\n')
        num[strlen(num) - 1] = '\0';
    number->digits = (char *)malloc(strlen(num) + 1);
    strcpy(number->digits, num);
    number->length = strlen(number->digits);
}

void xuat(BigInt number)
{
    printf("Number:\t%s\n", number.digits);
}
BigInt sum(BigInt a, BigInt b)
{
    BigInt result;
    int carry = 0,i;
    result.digits = (char *)malloc(sizeof(char) * a.length > b.length ? a.length + 1 : b.length + 1);
     for (i = 0; i < result.length; i++) {
        int sum = (i < a_len ? a[i] : 0) + (i < b_len ? b[i] : 0) + carry;
        result.digits = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[i] = carry;
        (*res_len)++;
    }

    return result;
}
int main (){
    BigInt a;
    nhap (&a, 'a');
    xuat (a);

}