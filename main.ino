#define SEVEN_SEG_A   11
#define SEVEN_SEG_B   12
#define SEVEN_SEG_C   7
#define SEVEN_SEG_D   6
#define SEVEN_SEG_E   5
#define SEVEN_SEG_F   10
#define SEVEN_SEG_G   9
#define SEVEN_SEG_DP  8

void setup() {

  pinMode(SEVEN_SEG_A, OUTPUT);
  pinMode(SEVEN_SEG_B, OUTPUT);
  pinMode(SEVEN_SEG_C, OUTPUT);
  pinMode(SEVEN_SEG_D, OUTPUT);
  pinMode(SEVEN_SEG_E, OUTPUT);
  pinMode(SEVEN_SEG_F, OUTPUT);
  pinMode(SEVEN_SEG_G, OUTPUT);
  pinMode(SEVEN_SEG_DP, OUTPUT);

  Serial.begin(9600);
}

void displayLeds(int a, int b, int c, int d, int e, int f, int g, int dp) {

  digitalWrite(SEVEN_SEG_A, a == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_B, b == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_C, c == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_D, d == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_E, e == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_F, f == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_G, g == 1 ? HIGH : LOW);
  digitalWrite(SEVEN_SEG_DP, dp == 1 ? HIGH : LOW);
}

void displayNumber(int number, bool dp) {

  switch (number) {
    case 0:
      displayLeds(1, 1, 1, 1, 1, 1, 0, 0);
      break;
    case 1:
      displayLeds(0, 1, 1, 0, 0, 0, 0, 0);
      break;
    case 2:
      displayLeds(1, 1, 0, 1, 1, 0, 1, 0);
      break;
    case 3:
      displayLeds(1, 1, 1, 1, 0, 0, 1, 0);
      break;
    case 4:
      displayLeds(0, 1, 1, 0, 0, 1, 1, 0);
      break;
    case 5:
      displayLeds(1, 0, 1, 1, 0, 1, 1, 0);
      break;
    case 6:
      displayLeds(1, 0, 1, 1, 1, 1, 1, 0);
      break;
    case 7:
      displayLeds(1, 1, 1, 0, 0, 0, 0, 0);
      break;
    case 8:
      displayLeds(1, 1, 1, 1, 1, 1, 1, 0);
      break;
    case 9:
      displayLeds(1, 1, 1, 1, 0, 1, 1, 0);
      break;
    default:
      displayLeds(0, 0, 0, 0, 0, 0, 0, 0);
  }
}

void loop() {

  for (int i = -1; i <= 9; i++) {
    displayNumber(i, true);
    delay(500);
  }
}
