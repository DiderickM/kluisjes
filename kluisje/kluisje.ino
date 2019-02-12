#include <Keypad.h>

String password = "1111";
String input;

const byte numRows = 4; //number of rows on the keypad
const byte numCols = 4; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  input = "";
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
char keypressed = keypad.getKey();
if (keypressed != NO_KEY)
{
String test = (String) keypressed;
if(test == "#"){
  if(input == password){
    Serial.println("Access Granted!");
    digitalWrite(11, HIGH);
    } else {
      Serial.println("Access Denied");
      digitalWrite(11, LOW);
      }
      input = "";
} else {
  input += keypressed;
  }
  Serial.println(input);

}
}
