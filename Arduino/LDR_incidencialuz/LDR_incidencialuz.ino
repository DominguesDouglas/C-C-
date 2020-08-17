int IN1 = 4; // pino IN1 conectado porta D4 Arduino
int IN2 = 5; // pino IN2 conectado porta D5 Arduino
void setup()
{
Serial.begin(9600); // console serial 9600 Bps
pinMode(IN1, OUTPUT); // definições das portas como portas de saidas
pinMode(IN2, OUTPUT);
digitalWrite(IN1, HIGH); // desativa porta IN1
digitalWrite(IN2, HIGH); // desativa porta IN2
}
void loop()
{
digitalWrite(IN2, HIGH); // desativa porta IN2
digitalWrite(IN1, LOW); // acionamento relé K1
Serial.println("Rele K1 acionado"); // print mensagem
delay (3000); // atraso de 3 segundos
digitalWrite(IN1, HIGH); // desativa porta IN1
digitalWrite(IN2, LOW); // acionamento relé K2
Serial.println("Rele K2 acionado"); // print mensagem
delay (3000); // atraso de 3 segundos
}
