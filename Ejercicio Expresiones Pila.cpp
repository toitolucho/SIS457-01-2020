#include <iostream>
#include <stack>
using namespace std;

bool esvalida(string expresion)
{
	stack<char> pila_exp;
	for(int i = 0; i<expresion.size(); i++)
	{
		char a = expresion[i];
		if(a == '(' || a =='{' || a == '[')
		{
			pila_exp.push(a);
		}
		else
		{
			if(pila_exp.size() == 0)
			{
				return false;
			}//{[(])}  ()()
			char x = pila_exp.top();
			switch (a)
			{
				case ')':
					if(x == '{' || x == '[')
						return false;
					break;
				case '}':
					if(x == '('  || x == '[')
						return false;
					break;
				case ']':
					if(x == '{'  || x == '(')
						return false;
					break;
			}
			pila_exp.pop();
					
					
			
		}
	}
	return pila_exp.size() == 0;
		
}

int main(int argc, char *argv[]) {
	
	string expresion;
	int n;
	cout<<"Int. Cantidad de pruebas"<<endl;
	cin>>n;
	while(n--)
	{
		cin>>expresion;
		if(esvalida(expresion))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	
	
	return 0;
}

