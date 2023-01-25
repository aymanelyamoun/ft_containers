#include <iostream>
#define RED true
#define BLACK false

enum {LEFT = 1, RIGHT};

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
            if (node->parent == tree.nil)
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

    int rotate_r(Node *node)
    {
        // if (node->parent != this->nil)
        if (node->left != this->nil && node->left->color == RED)
            return (LEFT);
        else if (node->right != this->nil && node->right->color == RED)
            return (RIGHT);
        return (0);
    }

    // int rotate_r(Node *node)
    // {
    //     // if (node->parent != this->nil)
    //     Node *tmp;
    //     if (node->left != this->nil && node->left->color == RED)
    //     {
    //         node->parent->right = right_rotate(node);
    //         tmp = left_rotate(node->parent);
    //         tmp->recolor();
    //         tmp->left->recolor();
    //     }
    //     else if (node->right != this->nil && node->right->color == RED)
    //     {
    //         tmp = left_rotate(node->parent);
    //         tmp->recolor();
    //         tmp->left->recolor();
    //     }
    //     return (tmp);
    // }

    int rotate_l(Node *node)
    {
        // if (node->parent != this->nil)
        Node *tmp;
        if (node->right != this->nil && node->right->color == RED)
        {
            return (RIGHT);
        }
        else if (node->left != this->nil && node->left->color == RED)
        {
            return (LEFT);
        }
        return (0);
    }

    int fix_tree_r(Node *node)
    {
        // std::cout << "+++=M=+++\n";
        if (node->get_sibling(*this, node)->color == RED)
        {
            recolor(node);
        }
        else
            return (rotate_r(node));
        return (0);
    }

    int fix_tree_l(Node *node)
    {
        // std::cout << "+++=-=+++\n";
        if (node->get_sibling(*this, node)->color == RED)
        {
            recolor(node);
        }
        else
            return (rotate_l(node));
        return (0);
        // return (node);
    }

    Node *do_right_rotate(Node *root, int rotation)
    {
        Node *tmp;

        if (rotation == LEFT)
        {
            root->right = right_rotate(root->right);
            tmp = left_rotate(root);
            tmp->recolor();
            tmp->left->recolor();
        }
        else if (rotation == RIGHT)
        {
            tmp = left_rotate(root);   
            tmp->recolor();
            tmp->left->recolor();
        }
        return (tmp);
    }

    Node *do_left_rotate(Node *root, int rotation)
    {
        Node *tmp;
        if (rotation == RIGHT)
        {
            root->left = left_rotate(root->left);
            tmp = right_rotate(root);
            root->recolor();
            root->right->recolor();
        }
        else if(rotation == LEFT)
        {
            tmp = right_rotate(root);
            root->recolor();
            root->right->recolor();
        }
        return (tmp);
    }

    Node *insert_util(Node *root, int data, int *rotation)
    {
        int rotate = 0;

        if (root == this->nil)
        {
            return (new Node(data, *this));
        }
        if (data > root->data)
        {
            // std::cout << "+++++\n";
            root->right = insert_util(root->right, data, &rotate);
            root->right->parent = root;
            if (root->color == RED && root->right->color == RED)
                *rotation = fix_tree_r(root);
            if (rotate)
                return (do_right_rotate(root, rotate));
        }
        if (data < root->data)
        {
            // std::cout << "+++-+++\n";
            root->left = insert_util(root->left, data, &rotate);
            root->left->parent = root;
            if (root->color == RED && root->left->color == RED)
                *rotation = fix_tree_l(root);
            if (rotate)
                return (do_left_rotate(root, rotate));
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
            this->root = insert_util(root, data, 0);
            this->root->recolor();
        }
        else
        {
            // std::cout << "+++=j=+++\n";
            this->root = insert_util(this->root, data, 0);
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

    void printTreeHelper(Node *root, int space)
    {
        int i;
        if(root != this->nil)
        {
            space = space + 10;
            printTreeHelper(root->right, space); 
            std::cout << std::endl; 
            for ( i = 10; i < space; i++) 
            {
                std::cout << " "; 
            } 
            std::cout << root->data; 
            std::cout << std::endl; 
            printTreeHelper(root->left, space); 
        }
    }
    void printTree()
    {
        printTreeHelper(this->root, 0);
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
            // std::cout << arr[i] <<"++000++\n";
        }
        // you can check colour of any node by with its attribute node.colour
        t.printTree();
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

/// add LEFT and RIGHT to check the rotation in the parent