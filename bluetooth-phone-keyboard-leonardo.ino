//BT = BlueTooth

#include <SoftwareSerial.h>   //Librairie pour créer une nouvelle connexion série a 9600 baud = librairie to create a new Serial connexion at 9600 baud
#include <KeyboardFR.h>

SoftwareSerial BTSerial(10, 11); // RX | TX  = > BT-TX=10 BT-RX=11

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter a command:");
  BTSerial.begin(9600);  // HC-05 9600 baud 
  KeyboardFR.begin();
}

void loop()
{
  String message;                       
    while (BTSerial.available()){     // Boucle de lecture sur le BT = Reading BT 
    message = BTSerial.readString();  // Lecture du message envoyé par le BT = Read message send by BT 
      Serial.print(message);          // Ecriture du message dans le serial usb = write in serial usb
      BTSerial.print(message);        // Ecriture du message dans le serial BT = write in serial BT
    }

      if(message.length()>1){
        if(message=="test\r\n"){
          BTSerial.println("CREDIT:Théo PERNEL (Dieu)");
          BTSerial.println("************");
          BTSerial.println("connection réussie, prêt a écrire...");
        }

        //touches clavier = keyboard keys**************************************
        
        else if(message=="release\r\n"){
          KeyboardFR.releaseAll();
          }
        else if(message=="enter\r\n"){
          KeyboardFR.press(KEY_RETURN);
        }
        else if(message=="backspace\r\n"){
          KeyboardFR.press(KEY_BACKSPACE);
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
        }
        else if(message=="alt\r\n"){
          KeyboardFR.press(KEY_LEFT_ALT);
        }
         else if(message=="tab\r\n"){
          KeyboardFR.press(KEY_TAB);
        }
         else if(message=="1tab\r\n"){
          KeyboardFR.press(KEY_TAB);
          KeyboardFR.releaseAll();
        }
        else if(message=="windows\r\n"){
          KeyboardFR.press(KEY_LEFT_GUI);
        }
        else if(message=="1windows\r\n"){
          KeyboardFR.press(KEY_LEFT_GUI);
          KeyboardFR.releaseAll();
        }
        else if(message=="shift\r\n"){
          KeyboardFR.press(KEY_LEFT_SHIFT);
        }
        else if(message=="esc\r\n"){
          KeyboardFR.press(KEY_ESC);
        }
        else if(message=="del\r\n"){
          KeyboardFR.press(KEY_DELETE);
          KeyboardFR.releaseAll();
        }
        else if(message=="up\r\n"){
          KeyboardFR.press(KEY_UP_ARROW);
          KeyboardFR.releaseAll();
        }
        else if(message=="down\r\n"){
          KeyboardFR.press(KEY_DOWN_ARROW);
          KeyboardFR.releaseAll();
        }
        else if(message=="left\r\n"){
          KeyboardFR.press(KEY_LEFT_ARROW);
          KeyboardFR.releaseAll();
        }
        else if(message=="right\r\n"){
          KeyboardFR.press(KEY_RIGHT_ARROW);
          KeyboardFR.releaseAll();
        }

        //raccourcis clavier = keyboard shortcuts *********************************
        
        else if(message=="alt f4\r\n"){
          KeyboardFR.press(KEY_LEFT_ALT);
          KeyboardFR.press(KEY_F4);
          KeyboardFR.releaseAll();
        }
        else if(message=="alt d\r\n"){
          KeyboardFR.press(KEY_LEFT_ALT);
          KeyboardFR.press('d');
          KeyboardFR.releaseAll();
        }
        else if(message=="alt tab\r\n"){
          KeyboardFR.press(KEY_LEFT_ALT);
          KeyboardFR.press(KEY_TAB);
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl c\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
          KeyboardFR.press('c');
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl a\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
          KeyboardFR.press('a');
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl v\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
          KeyboardFR.press('v');
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl w\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
          KeyboardFR.press('w');
          KeyboardFR.releaseAll();
        }
        else if(message=="ctrl t\r\n"){
          KeyboardFR.press(KEY_LEFT_CTRL);
          KeyboardFR.press('t');
          KeyboardFR.releaseAll();
        }
        
        else{
           KeyboardFR.print(message);
        }
      }
      else if(message.length()==1){
        KeyboardFR.press('message');
      }
    delay(100);
}
