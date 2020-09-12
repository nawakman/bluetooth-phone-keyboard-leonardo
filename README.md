# bluetooth-phone-keyboard-leonardo

Hello, how are you, i'm under the water :)

Soooo,this is a "text and shortcut transmitter from a phone to a computer based in a bluetooth connexion" working on a Arduino leonardo connected with RX TX to a HC-06 bluetooth module

Working principle: the phone send ASCII characters to the HC-06, that himself transmit to the leonardo the characters. Then the leonardo decide if it's a single keystroke, a shortcut or a text ( for example if it receive "altf4", i coded a line to detect it as a shortcut so beeem, it make alt+F4 on your keyboard )

I'm French, I used a modified keyboard library to adapt to the AZERTY keyboard, feel free to change it

You can press every single key of your keyboard, you just need to add a line with selected key ( findable in the Keyboard.h library )

On your phone you just need a kind of Bluetooth terminal apllication, you can find a lot of theim on the playstore ( Android Gang AOUUUUUUUH )
