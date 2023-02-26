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

        explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {}
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        reference top() { return c.back(); }
        const_reference top() const { return c.back(); }
        void push(const value_type &val) { c.push_back(val); }
        void pop() { c.pop_back(); }
        stack& operator=(const stack& __q) {c = __q.c; return *this;}

    protected:
        container_type c;
    private:
    template< class Ty, class Cont >
    friend bool operator==( const ft::stack<Ty,Cont>& lhs, const ft::stack<Ty,Cont>& rhs );

    template< class Ty, class Cont >
    friend bool operator<( const ft::stack<Ty,Cont>& lhs, const ft::stack<Ty,Cont>& rhs );
    };

    template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c == rhs.c;
    }

    template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return !(lhs == rhs);
    }

    template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
        return lhs.c < rhs.c;
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
