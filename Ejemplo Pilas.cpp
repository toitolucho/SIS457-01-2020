#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {
	stack<string> pila;
	
	pila.push("alejandro");
	pila.push("rodrigo");
	pila.push("fernando");
	
	cout<<pila.top()<<endl;
	
	pila.pop();
	
	cout<<pila.top()<<endl;
	
	return 0;
}

