#include <iostream>
#include <sstream>
#include <vector> 

int moneda[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };

std::vector<int> calcularVuelto(int precio, int pago) {
	int indice = 0;
	int restante = pago - precio;
	std::vector<int> vuelto;
	if (restante == 0) {
		vuelto.push_back(0);
		return vuelto;
	}
	while (restante != 0) {
		if (restante - moneda[indice] >= 0) {
			vuelto.push_back(moneda[indice]);
			restante = restante - moneda[indice];
		}
		else {
			indice++;
		}
	}
	return vuelto;
}

int main() {
	std::cout << "Ingrese pago, precio en el siguiente formato (pago, precio) o presione CTRL-C: ";
	std::string caso;
	while (std::getline(std::cin, caso)) {
		std::stringstream ss(caso);
		std::vector<int> vec;
		std::vector<int> vuelto;
		int i;
		ss >> i;
		vec.push_back(i);
		ss.ignore();
		ss.ignore();
		ss >> i;
		vec.push_back(i);
		vuelto = calcularVuelto(vec[1], vec[0]);
		std::cout << "[";
		for (int l = 0; l < vuelto.size() - 1; l++) {
			std::cout << " " << vuelto[l] << ",";
		}
		std::cout << " " << vuelto[vuelto.size() - 1] << " ]" << std::endl;
		vuelto.clear();
		std::cout << "Ingrese pago, precio en el siguiente formato (pago, precio) o presione CTRL-C: ";
	}
}