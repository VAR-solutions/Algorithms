// Calculates the height of binary Search Tree in Javascript

class TreeNode
{
	/* TreeNode Structure:
	 *       val
	 *       / \
	 *    left  right
	 */
	constructor(val,lNode=null,rNode=null)
	{
		this.val=val;
		this.left=lNode;
		this.right=rNode;
	}
};


class BinarySearchTree
{
	constructor(rootVal=null)
	{
		this._numOfNodes=0;
		this.root=null;
		if(rootVal!=null)
		{
			this._numOfNodes++;
			this.root=new TreeNode(rootVal);
		}
	}
	get number_of_nodes()
	{
		return this._numOfNodes;
	}
	
	
	//Inserts Values into the BST
	insert(newVal)
	{
		if(this.root==null)
		{
			this.root=new TreeNode(newVal);
			return 1;
		}
		let cur=this.root;
		
		while(cur!=null)
		{
			if(cur.val>newVal)
			{
				if(cur.left!=null)
					cur=cur.left;
				else
				{
					cur.left=new TreeNode(newVal);
					break;
				}
			}
			else if(cur.val<newVal)	
			{
				if(cur.right!=null)
					cur=cur.right;
				else
				{
					cur.right=new TreeNode(newVal);
					break;
				}
			}
			else
				return null;
		}
		
		this._numOfNodes++;
	}
	
	/* Height refers to the number of nodes
	 * in the longest path from root to some 
	 * leaf node
	*/
	/*      O         <------ Height:1
	 * 
	 *      O
	 * 	   / \
	 * 	  O   O        <---- Height:2
	 * 
	 *      O
	 * 	   / 
	 * 	  O            <---- Height:2   
	 * 
	 * Some books also use number of edges 
  	 */
	height(start=this.root)
	{
		if(start==null)
			return 0;
		let lh=this.height(start.left);	
		let rh=this.height(start.right);
		
		return Math.max(lh,rh)+1;
	}
};


let B =new BinarySearchTree();
B.insert(4);
B.insert(2);
B.insert(3);
B.insert(1);
B.insert(6);
/*
 * Final Tree:
 * 
 *      4
 *     / \
 *    2   6
 *   / \
 *  1   3
 * 
 * */
console.log(B.height());
