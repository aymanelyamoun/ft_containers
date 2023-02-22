// #ifndef MAP
// #define MAP
#pragma once
#include <memory>
#include "red_black_tree2.hpp"
#include "equality.hpp"

namespace ft{

	// template <class _Key, class _Tp, class _Compare = std::less<_Key>, class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	// class map
	// template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
	public:
    typedef Key                                     key_type;
    typedef key_type                                 value_type;
    typedef Compare                                 key_compare;
    typedef key_compare                              value_compare;
    typedef Allocator                               allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;

	typedef typename allocator_type::value_type*        pointer;
	typedef typename allocator_type::value_type const*  const_pointer;
	typedef typename allocator_type::size_type          size_type;
	typedef typename allocator_type::difference_type    difference_type;

	private:
		typedef get_key<key_type> _get_key;
		typedef ft::RBTree<value_type, _get_key, allocator_type, key_compare> RB_tree;
		RB_tree tree;
		typedef typename RB_tree::node_ptr node_ptr;
	public:
		typedef typename RB_tree::iterator iterator;
		typedef typename RB_tree::const_iterator const_iterator;
		typedef typename RB_tree::reverse_iterator reverse_iterator;

	set() : tree(key_compare()) {}
	explicit set( const key_compare& comp, const Allocator& alloc = Allocator())
	: tree(key_compare(comp), allocator_type(alloc)) {}

	template< class InputIt >
	set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : tree(key_compare())
	{insert(first, last);}

	set( const set& x ): tree(x.tree){}

	set& operator=( const set& x )
	{
		clear();
		insert(x.tree.begin(), x.tree.end());
		return (*this);
	}

	allocator_type get_allocator() const { return allocator_type(); }

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

	iterator erase( iterator first, iterator last )
	{
		return tree.erase(first, last);
	}

	size_type erase( const key_type& key )
	{
		return tree.erase(key);
	}

	void swap( set& other )
	{
		tree.swap(other.tree);
	}

	// lookup

	size_type count( const key_type& key ) const
	{
		return (find(key) != end());
	}

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

	key_compare key_comp() const
	{
		return (key_compare());
	}
};

}
template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
{
	return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class Key, class Compare, class Alloc >
bool operator!=( const ft::set<Key, Compare, Alloc>& lhs,
                 const ft::set<Key, Compare, Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool operator<( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class Compare, class Alloc >
bool operator>( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs )
{
	return rhs < lhs;
}

template< class Key, class Compare, class Alloc >
bool operator<=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template< class Key, class Compare, class Alloc >
bool operator>=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs )
{
	return (!(lhs < rhs));
}

template< class Key, class Compare, class Alloc >
void swap( ft::set<Key, Compare, Alloc>& lhs,
           ft::set<Key, Compare, Alloc>& rhs )
{
	lhs.swap(rhs);
}
