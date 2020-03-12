#include <iostream>
using namespace std;
struct AutoBus{
	float nivel_combustible;
	int nro_asientos; //capacidad de asientos que tiene el bus
	int nro_asientos_ocupados; //la cantidad asientos que estan ocupados
	string nombre_chofer;
	string ci;
};

bool estaLleno(AutoBus a)
{
	bool estado = false;
	if(a.nro_asientos == a.nro_asientos_ocupados)
	{
		estado = true;
	}
	return estado;
}

bool estaVacio(AutoBus a)
{	
	return a.nro_asientos_ocupados == 0;
}

void recogerPasajeros(int cantidad, float peso_promedio, AutoBus &a)
{	
	//cout<< &a<<"  ";
	a.nro_asientos_ocupados = a.nro_asientos_ocupados + cantidad;
}

void dejarPasajeros(int cantidad, AutoBus &a)
{
	//cout<< &a<<"  ";
	a.nro_asientos_ocupados = a.nro_asientos_ocupados - cantidad;
}

int main()
{
	AutoBus a1;
	a1.nivel_combustible = 100;
	a1.nro_asientos = 30;
	a1.nro_asientos_ocupados = 0;
	a1.nombre_chofer = "Jaime Leaño";
	a1.ci ="5680549 Ch";
	
	int cp_suben, cp_bajan;
	
	//cout<< "Global "<< &a1;
	
	for(int i  = 1; i<=10; i++)
	{
		cout<<"\t\tDATOS DE LA PARADA "<< i<<endl;
		cout<<"Int. la Cantidad de pasajeros que suben";
		cin>>cp_suben;
		cout<<"Int. la Cantidad de pasajeros que Bajan";
		cin>>cp_bajan;
		dejarPasajeros(cp_bajan, a1);
		
		if(estaLleno(a1))
		{
			cout<<"No pueden subir mas pasajeros"<<endl;
		}
		else
		{
			recogerPasajeros(cp_suben, 0, a1);
		}
		
		
		
		cout<<"Asientos Ocupados "<< a1.nro_asientos_ocupados<<endl;
	}
	
	cout<<"Cantidad de Pasajeros finales "<< a1.nro_asientos_ocupados;
	return 0;
}
