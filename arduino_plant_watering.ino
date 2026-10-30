// TODO: SAFETY - detect faulty or disconnected sensors and
// limit the total watering per day before unattended operation

const int pumpPin = A3;
const int sensorPin = A0;

// TODO: Calibrate threshold using actual soil moisture readings
const int moistureThreshold = 600;

// TODO: Adjust based on pump water flow
const unsigned long wateringTime = 1000UL;        // 1 second
const unsigned long checkInterval = 1800000UL;    // 30 minutes

void setup() {
    digitalWrite(pumpPin, LOW);
    pinMode(pumpPin, OUTPUT);
    pinMode(sensorPin, INPUT);

    Serial.begin(9600);
}

void loop() {
    int moisture = analogRead(sensorPin);

    Serial.print("Soil moisture: ");
    Serial.println(moisture);

    // Higher value means drier soil
    if (moisture > moistureThreshold) {
        Serial.println("Soil too dry - watering");

        digitalWrite(pumpPin, HIGH);
        delay(wateringTime);
        digitalWrite(pumpPin, LOW);
    } else {
        Serial.println("Soil moist - no watering");
    }

    delay(checkInterval);
}
