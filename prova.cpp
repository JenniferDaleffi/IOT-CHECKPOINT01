// Jennifer Eduarda Vieira Daleffi - RM557137
// Leonardo Cadena - RM557528
// 2TDSPV
 
#define BOTAO1 2
#define BOTAO2 3
#define BOTAO3 4
#define LED_VERDE1 5
#define LED_AMARELO1 6
#define LED_VERMELHO1 7
#define LED_VERDE2 8
#define LED_AMARELO2 9
#define LED_VERMELHO2 10
#define LED_PEDESTRE1 11
#define LED_PEDESTRE2 12
#define SENSOR_ANALOG 14
 
int limite_inf = 100;

int limite_sup = 950;

bool leds_acesos = false;
 
void setup() {

  Serial.begin(9600);
  Serial.println("RM: 557528, RM: 557137");
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);
  pinMode(BOTAO3, INPUT_PULLUP);
  pinMode(LED_VERDE1, OUTPUT);
  pinMode(LED_AMARELO1, OUTPUT);
  pinMode(LED_VERMELHO1, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
  pinMode(LED_AMARELO2, OUTPUT);
  pinMode(LED_VERMELHO2, OUTPUT);
  pinMode(LED_PEDESTRE1, OUTPUT);
  pinMode(LED_PEDESTRE2, OUTPUT);
  delay(2000);

}
 
void loop() {

  // REMOVA O COMENTÁRIO DA QUESTÃO QUE QUER TESTAR
  // questao2();
  // questao3();

  questao4();
  // questao5();  

}
 
void questao2() {

  digitalWrite(LED_VERDE1, HIGH);
  digitalWrite(LED_PEDESTRE1, LOW);
  delay(5000);
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_AMARELO1, HIGH);
  delay(2000);
  digitalWrite(LED_AMARELO1, LOW);
  digitalWrite(LED_VERMELHO1, HIGH);
  digitalWrite(LED_PEDESTRE1, HIGH);
  delay(5000);
  digitalWrite(LED_PEDESTRE1, LOW);

  for (int i = 0; i < 3; i++) {

    digitalWrite(LED_PEDESTRE1, HIGH);
    delay(500);
    digitalWrite(LED_PEDESTRE1, LOW);
    delay(500);

  }

  delay(3000);

}
 
void questao3() {

  int valor = analogRead(SENSOR_ANALOG);
  Serial.println(valor);
 
  if (valor < 200) {

    digitalWrite(LED_VERDE1, HIGH);
    digitalWrite(LED_AMARELO1, LOW);
    digitalWrite(LED_VERMELHO1, LOW);

  } else if (valor < 650) {

    digitalWrite(LED_VERDE1, LOW);
    digitalWrite(LED_AMARELO1, HIGH);
    digitalWrite(LED_VERMELHO1, LOW);

  } else if (valor < 950) {

    digitalWrite(LED_VERDE1, LOW);
    digitalWrite(LED_AMARELO1, LOW);
    digitalWrite(LED_VERMELHO1, HIGH);

  } else if (valor < 1000) {

    for (int i = 0; i < 3; i++) {

      digitalWrite(LED_VERDE1, HIGH);
      digitalWrite(LED_AMARELO1, HIGH);
      digitalWrite(LED_VERMELHO1, HIGH);
      delay(500);
      digitalWrite(LED_VERDE1, LOW);
      digitalWrite(LED_AMARELO1, LOW);
      digitalWrite(LED_VERMELHO1, LOW);
      delay(500);

    }

  } else {

    Serial.println("Alarme!");

    while (true) {

      digitalWrite(LED_VERMELHO1, HIGH);
      digitalWrite(LED_VERMELHO2, HIGH);
      delay(500);
      digitalWrite(LED_VERMELHO1, LOW);
      digitalWrite(LED_VERMELHO2, LOW);
      delay(500);

    }

  }

  delay(500);

}
 
void questao4() {

  int VALOR = analogRead(SENSOR_ANALOG);
  Serial.println(VALOR);
 
  if (VALOR > limite_sup && !leds_acesos) {

    digitalWrite(LED_VERDE1, HIGH);
    digitalWrite(LED_VERDE2, HIGH);

    leds_acesos = true;

  }
 
  if (VALOR < limite_inf && leds_acesos) {

    digitalWrite(LED_VERDE1, LOW);
    digitalWrite(LED_VERDE2, LOW);

    leds_acesos = false;

  }

  delay(500);

}
 
void questao5() {

  static bool estadoBotao1 = HIGH, estadoBotao2 = HIGH, estadoBotao3 = HIGH;
 
  if (digitalRead(BOTAO1) == LOW && estadoBotao1 == HIGH) {

    estadoBotao1 = LOW;

    digitalWrite(LED_VERDE1, HIGH);
    digitalWrite(LED_VERDE2, HIGH);

  }

  if (digitalRead(BOTAO1) == HIGH) estadoBotao1 = HIGH;
  if (digitalRead(BOTAO2) == LOW && estadoBotao2 == HIGH) {

    estadoBotao2 = LOW;

    digitalWrite(LED_VERDE1, LOW);
    digitalWrite(LED_VERDE2, LOW);

    for (int i = 0; i < 5; i++) {

      digitalWrite(LED_VERMELHO1, HIGH);
      digitalWrite(LED_VERMELHO2, HIGH);

      delay(500);
      digitalWrite(LED_VERMELHO1, LOW);
      digitalWrite(LED_VERMELHO2, LOW);
      delay(500);

    }

  }

  if (digitalRead(BOTAO2) == HIGH) estadoBotao2 = HIGH;
 
  if (digitalRead(BOTAO3) == LOW && estadoBotao3 == HIGH) {

    estadoBotao3 = LOW;
    
    digitalWrite(LED_VERMELHO1, LOW);
    digitalWrite(LED_VERMELHO2, LOW);

  }

  if (digitalRead(BOTAO3) == HIGH) estadoBotao3 = HIGH;

  delay(100);

}