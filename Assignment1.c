
int switch1 = 1; // pin 1 is assigned to switch 1 on esp32
int switch2 = 2; // pin 2 is assigned to switch 2 on esp32
int LED1 = 18;//  pin 1 will be as signal A or LED 1
int LED2 = 19;// pin 3 will be as signal B or LED 2
int A = 0;// Data read from switch1 stored in A
int B = 0;// Data read from switch2 stored in B
int a = 200;// First letter 'a' is the width of 1st cycle
int r = 7500;// This the max value after generating C cycle used in mode for generating a waveform
int b = 500;// parameter 'b' calculated as second letter*100 = 1*100 = 100
int c = 13; // Number of pulses in one cycle
int d = 4500;// Space in between the pulses 
// mode is calculated as rem(fifth letter/4) + 1 = rem(1/4) + 1 = 2. Hence we use mode 2

void setup() {
  // put your setup code here, to run once:
  pinMode(switch1, INPUT); // CP1 is an input component
  pinMode(switch2, INPUT); // CP2 is an input component
  pinMode(LED1, OUTPUT);// LED1 emits light used as output signal to study waveforms
  pinMode(LED2, OUTPUT);// LED2 to set as output component 
  Serial.begin(9600);

}

// Loop to check the inputs and perform operations 
void loop() {
  // put your main code here, to run repeatedly:
  A = digitalRead(switch1); // Collect the A to know LOW or High state
  B = digitalRead(switch2); // call the B as the second button
  
  if(A == HIGH)         // if else condition is used  
  {
    digitalWrite(LED1, LOW);  // This part of the code creates the blank signal
    digitalWrite(LED2, LOW);

  }

  else{

    if(B == LOW)  
    {
      digitalWrite(LED1, HIGH);
      delay(50);
      digitalWrite(LED2, LOW);

      for(int i =0;i<c;i++)  
      {
        digitalWrite(LED1, HIGH);
        delay(a);
        digitalWrite(LED1, LOW);
        delay(b);
        a = a+50;
      }
      digitalWrite(LED1, LOW);
      delay(d);  
    }

    else  // if switch2 is pressed mode is activated
    {
      digitalWrite(LED2, HIGH);  
      delay(50);
      digitalWrite(LED2, LOW);

      for(int i =0; i<c;i++){   

        digitalWrite(LED1, HIGH);
        delay(r);
        digitalWrite(LED1, LOW);
        delay(b);
        r = r-50;
      }

      digitalWrite(LED1, LOW);
      delay(d);


    }

  }

}
