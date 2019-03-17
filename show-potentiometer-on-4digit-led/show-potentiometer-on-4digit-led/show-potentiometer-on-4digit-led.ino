
/*

@Author Philippe Deslauriers
@public code : use and distribute without any restrictions

Showing number 0-9 on a Common Anode 7-segment LED display
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  
 */

 
// pin A0 on board is connected to potentiometer (center pin) 
// Pin 2-12 (11 total) are connected to the 7 segments of the display.

//https://www.arduino.cc/en/tutorial/AnalogInput
//https://create.arduino.cc/projecthub/SAnwandter1/programming-4-digit-7-segment-led-display-2d33f8
//https://halckemy.s3.amazonaws.com/uploads/attachments/261205/4_digit_7_segment_display_connections_KaSuFbbPfq.jpg


int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}

// "0001" will write "1" if this is set to true
boolean showLeadingZeros = false;

// reformat 0-1023 range to a single 0-9 digit
boolean reformat = false;

//delay after each "printSingleDigit" method
int delayMs = 1;
int potentiometerUpperBound = 1023;

// the loop routine runs over and over again forever:
void loop() {

  //read unformatted
  int value = readPotentiometer();

  //reformat 0-9
  if(reformat){
    //reformat will also stabilize the value, as the potentiomer input is not totally constant (analog input)
    value = formatToZeroToOne(value);
  }  

  print(value);
  
  delay(10);
  
}


int readPotentiometer(){
  //read potentiometer (middle) on PIN Analog A0 (potetiometer must hasve 
  //potentiometer must be connected to 5v  and gronud
  int val = analogRead(A0);
  return val;
}

int formatToZeroToOne(int val){
    //TODO : use a constant
    int increments = potentiometerUpperBound/9;
    int zeroToNine = val/increments;
    return zeroToNine = val/increments;
}

void print(int val){
  int a = (val%10000)/1000;
  int b = (val%1000)/100;
  int c = (val%100)/10;
  int d = val%10;
  int numberArray[4] = {a,b,c,d};
  printArray(numberArray);
}

void printArray(int numbers[4]){


  boolean hasStarted=showLeadingZeros;
  int number;
  
  for(int i=0;i<4;i++){
    
      number = numbers[i];
  
      if(i<3 && number==0 && !hasStarted){
        number = -1; //replace with a blank number
      }else{   
        hasStarted = true;
     }
    
     printSingleDigit(number,i);
    
  }
 
}

void printSingleDigit(int n, int led) {

   setLed(led);
   
   //only print a last digit
   switch(n%10){
     case 0 : zero();
       break;
     case 1 : one();
       break;
     case 2 : two();
       break;       
     case 3 : three();
       break;     
     case 4 : four();
       break;
     case 5 : five();
       break;
     case 6 : six();
       break;
     case 7 : seven();
       break;
     case 8 : eight();
       break;
     case 9 : nine();
       break;
     default : off(); 
       break;       
    }
    delay(delayMs);
    

}

void setLed(int led){
  digitalWrite(D1, led==0?HIGH:LOW);
  digitalWrite(D2, led==1?HIGH:LOW);
  digitalWrite(D3, led==2?HIGH:LOW);
  digitalWrite(D4, led==3?HIGH:LOW); 
}

void off(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void zero(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}
void one(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);
}
void two(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}
void three(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}
void four(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void five(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void six(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void seven(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}
void eight(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void nine(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
