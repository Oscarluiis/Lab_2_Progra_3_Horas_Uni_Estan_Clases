
//Clase tipificada

class Tiempo{

//Definicion o prototipo de una funcion
//Constructor ... para poder inicializar los atributos de una clase

public:
    Tiempo();
    void imprimir_formato_universal();
    void imprimir_formato_estandar();
    void establecer_hora(int, int, int);

private:
    int h, m, s;


};
Tiempo::Tiempo() {

    h = m = s = 0;
}
//Empezar a definir las funciones que estan como prototipo de la clase tiempo

void Tiempo::establecer_hora(int hora, int minuto, int segundo) {

        h = (hora >=0 && hora <= 24) ? hora : 0;  //Operador ternario
        m = (minuto >= 0 && minuto <=60) ? minuto : 0;
        s = (segundo >= 0 && segundo <= 60) ? segundo : 0;

}
#include <iomanip>
#include <iostream>
using namespace std;
//Estas dos clases que estamos usando, nos da la funcion para poder rellenar la cantidad de 0 que necesitamos
using  std::setfill;
using std::setw;
using std::endl;



void Tiempo::imprimir_formato_estandar() {
    cout << setfill('0') << setw(2) << ((h == 0 || h == 12) ? 12: (h%12))<< ":"
         <<  setfill('0') << setw(2) << m << ":"
         <<  setfill('0') << setw (2) << s << ((h < 12) ? "AM" : "PM") << endl;

}

void Tiempo::imprimir_formato_universal() {
    cout << h << ":"<< ":" << m << ":" << s << endl;
}

int main(){

    Tiempo t;
    t.establecer_hora(40,10,32);

    cout<<"La hora estandar es :";
    t.imprimir_formato_estandar();

    cout<<"La hora universal es :";
    t.imprimir_formato_universal();


//Establecer hora incorrecta
    t.establecer_hora(99,99,99);
    cout <<"\nValor de t, despues de establecer hora incorrecta: "<< endl;
    t.imprimir_formato_universal();
    t.imprimir_formato_estandar();


    return 0;
}