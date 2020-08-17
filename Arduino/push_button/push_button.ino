#define AnalogLDR A0
#define Limiar 1.5
#define ledPin 13

int Leitura = 0;
float VoltageLDR;
float ResLDR;

void setup ()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(100);
  }

  void loop()
  {
    Leitura = analogRead(AnalogLDR);
    VoltageLDR = Leitura * (5.0/1024);
    Serial.print("Leitura sensor LDR = ");
    Serial.println(VoltageLDR);

    if (VoltageLDR > Limiar)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
    delay(500);
    }
