# Binary search tree with insert and delete operations

class BinaryTreeNode:
    def __init__(self, key, val = 0, parent = None, left = None, right = None):
        self.key = key
        self.val = val
        self.parent = parent
        self.left = left
        self.right = right

    def hasLeftChild(self):
        return self.left

    def hasRightChild(self):
        return self.right

    def isLeftChild(self):
        return self.parent and self.parent.left == self

    def isRightChild(self):
        return self.parent and self.parent.right == self

    def isRoot(self):
        return not self.parent

    def isLeaf(self):
        return not (self.left or self.right)

    def hasBothChildren(self):
        return self.left and self.right

    def replaceNodeData(self, key, val, left, right):
        self.key = key
        self.val = val
        self.left = left
        self.right = right
        if self.hasLeftChild():
            self.left.parent = self
        if self.hasRightChild():
            self.right.parent = self


class BinarySearchTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def length(self):
        return self.size

    def insert(self, key, val = 0):
        if self.root:
            self._insert(key, val, self.root)
        else:
            self.root = BinaryTreeNode(key, val)
        self.size += 1

    def _insert(self, key, val, current_node):
        if key < current_node.key:
            if current_node.hasLeftChild():
                self._insert(key, val, current_node.left)
            else:
                current_node.left = BinaryTreeNode(key, val, parent = current_node)
        else:
            if current_node.hasRightChild():
                self._insert(key, val, current_node.right)
            else:
                current_node.right = BinaryTreeNode(key, val, parent = current_node)
