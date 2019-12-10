/* Binary Search Tree for integer values */

#include <iostream>
#include <queue>
using namespace std;

class BinaryTree {
    private:
        struct Node {
            int data;
            int level;
            Node* left;
            Node* right;
        };

    private:
        Node* root;

    private:
        Node* createNode(int data, int level) {
            Node* temp = new Node;
            temp->left = NULL;
            temp->right = NULL;
            temp->data = data;
            temp->level = level;
            return temp;
        }

    private:
        void add(int data, Node* tempRoot) {
            if(root == NULL) {
                root = createNode(data, 0);
            } else if(data < tempRoot->data) {
                if(tempRoot->left == NULL) {
                    tempRoot->left = createNode(data, tempRoot->level + 1);
                } else {
                    add(data, tempRoot->left);
                }
            } else if(data > tempRoot->data){
                if(tempRoot->right == NULL) {
                    tempRoot->right = createNode(data, tempRoot->level + 1);
                } else {
                    add(data, tempRoot->right);
                }
            } else {
            }
        }

    private:
        void display(Node* tempRoot, int order) {
            /*root left right , preorder*/
            if(order == 0) {
                if(tempRoot == NULL) {
                    cout << "Cannot display \n";
                } else {
                    cout << tempRoot->data << "  ";

                    if(tempRoot->left!=NULL)
                        display(tempRoot->left, order);

                    if(tempRoot->right!=NULL)
                        display(tempRoot->right, order);
                }
            }
            /*left root right, inorder */
            else if(order == 1) {
                if(tempRoot == NULL) {
                    cout << "Cannot display \n";

                } else {
                    if(tempRoot->left!=NULL)
                        display(tempRoot->left, order);

                    cout << tempRoot->data << "  ";

                    if(tempRoot->right!=NULL)
                        display(tempRoot->right, order);
                }
            }
            /*right left root , postorder*/
             else if(order == 2) {
                if(tempRoot == NULL) {
                    cout << "Cannot display \n";

                } else {
                    if(tempRoot->left!=NULL)
                        display(tempRoot->left, order);

                    if(tempRoot->right!=NULL)
                        display(tempRoot->right, order);

                    cout << tempRoot->data << "  ";
                }
            }
        }

    private:
        bool hasChildren(Node* temp) {
            if(temp->left!=NULL && temp->right!=NULL)
                return true;
            return false;
        }

    /*this is constructor, all private member functions are above and public are below*/

    public:
        BinaryTree() {
            root = NULL;
        }

    public:
        void add(int data) {
            add(data, root);
        }

    public:
        void display(int order){
            display(root, order);
        }

    public:
        void levelOrderDisplay() {
            Node* head = root;
            queue<Node*> q;
            q.push(head);
            int tlevel = 0; // for styling only
            cout << "Level :: 0 --> ";
            while(!q.empty()) {
                // first if is for styling only, can be omitted along with var tlevel
                if(tlevel!=q.front()->level) {
                    cout << "\n";
                    cout << "Level :: " << q.front()->level << " --> ";
                }
                cout  << q.front()->data << "   ";
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
                tlevel = q.front()->level;
                q.pop();
            }
        }

    public:
        Node* getMin(Node* temp) {
            if(temp == NULL)
                return NULL;
            while(temp->left!=NULL)
                temp = temp->left;
            return temp;
        }

    public:
        Node* getMax(Node* temp) {
            if(root == NULL)
                return NULL;
            while(temp->right!=NULL)
                temp = temp->right;
            return temp;


    public:
        int contains(int data, Node* temp) {
            if(temp == NULL) {
                return -1;
            } else {
                if(temp->data == data) {
                    return temp->data;
                }

                if(temp->left!=NULL && data < temp->data) {
                    int d2 = contains(data, temp->left);
                    if(d2 == data)
                        return d2;
                }

                if(temp->right!=NULL && data > temp->data) {
                   int d2 = contains(data, temp->right);
                   if(d2 == data)
                        return d2;
                }
            }
            return -1;
        }


    public:
        Node* removeData(int data, Node* temp) {
            if(temp == NULL) {
                cout << "No nodes in the tree ";
                return NULL;
            }

            if(data < temp->data) {
                temp->left = removeData(data, temp->left);
            } else if(data > temp->data) {
                temp->right = removeData(data, temp->right);
            } else {
                if(temp->left == NULL) {
                    Node* t2 = temp->right;
                    delete temp;
                    return t2;
                } else if(temp->right == NULL){
                    Node* t2 = temp->left;
                    delete temp;
                    return t2;
                } else {
                    Node* t2 = getMin(temp->right);
                    temp->data = t2->data;
                    temp->right = removeData(t2->data, temp->right);
                }
            }
            return temp;
        }




    public:
        Node* getRoot() {
            return root;
        }

};
