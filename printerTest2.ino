/*
 * This code is to use in Arduino UNO for interfacing the Thermal Printer.
 */


//Pin declaration
#include <SPI.h>
#include <SD.h>

File myFile;
int led = 13;
int SW = 2;

// Programe flow related operations

int is_switch_press = 0; // For detecting the switch press status
int debounce_delay = 500; //Debounce delay

void setup() {
 pinMode(led, OUTPUT);
 pinMode(SW, INPUT);
 Serial.begin(9600);

  while (!Serial) {
    ;
  }
  //Serial.print("Initializing...");
  if (!SD.begin(10)) {
    Serial.println("failed!");
    while (1);
  }
  //Serial.println("done.");
}

void loop() {
  char option;

  is_switch_press = digitalRead(SW); // Reading the Switch press status

  //Serial.println(is_switch_press);
  //delay(500);
  if (is_switch_press == HIGH){
    delay(debounce_delay); // debounce delay for button press
    if(is_switch_press == HIGH){
      digitalWrite(led, HIGH);
      Serial.println("WELCOME");
      delay(100);
      Serial.println("This is your reciept");
      myFile = SD.open("test3.txt");
      if (myFile) {
        Serial.println("test3.txt");
    
        while (myFile.available()) {
            
            //Serial.print(myFile.read());
            option = myFile.read();
            Serial.write(option);
        }
    
        myFile.close();
      } else {
    
      Serial.println("error opening file");
      }   
//      Serial.println("WELCOME");
//      delay(100);
//      Serial.println("This is your reciept");
//      Serial.println("with Arduino MEGA.");
      delay(100);
      Serial.println ("\n\r");
      Serial.println("DIVOR AUTOMATIONS");    
      Serial.println ("\n\r");
      Serial.println ("\n\r");
      Serial.println ("***************** \n \r");
      Serial.println ("Thank You");
      Serial.println ("\n\r");
      Serial.println ("\n\r");
      Serial.println ("\n\r");
      digitalWrite(led, LOW);    
    }    

  }

  else{
    digitalWrite(led, LOW);
  }    

}
