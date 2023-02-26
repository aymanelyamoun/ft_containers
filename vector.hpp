/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:02:08 by ael-yamo          #+#    #+#             */
/*   Updated: 2023/01/05 12:17:07by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include "iterator.hpp"
#include "type_trait.hpp"
#include "equality.hpp"

namespace ft{
    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type&   const_reference;
            typedef Alloc allocator_type;
            typedef typename allocator_type::value_type* pointer;
            typedef typename allocator_type::value_type const* const_pointer;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocator_type::difference_type difference_type;
            typedef typename ft::iterator_wrap<pointer> iterator;
            typedef typename ft::iterator_wrap<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator>         reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;
        private:
            size_type  __size;
            size_type  __capacity;
            Alloc   myAllocator;
            pointer arr;
        public:

        // // // // // // // //
        // Member functions start
        // // // // // // // //
    
            vector()
            {
                __size = 0;
                __capacity = 0;
            }

            // vector(int n)
            // {
            //     __size = 0;
            //     __capacity = n;
            //     arr = myAllocator.allocate(__capacity);
            //     for (size_type i = 0; i < n; i++)
            //     {
            //         myAllocator.construct(&arr[i], value_type());
            //         __size++;
            //     }
            // }

            explicit vector( const allocator_type& alloc )
            {
                __size = 0;
                __capacity = 0;
                this->myAllocator = alloc;
            }

            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                __size = 0;
                __capacity = n;
                myAllocator = alloc;
                arr = myAllocator.allocate(__capacity);
                for (size_type i = 0; i < n; i++)
                {
                    arr[i] = val;
                    __size++;
                }
            }

            template <class InputIterator>
            vector (typename ft::enable_if<std::__is_input_iterator<InputIterator>::value && !std::__is_forward_iterator<InputIterator>::value , InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                __size = 0;
                __capacity = 0;
                myAllocator = alloc;

                for (InputIterator it = first; it != last; it++)
                {
                    this->push_back(*it);
                }
            }
            
            template <class InputIterator>
            vector (typename ft::enable_if<std::__is_forward_iterator<InputIterator>::value , InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                __size = 0;
                myAllocator = alloc;

                difference_type df = std::distance(first, last);
                __capacity = df;
                arr = myAllocator.allocate(__capacity);
                for (InputIterator it = first; it != last; it++)
                {
                    this->push_back(*it);
                }
            }

            ~vector()
            {
                if (__size != 0)
                {
                    for(size_type i = 0; i < __size; i++)
                        myAllocator.destroy(arr + i);
                    myAllocator.deallocate(arr, __capacity);
                }
            }

            vector( const vector& x )
            {
                __size = 0;
                __capacity = 0;
                this->reserve(x.size());
                for (size_type i = 0; i < x.size(); i++)
                {
                    this->push_back(x[i]);
                }
            }
            vector& operator= (const vector& x)
            {
                if (this != &x)
                {
                    this->clear();
                    this->reserve(x.size());
                    for (size_type i = 0; i < x.size(); i++)
                    {
                        this->push_back(x[i]);
                    }
                }
                return (*this);
            }
            
            size_type recomended_size(size_type new_size)
            {
                size_type ms = max_size();
                if (new_size > ms)
                    std::__throw_length_error("vector");
                if (__capacity >= ms / 2)
                    return (ms);
                else
                    return std::max(new_size, __capacity * 2);
            }

            void assign( size_type n, const value_type& value )
            {
                if (n > 0)
                {
                    __size = 0;
                    if (n < __capacity)
                    {
                        __size = n;
                    }
                    else
                    {
                        vector v;
                        v.reserve(recomended_size(n));
                        v.__size = n;
                        swap(v);
                    }
                    std::fill_n(this->begin(), n, value);
                }
            }

            template< class InputIt >
            typename ft::enable_if<std::__is_input_iterator<InputIt>::value && !std::__is_forward_iterator<InputIt>::value, void >::type
            assign( InputIt first, InputIt last)
            {
                clear();
                for (;first != last; first++)
                    push_back(*first);
            }

            template< class InputIt >
            typename ft::enable_if<std::__is_forward_iterator<InputIt>::value, void >::type
            assign( InputIt first, InputIt last)
            {
                clear();
                difference_type new_size = ft::distance(first, last);
                size_type n = static_cast<size_type>(new_size);
                if (n > 0)
                {
                    if (n > __capacity)
                    {
                        if(__capacity != 0)
                            myAllocator.deallocate(arr, __capacity);
                        reserve(recomended_size(n));
                    }
                    for (;first != last; first++)
                    {
                        myAllocator.construct(&arr[__size], *first);
                        __size++;
                    }
                }
            }

            allocator_type get_allocator() const
            {
                return (myAllocator);
            }

        // // // // // // // //
        // Member functions end
        // // // // // // // //

        // // // // // // // //
        // Element access start
        // // // // // // // //

            reference at( size_type pos )
            {
                if (pos > this->size())
                    throw(std::out_of_range("index out of range"));
                return (arr[pos]); 
            }

            const_reference at( size_type pos ) const
            {
                if (pos > this->size())
                    throw(std::out_of_range("index out of range"));
                return (arr[pos]); 
            }

            reference operator[]( size_type pos ) { return (arr[pos]); }

            const_reference operator[]( size_type pos ) const { return (arr[pos]); }

            reference front() { return (arr[0]); }

            const_reference front() const { return (arr[0]); }

            reference back() { return (arr[__size - 1]);}

            const_reference back() const { return (arr[__size - 1]);}

            T* data() {return (arr); }
            const T* data() const {return (arr); }

        // // // // // // // //
        // Element access end
        // // // // // // // //

        // // // // // // // //
        // Iterators start
        // // // // // // // //

            iterator begin() {return iterator(arr);};
            const_iterator begin() const {return const_iterator(arr);};
            iterator end() {return iterator(&arr[__size]);};
            const_iterator end() const {return const_iterator(&arr[__size]);};
            reverse_iterator rbegin() {return reverse_iterator(end());}
            reverse_iterator rend() {return reverse_iterator(begin());}

        // // // // // // // //
        // Iterators end
        // // // // // // // //

        // // // // // // // //
        // Capacity start
        // // // // // // // //
            bool empty() const {bool is_empty = true; if (begin() != end()) is_empty = false; return (is_empty);}

            size_type size() const {return (__size);}

            size_type max_size() const 
            {
                return std::min<unsigned long>(myAllocator.max_size(), std::numeric_limits<difference_type >::max());
            }

            void reserve( size_type new_cap )
            {
                pointer tmp_arr;
                size_type  amount_to_free;

                amount_to_free = __capacity;
                if (__capacity < new_cap)
                {
                    __capacity = new_cap;
                    tmp_arr = myAllocator.allocate(__capacity);
                    for (size_t i = 0; i < __size; i++)
                        myAllocator.construct(&tmp_arr[i], arr[i]);
                    if (__size != 0)
                    {
                        for (size_t i = 0; i < __size; i++)
                            myAllocator.destroy(&arr[i]);
                        myAllocator.deallocate(arr, amount_to_free);
                    }
                    arr = tmp_arr; 
                }
            }

            size_type capacity() const {return (__capacity);}
        // // // // // // // //
        // Capacity end
        // // // // // // // //

        // // // // // // // //
        // Modifiers start
        // // // // // // // //

            void clear()
            {
                if (__size != 0)
                {
                    for (size_type i = 0; i < __size; i++)
                        myAllocator.destroy(&arr[i]);
                }
                __size = 0;
            }

            iterator insert( const_iterator pos, const T& value )
            {
                size_type i;
                value_type next = value;

                i = pos - begin();
                if (pos - begin() < 0)
                {
                    i = 0;
                    next = value_type();
                }
                if (__size < __capacity)
                {
                    for (size_type index = size(); index > i; --index)
                        myAllocator.construct(&arr[index], arr[index - 1]);
                    myAllocator.construct(&arr[i],  next);
                }
                else
                {
                    size_type tmp_capacity = __capacity;
                    __capacity = recomended_size(__capacity);
                    pointer tmp = myAllocator.allocate(__capacity);

                    std::copy(begin(), begin() + i, tmp);
                    myAllocator.construct(&tmp[i], next);
                    std::copy(begin() + i, end(), tmp + i + 1);
                    myAllocator.deallocate(arr, tmp_capacity);
                    arr = tmp;
                }
                __size++;
                return (iterator(arr + i));
            }

            iterator insert (const_iterator pos, size_type n, const value_type& value)
            {
                size_type i;
                value_type next = value;

                i = pos - begin();
                if (pos - begin() < 0)
                {
                    i = 0;
                    pos = begin();
                    next = value_type();
                }
                if (__size + n < __capacity)
                {
                    for (size_type index = size() + n - 1; index >= i + n; --index)
                    {
                        myAllocator.construct(&arr[index], arr[index - n]);
                        myAllocator.destroy(arr + index - n);
                    }

						for (size_type index = i; index < i + n; ++index)
							myAllocator.construct(&arr[index],  next);
                }
                else
                {
                    size_type tmp_capacity;
                    tmp_capacity = recomended_size(__capacity + n);
                    pointer tmp = myAllocator.allocate(tmp_capacity);



                    std::copy(begin(), begin() + i, tmp);
                    for (size_type index = i; index < i + n; ++index)
                        allocator_type().construct(tmp + index, value);
                    std::copy(begin() + i, end(), tmp + i + n);
                        myAllocator.deallocate(arr, __capacity);
                    __capacity = tmp_capacity;
                        arr = tmp;
                }
                __size += n;
                return (iterator(arr + i));
            }

            template <class InputIterator>
            iterator insert (const_iterator pos, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
            {
                size_type i;
                difference_type n;

                i = pos - begin();
                n = std::distance(first, last);
                if (pos - begin() < 0)
                {
                    i = 0;
                    pos = begin();
                }
                if (__size + n < __capacity)
                {
                    for (size_type index = size() + n - 1; index > i + n; --index)
                    {
                        myAllocator.construct(&arr[index], arr[index - n]);
                        myAllocator.destroy(arr + index - n);
                    }
        	        std::copy(first, last, arr + i);
                }
                else
                {
                    size_type tmp_capacity;
                    tmp_capacity = recomended_size(__capacity + n);
                    pointer tmp = myAllocator.allocate(tmp_capacity);

                    std::copy(begin(), begin() + i, tmp);
                    std::copy(first, last, tmp + i);
                    std::copy(begin() + i, end(), tmp + i + n);
                    myAllocator.deallocate(arr, __capacity);
                    arr = tmp;
                    __capacity = tmp_capacity;
                }
                __size += n;
                return (iterator(arr + i));
            }

            iterator erase (iterator position)
            {
                iterator it = position; 
            
                for (; it != end(); it++)
                    *it = *(it + 1);
                __size--;
                return (position);
            }

            iterator erase (iterator first, iterator last)
            {
                iterator it = first; 
                difference_type dis = std::distance(first, last);

                for (; it + dis != end(); it++)
                {
                    *it = *(it + dis);
                }
                for (it = end() - dis; it != end(); it++)
                {
                    myAllocator.destroy(it.base());
                }
                __size -= dis;
                return (first);
            }

            void push_back (const value_type& val)
            {
                pointer tmp_arr;
                size_type  amount_to_free;

                if (__size < __capacity)
                {
                    myAllocator.construct(&arr[__size], val);
                    __size++;
                }
                else
                {
                    amount_to_free = __capacity;
                    __capacity *= 2;
                    if (__capacity == 0)
                        __capacity = 1;
                    tmp_arr = myAllocator.allocate(__capacity);
                    for (size_t i = 0; i < __size; i++)
                        myAllocator.construct(&tmp_arr[i], arr[i]);
                    if (__size != 0)
                    {
                        for (size_t i = 0; i < __size; i++)
                            myAllocator.destroy(&arr[i]);
                        myAllocator.deallocate(arr, amount_to_free);
                    }
                    arr = tmp_arr;
                    myAllocator.construct(&arr[__size], val);
                    __size++;
                }
            }

            void pop_back()
            {
                if (__size > 0)
                {
                    myAllocator.destroy(&arr[__size - 1]);
                    __size--;
                }
            }

            void resize (size_type n, value_type val = value_type())
            {
                if (__size <= n)
                {
                    reserve(n);
                    while (__size < n)
                        push_back(val);
                }
                else if (__size > n)
                {
                    while (__size > n)
                        pop_back();
                }
            }
            
            void swap (vector& x)
            {
                std::swap(__capacity, x.__capacity);
                std::swap(__size, x.__size);
                std::swap(myAllocator, x.myAllocator);
                std::swap(arr, x.arr);
            }

        // // // // // // // //
        // Modifiers end
        // // // // // // // //
    };
    

template< class T, class Alloc >
void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
{lhs.swap(rhs); }

template <class _Tp, class _Allocator>
bool operator==(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Allocator>
bool operator!=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__x == __y);
}

template <class _Tp, class _Allocator>
bool operator< (const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Tp, class _Allocator>
bool operator> (const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return __y < __x;
}

template <class _Tp, class _Allocator>
bool operator>=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__x < __y);
}

template <class _Tp, class _Allocator>
bool operator<=(const vector<_Tp, _Allocator>& __x, const vector<_Tp, _Allocator>& __y)
{
    return !(__y < __x);
}
}


    // // // // // // // // //
    // // operator start
    // // // // // // // // //
    // template< class T, class Alloc >
    // bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
    // {
    //     if (lhs.size() != rhs.size())
    //         return (false);
    //     for (size_t i = 0; i < lhs.size(); i++)
    //     {
    //         if (lhs[i] != rhs[i])
    //             return (false);
    //     }
    //     return (true);
    // }

    // template< class T, class Alloc >
    // bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
    // {
    //     if (lhs.size() == rhs.size())
    //         return (false);
    //     for (size_t i = 0; i < lhs.size(); i++)
    //     {
    //         if (lhs[i] == rhs[i])
    //             return (false);
    //     }
    //     return (true);
    // }

    // template< class T, class Alloc >
    // bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
    // {
    //     if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
    //         return (true);
    //     return (false);
    // }


    // template< class T, class Alloc >
    // bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
    // {
    //     if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()))
    //         return (true);
    //     return (false);
    // }

    // template< class T, class Alloc >
    // bool operator<=( const std::vector<T,Alloc>& lhs,
    //              const std::vector<T,Alloc>& rhs )
    // {
    //     return (!(lhs > rhs));
    // }

    // template< class T, class Alloc >
    // bool operator>=( const std::vector<T,Alloc>& lhs,
    //              const std::vector<T,Alloc>& rhs )
    // {
    //     return (!(lhs < rhs));
    // }
    // // // // // // // // //
    // // operator end
    // // // // // // // // //












