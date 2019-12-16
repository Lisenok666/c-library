#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>

struct search_tree
{
    long long int key;
    struct search_tree* left;
    struct search_tree* right;
    char* last_name;
    long long int number;
};



struct search_tree* new_tree(long long int item, char * last_name, long long int number)
{
    struct search_tree* temp = (struct search_tree*)malloc(sizeof(struct search_tree));
    if (NULL == temp)
    {
        printf("Memmory eror\n");
        return NULL;
    }
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    temp->last_name = last_name;
    temp->number = number;
    return temp;
}



//struct search_tree* wfs(struct search_tree* tree, int key) {}

//
//void delete_pare(struct search_tree* tree, long long int key) {}

struct search_tree* insert(struct search_tree* tree, long long int key, char* last_name, long long int number)
{
    if (tree != NULL)
    {
        printf("%s %lld\n", tree->last_name, tree->number);
    }
    if (tree == NULL)
    {
        printf("OK_1\n");
        return new_tree(key, last_name, number);
    }
    if (key == tree->key)
    {
        printf("Change old value = %lld\n", tree->number);
        tree->key = key;
        tree->last_name = last_name;
        tree->number = number;
        return tree;
    }
    else if (key < tree->key)
        tree->left = insert(tree->left, key, last_name, number);
    else if (key > tree->key)
        tree->right = insert(tree->right, key, last_name, number);
    printf("OK\n");
    //tree->key = key;
    //tree->last_name = last_name;
    //tree->number = number;
    return tree;
}
void dfs(struct search_tree* tree, long long int key)
{
    //printf("%lld\n", tree->key);
    if (NULL != tree && key == tree->key)
    {
        printf("%s %lld\n", tree->last_name, tree->number);
    }
    else if(tree != NULL)
    {
        dfs(tree->left, key);
        //printf("%lld \n", tree->key);
        dfs(tree->right, key);
    }
    else 
    {
        printf("NO");
    }

}
void Hashing(struct search_tree* tree, int action)
{
    long long int item = 0, number = 0;
    unsigned int N = 1, delta = 1, i = 0;
    char* brace = (char*)malloc(sizeof(char) * N);
    while ((brace[i] = getchar()) != ' ' && brace[i] != ',' && brace[i] != '.')
    {
        item = item*10 + brace[i] - '@';
        ++i;
        //printf("%lld\n", item);
        N += delta;
        brace = (char*)realloc(brace, sizeof(char) * N);
    }
    //printf("%s1\n", brace);
    brace[i] = '\0';
    printf("%lld %s %lld\n",item, brace, number);
    if (action)
    {
        for (int j = 0; j < 7; j++)
        {
            int temp = getchar() - '0';
            number = number * 10 + temp;
            printf("%lld\n", number);
        }
        tree = insert(tree, item, brace, number);
        //printf("%s\n", tree->last_name);
    }
    else
    {
        printf("\n work1 \n");
        dfs(tree, item);
    }

}

int main(void)
{
    struct search_tree* tree = NULL;
    do
    {
        unsigned int N = 1, delta = 1, i = 0;
        char* brace = (char*)malloc(sizeof(char) * N);
        while ((brace[i] = getchar()) != ' ')
        {
            if (brace[i] == '.')
            {
                return 0;
            }
            ++i;
            N += delta;
            brace = (char*)realloc(brace, sizeof(char) * N);
        }
        //printf("%s1\n", brace);
        brace[i] = '\0';
        //printf("%s\n", brace);
        if (strcmp(brace, "FIND") == 0)
        {
            printf("1");
            Hashing(tree, 0);
        }
        else if (strcmp(brace, "INSERT") == 0)
        {
            Hashing(tree, 1);
            printf("%s\n", tree->last_name);
        }
    } while (getchar() != ' ' && getchar() != '.');
    printf("\n work \n");
    return 0;
}
