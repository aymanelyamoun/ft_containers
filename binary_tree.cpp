#include <iostream>
#define COUNT 10

struct tree_node
{
    int data;
    tree_node *left;
    tree_node *right;
    int h;
    short bf;

    int height(tree_node *node)
    {
        if (node == NULL)
            return 0;
        return (node->h);
    }

    tree_node(int data) : data(data), left(NULL), right(NULL) , h(1){}
    tree_node *right_rotate()
    {
        tree_node *tmp = this->left;
        tree_node *tmp2 = tmp->right;

        tmp->right = this;
        this->left = tmp2;

        tmp->h = std::max(height(tmp->left), height(tmp->right)) + 1;
        this->h = std::max(height(this->left), height(this->right) + 1);
        return (tmp);
    }

    tree_node *left_rotate()
    {
        tree_node *tmp = this->right;
        tree_node *tmp2 = tmp->left;

        tmp->left = this;
        this->right = tmp2;
        
        tmp->h = std::max(height(tmp->left), height(tmp->right)) + 1;
        this->h = std::max(height(this->left), height(this->right) + 1);
        return (tmp);
    }

//     tree_node *rightRotate(tree_node *y)
// {
//     tree_node *x = y->left;
//     tree_node *T2 = x->right;
 
//     x->right = y;
//     y->left = T2;
 
//     y->h = std::max(height(y->left),
//                     height(y->right)) + 1;
//     x->h = std::max(height(x->left),
//                     height(x->right)) + 1;
 
//     return x;
// }
 
// tree_node *leftRotate(tree_node *x)
// {
//     tree_node *y = x->right;
//     tree_node *T2 = y->left;
 
//     y->left = x;
//     x->right = T2;
 
//     x->h = std::max(height(x->left),   
//                     height(x->right)) + 1;
//     y->h = std::max(height(y->left),
//                     height(y->right)) + 1;
 
//     return y;
// }


    int getBalance(tree_node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    tree_node *add_node(tree_node *root, int key)
    {
        if (root == NULL)
            return (new tree_node(key));

        if (key > root->data)
        {
            std::cout << "+++++\n";
            root->right = add_node(root->right, key);
        }
        else if(key < root->data)
        {
            std::cout << "+++-+++\n";
            root->left = add_node(root->left, key);

        }
        else
            return root;
        root->h = 1 + std::max (height(root->left), height(root->right));

        // bf = height(root->left) - height(root->right);
        bf = getBalance(root);
        // std::cout << "bf :: " << bf << std::endl;

        if (bf > 1 && key < root->left->data)
        {
            std::cout << root->data << std::endl;
            std::cout << "=====\n";
            return (root->right_rotate());
        }
        if (bf < -1 && key > root->right->data)
        {
            std::cout << "==+==\n";
            return (root->left_rotate());
        }
        if (bf > 1 && key > root->left->data)
        {
            // std::cout << root->data << std::endl;
            std::cout << "==-==\n";
            root->left = root->left->left_rotate();
            return (root->right_rotate());
        }
        if (bf < -1 && key < root->right->data)
        {
            std::cout << "==-+==\n";
            root->right = root->right->right_rotate();
            return (root->left_rotate());
        }
        return root;
    }


void printBT(const std::string& prefix, const tree_node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const tree_node* node)
{
    printBT("", node, false);    
}

    void print2DUtil(tree_node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(tree_node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
};

void preOrder(tree_node *root)
{
    if(root != NULL)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    tree_node *root = NULL;
    // tree_node *root = new tree_node(841);
    int data;

    while (1)
    {
        std::cin >> data;
        root = root->add_node(root, data);
        std::cout << std::endl;
        root->printBT(root);
        // preOrder(root);
        // root->print2D(root);
    }
    
    // root->printBT(root);
    // std::cout << "\n++++++++++++++++++\n";
    // root->print2D(root);
}