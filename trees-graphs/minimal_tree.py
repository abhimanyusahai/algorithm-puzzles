# Given a sorted array in increasing order of unique integers, write an algorithm to create a binary search tree with minimal height

import numpy as np
from bst import BinaryTreeNode, BinarySearchTree
import tree_traversal


def create_minimal_bst(arr):
    if len(arr) == 1:
        tree = BinarySearchTree()
        tree.insert(arr[0])
        return tree
    else:
        tree = BinarySearchTree()
        tree.insert(arr[len(arr)/2])
        tree.root.left = create_minimal_bst(arr[:len(arr)/2]).root
        if len(arr) > 2:
            tree.root.right = create_minimal_bst(arr[(len(arr)/2 + 1):]).root
        return tree


def main():
    arr = [0, 1, 4, 5, 6, 9, 10, 11, 16, 17]
    b = create_minimal_bst(arr)
    tree_traversal.inorder(b)


if __name__ == "__main__":
    main()
