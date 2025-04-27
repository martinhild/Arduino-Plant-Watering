// TEST ohne Sensor, ob Board und Pumpe funktionieren

int Pumppin = A3; // Steuerung der Pumpe

void setup()
{
  
  pinMode(Pumppin, OUTPUT);//Ausgangspin für Relais
  pinMode(A0, INPUT); // Eingangspin vom Bodensensor
}

void loop()
{
      digitalWrite(Pumppin, HIGH); // Motor Start
      delay(2000); //2sec
      digitalWrite(Pumppin, LOW); // Motor Stop
      delay(3000); //3sec
}
