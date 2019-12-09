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
};


struct search_tree* new_tree(int item);

void dfs(struct search_tree* tree);

//struct search_tree* wfs(struct search_tree* tree, int key) ;

void delete_pare(struct search_tree* tree, int key);

struct search_tree* insert(struct search_tree* tree, int key);
