/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:52:53 by ael-yamo          #+#    #+#             */
/*   Updated: 2023/01/05 19:13:107 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
    template<class Iter>
    struct iterator_traits
    {
        typedef typename Iter::iterator_category iterator_category; 
        typedef typename Iter::value_type value_type;
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
    };

    template<class T> 
    struct iterator_traits<T*> 
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    };
    
    template<class Cat, class T, class Dist= ptrdiff_t, class Ptr= T*, class Ref= T&>
    struct iterator
    {
        typedef Cat iterator_category;
        typedef T value_type;
        typedef Dist difference_type;
        typedef Ptr pointer;
        typedef Ref reference;
    };

    template<class _Iter>
    struct iterator_wrap
    {
        typedef _Iter iterator_type;
        typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename iterator_traits<iterator_type>::value_type        value_type;
        typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
        typedef typename iterator_traits<iterator_type>::pointer           pointer;
        typedef typename iterator_traits<iterator_type>::reference         reference;
        private:
            iterator_type it;
        public:
            iterator_wrap() {};
            iterator_wrap(iterator_type ptr) : it(ptr) {};
        
            reference       operator*() { return (*it); }
            pointer         operator->() {return (it); }

            iterator_wrap   &operator++(){ it++ ; return *this; }
            iterator_wrap   operator++(int){ iterator_wrap tmp(*this); ++(*this); return tmp; }

            iterator_wrap   &operator--(){ it-- ; return *this;}
            iterator_wrap   operator--(int){ iterator_wrap tmp(*this); --(*this); return tmp; }

            iterator_wrap   operator+(difference_type n) { iterator_wrap tmp(*this) ; tmp =+ n; return (tmp); }
            iterator_wrap   operator-(difference_type n) { iterator_wrap tmp(*this) ; tmp =- n; return (tmp); }

            iterator_wrap   &operator-=(difference_type n) { it =- n; return (*this); }
            iterator_wrap   &operator+=(difference_type n) { it =+ n; return (*this); }

            reference       operator[](difference_type n) {return (it[n]);}
            iterator_type   base() const {return it;}
            
            template<class iter>
            inline bool operator==(const iterator_wrap<iter> &lhs) 
            { return (this->base() == lhs.base()); }
 
            template<class iter>
            inline bool operator!=(const iterator_wrap<iter> &lhs) 
            { return (this->base() != lhs.base());}

            // bool            operator<(iterator_wrap &lhs) {}
    };
    
    template <class _Iter>
    class reverse_iterator
    : public iterator<typename iterator_traits<_Iter>::iterator_category,
                      typename iterator_traits<_Iter>::value_type,
                      typename iterator_traits<_Iter>::difference_type,
                      typename iterator_traits<_Iter>::pointer,
                      typename iterator_traits<_Iter>::reference>
    {
        public:
            typedef _Iter                                            iterator_type;
            typedef typename iterator_traits<_Iter>::difference_type difference_type;
            typedef typename iterator_traits<_Iter>::reference       reference;
            typedef typename iterator_traits<_Iter>::pointer         pointer;
        private:
            iterator_type current;
        
        reverse_iterator() {}
        reverse_iterator (iterator_type __iter) : current(__iter){};
        template<class __iner>
        reverse_iterator(const reverse_iterator<__iner> &_iner_iter): current(_iner_iter.base()) {}

        iterator_type base() const {return current;}
        
        template<class __iner>
        reverse_iterator &operator=(reverse_iterator<__iner> &_iner_iter) 
        { current = _iner_iter.base(); return (*this);}

        reference operator*() const {iterator_type tmp = current; return *(--tmp);}
        
        pointer operator->() const {iterator_type tmp = current; return (--tmp);}
        
        reverse_iterator &operator++() {current-- ;return (*this);}
        reverse_iterator operator++(int) {reverse_iterator tmp = *this; --(*this); return (tmp);}

        reverse_iterator &operator--() {current++; return (*this);}
        reverse_iterator operator--(int) {reverse_iterator tmp = *this; ++(*this); return (tmp);}
        
        reverse_iterator operator+(difference_type n) const {return (current - n);}
        reverse_iterator &operator+=(difference_type n) { current -= n; return *this; }

        reverse_iterator operator-(difference_type n) const {return (current + n);}

        reverse_iterator &operator-=(difference_type n) { current += n; return *this; }

        reference operator[](difference_type n) const { return *(*this + n);}

    };
}










