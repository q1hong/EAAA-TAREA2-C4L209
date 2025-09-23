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
	private:
		string material;
		string tamano;
		double downforce;
	public:
		Aleron(int id, string material, string tamano, double downforce, double costo) : Componente(id, costo, "ALERON"){
			this->material = material;
			this->tamano = tamano;
			this->downforce = downforce;
		}
	string getMaterial() const {
		return material;
	}
	string getTamano() const{
		return tamano;
	}
	double getDownforce() const {
		return downforce;
	}

};	

class Chasis : public Componente{
	private:
		string material;
		double peso;
	public:
		Chasis(int id, string material, double peso, double costo) : Componente(id, costo, "CHASIS"){
			this->material = material;
			this->peso = peso;
		}
	// Getters
    string getMaterial() const {
        return material;
    }
    
    double getPeso() const {
        return peso;
    }
};

class Manillar : public Componente{
	private:
		string material;
		string tipo; // Crucero o Deportivo, no es el mismo que el de Componente()
	public:
		Manillar(int id, string material, string tipo, double costo) : Componente(id, costo, "MANILLAR"){
			this->material = material;
			this->tipo = tipo;
		}
	string getTipo() const {
		return tipo;
	}
    string getMaterial() const {
        return material;
    }	
};

// Interfaz para competidores
class ICompetidor{
	public:
		virtual double calcularPuntuacionRendimiento() const = 0;
		virtual ~ICompetidor(){}
};

// Base
class Vehiculo{
	private:
		int id;
		string marca;
		string modelo;
		Motor* motor;
		Llantas* llantas;
	public:
		Vehiculo(int id, string marca, string modelo){
			this->id = id;
			this->marca = marca;
			this->modelo = modelo;
			this->motor = nullptr;
			this->llantas = nullptr;
		}
};

class Automovil : public Vehiculo{
	private:
		Carroceria* carroceria;
		Transmision* transmision;
	public:
		Automovil(int id, string marca, string modelo) : Vehiculo(id, marca, modelo){
			this->carroceria = nullptr;
			this->transmision = nullptr;
		}
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