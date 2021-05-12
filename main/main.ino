#include <TroykaButton.h>
#include <QuadDisplay2.h>
#include <TroykaDHT.h>

TroykaButton btn(1);
QuadDisplay QDH(9,5,7);
QuadDisplay QDT(10,1,4);
DHT sen(0, DHT11);

 
void setup()
{
  Serial.begin(9600);
  btn.begin();
  QDH.begin();
  QDT.begin();
  sen.begin();
}
 
void loop()
{
  static bool flag = false;
 if (btn.isClick()){
    flag = !flag;
    if (flag){
        QDT.displayClear();
        QDH.displayClear();
    };
    sen.read();
    Serial.print(sen.getHumidity());
    QDH.displayHumidity(sen.getHumidity());
    Serial.print(sen.getTemperatureC());
    QDT.displayTemperatureC(sen.getTemperatureC());
  };
}
