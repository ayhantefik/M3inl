#define BTN 7
#define VIB 4

// Jag använder "16. vibrationssensormodul"

void setup() {
    pinMode(BTN, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(VIB, INPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(9600);
}

int btnValue = LOW;
int ledValue = HIGH;

void loop() {
    int vibValue = digitalRead(VIB);
    if(digitalRead(BTN) == LOW){
      if(btnValue == HIGH){
        btnValue = LOW;
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("OFF");
      }
      else{
        btnValue = HIGH;
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("ON");
      }
    }
    if(btnValue == HIGH){
      if(vibValue == LOW)
        Serial.println("No vibration");
      else
        Serial.println("Warning: VIBRATION");
    }

    delay(100);
}
