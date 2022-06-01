#pragma once
#include <array>
#include <iterator>
#include <algorithm>

template<class T>
class Predicate
{
public:
    virtual bool operator () (T x) = 0;
};

template<class T>
class Positive : public Predicate<T>
{
public:
    virtual bool operator () (T x)
    {
        return x > 0;
        
    }
};

template<class T>
class Negative : public Predicate<T>
{
public:
    virtual bool operator () (T x)
    {
        return x < 0;
        
    }
};

template<class T>
void erase_copy(T *begin, T *end, T *to)
{
    for (T* from = begin; from < end; from++)
    {
        *to = *begin;
        *begin = 0;
        to++;
        begin++;
    }
}

template<class T>
int erase_copy_if(T *begin, T *end, T *to, Predicate<T> &p)
{
    int n = 0;
    for (T* from = begin; from < end; from++)
    {
        if ( p(*from) )
        {
            *to = *begin;
            *begin = 0;
            to++;
            n++;
        }
        begin++;
    }
    return n;
}
