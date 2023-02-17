
int CP1 = 1; // pin 4 assigned to switch 1
int CP2 = 2; // pin 6 assigned to switch 2
int LD1 = 18;//  pin 1 will be as signal A or LED 1
int LD2 = 19;// pin 3 will be as signal B or LED 2
int P1 = 0;// Data read from BP1 stored in E1
int P2 = 0;// Data read from BP2 stored in E2
int a = 200;// First letter 'a'& width of 1st pulse
int r = 900;// This the max value after generating C pulses used in mode for generating waveform
int b = 500;// parameter 'b' calculated as second letter*100 = 1*100 = 100
int c = 13; // Number of pulses in the block
int d = 4500;// Spaces btw the pulse blocks
// mode is calculated as rem(fifth letter/4) + 1 = rem(1/4) + 1 = 2. Hence we use mode 2

void setup() {
  // put your setup code here, to run once:
  pinMode(CP1, INPUT); // CP1 is an input component
  pinMode(CP2, INPUT); // CP2 is an input component
  pinMode(LD1, OUTPUT);// LD1 emits light used as output signal to study waveforms
  pinMode(LD2, OUTPUT);// LD2 to set as output component 
  Serial.begin(9600);

}

// Loop to check the inputs and perform operations 
void loop() {
  // put your main code here, to run repeatedly:
  P1 = digitalRead(sw1); // Collect the P1 to know if its at LOW or High state
  P2 = digitalRead(sw2); // summon the P2 of the second button
  
  if(P1 == HIGH)         // using if else to 
  {
    digitalWrite(LD1, LOW);  // This part of the code creates the blank signal
    digitalWrite(LD2, LOW);

  }

  else{

    if(P2 == LOW)  
    {
      digitalWrite(LD1, HIGH);
      delay(50);
      digitalWrite(LD2, LOW);

      for(int i =0;i<c;i++)  
      {
        digitalWrite(LD1, HIGH);
        delay(a);
        digitalWrite(LD1, LOW);
        delay(b);
        a = a+50;
      }
      digitalWrite(LD1, LOW);
      delay(d);  
    }

    else  // This part of the code runs if switch2 is pressed
    {
      digitalWrite(LD2, HIGH);  
      delay(50);
      digitalWrite(LD2, LOW);

      for(int i =0; i<c;i++){   

        digitalWrite(LD1, HIGH);
        delay(r);
        digitalWrite(LD1, LOW);
        delay(b);
        r = r-50;
      }

      digitalWrite(LD1, LOW);
      delay(d);


    }

  }

}