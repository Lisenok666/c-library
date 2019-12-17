/*
    This file tree-library.c
    realization of fucntion without wft
    Author Leskecvich Daniil and Oleg Nicolaev
    Created by NAMELESS TEAM
*/

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



struct search_tree* new_tree(long long int item)
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
    return temp;
}



//struct search_tree* wfs(struct search_tree* tree, int key) {}

//
void delete_pare(struct search_tree* tree, long long int key) {}

struct search_tree* insert(struct search_tree* tree, long long int key)
{
    if (tree == NULL)
    {
        return new_tree(key);
    }

    if (key < tree->key)
        tree->left = insert(tree->left, key);
    else if (key > tree->key)
        tree->right = insert(tree->right, key);
    return tree;
}
void dfs(struct search_tree* tree)
{
    if (tree != NULL)
    {
        dfs(tree->left);
        printf("%lld \n", tree->key);
        dfs(tree->right);
    }
}

int main(void)
{
    char* comand = NULL;
    scanf("%s", comand);
    //
    char* strtok(char* comand, const char a  );
}