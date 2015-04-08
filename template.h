#pragma once
#include <iostream>
#include "Iset.h"

template <class T> class MySet : public ISet<T>
{
private:
    int s_set;
    T* arr;
    int cap;
    
public:
    MySet();
    ~MySet();
    virtual void add (const T& elem); // добавление в множество
    virtual void remove (const T& elem); // удаление элемента
    virtual bool contains (const T& elem) const; // содержание
    virtual int size () const;  // возращает размер
    void OutPut(); // только для удобства проверки
    MySet<T>& operator =(const MySet<T>& a);  // копирование
};


template <class T> MySet<T> :: MySet ()
{
    s_set = 0;
    arr = new T[1];
    cap = 1;
}


template <class T> MySet<T> :: ~MySet ()
{
    delete[] arr;
};


template <class T> void MySet<T> :: OutPut ()
{
    for (int i = 0 ; i < s_set ; i++)
        std :: cout << arr[i] << " ";
};


template <class T>  void MySet<T> :: add (const T& elem)
{
    T* e_set = new T[s_set + 1];
    if (s_set != 0)
        for (int i = 0 ; i < s_set ; i++)
        {
            e_set[i] = arr[i];
            if (arr[i] == elem)
                return;
        }
    
    delete[] arr;
    e_set[s_set] = elem;
    arr = e_set;
    s_set++;
}


template <class T> void MySet<T> :: remove (const T& elem)
{
    int i;
    for (i = 0 ; arr[i] != elem && i < s_set; i++)
    if (i == s_set && arr[s_set] != elem)
        return;
        
    for (int j = i ; j < s_set - 1 ; j++)
        arr[j] = arr[j + 1];
    s_set--;
    
}



template <class T> bool MySet<T> :: contains (const T& elem) const
{
    for (int i = 0 ; i < s_set ; i++)
        if (arr[i] == elem)
            return true;
    
    return false;
}


template <class T> int MySet<T> :: size () const
{
    return s_set;
}


template <class T> MySet<T>& MySet<T> :: operator= (const MySet<T>& a)
{
    s_set = a.s_set;
    cap = s_set + 1;
    if (s_set != 0)
    {
        if (arr != 0) delete[] arr;
        arr = new T[cap];
        for (int i = 0 ; i<s_set ; i++)
            arr[i] = a.arr[i];
    }
    return *this;
}
