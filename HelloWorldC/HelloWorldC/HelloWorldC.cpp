#include <iostream>
int main()
{
    using namespace std;


    //main character
    srand(time(NULL));
    string characterName;
    int characterHPValue = 6000;


    //boss character
    string bossName = "Malenia";
    int bossHPValue = 8000;


    //boss2 character
    string boss2Name = "George";
    int boss2HPValue = 3000;

    //Game options
    int enemySelection = 0;
    int gunSelection = 0;

    //Enter character name
    cout << "Escribe el nombre de tu personaje\n";
    cin >> characterName;
    while ((bossHPValue > 0 || boss2HPValue > 0) && characterHPValue > 0) {

        //main game
        if (bossHPValue > 0) {
            int bossAttackValue = rand() % 350 + 50;
            characterHPValue = characterHPValue - bossAttackValue;
            if (characterHPValue > 0) {
                cout << "El enemigo " << bossName << " te ha dado un golpe de " << bossAttackValue << " puntos y te quedan " << characterHPValue << " puntos de vida\n";
            }
            else {
                cout << bossName << " ha acabado contigo. Game Over! \n";
            }
        }

        if (boss2HPValue > 0 && characterHPValue > 0) {
            int boss2AttackValue = rand() % 350 + 50;
            characterHPValue = characterHPValue - boss2AttackValue;
            if (characterHPValue > 0) {
                cout << "El enemigo " << boss2Name << " te ha dado un golpe de " << boss2AttackValue << " puntos y te quedan " << characterHPValue << " puntos de vida\n";
            }
            else {
                cout << boss2Name << " ha acabado contigo. Game Over! \n";
            }
        }


        //Attack to enemy
        if (characterHPValue > 0) {


            enemySelection = 0;
            //Seleccionar enemigo a atacar

            while (enemySelection <= 0 || enemySelection > 2) {
                cout << "Selecciona a que enemigo quieres atacar\n";
                if (bossHPValue > 0) {
                    cout << "Selecciona 1 si quieres atacar a " << bossName << "\n";
                }
                if (boss2HPValue > 0) {
                    cout << "Selecciona 2 si quieres atacar a " << boss2Name << "\n";
                }
                cin >> enemySelection;
                if ((enemySelection <= 0 || enemySelection > 2)) {
                    cout << "La eleccion no es correcta\n";
                }
            }


            string gun1 = "Cuchillo";
            string gun2 = "Fusil";
            string gun3 = "Lapiz";

            //Seleccionar el ataque
            if (characterHPValue > 0) {


                gunSelection = 0;

                while (gunSelection <= 0 || gunSelection > 3) {
                    cout << "Selecciona con que arma quieres atacar \n";
                    if (enemySelection > 0) {
                        cout << "Selecciona 1 si quieres atacar con " << gun1 << "\n";
                    }
                    if (enemySelection > 0) {
                        cout << "Selecciona 2 si quieres atacar con " << gun2 << "\n";
                    }
                    if (enemySelection > 0) {
                        cout << "Selecciona 3 si quieres atacar con " << gun3 << "\n";
                    }
                    cin >> gunSelection;
                    if ((gunSelection <= 0 || gunSelection > 3)) {
                        cout << "La eleccion no es correcta\n";
                    }
                }

                //Atacar al enemigo seleccionado con el ataque seleccionado
                if (enemySelection == 1 && bossHPValue > 0) {
                    int characterAttackValue = rand() % 350 + 50;
                    bossHPValue = bossHPValue - characterAttackValue;
                    if (gunSelection == 1) {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el cuchillo y le quedan " << bossHPValue << " puntos de vida\n";
                    }
                    else if (gunSelection == 2) {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el fusil y le quedan " << bossHPValue << " puntos de vida\n";
                    }
                    else {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el lapiz y le quedan " << bossHPValue << " puntos de vida\n";
                    }
                }
                else {
                    int characterAttackValue = rand() % 350 + 50;
                    boss2HPValue = boss2HPValue - characterAttackValue;
                    if (gunSelection == 1) {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el cuchillo y le quedan " << boss2HPValue << " puntos de vida\n";
                    }
                    else if (gunSelection == 2) {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el fusil y le quedan " << boss2HPValue << " puntos de vida\n";
                    }
                    else {
                        cout << "El personaje " << characterName << " ha hecho un ataque de " << characterAttackValue << " puntos con el lapiz y le quedan " << boss2HPValue << " puntos de vida\n";
                    }
                }
                /*
                int characterAttackValue = rand() % 100 + 150;
                bossHPValue = bossHPValue- characterAttackValue;
                cout << " El personaje " << characterName << " ha hecho un ataque de " << bossName << " puntos y le quedan " << bossHPValue << "puntos de vida\n";
                cout << " El personaje " << characterName << " ha hecho un ataque de " << boss2Name << " puntos y le quedan " << boss2HPValue << "puntos de vida\n";
                */
            }



        }

    }
}