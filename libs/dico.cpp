using namespace std;

class sw_dico{
    public :
    const string arr[7] = {"quit","create","choose","add","remove","clean","actif"};
    string dico_actif;

    int ch_dico(string cmd){
        int compt = 0;
        for(const string& i : arr){
            if(cmd == i){
                return compt;
            }
            compt++;
        }
        return 404;
    }
};

void ges_dico(){
    string cmd;
    sw_dico dico;
    dico.dico_actif = "";
    fstream fichier;
    int c = 0;
    cout << "|| App Dico ||" << endl;
    do{
        cout << "=>";
        cin >> cmd;
        c = dico.ch_dico(cmd);
        switch (c){
            case 0:
                cout << "Fermeture de l'application." << endl;
                break;
            case 1:{
                string name,ext;
                cout << "Nom du dictionnaire : ";
                cin >> name;
                cout << "Format du dictionnaire : ";
                cin >> ext;
                cout << endl;
                string concat = name + "." + ext;
                make_dico(concat);
            }
                break;
            case 2:{
                string name;
                cout << "Veuillez renseigner le nom du dictionnaire : ";
                cin >> name;
                if(search(name)){
                    dico.dico_actif = name;
                    fichier.open(name);
                }
                else{
                    cout << "Le dictionnaire est introuvable." << endl;
                }
            }
                break;
            case 3:{
                if(dico.dico_actif != ""){
                    string word;
                    cout << "Mot à ajouter : ";
                    cin >> word;
                    add_word(dico.dico_actif,word);
                }
                else{
                    cout << "Pas de dictionnaire sélectionné." << endl;
                }
            }
                break;
            case 4:
                if(dico.dico_actif != ""){
                    string word;
                    cout << "Mot à supprimer : ";
                    cin >> word;
                    rem_word(dico.dico_actif,word);
                }
                else{
                    cout << "Pas de dictionnaire sélectionné." << endl;
                }
                break;
            case 5:
                if (dico.dico_actif != ""){
                    clean(dico.dico_actif);
                }
                else{
                    cout << "Aucun dictionnaire n'est sélectionné." << endl;
                }
                break;
            case 6:
                if (dico.dico_actif != ""){
                    cout << "Dictionnaire sélectionné : " << dico.dico_actif << endl;
                }
                else{
                    cout << "Aucun dictionnaire n'est sélectionné." << endl;
                }
                break;   
        }
    }
    while(c!=0);
}

