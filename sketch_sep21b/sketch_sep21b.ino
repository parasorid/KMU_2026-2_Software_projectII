#define PIN_LED 7

void setup() {
  pinMode(PIN_LED, OUTPUT);

}

int pwm_period = 1000;

void set_period(int period) {
  if(period >= 100 && period <= 10000){
    pwm_period = period;
  }
  else{
    printf("Period 값이 원하던 값과 다릅니다. 다른것을 입력하여 주십시오.");
  }
}

void set_duty(int duty) {

  if(duty<0 || duty > 100) 
    return;

  unsigned long time_on =(unsigned long)pwm_period * duty / 100;
  unsigned long time_off = pwm_period - time_on;

  digitalWrite(PIN_LED, HIGH);
  delayMicroseconds(time_on);

  digitalWrite(PIN_LED, LOW);
  delayMicroseconds(time_off);
}

void loop() {
  set_period(100);

  int cycles = 1000000 / pwm_period;
  int half_cycles = cycles / 2;

  for (int i = 0; i < cycles; i++) {

    int duty;

    if (i < half_cycles) {
      duty = i * 100L / half_cycles;
    }

    else {
      duty = (cycles - i) * 100L / half_cycles;
    }

    set_duty(duty);
  }
}
