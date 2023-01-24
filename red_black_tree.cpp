#include <iostream>
#define RED true
#define BLACK false

struct RBTree;



struct RBTree
{
    struct Node
    {
        int data;
        Node *right;
        Node *left;
        Node *parent;
        bool color;

        Node(int data, RBTree tree): data(data), right(tree.nil), left(tree.nil), parent(tree.nil), color(RED){}
        // Node(int data, RBTree *tree): data(data), color(RED)
        // {
        //     right = tree->nil;
        //     left = tree->nil;
        //     parent = tree->nil;
        // }

        Node(bool color): color(color), right(NULL), left(NULL), parent(NULL) {}
        void recolor() { color = !color;}

        Node *get_sibling(RBTree tree, Node *node)
        {
            if (node == NULL)
                return tree.nil;
            if (node->parent != tree.nil)
                return tree.nil;
            if (node->parent->left == node)
                return node->parent->right;
            else
                return node->parent->left;
        }
    };
    Node *nil;
    Node *root;

    RBTree() {nil = new Node(BLACK); root = nil;}

    void recolor(Node *root)
    {
        root->recolor();
        root->parent->recolor();
        root->get_sibling(*this, root)->recolor();
        this->root->color = BLACK;
    }

    Node *left_rotate(Node *root)
    {
        Node *tmp = root->right;
        Node *tmp2 = tmp->left;

        tmp->left = root;
        root->right = tmp2;
        if (tmp2 != this->nil)
            tmp2->parent = root;
        root->parent = tmp;
        return (tmp);
    }

    Node *right_rotate(Node *root)
    {
        Node *tmp = root->left;
        Node *tmp2 = tmp->right;

        tmp->right = root;
        root->left = tmp2;
        root->parent = tmp;
        if (tmp2 != this->nil)
            tmp2->parent = root;
        return (tmp);
    }

    Node *rotate_r(Node *node)
    {
        // if (node->parent != this->nil)
        Node *tmp;
        if (node->left != this->nil && node->left->color == RED)
        {
            node->parent->right = right_rotate(node);
            tmp = left_rotate(node->parent);
            tmp->recolor();
            tmp->left->recolor();
        }
        else if (node->right != this->nil && node->right->color == RED)
        {
            tmp = left_rotate(node->parent);
            tmp->recolor();
            tmp->left->recolor();
        }
        return (tmp);
    }

    Node *rotate_l(Node *node)
    {
        // if (node->parent != this->nil)
        Node *tmp;
        if (node->right != this->nil && node->right->color == RED)
        {
            node->parent->right = left_rotate(node);
            tmp = right_rotate(node->parent);
            tmp->recolor();
            tmp->right->recolor();
        }
        else if (node->left != this->nil && node->left->color == RED)
        {
            tmp = left_rotate(node->parent);
            tmp->recolor();
            tmp->right->recolor();
        }
        return (tmp);
    }

    Node *fix_tree_r(Node *node)
    {
        std::cout << "+++==+++\n";
        if (node->get_sibling(*this, node)->color == RED)
            recolor(node);
        else
            return (rotate_r(node));
        return (node);
    }

    Node *fix_tree_l(Node *node)
    {
        std::cout << "+++=-=+++\n";
        if (node->get_sibling(*this, node)->color == RED)
            recolor(node);
        else
            return (rotate_l(node));
        return (node);
    }

    Node *insert_util(Node *root, int data)
    {
        if (root == NULL)
        {
            return (new Node(data, *this));
        }
        if (data > root->data)
        {
            // std::cout << "+++++\n";
            root->right = insert_util(root->right, data);
            root->right->parent = root;
            if (root->color == RED && root->right->color == RED)
                return (fix_tree_r(root));
        }
        if (data < root->data)
        {
            std::cout << "+++-+++\n";
            root->left = insert_util(root->left, data);
            root->left->parent = root;
            if (root->color == RED && root->left->color == RED)
                return (fix_tree_l(root));
        }
        return root;
        // if (root == this->root)
        // {
        //     if (root->color == RED)
        //         root->recolor();
        // }
    }
    void insert(int data)
    {
        if (this->root == this->nil)
        {
            // std::cout << "+++=-=+++\n";
            this->root = insert_util(NULL, data);
            this->root->recolor();
        }
        else
        {
            // std::cout << "+++=j=+++\n";
            this->root = insert_util(this->root, data);
        }
    }

    void inorderTraversalHelper(Node *node)
    {
        if(node!=this->nil)
        {
            inorderTraversalHelper(node->left);
            std::cout << node->data;
            inorderTraversalHelper(node->right);
        }
    }
    //function to print inorder traversal
    void inorderTraversal()
    {
        inorderTraversalHelper(this->root);
    }


};

    int main() 
    {
        RBTree t;
        int arr[] = {1,4,6,3,5,7,8,2,9};
        for(int i=0;i<9;i++)
        {
            t.insert(arr[i]);
            std::cout << std::endl;
            t.inorderTraversal();
            // std::cout << "++000++\n";
        }
        // you can check colour of any node by with its attribute node.colour
        // t.printTree();
    }

// int main()
// {
//     RBTree tree;


// }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// fix the rotation to only rotate when on the parent and not inside the child it causes problems with the parent children ///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

