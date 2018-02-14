Danny Sullivan and Nugzar Chkaidze - PA3 AVL README.txt

We added avl tree rotations to the binary search tree implementation, which would store the graph balanced.
We used http://www.geeksforgeeks.org/avl-tree-set-1-insertion/ for the implementation of avl rotations.
int height was added in the structure of node, which would hold the deepest level down from the vertex.
Leafs height is 1.
leftRotation
	Node's right child is taking place of the node. The node is becoming its right childs left child.
	Node's right child is becoming previously right child's left child.
RightRotation does the same as leftRotation symetrically.
Function getbalance returns the difference between left and right children's heights.
if node's balance is -1,0 or 1 it is considered to be balanced.
As new node is inserted in a balanced tree, any nodes balance can become 2 or -2. It can't become 3 or more or -3 or less because 1 node can only add 1 or substract 1.
When balance becomes 2 or -2 some rotations must be completed to make the tree balanced.
1)Left Left case when balance is 2 and added word is less than node's left child's string, so new word
was added left to the left child and diference between nodes left height is 2 more than right height.
We need to rotate right, so 1 is added to the right height, and 1 is substracted from left height and it will become ballanced.
2)Right right is the same as 1)symetrically
3)Left Right when balance is 2 and added word is more then left childs words string. That means that new word
was added right to the node's left child and height is 2 more on the way of the new string.
So we need to rotate left child to the left first, and then rotate node to the right.
4)Right Left is the same as 3) symetrically
