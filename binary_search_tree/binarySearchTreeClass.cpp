#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
		int data;
        
		Node* left;
		Node* right;
        Node* parent;
		Node(int data){
			this->data = data;
			this->left = NULL;    
			this->right = NULL;
            this->parent = NULL;
            
		}};

class BST{
    protected:
    Node* root;
    
    int height;
    public:
    BST(){
        root = NULL;
        
        height = -1;
    }

    
    void insertData(){
        insertData(root);
    }
    void insertData(Node*& root){
    cout<<"insert Element: "<<endl;
	int data;
	cin>>data;
	while(data != -1){
        Node* child = new Node(data);
	    BST_insertion(root, child);
	    cin >> data;
	}
    }
    void BST_insertion(Node*& p, Node*& c);
    void getMax(){
        getMax(root);
    }
    Node* getMax(Node* p);
    void getMin(){
        getMin(root);
    }
    Node* getMin(Node* p);
    Node* searchData(Node* root, int data);
    void deleteData(int data){
        Node* d = searchData(root, data);
        if(d != NULL)
        deleteData(root, d);
    }
    void deleteData(Node*& p, Node*& data);
    void preorder(){
        preorder(root);
    }
    void preorder(Node* p);
    void postorder(){
        postorder(root);
    }
    void postorder(Node* p);
    void inorder(){
        inorder(root);
    }
    void inorder(Node* p);
    void levelorder(){
        cout<<"level order traversal is "<<endl;
        height = levelorder(root);
    }
    int levelorder(Node* p);
    int Height(){
        return height;
    }
    void Transplant(Node*& root, Node*& u, Node*& v);
    ~BST(){
        postorderDeletion(root);
    }
    void postorderDeletion(Node* root);
    

};

void BST:: postorderDeletion(Node* root){
    if(root == NULL) return;
    postorderDeletion(root->left);
    postorderDeletion(root->right);
    delete[] root;
}
Node* BST:: searchData(Node* root, int data){
    Node* x = root;
    while(x != NULL){
        if(x->data == data) return x;
        else if(x->data < data)
            x = x->right;
        else
            x = x->left;
    }
    return x;
}
Node* BST:: getMin(Node* root){
    if(root == NULL)
		return NULL;
	Node* tmp = root;
	while(tmp->left != NULL)
            tmp = tmp->left;
	return tmp;
}
Node* BST:: getMax(Node* root){
    if(root == NULL)
		return NULL;
	Node* tmp = root;
	while(tmp->right != NULL)
		tmp = tmp->right;
	return tmp;
}
void BST:: BST_insertion(Node*& root, Node*& child){
        Node* y = NULL;
        Node* x = root;
        while(x != NULL){
            y = x;
            if(child->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        child->parent = y;
        if(y == NULL)
            root = child;
        else if(child->data < y->data)
            y->left = child;
        else
            y->right = child;
    }

void BST:: deleteData(Node*& root, Node*& d){
	if(d->left == NULL)
        Transplant(root, d, d->right);
    else if(d->right == NULL)
        Transplant(root, d, d->left);
    else{
        Node* mini = getMin(d->right);
        if(mini->parent != d){
            Transplant(root, mini, mini->right);
            mini->right = d->right;
            mini->right->parent = mini;
        }
        Transplant(root, d, mini);
        mini->left = d->left;
        mini->left->parent = mini;
    }
    
}
void BST:: Transplant(Node*& root, Node*& u, Node*& v){
    if(u->parent == NULL)
        root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != NULL){
        v->parent = u->parent;
    }
}
void BST:: preorder(Node* root){
	if(root == NULL)
		return;
	cout<< root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void BST:: inorder(Node* root){

	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data <<" ";
	inorder(root->right);
}
void BST:: postorder(Node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
int BST:: levelorder(Node* root){
    if(root == NULL)
		return -1;
    int h = -1;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* front = q.front();
		q.pop();
		if(front == NULL){
            h++;
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout<<front->data<<" ";
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
		}}
        return h;
}





int main(){
    BST a;
    a.insertData();
    a.levelorder();
    cout<<"height of tree is "<<a.Height()<<endl;
    a.deleteData(5);
    a.levelorder();
    
    }

