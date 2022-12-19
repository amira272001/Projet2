#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//......................la fonction crypté CHIFFREMENT HILL............................//
string crypté(string mots_à_crypté) {
    int x, y, i, j, k, n; string s=mots_à_crypté; 
    n = 1;
    int a[10][10];// LA MATRICE
    int f = 4;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = f;
            f = f - 1;
        }
    }
    int temp = (n - s.size() % n) % n;
    for (i = 0; i < temp; i++) {
        s += 'x';
    } k = 0;
    string ans = "";
    while (k < s.size()) {
        for (i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (j = 0; j < n; j++) {
                sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
                sum = sum % 26;
            } ans += (sum + 'a');
        }   k += n;
    } return  ans;

}

// ....................fonction clean screan .......................//
void clearScean()
{
    system("cls");
}

//...............les clases..................................//

class facteur
{
public:
   
    void ajouter(string file,int id, string nom, string prenom, int age, string zone);
    void supprimer(string file,int Line_to_Erase);
    void modiffier(string file, int Line_to_Erase, string word);

private:
   static int id;// donner 
    string nom;
    string prénom;
    int age;
    string zone;



};
class habitant {
public:

    void ajouter(string file, int id, string nom, string prenom, int age, string zone);
    void supprimer(string file, int Line_to_Erase);
    void modiffier(string file,int Line_to_Erase, string word);

private:
    static int id;// donner 
    string nom;
    string prénom;
    int age;
    string zone;

};
class recommandé {

   
public:
    int idFacteur;
    int idHabitant;
    string contenu;
    string type;
    recommandé(int x, int z, string c);
    void ajouter(string file, int idFacteur, int idHabitants, string contenu, string type);
    void supprimer(string file, int Line_to_Erase);
    
};
 recommandé::recommandé(int x, int z, string c) { idFacteur = x; idHabitant = z; contenu = c; }
class coli : public recommandé {
public:
    string contenu_du_la_lettre;
  
   

};
class lettre : public recommandé {
   
public:
    string objet;
    void ajouterL(string file, int idFacteur, int idHabitants, string contenu);
    void supprimerL(string file, int Line_to_Erase);
    

};

class zone {
private:
    string zoneGeo;
public:
    zone( string z) {zoneGeo = z; }

};



//...............................

//..............................LA FONCTION AJOUTER POUR FACTEUR
void facteur::ajouter(string file,int id, string nom, string prenom, int age, string zone) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << id << ",";
        myfile << nom << ",";
        myfile << prenom << ",";
        myfile << age << ",";
        myfile << zone << " \n";

        myfile.close();

    }
}
//........................................ LA FONCTION SUPPRIMER POUR FACTEUR
void facteur::supprimer(string file,int Line_to_Erase) {
    std::string Buffer = "         \n"; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile(file); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}
//.................................
void facteur::modiffier(string file,int Line_to_Erase, string word) {
    std::string Buffer =crypté( word); //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile("a.txt"); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
};

//..............................
void habitant::ajouter(string file, int id, string nom, string prenom, int age, string zone) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << id << ",";
        myfile << nom << ",";
        myfile << prenom << ",";
        myfile << age << ",";
        myfile << zone << " \n";

        myfile.close();

    }
}
//........................................
void habitant::supprimer(string file, int Line_to_Erase) {
    std::string Buffer = "         \n"; 
    std::ifstream ReadFile(file);
    if (ReadFile) 
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) 
        {
            Line++;
            if (Line != Line_to_Erase) 
                Buffer += line + "\n"; 
        }
    }
    ReadFile.close(); 

    std::ofstream WriteFile(file); 
    WriteFile << Buffer; 
    WriteFile.close(); 
}
//.................................
void habitant::modiffier(string file,int Line_to_Erase, string word) {
    std::string Buffer = crypté(word); //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile("a.txt"); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
};
//..........................................................................................................................
void recommandé::ajouter(string file, int idFacteur,int idHabitant, string zone, string type) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << idFacteur << ",";
        myfile << idHabitant << ",";
        myfile << type << ",";
        myfile << contenu << " \n";


        myfile.close();

    }
}
//........................................
void recommandé::supprimer(string file, int Line_to_Erase) {
    std::string Buffer = "         \n"; 
    std::ifstream ReadFile(file);
    if (ReadFile)
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) 
        {
            Line++;
            if (Line != Line_to_Erase) 
                Buffer += line + "\n"; 
        }
    }
    ReadFile.close(); 

    std::ofstream WriteFile(file); 
    WriteFile << Buffer; 
    WriteFile.close(); 
}
//.................................



//.................................

// ......................... Main..........................................//

int main() {
    // IL FAUT D4ABORD CREE DES FICHIERS TEXT POUR CHAQUE CLASSE
    // la stricture de fichier et  id,nom,prenom,age,zone 

    int val, age, id, i; string fileName, nom, prenom, zone, mod, filehabitant, filerecommandé; facteur fac1; habitant hab1; int idfac;
    int v;
    cout << "enter un fichier pour la table facteur sous la forme le_nom_du_fichier.txt ( base de donne)";
    cin >> fileName;  
    cout << "enter un fichier pour la table habitant sous la forme le_nom_du_fichier.txt ( base de donne)";
    cin >> filehabitant; 
    cout << "enter un fichier pour la table recommandE sous la forme le_nom_du_fichier.txt ( base de donne)";
    cin >> filerecommandé;  clearScean();


    cout << "pour ajouter un facteur cliquer sur : 1, un habitant : 2";
    cin >> val;
    switch (val) {
    case 1:

        cout << "enter le nom , prEnom , age ,id, nom du zone ";
        cin >> nom >> prenom >> age >> id >> zone;
        fac1.ajouter(fileName, id, crypté(nom), crypté(prenom), age, crypté(zone));
        cout << "pour supprimer un facteur cliquer sur:1 ou modifier un facteur cliquer sur:2 ET :0 pour default";
        cin >> val;
        switch (val) {
        case 1:

            cout << "enter le ID (c'est le numero de la ligne) de facteur qui tu veut le supprimer ";
            cin >> i;
            fac1.supprimer(fileName, i);
            break;
        case 2:
            cout << "enter le id de facteur qui tu veut le modifier et tout les informations nom,prenom,age,id,nom du zone(les info separe par ,) ";
            cin >> i >> mod;
            fac1.modiffier(fileName,i, mod);

            break;

        }



        break;
       case 2:
        cout << "enter le nom , prenom , age ,id, nom du zone ";
        cin >> nom >> prenom >> age >> id >> zone;
        hab1.ajouter(filehabitant, id, crypté(nom), crypté(prenom), age, crypté(zone));
        int vv;
        cout << "voulez vous ajouter un coli :1 OU une lettre :2";
        cin >> vv;
            if (vv == 1)
            {
                cout << "donner id de facteur etl'objet"; cin >> idfac >> nom;
                recommandé c(idfac, id, nom); c.ajouter(filerecommandé, idfac, id, crypté(nom), "coli"); 
                cout << "cliquer sur 1 ou 0 pour default"; cin >> v;
                if (v== 1)
                {


                    cout << "pour supprimer un coli entrer la ligne cliquer sur1 ou 0 pour default"; cin >> i;
                    c.supprimer(filerecommandé, i);
                }

            }; if (vv == 2) {
                cout << "donner id de facteur et l'objet"; cin >> idfac >> nom;
                recommandé l(idfac, id, nom); l.ajouter(filerecommandé, idfac, id, crypté(nom), "lettre");
                cout << "cliquer sur 1 ou 0 pour default"; cin >> v;
                if (v == 1)
                {
                    cout << "pour supprimer une lettre entrer la ligne  "; cin >> i;
                    l.supprimer(filerecommandé, i);
                }
            }
            
            cout << "pour supprimer un habitant cliquer sur:1 ou modifier un habitant cliquer sur:2 et :0 default";
            cin >> val;
            switch (val) {
            case 1:

                cout << "enter le ID (c'est le numero de la ligne) de habitant qui tu veut le supprimer ";
                cin >> i;
                hab1.supprimer(filehabitant, i);
                break;
            case 2:
                cout << "enter le id d'habitant qui tu veut le modifier et tout les informations nom,prénom,age,id,nom du zone(les info separe par ,) ";
                cin >> i >> mod;
                hab1.modiffier(filehabitant,i, mod);

                break;
            }

        break;


    }
    clearScean();

    

}