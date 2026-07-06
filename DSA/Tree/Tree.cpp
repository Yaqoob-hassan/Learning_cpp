#include<iostream>
using namespace std;

struct Tree
{
     int data;
     Tree* left;
     Tree* right;

     Tree(int val){
     data = val;
     left = nullptr;
     right = nullptr; }
};

Tree* insert(Tree* root, int data) {
    if(root == nullptr) {
        return new Tree(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;

    
}

Tree* search(Tree* root, int data) {
    if(root == nullptr ) {
        return nullptr;
    }

    if(data == root->data) {
        return root;
    }


    if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

Tree* Find_Min(Tree* root) {
    if(root == nullptr) {
        return nullptr;
    }
    while(root->left != nullptr) {
        root =  root->left;
    }

    return root;
}

Tree* Find_Max(Tree* root) {
    if(root == nullptr) {
        return nullptr;
    }
    while(root->right != nullptr) {
        root =  root->right;
    }

    return root;
}

void Pre_order(Tree* root) {
    if(root == nullptr) {
        return;
}
    cout << root->data << " ";
    // cout << " ";
    Pre_order(root->left);
    // cout << " ";
    Pre_order(root->right);
}

void Inorder(Tree* root) {
    if(root == nullptr) {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Post_Order(Tree* root) {
    if(root == nullptr) {
        return;
    }

    Post_Order(root->left);
    Post_Order(root->right);
    cout << root->data << " ";
}
int height(Tree* root ) {
    if(root ==  nullptr) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}







int main() {
    Tree* root = nullptr;

    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 21);

    
    cout << "Value inserted successfully." << endl;

    Tree* s1 = search(root, 21);
    if(s1 != nullptr) {
        cout << "Found value  :" << s1->data << endl;
    }

    Tree* s2= Find_Min(root);
    if(s2!= nullptr) {
        cout << "Minimum Value is : " << s2->data << endl;
    }

    cout << "Pre Ordering of Root." << endl;
    Pre_order(root);
    cout << endl;

    cout << "InOrdering of Root." << endl;
    Inorder(root);
    cout << endl;
    
    cout << "Post Order of Root." << endl;
    Post_Order(root);
    cout << endl;







    return 0;

}
