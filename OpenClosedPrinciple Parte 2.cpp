#include <iostream>
#include <vector>
using namespace std;


enum class Color{Rojo = 1, Verde, Amarillo, Blanco, Azul};
enum class Tamanio{ExtraGrande = 1, Grande, Mediano, Pequenio};
class Articulo
{
public:
	string nombre;
	float precio;
	Color color;
	Tamanio tamanio;
	
	void imprimir()
	{
		cout<<"Nombre "<<nombre<<endl;
		cout<<"Precio "<<precio<<endl;
		switch(color)
		{
			case Color::Rojo : cout<<"Color Rojo"<<endl; break;
			case Color::Verde : cout<<"Color Verde"<<endl; break;
			case Color::Amarillo : cout<<"Color Amarillo"<<endl; break;
			case Color::Blanco : cout<<"Color Blanco"<<endl; break;
			case Color::Azul : cout<<"Color Azul"<<endl; break;		
		}
		
		switch(tamanio)
		{
			case Tamanio::ExtraGrande : cout<<"Tamanio ExtraGrande"<<endl; break;
			case Tamanio::Grande : cout<<"Tamanio Grande"<<endl; break;
			case Tamanio::Mediano : cout<<"Tamanio Mediano"<<endl; break;
			case Tamanio::Pequenio : cout<<"Tamanio Pequenio"<<endl; break;
		
		}
	}
	
};


typedef vector<Articulo> Items;
typedef int entero;

class FiltradorArticulos
{
public:
	//entero cantidad;
	 Items articulos;
	Items filtrarPorColor(Color c)
	{
		Items resultado;
		for( auto x : articulos )
		{
			if(x.color == c)
			{
				resultado.push_back(x);
			}
		}
		return resultado;
	};
	
	Items filtrarPorTamanio(Tamanio t)
	{
		Items resultado;
		for( auto x : articulos )
		{
			if(x.tamanio == t)
			{
				resultado.push_back(x);
			}
		}
		return resultado;
	};
	
	Items filtrarPorTamanioColor(Tamanio t, Color c)
	{
		Items resultado;
		for( auto x : articulos )
		{
			if(x.tamanio == t  && x.color == c)
			{
				resultado.push_back(x);
			}
		}
		return resultado;
	};
};


template<typename T> class ICondicionable{
public:
	virtual bool cumpleCondicion(T* objeto) = 0;
};

template<typename T>  class IFiltrable{
public:
	virtual vector<T*>  filtrar(vector<T*> lista, ICondicionable<T> &condicion) = 0;
};


class FiltroColor : public ICondicionable<Articulo>
{
public:
	Color color;
	
	FiltroColor(Color cq)
	{
		color = cq;
	}
	
	bool cumpleCondicion(Articulo* p) override
	{
		return p->color == color;
	}
};

class FiltroBarato : public ICondicionable<Articulo>
{
public:
	float precioBarato;
	
	FiltroBarato(float precio)
	{
		precioBarato = precio;
	}
	
	bool cumpleCondicion(Articulo* p) override
	{
		return p->precio <= precioBarato;
	}
};

class FiltroTamanio : public ICondicionable<Articulo>
{
public:
	Tamanio tamanio;
	
	FiltroTamanio(Tamanio cq)
	{
		tamanio = cq;
	}
	
	bool cumpleCondicion(Articulo* p) override
	{
		return p->tamanio == tamanio;
	}
};

template <typename T> class FiltroAnd : public ICondicionable<T>
{
public:
	ICondicionable<T>& filtro1;
	ICondicionable<T>& filtro2;
	
	FiltroAnd(ICondicionable<T>& a, ICondicionable<T>& b): filtro1(a), filtro2(b) 
	{
		//filtroColor  (a);
		//filtroTamanio = b;
	}
	
	bool cumpleCondicion(T* p) override
	{
		return filtro1.cumpleCondicion(p) && filtro2.cumpleCondicion(p);
	}
};

class FiltradorArticulosMejorado : public IFiltrable<Articulo>
{
	typedef vector<Articulo *> vectorA;
	typedef int entero;
	
	entero n;
public:
	vectorA filtrar(vectorA lista, ICondicionable<Articulo> &sentencia) override
	{
		vectorA resultado;
		for( auto x : lista )
		{
			if(sentencia.cumpleCondicion(x))
			{
				resultado.push_back(x);
			}
		}
		return resultado;
	}
};

int main(int argc, char *argv[]) {
	
	vector<Articulo*> lista;
	Articulo ar1;
	ar1.nombre = "Camiseta"; 
	ar1.precio = 50.0f;
	ar1.color = Color::Rojo;
	ar1.tamanio = Tamanio::Grande;
	Articulo ar2 {"Buso", 35, Color::Azul, Tamanio::Mediano};
	Articulo ar3 {"Camisa" , 65 , Color::Rojo, Tamanio::Mediano};
	Articulo ar4 {"Corbata" , 25 , Color::Azul, Tamanio::Pequenio};
	Articulo ar5 {"Malla" , 25 , Color::Blanco, Tamanio::ExtraGrande};
	
	lista.push_back(&ar1);
	lista.push_back(&ar2);
	lista.push_back(&ar3);
	lista.push_back(&ar4);
	lista.push_back(&ar5);
	
	FiltroColor fc(Color::Rojo);
	FiltroTamanio ft(Tamanio::Mediano);
	FiltroBarato fb(30);
	
	FiltroAnd <Articulo> ftc(fc,ft);
	
	FiltradorArticulosMejorado fam;
	auto resp = fam.filtrar(lista,fb);
	for(auto x : resp)
		x->imprimir();
	return 0;
}

int main2(int argc, char *argv[]) {
	
	Items articulos;
	Articulo ar1;
	ar1.nombre = "Camiseta"; 
	ar1.precio = 50.0f;
	ar1.color = Color::Rojo;
	ar1.tamanio = Tamanio::Grande;
	Articulo ar2 {"Buso", 35, Color::Azul, Tamanio::Mediano};
	Articulo ar3 {"Camisa" , 65 , Color::Rojo, Tamanio::Mediano};
	Articulo ar4 {"Corbata" , 25 , Color::Azul, Tamanio::Pequenio};
	Articulo ar5 {"Malla" , 25 , Color::Blanco, Tamanio::ExtraGrande};
	
	articulos.push_back(ar1);	
	articulos.push_back(ar2);
	articulos.push_back(ar3);
	articulos.push_back(ar4);
	articulos.push_back(ar5);
	
	FiltradorArticulos fa;
	fa.articulos = articulos;
	Items resp =  fa.filtrarPorColor(Color::Azul);
	cout<<"Filtro por Color"<<endl;
	for(auto x : resp)
		x.imprimir();
	resp = fa.filtrarPorTamanio(Tamanio::Mediano);
	cout<<endl<<"Filtro por Tamanio"<<endl;
	for(auto x : resp)
		x.imprimir();
	
	resp = fa.filtrarPorTamanioColor(Tamanio::Mediano, Color::Rojo);
	cout<<endl<<"Filtro por Tamanio y Color"<<endl;
	for(auto x : resp)
		x.imprimir();
	return 0;
}

