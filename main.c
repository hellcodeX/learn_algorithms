#include "binarytrees.h"

int main() {
    Tree* tree = new_tree(DECIMAL_ELEM, STRING_ELEM);

    set_tree(tree, decimal(50), string("A"));

    del_tree(tree, decimal(50));

    print_tree(tree);
    print_tree_as_list(tree);

    set_tree(tree, decimal(40), string("B"));

    print_tree(tree);
    print_tree_as_list(tree);
    free_tree(tree);
    return 0;
}