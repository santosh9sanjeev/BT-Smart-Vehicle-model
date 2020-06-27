int a=5,b=6,c=7,d=8;
char data;
const int trigpin =9;
const int echopin=11;
int i,j;

long duration;
int distance;
int led1=2,led2=3;

void setup() {
  Serial.begin(9600);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}

void loop() {
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(echopin,LOW);

  duration=pulseIn(echopin,HIGH);

  distance=duration*0.034/2;
  while(Serial.available()!=0)
  {data=Serial.read();
  Serial.print(data);
     if(data=='0')
     {digitalWrite(a,LOW);
     digitalWrite(b,LOW);
     digitalWrite(c,LOW);
     digitalWrite(d,LOW);
     }
     else if(data=='2')
     {digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);}
     else if(data=='4')
     {digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
     }
     else if (data=='6')
     {digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
     }  
  else if (data=='8')
     {digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     }
      }
      if(distance<10)
      {digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
}}
