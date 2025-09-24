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
	virtual ~Componente(){}

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
		string tamano;
		string perfil;
	public:
		Llantas(int id, string tipo, string tamano, string perfil, double costo) : Componente(id, costo, tipo){
			this-> tamano = tamano;
			this-> perfil = perfil;
		}
	string getTamano() const{
		return tamano;
	}
	string getPerfil() const{
		return perfil;
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
		string getColor() const{
			return color;
		}
		int getNumeroPuertas() const{
			return numeroPuertas;
		}
	};

class Transmision : public Componente{
	private:
		int velocidades;
	public:
		Transmision(int id, string tipo, int velocidades, double costo) : Componente(id, costo, tipo){
			this->velocidades = velocidades;
		}
		int getVelocidades() const{
			return velocidades;
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
	protected:
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
		virtual ~Vehiculo(){
			delete motor;
			delete llantas;
		}
	int getID() const {
	return id;
	}
	string getMarca() const{
		return marca;
	}
	string getModelo() const{
		return modelo;
	}
	Motor* getMotor() const {
		return motor;
	}
	Llantas *getLlantas() const{
		return llantas;
	}
	void setMotor(Motor* m){
		motor = m;
	}
	void setLlantas(Llantas* l){
		llantas = l;
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
		Carroceria* getCarroceria() const {
			return carroceria;
		}
		Transmision* getTransmision() const{
			return transmision;
		}
		void setCarroceria(Carroceria* c){
			carroceria = c;
		}
		void setTransmision(Transmision* t){
			transmision = t;
		}
};

// Vehiculos derivados

class Sedan : public Automovil{
	public:
    	Sedan(int id, string marca, string modelo) : Automovil(id, marca, modelo) {}
};

class Camioneta : public Vehiculo{
	protected:
    	Carroceria* carroceria;
   		Transmision* transmision;
	public:
    	Camioneta(int id, string marca, string modelo) : Vehiculo(id, marca, modelo){
        	this->carroceria = nullptr;
        	this->transmision = nullptr;
   		}
    
    	Carroceria* getCarroceria() const { return carroceria; }
    	Transmision* getTransmision() const { return transmision; }
    
    	void setCarroceria(Carroceria* c) { carroceria = c; }
    	void setTransmision(Transmision* t) { transmision = t; }
};

class Deportivo : public Automovil, public ICompetidor{
	private:
		Aleron* aleron;
	public:
		Deportivo(int id, string marca, string modelo) : Automovil(id, marca, modelo){
			this->aleron = nullptr;
		}
		virtual ~Deportivo(){
			delete aleron;
		}

	double calcularPuntuacionRendimiento() const override {
		if(!getMotor() || !getLlantas() || !aleron){
			return 0.0;
		}
		
		double potenciaHP = getMotor()->getPotencia();
		double downforceAleron = aleron->getDownforce();
		string tipoLlantas = getLlantas()->getTipo();

		double bonusLlantas = 0.0;
		
		if(tipoLlantas == "Deportivas"){
			bonusLlantas = 50;
		}
		else{
			bonusLlantas = 10;
		};
		double factorX = (rand()%11)-5;
		double puntuacion_base = (potenciaHP*0.5)+bonusLlantas+(downforceAleron*1.5);
		double puntuacion_final = puntuacion_base + (puntuacion_base*factorX/100.0);

		return puntuacion_final;
	}
	void setAleron(Aleron* a){
		aleron = a;
	}
	Aleron* getAleron() const {
		return aleron;
	}
};

class Motocicleta : public Vehiculo, public ICompetidor{
	private:
		Chasis* chasis;
		Manillar* manillar;

	public:
		Motocicleta(int id, string marca, string modelo) : Vehiculo(id, marca, modelo) {
			this->chasis = nullptr;
			this->manillar = nullptr;
		}
		virtual ~Motocicleta(){
			delete chasis;
			delete manillar;
		}
		double calcularPuntuacionRendimiento() const override {
			if (!getMotor() || !chasis || !manillar){
				return 0.0;
			}
			double potenciaHP = getMotor()->getPotencia();
			double pesoChasis = getChasis()->getPeso();
			string tipoManillar = getManillar()->getTipo();

			double bonusManillar = 0.0;
			double factorX = (rand()%11)-5;

			if (tipoManillar=="Deportivo"){
				bonusManillar = 40;
			}
			else{
				bonusManillar = 15;
			}

			double puntuacion_base = (potenciaHP/pesoChasis)*50+(bonusManillar);
			double puntuacion_final = puntuacion_base + (puntuacion_base*factorX/100.0);
			
			return puntuacion_final;
		}
	Chasis* getChasis() const{
		return chasis;
	}
	Manillar* getManillar() const { 
		return manillar;
	}
	void setChasis(Chasis* c){
		chasis = c;
	}
	void setManillar(Manillar* m){
		manillar = m;
	}

};