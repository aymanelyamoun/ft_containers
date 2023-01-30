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

    Node *delete_red(Node *root, Node *child)
    {
        if (child == this->nil)
        {
            delete root;
            root = this->nil;
        }
        else
        {
            child->parent = root->parent;
            delete root;
            root = child;
            child->be_black();
        }
        return (root);
    }

    Node *delete_black(Node *root, Node *child)
    {
        if (child == this->nil)
        {
            delete root;
            root = this->nil;
        }
        else
        {
            child->parent = root->parent;
            delete root;
            root = child;
        }
        return (root);
    }

    Node *fix_db(Node *root, Node *sibling, bool *is_db, int *child_is_db)
    {
        if (root == this->root)
            return (root);
        else if (sibling->is_black() && sibling->has_red_child())
        {
            Node *tmp;
            Node *tmp2;
            //handle the first part of lr and rl cases here before returning to the parent
            if (child_derection(sibling) == LEFT && sibling->has_red_child() == RIGHT)
            {
                // std::cout << "+++++";
                tmp = sibling->parent;
                tmp2 = left_rotate(sibling);
                tmp2->parent = tmp;
                tmp->left = tmp2;
                tmp2->recolor();
                tmp2->left->recolor();
                // sibling->parent->left = left_rotate(sibling);
                // sibling->parent->left->recolor();
                // sibling->parent->left->left->recolor();
            }
            if (child_derection(sibling) == RIGHT && sibling->has_red_child() == LEFT)
            {
                tmp = sibling->parent;
                tmp2 = right_rotate(sibling);
                tmp2->parent = tmp;
                tmp->right = tmp2;
                tmp2->recolor();
                tmp2->right->recolor();
                // sibling->parent->right = right_rotate(sibling);
                // sibling->parent->right->parent = tmp;
                // std::cout << sibling->parent->right << std::endl;
                // sibling->parent->right->recolor();
                // sibling->parent->right->right->recolor();
            }
            *child_is_db = db_derction(sibling);
            *is_db = false;
            return (root);
        }
        else if (sibling->is_black())
        {
            sibling->recolor();
            if (sibling->parent->is_red())
                sibling->parent->be_black();
            else
            {
                *child_is_db = 0;
                *is_db = true;
            }
        }
        else
        {
            *child_is_db = db_derction(sibling) + 10;
            *is_db = false;
        }
        return (root);
    }

    Node *delete_node_util(Node *root, bool *is_db, int *child_is_db)
    {
        Node *sibling;

        if (root->right == this->nil && root->left == this->nil)
        {
            if (root->color == RED)
            {
                root = delete_red(root, this->nil);
                *is_db = false;
                *child_is_db = 0;
            }
            else
            {
                sibling = get_sibling(root);
                root = delete_black(root, root->right);
                return (fix_db(root, sibling, is_db, child_is_db));
            }
        }
        else if (root->right != this->nil && root->left == this->nil)
        {
            if (root->color == RED || root->right->color == RED)
            {
                root = delete_red(root, root->right);
                *is_db = false;
                *child_is_db = 0;
            }
            else
            {
                sibling = get_sibling(root);
                root = delete_black(root, root->right);
                return (fix_db(root, sibling, is_db, child_is_db));
                // fix_double_black(root, sibling);
                // *is_double_black = true;
            }
            // tmp = root->right;
            // delete root;
            // root = tmp;
        }
        else if (root->right == this->nil && root->left != this->nil)
        {
            if (root->color == RED || root->left->color == RED)
            {
                root = delete_red(root, root->left);
                *is_db = false;
                *child_is_db = 0;
            }
            else
            {
                sibling = get_sibling(root);
                root = delete_black(root, root->left);
                return (fix_db(root, sibling, is_db, child_is_db));
            }
        }
        else
        {
            root->data = find_min(root->right)->data;
            root->right = delete_node(root->right, root->data);
        }
        return (root);
    }

    Node *fix_db_child_b_s(Node *root, int direction)
    {
        Node *tmp = root;
        bool root_color = root->color;

        if (direction == LEFT)
        {
            tmp = left_rotate(root);
            tmp->color = root_color;
            tmp->right->be_black();
            tmp->left->be_black();
        }
        else if (direction == RIGHT)
        {
            tmp = right_rotate(root);
            tmp->color = root_color;
            tmp->right->be_black();
            tmp->left->be_black();
        }
        return (tmp);
    }

    Node *fix_db_child_r_s(Node *root, int direction, bool *is_db, int *child_is_db)
    {
        Node *tmp;

        if (direction == LEFT)
        {
            root->recolor();
            root->right->recolor();
            
            tmp = left_rotate(root);
            // check this it could be wrong / the asignment to sibling
            root->left = fix_db(root->left, root->right, is_db, child_is_db);
            if (*is_db)
                return (fix_db(tmp, get_sibling(tmp), is_db, child_is_db));
            else if (*child_is_db == LEFT || *child_is_db == RIGHT)
                return (fix_db_child_b_s(tmp, *child_is_db));
            else if (*child_is_db == (LEFT + 10) || *child_is_db == (RIGHT + 10))
            {
                child_is_db -= 10;
                return fix_db_child_r_s(tmp, *child_is_db, is_db, child_is_db);
            }
            return tmp;
        }
        else if (direction == RIGHT)
        {
            root->recolor();
            root->left->recolor();
            tmp = right_rotate(root);
            // check this it could be wrong / the asignment to sibling
            root->right = fix_db(root->right, root->left, is_db, child_is_db);
            if (*is_db)
                return (fix_db(tmp, get_sibling(tmp), is_db, child_is_db));
            else if (*child_is_db == LEFT || *child_is_db == RIGHT)
                return (fix_db_child_b_s(tmp, *child_is_db));
            else if (*child_is_db == (LEFT + 10) || *child_is_db == (RIGHT + 10))
            {
                child_is_db -= 10;
                return fix_db_child_r_s(tmp, *child_is_db, is_db, child_is_db);
            }
            return tmp;
        }
        return root;
    }

    Node *delete_node(Node *root, int data)
    {
        static bool is_double_black = false;
        static int child_is_double_black = false;

        if (root == this->nil)
            return nil;
        else if (root->data == data)
        {
            // Node *tmp;
            return delete_node_util(root, &is_double_black, &child_is_double_black);
        }
        else if (root->data < data)
        {
            root->right = delete_node(root->right, data);

        }
        else if (root->data > data)
        {
            root->left = delete_node(root->left, data);
        }
            if (is_double_black)
                return (fix_db(root, get_sibling(root), &is_double_black, &child_is_double_black));
            else if (child_is_double_black == LEFT || child_is_double_black == RIGHT)
                return (fix_db_child_b_s(root, child_is_double_black));
            else if (child_is_double_black == (LEFT + 10) || child_is_double_black == (RIGHT + 10))
            {
                child_is_double_black -= 10;
                return fix_db_child_r_s(root, child_is_double_black, &is_double_black, &child_is_double_black);
            }
        return root;
    }


    // Node *delete_node_util(Node *root, bool *is_double_black)
    // {
    //     // Node *tmp;
    //     Node *next;
    //     Node *sibling;

    //     if (root->right == this->nil && root->left == this->nil)
    //     {
    //         if (root->color == RED)
    //             root = delete_red(root, this->nil);
    //         else
    //         {
    //             sibling = root->get_sibling(*this, root);
    //             std::cout << "+++-+++" << std::endl;
    //             root = delete_black(root, root->right);
    //             fix_double_black(root, sibling);
    //             // *is_double_black = true;
    //         }
    //         // delete root;
    //         // root = this->nil;
    //     }
    //     else if (root->right != this->nil && root->left == this->nil)
    //     {
    //         // next = root->right;
    //         // sibling = root->get_sibling(*this, root);
    //         if (root->color == RED || root->right->color == RED)
    //             root = delete_red(root, root->right);
    //         else
    //         {
    //             sibling = root->get_sibling(*this, root);
    //             std::cout << "+++-+++" << std::endl;
    //             root = delete_black(root, root->right);
    //             fix_double_black(root, sibling);
    //             // *is_double_black = true;
    //         }
    //         // tmp = root->right;
    //         // delete root;
    //         // root = tmp;
    //     }
    //     else if (root->right == this->nil && root->left != this->nil)
    //     {
    //         if (root->color == RED || root->left->color == RED)
    //             root = delete_red(root, root->left);
    //         else
    //         {
    //             std::cout << "+++++++" << std::endl;
    //             root = delete_black(root, root->left);
    //             *is_double_black = true;
    //         }
    //         // tmp = root->left;
    //         // delete root;
    //         // root = tmp;
    //     }
    //     else
    //     {
    //         std::cout << "+++-+++" << std::endl;
    //         root->data = find_min(root->right)->data;
    //         root->right = delete_node(root->right, root->data);
    //     }
    //     return (root);
    // }

    // Node *fix_double_black(Node *d_black, Node *sibling)
    // {
    //     if (d_black == this->root)
    //         return d_black;
    //     if (/*sibling != this->nil &&*/ child_derection(sibling) == RIGHT)
    //     {
    //         return (fix_double_black_l(sibling->parent));
    //     }
    //     else if (/*sibling != this->nil &&*/ child_derection(sibling) == LEFT)
    //     {
    //         return (fix_double_black_r(sibling->parent));
    //     }
    //     return d_black;
    // }

    // Node *fix_double_black_l(Node *root)
    // {
    //     Node *tmp;

    //     if (root->right == BLACK)
    //     {
    //         if (root->right->has_red_child())
    //         {
    //             if (root->right->has_red_child() == LEFT)
    //             {
    //                 root->right = right_rotate(root->right);
    //                 tmp = left_rotate(root);
    //                 // if sus make it make_black for root, left and right;
    //                 tmp->recolor();
    //             }
    //             else
    //             {
    //                 tmp = left_rotate(root);
    //                 tmp->recolor();
    //             }
    //             return tmp;
    //         }
    //         else
    //         {
    //             root->right->recolor();
    //             if (root->is_red() == false)
    //                 return (fix_double_black(root, root->get_sibling(*this, root)));
    //             else
    //             {
    //                 root->be_black();
    //                 return (root);
    //             }

    //         }
    //     }
    //     else
    //     {
    //         //save the double black child
    //         tmp = root->left;
    //         if (root == this->root)
    //             this->root = left_rotate(root);
    //         else
    //         {
    //             if (child_derection(root->parent) == RIGHT)
    //             {
    //                 root->parent->right = left_rotate(root);
    //                 root->parent->right->recolor();
    //                 root->left->recolor();
                    
    //             }
    //             if (child_derection(root->parent) == LEFT)
    //             {
    //                 root->parent->left = left_rotate(root);
    //                 root->parent->left->recolor();
    //                 root->left->recolor();
    //             }
    //             if (child_derection(tmp) == RIGHT)
    //                 tmp->parent->right = fix_double_black(tmp, tmp->get_sibling(*this, tmp));
    //             if (child_derection(tmp) == LEFT)
    //                 tmp->parent->left = fix_double_black(tmp, tmp->get_sibling(*this, tmp));
    //         }
    //     }
    //     return root;
    // }

    // Node *delete_node(Node *root, int data)
    // {
    //     bool is_double_black = false;
    //     if (root == this->nil)
    //         return (this->nil);
    //     if (data == root->data)
    //     {
    //         std::cout << "+++==+++" << std::endl;
    //         return delete_node_util(root, &is_double_black);
    //     }
    //     else if (data < root->data)
    //     {
    //         root->left = delete_node(root->left, data);
    //         if (is_double_black)
    //         {
    //             root = fix_double_black(root->left, root->left->get_sibling(*this, root->left));
    //         }
    //     }
    //     else if (data > root->data)
    //     {
    //         root->right = delete_node(root->right, data);
    //         if (is_double_black)
    //         {
    //             root = fix_double_black(root->right, root->right->get_sibling(*this, root->right));
    //         }
    //     }
    //     return root;
    // }

    void delete_(int data)
    {
        this->root = delete_node(this->root, data);
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