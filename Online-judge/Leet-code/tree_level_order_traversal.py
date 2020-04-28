class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
    	ans = []
    	queue = []
    	queue.append(root)
    	while queue:
    		innner_list = []
    		size = len(queue)
    		for i in range(size):
    			current_node = queue.pop(0)
    			if current_node:
    				innner_list.append(current_node.val)

    			if current_node and current_node.left:
    				queue.append(current_node.left)
    			if current_node and current_node.right:
    				queue.append(current_node.right)
    		ans.append(innner_list)
    	return ans
