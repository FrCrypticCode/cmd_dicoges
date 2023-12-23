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
    vector<string> temp;
    while(getline(fichier,line)){
        char f = line.front();
        if(!isspace(f)){
            temp.push_back(line);
        }
    }
    fichier.close();
    ofstream file(name);
    for(string i:temp){
        file << i << endl;
    }
}

void add_word(string name,string word){
    ifstream fichier(name);
    vector<string> file ;
    string line;
    bool check = false;
    char index = word.front();
    while (getline(fichier,line)){
        file.push_back(line);
        int pos = line.find('#');
        if (pos !=-1 && line.at(pos+1) == index){ 
            file.push_back(word);
            check = true;
        }
    }
    if(!check){
        string str;
        str.push_back('#');
        str.push_back(index);
        file.push_back(str);
        file.push_back(word);
    }

    fstream fic(name);
    for (string line : file) {
        fic << line << endl;
    }
}

void rem_word(string name,string word){
    fstream fichier(name);
    string lines[4];
    string line;
    int compt = 0;
    int pos = 0;
    bool valid = false;
    while(getline(fichier,line)){
        size_t found = line.find(word);
        int l = line.size()+1;
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