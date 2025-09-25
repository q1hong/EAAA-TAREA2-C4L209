#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Base
class Componente{
protected:
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
	Motor(int id, string tipoVehiculo, string tipo, string cilindrada, int potencia, double costo) : Componente(id, costo, "MOTOR"){
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
		Llantas(int id, string tipo, string tamano, string perfil, double costo) : Componente(id, costo, "LLANTAS"){
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
		Carroceria(int id, string tipo, string color, int numeroPuertas, double costo) : Componente(id, costo, "CARROCERIA"){
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
		Transmision(int id, string tipo, int velocidades, double costo) : Componente(id, costo, "TRANSMISION"){
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
		virtual ~Vehiculo(){}
		Vehiculo(int id, string marca, string modelo){
			this->id = id;
			this->marca = marca;
			this->modelo = modelo;
			this->motor = nullptr;
			this->llantas = nullptr;
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
	private:
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
		virtual ~Deportivo(){}

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
		virtual ~Motocicleta(){}
		double calcularPuntuacionRendimiento() const override {
            if (!getMotor() || !chasis || !manillar){
                return 0.0;
            }
    
            double potenciaHP = getMotor()->getPotencia();
            double pesoChasis = chasis->getPeso();  // ✅ Usar atributo directo
            string tipoManillar = manillar->getTipo();  // ✅ Usar atributo directo

            double bonusManillar = 0.0;
            double factorX = (rand() % 11) - 5;  // -5 a +5

            if (tipoManillar == "Deportivo") {
            bonusManillar = 40;
            } 
            else {
            bonusManillar = 15;
        }

            double puntuacion_base = (potenciaHP / pesoChasis) * 50 + bonusManillar;
            double puntuacion_final = puntuacion_base + (puntuacion_base * factorX / 100.0);
    
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

void cargarComponentesDesdeArchivo(const string& nombreArchivo, vector<Componente*>& componentes) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string token;
        vector<string> tokens;
        
        while (getline(ss, token, '"')) {
            if (!token.empty() && token != "\n") {
                tokens.push_back(token);
            }
        }
        
        if (tokens.size() < 2) {
            cout << "Línea ignorada (formato inválido): " << linea << endl;
            continue;
        }
        
        int id = stoi(tokens[0]);
        string tipoComponente = tokens[1];
        
        if (tipoComponente == "MOTOR") {
            if (tokens.size() >= 7) {
                string tipoVehiculo = tokens[2];
                string tipoMotor = tokens[3];
                string cilindrada = tokens[4];
                int potencia = stoi(tokens[5]);
                double costo = stod(tokens[6]);
                
                componentes.push_back(new Motor(id, tipoVehiculo, tipoMotor, cilindrada, potencia, costo));
            }
        }
        else if (tipoComponente == "LLANTAS") {
            if (tokens.size() >= 6) {
                string tipoLlantas = tokens[2];
                string tamaño = tokens[3];
                string perfil = tokens[4];
                double costo = stod(tokens[5]);
                
                componentes.push_back(new Llantas(id, tipoLlantas, tamaño, perfil, costo));
            }
        }
        else if (tipoComponente == "CARROCERIA") {
            if (tokens.size() >= 6) {
                string tipoCarroceria = tokens[2];
                string color = tokens[3];
                int puertas = stoi(tokens[4]);
                double costo = stod(tokens[5]);
                
                componentes.push_back(new Carroceria(id, tipoCarroceria, color, puertas, costo));
            }
        }
        else if (tipoComponente == "TRANSMISION") {
            if (tokens.size() >= 5) {
                string tipoTransmision = tokens[2];
                int velocidades = stoi(tokens[3]);
                double costo = stod(tokens[4]);
                
                componentes.push_back(new Transmision(id, tipoTransmision, velocidades, costo));
            }
        }
        else if (tipoComponente == "ALERON") {
            if (tokens.size() >= 6) {
                string material = tokens[2];
                string tamaño = tokens[3];
                double downforce = stod(tokens[4]);
                double costo = stod(tokens[5]);
                
                componentes.push_back(new Aleron(id, material, tamaño, downforce, costo));
            }
        }
        else if (tipoComponente == "CHASIS") {
            if (tokens.size() >= 5) {
                string material = tokens[2];
                double peso = stod(tokens[3]);
                double costo = stod(tokens[4]);
                
                componentes.push_back(new Chasis(id, material, peso, costo));
            }
        }
        else if (tipoComponente == "MANILLAR") {
            if (tokens.size() >= 5) {
                string tipoManillar = tokens[2];
                string material = tokens[3];
                double costo = stod(tokens[4]);
                
                componentes.push_back(new Manillar(id, material, tipoManillar, costo));
            }
        }
        else {
            cout << "Tipo de componente desconocido: " << tipoComponente << endl;
        }
    }
    
    archivo.close();
    cout << "Componentes cargados correctamente" << endl;
}

vector<Vehiculo*> inventario;
int nextId = 1;

void mostrarMenu() {
    cout << "\n*** Sistema de Inventario de Vehículos v4.0 ***" << endl;
    cout << "1. Agregar Vehículo" << endl;
    cout << "2. Listar Vehículos" << endl;
    cout << "3. Buscar por Marca" << endl;
    cout << "4. Eliminar Vehículo" << endl;
    cout << "5. Realizar Carrera" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void listarVehiculos() {
    if (inventario.empty()) {
        cout << "No hay vehículos en el inventario." << endl;
        return;
    }
    
    cout << "\n-- Listado de Vehículos en Inventario --" << endl;
    for (Vehiculo* v : inventario) {
        cout << "[ID: " << v->getID() << "] ";
        
        // Determinar tipo
        if (dynamic_cast<Deportivo*>(v)) {
            cout << "Deportivo - ";
        } else if (dynamic_cast<Sedan*>(v)) {
            cout << "Sedan - ";
        } else if (dynamic_cast<Camioneta*>(v)) {
            cout << "Camioneta - ";
        } else if (dynamic_cast<Motocicleta*>(v)) {
            cout << "Motocicleta - ";
        }
        
        cout << v->getMarca() << " " << v->getModelo() << endl;
        
        // Mostrar componentes principales
        if (v->getMotor()) {
            cout << "  - Motor: " << v->getMotor()->getPotencia() << "hp" << endl;
        }
        if (v->getLlantas()) {
            cout << "  - Llantas: " << v->getLlantas()->getTamano() << endl;
        }
        
        // Componentes específicos
        if (Deportivo* d = dynamic_cast<Deportivo*>(v)) {
            if (d->getAleron()) {
                cout << "  - Alerón: " << d->getAleron()->getMaterial() << endl;
            }
        } else if (Motocicleta* m = dynamic_cast<Motocicleta*>(v)) {
            if (m->getChasis()) {
                cout << "  - Chasis: " << m->getChasis()->getMaterial() << endl;
            }
            if (m->getManillar()) {
                cout << "  - Manillar: " << m->getManillar()->getTipo() << endl;
            }
        }
        cout << endl;
    }
}

// Función para buscar componente por ID y tipo
Componente* buscarComponentePorId(const vector<Componente*>& componentes, int id, const string& tipo) {
    for (Componente* comp : componentes) {
        if (comp->getID() == id && comp->getTipo() == tipo) {
            return comp;
        }
    }
    return nullptr;
}

void mostrarComponentesPorTipo(const vector<Componente*>& componentes, const string& tipo, const string& filtroVehiculo = "") {
    bool encontrados = false;
    
    for (Componente* comp : componentes) {
        if (comp->getTipo() == tipo) {
            // Filtrar por tipo de vehículo si se especifica
            if (filtroVehiculo != "") {
                if (Motor* motor = dynamic_cast<Motor*>(comp)) {
                    if (motor->getTipoVehiculo() != filtroVehiculo) {
                        continue; // Saltar si no coincide
                    }
                }
            }
            
            encontrados = true;
            cout << "[ID: " << comp->getID() << "] ";
            
            // Mostrar información específica según el tipo
            if (Motor* motor = dynamic_cast<Motor*>(comp)) {
                cout << "Motor " << motor->getTipoVehiculo() << " - " << motor->getCilindrada() 
                     << ", " << motor->getPotencia() << "hp, Costo: " << comp->getCosto();
            }
            else if (Llantas* llantas = dynamic_cast<Llantas*>(comp)) {
                cout << "Llantas " << llantas->getTamano() << " - " << llantas->getPerfil() 
                     << ", Costo: " << comp->getCosto();
            }
            else if (Carroceria* carroceria = dynamic_cast<Carroceria*>(comp)) {
                cout << "Carroceria " << carroceria->getColor() << " - " << carroceria->getNumeroPuertas() 
                     << " puertas, Costo: " << comp->getCosto();
            }
            else if (Transmision* transmision = dynamic_cast<Transmision*>(comp)) {
                cout << "Transmisión " << transmision->getVelocidades() << " velocidades, Costo: " << comp->getCosto();
            }
            else if (Aleron* aleron = dynamic_cast<Aleron*>(comp)) {
                cout << "Alerón " << aleron->getMaterial() << " - " << aleron->getTamano() 
                     << ", " << aleron->getDownforce() << "kg downforce, Costo: " << comp->getCosto();
            }
            else if (Chasis* chasis = dynamic_cast<Chasis*>(comp)) {
                cout << "Chasis " << chasis->getMaterial() << " - " << chasis->getPeso() 
                     << "kg, Costo: " << comp->getCosto();
            }
            else if (Manillar* manillar = dynamic_cast<Manillar*>(comp)) {
                cout << "Manillar " << manillar->getTipo() << " - " << manillar->getMaterial() 
                     << ", Costo: " << comp->getCosto();
            }
            else {
                cout << comp->getTipo() << ", Costo: " << comp->getCosto();
            }
            cout << endl;
        }
    }
    
    if (!encontrados) {
        cout << "No hay componentes del tipo '" << tipo << "'";
        if (filtroVehiculo != "") {
            cout << " para " << filtroVehiculo;
        }
        cout << " cargados." << endl;
    }
}

void agregarVehiculo(vector<Componente*>& componentes) {
    cout << "\n-- Agregar Nuevo Vehículo --" << endl;
    
    // 1. Seleccionar tipo de vehículo
    cout << "Seleccione el tipo de vehículo:" << endl;
    cout << "1. Deportivo" << endl;
    cout << "2. Sedan" << endl;
    cout << "3. Camioneta" << endl;
    cout << "4. Motocicleta" << endl;
    cout << "Opción: ";
    
    int tipoVehiculo;
    cin >> tipoVehiculo;
    cin.ignore();
    
    if (tipoVehiculo < 1 || tipoVehiculo > 4) {
        cout << "Tipo de vehículo inválido." << endl;
        return;
    }
    
    // 2. Pedir marca y modelo
    string marca, modelo;
    cout << "Ingrese la marca del vehículo: ";
    getline(cin, marca);
    cout << "Ingrese el modelo del vehículo: ";
    getline(cin, modelo);
    
    // 3. Crear el vehículo según el tipo
    Vehiculo* nuevoVehiculo = nullptr;
    
    switch (tipoVehiculo) {
        case 1: // Deportivo
            nuevoVehiculo = new Deportivo(nextId, marca, modelo);
            break;
        case 2: // Sedan
            nuevoVehiculo = new Sedan(nextId, marca, modelo);
            break;
        case 3: // Camioneta
            nuevoVehiculo = new Camioneta(nextId, marca, modelo);
            break;
        case 4: // Motocicleta
            nuevoVehiculo = new Motocicleta(nextId, marca, modelo);
            break;
    }
    
    // 4. Asignar componentes básicos (Motor y Llantas para todos)
    string filtroMotor = "";
    if (tipoVehiculo == 1 || tipoVehiculo == 2 || tipoVehiculo == 3) {
        filtroMotor = "Auto";
    } else if (tipoVehiculo == 4) {
        filtroMotor = "Moto";
    }

    cout << "\n-- Selección de Motor (" << filtroMotor << ") --" << endl;
    mostrarComponentesPorTipo(componentes, "MOTOR", filtroMotor);
    cout << "Seleccione ID del motor: ";
    int idMotor;
    cin >> idMotor;

    Motor* motorSeleccionado = dynamic_cast<Motor*>(buscarComponentePorId(componentes, idMotor, "MOTOR"));
    if (motorSeleccionado) {
        // Verificar compatibilidad del motor con el vehículo
        if (motorSeleccionado->getTipoVehiculo() != filtroMotor) {
            cout << "Error: El motor seleccionado es para " << motorSeleccionado->getTipoVehiculo() 
                 << ", pero el vehículo es " << filtroMotor << "." << endl;
            delete nuevoVehiculo;
            return;
        }
        nuevoVehiculo->setMotor(motorSeleccionado);
    } else {
        cout << "Error: Motor con ID " << idMotor << " no encontrado." << endl;
        delete nuevoVehiculo;
        return;
    }

    // 5. Seleccionar llantas
    cout << "\n-- Selección de Llantas --" << endl;
    mostrarComponentesPorTipo(componentes, "LLANTAS");
    cout << "Seleccione ID de las llantas: ";
    int idLlantas;
    cin >> idLlantas;

    Llantas* llantasSeleccionadas = dynamic_cast<Llantas*>(buscarComponentePorId(componentes, idLlantas, "LLANTAS"));
    if (llantasSeleccionadas) {
        nuevoVehiculo->setLlantas(llantasSeleccionadas);
    } else {
        cout << "Error: Llantas con ID " << idLlantas << " no encontradas." << endl;
        delete nuevoVehiculo;
        return;
    }

    // 6. Asignar componentes específicos según el tipo de vehículo
    if (tipoVehiculo == 1 || tipoVehiculo == 2) { // Deportivo o Sedan (Automovil)
        Automovil* autoPtr = dynamic_cast<Automovil*>(nuevoVehiculo);
        
        // Carrocería
        cout << "\n-- Selección de Carrocería --" << endl;
        mostrarComponentesPorTipo(componentes, "CARROCERIA");
        cout << "Seleccione ID de la carrocería: ";
        int idCarroceria;
        cin >> idCarroceria;
        
        Carroceria* carroceriaSeleccionada = dynamic_cast<Carroceria*>(buscarComponentePorId(componentes, idCarroceria, "CARROCERIA"));
        if (carroceriaSeleccionada) {
            autoPtr->setCarroceria(carroceriaSeleccionada);
        } else {
            cout << "Error: Carrocería con ID " << idCarroceria << " no encontrada." << endl;
            delete nuevoVehiculo;
            return;
        }
        
        // Transmisión
        cout << "\n-- Selección de Transmisión --" << endl;
        mostrarComponentesPorTipo(componentes, "TRANSMISION");
        cout << "Seleccione ID de la transmisión: ";
        int idTransmision;
        cin >> idTransmision;
        
        Transmision* transmisionSeleccionada = dynamic_cast<Transmision*>(buscarComponentePorId(componentes, idTransmision, "TRANSMISION"));
        if (transmisionSeleccionada) {
            autoPtr->setTransmision(transmisionSeleccionada);
        } else {
            cout << "Error: Transmisión con ID " << idTransmision << " no encontrada." << endl;
            delete nuevoVehiculo;
            return;
        }
        
        // Alerón (solo para Deportivo)
        if (tipoVehiculo == 1) {
            Deportivo* deportivoPtr = dynamic_cast<Deportivo*>(nuevoVehiculo);
            cout << "\n-- Selección de Alerón --" << endl;
            mostrarComponentesPorTipo(componentes, "ALERON");
            cout << "Seleccione ID del alerón: ";
            int idAleron;
            cin >> idAleron;
            
            Aleron* aleronSeleccionado = dynamic_cast<Aleron*>(buscarComponentePorId(componentes, idAleron, "ALERON"));
            if (aleronSeleccionado) {
                deportivoPtr->setAleron(aleronSeleccionado);
            } else {
                cout << "Error: Alerón con ID " << idAleron << " no encontrado." << endl;
                delete nuevoVehiculo;
                return;
            }
        }
    }
    else if (tipoVehiculo == 3) { // Camioneta
        Camioneta* camionetaPtr = dynamic_cast<Camioneta*>(nuevoVehiculo);
        
        // Carrocería
        cout << "\n-- Selección de Carrocería --" << endl;
        mostrarComponentesPorTipo(componentes, "CARROCERIA");
        cout << "Seleccione ID de la carrocería: ";
        int idCarroceria;
        cin >> idCarroceria;
        
        Carroceria* carroceriaSeleccionada = dynamic_cast<Carroceria*>(buscarComponentePorId(componentes, idCarroceria, "CARROCERIA"));
        if (carroceriaSeleccionada) {
            camionetaPtr->setCarroceria(carroceriaSeleccionada);
        } else {
            cout << "Error: Carrocería con ID " << idCarroceria << " no encontrada." << endl;
            delete nuevoVehiculo;
            return;
        }
        
        // Transmisión
        cout << "\n-- Selección de Transmisión --" << endl;
        mostrarComponentesPorTipo(componentes, "TRANSMISION");
        cout << "Seleccione ID de la transmisión: ";
        int idTransmision;
        cin >> idTransmision;
        
        Transmision* transmisionSeleccionada = dynamic_cast<Transmision*>(buscarComponentePorId(componentes, idTransmision, "TRANSMISION"));
        if (transmisionSeleccionada) {
            camionetaPtr->setTransmision(transmisionSeleccionada);
        } else {
            cout << "Error: Transmisión con ID " << idTransmision << " no encontrada." << endl;
            delete nuevoVehiculo;
            return;
        }
    }
    else if (tipoVehiculo == 4) { // Motocicleta
        Motocicleta* motoPtr = dynamic_cast<Motocicleta*>(nuevoVehiculo);
        
        // Chasis
        cout << "\n-- Selección de Chasis --" << endl;
        mostrarComponentesPorTipo(componentes, "CHASIS");
        cout << "Seleccione ID del chasis: ";
        int idChasis;
        cin >> idChasis;
        
        Chasis* chasisSeleccionado = dynamic_cast<Chasis*>(buscarComponentePorId(componentes, idChasis, "CHASIS"));
        if (chasisSeleccionado) {
            motoPtr->setChasis(chasisSeleccionado);
        } else {
            cout << "Error: Chasis con ID " << idChasis << " no encontrado." << endl;
            delete nuevoVehiculo;
            return;
        }
        
        // Manillar
        cout << "\n-- Selección de Manillar --" << endl;
        mostrarComponentesPorTipo(componentes, "MANILLAR");
        cout << "Seleccione ID del manillar: ";
        int idManillar;
        cin >> idManillar;
        
        Manillar* manillarSeleccionado = dynamic_cast<Manillar*>(buscarComponentePorId(componentes, idManillar, "MANILLAR"));
        if (manillarSeleccionado) {
            motoPtr->setManillar(manillarSeleccionado);
        } else {
            cout << "Error: Manillar con ID " << idManillar << " no encontrado." << endl;
            delete nuevoVehiculo;
            return;
        }
    }
    
    // 7. Agregar al inventario
    inventario.push_back(nuevoVehiculo);
    cout << "Vehículo '" << marca << " " << modelo << "' agregado con éxito con ID: " << nextId << endl;
    nextId++;
}

void buscarPorMarca() {
    if (inventario.empty()) {
        cout << "No hay vehículos en el inventario." << endl;
        return;
    }
    
    cout << "\n-- Buscar Vehículo por Marca --" << endl;
    cout << "Ingrese la marca a buscar: ";
    string marcaBuscar;
    getline(cin, marcaBuscar);
    
    bool encontrados = false;
    cout << "\nResultados para la marca '" << marcaBuscar << "':" << endl;
    
    for (Vehiculo* v : inventario) {
        if (v->getMarca() == marcaBuscar) {
            encontrados = true;
            cout << "[ID: " << v->getID() << "] ";
            
            // Determinar el tipo de vehículo
            if (dynamic_cast<Deportivo*>(v)) {
                cout << "Deportivo - ";
            } else if (dynamic_cast<Sedan*>(v)) {
                cout << "Sedan - ";
            } else if (dynamic_cast<Camioneta*>(v)) {
                cout << "Camioneta - ";
            } else if (dynamic_cast<Motocicleta*>(v)) {
                cout << "Motocicleta - ";
            }
            
            cout << v->getMarca() << " " << v->getModelo() << endl;
        }
    }
    
    if (!encontrados) {
        cout << "No se encontraron vehículos de la marca '" << marcaBuscar << "'." << endl;
    }
}

void eliminarVehiculo() {
    if (inventario.empty()) {
        cout << "No hay vehículos en el inventario." << endl;
        return;
    }
    
    cout << "\n-- Eliminar un Vehículo --" << endl;
    listarVehiculos();
    
    cout << "Ingrese el ID del vehículo a eliminar: ";
    int idEliminar;
    cin >> idEliminar;
    
    // Buscar el vehículo
    auto it = inventario.begin();
    while (it != inventario.end()) {
        if ((*it)->getID() == idEliminar) {
            string marca = (*it)->getMarca();
            string modelo = (*it)->getModelo();
            
            // Determinar tipo para el mensaje
            string tipo;
            if (dynamic_cast<Deportivo*>(*it)) tipo = "Deportivo";
            else if (dynamic_cast<Sedan*>(*it)) tipo = "Sedan";
            else if (dynamic_cast<Camioneta*>(*it)) tipo = "Camioneta";
            else if (dynamic_cast<Motocicleta*>(*it)) tipo = "Motocicleta";
            
            delete *it;
            it = inventario.erase(it);
            
            cout << "Vehículo '" << marca << " " << modelo << "' (" << tipo 
                 << ") con ID " << idEliminar << " ha sido eliminado." << endl;
            return;
        } else {
            ++it;
        }
    }
    
    cout << "Error: No se encontró un vehículo con ID " << idEliminar << "." << endl;
}

void realizarCarrera() {
    if (inventario.empty()) {
        cout << "No hay vehículos en el inventario." << endl;
        return;
    }
    
    cout << "\n-- Simulador de Carreras --" << endl;
    listarVehiculos();
    
    // Seleccionar primer competidor
    cout << "Ingrese el ID del primer competidor: ";
    int id1;
    cin >> id1;
    
    Vehiculo* competidor1 = nullptr;
    for (Vehiculo* v : inventario) {
        if (v->getID() == id1) {
            competidor1 = v;
            break;
        }
    }
    
    if (!competidor1) {
        cout << "Error: No se encontró un vehículo con ID " << id1 << "." << endl;
        return;
    }
    
    // Seleccionar segundo competidor
    cout << "Ingrese el ID del segundo competidor: ";
    int id2;
    cin >> id2;
    
    Vehiculo* competidor2 = nullptr;
    for (Vehiculo* v : inventario) {
        if (v->getID() == id2) {
            competidor2 = v;
            break;
        }
    }
    
    if (!competidor2) {
        cout << "Error: No se encontró un vehículo con ID " << id2 << "." << endl;
        return;
    }
    
    // Verificar que ambos sean competidores
    ICompetidor* comp1 = dynamic_cast<ICompetidor*>(competidor1);
    ICompetidor* comp2 = dynamic_cast<ICompetidor*>(competidor2);
    
    if (!comp1) {
        cout << "Error: El vehículo con ID " << id1 << " (" << competidor1->getMarca() 
             << " " << competidor1->getModelo() << ") no es un vehículo de carreras." << endl;
        return;
    }
    
    if (!comp2) {
        cout << "Error: El vehículo con ID " << id2 << " (" << competidor2->getMarca() 
             << " " << competidor2->getModelo() << ") no es un vehículo de carreras." << endl;
        return;
    }
    
    cout << "\nAmbos vehículos son competidores! Iniciando carrera..." << endl;
    cout << "Calculando rendimiento..." << endl;
    
    // Calcular puntuaciones
    double puntuacion1 = comp1->calcularPuntuacionRendimiento();
    double puntuacion2 = comp2->calcularPuntuacionRendimiento();
    
    cout << "> " << competidor1->getMarca() << " " << competidor1->getModelo() 
         << ": Puntuación de " << puntuacion1 << endl;
    cout << "> " << competidor2->getMarca() << " " << competidor2->getModelo() 
         << ": Puntuación de " << puntuacion2 << endl;
    
    // Determinar ganador
    cout << "\n";
    if (puntuacion1 > puntuacion2) {
        cout << "*** !El Vehículo " << id1 << " (" << competidor1->getMarca() 
             << " " << competidor1->getModelo() << ") ha ganado la carrera! ***" << endl;
    } else if (puntuacion2 > puntuacion1) {
        cout << "*** !El Vehículo " << id2 << " (" << competidor2->getMarca() 
             << " " << competidor2->getModelo() << ") ha ganado la carrera! ***" << endl;
    } else {
        cout << "*** !Empate! Ambos vehículos tienen la misma puntuación. ***" << endl;
    }
}

int main() {
    srand(time(0));
    
    vector<Componente*> componentes;
    cargarComponentesDesdeArchivo("componentes.txt", componentes);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();
        
        switch (opcion) {
            case 1:
                agregarVehiculo(componentes);
                break;
            case 2:
                listarVehiculos();
                break;
            case 3:
                buscarPorMarca();
                break;
            case 4:
                eliminarVehiculo();
                break;
            case 5:
                realizarCarrera();
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    for (Componente* comp : componentes) {
        delete comp;
    }
    componentes.clear();
    
    for (Vehiculo* v : inventario) {
        delete v;
    }
    inventario.clear();
    
    return 0;
}