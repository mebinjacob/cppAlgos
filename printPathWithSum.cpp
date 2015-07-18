#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};

public void findSum(Node node, int sum, int[] path, int level)
{
	if(node == null)
		return;
	
	/*Insert current node into path.*/
	path[level] = node.data;
	
	/* Look for paths with a sum that ends at this node.*/
	int t = 0;
	for(int i = level; i >= 0; i--){
		t += path[i];
		if(t == sum){
			print(path, i, level);
		}
	}
	
	/* Search nodes beneath this one. */
	findSum(node.left, sum, path, level + 1);
	findSum(node.right, sum, path, level + 1);

	/* 
	* Remove current node from path. Not strictly necessary, since
	* we would ignore this value, but it's a good practice.
	*/
	path[level] = Integer.MIN_VALUE;
}

public void findSum(Node node, int sum){
	int depth = depth(node);
	int[] path = new int[depth];
	findSum(node, sum, path, 0);
}

public static void print(int[] path, int start, int end){
	for(int i = start; i <= end; i++)
	{
		System.out.print(path[i] + " " );
	}
	System.out.println();
}

public int depth(Node root){
	if(root == NULL) return 0;
	else{
		return 1 + Math.max(depth(node.left), depth(node.right));
	}
}
