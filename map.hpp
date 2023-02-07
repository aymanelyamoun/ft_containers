#include <memory>
#include "red_black_tree2.hpp"

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

private:
    typedef RBTree<value_type, allocator_type, key_compare> RB_tree;

    RB_tree tree;

};