#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4
#define Motor11 23
#define Motor12 22
#define Motor21 25
#define Motor22 24
#define PWMmotor1 2
#define PWMmotor2 3

int IR1read = 0;
int IR2read = 0;
int IR3read = 0;
int IR4read = 0;
int IR5read = 0;
int motspd =170;
int lowspd = 20;
int highspd = 500;

void setup() {

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);


  pinMode(Motor11, OUTPUT);
  pinMode(Motor12, OUTPUT);
  pinMode(Motor21, OUTPUT);
  pinMode(Motor22, OUTPUT);
  pinMode(PWMmotor1, OUTPUT);
  pinMode(PWMmotor2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  scan();

  /*Forward...........................................................*/
  if (IR1read == 1 && IR2read == 1 && IR3read == 0 && IR4read == 1 && IR5read == 1  ) { //ok
    forward();


  }
  /* if (IR1read ==1 && IR2read ==1 && IR3read == 1 && IR4read == 0 && IR5read == 1 ) {//ok
     forward();

    }
  */if (IR1read == 1 && IR2read == 0 && IR3read == 0 && IR4read == 0 && IR5read == 1  ) { //ok
    forward();


  }


  /*Turn Left..........................................................*/
  if (IR1read == 1 && IR2read == 0 && IR3read == 0 && IR4read == 1 && IR5read == 1 ) { //ok
    left();
    delay(lowspd);
  }
  if (IR1read == 0 && IR2read == 0 && IR3read == 0 && IR4read == 1 && IR5read == 1) { //ok
    left();
    delay(highspd);
  }
  if (IR1read == 0 && IR2read == 0 && IR3read == 0 && IR4read == 0 && IR5read == 1) { //ok
    left();
    delay(highspd);
  }
  if (IR1read == 0 && IR2read == 0 && IR3read == 1 && IR4read == 1 && IR5read == 1) {//ok
    left();
    delay(highspd);
  }
  if (IR1read == 1 && IR2read == 0 && IR3read == 1 && IR4read == 1 && IR5read == 1) {//ok
    left();
    delay(lowspd);
  }
  if (IR1read == 0 && IR2read == 1 && IR3read == 1 && IR4read == 1 && IR5read == 1) {//ok
    left();
    delay(highspd);
  }
  if (IR1read == 0 && IR2read == 0 && IR3read == 1 && IR4read == 0 && IR5read == 1) {//ok
    left();
    delay(highspd);
  }
  if (IR1read == 1 && IR2read == 1 && IR3read == 0 && IR4read == 1 && IR5read == 0 ) { //tested for a special junction counting
    left();
    delay(lowspd);
  }


  /* Turn Right...........................................................*/

  if (IR1read == 1 && IR2read == 1 && IR3read == 0 && IR4read == 0 && IR5read == 0 ) { //ok
    right();
    delay(highspd);
  }
  if (IR1read == 1 && IR2read == 1 && IR3read == 1 && IR4read == 0 && IR5read == 0 ) { //ok
    right();
    delay(highspd);
  }
  if (IR1read == 1 && IR2read == 1 && IR3read == 0 && IR4read == 0 && IR5read == 1 ) { //ok
    right();
    delay(lowspd);
  }

  if (IR1read == 1 && IR2read == 1 && IR3read == 1 && IR4read == 0 && IR5read == 1 ) { //ok
    right();
    delay(lowspd);
  }

  /*Stoping.............................................................. */

  if (IR1read == 1 && IR2read == 1 && IR3read == 1 && IR4read == 1 && IR5read == 1) { //ok
    breake();
    delay(lowspd);
    
  }

  if (IR1read == 1 && IR2read == 1 && IR3read == 1 && IR4read == 1 && IR5read == 1) { //ok
    breake();
    delay(lowspd);
  }


  
}

void scan() {
  IR1read = digitalRead(IR1);
  IR2read = digitalRead(IR2);
  IR3read = digitalRead(IR3);
  IR4read = digitalRead(IR4);
  IR5read = digitalRead(IR5);



  Serial.print(digitalRead(IR1));
  Serial.print(digitalRead(IR2));
  Serial.print(digitalRead(IR3));
  Serial.print(digitalRead(IR4));
  Serial.print(digitalRead(IR5));

  Serial.println("  ");
}

void forward() {
  digitalWrite(Motor11, HIGH);
  digitalWrite(Motor12, LOW);
  digitalWrite(Motor21, HIGH);
  digitalWrite(Motor22, LOW);
  analogWrite(PWMmotor1, motspd);
  analogWrite(PWMmotor2, motspd);

  Serial.println(" forward ");

}

void breake() {
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, LOW);
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, LOW);
  Serial.println(" breake ");
}

void left() {
  digitalWrite(Motor11, HIGH);
  digitalWrite(Motor12, LOW);
  digitalWrite(Motor21, LOW);
  digitalWrite(Motor22, HIGH);
  analogWrite(PWMmotor1, motspd);
  analogWrite(PWMmotor2, motspd);
  Serial.println(" left ");
}
void right() {
  digitalWrite(Motor11, LOW);
  digitalWrite(Motor12, HIGH);
  digitalWrite(Motor21, HIGH);
  digitalWrite(Motor22, LOW);
  analogWrite(PWMmotor1, motspd);
  analogWrite(PWMmotor2, motspd);

  Serial.println(" right ");
}
