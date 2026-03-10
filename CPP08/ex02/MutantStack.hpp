#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename t> 
class MutantStack : public std::stack<t>
{
    public:
        typedef typename std::stack<t>::container_type::iterator iterator;

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack<t> &other);
        MutantStack<t> &operator=(const MutantStack<t> &other);

        iterator begin();
        iterator end();
};

template <typename t> 
MutantStack<t>::MutantStack() : std::stack<t>() {}

template <typename t> 
MutantStack<t>::~MutantStack() {}

template <typename t> 
MutantStack<t>::MutantStack(const MutantStack<t> &other) : std::stack<t>(other) {}

template <typename t> 
MutantStack<t> &MutantStack<t>::operator=(const MutantStack<t> &other)
{
    if (this == &other)
        return (*this);
    std::stack<t>::operator=(other);
    return (*this);
}

template <typename t> 
typename MutantStack<t>::iterator MutantStack<t>::begin()
{
    return (this->c.begin());
}

template <typename t> 
typename MutantStack<t>::iterator MutantStack<t>::end()
{
    return (this->c.end());
}

#endif
