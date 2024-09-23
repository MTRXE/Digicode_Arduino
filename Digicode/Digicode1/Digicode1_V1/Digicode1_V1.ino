/*    
 *     Bette.Mathys
 *     Digicode_V1
 *     
 *     mise en place d'un digicode avec en code 1234
 *    
 *     port Serial
 *          
 *     05/09/2024 Chrono1_V1: création d'un digicode 
 */

char CodeRecu = 0; 
/*char Code = 0x31, 0x32, 0x33, 0x34;*/

void setup() {
  Serial.begin(9600); 
1
}

void loop() {
  
   while (Serial.available() == 4) {
    
    CodeRecu = Serial.read();
    Serial.print("Recu: ");
    Serial.println(CodeRecu, HEX);
   }
   
}
