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
const int servoPin = 10;

//Mot de passe
const String mdp = "419A";
int k = 0; compte le nombre de caractère just d'affilé

void setup()
{
  Serial.begin(9600);
  myServo.attach(10);
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
    Serial.println(key);
  
  }
  
}


