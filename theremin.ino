#define trigger 3 //"trigger" now refers to digital pin 3
#define echo 4 //"echo" now refers to digital pin 4
#define buzzer 5 //"buzzer" now refers to digital pin 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //open serial port & set data rate to 9600bps
  pinMode(trigger,OUTPUT); //trigger=output from arduino
  pinMode(echo,INPUT); //echo=input to arduino
  pinMode(buzzer,OUTPUT); //buzzer= output from arduino
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //pitches in C blues scale:
  float C5=523.25;
  float Eflat5=622.25;
  float F5=698.26;
  float Fsharp5=739.99;
  float G5=783.99;
  float Bflat5=932.33;
  float C6=1046.50;

  //send out a 10ms trigger pulse:
  digitalWrite(trigger, LOW); //set trigger pin to LOW initially
  delay(2);
  digitalWrite(trigger, HIGH); //jump it up to high
  delay(10);
  digitalWrite(trigger, LOW); //reset back to low

  
  long duration=pulseIn(echo, HIGH); //time for echo pin to jump high
  Serial.print("Pulse duration: ");
  Serial.println(duration);
  
  long distance=duration/58.2; //as per interwebz...check w/data sheet 
  Serial.print("distance");
  Serial.println(distance); //want to be able to check if numbers are reasonable/figure our range

  long max_dist=35; //TO BE DETERMINED (max dist=end of reasonable range for hand)

  boolean C5range= (distance<max_dist/7);
  boolean Eflat5range=(distance>=max_dist/7) && (distance<2*max_dist/7);
  boolean F5range=(distance>=2*max_dist/7) && (distance<3*max_dist/7);
  boolean Fsharp5range=(distance>=3*max_dist/7) && (distance<4*max_dist/7);
  boolean G5range=(distance>=4*max_dist/7) && (distance<5*max_dist/7);
  boolean Bflat5range=(distance>=5*max_dist/7) && (distance<6*max_dist/7);
  boolean C6range=(distance>=6*max_dist/7);

  if (C5range){ //[isTrue]
    tone(buzzer,C5);
    Serial.println("Playing C5");
  }
  else if (Eflat5range){
    tone(buzzer,Eflat5);
    Serial.println("Playing Eflat5");
  }
  else if (F5range){
    tone(buzzer,F5);
    Serial.println("Playing F");
  }
  else if (Fsharp5range){
    tone(buzzer,Fsharp5);
    Serial.println("Playing Fsharp5");
  }
  else if (G5range){
    tone(buzzer,G5);
    Serial.println("Playing G5");
  }
  else if (Bflat5range){
    tone(buzzer,Bflat5);
    Serial.println("Playing Bflat5");
  }
  else if (C6range){
    tone(buzzer,C6);
    Serial.println("Playing C6");
  } 
  else{
    Serial.println("out of range, no sound");
    }
Serial.println("Please wait");
delay(250);
  
}

