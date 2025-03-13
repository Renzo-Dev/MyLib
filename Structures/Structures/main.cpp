#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> s = Stack<int>();
	s.push(1);
	s.push(2);
	Stack<int> r = Stack<int>(s);
}
