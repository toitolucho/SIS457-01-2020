#include <iostream>
#include <list>
using namespace std;

void mostrarElementos(list<string> lista)
{
	for(auto  i = lista.begin(); i!= lista.end(); ++i )
	{
		cout<< *i <<" ";
	}
	cout<<endl;
}


int main(int argc, char *argv[]) {
	list<string> estudiantes;
	
	estudiantes.push_back("fernando");
	estudiantes.push_back("alexander");
	estudiantes.push_front("Romina");
	estudiantes.push_back("adolfo");
	estudiantes.push_back("daniel");
	estudiantes.push_back("carlos");
	
	mostrarElementos(estudiantes);
	
	if(estudiantes.empty())
	{
		cout<<"lista vacia"<<endl;
	}
	else
		cout<<"lista con elementos"<<endl;
	
	
	
	
	string primero, ultimo;
	
	primero = estudiantes.front();
	estudiantes.pop_front();
	
	ultimo = estudiantes.back();
	estudiantes.pop_back();
	mostrarElementos(estudiantes);
	
	cout<<"Primer elemento "<< primero<<endl;
	cout<<"Ultimo elemento "<< ultimo<<endl;
	
	estudiantes.sort();
	estudiantes.reverse();
	
	mostrarElementos(estudiantes);
	
	
	return 0;
}

