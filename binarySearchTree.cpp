#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
            }};

class Tree{
    Node* root;
    public:    
        Tree(){
           root = NULL;
            }

        bool search_data(Node* root, int data){
            if(root == NULL) return false;
            else{
                if(root->data == data) return true;
                else if(root->data > data) return search_data(root->left, data);
                else return search_data(root->right, data);
            }
        }

        bool search(int data){
            return search_data(root, data);
        } 

        void insert_data(Node*& root, int data){
            
           if(root == NULL){
            root = new Node(data);
           }
           else if(data > root->data){
                insert_data(root->right, data);
           }
           else
               insert_data(root->left, data);
        }

        void insert(int data){
            if(search(data)) return;
            insert_data(root, data);
        }

        Node* getMin(Node* root){
               if(root->left == NULL)
                   return root;
               return getMin(root->left);
               }
        Node* Delete(Node* root, int d){
            if(root == NULL)
                return root;
           
            if(root->data == d){
                if(root->left == NULL && root->right == NULL){
                    delete[] root;
                    return NULL;
                    }
                else if(root->left != NULL && root->right == NULL){
                     Node* tmp = root->left;
                     delete[] root;
                     return tmp;
                     }
                 else if(root->right != NULL && root->left == NULL){
                     Node* tmp = root->right;
                     delete[] root;
                     return tmp;
                     }
                 else if(root->right != NULL && root->left != NULL){
                     Node* mini = getMin(root->right);
                     Node* L = root->left;
                     Node* R = root->right;
                     root = mini;
                     Delete(root->right, mini->data);
                     root->left = L;
                     root->right = R;
                 }
         }
            else if(root->data > d){
                return Delete(root->left, d);
                }
            else
                return Delete(root->right, d);
                }
    
        void delete_data(int data){
            Node* tmp = Delete(root, data);
            }

        
     };

    
            
int main(){
    
    Tree* t = new Tree;
    t->insert(5);
    t->insert(12);
    cout<< t->search(15)<<endl;
    t->insert(15);
    cout<< t->search(15)<<endl;
    
    }
    