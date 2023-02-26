#ifndef MEE
#define MEE
#include <iostream>
#include <functional>
#include "iterator.hpp"
#include <algorithm>
#include "pair.hpp"

#define RED true
#define BLACK false

enum {LEFT = 1, RIGHT, BOTH};

namespace ft{

template<typename T, class _get_key, class _Allocator , class compare >
struct RBTree;

template<typename node_ptr>
node_ptr minimum(node_ptr node)
{
while (node->left != node->nil) {
    node = node->left;
}
return node;
}

template<typename node_ptr>
node_ptr maximum(node_ptr node) {
while (node->right != node->nil) {
    node = node->right;
}
return node;
}

template<typename node_ptr>
node_ptr successor(node_ptr x)
{
    if (x->left == NULL && x->right == NULL)
        return minimum(x->parent);
    if (x->right != x->nil)
    {
        return minimum(x->right);
    }

    node_ptr y = x->parent;
    while (y != x->nil && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template<typename node_ptr>
node_ptr predecessor(node_ptr x)
{
    if (x->left == NULL && x->right == NULL)
        return maximum(x->parent);
    if (x->left != x->nil) {
        return maximum(x->left);
    }
    node_ptr y = x->parent;
    while (y != x->nil && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

template<typename node_ptr>
node_ptr get_next_node(node_ptr node)
{
    return successor(node);
}

template <typename T, class _get_key, class alloc, class Node_ptr>
struct RB_Tree_iterator
{
    typedef alloc allocator_type;

    typedef T value_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef typename allocator_type::value_type*        pointer;
    typedef typename allocator_type::value_type const*  const_pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    typedef Node_ptr __node_ptr;

    __node_ptr it;
    RB_Tree_iterator() {}
    RB_Tree_iterator(__node_ptr node): it(node) {}

    reference operator*() {return (it->data);}
    pointer operator->() {return (&(it->data));}

    RB_Tree_iterator &operator++() {it = successor(it); return *this;}
    RB_Tree_iterator operator++(int) {RB_Tree_iterator tmp(*this); ++(*this); return tmp;}

    RB_Tree_iterator &operator--() {it = predecessor(it); return *this;}
    RB_Tree_iterator operator--(int) {RB_Tree_iterator tmp(*this); --(*this); return tmp;}

    __node_ptr base() const {return it;}
    inline bool operator!=(const RB_Tree_iterator &lhs)
        { return (this->base() != lhs.base());}
    inline bool operator==(const RB_Tree_iterator &lhs)
        { return (this->base() == lhs.base()); }
};

template <typename T, class _get_key, class alloc, class Node_ptr>
struct RB_Tree_const_iterator
{
    typedef alloc allocator_type;
    typedef T value_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef const value_type&                                 reference;
    typedef typename allocator_type::value_type const*        pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    typedef Node_ptr __node_ptr;

    private:
    typedef RB_Tree_iterator<T, _get_key, alloc, Node_ptr> non_const_iterator;
    public:
    __node_ptr it;
    RB_Tree_const_iterator() {}
    RB_Tree_const_iterator(non_const_iterator iter): it(iter.base()) {}

    reference operator*() const {return (it->data);}
    pointer operator->() const {return (&(it->data));}

    RB_Tree_const_iterator &operator++() {it = successor(it); return *this;}
    RB_Tree_const_iterator operator++(int) {RB_Tree_const_iterator tmp(*this); ++(*this); return tmp;}

    RB_Tree_const_iterator &operator--() {it = predecessor(it); return *this;}
    RB_Tree_const_iterator operator--(int) {RB_Tree_const_iterator tmp(*this); --(*this); return tmp;}

    __node_ptr base() const {return it;}
    inline bool operator!=(const RB_Tree_const_iterator &lhs)
        { return (this->base() != lhs.base());}
    inline bool operator==(const RB_Tree_const_iterator &lhs)
        { return (this->base() == lhs.base()); }
};

template <typename T, class _get_key, class alloc, class Node_ptr>
struct RB_Tree_reverse_iterator
{
    typedef alloc allocator_type;
    typedef T value_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef typename allocator_type::value_type*        pointer;
    typedef typename allocator_type::value_type const*  const_pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    typedef Node_ptr __node_ptr;

    __node_ptr it;
    RB_Tree_reverse_iterator() {}
    RB_Tree_reverse_iterator(__node_ptr node): it(node) {}

    reference operator*() {return (it->data);}
    pointer operator->() {return (&(it->data));}

    RB_Tree_reverse_iterator &operator++() {it = predecessor(it); return *this;}
    RB_Tree_reverse_iterator operator++(int) {RB_Tree_reverse_iterator tmp(*this); ++(*this); return tmp;}

    RB_Tree_reverse_iterator &operator--() {it = successor(it); return *this;}
    RB_Tree_reverse_iterator operator--(int) {RB_Tree_reverse_iterator tmp(*this); --(*this); return tmp;}

    __node_ptr base() const {return it;}
    inline bool operator!=(const RB_Tree_reverse_iterator &lhs)
        { return (this->base() != lhs.base());}
    inline bool operator==(const RB_Tree_reverse_iterator &lhs)
        { return (this->base() == lhs.base()); }
};

template <typename T, class _get_key, class alloc, class Node_ptr>
struct RB_Tree_const_reverse_iterator
{
    typedef alloc allocator_type;
    typedef T value_type;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef const value_type&                                 reference;
    // typedef const value_type&                           const_reference;
    typedef typename allocator_type::value_type const*        pointer;
    // typedef typename allocator_type::value_type const*  const_pointer;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;
    // typedef typename RBTree<value_type, _get_key, allocator_type, comp>::node_ptr __node_ptr;
    typedef Node_ptr __node_ptr;
    // typedef node_p __node_ptr;
    private:
    typedef RB_Tree_reverse_iterator<T, _get_key, alloc, Node_ptr> non_const_reverse_iteratotr;
    public:
    __node_ptr it;
    RB_Tree_const_reverse_iterator() {}
    RB_Tree_const_reverse_iterator(__node_ptr node): it(node) {}
    RB_Tree_const_reverse_iterator(non_const_reverse_iteratotr iter): it(iter.base()) {}

    reference operator*() const {return (it->data);}
    pointer operator->() const {return (&(it->data));}

    RB_Tree_const_reverse_iterator &operator++() {it = predecessor(it); return *this;}
    RB_Tree_const_reverse_iterator operator++(int) {RB_Tree_const_reverse_iterator tmp(*this); ++(*this); return tmp;}

    RB_Tree_const_reverse_iterator &operator--() {it = successor(it); return *this;}
    RB_Tree_const_reverse_iterator operator--(int) {RB_Tree_const_reverse_iterator tmp(*this); --(*this); return tmp;}

    __node_ptr base() const {return it;}
    inline bool operator!=(const RB_Tree_const_reverse_iterator &lhs)
        { return (this->base() != lhs.base());}
    inline bool operator==(const RB_Tree_const_reverse_iterator &lhs)
        { return (this->base() == lhs.base()); }
};
    
template <typename key>
struct get_key
{
    typedef key key_type;

    key_type operator()(const key_type &p) const
    {
        return p;
    }
};

template< typename T>
struct _Node
{
    T data;
    _Node *right;
    _Node *left;
    _Node *parent;
    bool color;
    _Node *nil;

    _Node(T data, _Node *nil): data(data), right(nil), left(nil), parent(nil), color(RED), nil(nil){}

    _Node(bool color): right(NULL), left(NULL), parent(NULL), color(color) {}
    _Node (const _Node & obj, T data):data(data),  right(obj.right), left(obj.left), parent(obj.parent), color(obj.color), nil(obj.nil){}
    void recolor() { color = !color;}
    void be_black() {color = BLACK;}
    void be_red() {color = RED;}
    bool is_red(){return (color == RED);}
    bool is_black(){return (color == BLACK);}
};

template<typename T, class _get_key = get_key<T> , class _Allocator = std::allocator<T> , class compare = std::less<T> >
struct RBTree
{
    typedef compare value_compare;
    _get_key key;
    value_compare comp;
    typedef typename _get_key::key_type key_type;
	typedef typename _Allocator::size_type size_type;

    typedef T value_type;
    typedef value_type& reference;
    typedef _Allocator allocator_type;
    typedef _Node<value_type> Node;
    typedef typename allocator_type::template rebind<Node>::other	allocator_node;
    typedef typename allocator_node::value_type* node_ptr;
	typedef typename allocator_node::difference_type    difference_type;

    typedef typename ft::RB_Tree_iterator<value_type, _get_key, allocator_type, node_ptr> iterator;
    typedef typename ft::RB_Tree_const_iterator<value_type, _get_key, allocator_type, node_ptr> const_iterator;
    typedef typename ft::RB_Tree_reverse_iterator<value_type, _get_key, allocator_type, node_ptr> reverse_iterator;
    typedef typename ft::RB_Tree_const_reverse_iterator<value_type, _get_key, allocator_type, node_ptr> const_reverse_iterator;

    private:
        difference_type _size;
        allocator_node alloc;
    public:
        Node	*nil;
        Node	*root;


    int has_red_child(node_ptr node)
    {
        if (node->right->is_red() && node->left->is_red())
            return (BOTH);
        if (node->right->is_red())
            return (RIGHT);
        if (node->left->is_red())
            return (LEFT);
        return (0);
    }

    iterator begin() {return (find_min(root));}
    iterator end() {return (nil);}

    const_iterator begin() const {return (const_iterator(find_min(root)));}
    const_iterator end() const {return const_iterator(nil);}

    reverse_iterator rbegin() const {return (find_max(this->root));}
    reverse_iterator rend() const{return this->nil;}

    RBTree(const compare &cmp)
    {
        nil = alloc.allocate(1);
        alloc.construct(nil, Node(BLACK));
        root = nil;
        _size = 0;
        comp = cmp;
    }

    explicit RBTree(const value_compare& __comp, const allocator_type& __a)
    {
        nil = alloc.allocate(1);
        alloc.construct(nil, Node(BLACK));
        root = nil;
        _size = 0;
        comp = __comp;
        alloc = __a;
    }

    RBTree(const RBTree& tree)
    {
        nil = alloc.allocate(1);
        alloc.construct(nil, Node(BLACK));
        root = nil;
        _size = 0;
        insert(tree.begin(), tree.end());
    }

    ~RBTree()
    {
        free_tree();
        alloc.destroy(nil);
        alloc.deallocate(nil, 1);
    }

    size_type size() const
    {
        return _size;
    }

    size_type max_size() const throw()
    {
        return std::min<unsigned long>(alloc.max_size(), std::numeric_limits<difference_type >::max());
    }

    void print_add()
    {
        std::cout << "begin: " << begin().base() << " root: " << this->root << " nil: " << this->nil << " end: " << end().base() << std::endl;
    }

    allocator_type get_allocator() const
    {
        return allocator_type();
    }

    iterator find(key_type value)
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (comp(key(tmp->data), value))
                tmp = tmp->right;
            else if (comp(value, key(tmp->data)))
                tmp = tmp->left;
            else
            {
                break;
            }
        }
        return iterator (tmp);
    }

    const_iterator find(key_type value) const
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (comp(key(tmp->data), value))
                tmp = tmp->right;
            else if (comp(value, key(tmp->data)))
                tmp = tmp->left;
            else
            {
                break;
            }
        }
        return const_iterator (tmp);
    }


    node_ptr find(node_ptr *parent, key_type value) const
    {
        Node *tmp;

        tmp = this->root;
        while (tmp != this->nil)
        {
            *parent = tmp;
            if (comp(value, key(tmp->data)))
                tmp = tmp->left;
            else if (comp(key(tmp->data), value))
                tmp = tmp->right;
            else
            {
                break;
            }
        }
        return (tmp);
    }

    node_ptr find(const_iterator pos, node_ptr *parent, key_type value) const
    {
        if (pos == end() || comp(value, key(*pos)))
        {
            const_iterator prior = pos;
            if ((pos == begin() || comp(key(*(--prior)), value)) && prior != end())
            {
                if (pos.base()->left == this->nil)
                {
                    *parent = pos.base();
                    return (this->nil);
                }
                else
                {
                    *parent = prior.base();
                    return (prior.base()->right);
                }
            }
            return (find(parent, value));
        }
        else if (comp(key(*pos), value))
        {
            const_iterator next = pos;
            if (next == end() || comp(value, key(*(++next))))
            {
                if (pos.base()->right == this->nil)
                {
                    *parent = pos.base();
                    return pos.base()->right;
                }
                else
                {
                    *parent = next.base();
                    return next.base()->left;
                }
            }
            return (find(parent, value));
        }
        *parent = pos.base();
        return pos.base();
    }

    iterator lower_bound( const key_type& k )
    {
        node_ptr tmp;
        node_ptr ret;

        tmp = root;
        ret = this->nil;
        while (tmp != this->nil)
        {
            if (!comp(key(tmp->data), k))
            {
                ret = tmp;
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;
        }
        return (iterator(ret));
    }

    iterator upper_bound( const key_type& k )
    {
        node_ptr tmp;
        node_ptr ret;

        tmp = root;
        ret = this->nil;
        while (tmp != this->nil)
        {
            if (comp(k, key(tmp->data)))
            {
                ret = tmp;
                tmp = tmp->left;
            }
            else
                tmp = tmp->right;
        }
        return (iterator(ret));
    }

    ft::pair<iterator,iterator> equal_range( const key_type& key )
    {
        return (ft::pair<iterator, iterator> (lower_bound(key), upper_bound(key)));
    }

    void free_tree()
    {
        iterator it;
        it = this->begin();
        for (;it != this->end(); )
        {
			it = erase(it);
        }
    }

    int child_derection(Node *root)
    {
        if (root->parent != root->nil && root == root->parent->right)
            return (RIGHT);
        else if (root->parent != root->nil && root == root->parent->left)
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
        if(tmp2 != nil)
            tmp2->parent = root;
        transplant(root, tmp);
        root->parent = tmp;
    }

    void rb_right_rotate(Node *root)
    {
        Node *tmp = root->left;
        Node *tmp2 = tmp->right;

        tmp->right = root;
        root->left = tmp2;
        if(tmp2 != nil)
            tmp2->parent = root;
        transplant(root, tmp);
        root->parent = tmp;
    }

    void fix_db(Node *parent, Node *db, Node *sibling)
    {
        if (db == this->root)
            return ;
        if (sibling == this->nil)
            fix_db(parent->parent, parent, get_sibling(parent));
        else if (sibling->is_black())
        {
            if (has_red_child(sibling))
            {
                if (child_derection(sibling) == RIGHT)
                {
                    if (has_red_child(sibling) == RIGHT || has_red_child(sibling) == BOTH)
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
                    if (has_red_child(sibling) == LEFT || has_red_child(sibling) == BOTH)
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
        if(root->left != nil)
            root->left->parent = replace;
        if(root->right != nil)
            root->right->parent = replace;

        if (root == this->root)
            this->root = replace;
        else if (child_derection(root) == LEFT)
            root->parent->left = replace;
        else if (child_derection(root) == RIGHT)
            root->parent->right = replace;
        replace->parent = root->parent;
    }

    void delete_node(Node *tree_node)
    {
        Node *tmp, *tmp2;
        Node *sibling;
        Node *parent;
        Node *db;

        tmp = tree_node;
        if (tmp != tmp->nil)
            _size--;
        if (tmp->left == this->nil && tmp->right == this->nil)
        {
            sibling = get_sibling(tmp);
            parent = tmp->parent;
            db = this->nil;
            transplant(tmp, this->nil);
            if (tmp->is_black())
                fix_db(parent, db, sibling);
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
        }
        else
        {
            tmp2 = find_min(tmp->right);
            sibling = get_sibling(tmp2);
            node_ptr replace = alloc.allocate(1);
            alloc.construct(replace, Node(*tmp2, tmp2->data));
            assign_with_p(tmp2, replace);
            assign_with_p(tmp, tmp2);
            tmp2->left = tmp->left;
            tmp2->right = tmp->right;
            tmp2->color = tmp->color;
            parent = replace->parent;
            db = replace->right;
            
            transplant(replace, replace->right);
            if (replace->is_black() && db->is_black())
                fix_db(parent, db, sibling);
            else replace->right->be_black();

            alloc.destroy(replace);
            alloc.deallocate(replace, 1);
        }
        alloc.destroy(tmp);
        alloc.deallocate(tmp, 1);
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

    Node *insert_util(Node *root, T data, int *rotation, ft::pair<iterator, bool> &ret)
    {
        int rotate = 0;

        if (root == this->nil)
        {
            node_ptr tmp = alloc.allocate(1);
            alloc.construct(tmp, Node(data, this->nil));
            ret.first = iterator(tmp);
            ret.second = true;
            _size++;
            return (tmp);
        }
        if (comp(key(root->data), key(data)))
        {
            root->right = insert_util(root->right, data, &rotate, ret);
            root->right->parent = root;
            if (root->color == RED && root->right->color == RED)
                *rotation = fix_tree_r(root);
            if (rotate)
                return (do_right_rotate(root, rotate));
        }
        if (comp(key(data), key(root->data)))
        {
            root->left = insert_util(root->left, data, &rotate, ret);
            root->left->parent = root;
            if (root->color == RED && root->left->color == RED)
                *rotation = fix_tree_l(root);
            if (rotate)
                return (do_left_rotate(root, rotate));
        }
        return root;
    }

	void fix_tree_rb_while(node_ptr node)
	{
		node_ptr uncle;
		node_ptr tmp;

		if (node == this->root)
			node->be_black();
		else if (node->parent->is_red())
		{
			uncle = get_sibling(node->parent);
			if (uncle->is_red())
			{
				node->parent->be_black();
				uncle->be_black();
				node->parent->parent->be_red();
				fix_tree_rb_while(node->parent->parent);
			}
			else
			{
				if (child_derection(node->parent) == LEFT)
				{
					tmp = node->parent->parent;
					if(child_derection(node) == RIGHT)
						rb_left_rotate(node->parent);
                    if (tmp == nil)
                    {
                        std::cout << "tmp is nil\n";
                        exit(1);
                    }
                    if (tmp != nil)
                        tmp->recolor();
                    if (tmp->left != nil)
                        tmp->left->recolor();
					rb_right_rotate(tmp);
				}
				else
				{
					tmp = node->parent->parent;
					if(child_derection(node) == LEFT)
						rb_right_rotate(node->parent);
                    if (tmp != nil)
                        tmp->recolor();
                    if (tmp->right != nil)
                        tmp->right->recolor();
					rb_left_rotate(tmp);
				}
			}
		}
	}

	ft::pair<iterator, bool> insert_while(iterator pos, value_type data)
	{
		// node_ptr tmp;
		node_ptr parent;
		bool found = true;
		node_ptr node;

		parent = this->nil;
        if (pos != nil)
            node = find(pos, &parent, key(data));
        else
            node = find(&parent, key(data));
        
        if (node == this->nil || root == this->nil)
            found = false;
		if (!found)
		{
            node = alloc.allocate(1);
            alloc.construct(node, Node(data, this->nil));
            _size++;
			if (parent == this->nil)
			{
				this->root = node;
				root->be_black();
                nil->parent = root;
				return ft::pair<iterator, bool>(node, !found);
			}
			node->parent = parent;
			if (comp(key(data), key(parent->data)))
            {
				parent->left = node;
            }
			else if (comp(key(parent->data), key(data)))
            {
				parent->right = node;
            }

			fix_tree_rb_while(node);
		}
        nil->parent = root;
		return ft::pair<iterator, bool>(node, !found);
	}

	iterator insert(iterator pos, T data)
	{
		return (insert_while(pos, data).first);
	}

    ft::pair<iterator, bool> insert(T data)
    {
        return insert_while(this->nil, data);
    }

    void swap(RBTree &tree)
    {
		std::swap(root, tree.root);
        std::swap(nil, tree.nil);
        std::swap(alloc, tree.alloc);
        std::swap(comp, tree.comp);
        std::swap(_size, tree._size);
    }

    Node* find_max(Node* root) const
    {
        if (root->right == this->nil)
            return root;
        return (find_max(root->right));
    }
    Node *find_min(Node *root) const
    {
		if (root == this->nil)
			return (root);
        if (root->left == this->nil)
            return root;
        return (find_min(root->left));
    }

	iterator erase( iterator pos )
	{
	    Node *tmp;

        tmp = pos.base();
		++pos;
        delete_node(tmp);
        nil->parent = root;
		return pos;
	}

	iterator erase( iterator first, iterator last )
	{
		for(; first != last;)
        {
			first = erase(first);
        }
		return first;
	}

    size_type erase(key_type key_data)
    {
        Node *tmp;
		size_type found = 0;

        tmp = this->root;
        while (tmp != this->nil)
        {
            if (comp(key(tmp->data), key_data))
                tmp = tmp->right;
            else if (comp(key_data, key(tmp->data)))
                tmp = tmp->left;
            else
            {
				found = 1;
                delete_node(tmp);
                break;
            }
        }
        nil->parent = root;
		return found;
    }

	template <class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        for (;first != last; first++)
        {
            this->insert(*first);
        }
        nil->parent = root;
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
            std::cout << key(root->data);
                
            if (root->color == RED)
                std::cout << 'r';
            else
                std::cout << 'b';
            // else
            std::cout << std::endl; 
            printTreeHelper(root->left, space); 
        }
    }
    void printTree()
    {
        printTreeHelper(this->root, 0);
    }

};

}

#endif