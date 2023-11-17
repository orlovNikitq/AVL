#include<iostream>
#include <iomanip>
using namespace std;

struct node {
	int data;
    node* left;
    node* right;
    int balance;
};
int height(node* root) {
    if (root == nullptr) return 0;
    int hLeft = height(root->left), hRight = height(root->right);
    if (hLeft > hRight)
        return hLeft + 1;
    else
        return hRight + 1;
}
void setBalance(node*& root) {
    if (root != nullptr) root->balance = height(root->right) - height(root->left);
}
void singleRightRotate(node*& root) {
    node* leftSubtree, *leftSubreeRightSubtree;
    leftSubtree = root->left;
    leftSubreeRightSubtree = leftSubtree->right;
    leftSubtree->right = root;
    root->left = leftSubreeRightSubtree;
    root = leftSubtree;
    setBalance(root->right);
    setBalance(root);
}
void singleLeftRotate(node*& root) {
    node* rightSubtree, *rightSubreeLeftSubtree;
    rightSubtree = root->right;
    rightSubreeLeftSubtree = rightSubtree->left;
    rightSubtree->left = root;
    root->right = rightSubreeLeftSubtree;
    root = rightSubtree;
    setBalance(root->left);
    setBalance(root);
}
void insert(node*& root, int info) {
    if (root == nullptr) {
        root = new node;
        root->data = info;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        if (info > root->data) {
            insert(root->right, info);
            if (height(root->right) - height(root->left) > 1) {
                if (height(root->right->right) < height(root->right->left)) {
                    singleRightRotate(root->right);
                }
                singleLeftRotate(root);
            }
           
            
        }
        else {
            if (info < root->data) {
                insert(root->left, info);
                if (height(root->left) - height(root->right) > 1) {
                    if (height(root->left->left) < height(root->left->right)) {
                        singleLeftRotate(root->left);
                    }
                    singleRightRotate(root);
                }
            }
            setBalance(root);
        }
    }
}
void print(node* root) {
    if (root != nullptr) {
        print(root->left);
        cout << "Data: " << root->data << ", Balance: " << root->balance << " " << endl;
        print(root->right);
    }
}

int main() {
    node* root = nullptr;
    insert(root, 10);
    print(root);
    //cout << "Height: " << height(root) << endl;

    insert(root, 5);
    print(root);
   // cout << "Height: " << height(root) << endl;

    insert(root, 15);
    print(root);
    cout << "Height: " << height(root) << endl;

    std::cout<<height(root)<<endl;
    print(root);
}