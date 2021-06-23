class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST(object):
    def __init__(self):
        self.root = None

    def insert_node(self, data):
        new_node = Node(data)
        if self.root is None:
            self.root = new_node
            return

        current_node = self.root
        while current_node is not None:
            parent_node = current_node
            if data > current_node.data:
                current_node = current_node.right
            else:
                current_node = current_node.left

        if new_node.data < parent_node.data:
            parent_node.left = new_node
        else:
            parent_node.right = new_node

    def pre_order(self, node):
        if node is not None:
            self.pre_order(node.left)
            print(node.data)
            self.pre_order(node.right)

    def in_order(self, node):
        if node is not None:
            print(node.data)
            self.in_order(node.left)
            self.in_order(node.right)

    def post_order(self, node):
        if node is not None:
            self.post_order(node.left)
            self.post_order(node.right)
            print(node.data)


b_tree = BST()
b_tree.insert_node(3)
b_tree.insert_node(4)
b_tree.insert_node(1)
b_tree.insert_node(40)
b_tree.insert_node(0)
b_tree.insert_node(2)
# b_tree.pre_order(b_tree.root)
# b_tree.in_order(b_tree.root)
# b_tree.post_order(b_tree.root)
