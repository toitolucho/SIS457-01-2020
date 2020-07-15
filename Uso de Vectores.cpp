#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int a[10];
	vector<int> notas(5,0);
	
	//push_back --> permite insertar elementos al final
	//  |_|_|_|_|_|_|_|
	notas.push_back(1);
	notas.push_back(2);

	a[0] = 1;
	a[1] = 2;
	
	
	
	cout<<"dimension "<< notas.size()<<endl;
	cout<<"Posicion 0 "<<notas[0]<<endl;
	notas[0] = notas[0] +10;
	cout<<notas[0];
	
	notas.push_back(60);
	cout<<"dimension "<< notas.size()<<endl;
	
	
	notas.insert(notas.begin()+1,100);
	cout<<"posicion 0"<<notas[0]<<endl;
	
	for(int i=0; i<notas.size(); i++ )
	{
		cout<< notas[i]<< " ";
	}
	cout<<endl;
	vector<int>::iterator i;
	for( i = notas.begin() ; i!= notas.end(); ++i )
	{
		cout<< *i <<" ";
	}
	
	//para eleminar elementos
	//pop_back -> elimina el ultimo elemento insertado
	//erase  -> elimina un elemento en una determinada posicion (puntero)
	
	notas.pop_back();
	notas.erase(notas.begin()+1);
	notas.pop_back();
	notas.clear();
	notas.resize(10);
	
	
	cout<<endl;
	for( i = notas.begin() ; i!= notas.end(); ++i )
	{
		cout<< *i <<" ";
	}
	
	notas.assign(5, -15);
	cout<<endl;
	for( i = notas.begin() ; i!= notas.end(); ++i )
	{
		cout<< *i <<" ";
	}
	

	cout<<endl<<notas.front();
	
	cout<<endl;
	for( i = notas.begin() ; i!= notas.end(); ++i )
	{
		cout<< *i <<" ";
	}
	return 0;
}

