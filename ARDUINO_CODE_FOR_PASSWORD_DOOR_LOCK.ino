#include<LiquidCrystal.h>
#include<Servo.h>
    LiquidCrystal lcd(5,4,3,2,1,0);
    Servo myservo;
    void setup()
    {
    lcd.begin(16,2);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(13,INPUT);
    pinMode(10,INPUT);
    pinMode(11,INPUT);
    pinMode(12,INPUT);
    myservo.attach(9);
    lcd.setCursor(0,0);
    lcd.print("Enter Pass:");
    }
    int pos=8;
    int col[3]={8,7,6};
    int row[4]={12,11,10,13};
    char button[4][3]={'1','2','3',
    '4','5','6',
    '7','8','9',
    '*','0','#'};
    int btnstate[4][3],lst_btnstate[4][3]={1,1,1,1,1,1,1,1,1,1,1,1};
    int row_num,col_num,btn_press=0,match;
    char pwd[4];
    char true_pwd[4]={'1','2','3','4'};
    char ch;
    char keypad()
    {
    for(col_num=0;col_num
    <3;col_num++)
                  {
                  digitalWrite(col[col_num],HIGH);
                  }
                  for(col_num=0;col_num<3;col_num++)
    {
    digitalWrite(col[col_num],LOW);
    for(row_num=0;row_num
    <4;row_num++)
                  {
                  btnstate[row_num][col_num]=digitalRead(row[row_num]);
                  if((btnstate[row_num][col_num]==0)&&(btnstate[row_num][col_num]!=lst_btnstate[row_num][col_num]))
                  {
                  return(button[row_num][col_num]);
                  }
                  }
                  digitalWrite(col[col_num],HIGH);        // to make the column high
                  }
                  return('a');                            //it will be operated only if above written return statement was                        
                  }
                  void loop()
                  {
                  lcd.display();
                  ch=keypad();
                  if(ch!='a')                             //if button is pressed
                  {
                  lcd.print(ch);
                  pwd[btn_press]=ch;                      //storing the pressed number in pwd array for further 
                                                          //matching with the true_pwd array containing the true password
                  btn_press++;
                  delay(100);                             //provinding delay for debouncing of switch
                  }
                  if(btn_press==4)                        //if four times button has been pressed i.e. four numbers have been pressed
                  {
                  delay(300);                             // providing delay so that pressed numbers remain visible for some time on LCD
                  for(btn_press=0;btn_press<4;btn_press++)
    {
    if(pwd[btn_press]!=true_pwd[btn_press])
    {
    match=0;
    break;
    }
    else
    {
    match=1;
    }
    }
    if(match==1)
    {
    lcd.setCursor(0,0);
    lcd.print("----WELCOME----");
    delay(500);
    btn_press=0;
    lcd.setCursor(0,0);
    lcd.print("                                  ");
    lcd.setCursor(0,1);
    lcd.print("                           ");
    lcd.setCursor(0,0);
    lcd.print("door is open");
    for(pos=8;pos
    <=90;pos++)
               {
               myservo.write(pos);
               delay(10);
               }
               delay(5000);
               lcd.clear();
               lcd.print("Enter Pass:");
               for(pos=90;pos>=8;pos--)
      {
      myservo.write(pos);
      delay(10);
      }
      }
      else
      {
      lcd.setCursor(0,0);
      lcd.print("You are not the");
      lcd.setCursor(0,1);
      lcd.print("right user");
      delay(500);
      btn_press=0;
      lcd.setCursor(0,0);
      lcd.print("                             ");
      lcd.setCursor(0,1);
      lcd.print("                           ");
      lcd.setCursor(0,0);
      lcd.print("Enter Pass:");
      }
      }
      digitalWrite(col[col_num],HIGH);                      //to make the column high, as earlier 
                                                             // written same statement will not be executed when 
                                                             //return[row_num][col_num] satement is executed
      for(col_num=0;col_num
      <3;col_num++)
                    {
                    for(row_num=0;row_num<4;row_num++)
      {
      lst_btnstate[row_num][col_num]=btnstate[row_num][col_num];}}}

