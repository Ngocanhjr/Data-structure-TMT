#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIGITS 1000 //Lenght of number can input

typedef struct
{
    char *numbers; // Pointer to store array of digit
    int length;   // Length of the number
} BigInt;

BigInt read();
void display(BigInt a);
int isNegativeNumber (BigInt a);
void reverse (BigInt &a);

BigInt add (BigInt a, BigInt b){
    if(isNegativeNumber(a)){
        printf("a is negative number\n");
    } else {
        printf("a is positive number\n");
    }
    if(isNegativeNumber(b)){
        printf("b is negative number\n");
    } else{
        printf("b is positive number\n");
    }
    BigInt result;
    result.numbers = (char*)malloc(sizeof(char)*(a.length>b.length? a.length + 1:b.length + 1)); // 1 is store digit when lenght of result larger then origin a, b number
    int lenMax = a.length;
    if(a.length < b.length){
        lenMax = b.length;
    }
    int carry = 0, idxResult =0;
    for (int i = a.length - 1, j = b.length - 1; i >= 0 || j >=0; i--, j--, idxResult++){
        int aDigit = i >= 0 ? a.numbers[i] - 48 : 0; // -48 convert to natural number
        int bDigit = j >= 0 ? b.numbers[j] - 48 : 0;
        int sumOfDigit = aDigit + bDigit + carry;
        carry = sumOfDigit > 9 ? 1 : 0;
        result.numbers [idxResult] = sumOfDigit%10 + 48; //+46 48 convert to ascii
    }
    if (carry){
        result.numbers[idxResult] = '1';
        lenMax++;
    }
    //update memory store number
    result.length = lenMax;
    result.numbers[lenMax] = '\0';
    printf ("%s\n", result.numbers);
    reverse(result);
    printf ("%s", result.numbers);
    return result;
}
BigInt substract (BigInt a, BigInt b){

}

int main (){
    BigInt a = read();
    display (a);
    BigInt b = read();
    display (b);
    BigInt ad = add(a,b);

}
int isNegativeNumber (BigInt a){
    if(a.numbers[0] == '-'){
        return 1;
    }
    return 0;
}
void reverse (BigInt &a){
    for (int i = 0; i < a.length/2; i++){
        char temp = a.numbers[i];
        a.numbers[i] = a.numbers[a.length - i - 1];
        a.numbers[a.length - i - 1] = temp;
    } 
}
BigInt read(){
    char numberArray[MAX_DIGITS]; //Array store number when input
    printf("Enter new numbers: ");
    scanf ("%s",numberArray);
    // fgets(num, MAX_DIGITS, stdin);
    // if (num[strlen(num) - 1] == '\n')
    //     num[strlen(num) - 1] = '\0';
    int sizeOfNumberArray = strlen(numberArray);
//    printf("%d", sizeOfNumberArray);
    BigInt newBigNumber;
    newBigNumber.length = sizeOfNumberArray;
    newBigNumber.numbers = (char *)malloc(sizeOfNumberArray*sizeof(char));
    strcpy(newBigNumber.numbers, numberArray);
    return newBigNumber;
}
void display(BigInt a){
    int len = a.length;
    printf("Number:%*s\n", 12 + len, a.numbers); //format when print (12: distinct "Number:            ")
//    printf ("%d", len);
    
}