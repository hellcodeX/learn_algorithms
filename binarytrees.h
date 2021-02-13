#ifndef BINARYTREES_BINARYTREES_H
#define BINARYTREES_BINARYTREES_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    DECIMAL_ELEM,
    REAL_ELEM,
    STRING_ELEM
} vtype_tree_t;

typedef union {
    int64_t decimal;
    double real;
    uint8_t* string;
} value_tree_t;

typedef struct tree_node {
    struct {
        value_tree_t key;
        value_tree_t value;
    } data;
    struct tree_node* left;
    struct tree_node* right;
    struct tree_node* parent;
} tree_node;

typedef struct Tree {
    struct {
        vtype_tree_t key;
        vtype_tree_t value;
    } type;
    struct tree_node* node;
} Tree;

Tree* new_tree(vtype_tree_t key, vtype_tree_t value);
void free_tree(Tree* tree);

value_tree_t get_tree(Tree* tree, void* key);
void set_tree(Tree* tree, void* key, void* value);
void del_tree(Tree* tree, void* key);
_Bool in_tree(Tree* tree, void* key);

void* decimal(int64_t x);
void* string(uint8_t* x);
void* real(double x);

void print_tree(Tree* tree);
void print_tree_as_list(Tree* tree);

static tree_node* _new_node(vtype_tree_t tkey, vtype_tree_t tvalue,  void* key,void* value);
static void _set_key(tree_node* node,  vtype_tree_t tkey, void* key);
static void _set_value(tree_node* node,  vtype_tree_t tvalue, void* value);
static void _set_tree(tree_node* node, vtype_tree_t tkey, vtype_tree_t tvalue, void* key, void* value);
static void _print_tree(tree_node* node, vtype_tree_t tkey, vtype_tree_t tvalue);
static void _print_tree_as_list(tree_node* node, vtype_tree_t tkey, vtype_tree_t tvalue);
static void _print_tree_elem(tree_node* node, vtype_tree_t tkey, vtype_tree_t tvalue);
static void _free_tree(tree_node* node);
static tree_node* _get_tree(tree_node* node, vtype_tree_t tkey, void* key);
static tree_node* _del1_tree(Tree* tree, vtype_tree_t tkey, void* key);
static void _del3_tree(tree_node* node);
static void _del2_tree(Tree* tree, tree_node* node);

#endif //BINARYTREES_BINARYTREES_H
