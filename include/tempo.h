#pragma once



//Retorna a hora atual no formato hh:mm:ss
void hora_certa();

/*
@brief Retorna tempo no formato POSIX
@return unsigned long
*/
unsigned long timeStamp();

//Configura o servidor NTP
void setup_time();

//Atualiza o servidor NTP
void atualiza_time();

extern unsigned long epochTime;