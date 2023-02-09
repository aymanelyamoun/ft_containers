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

		key operator()(value_type &p1)
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
			bool operator()(value_type &p1, value_type &p2)
			{
				return comp(p1.first, p2.first);
			}
		};

	private:
		typedef RBTree<value_type, get_key_pairs<const key_type, value_type>, allocator_type, key_compare> RB_tree;
		RB_tree tree;
	public:
		typedef typename RB_tree::iterator iterator;
		typedef typename RB_tree::reverse_iterator reverse_iterator;

		reverse_iterator rbegin() {return tree.rbegin();}
		reverse_iterator rend() {return tree.rend();}

		void insert(value_type value)
		{
			tree.insert(value);
		}
		void delete_(value_type value)
		{
			tree.delete_(value);
		}

	};
}
#endif