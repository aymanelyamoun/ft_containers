#ifndef MAP
#define MAP

#include <memory>
#include "red_black_tree2.hpp"

namespace ft
{

	template<typename key, typename T>
	struct get_key_pairs
	{
		typedef T value_type;
		typedef key key_type;

		key operator()(value_type &p1) const
		{
			return p1.first;
		}
	};

	template <class _Key, class _Tp, class _Compare = std::less<_Key>, class _Allocator = std::allocator<std::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key                                        key_type;
		typedef _Tp                                         mapped_type;
		typedef std::pair<const key_type, mapped_type>      value_type;
		typedef _Compare                                    key_compare;
		typedef _Allocator                                  allocator_type;
		typedef value_type&                                 reference;
		typedef const value_type&                           const_reference;
		typedef typename allocator_type::value_type*        pointer;
		typedef typename allocator_type::value_type const*  const_pointer;
		typedef typename allocator_type::size_type          size_type;
		typedef typename allocator_type::difference_type    difference_type;


		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		// public:
		// 	value_compare() {}
		protected:
			key_compare comp;
			value_compare(key_compare c): comp(c) {}
		public:
			bool operator()(const value_type &p1, const value_type &p2) const
			{
				return comp(p1.first, p2.first);
			}
		};

	private:
		typedef get_key_pairs<const key_type, value_type> _get_key_pairs;
		typedef RBTree<value_type, _get_key_pairs, allocator_type, key_compare> RB_tree;
		RB_tree tree;
		size_type _size;
		typedef typename RB_tree::node_ptr node_ptr;
	public:
		typedef typename RB_tree::iterator iterator;
		typedef typename RB_tree::reverse_iterator reverse_iterator;

		explicit map (const key_compare& _comp = key_compare(), const allocator_type& alloc = allocator_type())
		: tree(key_compare(_comp), allocator_type(alloc)) {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{ insert(first, last); }

		map (const map& x): tree(x.tree), _size(x._size){}

		map& operator= (const map& x)
		{
			_size = x._size;
        	insert(tree.begin(), tree.end());
			// tree = x.tree;
			return (*this);
		}

    	allocator_type get_allocator() const
		{
			return allocator_type();
		}

		mapped_type &at(key_type value)
		{
			node_ptr tmp;
			tmp = tree.find(value);
			if (tmp == tree.nil)
				throw std::out_of_range("map::at:  key not foundadd aditional value");
			return (tmp->data.second);
		}

		mapped_type& operator[] (const key_type& k)
		{
			return (tree.insert(value_type(k, mapped_type())).first->second);
		}

		void print()
		{
			tree.printTree();
		}

    	void print_add()
		{
			tree.print_add();
		}
		// ~map(){std::cout << "map c was called\n";//tree.~RBTree(); }

		/// iterators

		iterator begin() {return tree.begin();}
		iterator end() const {return tree.end();}
		reverse_iterator rbegin() {return tree.rbegin();}
		reverse_iterator rend() {return tree.rend();}

		/// iterators end

		// capcity 

		bool empty() const
		{
			return (tree.begin() == tree.end());
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return tree.max_size();
		}

		//end capacity

		// modifiers 

		void clear() {tree.free_tree();}

		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) { tree.insert(first, last); }

		std::pair<iterator, bool> insert(value_type value)
		{
			return tree.insert(value);
		}

		iterator insert(iterator pos, value_type data)
		{
			return (tree.insert(pos, data));
		}

		iterator erase( iterator pos )
		{
			return tree.erase(pos);
		}

		void swap( map& other )
		{
			tree.swap(other.tree);
		}

		size_type count( const key_type& key ) const
		{
			return (find(key) != end());
		}


		// void delete_(value_type value)
		// {
		// 	tree.delete_(value);
		// }

		// modifiers end

		// lookup
		iterator find( const key_type& key ) const
		{
			return (tree.find(key));
		}

		iterator lower_bound( const key_type& key )
		{
			return tree.lower_bound(key);
		}
		iterator upper_bound( const key_type& k )
		{
			return tree.upper_bound(k);
		}

    	std::pair<iterator,iterator> equal_range( const key_type& key )
		{
			return tree.equal_range(key);
		}

		// lookup end

		// observers start

		key_compare key_comp() const
		{
			return (key_compare());
		}

		value_compare value_comp() const
		{
			return (value_compare(key_compare()));
		}

		// observers end
	};
}
#endif