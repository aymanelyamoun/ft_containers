#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef typename container_type::value_type      value_type;
        typedef typename container_type::reference       reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::size_type       size_type;

        explicit stack(const container_type &ctnr = container_type()) : _ctnr(ctnr) {}
        bool empty() const { return _ctnr.empty(); }
        size_type size() const { return _ctnr.size(); }
        reference top() { return _ctnr.back(); }
        const_reference top() const { return _ctnr.back(); }
        void push(const value_type &val) { _ctnr.push_back(val); }
        void pop() { _ctnr.pop_back(); }
        stack& operator=(const stack& __q) {_ctnr = __q._ctnr; return *this;}

    protected:
        container_type _ctnr;
    template< class Ty, class Cont >
    friend bool operator==( const ft::stack<Ty,Cont>& lhs, const ft::stack<Ty,Cont>& rhs );

    template< class Ty, class Cont >
    friend bool operator<( const ft::stack<Ty,Cont>& lhs, const ft::stack<Ty,Cont>& rhs );
    };

    template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs._ctnr == rhs._ctnr;
    }

    template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return !(lhs == rhs);
    }

    template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs._ctnr < rhs._ctnr;
    }

    template< class T, class Container >
    bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return rhs < lhs;
    }

    template< class T, class Container >
    bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return !(rhs < lhs);
    }

    template< class T, class Container >
    bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return !(rhs > lhs);
    }

}
