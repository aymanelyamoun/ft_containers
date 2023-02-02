#include <iostream>
#define RED true
#define BLACK false

enum {LEFT = 1, RIGHT, BOTH};

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

        Node(bool color): color(color), right(NULL), left(NULL), parent(NULL) {}
        void recolor() { color = !color;}
        void be_black() {color = BLACK;}
        void be_red() {color = RED;}
        bool is_red(){return (color == RED);}
        bool is_black(){return (color == BLACK);}

        // Node *get_sibling(RBTree tree, Node *node)
        // {
        //     if (node == NULL)
        //         return tree.nil;
        //     if (node->parent == tree.nil)
        //         return tree.nil;
        //     if (node->parent->left == node)
        //         return node->parent->right;
        //     else
        //         return node->parent->left;
        // }
        int has_red_child()
        {
            if (this->right->is_red() && this->left->is_red())
                return (BOTH);
            if (this->right->is_red())
                return (RIGHT);
            if (this->left->is_red())
                return (LEFT);
            return (0);
        }
    };
    Node *nil;
    Node *root;

    RBTree() {nil = new Node(BLACK); root = nil;}

    int child_derection(Node *root)
    {
        if (root->parent != nil && root == root->parent->right)
            return (RIGHT);
        else if (root->parent != nil && root == root->parent->left)
            return (LEFT);
        return (0);
    }

    Node *get_sibling(Node *node)
    {
        if (node == NULL)
            return this->nil;
        if (node->parent == this->nil)
            return this->nil;
        if (node->parent->left == node)
            return node->parent->right;
        else
            return node->parent->left;
    }

    Node *new_sibling(Node *parent, Node *node)
    {
        if (node == NULL)
            return this->nil;
        if (parent == this->nil)
            return this->nil;
        if (parent->left == node)
            return parent->right;
        else
            return parent->left;
    }

    int db_derction(Node *sibling)
    {
        if (child_derection(sibling) == LEFT)
            return (RIGHT);
        if (child_derection(sibling) == RIGHT)
            return (LEFT);
        return (0);
    }

    void recolor(Node *root)
    {
        root->recolor();
        root->parent->recolor();
        // root->get_sibling(*this, root)->recolor();
        get_sibling(root)->recolor();
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

    int get_rotate_direction_r(Node *node)
    {
        // if (node->parent != this->nil)
        if (node->left != this->nil && node->left->color == RED)
            return (LEFT);
        else if (node->right != this->nil && node->right->color == RED)
            return (RIGHT);
        return (0);
    }

    void transplant(Node *node, Node *add)
    {
        if (node->parent == this->nil)
            this->root = add;
        if (node->parent->left == node)
            node->parent->left = add;
        if (node->parent->right == node)
            node->parent->right = add; 
        add->parent = node->parent;
    }

    void link_to_tree(Node *root, Node *node)
    {
        if (root->parent != this->nil)
        {
            if (child_derection(root) == LEFT)
                root->parent->left = node;
            if (child_derection(root) == RIGHT)
                root->parent->right = node;
        }
    }

    void rb_left_rotate(Node *root)
    {
        Node *tmp = root->right;
        Node *tmp2 = tmp->left;

        tmp->left = root;
        root->right = tmp2;
        if (root == this->root)
            this->root = tmp;
        tmp->parent = root->parent;
        link_to_tree(root, tmp);
        root->parent = tmp;
    }

    void rb_right_rotate(Node *root)
    {
        Node *tmp = root->left;//
        Node *tmp2 = tmp->right;

        tmp->right = root;
        root->left = tmp2;//
        if (root == this->root)
            this->root = tmp;
        tmp->parent = root->parent;
        link_to_tree(root, tmp);
        root->parent = tmp;
    }

    void fix_db(Node *parent, Node *db, Node *sibling)
    {
        Node *tmp;

        std::cout << "i need to be fixed\n";
        if (db == this->root)
            return ;
        if (sibling == this->nil)
            fix_db(parent->parent, parent, get_sibling(parent));
        else if (sibling->is_black())
        {
            if (sibling->has_red_child())
            {
                std::cout << "i wanna be fixed 1\n";
                if (child_derection(sibling) == RIGHT)
                {
                    if (sibling->has_red_child() == RIGHT || sibling->has_red_child() == BOTH)
                    {
                        sibling->right->be_black();
                        sibling->color = parent->color;
                        rb_left_rotate(parent);
                    // std::cout << "----\n";
                    }
                    else
                    {
                        sibling->left->be_black();
                        sibling->color = parent->color;
                        rb_right_rotate(sibling);
                        rb_left_rotate(parent);
                        std::cout << "--+--\n";
                    }
                }
                else if (child_derection(sibling) == LEFT)
                {
                    if (sibling->has_red_child() == LEFT || sibling->has_red_child() == BOTH)
                    {
                        std::cout << "+--+--\n";
                        sibling->left->be_black();
                        sibling->color = parent->color;
                        rb_right_rotate(parent);
                    }
                    else
                    {
                        std::cout << "+--+--+\n";
                        sibling->right->be_black();
                        sibling->color = parent->color;
                        rb_left_rotate(sibling);
                        rb_right_rotate(parent);
                    }
                }
            }
            else
            {
                std::cout << "i wanna be fixed 2\n";
                sibling->recolor();
                if (parent->is_black())
                    fix_db(parent->parent, parent, get_sibling(parent));
                else
                    parent->be_black();
            }
        }
        else
        {
            std::cout << "i wanna be fixed 3\n";
            parent->recolor();
            sibling->recolor();
            if (child_derection(sibling) == RIGHT)
                rb_left_rotate(parent);
            else if (child_derection(sibling) == LEFT)
                rb_right_rotate(parent);
            // find a way to send db parent -- problem whent db is NULL
            fix_db(parent, db, new_sibling(parent, db));
        }
    }

    void delete_node(Node *tree_node)
    {
        Node *tmp, *tmp2;
        Node *sibling;
        Node *parent;
        Node *db;

        tmp = tree_node;
        if (tmp->left == this->nil && tmp->right == this->nil)
        {
            std::cout << "1++++++\n";
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = this->nil;
            transplant(tmp, this->nil);
            if (tmp->is_black())
                fix_db(parent, db, sibling);
            delete tmp;
            tmp = this->nil;
                // std::cout << "double black should be fixed\n";
        }
        else if (tmp->left != this->nil && tmp->right == this->nil)
        {
            std::cout << "2++++++\n";
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = tmp->left;
            transplant(tmp, tmp->left);
            // tree_node->left = tmp->left;
            if (tmp->left->is_black() && tmp->is_black())
                fix_db(parent, db, sibling);
                // std::cout << "double black should be fixed\n";
            else tmp->left->be_black();
            delete tmp;
            tmp = this->nil;
        }
        else if (tmp->left == this->nil && tmp->right != this->nil)
        {
            std::cout << "3++++++\n";
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = tmp->right;
            transplant(tmp, tmp->right);
            // tree_node->right = tmp->right;
            if (tmp->right->is_black() && tmp->is_black())
                fix_db(parent, db, sibling);
                // std::cout << "double black should be fixed\n";
            else tmp->right->be_black();
            delete tmp;
            tmp = this->nil;
        }
        else
        {
            std::cout << "4+++++4\n";
            tmp2 = find_min(tmp->right);
            sibling = get_sibling(tmp2);
            parent = tmp2->parent;
            db = tmp2->right;
            tmp->data = tmp2->data;
            transplant(tmp2, tmp2->right);

            std::cout << "color tmp :" << tmp2->data << std::endl;
            if (tmp2->is_black() && db->is_black())
                fix_db(parent, db, sibling);
                // std::cout << "double black should be fixed\n";
            else tmp2->right->be_black();
        }
    }
// };

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

    int get_rotate_direction_l(Node *node)
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
        if (get_sibling(node)->color == RED)
        {
            recolor(node);
        }
        else
            return (get_rotate_direction_r(node));
        return (0);
    }

    int fix_tree_l(Node *node)
    {
        // std::cout << "+++=-=+++\n";
        if (get_sibling(node)->color == RED)
        {
            recolor(node);
        }
        else
            return (get_rotate_direction_l(node));
        return (0);
        // return (node);
    }

    Node *do_right_rotate(Node *root, int rotation)
    {
        Node *tmp;

            std::cout << "++++";
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
        std::cout << "++-++";
        if (rotation == RIGHT)
        {
            root->left = left_rotate(root->left);
            tmp = right_rotate(root);
            tmp->recolor();
            tmp->right->recolor();
        }
        else if(rotation == LEFT)
        {
            tmp = right_rotate(root);
            tmp->recolor();
            tmp->right->recolor();
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

    Node *find_min(Node *root)
    {
        if (root->left == this->nil)
            return root;
        return (find_min(root->left));
    }

    /* add the delete logic here */

    void delete_(int data)
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (tmp->data == data)
            {
                delete_node(tmp);
                break;
            }
            else if (tmp->data < data)
                tmp = tmp->right;
            else if (tmp->data > data)
                tmp = tmp->left;
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
            if (root->color == RED)
                std::cout << 'r';
            else
                std::cout << 'b';
            std::cout << std::endl; 
            printTreeHelper(root->left, space); 
        }
    }
    void printTree()
    {
        printTreeHelper(this->root, 0);
    }

};
// #include <set>
    int main() 
    {
        RBTree t;
        // std::set<int> hop;
        int input;
        long long i = 0;
        // int arr[] = {1,4,6,3,5,7,8,2,9};
        while(1)
        {
            std::cin >> input;
            // hop.insert(i);
            if (input == 1)
            {
                std::cin >> input;
                t.insert(input);
            }
            else if (2)
            {
                std::cin >> input;
                t.delete_(input);
            }
            // if (t.root == t.nil)
            //     break;
            // std::cout << std::endl;
            // t.inorderTraversal();
            i++;
            t.printTree();
            // std::cout << arr[i] <<"++000++\n";
        }
        // you can check colour of any node by with its attribute node.colour
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