#include "handlingTG.h"

void handleNewMessages(int numNewMessages)
{
  Serial.print("Счётчик сообщений Telegram: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++)
  {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
    text.toLowerCase();
    String from_name = bot.messages[i].from_name;
    
    if (from_name == "")
      from_name = "Guest";
    if ((text == "/light") || (text == "light"))
    {
        long signalToLamp = lamp.get_signal(1);
        irsend.sendNEC(signalToLamp,32);
        counters[0]+=1;
        if (counters[0]%2==0)
        {
            bot.sendMessage(chat_id, "Лампа выключена", "");
        }
        else
        {
            bot.sendMessage(chat_id, "Лампа включена", "");
        }
    }
    if ((text == "/rgb") || (text == "rgb"))
    {
      long signalToLamp = lamp.get_signal(2);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "Включен RGB формат", "");
    }
    if ((text == "/briup") || (text == "briup"))
    {
      long signalToLamp = lamp.get_signal(3);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "Увеличена яркость", "");
    }
    if ((text == "/bridown") || (text == "bridown"))
    {
      long signalToLamp = lamp.get_signal(4);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "Уменьшена яркость", "");
    }
    if ((text == "/warm") || (text == "warm") || (text == "/rgbchange")||(text == "rgbchange"))
    {
        long signalToLamp = lamp.get_signal(5);
        irsend.sendNEC(signalToLamp,32);
        delay(300);
        if((text == "/warm") || (text == "warm"))
        {
            bot.sendMessage(chat_id, "Включен более тёплый оттенок", "");
        }
        if ((text == "/rgbchange")||(text == "rgbchange"))
        {
            bot.sendMessage(chat_id, "Смена цвета RGB", "");
        }
    }
    if ((text == "/cold") || (text == "cold") || (text == "/rgbshow")||(text == "rgbshow"))
    {
        long signalToLamp = lamp.get_signal(6);
        irsend.sendNEC(signalToLamp,32);
        delay(300);
        if((text == "/cold") || (text == "cold"))
        {
            bot.sendMessage(chat_id, "Включен более холодный оттенок", "");
        }
        if ((text == "/rgbshow")||(text == "rgbshow"))
        {
            bot.sendMessage(chat_id, "Плавное переключение режимов RGB", "");
        }
    }
    if ((text == "/change") || (text == "change"))
    {
      long signalToLamp = lamp.get_signal(7);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "Смена отображения", "");
    }
    if ((text == "/nightmode") || (text == "nightmode"))
    {
      long signalToLamp = lamp.get_signal(8);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "Ночной режим", "");
    }
    if ((text == "/halfwarm") || (text == "halfwarm"))
    {
      long signalToLamp = lamp.get_signal(9);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "50% тёплого оттенка", "");
    }
    if ((text == "/halfcold") || (text == "halfcold"))
    {
      long signalToLamp = lamp.get_signal(10);
      irsend.sendNEC(signalToLamp,32);
      delay(300);
      bot.sendMessage(chat_id, "50% холодного оттенка", "");
    }
    if ((text == "/help") || (text == "help"))
    {
        bot.sendMessage(chat_id, "Справка по командам: ", "");
        bot.sendMessage(chat_id, "Команды можно писать в любом регистре как с символом \"/\" так и без него.", "");
        bot.sendMessage(chat_id,"Для включения/выключения лампы используется light.","");
        bot.sendMessage(chat_id,"Команды стандартного режима: warm, cold, halfwarm, halfcold.","");
        bot.sendMessage(chat_id,"Команды RGB-режима: rgb, rgbchange, rgbshow.","");
        bot.sendMessage(chat_id,"Команды регулирования яркости: briup, bridown.","");
        bot.sendMessage(chat_id,"Команда смены отображения: change.","");
        bot.sendMessage(chat_id,"Команда ночного режима: nightmode.","");        
    }

    if ((text == "/start") || (text == "start"))
    {
      bot.sendMessage(chat_id, "Привет, " + from_name + "!", "");
      bot.sendMessage(chat_id, "Я контроллер семейства ESP32.", "");
      bot.sendMessage(chat_id, "Чтобы узнать как мной управлять напиши /help или help", "");
    }
  }
}