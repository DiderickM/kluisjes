#include <Keypad.h>

String password[] ={"12021", "12022", "12023", "12024", "12025", "12026"};
String input;

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9, 8, 7, 6}; //Rows 0 to 3
byte colPins[numCols] = {5, 4, 3, 2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup(){
  Serial.begin(9600);
  input = "";

  //pinmodes
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);        // Welke pins gebruiken we precies? Pas dit ook aan in de loop
//  pinMode(13, OUTPUT);
//  pinMode(14, OUTPUT);
//  pinMode(15, OUTPUT);
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop(){
  char keypressed = keypad.getKey();
  if (keypressed != NO_KEY)
  {
    String test = (String) keypressed;
    if (test == "#") {
      if (input == password[0]) {
        Serial.println("Access to locker 1 granted!");
        digitalWrite(10, HIGH);
      } else if (input == password[1]) {
        Serial.println("Access to locker 2 granted!");
        digitalWrite(11, HIGH);
      } else if (input == password[2]) {
        Serial.println("Access to locker 3 granted!");
        digitalWrite(12, HIGH);
      } else if (input == password[3]) {
        Serial.println("Access to locker 4 granted!");
//        digitalWrite(13, HIGH);
      } else if (input == password[4]) {
        Serial.println("Access to locker 5 granted!");
//        digitalWrite(14, HIGH);
      } else if (input == password[5]) {
        Serial.println("Access to locker 6 granted!");
//        digitalWrite(15, HIGH);
      } else {
        input = "";
      }
    } else {
      input += keypressed;
    }
    Serial.println(input);

  }
}
