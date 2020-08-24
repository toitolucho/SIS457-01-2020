#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Agenda
{
	public : 
		vector<string> notas;
		int gestion;
	
		void anotar(string nota)
		{
			notas.push_back(nota);
		}
		
		void borrar(string nota)
		{
			
		}
		void visualizar()
		{
			for(string nota: notas)
			{
				cout<<nota<<endl;
			}
		}
		
		
	
};

class ManegadorAgenda
{
	public:
	static void sacarRespaldo(Agenda& agenda,  string nombreArchivo)
	{
		ofstream ofs (nombreArchivo);
		for(string nota: agenda.notas)
		{
			ofs<<nota<<endl;
		}
	}
};

int main(int argc, char *argv[]) {
	
	Agenda miAgenda;
	miAgenda.anotar("1er Parial Programacion 01/09/2020");
	miAgenda.anotar("2do Parial Programacion 15/09/2020");
	miAgenda.anotar("Final Parial Programacion 30/09/2020");
	miAgenda.anotar("Sesion de Reunion");
	//miAgenda.sacarRespaldo("respaldo.txt");
	
	//miAgenda.visualizar();
	ManegadorAgenda::sacarRespaldo(miAgenda, "respaldo2.txt");
		
	return 0;
}

