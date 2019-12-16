/*
	This file Header_tree.h
	tree header
	Authora Daniil leskevich and  Oledg Nicolaev
	Created by NAMELESS TEAM 
*/
#pragma once
struct search_tree
{
    int key;
    struct search_tree* left;
    struct search_tree* right;
    char* string;
};

/*
 * Create tree
 * Params: key
 * Returns pointer to tree
 */
struct search_tree* new_tree(int item);

/* DFS
 * Params: pointer to the tree
 * Returns none
 */
void dfs(struct search_tree* tree);

//struct search_tree* wfs(struct search_tree* tree, int key) ;

struct search_tree* delete_pare(struct search_tree* tree, int key);

 /*
 * Insert elements in tree, create new_tree if tree == NULL
 * Params: key - pointer to the tree
 * Returns pointer to tree
 */
struct search_tree* insert(struct search_tree* tree, int key);

