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

#include <iostream>
#include <memory>
#include "iterator.hpp"

namespace ft{
    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type&   const_reference;
            typedef Alloc allocator_type;
            typedef allocator_type::value_type* pointer;
            typedef allocator_type::value_type const* const_pointer;
            typedef allocator_type::size_type size_type;
            typedef allocator_type::difference_type difference_type;
            typedef typename ft::iterator_wrap<pointer> iterator;
            typedef typename ft::iterator_wrap<const_pointer> const_iterator;
            typedef ft::reverse_iterator<iterator>         reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;
        private:
            size_t  __size;
            size_t  __capacity;
            Alloc   myAllocator;
            pointer arr;
            iterator __begin;
            iterator __end;
        public:

        // // // // // // // //
        // Member functions start
        // // // // // // // //
    
            vector()
            {
                __size = 0;
                __capacity = 0;
            }

            vector(int n)
            {
                __size = 0;
                __capacity = n;
                arr = myAllocator.allocate(__capacity);
            }

            vector(int n, int value)
            {
                __size = 0;
                __capacity = n;
                arr = myAllocator.allocate(__capacity);
                for (size_t i = 0; i < n; i++)
                {
                    arr[i] = value;
                    __size++;
                }
            }
            ~vector()
            {
                if (__size != 0)
                    myAllocator.deallocate(arr, __capacity);
            }

            void assign( size_type n, const value_type& value )
            {
                this->__size = 0;
                for (size_type i = 0; i < n; i++)
                {
                    this->push_back(value);
                }
            }
            template< class InputIt >
            void assign( InputIt first, InputIt last );

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

            size_t size() { return (__size);}

            size_t capacity() { return (__capacity);}

            reference at( size_type pos )
            {
                if (pos < this->size())
                    throw(std::out_of_range("index out of range"));
                return (arr[pos]); 
            }

            const_reference at( size_type pos ) const
            {
                if (pos < this->size())
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
            iterator end() {return iterator(&arr[__size]);};
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

            // size_type max_size() const 
            // {
            //     return std::numeric_limits<difference_type>::max();
            // }

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
                        tmp_arr[i] = value_type(arr[i]);
                    if (__size != 0)
                        myAllocator.deallocate(arr, amount_to_free);
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
                    myAllocator.deallocate(arr, __capacity);
                __size = 0;
                __capacity = 0;
            }

            void insert (iterator position, size_type n, const value_type& x)
            {
                
            }

            void push_back (const value_type& val)
            {
                pointer tmp_arr;
                size_type  amount_to_free;

                if (__size < __capacity)
                {
                    arr[__size] = val;
                    __size++;
                }
                else
                {
                    // use reserve 
                    amount_to_free = __capacity;
                    __capacity *= 2;
                    if (__capacity == 0)
                        __capacity = 1;
                    tmp_arr = myAllocator.allocate(__capacity);
                    for (size_t i = 0; i < __size; i++)
                        tmp_arr[i] = value_type(arr[i]);
                    if (__size != 0)
                        myAllocator.deallocate(arr, amount_to_free);
                    arr = tmp_arr;
                    arr[__size] = val;
                    __size++;
                }
            }

            void pop_back()
            {
                if (__size > 0)
                    __size--;
            }

        // // // // // // // //
        // Modifiers end
        // // // // // // // //


            //add copy asign and destuctor;



    };

}













