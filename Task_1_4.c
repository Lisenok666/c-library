#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 120
typedef char T;


typedef struct Stack_tag
{
    T data[STACK_MAX_SIZE];
    int size;
} Stack_t;


void push(Stack_t* stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(-1);
    }
    stack->data[stack->size] = value;
    stack->size++;
}


T pop(Stack_t* stack) {
    stack->size--;
    return stack->data[stack->size];
}
int main(int argc, char* argv[])
{
    Stack_t x;
    x.size = 0;
    unsigned int N = 1, delta = 1, i = 0;
    char* brace = (char*)malloc(sizeof(char) * N);
    while ((brace[i] = getchar()) != '\n')
    {
        ++i;
        N += delta;
        brace = (char*)realloc(brace, sizeof(char) * N);
    }
    if (brace[0] == '(' || brace[0] == '{' || brace[0] == '[') push(&x, brace[0]); //Правильное выражение начинается только с открывающей скобки
    else {
        if (i == 0) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    for (int j = 1; j < i; j++) {
        if (brace[j] == '(' || brace[j] == '{' || brace[j] == '[') { //Любую открывающую скобку добавляем в стек
            push(&x, brace[i]);
        }
        else
        {
            char c = pop(&x);
            //printf("%c %d", c, x.size);
            if (x.size >= 0 && ((brace[j] - ')' == c - '(') || (brace[j] - '}' == c - '{') || (brace[j] - ']' == c - '['))) {

            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
       
    }
    if (x.size == 0) printf("YES\n");//Правильное арифметическое выражение получим при пустом стэке
    else printf("NO\n");
    return 0;
}