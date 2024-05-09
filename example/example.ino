#include <PrintSerial.h>
#define PRINT_LEVEL 1

PrintSerial print;

void setup()
{
  print.begin(115200, 1); 
}

void loop()
{
  print.done("Tarefa concluída com sucesso.");
  print.log("Mensagem de log.");
  print.warning("Aviso: Algo pode estar errado.");
  print.error("Erro: Falha crítica no sistema.");
  delay(1000);
}