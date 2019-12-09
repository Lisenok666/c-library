/*
    This file tree-library.c
    realization of fucntion without wft
    Author Leskecvich Daniil and Oleg Nicolaev
    Created by NAMELESS TEAM
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include "Header_tree.h"


struct search_tree* new_tree(int item)
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

void delete_pare(struct search_tree* tree, int key) {}

struct search_tree* insert(struct search_tree* tree, int key) 
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
        printf("%d \n", tree->key);
        dfs(tree->right);
    }
}
