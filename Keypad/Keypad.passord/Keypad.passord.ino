#include<Keypad.h>
#include<Password.h>

int led1 = 12;
int led2 = 13;
String newPasswordString;
char newPassword[6];

Password password = Password("1234");

byte maxPasswordLength = 6;
byte currentPasswordLength = 0;
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
 
//Define the keymap
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //connect to row pinouts
byte colPins[COLS] = {5,4,3,2}; //connect to column pinouts

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 char customKey = keypad.getKey();
 if(customKey != NO_KEY){
  delay(60);
  switch(customKey){
    case 'A' : break;
    case 'B' : break;
    case 'C' : break;
    case 'D' : break;
    case '*' : checkPassword(); break;
    case '#' : resetPassword(); break;
    default: processNumberKey(customKey);
  }
 }
}

void processNumberKey(char key){
  Serial.print(key);
  currentPasswordLength++;
  password.append(key);
  if(currentPasswordLength == maxPasswordLength){
    checkPassword();
  }
}

void checkPassword(){
  if(password.evaluate()){
    Serial.println(" OK");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    }
  else{
    Serial.println(" Wrong Password");
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    }
  resetPassword();
}

void resetPassword(){
  password.reset();
  currentPasswordLength = 0;
  Serial.println();
}

