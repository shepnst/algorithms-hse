#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

double stack[SIZE];

int top = -1;
double pop() {
    return stack[top--];
}

double push(double el) {
    return stack[++top] = el;
}

int priority(char token) {
    switch (token) {
 
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int top = -1;

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            while (isalnum(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (token == '(') {
            stack[++top]=token;
        }
        else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            top--;
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(token)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = token;
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';

    }

    postfix[j] = '\0';
}


int evaluation(char* postfix) {
    double operand1, operand2;
    char* token = strtok(postfix, " ");
    while (token) {
        if (isalnum(*token)) {
            push(atof(token));
        }
        else {
            operand2 = pop();
            operand1 = pop();
            switch (*token) {
            case '+':push(operand1 + operand2); break;
            case '-':push(operand1 - operand2); break;
            case '*':push(operand1 * operand2); break;
            case '/':push(operand1 / operand2); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char infix[SIZE];
    char postfix[SIZE];
    fgets(infix, SIZE, stdin);
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[--len] = '\0';
    }
    infixToPostfix(infix, postfix);
    printf("Expression:\n");
    printf("%s", infix);
    printf("\nReverse Polish Notation:\n");
    printf("%s", postfix);
    int result = evaluation(postfix);
    printf("\nResult:");
    printf("\n");
    printf("%d", result);

}
