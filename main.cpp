#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){

	return 0;
}
// Base
class Componente{
private:
	int id;
	double costo;
	string tipo;

public:
	Componente(int id, double costo, string tipo){
		this->id = id;
		this->costo = costo;
		this->tipo = tipo;
	}
	int getID() const{
		return id;
	}
	double getCosto() const {
		return costo;
	}
	string getTipo() const {
		return tipo;
	}
	void setID(int id_nuevo) {
		id = id_nuevo;
	}
	void setCosto(double costo_nuevo) {
		costo = costo_nuevo;
	}
};

class Motor : public Componente{
private:
	string tipoVehiculo;
	string cilindrada;
	int potencia;

public:
	Motor(int id, string tipoVehiculo, string tipo, string cilindrada, int potencia, double costo) : Componente(id, costo, tipo){
		this->tipoVehiculo = tipoVehiculo;
		this->cilindrada = cilindrada;
		this->potencia = potencia;
	}
	// Getters
	string getTipoVehiculo() const {
		return tipoVehiculo;
	}
	string getCilindrada() const {
		return cilindrada;
	}
	int getPotencia() const {
		return potencia;
	}
};

class Llantas : public Componente{
	private:
		double tamano;
		string perfil;
	public:
		Llantas(int id, string tipo, double tamano, string perfil, double costo) : Componente(id, costo, tipo){
			this-> tamano = tamano;
			this-> perfil = perfil;
		}
};

class Carroceria : public Componente{
	private:

		string color;
		int numeroPuertas;
	public:
		Carroceria(int id, string tipo, string color, int numeroPuertas, double costo) : Componente(id, costo, tipo){
			this->color = color;
			this->numeroPuertas = numeroPuertas;
		}
	};

class Transmision : public Componente{
	private:
		int velocidades;
	public:
		Transmision(int id, string tipo, int velocidades, double costo) : Componente(id, costo, tipo){
			this->velocidades = velocidades;
		}
};

// Componentes exclusivos
class Aleron : public Componente{

};

class Chasis : public Componente{

};

class Manillar : public Componente{

};

// Interfaz para competidores
class ICompetidor{

};

// Base
class Vehiculo{

};

class Automovil : public Vehiculo{

};

// Vehiculos derivados
class Deportivo : public Automovil, public ICompetidor{

};

class Sedan : public Automovil{

};

class Camioneta : public Vehiculo{

};

class Motocicleta : public Vehiculo, public ICompetidor{

};