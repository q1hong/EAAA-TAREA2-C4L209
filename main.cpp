#include <iostream>
using namespace std;

int main(){

	return 0;
}
// Base
class Componente { 
	
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


