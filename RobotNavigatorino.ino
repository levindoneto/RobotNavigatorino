#include <Servo.h> 
#define DIR_PIN1  3 
#define DIR_PIN2  4 
#define ESQ_PIN1  5 
#define ESQ_PIN2  6 
#define ECHO  12 
#define TRIG  13
Servo myservo;
void setup()
{
  myservo.attach(8);
  myservo.write(90);
  Serial.begin(9600); 
  setupMove(); 
  setupUltrasonic(); 
}

void loop()
{
  unsigned int d, d_esq, d_dir; 
  myservo.write(90);
  moveFrente();
  delay(250);
  movePara();
  d = leDistancia(); 
 
  if(d < 13) 
  {
    moveTras();
    delay(250);
    movePara();
    myservo.write(15);
    delay(500);
    d_dir = leDistancia();
    myservo.write(165);
    delay(500);
    d_esq = leDistancia();
    
         while(d_dir < 13 && d_esq < 13)
    {
      moveTras();
      delay(250);
      movePara();
      myservo.write(13);
      delay(500);
      d_dir = leDistancia();
      myservo.write(165);
      delay(500);
      d_esq = leDistancia();
     }
    
    if(d_dir>d_esq)
      {
        moveDireita();
        delay(250);
        movePara();
      }
     else
      {
        moveEsquerda();
        delay(250);
        movePara();
      } 
   }
}

void moveTras() 
{
  digitalWrite(ESQ_PIN1, LOW); 
  digitalWrite(ESQ_PIN2, HIGH);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, HIGH);
}

void moveFrente() 
{
  digitalWrite(ESQ_PIN1, HIGH); 
  digitalWrite(ESQ_PIN2, LOW);
  digitalWrite(DIR_PIN1, HIGH);
  digitalWrite(DIR_PIN2, LOW);
}

void moveDireita() 
{
  digitalWrite(ESQ_PIN1, HIGH); 
  digitalWrite(ESQ_PIN2, LOW);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, HIGH);
}

void moveEsquerda() 
{
  digitalWrite(ESQ_PIN1, LOW); 
  digitalWrite(ESQ_PIN2, HIGH);
  digitalWrite(DIR_PIN1, HIGH);
  digitalWrite(DIR_PIN2, LOW);
}

void movePara() 
{
  
  digitalWrite(ESQ_PIN1, LOW); 
  digitalWrite(ESQ_PIN2, LOW);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, LOW);
}

void setupMove() 
{
  
  pinMode(ESQ_PIN1, OUTPUT);
  pinMode(ESQ_PIN2, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  digitalWrite(ESQ_PIN1, LOW); 
  digitalWrite(ESQ_PIN2, LOW);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, LOW);
}

unsigned int leDistancia() 
{
  int duracao; 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW); 
  duracao = pulseIn(ECHO, HIGH); 
  return duracao/58;
}

void setupUltrasonic() 
{
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT); 
  digitalWrite(TRIG, LOW);
}
