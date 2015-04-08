#pragma once
#include <iostream>
#include "Iset.h"

template <class T> class MySet :
public ISet<T>
{
private:
	int s_set;
	T* arr;
public:
	 MySet();
	~MySet();
	 virtual void add (const T& elem);
	 virtual void remove (const T& elem);
	 virtual bool contains(const T& elem) const;
	 virtual int size () const;
	 void OutPut();
};


	template <class T> MySet<T> :: MySet () 
	{
		s_set = 0;
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
		for (int i = 0 ; i < s_set ; i++)                                 
		    if (arr[i] == elem)    // такой элемент уже существует              
			return;
		
	    if (s_set != 0)
	    {
			T* e_arr;
		    e_arr = new T[s_set];

		    for (int i = 0 ; i < s_set ; i++)
				e_arr[i] = arr[i];

		    delete[] arr;
		    arr = e_arr;
	    };

    	e_arr[s_set] = elem;
	    s_set++;
	}


	template <class T>	void MySet<T> :: remove (const T& elem)
	{
		int i;
	for ( i = 0; arr[i] != elem && i < s_set; i++)
	if (i == s_set && arr[s_set] != elem) // такой элемент не существует
		return;
	
	T* e_arr = new T[s_set - 1];

	for (int j = 0 ; j < i ; j++)  
		e_arr[j] = arr[j];

	for (int j = i ; j < s_set - 1 ; j++)  
		e_arr[j] = arr[j + 1];   

	delete[] arr;

	s_set--;
	}



	template <class T> bool MySet<T> :: contains (const T& elem) const
	{
		for (int i = 0; i < s_set; i++)
			if (arr[i] == elem)
				return true;
		
		return false;
	}


	template <class T> int MySet<T> :: size () const
	{
		return s_set;
	}
