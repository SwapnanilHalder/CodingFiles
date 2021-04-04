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

		avlTree() {
			this->root = NULL;
		}

		int height(Node *N) { 
			if (N == NULL) return 0; 
			return N->height; 
		} 

		// Function to create a new node with left and right child as NULL
		Node* newNode(int data) { 
			Node* node = new Node(); 
			node->data = data; 
			node->left = NULL; 
			node->right = NULL; 
			node->height = 1; 

			return(node); 
		} 

        // Right Rotate the node y
		Node *rightRotate(Node *y) { 
			Node *x = y->left; 
			Node *T2 = x->right; 

			// Perform rotation 
			x->right = y; 
			y->left = T2; 

			y->height = max(height(y->left), height(y->right)) + 1; 
			x->height = max(height(x->left), height(x->right)) + 1; 

			// Return new root 
			return x; 
		} 

        // Left Rotate the node x
		Node *leftRotate(Node *x) { 
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

		// Get height_diff factor of node N 
		int heightDiff(Node *N) { 
			if (N == NULL) 
				return 0; 
			return height(N->left) - height(N->right); 
		} 


        // Recursively insert a data in the subtree and return the new node of the subtree
		Node* insert(Node* node, int data) { 
			if (node == NULL) 
				return(newNode(data)); 


			if (data < node->data) 
				node->left = insert(node->left, data); 

			else if (data > node->data) 
				node->right = insert(node->right, data); 

			else 
				return node; 


			// update height
			node->height = 1 + max(height(node->left), height(node->right)); 

			int height_diff = heightDiff(node); 

			// Left Left Case 
			if (height_diff > 1 && data < node->left->data) 
				return rightRotate(node); 


			// Right Right Case 
			if (height_diff < -1 && data > node->right->data) 
				return leftRotate(node); 


			// Left Right Case 
			if (height_diff > 1 && data > node->left->data) { 
				node->left = leftRotate(node->left); 
				return rightRotate(node); 
			} 

			// Right Left Case 
			if (height_diff < -1 && data < node->right->data) { 
				node->right = rightRotate(node->right); 
				return leftRotate(node); 
			} 

			/* return the (unchanged) node pointer */
			return node; 
		}
 

        // Recursive function to delete a node from subtree and return root of the modified subtree
		Node* deleteNode(Node* root, int data) {  
  
		    if (root == NULL)  
		        return root;  
		  
		    if ( data < root->data )  
		        root->left = deleteNode(root->left, data);  
		  
		    else if( data > root->data )  
		        root->right = deleteNode(root->right, data);  

		    else {  
		        // node with only one child or no child  
		        if( (root->left == NULL) || (root->right == NULL) )  {  
		            Node *temp = root->left ?  
		                         root->left :  
		                         root->right;  
		  
		            // No child case  
		            if (temp == NULL)  {  
		                temp = root;  
		                root = NULL;  
		            }  
		            else // One child case  
		            *root = *temp;  
		            free(temp);  
		        }  
		        else {   
		            Node* temp = smallest(root->right);  

		            root->data = temp->data;  

		            root->right = deleteNode(root->right,  
		                                     temp->data);  
		        }  
		    }  

		    if (root == NULL)  return root;  

		    root->height = 1 + max(height(root->left), height(root->right));  
		  
		    int height_diff = heightDiff(root);  
		  
		    // Left Left Case  
		    if (height_diff > 1 &&  heightDiff(root->left) >= 0)  
		        return rightRotate(root);  
		  
		    // Left Right Case  
		    if (height_diff > 1 &&  heightDiff(root->left) < 0)  {  
		        root->left = leftRotate(root->left);  
		        return rightRotate(root);  
		    }  
		  
		    // Right Right Case  
		    if (height_diff < -1 &&  heightDiff(root->right) <= 0)  
		        return leftRotate(root);  
		  
		    // Right Left Case  
		    if (height_diff < -1 &&  heightDiff(root->right) > 0) {  
		        root->right = rightRotate(root->right);  
		        return leftRotate(root);  
		    }  
		  
		    return root;  
		} 

	    int get_height(Node* p) {
            if (!p) return 0;
            int left = get_height(p->left), right = get_height(p->right);
            return max(left, right)+1;
	    }

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
            cout << "Printing the AVL tree : \n";
	        helper(w, (string *)arr, root, 0, 0, w-1);
	        for(int i=0;i<h;i++){
	        	for(int j=0;j<w;j++) cout<<arr[i][j] << "   ";
                cout << "\n";
	        }
            cout << "\n";
	    }

	    Node* smallest(Node* root) {
	    	Node* temp = root;
	    	while(temp->left) temp = temp->left;
	    	return temp;
	    }

};

int main() { 
	avlTree tree;

	tree.root = tree.insert(tree.root, 6); 
	tree.root = tree.insert(tree.root, 1); 
	tree.root = tree.insert(tree.root, 2);
	tree.root = tree.insert(tree.root, 17);
	tree.root = tree.insert(tree.root, 12);
	tree.root = tree.insert(tree.root, 19);
	tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 11);

	tree.printTree(tree.root);

	tree.root = tree.deleteNode(tree.root, 15);
	tree.root = tree.deleteNode(tree.root, 11);

	tree.printTree(tree.root);

	return 0; 
}