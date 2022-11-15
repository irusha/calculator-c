#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int arrayRealLength(const char array[]){
    int count = 0;

    while (array[count] != NULL){
        count++;
    }
    return count;
}

int bigArrayRealLength(const char *array[]){
    int count = 0;

    while (array[count] != NULL){
        count++;
    }
    return count;
}

char* refinedArray(char array[]){
    char *tempStr = malloc(arrayRealLength(array) + 1);
    for (int i = 0; i < arrayRealLength(array); ++i) {
        tempStr[i] = array[i];
    }
    tempStr[arrayRealLength(array)] = '\0';

    return tempStr;
}

char *expressionEncoder(const char *array){
    int numberCount = 0;
    int operationsCount = 0;
    char operations[100];
    char numbers[100];
    for (int i = 0; i < arrayRealLength(array); ++i) {
        if(isdigit(array[i])){
            numbers[numberCount] = array[i];
            numberCount ++;
        }

        else if(array[i] == '+' || array[i] == '*' || array[i] == '/' || array[i] == '-'){
            numbers[numberCount] = ',';
            numberCount++;

            operations[operationsCount] = array[i];
            operationsCount++;
        }

    }
    return strcat(strcat(refinedArray(numbers), "&"), refinedArray(operations));
}

double expressionDecoder(char *expression){
    char * token = strtok(expression, "&");
    // loop through the string to extract all other tokens
    int count = 0;
    char *splitItems[2];
    while( token != NULL ) {
        splitItems[count] = token;
        token = strtok(NULL, "&");
        count++;
    }

    int isSIgnAtFirst = 0;
    char firstSign;
    char *numbersToBeCalculated[100];
    char *numTokens = strtok(splitItems[0], ",");

    for (int i = 0; i < strlen(splitItems[0]); ++i) {
        if(i == 0 && splitItems[0][i] == ','){
            if(splitItems[1][0] == '*' || splitItems[1][0] == '/'){
                isSIgnAtFirst = 2;

            } else{
                isSIgnAtFirst = 1;
                firstSign = splitItems[1][0];

            }
        }
    }

    count = 0;
    while( numTokens != NULL ) {
        numbersToBeCalculated[count] = numTokens;
        numTokens = strtok(NULL, ",");
        count++;
    }

    char *ptr;
    double result;

    if(splitItems[1][0] == '*' || splitItems[1][0] == '/'){
        result = 1;
    } else{
        result = 0;
    }

    printf("%s\n", numbersToBeCalculated[0]);
    bool ranFirstTime = false;
    for (int i = 0; i < bigArrayRealLength((const char **) numbersToBeCalculated); ++i) {
        if(isSIgnAtFirst == 1 || isSIgnAtFirst == 2){
            if (splitItems[1][i] == '+'){
                result = result + strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '-'){
                result = result - strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '*'){
                result = result * strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '/'){
                result = result / strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            }
        } else{

            if (splitItems[1][i] == '+'){
                result = result + strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '-'){
                result = result - strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '*'){
                result = result * strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            } else if (splitItems[1][i] == '/'){
                result = result / strtod(numbersToBeCalculated[i], &ptr);
                printf("%.3f\n", result);
            }
        }
    }




}

void mainApp() {
    char inputStr[100];
    scanf("%s", inputStr);

    int arrLen = arrayRealLength(inputStr);

    char *encodedExpression = expressionEncoder(inputStr);
    expressionDecoder(encodedExpression);

    if(arrLen == NULL){
        arrLen = 0;
    }
}


int main(){
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    for(;;){
        mainApp();
    }
#pragma clang diagnostic pop
}

