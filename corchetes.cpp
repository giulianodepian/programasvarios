#include <iostream>
#include <sstream> 


int main() {
	std::string caso;
	std::cout << "Ingrese caso de prueba o presione CTRL-C para cerrar: ";
	while (std::getline(std::cin, caso)) {
		int cantCorchete1{ 0 };
		int cantCorchete2{ 0 };
		for (int i = 0; i < caso.size(); ++i) {
			if (caso[i] == '[') {
				cantCorchete1++;
			}
			// Controla que no sea el primer caracter ']' y que le corresponda un '['
			else if (caso[i] == ']' and i != 0 and cantCorchete1 > cantCorchete2) {
				cantCorchete2++;
			}
			// En caso de no cumplir la condicion anterior, el string queda insalvable el balanceo y se fuerza que de false
			else {
				cantCorchete1++;
				break;
			}
		}
		std::cout << std::boolalpha << (cantCorchete1 == cantCorchete2) << std::endl;
		std::cout << "Ingrese caso de prueba o presione CTRL-C para cerrar: ";
	}
	std::getline(std::cin, caso);
}