#define PinButton 8
#define ledPin 7

int estado = 0;
int guarda_estado = LOW;

void setup()
{
  pinMode(PinButton, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(100);
 }

  void loop(){
  
  estado = digitalRead(PinButton);
  
    if ( estado == HIGH)
    {
      guarda_estado = !guarda_estado;
      delay(500);
    }
    if (guarda_estado == HIGH)
    {
     digitalWrite(ledPin, HIGH);
     Serial.println("Acendendo Led"); 
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.println("Desligando Led");
    }
    delay(500);
  }
