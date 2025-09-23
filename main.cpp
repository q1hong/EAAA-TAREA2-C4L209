#include <iostream>
using namespace std;

int main(){

	return 0;
}
// Base
class Componente { 
	private:
		int id;
		double costo;
	public:
		Componente(int id, double costo){
			this->id = id;
			this->costo = costo;
		}
		int getID(){
			return id;
		}
		double getCosto(){
			return costo;
		}
		void setID(int id_nuevo){
			id = id_nuevo;
		}
		void setCosto(double costo_nuevo){
			costo = costo_nuevo;
		}

};

class Motor : public Componente{

};

class Carroceria : public Componente{

};

class Transmision : public Componente{

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
class Deportivo : public Automovil, public  ICompetidor{

};

class Sedan : public Automovil {

};

class Camioneta : public Vehiculo{

};

class Motocicleta : public Vehiculo, public ICompetidor{

};


