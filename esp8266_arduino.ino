//author: Arun Kumar Mukkamla
//co-author: Akhil Kumar Vannala
//Date: 15-09-2017
//Vehicle Accident Detection and Vehicle Maintenance Using Arduino Uno and ESP8266.

String apikey ="";//Enter Your ThinkSpeak API Key
const char* server = "api.thingspeak.com";

const char* ssid="";//Enter Your WiFi ssid
const char* password="";//Enter Your WiFi password 
char res[130];
int led = 13;
int led1 = 12;
//Check Function For Checking The ESP8266 Is Connected To The Internet Or Not.
char check(char* ex,int timeout)
{
  int i=0;
  int j = 0,k=0;
                                            while (1)
                                            {
                                              sl:
                                                            if(Serial.available() > 0)
                                                            {
                                                              res[i] = Serial.read();
                                                                            if(res[i] == 0x0a || res[i]=='>' || i == 100)
                                                                            {
                                                                              i++;
                                                                              res[i] = 0;
                                                                              break;
                                                                            }
                                                              i++;
                                                            }
                                              j++;
                                              if(j == 30000)
                                              {
                                                k++;
                                                //Serial.println("kk");
                                                j = 0;  
                                              }
                                              if(k > timeout)
                                              {
                                               // Serial.println("timeout");
                                                return 1;
                                               }
                                            }//while 1
  if(!strncmp(ex,res,strlen(ex)))
  {
    //Serial.println("ok..");
    return 0;
   }
  else
  {
   // Serial.print("Wrong  ");
   // Serial.println(res);
    i=0;
    goto sl;
   }
}
void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
} 

char buff[200];
 float sen1=0,sen2=0,sen3=0;
 //void setup
void setup() {

  char ret; 
  
   pinMode(led, OUTPUT);   
   pinMode(led1, OUTPUT);  
   digitalWrite(led, LOW);      
   digitalWrite(led1, LOW);   
   Serial.begin(115200);

    sen1 = analogRead(A0);
    sen2 = analogRead(A1);
    sen3 = analogRead(A2);//One Can Enter More no.of Sensors
    delay(3000);
    serialFlush();
   
   st:
   digitalWrite(led,LOW);
   Serial.println("ATE0");//AT command for echoing a signal to check the wifi device.
   ret = check((char*)"OK",50);
   Serial.println("AT");//AT command for a general test
   ret = check((char*)"OK",50);
   
   if(ret != 0){
    delay(100);
    digitalWrite(led,HIGH);
    delay(100);
    //digitalWrite(led1, HIGH);delay(500);digitalWrite(led1, LOW);
    goto st;
   }
                                                                             
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    Serial.println("AT+CWMODE = 1");//AT command for puting the modem in wifi mode 
                                   //and Query 1 indicates the esp8266 is in  client mode or station mode.
    ret  = check((char*)"OK",50);
    
    connectagain:
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    serialFlush();
    Serial.print("AT+CWJAP=\"");//AT Command Used To Connect to AP
                                //The SSID and Password Queries are Given to The WiFi Module. 
    Serial.print(ssid);
    Serial.print("\",\"");
    Serial.print(password);
    Serial.println("\"");
    
    if(check((char*)"OK",300)){
      goto connectagain;
    }
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    Serial.println("AT+CIPMUX=1");//this AT command is used to start a multi-IP connection
    digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
    digitalWrite(led1, HIGH);//delay(500);digitalWrite(led1, LOW);
}

void loop() {
  serialFlush();
  Serial.println("AT+CIPSTART=4,\"TCP\",\"184.106.153.149\",80");//This AT Command Is Used To Set Up Whether TCP or UDP Connection
                                                                 //The Queries Given To This Command Are Type of Connection, IP Address, and Port Number

  if(!check((char*)"Linked",200))
  {
      digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
      serialFlush();
      Serial.println("AT+CIPSEND=4,76");//This AT Command Is Used To Send The Data Through WiFi Chip To The Earlier Mentioned IP Address
                                       //The 4 Is The Connection Id And 76 Is The Length Of The Data
      if(!check((char*)">",50))
      {
          digitalWrite(led, HIGH);delay(500);digitalWrite(led, LOW);
          sen2 = analogRead(A1)/2;
          
          
          serialFlush();
        //Start of the sensor data upload code
          Serial.print("GET /update?api_key=QF0QD6JZ6WKNRFQY");//API Key of The ThingSpeak Cloud Goes Here
          sprintf(buff,"field1=%04u",sen2);//The Field Data of The Thingspeak Cloud Account Goes Here 
          Serial.print(buff);
          Serial.println("");
        //End of the sensor data upload code
        //This block represents the data upload of the sensor 2, You can repeat this block accordingly, based on no.of sensors. 
          if(!check((char*)"OK",200))
          {
              digitalWrite(led1, HIGH);delay(500);digitalWrite(led1, LOW);
              
              Serial.println("AT+CIPCLOSE");// This AT Command Is Used For Closing The TCP/IP Connection
          }
            
      }
     
    }
  
  

}
