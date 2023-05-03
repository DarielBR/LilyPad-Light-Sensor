
#include "hardware.h"

int ledArray_lenght = sizeof(ledBar)/sizeof(ledBar[0]);
void ledBar_Range (float reading)
{
    for(int i=0; i < ledArray_lenght; i++)
  {
    float percent = (100*reading)/max_analog_read;
    float current_step = max_analog_read/ledArray_lenght*(i+1);
    float last_step = max_analog_read/ledArray_lenght*(i);
    if (reading == 0)
    {
      digitalWrite(ledBar[i], LOW);
    }
    else
    {
      if((reading >= current_step) || (reading < current_step && reading > last_step))
      {
        digitalWrite(ledBar[i], HIGH);
        Serial.println("Si"); 
      }
      else
      {
        digitalWrite(ledBar[i], LOW);
        Serial.println("No");
      }
    }
  }
}

void Set_Max_Treshold(float reading)
{
  if(reading > max_analog_read)
  {
    max_analog_read = reading;
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
  }  
}

void setup() {
  // put your setup code here, to run once:
 
  for (int i=0; i < ledArray_lenght; i++)
  {
    pinMode(ledBar[i], OUTPUT);  
  }
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Set_Max_Treshold(analogRead(sensorPin));
  ledBar_Range(analogRead(sensorPin));
  
  delay(100);
}
