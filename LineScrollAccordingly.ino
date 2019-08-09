                                              //--------------- LCD class Header ---------------//

#include <LiquidCrystal.h>

                                              //--------------- Circut Pins of LCD ---------------//

LiquidCrystal lcd(1,2,4,5,6,7);

                                              //--------------- 16x2 LCD ---------------//

int screenWidth = 16;
int screenHeight = 2;

                                              //--------------- Button and Counter ---------------//

int count = 1;
int button1 = 9;
int button2 = 10;

                                              //--------------- Button Values setup in Boolean ---------------//

boolean button1_last_up = LOW;          
boolean button1_current_up=LOW;            
boolean button2_last_down = LOW;
boolean button2_current_down = LOW;

                                              //--------------- String of Instructions to Display ---------------//

String line1 = "We have Openings for Developers ";
String line2 = "Step In Technologies Gandhinagar";
String line3 = "Opening for Android Developer";
String line4 = "Opening for IoT Developer";
String line5 = "Opening for PHP Developer";
String line6 = "Opening for HR";
String Common = "Fresher/Experienced";

                                              //--------------- Reference flags ---------------//

int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

                                              //--------------- Array of Strings From 0 to 6 (.i.e  line[0],line[1],line[2],line[3],line[4],line[5],line[6]) ---------------//

String line[] = { line1,
                  line2,
                  line3,
                  line4,
                  line5,
                  line6,
                  Common
               };


                                              //--------------- Boolean Value Setup Detail for Debounce  ---------------//

boolean debounce(boolean last, int pin)
{
    boolean current = digitalRead(pin);
    if (last != current)
    {
      delay(10);
      current = digitalRead(pin);
    }
    return current;
}
               
                                              //---------------Initialization of the Setup ---------------//
                                              
void setup() 
{
   pinMode(button1,INPUT);
   pinMode(button2,INPUT);
   lcd.begin(screenWidth,screenHeight);
   //Serial.begin(9600);
}

                                              //--------------- Loop Condition ---------------//

void loop() 
{  
      button1_current_up = debounce(button1_last_up, button1);         //Debounce for Up button
      button2_current_down = debounce(button2_last_down, button2);   //Debounce for Down button

      if (button1_last_up== LOW && button1_current_up == HIGH)
      { 
          lcd.clear();                     //When page is changed, lcd clear to print new page   
          if( count < 5 )
          {                                              //Page counter never higher than 4(total of pages)
            count++;                                              //Page up
          //  Serial.println(count);
          }
          else
          {
            count = 1;                                              //return to page 0
          }
      }
      
      button1_last_up = button1_current_up;
              
      if (button2_last_down == LOW && button2_current_down == HIGH)
      {
          lcd.clear();                                              //-------------------   When page is changed, lcd clear to print new page   ----------------------//    
          if( count > 1 )
          {                                              //-----------   Page counter never lower than 1 (total of pages)   -----------//
            count--; 
        //    Serial.println(count);//Page down 
          }
          else
          {
            count= 6;                                              //---------------------   return to page 4   ---------------------------//
          }
       }
        
       button2_last_down = button2_current_down;

      if( count == 1 )
      {
      //    Serial.println("Step In Detail");
          StepInTechnology();
          delay(1000);
      }
       
      else if( count == 2 )
      {
       //   Serial.println("Android Detail");
          Android();
          delay(1000);
      } 
       
      else if( count == 3 )
      {
    //      Serial.println("IoT Detail");
          IoT();
          delay(1000);
      } 
       
      else if( count == 4 )
      {
     //     Serial.println("PHP Detail");
          PHP();
          delay(1000);
      } 
       
      else if( count == 5 )
      {
      //    Serial.println("HR Detail");
          HR();
          delay(1000);
      }        
        lcd.clear();
}

                                              //--------------- Android Detail Display ---------------//

void Android()
{
  lcd.setCursor(scrollCursor, 0);
  
  lcd.print(line[2].substring(stringStart,stringStop));
  delay(200);
  
  lcd.setCursor(0, 1);
  lcd.print(line[6]);//.substring(stringStart,stringStop));
  delay(700);
//  displayFunc();
  
  lcd.clear();
  
  if(stringStart == 0 && scrollCursor > 0)
  {
      scrollCursor--;
      stringStop++;
  }
  else if (stringStart == stringStop)
  {
      stringStart = stringStop = 0;
      scrollCursor = screenWidth;
  } 
  else if (stringStop == line[2].length() && scrollCursor == 0)
  {
      stringStart++;
  } 
  else 
  {
      stringStart++;
      stringStop++;
  }
  
}

                                              //--------------- IoT Detail Display ---------------//

void IoT()
{
    lcd.setCursor(scrollCursor, 0);
    
    lcd.print(line[3].substring(stringStart,stringStop));
    delay(200);
    
    lcd.setCursor(0, 1);
    lcd.print(line[6]);//.substring(stringStart,stringStop));
    delay(700);
//    displayFunc();

    lcd.clear();
    
    if(stringStart == 0 && scrollCursor > 0)
    {
        scrollCursor--;
        stringStop++;
    } 
    else if (stringStart == stringStop)
    {
        stringStart = stringStop = 0;
        scrollCursor = screenWidth;
    } 
    else if (stringStop == line[3].length() && scrollCursor == 0)
    {
        stringStart++;
    } 
    else 
    {
        stringStart++;
        stringStop++;
    }
    
}

                                              //--------------- PHP Detail Display ---------------//

void PHP()
{
    lcd.setCursor(scrollCursor, 0);
    
    lcd.print(line[4].substring(stringStart,stringStop));
    delay(200);
    
    lcd.setCursor(0, 1);
    lcd.print(line[6]);//.substring(stringStart,stringStop));
    delay(700);
//    displayFunc();

    lcd.clear();
    
    if(stringStart == 0 && scrollCursor > 0)
    {
        scrollCursor--;
        stringStop++;
    } 
    else if (stringStart == stringStop)
    {
        stringStart = stringStop = 0;
        scrollCursor = screenWidth;
    }
    else if (stringStop == line[4].length() && scrollCursor == 0) 
    {
        stringStart++;
    }
    else 
    {
        stringStart++;
        stringStop++;
    }
    
}

                                              //--------------- HR Detail Display ---------------//

void HR()
{
  lcd.setCursor(scrollCursor, 0);
  
  lcd.print(line[5].substring(stringStart,stringStop));
  delay(200);
  
  lcd.setCursor(0, 1);
  lcd.print(line[6]);//.substring(stringStart,stringStop));
  delay(700);
//  displayFunc();
  
  lcd.clear();
  
  if(stringStart == 0 && scrollCursor > 0)
  {
      scrollCursor--;
      stringStop++;
  } 
  else if (stringStart == stringStop)
  {
      stringStart = stringStop = 0;
      scrollCursor = screenWidth;
  } 
  else if (stringStop == line[5].length() && scrollCursor == 0) 
  {
      stringStart++;
  } 
  else 
  {
      stringStart++;
      stringStop++;
  }
  
}

                                              //--------------- Display Detail ---------------//

//void displayFunc()
//{
//    lcd.display();
//    delay(700);
//    lcd.noDisplay();
//    delay(100);
//    
//}

                                              //--------------- Step In Technology Detail Display ---------------//

void StepInTechnology()
{
      lcd.setCursor(scrollCursor, 0);
      
      lcd.print(line[0].substring(stringStart,stringStop));
      delay(300);
      
      lcd.setCursor(0, 1);
      lcd.print(line[1].substring(stringStart,stringStop));
      delay(700);
//      displayFunc();
      lcd.clear();
      
      if(stringStart == 0 && scrollCursor > 0)
      {
          scrollCursor--;
          stringStop++;
      } 
      else if (stringStart == stringStop)
      {
          stringStart = stringStop = 0;
          scrollCursor = screenWidth;
      }
      else if (stringStop == line[0].length() && scrollCursor == 0) 
      {
          stringStart++;
      } 
      else
      {
          stringStart++;
          stringStop++;
      }
      
}
