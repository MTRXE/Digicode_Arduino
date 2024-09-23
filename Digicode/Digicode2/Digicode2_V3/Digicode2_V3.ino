
/*  Bette Mathys
 *   CIEL 2
 *  Digicode
 *  code 1234
 *  
 *  
 *  
 *  
 *  09/09/24 : Digicode_v1: Création d'un digicode avec code prédefinies
 *  13/09/24 : Digicode_v: Changement du mdp
 */
// Déclaration

char CodeTableau[4] = {0x31, 0x32, 0x33, 0x34}; // Code initial
char Code[4]; // Code entré par l'utilisateur
bool CodeBon; // Variable pour vérifier si le code est correct

void SaisieCode() {
  // Compare le code entré avec le code défini dans le programme
  CodeBon = true;
  for (byte i = 0; i < 4; i++) {
    if (Code[i] != CodeTableau[i]) {
      CodeBon = false;
      break;
    }
  }
}

void Menu() {
  Serial.println("Menu:");
  Serial.println("1 : Vérification");
  Serial.println("2 : Modification");
  Serial.println("3 : Exit");

}

void CodeVerifs() {

  Serial.println("Entrez le code (4 chiffres) : ");
  while (Serial.available() < 4) {
    // Attend que l'utilisateur entre 4 chiffres
  }
  delay(100);

  // Lit les 4 caractères du code entré
  for (byte i = 0; i < 4; i++) {
    Code[i] = Serial.read();
  }


  Serial.print("Le code : ");
  Serial.println(CodeTableau);
  for (byte i = 0; i < 4; i++) {
    Serial.print(CodeTableau[i]);
  }
  
  Serial.println("");

  SaisieCode();

  delay(3000);

  if (CodeBon) {
    Serial.println("Code Bon");
  } else {
    Serial.println("Code incorrect");
  }
}

void CodeModifs() {
  Serial.println("Entrez le nouveau code (4 chiffres) : ");
  while (Serial.available() < 4) {
    // Attend que l'utilisateur entre 4 chiffres
  }
  delay(100);

  // Lit les 4 caractères du nouveau code
  for (byte i = 0; i < 4; i++) {
    CodeTableau[i] = Serial.read();
  }

  Serial.print("Nouveau code: ");
  for (byte i = 0; i < 4; i++) {
    Serial.print(CodeTableau[i]);
  }
  Serial.println();
}
void setup() {
  Serial.begin(9600);
  Menu(); // Affiche le menu principal au démarrage
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Lit la commande

    switch (command) {
      case '1':
        CodeVerifs(); // Appelle la fonction pour vérifier le code
        break;
        
      case '2':
        CodeModifs(); // Appelle la fonction pour modifier le code
        break;

      case '3':
        Serial.println("Retour au menu principal...");
        Menu(); // Affiche le menu principal
        break;

      default:
        Serial.println("Commande non reconnue. Entrez '1' vérifier le code, '2' modifier le code, '3' quitter.");
        break;
    }
    
    // Réinitialise le buffer Serial
    while (Serial.available() > 0) {
      Serial.read();
    }

    delay(2000);
  }
}
