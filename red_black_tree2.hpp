#ifndef MEE
#define MEE
#include <iostream>
#include <functional>
#include "iterator.hpp"

#define RED true
#define BLACK false

enum {LEFT = 1, RIGHT, BOTH};

template <typename T>
struct get_key
{
    typedef T key_type;
    T operator()(T &value) {return value;}
};

template<typename T, class _get_key = get_key<T> , class _Allocator = std::allocator<T> , class compare = std::less<T> >

struct RBTree
{
    typedef compare value_compare;
    _get_key key;
    value_compare comp;
    struct Node
    {
        T data;
        Node *right;
        Node *left;
        Node *parent;
        bool color;
		RBTree *nodes_tree;

        Node(T data, RBTree *tree): data(data), right(tree->nil), left(tree->nil), parent(tree->nil), color(RED){nodes_tree = tree;}

        Node(bool color): color(color), right(NULL), left(NULL), parent(NULL) {}
        Node (const Node & obj):color(obj.color), right(obj.right), left(obj.left), parent(obj.parent), data(obj.data) {nodes_tree = obj.nodes_tree;}
        void recolor() { color = !color;}
        void be_black() {color = BLACK;}
        void be_red() {color = RED;}
        bool is_red(){return (color == RED);}
        bool is_black(){return (color == BLACK);}

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
    // kdfj //
    Node* minimum(Node* node) const{
    while (node->left != nodes_tree->nil) {
      node = node->left;
    }
    return node;
  }

  Node* maximum(Node* node) const{
    while (node->right != nodes_tree->nil) {
      node = node->right;
    }
    return node;
  }

  Node* successor(Node* x) const {
    if (x->right != nodes_tree->nil) {
      return minimum(x->right);
    }

    Node* y = x->parent;
    while (y != nodes_tree->nil && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  Node* predecessor(Node* x) const{
    if (x->left != nodes_tree->nil) {
      return maximum(x->left);
    }

    Node* y = x->parent;
    while (y != nodes_tree->nil && x == y->left) {
      x = y;
      y = y->parent;
    }

    return y;
  }
    // kdfj //

        bool is_nil() { return (this == nodes_tree->nil); }

        // int child_derection(Node *root)
        // {
        //     if (root->parent != nil && root == root->parent->right)
        //         return (RIGHT);
        //     else if (root->parent != nil && root == root->parent->left)
        //         return (LEFT);
        //     return (0);
        // }
        Node *get_next_node()
        {
            return successor(this);
        }

    };
//aymane
    typedef Node* node_ptr;
    typedef T type_name;
    typedef type_name& reference;
    typedef _Allocator allocator_type;

    typedef typename ft::RB_Tree_iterator<type_name, _get_key, allocator_type, compare> iterator;
    typedef typename ft::RB_Tree_reverse_iterator<type_name, _get_key, allocator_type, compare> reverse_iterator;
    iterator __begin;
    Node	*nil;// = new Node(BLACK);
    Node	*root;
    iterator begin() const{return (find_min(this->root));}
    iterator end() const {return this->nil;}
    reverse_iterator rbegin() const {return (find_max(this->root));}
    reverse_iterator rend() const{return this->nil;}

    RBTree() {nil = new Node(BLACK) ; root = nil;}
    RBTree(const value_compare& __comp, const allocator_type& __a) {nil = new Node(BLACK) ; root = nil;}
    RBTree(const RBTree& tree)
    {
        nil = new Node(BLACK) ; root = nil;
        insert(tree.begin(), tree.end());
    }
    ~RBTree()
    {
        // std::cout << "tree c was called\n";
        free_tree();
        // std::cout << "tree c is done\n";
        
    }

    RBTree& operator=(const RBTree& tree)
    {
        // if (*this != tree)
            insert(tree.begin(), tree.end());
        return (*this);
    }

    allocator_type get_allocator() const
    {
        return allocator_type();
    }

    node_ptr find(typename _get_key::key_type value)
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (comp(key(tmp->data), value))// tmp->data < data)
                tmp = tmp->right;
            else if (comp(value, key(tmp->data)))
            // else if (comp(key(data), value))// tmp->data > data)
                tmp = tmp->left;
            else
            {
                break;
            }
        }
        return tmp;
    }

    void free_tree()
    {
        iterator it;
        it = begin();
        iterator tmp;
        for (;it != this->end(); it++)
        {
            // tmp = it;
            // std::cout << it->first << std::endl;
            delete_(it);
        } 
    }

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
        if (node->left != this->nil && node->left->color == RED)
            return (LEFT);
        else if (node->right != this->nil && node->right->color == RED)
            return (RIGHT);
        return (0);
    }

    void transplant(Node *node, Node *add)
    {
        // if (node == root)
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
        Node *tmp = root->left;
        Node *tmp2 = tmp->right;

        tmp->right = root;
        root->left = tmp2;
        if (root == this->root)
            this->root = tmp;
        tmp->parent = root->parent;
        link_to_tree(root, tmp);
        root->parent = tmp;
    }

    void fix_db(Node *parent, Node *db, Node *sibling)
    {
        Node *tmp;

        if (db == this->root)
            return ;
        if (sibling == this->nil)
            fix_db(parent->parent, parent, get_sibling(parent));
        else if (sibling->is_black())
        {
            if (sibling->has_red_child())
            {
                if (child_derection(sibling) == RIGHT)
                {
                    if (sibling->has_red_child() == RIGHT || sibling->has_red_child() == BOTH)
                    {
                        sibling->right->be_black();
                        sibling->color = parent->color;
                        rb_left_rotate(parent);
                    }
                    else
                    {
                        sibling->left->be_black();
                        sibling->color = parent->color;
                        rb_right_rotate(sibling);
                        rb_left_rotate(parent);
                    }
                }
                else if (child_derection(sibling) == LEFT)
                {
                    if (sibling->has_red_child() == LEFT || sibling->has_red_child() == BOTH)
                    {
                        sibling->left->be_black();
                        sibling->color = parent->color;
                        rb_right_rotate(parent);
                    }
                    else
                    {
                        sibling->right->be_black();
                        sibling->color = parent->color;
                        rb_left_rotate(sibling);
                        rb_right_rotate(parent);
                    }
                }
            }
            else
            {
                sibling->recolor();
                if (parent->is_black())
                    fix_db(parent->parent, parent, get_sibling(parent));
                else
                    parent->be_black();
            }
        }
        else
        {
            parent->recolor();
            sibling->recolor();
            if (child_derection(sibling) == RIGHT)
                rb_left_rotate(parent);
            else if (child_derection(sibling) == LEFT)
                rb_right_rotate(parent);
            fix_db(parent, db, new_sibling(parent, db));
        }
    }

    void assign_with_p(Node *root, Node *replace)
    {
        if (root == this->root)
            this->root = replace;
        else if (child_derection(root) == LEFT)
            root->left = replace;
        else if (child_derection(root) == RIGHT)
            root->right = replace;
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
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = this->nil;
            transplant(tmp, this->nil);
            if (tmp->is_black())
                fix_db(parent, db, sibling);
            delete tmp;
            tmp = this->nil;
        }
        else if (tmp->left != this->nil && tmp->right == this->nil)
        {
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = tmp->left;
            transplant(tmp, tmp->left);
            if (tmp->left->is_black() && tmp->is_black())
                fix_db(parent, db, sibling);
            else tmp->left->be_black();
            delete tmp;
            tmp = this->nil;
        }
        else if (tmp->left == this->nil && tmp->right != this->nil)
        {
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = tmp->right;
            transplant(tmp, tmp->right);
            if (tmp->right->is_black() && tmp->is_black())
                fix_db(parent, db, sibling);
            else tmp->right->be_black();
            delete tmp;
            tmp = this->nil;
        }
        else
        {
            std::cout << "++++4\n";
            tmp2 = find_min(tmp->right);
            sibling = get_sibling(tmp2);
            parent = tmp2->parent;
            std::cout << tmp->parent << std::endl;
            std::cout << this->nil << std::endl;
            db = tmp2->right;
            Node *replace = new Node(*tmp);
            assign_with_p(tmp, replace);
            transplant(tmp2, tmp2->right);
            if (tmp2->is_black() && db->is_black())
                fix_db(parent, db, sibling);
            else tmp2->right->be_black();
            delete tmp2;
            tmp2 = this->nil;
        }
    }

    int get_rotate_direction_l(Node *node)
    {
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
        if (get_sibling(node)->color == RED)
        {
            recolor(node);
        }
        else
            return (get_rotate_direction_l(node));
        return (0);
    }

    Node *do_right_rotate(Node *root, int rotation)
    {
        Node *tmp;

        if (rotation == LEFT)
        {
            root->right = right_rotate(root->right);
            tmp = left_rotate(root);
            if (root == this->root)
                tmp->parent = this->nil;
            tmp->recolor();
            tmp->left->recolor();
        }
        else if (rotation == RIGHT)
        {
            tmp = left_rotate(root);   
            if (root == this->root)
                tmp->parent = this->nil;
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
            if (root == this->root)
                tmp->parent = this->nil;
            tmp->recolor();
            tmp->right->recolor();
        }
        else if(rotation == LEFT)
        {
            tmp = right_rotate(root);
            if (root == this->root)
                tmp->parent = this->nil;
            tmp->recolor();
            tmp->right->recolor();
        }
        return (tmp);
    }

    Node *insert_util(Node *root, T data, int *rotation)
    {
        int rotate = 0;

        if (root == this->nil)
        {
            return (new Node(data, this));
        }
        if (comp(key(root->data), key(data)))// data > root->data)//
        {
            root->right = insert_util(root->right, data, &rotate);
            root->right->parent = root;
            if (root->color == RED && root->right->color == RED)
                *rotation = fix_tree_r(root);
            if (rotate)
                return (do_right_rotate(root, rotate));
        }
        if (comp(key(data), key(root->data)))
        // if (data < root->data)
        {
            root->left = insert_util(root->left, data, &rotate);
            root->left->parent = root;
            if (root->color == RED && root->left->color == RED)
                *rotation = fix_tree_l(root);
            if (rotate)
                return (do_left_rotate(root, rotate));
        }
        return root;
    }
    void insert(T data)
    {
        if (this->root == this->nil)
        {
            this->root = insert_util(root, data, 0);
            this->root->recolor();
        }
        else
        {
            this->root = insert_util(this->root, data, 0);
        }
    }

    Node* find_max(Node* root) const
    {
        if (root->right == this->nil)
            return root;
        return (find_max(root->right));
    }
    Node *find_min(Node *root) const
    {
        if (root->left == this->nil)
            return root;
        return (find_min(root->left));
    }

    /* add the delete logic here */

    void delete_(T data)
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (comp(key(tmp->data), key(data)))// tmp->data < data)
                tmp = tmp->right;
            else if (comp(key(data), key(tmp->data)))// tmp->data > data)
                tmp = tmp->left;
            else
            {
                delete_node(tmp);
                break;
            }
        }
    }
	template <class InputIterator>
    void delete_(InputIterator it)
    {
        delete_(*it);
    }

	template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        for (;first != last; first++)
        {
            this->insert(*first);
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
// template <typename T, class _Allocator = std::allocator<T> >
// struct test
// {
// typedef T type_name;
//     typedef _Allocator allocator_type;

//     typedef typename ft::RB_Tree_iterator<type_name, allocator_type> iterator;
// };

// #include <string>
// // #include <set>
//     int main() 
//     {
//         RBTree<int> t;
//         RBTree<int>::iterator it;
//         // std::set<int> hop;
//         int input;
//         long long i = 0;
//         // int arr[] = {1,4,6,3,5,7,8,2,9};
//         while(1)
//         {
//             std::cin >> input;
//             // hop.insert(i);
//             if (input == 1)
//             {
//                 std::cin >> input;
//                 t.insert(input);
//             }
//             else if (input == 2)
//             {
//                 std::cin >> input;
//                 t.delete_(input);
//             }
//             else if (input == 3)
//                 break;
//             // if (t.root == t.nil)
//             //     break;
//             // std::cout << std::endl;
//             // t.inorderTraversal();
//             i++;
//             t.printTree();
//             // std::cout << arr[i] <<"++000++\n";
//         }
//         for (int i = 0; i < 3; i++)
//         {
//             std::cout << *it;
//         }
//         // you can check colour of any node by with its attribute node.colour
//     }

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
#endif