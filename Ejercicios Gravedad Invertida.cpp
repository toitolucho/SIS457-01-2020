#include <iostream>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
	list<int> columnas;
	int n;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		int a;
		cin>>a;
		columnas.push_back(a);
	}
	columnas.sort();
	//list<int>::  j
	for(auto j = columnas.begin(); j!=columnas.end(); ++j)
	{
		cout<< *j <<" ";
	}
	
	
	return 0;
}

