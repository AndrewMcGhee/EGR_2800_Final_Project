// Pins
#define SENSOR_PIN_0  A4
#define SENSOR_PIN_1  A5

#define CHECK_DELAY  100


void
setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
}

void
loop() {
  // read the state of the the input pin:
  int state0 = digitalRead(SENSOR_PIN_0);
  int state1 = digitalRead(SENSOR_PIN_1);

  if (state0 == LOW)
    Serial.println("The obstacle is present");
  else
    Serial.println("The obstacle is NOT present");

  if (state1 == LOW)
    Serial.println("The obstacle is present");
  else
    Serial.println("The obstacle is NOT present");

  delay(CHECK_DELAY);
}
