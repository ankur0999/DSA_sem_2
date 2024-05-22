#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
		int data;
        int BF;
		Node* left;
		Node* right;
        Node* parent;
        int height;
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
            this->parent = NULL;
            this->BF = 0;
            this->height = 0;
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
    Node* deleteData(int data){
        Node* d = searchData(root, data);
        
        if(d != NULL){
            if(d->parent){
                Node* p = d->parent;
                if(d->left == NULL || d->right == NULL){
                    deleteData(root, d);
                    return p;
                }
                else{
                    Node* q = getMin(d->right)->parent;
                    deleteData(root, d);
                    return q;
                }
                }
            else{
                if(d->left == NULL || d->right == NULL){
                    deleteData(root, d);
                    return NULL;
                    }
                else{
                    Node* q = getMin(d->right)->parent;
                    deleteData(root, d);
                    return q;
                }
            }}
            return NULL;
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
        levelorder(root);
    }
    void levelorder(Node* p);
    int Height(){
        return Height(root);
    }
    int Height(Node* root);
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
void BST:: levelorder(Node* root){
    if(root == NULL)
		return;
    
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* front = q.front();
		q.pop();
		if(front == NULL){
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
        
}
int BST:: Height(Node* root){
    if(root == NULL) return -1;

    int h = -1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            h++;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
    }
    return h;
}
class AVL : public BST{
    public:
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
        if(balFac(child->parent));
	        AVL_insertion(root, child);
        cin >> data;
    }
}
    void AVL_insertion(Node*& root, Node*& child);
    void balanceFactor(Node* root);
    bool balFac(Node*);
    void LL_Rotation(Node*& root, Node* x, Node* y);
    void RR_Rotation(Node*& root, Node* x, Node* y);
    void LR_Rotation(Node*& root, Node* x, Node* y);
    void RL_Rotation(Node*& root, Node* x, Node* y);
    void AVL_deletion();
};
void AVL:: balanceFactor(Node* root){
    if(root == NULL)
    return;
    Node* x = root;
    int h1 = 0;
    int h2 = 0;
    if(x->left ){
        h1 = Height(x->left) + 1;
        balanceFactor(x->left);
        }
    if(x->right){
        h2= Height(x->right) + 1;
        balanceFactor(x->right);
        }
    x->BF = h1 - h2;
}
bool AVL:: balFac(Node* root){
    Node* x  = root;
    while(x!= NULL){
        int h1 = Height(x->left) + 1;
        int h2 = Height(x->right) + 1;
        x->BF = h1 - h2;
        if(x->BF == 2 || x->BF == -2)
            return true;
        x = x->parent;
    }
    return false; 
}

void AVL:: AVL_insertion(Node*& root, Node*& child){
    Node* x = child;
    Node* y = NULL;
    
    while((x != NULL) && (x->BF == 0 || (x->BF == 1 || x->BF == -1))){
        y = x;
        x = x->parent;
    }
   
    if(x != NULL){
        
        if(x->BF == 2 && y->BF == 1){
            RR_Rotation(root,x,y);
            balanceFactor(x);
            }
        if(x->BF == -2 && y->BF == -1){
            LL_Rotation(root,x,y);
            balanceFactor(x);
            }
        if(x->BF == 2 && y->BF == -1){
            LR_Rotation(root,x,y);
            balanceFactor(x);
            }
        if(x->BF == -2 && y->BF == 1){
            RL_Rotation(root,x,y);
            balanceFactor(x);
            }
    }
}
void AVL:: RR_Rotation(Node*& root, Node* x, Node* y){
    if(x->parent == NULL){
        root = y;
        y->parent = NULL;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
        y->parent = x->parent;
    }
    else{
        x->parent->right = y;
        y->parent = x->parent;
    }

    Node* tmp = y->right;
    y->right = x;
    x->parent = y;
    x->left = tmp;
    if(tmp)
    tmp->parent = x;
    
}
void AVL:: LL_Rotation(Node*& root, Node* x, Node* y){
    if(x->parent == NULL)
        root = y;
    
    else if(x == x->parent->left)
        x->parent->left = y;
    
    else
        x->parent->right = y;
    
    y->parent = x->parent;
    Node* tmp = y->left;
    y->left = x;
    x->parent = y;
    x->right = tmp;
    if(tmp)
    tmp->parent = x;
    
}
void AVL:: LR_Rotation(Node*& root, Node* x, Node* y){
    Node* tmpL = y->right->left;
    Node* tmpR = y->right->right;
    if(x->parent == NULL)
        root = y->right;
    else if(x->parent->left == x){
        x->parent->left = y->right;
    }
    else if(x->parent->right == x){
        x->parent->right = y->right;
    }
    y->right->parent = x->parent;
    y->right->left = y;
    y->parent = y->right;
    y->right->right = x;
    x->parent = y->right;
    y->right = tmpL;
    if(tmpL)
    tmpL->parent = y;
    x->left = tmpR;
    if(tmpR)
    tmpR->parent = x;
}
void AVL:: RL_Rotation(Node*& root, Node* x, Node* y){
    Node* tmpL = y->left->left;
    Node* tmpR = y->left->right;
    if(x->parent == NULL)
        root = y->left;
    else if(x->parent->left == x)
        x->parent->left = y->left;
    else if(x->parent->right == x)
        x->parent->right = y->left;

    y->left->parent = x->parent;
    y->left->left = x;
    x->parent = y->left;
    y->left->right = y;
    y->parent = y->left;
    x->right = tmpL;
    if(tmpL)
    tmpL->parent = x;
    y->left = tmpR;
    if(tmpR)
    tmpR->parent = y;
    
}
void AVL:: AVL_deletion(){
    cout<<"Enter data: ";
    int d;
    cin>>d;
    Node* p = deleteData(d);
    balanceFactor(p);
    
    
    while((p != NULL) && (p->BF == 2 || p->BF == -2)|| p->BF == 0){
    
    
    
    if(p->BF == 2){
        
        if(p->left->BF == 1)
            RR_Rotation(root, p, p->left);
        else
            LR_Rotation(root, p, p->left);
        
        if(p->BF == 0){
                if(balFac(p)){
                p->parent;
                
                }
                else
                    return;
        }
        else
                return;
    }

    else if(p->BF == -2){
        
        if(p->right->BF == -1)
            LL_Rotation(root, p, p->right);
        
        else
            RL_Rotation(root, p, p->right);
        if(p->BF == 0){
            if(balFac(p))
                p->parent;
            else
                return;
        }
        else
            return;
    }
    else{
        
        if(balFac(p)){
                
                p = p->parent;
                }
                else
                    return;
        
        }
    }
}





int main(){
    AVL a;
    a.insertData();
    a.levelorder();
    a.AVL_deletion();
    a.levelorder();
    }

