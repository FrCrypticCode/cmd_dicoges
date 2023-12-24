using namespace std;

bool search(string name){
    if(sizeof(name)==0){
        return false;
    }
    ifstream fichier(name);
    if(fichier){
        return true;
    }
    else{
        return false;
    }

}

void look_at(){
    string name;
    cout << "Chemin du fichier : ";
    cin >> name;
    cout << endl;
    bool check;
    check = search(name);
    if(check){
        cout << "Votre fichier existe." << endl;
    }
    else{
        cout << "Votre fichier n'existe pas." << endl;
    }
}

void make_dico(string name){
    ifstream fichier(name);
    if (!fichier){
        ofstream file(name);
        cout << "Dictionnnaire créé." << endl;
    }
    else{
        cout << "Un fichier du même nom existe déjà." << endl;
    }
}

void clean(string name){
    fstream fichier(name);
    string line;
    ofstream temp("temp.txt");
    while(getline(fichier,line)){
        char f = line.front();
        if(!isspace(f)){
            temp << line << endl;
        }
    }
    fichier.close();
    temp.close();
    remove(name.c_str());
    rename("temp.txt",name.c_str());
}

void add_word(string name,string word){
    fstream fichier(name);
    ofstream fichier_c("temp.txt");
    string line,index;
    index.push_back('#');
    index.push_back(word.front());
    int pos = 0;
    bool check = false;
    while(getline(fichier,line)){
        cout << word << "| Index : " << index << " | " << line << endl;
        if(line == index){
            fichier_c << line << endl << word << endl;
            check = true;
        }
        else{
            fichier_c << line << endl;
        }
        pos+= 1;
    }
    if(check == false){
        cout << "Ligne : " << pos << " Contenu : " << line << endl;
        fichier_c << index << endl << word;
    }
    fichier.close();
    fichier_c.close();
    remove(name.c_str());
    rename("temp.txt",name.c_str());
}

void rem_word(string name,string word){
    fstream fichier(name);
    string line;
    size_t found;
    int compt = 0;
    int pos = 0;
    int l;
    bool valid = false;
    while(getline(fichier,line)){
        found = line.find(word);
        l = line.size()+1;
        if(found!=std::string::npos){
            fichier.seekg(pos);
            string add;
            for(int i=0;i<line.size();i++){
                add.push_back(' ');
            }
            fichier << add << endl;
            valid = true;
        }
        pos += l;
        compt++;
    }
    fichier.close();
    if(!valid){
        cout << "Le mot n'est pas dans ce dictionnaire." << endl;
    }else{
        cout << "Nettoyage des données." << endl;
        clean(name);
    }
}