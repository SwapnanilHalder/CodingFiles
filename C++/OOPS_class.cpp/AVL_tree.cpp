#include <iostream>
using namespace std; 

// An AVL tree node 
class Node { 
	public: 
	int data; 
	Node *left; 
	Node *right; 
	int height; 
}; 
 
class avlTree{
	public:

		Node *root;

		avlTree(){
			this->root = NULL;
		}

		// A utility function to get the 
		// height of the tree 
		int height(Node *N) 
		{ 
			if (N == NULL) return 0; 
			return N->height; 
		} 



		/* Helper function that allocates a 
		new node with the given data and 
		NULL left and right pointers. */
		Node* newNode(int data) 
		{ 
			Node* node = new Node(); 
			node->data = data; 
			node->left = NULL; 
			node->right = NULL; 
			node->height = 1; // new node is initially 
							// added at leaf 
			return(node); 
		} 

		// A utility function to right 
		// rotate subtree rooted with y 
		// See the diagram given above. 
		Node *rightRotate(Node *y) 
		{ 
			Node *x = y->left; 
			Node *T2 = x->right; 

			// Perform rotation 
			x->right = y; 
			y->left = T2; 

			// Update heights 
			y->height = max(height(y->left), 
							height(y->right)) + 1; 
			x->height = max(height(x->left), 
							height(x->right)) + 1; 

			// Return new root 
			return x; 
		} 

		// A utility function to left 
		// rotate subtree rooted with x 
		// See the diagram given above. 
		Node *leftRotate(Node *x) 
		{ 
			Node *y = x->right; 
			Node *T2 = y->left; 

			// Perform rotation 
			y->left = x; 
			x->right = T2; 

			// Update heights 
			x->height = max(height(x->left),	 
							height(x->right)) + 1; 
			y->height = max(height(y->left), 
							height(y->right)) + 1; 

			// Return new root 
			return y; 
		} 

		// Get Balance factor of node N 
		int getBalance(Node *N) 
		{ 
			if (N == NULL) 
				return 0; 
			return height(N->left) - height(N->right); 
		} 

		// Recursive function to insert a data 
		// in the subtree rooted with node and 
		// returns the new root of the subtree. 
		Node* insert(Node* node, int data) 
		{ 
			/* 1. Perform the normal BST insertion */
			if (node == NULL) 
				return(newNode(data)); 


			if (data < node->data) 
				node->left = insert(node->left, data); 

			else if (data > node->data) 
				node->right = insert(node->right, data); 

			else // Equal datas are not allowed in BST 
				return node; 


			/* 2. Update height of this ancestor node */
			node->height = 1 + max(height(node->left), 
								height(node->right)); 

			/* 3. Get the balance factor of this ancestor 
				node to check whether this node became 
				unbalanced */


			int balance = getBalance(node); 

			// If this node becomes unbalanced, then 
			// there are 4 cases 


			// Left Left Case 
			if (balance > 1 && data < node->left->data) 
				return rightRotate(node); 


			// Right Right Case 
			if (balance < -1 && data > node->right->data) 
				return leftRotate(node); 


			// Left Right Case 
			if (balance > 1 && data > node->left->data) 
			{ 
				node->left = leftRotate(node->left); 
				return rightRotate(node); 
			} 


			// Right Left Case 
			if (balance < -1 && data < node->right->data) 
			{ 
				node->right = rightRotate(node->right); 
				return leftRotate(node); 
			} 


			/* return the (unchanged) node pointer */
			return node; 
		}

		// Recursive function to delete a node  
		// with given data from subtree with  
		// given root. It returns root of the  
		// modified subtree.  
		Node* deleteNode(Node* root, int data)  
		{  
		      
		    // STEP 1: PERFORM STANDARD BST DELETE  
		    if (root == NULL)  
		        return root;  
		  
		    // If the data to be deleted is smaller  
		    // than the root's data, then it lies 
		    // in left subtree  
		    if ( data < root->data )  
		        root->left = deleteNode(root->left, data);  
		  
		    // If the data to be deleted is greater  
		    // than the root's data, then it lies  
		    // in right subtree  
		    else if( data > root->data )  
		        root->right = deleteNode(root->right, data);  
		  
		    // if data is same as root's data, then  
		    // This is the node to be deleted  
		    else
		    {  
		        // node with only one child or no child  
		        if( (root->left == NULL) || 
		            (root->right == NULL) )  
		        {  
		            Node *temp = root->left ?  
		                         root->left :  
		                         root->right;  
		  
		            // No child case  
		            if (temp == NULL)  
		            {  
		                temp = root;  
		                root = NULL;  
		            }  
		            else // One child case  
		            *root = *temp; // Copy the contents of  
		                           // the non-empty child  
		            free(temp);  
		        }  
		        else
		        {  
		            // node with two children: Get the inorder  
		            // successor (smallest in the right subtree)  
		            Node* temp = smallest(root->right);  
		  
		            // Copy the inorder successor's  
		            // data to this node  
		            root->data = temp->data;  
		  
		            // Delete the inorder successor  
		            root->right = deleteNode(root->right,  
		                                     temp->data);  
		        }  
		    }  
		  
		    // If the tree had only one node 
		    // then return  
		    if (root == NULL)  
		    return root;  
		  
		    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
		    root->height = 1 + max(height(root->left),  
		                           height(root->right));  
		  
		    // STEP 3: GET THE BALANCE FACTOR OF  
		    // THIS NODE (to check whether this  
		    // node became unbalanced)  
		    int balance = getBalance(root);  
		  
		    // If this node becomes unbalanced,  
		    // then there are 4 cases  
		  
		    // Left Left Case  
		    if (balance > 1 &&  
		        getBalance(root->left) >= 0)  
		        return rightRotate(root);  
		  
		    // Left Right Case  
		    if (balance > 1 &&  
		        getBalance(root->left) < 0)  
		    {  
		        root->left = leftRotate(root->left);  
		        return rightRotate(root);  
		    }  
		  
		    // Right Right Case  
		    if (balance < -1 &&  
		        getBalance(root->right) <= 0)  
		        return leftRotate(root);  
		  
		    // Right Left Case  
		    if (balance < -1 &&  
		        getBalance(root->right) > 0)  
		    {  
		        root->right = rightRotate(root->right);  
		        return leftRotate(root);  
		    }  
		  
		    return root;  
		} 

		// A utility function to print preorder 
		// traversal of the tree. 
		// The function also prints height 
		// of every node 

	    int get_height(Node* p) {
	            if (!p) return 0;
	            int left = get_height(p->left), right = get_height(p->right);
	            return max(left, right)+1;
	    }
	    // width is the max(left, right)*2+1
	    int get_width(Node* p) {
	            if (!p) return 0;
	            int left = get_width(p->left), right = get_width(p->right);
                int w =  max(left, right)*2+1;
	            return max(left, right)*2+1;
	    }

	    // always put the value in the middle of the range.
	    int h,w;
	    void helper(int w, string *arr, Node* p, int level, int l, int r) {
	            if (!p) return;
	            int mid = l+(r-l)/2;
	            *((arr+level*w)+mid) = to_string(p->data);
	            helper(w, arr, p->left, level+1, l, mid-1);
	            helper(w, arr, p->right, level+1, mid+1, r);
	    }

	    void printTree(Node* root) {
	        h = get_height(root );
            w = get_width(root);

	        string arr[h][w];

	        helper(w, (string *)arr, root, 0, 0, w-1);
	        for(int i=0;i<h;i++){
	        	for(int j=0;j<w;j++) cout<<arr[i][j] << "  ";
                cout << "\n";
	        }
            cout << "\n";
	    }

	    Node* smallest(Node* root){
	    	Node* temp = root;
	    	while(temp->left) temp = temp->left;
	    	return temp;
	    }

	    void avlSort(Node* root, int n){
	    	int sortedArr[n], i=0;
	    	while(root){
	    		int small = smallest(root)->data;
	    		sortedArr[i++] = small;
	    		root = deleteNode(root, small);
	    	}

	    	cout<<"The sorted array is : ";
			for(int i=0; i<n; i++) cout<<sortedArr[i]<<" ";
			cout<<endl;
	    } 

};

// Driver Code 
int main() 
{ 
	avlTree tree;

	tree.root = tree.insert(tree.root, 6); 
	tree.root = tree.insert(tree.root, 1); 
	tree.root = tree.insert(tree.root, 2);
	tree.root = tree.insert(tree.root, 17);
	tree.root = tree.insert(tree.root, 12);
	tree.root = tree.insert(tree.root, 19);
	tree.root = tree.insert(tree.root, 15);

	tree.printTree(tree.root);

	tree.root = tree.deleteNode(tree.root, 15);
	tree.root = tree.deleteNode(tree.root, 6);

	tree.printTree(tree.root);

	avlTree tree2;
	int arr[10] = {9, 11, 3, 51, 77, 33, 900, 12, 150, 245};
	int size = *(&arr + 1) - arr;
	for(int i=0; i<size ; i++){
		tree2.root = tree2.insert(tree2.root, arr[i]);
	}

	tree2.avlSort(tree2.root, size);
	
	return 0; 
}