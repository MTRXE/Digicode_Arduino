
/*  Bette Mathys
 *   CIEL 2
 *  Digicode
 *  code 1234
 *  
 *  
 *  
 *  
 *  09/09/24 : Digicode_v1: Création d'un digicode avec code prédefinies
 *  13/09/24 : Digicode_v1: Changement du mdp
 */
char CodeTableau[4];  // On initialise un tableau de 4 caractères pour stocker le code entré
char Code[4] = {0x31, 0x32, 0x33, 0x34}; // Le code correct à comparer

void saisie()
{
  
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("Entrez le code : ");
}

void loop() 
{
  // Attendre que 4 caractères soient disponibles dans le buffer
  while (Serial.available() == 0) {
    // On attend que 4 caractères soient entrés
}

  delay(100); 

  // Lis les 4 caractéres
  for (byte i = 0; i < 4; i++) {
    CodeTableau[i] = Serial.read();
  }

  // Afficher les valeurs lues 
  Serial.print("Le code : ");
  //Serial.println(CodeTableau);123
  for (byte i = 0; i < 4; i++) {
    Serial.print(CodeTableau[i]);
  }
  
  Serial.println("");

  // Vérifier si le code entré est correct
  bool codeBon = true;
    for (byte i = 0; i < 4; i++) {
      if (CodeTableau[i] != Code[i]) {
        codeBon = false;
        break;  // Si sa ne correspond pas on arrête la vérification
      }
  }

  if (codeBon) {
    Serial.println("Code Bon");
  } else {
    Serial.println("Code Mauvais");
  }

  // Vider le buffer série 
  while (Serial.available() > 0) {
    Serial.read();
  }
}
