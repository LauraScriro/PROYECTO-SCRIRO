
#include <Servo.h> //Libreria para el Servomotor 

Servo servo1; //Se crea un objeto llamado servo1 en la clase Servo, puedes controlar hasta un maximo de 12
const int flexpin = 0; //Declara que el pin del flex va en la entrada analoga A0 y se llama flexpin
Servo servo2; //Se crea un objeto llamado servo2 en la clase Servo, puedes controlar hasta un maximo de 12
const int flexpin1 = 1; //Declara que el pin del flex va en la entrada analoga A1 y se llama flexpin1
Servo servo3; //Se crea un objeto llamado servo3 en la clase Servo, puedes controlar hasta un maximo de 12
const int flexpin2 = 2; //Declara que el pin del flex va en la entrada analoga A2 y se llama flexpin2

void setup() 
  { 
    Serial.begin(9600); //Inicia Serial monitor para ver los valores del sensor
    servo1.attach(9); //Se permite el control de un servo en el pin 9
    servo2.attach(10); //Se permite el control de un servo en el pin 10
    servo3.attach(11); //Se permite el control de un servo en el pin 11
  } 


void loop() 
  { 
    int flexposition;    // Valor de entrada dado por el Flex sensor0
    int servoposition1;   // Valor de salida dado al servo1
    flexposition = analogRead(flexpin); //Lee la posicion de el flex sensor0 en el rango analogo (0 a 1023)
    int flexposition1;    // Valor de entrada dado por el Flex sensor1
    int servoposition2;   // Valor de salida dado al servo2
    flexposition1 = analogRead(flexpin1); //Lee la posicion de el flex sensor1 en el rango analogo (0 a 1023)
    int flexposition2;    // Valor de entrada dado por el Flex sensor2
    int servoposition3;   // Valor de salida dado al servo3
    flexposition2 = analogRead(flexpin2); //Lee la posicion de el flex sensor2 en el rango analogo (0 a 1023)

    //Es en esta parte donde se le indica esperar y efectuar ciertos valores, maximos y minimos:
  
    //map(valor, fromLow, fromHigh, toLow, toHigh)
    servoposition1 = map(flexposition, 710, 990, 0, 180);
    //constrain1(x, a, b)
    servoposition1 = constrain(servoposition1, 0, 360);
    //map(valor, fromLow, fromHigh, toLow, toHigh)
    servoposition2 = map(flexposition1, 710, 990, 0, 180);
    //constrain2(x, a, b)
    servoposition2 = constrain(servoposition2, 0, 360);
    //map(valor, fromLow, fromHigh, toLow, toHigh)
    servoposition3 = map(flexposition2, 710, 990, 0, 180);
    //constrain3(x, a, b)
    servoposition3 = constrain(servoposition3, 0, 360);

    servo1.write(servoposition1); //Aqui es donde se indica que se mueva a la posicion indicada
    servo2.write(servoposition2); //Aqui es donde se indica que se mueva a la posicion indicada
    servo3.write(servoposition3); //Aqui es donde se indica que se mueva a la posicion indicada

    //Con esta parte, se imprime en el monitor los valores del sensor y el servo
    Serial.print("sensor0: ");
    Serial.print(flexposition);
    Serial.print("  servo1: ");
    Serial.println(servoposition1);
    Serial.print("sensor1: ");
    Serial.print(flexposition1);
    Serial.print("  servo2: ");
    Serial.println(servoposition2);
    Serial.print("sensor2: ");
    Serial.print(flexposition2);
    Serial.print("  servo3: ");
    Serial.println(servoposition3);

    /* Despues de subir el programa a la tarjeta, puedes abrir el serial monitor para 
       ver los valores del sensor, dobla el flex y veras los valores maximos y minimos
       si remplazas el 600 y 900 en map() podras obtener maximos resultados
    */    
    delay(20); //Espera 20ms entre las actualizaciones del servo
  } 
