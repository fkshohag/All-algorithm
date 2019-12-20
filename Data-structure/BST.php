<?php
 error_reporting(E_ALL);
class Node {
	public $data;
	public $parent;
	public $left;
	public $right;

	public function __construct($data) {
		$this->data = $data;
		$this->parent = null;
		$this->left = null;
		$this->right = null;
	}
}

class BinarySearchTree {
	public $root;

	public function __construct() {
		$this->root = null;
	}

	public function insertNode($data) {
		$newNode = new Node($data);
		$currentNode = $this->root;
		$parentNode = null;

		if($currentNode == null) {
			$this->root = $newNode;
		} else {
			while ($currentNode != null) {
				$parentNode = $currentNode;
				if($newNode->data < $currentNode->data) {
					$currentNode = $currentNode->left;
				} else {
					$currentNode = $currentNode->right;
				}
			}
			
			$newNode->parent = $parentNode;
			if($newNode->data < $parentNode->data) {
				$parentNode->left = $newNode;
			} else {
				$parentNode->right = $newNode;
			}
		}
	}

	public function inOrderTreeWalk($node) {
		if ($node != null) {
			$this->inOrderTreeWalk($node->left);
			echo $node->data.' ';
			$this->inOrderTreeWalk($node->right);
		}
	}

	public function preOrderTreeWalk($node) {
		if ($node != null) {
			echo $node->data.' ';
			$this->inOrderTreeWalk($node->left);
			$this->inOrderTreeWalk($node->right);
		}
	}

	public function PostOrderTreeWalk ($node) {
		if ($node != null) {
			$this->inOrderTreeWalk($node->left);
			$this->inOrderTreeWalk($node->right);
			echo $node->data.' ';
		}
	}
}

$bst = new BinarySearchTree();
$bst->insertNode(10);
$bst->insertNode(9);
$bst->insertNode(34);
echo "Inorder (Left, Root, Right): ";
$bst->inOrderTreeWalk($bst->root);
echo "<br>";
echo "Preorder (Root, Left, Right): ";
$bst->preOrderTreeWalk($bst->root);
echo "<br>";
echo "Postorder (Left, Right, Root): ";
$bst->PostOrderTreeWalk($bst->root);
