#include <Keypad.h>
#include <Servo.h>

/*-------------NOTE----------------
 * rajouter option de delais de l'ouverture en fonction de la lettre entrée (en dernière entrée)
 * 
 * 
 * 
 * 
 * 
 */

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
const byte angleInit = 0; //A definir. Angle de départ du servo moteur
const byte angleOuverture = 80; //Angle d'ouverture de la porte
//Mot de passe
const String mdp = "419";
String buffer[4] = "FFFF";
boolean doorOpen = false; //true = porte ouverte, false = porte fermée
//byte k = 0; //variable permettant le remplissage initial du 

void setup()
{
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(angleInit);
}

void loop()
{
  char key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    Serial.println(key);
    if (buffer[3] == "F") //Tant que le buffer n'est pas remplie, on remplie le buffer
    {
      buffer[k] = key;
    }
    else //Si le buffer est plein, on décale toute les lettres et la nouvelle entrée est mise en dernière position du buffer
    {
      for (byte i = 0; i < mdp.length()-1; i++)
        buffer[i] = buffer[i+1];
      buffer[mdp.lenght()] = key;
    }

    if (buffer.subString(0,2) == mdp && doorOpen == true)// ICI
    {
      myServo.write(angleInit + angleOuverture)
      doorOpen = true;
      if (buffer[3] == "A")
      {
        delay(15000);
        myServo.write(angleInit)
      }

    if (doorOpen == true && key == "D")
    {
      myServo.write(angleInit)
      doorOpen = false;
  }
}

checkCode(String buffer)
{
  if (
}




