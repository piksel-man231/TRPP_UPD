#include <TroykaButton.h>

TroykaButton btn(1);
 
void setup()
{
  Serial.begin(9600);
  btn.begin();
}
 
void loop()
{
  static bool flag = false;
 if (btn.isClick()){
    flag = !flag;
    if (flag){
        QDT.clear();
        QDH.clear();
    };
  };
}
