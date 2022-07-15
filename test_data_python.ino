byte HOR[4] = {0x09,0x03,0x06,0x0C};    // Matriz dos bytes das Fases do Motor - sentido Horário Full Step
byte AHO[4] = {0x0C,0x06,0x03,0x09};    // Matriz dos bytes das Fases do Motor - sentido Anti-Horário Full Step
int atraso_fase = 2 ;                   // Intervalo de tempo entre as fases em milisegundos - min 2 para Full Step 
int x;
int intervalo = 1000;            // Intervalo de tempo entre os movimentos do motor em ms
void Motor_AHO()                    // Movimento no sentido anti-horário 
{
  for(int i = 0; i < 1024; i++)      // incrementa o contador i de 0 a 511 - uma volta
  
    for(int j = 0; j < 4; j++)      // incrementa o contador j de 0 a 3 
    {
      PORTB = AHO[j];               // Carrega bytes da Matriz AHO na Porta B 
      delay (atraso_fase);          // Atraso de tempo entre as fases em milisegundos
    }    
}
void Motor_HOR()                    // Movimento no sentido horário 
{
  for(int i = 0; i < 1024; i++)      // incrementa o contador i de 0 a 511 - uma volta
  
    for(int j = 0; j < 4; j++)      // incrementa o contador j de 0 a 3 
    {
      PORTB = HOR[j];               // Carrega bytes da Matriz HOR na Porta B 
      delay (atraso_fase);          // Atraso de tempo entre as fases em milisegundos
    }
}
void setup()
{
  DDRB = 0x0F;           // Configura Portas D08,D09,D10 e D11 como saída 
  PORTB = 0x00;          // Reset dos bits da Porta B (D08 a D15) 
  Serial.begin(115200);
  Serial.setTimeout(1);

}
void loop()
{
 while (!Serial.available());
 x = Serial.readString().toInt();
 if (x == 2){
   Motor_AHO();           // Gira motor no sentido Anti-Horário 
   delay (intervalo);     // Atraso em milisegundos 
   Motor_HOR();           // Gira motor no sentido Horário 
   delay (intervalo);     // Atraso em milisegundos 
  }


}
