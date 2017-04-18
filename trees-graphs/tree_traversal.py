# Implement pre-order, in-order and post-order tree traversals

def inorder(t):
    node = t.root
    _inorder(node)

def _inorder(node):
    if not node == None:
        _inorder(node.left)
        print node.key
        _inorder(node.right)
 
