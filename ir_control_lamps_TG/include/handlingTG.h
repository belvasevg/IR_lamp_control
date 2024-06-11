#include <IRremote.h>

#include "portsConf.h"
#include "tgBot.h"
#include "lamp_control.cpp"


IRsend irsend(IR_SIGNAL);
LampControl lamp;

long signalToLamp;

unsigned long counters[10] {0};

void handleNewMessages(int numNewMessages);