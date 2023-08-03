#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String f_url = "https://s-m.com.sa/f.html";
const String b_url = "https://s-m.com.sa/b.html";
const String r_url = "https://s-m.com.sa/r.html";
const String l_url = "https://s-m.com.sa/l.html";
const String s_url = "https://s-m.com.sa/s.html";

const int blue_forward_ledpin = 2;
const int green_backward_ledpin = 4;
const int orange_right_ledpin = 5;
const int yellow_left_ledpin = 15;
const int purple_stop_ledpin = 18;

const String url = r_url;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");

  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) 
  {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println();
    Serial.println(payload);
  }
  else 
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }

    if (url == f_url) 
    {
      digitalWrite(blue_forward_ledpin, HIGH);
      pinMode(blue_forward_ledpin, OUTPUT);
    } 
    else if (url == b_url) 
    {
      digitalWrite(green_backward_ledpin, HIGH);
      pinMode(green_backward_ledpin, OUTPUT);
    } 
    else if (url == r_url) 
    {
      digitalWrite(orange_right_ledpin, HIGH);
      pinMode(orange_right_ledpin, OUTPUT);
    } 
    else if (url == l_url) 
    {
      digitalWrite(yellow_left_ledpin, HIGH);
      pinMode(yellow_left_ledpin, OUTPUT);
    } 
    else if (url == s_url) 
    {
      digitalWrite(purple_stop_ledpin, HIGH);
      pinMode(purple_stop_ledpin, OUTPUT);
    }
}

void loop() 
{
  delay(100);
}