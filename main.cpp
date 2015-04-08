#include "template.h"

void main(void)
	{
	 
	int arr[3];
	int check = 321;
	arr[0] = 123; arr[1] = 456; arr[2] = 789;
	MySet<int> one;
	one.add(arr[0]);
	one.add(arr[1]);
	one.add(arr[2]);
	one.add(arr[2]);
	one.OutPut();
	std :: cout << std :: endl << one.size() << std ::  endl;
	
	one.remove(arr[1]);
	S.OutPut();
	 std :: cout <<  std :: endl << one.size() << std ::  endl <<  std :: endl;

	   system("PAUSE");
	} 
