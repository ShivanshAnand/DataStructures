#include <iostream>
using namespace std;

class BinSearchTree
{
	private:
		struct Node
		{
			unsigned int data;
			Node* left;
			Node* right;
		};

		Node* head = NULL;


		void insert(int val, Node* temp)
		{
			Node* curr = new Node;
			curr->data = val;
			curr->left = NULL; 
			curr->right = NULL;

			if (head == NULL)
			{
				head = curr;
			}
			else
			{
				if(val > temp->data)
				{ 
					if (temp->right != NULL)
						insert(val, temp->right);
					else
						temp->right = curr;
				}
				else if(val < temp->data)
				{
					if (temp->left != NULL)
						insert(val, temp->left);
					else
						temp->left = curr;
				}
				else
				{
					cout << "duplicates not allowed";
				}
			}
		}


		void displayInorder(Node* temp)
		{
			if (temp == NULL)
			{
				cout << "Can't display\n";
			}
			else
			{
				if (temp->left != NULL)
				{
					displayInorder(temp->left);
				}
				
				cout << temp->data << ",";

				if(temp->right != NULL)
				{
					displayInorder(temp->right);
				}
			}
		}

		void displayPreorder(Node* temp)
		{
			if (temp == NULL)
			{
				cout << "Can't display\n";
			}
			else
			{
				cout << temp->data << ",";

				if (temp->left != NULL)
				{
					displayPreorder(temp->left);
				}

				if (temp->right != NULL)
				{
					displayPreorder(temp->right);
				}
			}
		}

		void displayPostorder(Node* temp)
		{
			if (temp == NULL)
			{
				cout << "Can't display\n";
			}
			else
			{
				if (temp->left != NULL)
				{
					displayPostorder(temp->left);
				}

				if (temp->right != NULL)
				{
					displayPostorder(temp->right);
				}

				cout << temp->data << ",";
			}
		}

		bool contains(int data, Node* temp)
		{
			if (temp != NULL)
			{
			
				if (temp->data == data)
				{
					return true;
				}
				else if (data < temp->data)
				{
					return contains(data, temp->left);
				}
				else
				{
					return contains(data, temp->right);
				}
			}

			return false;
		}

		void printNodesWithNoSiblings(Node* temp)
		{
			if (temp != NULL)
			{

				if (temp->left != NULL && temp->right != NULL)
				{
					printNodesWithNoSiblings(temp->left);
					printNodesWithNoSiblings(temp->right);
				}
				else if (temp->left != NULL)
				{
					cout << temp->left->data << "\n";
					printNodesWithNoSiblings(temp->left);
				}
				else if(temp->right!=NULL)
				{
					cout << temp->right->data << "\n";
					printNodesWithNoSiblings(temp->right);
				}
			}
		}

		void printLeafNodes(Node* temp)
		{
			if (temp != NULL)
			{
				if (temp->left == NULL && temp->right == NULL)
				{
					cout << temp->data << "\n";
				}

				if (temp->left != NULL)
				{
					printLeafNodes(temp->left);
				}

				if (temp->right != NULL)
				{
					printLeafNodes(temp->right);
				}
			}
		}





	public:
		void insert(int data)
		{
			insert(data, head);
		}

		void display(int code)
		{
			if (code == 1)
			{
				displayInorder(head);
			}
			else if (code == 2)
			{
				displayPreorder(head);
			}
			else if (code == 3)
			{
				displayPostorder(head);
			}
			else
			{
				cout << "cannot display";
			}
		}

		bool contains(int data)
		{
			return contains(data, head);
		}

		int getMax()
		{
			if (head == NULL)
			{
				return -1;
			}

			Node* temp = head;

			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			return temp->data;
		}

		int getMin()
		{
			if (head == NULL)
			{
				return -1;
			}

			Node* temp = head;

			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			return temp->data;
		}

		void printNodesWithNoSiblings()
		{
			printNodesWithNoSiblings(head);
		}

		void printLeafNodes()
		{
			printLeafNodes(head);
		}
	

};

int main()
{
	BinSearchTree bin;
	bin.insert(10);
	bin.insert(5);
	bin.insert(15);
	bin.insert(4);
	bin.insert(6);

	bin.printLeafNodes();


	return 0;

}
