
// ArcadeCoinsLights
// Switch On TV, Computer X-Arcade custom setup
// Blink 3 LEDs to light the Arcade Coin Part

int LED1=13;    // 1F
int LED2=12;    // 5F
int LED3=11;    // 10F
int Buzzer1=8;  // Buzzer
int Relay1=7;   // TV Power Switch
int Relay2=6;   // Computer Power Switch
int Relay3=5;   // X-Arcade Custom Mode Activator Switch

void setup() {
  // Initialize the Relays
  // When switched On, Arduino set as input I/O pins with a floating' voltage
  pinMode(Relay1, OUTPUT);    // Already set as HIGH when Arduino is switched On. It Will be turnd as LOW when pin mode is set.
  digitalWrite(Relay1, HIGH); // Quicky turn it HIGH so the Relay won't see the upper change.
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, HIGH);
  pinMode(Relay3, OUTPUT);
  digitalWrite(Relay3, HIGH);
  
  // initialize digital pins 11, 12, 13 as an output.
  // /!\  Random routine based on Min=LED3 Max=LED1+1  /!\
  pinMode(LED3, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  first_run();
}

void loop() {
  int blink_delay = 100;
  
  for(int i=0; i<3; i++)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    delay(400);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(400);
  }
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(400);
  
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED1, HIGH);
    delay(blink_delay);
    digitalWrite(LED2, HIGH);
    delay(blink_delay);
    digitalWrite(LED3, HIGH);
    delay(blink_delay);
    digitalWrite(LED1, LOW);
    delay(blink_delay);
    digitalWrite(LED2, LOW);
    delay(blink_delay);
    digitalWrite(LED3, LOW);
    delay(blink_delay);
    digitalWrite(LED3, HIGH);
    delay(blink_delay);
    digitalWrite(LED2, HIGH);
    delay(blink_delay);
    digitalWrite(LED1, HIGH);
    delay(blink_delay);
    digitalWrite(LED3, LOW);
    delay(blink_delay);
    digitalWrite(LED2, LOW);
    delay(blink_delay);
    digitalWrite(LED1, LOW);
    delay(blink_delay);
  }
  
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED1, HIGH);
    delay(blink_delay);
    digitalWrite(LED1, LOW);
    delay(blink_delay);
    digitalWrite(LED2, HIGH);
    delay(blink_delay);
    digitalWrite(LED2, LOW);
    delay(blink_delay);
    digitalWrite(LED3, HIGH);
    delay(blink_delay);
    digitalWrite(LED3, LOW);
    delay(blink_delay);
  }
  
  for(int i=0; i<5; i++)
  {
    digitalWrite(LED3, HIGH);
    delay(blink_delay);
    digitalWrite(LED3, LOW);
    delay(blink_delay);
    digitalWrite(LED2, HIGH);
    delay(blink_delay);
    digitalWrite(LED2, LOW);
    delay(blink_delay);
    digitalWrite(LED1, HIGH);
    delay(blink_delay);
    digitalWrite(LED1, LOW);
    delay(blink_delay);
  }
  delay(150);
  
  for(int i=0; i<100; i++)
  {
    int ranpin = random(LED3, LED1+1);
    if(digitalRead(ranpin)==HIGH) digitalWrite(ranpin, LOW);
    else digitalWrite(ranpin, HIGH);
    delay(100);
  }
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(20000);
}

void first_run() {
  int speed = 50;

  // Play Sound
  delay(500);
  for(int beep=0; beep<8; beep++)
  {
    for(int i=0; i<1000; i+=200)
    {
      int freq = beep * 1000 + i;
      tone(Buzzer1, freq, speed/3+7);
      delay(speed/3+2);
    }
  }
  delay(500);
  
  // Simulate the TV switch button with a relay
  // Remember: "LOW is Pressed, HIGH is Released"
  digitalWrite(Relay1, LOW);
  delay(400);
  digitalWrite(Relay1, HIGH);
  digitalWrite(LED1, HIGH);
  delay(5000);

  // Simulate the Computer PowerSWitch button with a relay
  digitalWrite(Relay2, LOW);
  delay(400);
  digitalWrite(Relay2, HIGH);
  digitalWrite(LED2, HIGH);
  delay(10000);

  // Simulate the X-Arcade switch with a relay
  digitalWrite(Relay3, LOW);
  delay(400);
  digitalWrite(Relay3, HIGH);
  delay(500);
  digitalWrite(Relay3, LOW);
  delay(400);
  digitalWrite(Relay3, HIGH);
  digitalWrite(LED3, HIGH);
  delay(400);
}
