int cnt = 0;

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    ;
  }
}

void loop() {
  cnt += 1;

  Serial.print(cnt);
  Serial.println(" Hello World!");

  delay(1000);
}
