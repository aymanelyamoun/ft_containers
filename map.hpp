// #ifndef MAP
// #define MAP
#pragma once
#include <memory>
#include "red_black_tree2.hpp"
#include "equality.hpp"

namespace ft
{

	template<typename key, typename T>
	struct get_key_pairs
	{
		typedef T value_type;
		typedef key key_type;

		key_type operator()(const value_type &p1) const
		{
			return p1.first;
		}
	};

	template <class _Key, class _Tp, class _Compare = std::less<_Key>, class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key                                        key_type;
		typedef _Tp                                         mapped_type;
		typedef ft::pair<const key_type, mapped_type>      value_type;
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
		typedef ft::RBTree<value_type, _get_key_pairs, allocator_type, key_compare> RB_tree;
		RB_tree tree;
		// size_type _size;
		typedef typename RB_tree::node_ptr node_ptr;
	public:
		typedef typename RB_tree::iterator iterator;
		typedef typename RB_tree::const_iterator const_iterator;
		typedef typename RB_tree::reverse_iterator reverse_iterator;

		explicit map (const key_compare& _comp = key_compare(), const allocator_type& alloc = allocator_type())
		: tree(key_compare(_comp), allocator_type(alloc)) {}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{ insert(first, last); }

		map (const map& x): tree(x.tree){}

		map& operator= (const map& x)
		{
			// _size = x._size;
			clear();
        	insert(x.tree.begin(), x.tree.end());
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
			tmp = tree.find(value).base();
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
		iterator end() {return tree.end();}

		const_iterator begin() const {return tree.begin();}
		const_iterator end() const {return tree.end();}

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
			return tree.size();
		}

		size_type max_size() const
		{
			return tree.max_size();
		}

		//end capacity

		// modifiers 

		void clear() {tree.free_tree();}

		ft::pair<iterator, bool> insert(const value_type& value)
		{
			return tree.insert(value);
		}

		iterator insert(iterator pos, const value_type& data)
		{
			return (tree.insert(pos, data));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) { tree.insert(first, last); }
		
		iterator erase( iterator pos )
		{
			return tree.erase(pos);
		}

		//forgot erase with range and erase with key

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
		iterator find( const key_type& key )
		{
			// std::cout << "iter\n";
			return (tree.find(key));
		}

		const_iterator find( const key_type& key ) const
		{
			// std::cout << "const iter\n";
			return (const_iterator(tree.find(key)));
		}

		iterator lower_bound( const key_type& key )
		{
			return tree.lower_bound(key);
		}
		const_iterator lower_bound( const key_type& key ) const
		{
			return tree.lower_bound(key);
		}
		iterator upper_bound( const key_type& k )
		{
			return tree.upper_bound(k);
		}
		const_iterator upper_bound( const key_type& k ) const
		{
			return tree.upper_bound(k);
		}

    	ft::pair<iterator,iterator> equal_range( const key_type& key )
		{
			return tree.equal_range(key);
		}

    	ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const
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

template< class Key, class T, class Compare, class Alloc >
bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
                 const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return rhs < lhs;
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs )
{
	return (!(lhs < rhs));
}

template< class Key, class T, class Compare, class Alloc >
void swap( ft::map<Key, T, Compare, Alloc>& lhs,
           ft::map<Key, T, Compare, Alloc>& rhs )
{
	lhs.swap(rhs);
}

// #endif