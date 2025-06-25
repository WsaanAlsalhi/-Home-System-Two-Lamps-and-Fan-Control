const int buttonPin = 2;    // زر التحكم في الليدات
const int led1 = 3;         // LED الأبيض الأول
const int led2 = 4;         // LED الأبيض الثاني

const int motorPin = 5;         // المحرك
const int motorButtonPin = 7;   // زر تشغيل/إيقاف المحرك
const int potPin = A0;          // المقاومة المتغيرة

int buttonState = HIGH;
int lastButtonState = HIGH;
bool ledsOn = false;

int motorButtonState = HIGH;
int lastMotorButtonState = HIGH;
bool motorRunning = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motorButtonPin, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motorPin, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  analogWrite(motorPin, 0);
  motorRunning = false;
}

void loop() {
  // زر تشغيل/إيقاف الليدات
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledsOn = !ledsOn;
    digitalWrite(led1, ledsOn ? HIGH : LOW);
    digitalWrite(led2, ledsOn ? HIGH : LOW);
    delay(200);
  }
  lastButtonState = buttonState;

  // زر المحرك
  motorButtonState = digitalRead(motorButtonPin);
  if (motorButtonState == LOW && lastMotorButtonState == HIGH) {
    motorRunning = !motorRunning;
    delay(200);
  }
  lastMotorButtonState = motorButtonState;

  if (motorRunning) {
    int potValue = analogRead(potPin);
    int speed = map(potValue, 0, 1023, 0, 255);
    analogWrite(motorPin, speed);
  } else {
    analogWrite(motorPin, 0);
  }
}
