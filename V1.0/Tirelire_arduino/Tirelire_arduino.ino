#include <Keypad.h>
#include <Servo.h>

//KEYPAD
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[rows] = {9,8,7,6};
byte colsPins[cols] = {5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colsPins, rows, cols);

//SERVO
Servo myServo;
const byte servoPin = 10;

//Mot de passe
const String mdp = "419A";
String buffer[4] = "FFFF";
byte k = 0; //variable permettant le remplissage initial du 

void setup()
{
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop()
{
  char key = keypad.getKey();
  if (buffer[3] == "F") //Tant que le buffer n'est pas remplie, on remplie le buffer
  {
    buffer[k] = key;
  }
  else
  {
    for (byte i = 0; i < mdp.length(); i++)
  }
  if (key != NO_KEY)
    Serial.println(key);
  
  
  
  
  
}


