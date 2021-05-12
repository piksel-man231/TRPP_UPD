#include <QuadDisplay2.h>
#include <TroykaDHT.h>

QuadDisplay QDH(9,5,7);
DHT sen(0, DHT11);

void setup() {
  QDH.begin();
  sen.begin();
  Serial.begin(9600);
}


void loop() {ыы
  sen.read();
  Serial.print(sen.getHumidity());
  QDH.displayHumidity(sen.getHumidity());
}
