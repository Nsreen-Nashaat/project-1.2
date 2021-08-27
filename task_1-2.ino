String mydata;
char password[100]={'m','i','a'}, *ch;
int i;
void setup() 
{
  Serial.begin(115200);
   pinMode(13, OUTPUT);
}
void loop()
{
  if(Serial.available()) 
  {
     mydata=Serial.readString();
  }
  if(mydata == password)
  {
    digitalWrite(13, HIGH);
    delay(3000);
    for(i = 0; password[i] != '\0'; i++)  //ciphing
    {
      ch = &password[i];
      if(*ch >= 'a' && *ch <= 'z'){
      *ch += 1;}

    if(*ch > 'z'){
      *ch = *ch - 'z' + 'a' - 1;
}
else if(*ch >= 'A' && *ch <= 'Z'){
*ch += 1;}

if(*ch > 'Z'){
*ch = *ch - 'Z' + 'A' - 1;
}
else if(*ch >= '0' && *ch <= '9'){
*ch += 1;}

if(*ch > '9'){
*ch = *ch - '9' + '0' - 1;
}
password[i] = *ch;
}
  }
  else 
  {
    digitalWrite(13, HIGH);
    delay(1000); 
    digitalWrite(13, LOW);
    delay(1000);
  }
  
}
