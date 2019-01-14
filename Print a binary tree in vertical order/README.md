# Print a binary tree in vertical order

* You are given a binary tree for which you must print its vertical order traversal. your task is to complete the function verticalOrder which takes one argument the root of the binary tree and prints the node of the binary tree in vertical order.

## Testcase1:
```
    1
   /  ＼
  2    3
      /
     5
```
* As it is evident from the above diagram that during vertical traversal 2 will come first, then 1 and  5, and then 3. So output is 2 1 5 3

## Testcase2:

```
    1
   / ＼
  3   2
```

* As it is evident from the above diagram that during vertical traversal 3 will come first, then 1 and then 2. So output is 3 1 2
```c
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
	int data;
	Node* left;
	Node* right;
}; */

void verticalOrder(Node *root)
{
	//Your code here
}
```

## Solution
* The idea is to traverse the tree once and get the minimum and maximum horizontal distance with respect to root. For the tree shown above, minimum distance is -2 (for node with value 4) and maximum distance is 3 (For node with value 9).
* Once we have maximum and minimum distances from root, we iterate for each vertical line at distance minimum to maximum from root, and for each vertical line traverse the tree and print the nodes which lie on that vertical line.
