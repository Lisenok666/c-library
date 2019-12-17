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

/*
 * Create tree
 * Params: key
 * Returns pointer to tree
 */
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

struct search_tree* delete_pare(struct search_tree* tree, int key)
{
    //struct search_tree* temp = tree;

    /*if (tree == NULL)
        return tree;

    if (key < tree->key)
    {
        tree->left = delete_pare(tree->left, key);
    }
    else if (key > tree->key)
    {
        tree->right = DeleteNode(tree->right, key);
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        tree->key = Minimum(tree->right)->key;
        tree->right = delete_pare(tree, tree->right->key);
    }
    else if (tree->left != NULL)
    {
        
        tree = tree->left;
    }
    else
    {
        tree = tree->right;
    }

    return tree;*/
}
/*
 * Insert elements in tree, create new_tree if tree == NULL
 * Params: key - pointer to the tree
 * Returns pointer to tree
 */
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
/* DFS
 * Params: pointer to the tree
 * Returns none
 */
void dfs(struct search_tree* tree)
{
    if (tree != NULL)
    {
        dfs(tree->left);
        printf("%d \n", tree->key);
        dfs(tree->right);
    }
}
