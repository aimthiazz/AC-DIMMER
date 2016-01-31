unsigned long duration=0;
int flag1=0;
int a=0;
int arr[5];
int i,j;
int d1,d2,d3,d4,final_value;
int count;
int delay1=5000;
int ini_tim;
int fi_tim;
int trig;
void setup()
{
  noInterrupts();
  TCCR1A=0;
  TCCR1B=0;
  TCNT1=0;
  OCR1A=15625;
  TCCR1B |=(1<<WGM12);
  TCCR1B |=(1<<CS12)|(1<<CS10);
  TIMSK1 |=(1<<OCIE1A);
  interrupts();
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0,flag,FALLING);
}
ISR(TIMER1_COMPA_vect)
{
  count++;
 // Serial.println(count);
}

void flag()
{
  delayMicroseconds(delay1);
  digitalWrite(11,1);
  delayMicroseconds(10);
  digitalWrite(11,0);
}
char key;
unsigned long start;
void loop()
{
  while(Serial.available()>0)
  {
    key=Serial.read();
    if(key=='-')
    {
      if(delay1<8000)
      {
      delay1=delay1+500;
      }
      if(delay1>8000)
      {
        delay1=8000;
      }
      trig=0;
    }
    else if(key=='+')
    {
      if(delay1>1000)
      {
      delay1=delay1-500;
      }
      if(delay1<1000)
      {
        delay1=1000;
      }
      trig=0;
    }
    else if(key>=48)
    {
      key=key-48;
    
    arr[i]=key;
    i++;
    trig=1;
    
      
    }
   
}
//Serial.println(i); 
if(i==1)
{delay1=1000;
  d1=arr[0];
  final_value=d1;
  i=0;
  fi_tim=ini_tim+final_value;
  
}
if(i==2)
{delay1=1000;
  //Serial.println(i);
  d1=arr[0];
  d2=arr[1];
  final_value=(d1*10)+d2;
 
  //Serial.println(delay1);
  i=0;
  ini_tim=count;
  fi_tim=ini_tim+final_value;
 // Serial.println(ini_tim);
}
if(i==3)
{delay1=1000;
 // Serial.println(i);
  d1=arr[0];
  d2=arr[1];
  d3=arr[2];
  final_value=(d1*100)+(d2*10)+d3;
  //Serial.println(delay1);
  ini_tim=count; 
  fi_tim=ini_tim+final_value;
   // Serial.println(ini_tim);
   i=0;
}
if(i==4)
{delay1=1000;
  d1=arr[0];
  d2=arr[1];
  d3=arr[2];
  d4=arr[3];
  final_value=(d1*1000)+(d2*100)+(d3*10)+d4;
  //Serial.println(delay1);
   i=0;
   ini_tim=count;
   fi_tim=ini_tim+final_value;
     //Serial.println(ini_tim);
}
delay(10);
  if(trig==1)
  {
delay1=map((fi_tim-count),0,fi_tim,8000,1000);
}
if(delay1<=1000)
{
  trig=0;
}
if(delay1>=8000)
{
  trig=0;
}
Serial.println(delay1);
}
/*{
  if(flag1==1)
  {
    
    //Serial.println(duration-start);
    //duration=0;
    flag1=0;
    start=millis();
  }
  duration=millis();
  if(duration-start==5)
  {
    Serial.println(duration-start);
    digitalWrite(11,1);
  }
  duration=millis();
  delayMicroseconds(200);
  digitalWrite(11,0);
  
  
}*/
