
//Abyel Romero
//Actor-Actress Tree functions definitions

#include <fstream>
#include <sstream>
#include "BSTActorActress.h"
#include "ActorActress.h"
#include <string>
#include <iomanip>
#include <algorithm>



BSTActorActress ::BSTActorActress(){ root = nullptr; seconds = false; size = 0; }

//BSTPictures::~BSTPictures(){ delete root;}

//
ActorActressNode * BSTActorActress:: Root(){ return root;}

void BSTActorActress::setRoot(ActorActressNode *_root) {root = _root;}

void BSTActorActress:: addNode(ActorActress pic){
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodePrivate(root, pic);
    }
}
//
//
void BSTActorActress:: addNodePrivate(ActorActressNode *node, ActorActress pic){
    
    
    
    if (pic.actorName.compare(node->key.actorName) < 0){
        if (node->left != nullptr){
            
            addNodePrivate(node->left, pic);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.actorName.compare(node->key.actorName) > 0){
        if (node->right != nullptr){
            
            addNodePrivate(node->right, pic);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
}//function

void BSTActorActress::addNodeYear(ActorActress actor){
    
    if (root == nullptr){
        
        root = setParameters(root, actor);
        size++;
    }
    
    else{
        addNodeYearPrivate(root, actor);
    }
    
}

void BSTActorActress:: addNodeYearPrivate(ActorActressNode *node, ActorActress actor){
    
    
    if (actor.year <  node->key.year){
        if (node->left != nullptr){
            
            addNodeYearPrivate(node->left, actor);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, actor);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (actor.year >  node->key.year){
        if (node->right != nullptr){
            
            addNodeYearPrivate(node->right, actor);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, actor);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}



void BSTActorActress::addNodeAward(ActorActress actor){
    
    if (root == nullptr){
        
        root = setParameters(root, actor);
        size++;
    }
    
    else{
        addNodeYearPrivate(root, actor);
    }
    
}

void BSTActorActress:: addNodeAwardPrivate(ActorActressNode *node, ActorActress actor){
    
    
    if (actor.actorName.compare(node->key.actorName) < 0){
        if (node->left != nullptr){
            
            addNodeAwardPrivate(node->left, actor);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, actor);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (actor.actorName.compare(node->key.actorName) > 0){
        if (node->right != nullptr){
            
            addNodeAwardPrivate(node->right, actor);
        }
        else {
            ActorActressNode * temp = new ActorActressNode;
            temp = setParameters(temp, actor);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTActorActress:: deleteMainMenu(){
    
    bool repeat = true;
    bool modify = true;
    
    while(repeat == true){
        
        int search;
        cout << "Search for a record to delete. What kind of search would you like to perform?" << endl;
        cout << "1. Actor Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Winner" << endl;
        cout << "4. Award" << endl;
        cout << "5. Film" << endl;
        cin >> search;
        
        
        if(search == 1 || search == 2 || search == 3 ||  search == 4 || search == 5 ){
            switch (search) {
                case 1:{
                    string input;
                    
                    cout << "You chose search for actor name. Enter your input" << endl;
                    cin >> input;
                    
                    partialSearchActorName(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to delete?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        
                        int x;
                        cin >> x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        
                        repeat = false;
                    }
                    break;
                }
                    
                case 2:{
                    
                    int input;
                    
                    cout << "You chose search for year. Enter your input" << endl;
                    cin >> input;
                    partialSearchYear(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to delete?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Year: "<< itemsFound[i]->key.year << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        repeat = false;
                        
                    }
                    break;
                }
                    
                case 3:{
                    
                    int input;
                    
                    cout << "You chose search for winner. Enter your input" << endl;
                    cin >> input;
                    partialSearchWinner(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Winner: "<< itemsFound[i]->key.winner << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 4:{
                    
                    string input;
                    
                    cout << "You chose search for rating. Enter your input" << endl;
                    cin >> input;
                    partialSearchAward(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Award: "<< itemsFound[i]->key.award << " Name: " << itemsFound[i]->key.actorName << endl;
                            
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);

                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 5:{
                    
                    string input;
                    
                    cout << "You chose search for duration. Enter your input" << endl;
                    cin >> input;
                    partialSearchFilm(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Film: "<< itemsFound[i]->key.film << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);

                        repeat = false;
                        
                    }
                    break;
                }
                    
                    
            }
            
        }
        
        else{
            cout << "Enter a valid input." << endl;
        }
    }
    
}


ActorActressNode* BSTActorActress:: deleteNodePrivate(ActorActressNode  *node, ActorActress pic){
    
    
    
    if (node == nullptr){
        return root;
        
    }
    
    else if(pic.actorName.compare(node->key.actorName) < 0){
        node->left = deleteNodePrivate(node->left, pic);
        
    }
    else if (pic.actorName.compare(node->key.actorName) > 0){
        node->right = deleteNodePrivate(node->right, pic);
    }
    
    else { //if current node is equal to node
        
        // Case 1: No Child
        if (node->left == nullptr && node->right == nullptr) {
            delete root;
            node = nullptr;
            size--;
            // Case 2: one child
        }
        else if (node->left == nullptr) { //if left of node is empty then set current to right node and delete current
            ActorActressNode *temp = node;
            ActorActressNode *temp2 = node->parent;
            
            node = node->right;
            node->parent = temp2;
            delete temp;
            size--;
        }
        else if (node->right == nullptr) { //other way around
            ActorActressNode *temp = node;
            ActorActressNode *temp2 = node->parent;
            
            node = root->left;
            node->parent = temp2;
            
            delete temp;
            size--;
        }
        else {
            ActorActressNode *temp = min(node->right);
            node->key = temp->key;
            node->right = deleteNodePrivate(node->right, temp->key);
            
        }
    }
    return node;
    
}

void BSTActorActress::deleteNode(ActorActress pic){
    
    
    
    if(deleteNodePrivate(root, pic) == nullptr){
        root = nullptr;
        size--;
    }
    
}


void BSTActorActress:: modifyInfo(){
    
    bool repeat = true;
    bool modify = true;
    
    while(repeat == true){
        
        int search;
        cout << "Search for a record to modify. What kind of search would you like to perform?" << endl;
        cout << "1. Actor Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Winner" << endl;
        cout << "4. Award" << endl;
        cout << "5. Film" << endl;
        cin >> search;
        
        
        if(search == 1 || search == 2 || search == 3 ||  search == 4 || search == 5 ){
            switch (search) {
                case 1:{
                    string input;
                    
                    cout << "You chose search for actor name. Enter your input" << endl;
                    cin >> input;
                    
                    partialSearchActorName(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        
                        int x;
                        cin>>x;
                        
                        ActorActress modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new name for this record" << endl;
                        cin >> input;
                        
                        ActorActress temp = itemsFound[x-1]->key;
                        
                        temp.actorName = input;
                        
                        deleteNode(itemsFound[x-1]->key);
                        addNode(temp);
                        
                        repeat = false;
                        
                    }
                    break;
                }
                    
                case 2:{
                    
                    int input;
                    
                    cout << "You chose search for year. Enter your input" << endl;
                    cin >> input;
                    partialSearchYear(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Year: "<< itemsFound[i]->key.year << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        ActorActress modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new year for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.year = input;
                        repeat = false;
                        
                    }
                    break;
                }
                    
                case 3:{
                    
                    int input;
                    
                    cout << "You chose search for winner. Enter your input" << endl;
                    cin >> input;
                    partialSearchWinner(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Winner: "<< itemsFound[i]->key.winner << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        ActorActress modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new nominations for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.winner = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 4:{
                    
                    string input;
                    
                    cout << "You chose search for rating. Enter your input" << endl;
                    cin >> input;
                    partialSearchAward(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Award: "<< itemsFound[i]->key.award << " Name: " << itemsFound[i]->key.actorName << endl;
                            
                        }
                        int x;
                        cin>>x;
                        
                        ActorActress modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new rating for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.award = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 5:{
                    
                    string input;
                    
                    cout << "You chose search for duration. Enter your input" << endl;
                    cin >> input;
                    partialSearchFilm(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Film: "<< itemsFound[i]->key.film << " Name: " << itemsFound[i]->key.actorName << endl;
                        }
                        int x;
                        cin>>x;
                        
                        ActorActress modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new duration for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.film = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
               
                
            }
            
        }
        
        else{
            cout << "Enter a valid input." << endl;
        }
    }
}




void BSTActorActress:: printInOrder(){
    vector<int> searches;
    cout << "Enter which fields you would like to print. Enter something like this 1 2 4 or 8 9 6 or 1 3 4 2 etc" << endl;
    cout << "1. Actor Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Winner" << endl;
    cout << "4. Award" << endl;
    cout << "5. Film" << endl;
    string  input;
    
    cin.ignore();
    getline(cin, input);
    
    istringstream is(input);
    int n;
    
    while( is >> n ) {
        searches.push_back(n);
    }
    
    printInOrderPrivate(root, searches);
}

void BSTActorActress:: printInOrderPrivate(ActorActressNode *node, vector<int> searches){
    
    if (root != nullptr){
        
        if (node ->left != nullptr){
            printInOrderPrivate(node->left, searches);
        }
        
        for(int i = 0; i < searches.size(); i++){
            
            if(searches[i]==1){
                cout << " Name: " << node->key.actorName;
                
            }
            
            if(searches[i]==2){
                cout << " Year: "<< node->key.year;
                
            }
            
            if(searches[i]==3){
                cout << " Winner: "<< node->key.winner;
                
            }
            
            if(searches[i]==4){
                cout<< " Award: " << node->key.award;
                
            }
            
            if(searches[i]==5){
                cout<< " Film: " << node->key.film;
                
            }
        cout << endl;
        }
        
        if (node->right!= nullptr){
            printInOrderPrivate(node ->right, searches);
        }
        
    }
    
    else{
        cout << "Error! Empty tree.";
    }
    
    cout << "\n";
}

void BSTActorActress:: outputSearchReport(){
    
    ofstream out;
    
    if (itemsFound.size() == 0){
        cout <<"Error. First perform a search." << endl;
    }
    
    else{
        out.open("Actor-Actress Search Report.txt");
       
        out << setw(7) << "Year:" << setw(15) << "Award" << setw(15) << "Winner:" << setw(15) << "Name:" << setw(15) << "Film:" << endl;
        
        for (int i = 0; i < itemsFound.size(); i++){
            
            out << setw(7) << itemsFound[i]->key.year << setw(15) << itemsFound[i]->key.award << itemsFound[i]->key.winner << itemsFound[i]->key.actorName << itemsFound[i]->key.film  << endl;
        }
        
        itemsFound.clear();
        out.close();
    }
}


void BSTActorActress:: saveAs(){
    
    string name;
    cout <<"Enter the name for the new file without extention" << endl;
    cin.ignore();
    getline(cin, name);
    
    
    ofstream out;
    out.open(name + ".csv");
    out << "year,award,winner,name,film\n";
    saveAsOrOverwritePrivate(root, out);
}

void BSTActorActress::saveAsOrOverwritePrivate(ActorActressNode * node, ofstream & out){
    
    if (root != nullptr){
        
        if (node ->left != nullptr){
            saveAsOrOverwritePrivate(node->left, out);
        }
        
        out << " " << node->key.year << "," << node->key.award << "," << node->key.winner << "," << node->key.actorName << ","<< node->key.film <<"\n";
        
        if (node->right!= nullptr){
            saveAsOrOverwritePrivate(node->right, out);
        }
        
    }
    
    else{
        cout << "Error! Empty tree.";
    }
    
    
}

void BSTActorActress:: overwrite(){
    
    ofstream out;
    out.open("actoractress.csv");
    out << "year,award,winner,name,film\n";
    
    
    saveAsOrOverwritePrivate(root, out);
}


void  BSTActorActress:: readFile(){
    
    ActorActress p;
    ifstream input;
    input.open("actoractress.csv");
    bool x = true;

    string name, year, winner, film, award;
    
    while (getline(input, year, ',' )){
        getline(input, award, ',' );
        getline(input, winner, ',' );
        getline(input, name, ',' );
        getline(input, film);
        
        //these lines set the parameters of the actoractress object to the string read by the ifstream object
        
        p.actorName = name;
        
        try{ //try catch for year conversion to int
            
            p.year = stoi(year);
        }
        
        catch(std::invalid_argument& e){
            p.year = -1;
        }
        
        try{ //try catch for winner conversion to int
            
            p.winner = stoi(winner);
        }
        
        catch(std::invalid_argument& e){
            p.winner = -1;
        }
        
        p.award = award;
        p.film = film;
        
        if (x == false){
            addNode(p);
        }
        
        else{
            x = false;
        }
    }
}



ActorActressNode* BSTActorActress ::min(ActorActressNode* node)
{
    ActorActressNode* tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->left)
    {
        tempNode = min(node->left);
    }
    else
        tempNode = node;
    
    return tempNode;
}


ActorActressNode* BSTActorActress:: setParameters(ActorActressNode*  node, ActorActress temp){
    node = new ActorActressNode;
    
    node->key.actorName = temp.actorName;
    node->key.year = temp.year;
    node->key.winner = temp.winner;
    node->key.award = temp.award;
    node->key.film = temp.film;
    return node;
}


void BSTActorActress:: addToVector(vector <ActorActressNode *> & temp, ActorActressNode * temp2){
    
    if (root != nullptr){
        
        if (temp2->left != nullptr){
            addToVector(temp, temp2->left);
        }
        
        temp.push_back(temp2);
        
        
        if (temp2->right!= nullptr){
            addToVector(temp, temp2->right);
        }
    }
    else{
        cout << "Error! Empty tree.";
    }
}

void BSTActorActress::sortByYear(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node){ //bubble sort
    
    vector<ActorActressNode *> temp;
    
    addToVector(temp, currentBST.Root());
    

    for(int j = 0; j < size; j++){

        for(int i = j + 1; i < size; i++){

            if(temp[j]->key.year > temp[i]->key.year ){
                
                ActorActressNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeYear(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
    
    
}

void BSTActorActress:: sortByAward(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node){ //bubble sort
    
    vector<ActorActressNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){

            if(temp[j]->key.award.compare(temp[i]->key.award) < 0){
                
                ActorActressNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeAward(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
    
}


void BSTActorActress:: sortByActorName(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node){ //no bubble sort since tree is by default sorted by act name
    
    if (root != nullptr){
        
        if (node->left != nullptr){
            sortByActorName(currentBST, newSortedBST, node->left);
        }
        newSortedBST.addNode(node->key);
        
        cout << node->key.film << endl;
        
        if (node->right!= nullptr){
            sortByActorName(currentBST, newSortedBST, node->right);
        }
        
    }
    else{
        cout << "Error! Empty tree.";
    }
    
    currentBST.setRoot(newSortedBST.Root());
    
}


ActorActressNode* BSTActorActress:: completeSecondSearch(){
    seconds = true;
    
    BSTActorActress temp;
    for (int i = 0; i < itemsFound.size(); i ++){
        temp.addNode(itemsFound[i]->key);
    }
    itemsFound.clear();
    cout <<"What type of search would you like to perform now?" << endl;
    cout << "1. Actor Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Winner" << endl;
    cout << "4. Award" << endl;
    cout << "5. Film" << endl;
    
    int input;
    cin >> input;
    
    int search;
    string search2;
    
    cout <<"Enter your input:" << endl;
    
    if(input == 1){
        cin >> search2;
        completeSearchActorName(temp, search2);
    }
    
    else if(input == 2){
        cin >> search;
        completeSearchYear(temp, search);
    }
    
    else if(input == 3){
        cin >> search;
        completeSearchWinner(temp, search);
        
    }
    else if(input == 4){
        cin >> search2;
        completeSearchAward(temp, search2);
    }
    
    else if(input == 5){
        cin >> search2;
        completeSearchFilm(temp, search2 );
    }
    
    return nullptr;
    
}


ActorActressNode* BSTActorActress:: partialSecondSearch(){
    bool modify = false;
    
    BSTActorActress temp;
    for (int i = 0; i < itemsFound.size(); i ++){
        temp.addNode(itemsFound[i]->key);
    }
    
    itemsFound.clear();
    
    cout <<"What type of search would you like to perform now?" << endl;
    cout << "1. Actor Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Winner" << endl;
    cout << "4. Award" << endl;
    cout << "5. Film" << endl;
 
    
    int input;
    cin >> input;
    
    int search;
    string search2;
    double search3;
    
    cout <<"Enter your input:" << endl;
    
    if(input == 1){
        cin >> search2;
        partialSearchActorName(temp, search2, modify);
    }
    
    else if(input == 2){
        cin >> search;
        partialSearchYear(temp, search, modify);
    }
    
    else if(input == 3){
        cin >> search;
        partialSearchWinner(temp, search, modify);
        
    }
    else if(input == 4){
        cin >> search3;
        partialSearchAward(temp, search2, modify);
    }
    
    else if(input == 5){
        cin >> search;
        partialSearchFilm(temp, search2, modify);
    }
    
    
    return nullptr;
    
}



//searches (didn't have time to implement templetes or something for these to have less functions)

//name
ActorActressNode* BSTActorActress:: completeSearchActorName(BSTActorActress bst, string name){
    
    return completeSearchActorNamePrivate(bst.Root(), name);
}


ActorActressNode * BSTActorActress:: completeSearchActorNamePrivate(ActorActressNode * node, string name){
    
    if (node == nullptr){ //if the search is over
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Actor Name: " << itemsFound[i]->key.actorName << endl;
        }
        
        cout<< "What would you like to do now?"  << endl;
        cout << "1. Peform a second search from this output" << endl;
        cout <<"2. Start a new search" << endl;
        cout << "3. Exit from search" << endl;
        cin >> input;
        
        if( input == 3){
            return nullptr;
        }
        if( input == 1){
            if(seconds == true){
                cout << "Error! Peroform a search first" << endl;
                seconds = false;
                return nullptr;
            }
            
            else{
                completeSecondSearch();
                
            }
        }
        
        else{
            cout <<"Enter your new search for name:" << endl;
            cin.ignore();
            getline(cin, name);
            itemsFound.clear();
            
            completeSearchActorName(*this, name);
            return nullptr;
            
        }
    }
    
    else if (node->key.actorName == name){
        itemsFound.push_back(node);
        
    }
    
    
    if(name.compare(node->key.actorName) > 0){
        node->right = node-> right;
        return completeSearchActorNamePrivate(node->right, name);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchActorNamePrivate(node->left, name);
    }
    
    
    
}



ActorActressNode* BSTActorActress:: partialSearchActorName(BSTActorActress bst, string name, bool modify){
    
    return partialSearchActorNamePrivate(bst.Root(), name, modify);
}


ActorActressNode * BSTActorActress:: partialSearchActorNamePrivate(ActorActressNode *node, string name, bool modify){
    
    string temp = name;
    string temp2 = node->key.actorName;
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Actor Name: " << itemsFound[i]->key.actorName << endl;
            }
            
            cout<< "What would you like to do now?"  << endl;
            cout << "1. Peform a second search from this output" << endl;
            cout <<"2. Start a new search" << endl;
            cout << "3. Exit" << endl;
            cin >> input;
            if( input == 3){
                return nullptr;
            }
            
            if( input == 1){
                partialSecondSearch();
            }
            
            else{
                cout <<"Enter your new search for name:" << endl;
                cin.ignore();
                getline(cin, name);
                itemsFound.clear();
                
                partialSearchActorName(*this, name, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }
    }
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        
        
        itemsFound.push_back(node);
        //        cout <<  name <<" found on: " << node->key.name << endl;
        
    }
    
    if (node ->left != nullptr){
        partialSearchActorNamePrivate(node->left, name, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchActorNamePrivate(node->right, name, modify);
    }
    
    return node;
}

//year

ActorActressNode* BSTActorActress:: completeSearchYear(BSTActorActress bst,int year){
    
    return completeSearchYearPrivate(bst.Root(), year);
}


ActorActressNode * BSTActorActress:: completeSearchYearPrivate(ActorActressNode * node, int year){
    
    if (node == nullptr){
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Actor Name: " << itemsFound[i]->key.actorName << " Year: " << itemsFound[i]->key.year << endl;
        }
        
        cout<< "What would you like to do now?"  << endl;
        cout << "1. Peform a second search from this output" << endl;
        cout <<"2. Start a new search" << endl;
        cout << "3. Exit from search" << endl;
        cin >> input;
        
        
        if( input == 3){
            return nullptr;
        }
        if( input == 1){
            if (itemsFound.size() == 0){
                cout << "Error. Perform a first search first!" << endl;
            }
            else{
                completeSecondSearch();
            }
        }
        
        else{
            cout <<"Enter your new search for year:" << endl;
            cin >> year;
            itemsFound.clear();
            
            completeSearchYear(*this, year);
            return nullptr;
            
        }        }
    
    else if (node->key.year == year){
        itemsFound.push_back(node);
        
    }
    
    
    if(year < node->key.year ){
        node->right = node-> right;
        return completeSearchYearPrivate(node->right, year);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchYearPrivate(node->left, year);
    }
}


ActorActressNode* BSTActorActress:: partialSearchYear(BSTActorActress bst,int year, bool modify){
    
    return partialSearchYearPrivate(bst.Root(), year, modify);
}


ActorActressNode * BSTActorActress:: partialSearchYearPrivate(ActorActressNode *node, int year, bool modify){
    
    string temp = to_string(year);
    string temp2 = to_string(node->key.year);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Actor Name: " << itemsFound[i]->key.actorName << "Year: " << itemsFound[i]->key.year << endl;
            }
            
            cout<< "What would you like to do now?"  << endl;
            cout << "1. Peform a second search from this output" << endl;
            cout <<"2. Start a new search" << endl;
            cout << "3. Exit from search" << endl;
            cin >> input;
            if( input == 3){
                return nullptr;
            }
            
            if( input == 1){
                partialSecondSearch();
            }
            
            else{
                cout <<"Enter your new search for year:" << endl;
                cin >> year;
                itemsFound.clear();
                
                partialSearchYear(*this, year, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }    }
    
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        
        
        itemsFound.push_back(node);
        
    }
    
    if (node ->left != nullptr){
        partialSearchYearPrivate(node->left, year, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchYearPrivate(node->right, year, modify);
    }
    return node;
}

//nominations

ActorActressNode* BSTActorActress:: completeSearchWinner(BSTActorActress bst,int nominations){
    
    return completeSearchWinnerPrivate(bst.Root(), nominations);
}


ActorActressNode * BSTActorActress:: completeSearchWinnerPrivate(ActorActressNode * node, int nominations){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Winner: "<< itemsFound[i]->key.winner << " Name: " << itemsFound[i]->key.actorName << endl;
        }
        
        cout<< "What would you like to do now?"  << endl;
        cout << "1. Peform a second search from this output" << endl;
        cout <<"2. Start a new search" << endl;
        cout << "3. Exit from search" << endl;
        cin >> input;
        if( input == 3){
            return nullptr;
        }
        
        if( input == 1){
            completeSecondSearch();
        }
        
        else{
            cout <<"Enter your new search for nominations:" << endl;
            cin >> nominations;
            itemsFound.clear();
            
            completeSearchWinner(*this, nominations);
            return nullptr;
            
        }    }
    
    else if (node->key.winner == nominations){
        itemsFound.push_back(node);
        
    }
    
    
    if(nominations < node->key.winner ){
        node->right = node-> right;
        return completeSearchWinnerPrivate(node->right, nominations);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchWinnerPrivate(node->left, nominations);
    }
}


ActorActressNode* BSTActorActress:: partialSearchWinner(BSTActorActress bst,int nominations, bool modify){
    
    return partialSearchWinnerPrivate(bst.Root(), nominations, modify);
}


ActorActressNode * BSTActorActress:: partialSearchWinnerPrivate(ActorActressNode *node, int nominations, bool modify){
    
    string temp = to_string(nominations);
    string temp2 = to_string(node->key.winner);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Winner: "<< itemsFound[i]->key.winner << " Name: " << itemsFound[i]->key.actorName << endl;
            }
            
            cout<< "What would you like to do now?"  << endl;
            cout << "1. Peform a second search from this output" << endl;
            cout <<"2. Start a new search" << endl;
            cout << "3. Exit from search" << endl;
            cin >> input;
            if( input == 3){
                return nullptr;
            }
            
            if( input == 1){
                partialSecondSearch();
            }
            
            else{
                cout <<"Enter your new search for nominations:" << endl;
                cin >> nominations;
                itemsFound.clear();
                
                partialSearchWinner(*this, nominations, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }    }
    
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        
        
        itemsFound.push_back(node);
        
    }
    
    if (node ->left != nullptr){
        partialSearchWinnerPrivate(node->left, nominations, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchWinnerPrivate(node->right, nominations, modify);
    }
    return node;
}



//genre1
ActorActressNode* BSTActorActress:: completeSearchAward(BSTActorActress bst, string genre){
    
    return completeSearchAwardPrivate(bst.Root(), genre);
}


ActorActressNode * BSTActorActress:: completeSearchAwardPrivate(ActorActressNode * node, string genre){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Award: "<< itemsFound[i]->key.award << " Name: " << itemsFound[i]->key.actorName << endl;
        }
        
        cout<< "What would you like to do now?"  << endl;
        cout << "1. Peform a second search from this output" << endl;
        cout <<"2. Start a new search" << endl;
        cout << "3. Exit from search" << endl;
        cin >> input;
        if( input == 3){
            return nullptr;
        }
        
        if( input == 1){
            completeSecondSearch();
        }
        
        else{
            cout <<"Enter your new search for genre 1:" << endl;
            cin >> genre;
            itemsFound.clear();
            
            completeSearchAward(*this, genre);
            return nullptr;
            
        }
        
    }
    
    else if (node->key.award == genre){
        itemsFound.push_back(node);
        
    }
    
    
    
    if(genre.compare(node->key.award) > 0){
        node->right = node-> right;
        return completeSearchAwardPrivate(node->right, genre);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchAwardPrivate(node->left, genre);
    }
}



ActorActressNode* BSTActorActress:: partialSearchAward(BSTActorActress bst, string genre, bool modify){
    
    return partialSearchAwardPrivate(bst.Root(), genre, modify);
}


ActorActressNode * BSTActorActress:: partialSearchAwardPrivate(ActorActressNode *node, string genre, bool modify){
    
    string temp = genre;
    string temp2 = node->key.award;
    
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Award: "<< itemsFound[i]->key.award << " Name: " << itemsFound[i]->key.actorName << endl;
            }
            
            cout<< "What would you like to do now?"  << endl;
            cout << "1. Peform a second search from this output" << endl;
            cout <<"2. Start a new search" << endl;
            cout << "3. Exit from search" << endl;
            cin >> input;
            if( input == 3){
                return nullptr;
            }
            
            if( input == 1){
                partialSecondSearch();
            }
            
            else{
                cout <<"Enter your new search for genre 1:" << endl;
                cin >> genre;
                itemsFound.clear();
                
                partialSearchAward(*this, genre, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }    }
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        itemsFound.push_back(node);
    }
    
    
    if (node ->left != nullptr){
        partialSearchAwardPrivate(node->left, genre, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchAwardPrivate(node->right, genre, modify);
    }
    
    
    return node;
}

//genre2

ActorActressNode* BSTActorActress:: completeSearchFilm(BSTActorActress bst, string genre){
    
    return completeSearchFilmPrivate(bst.Root(), genre);
}


ActorActressNode * BSTActorActress:: completeSearchFilmPrivate(ActorActressNode * node, string genre){
    
    if (node == nullptr){
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Film: "<< itemsFound[i]->key.film << " Name: " << itemsFound[i]->key.actorName << endl;
            
        }
        
        cout<< "What would you like to do now?"  << endl;
        cout << "1. Peform a second search from this output" << endl;
        cout <<"2. Start a new search" << endl;
        cout << "3. Exit from search" << endl;
        cin >> input;
        if( input == 3){
            return nullptr;
        }
        
        if( input == 1){
            completeSecondSearch();
        }
        
        else{
            cout <<"Enter your new search for genre2:" << endl;
            cin >> genre;
            itemsFound.clear();
            
            completeSearchFilm(*this, genre);
            return nullptr;
            
        }
    }
    
    
    else if (node->key.film == genre){
        itemsFound.push_back(node);
        
    }
    
    if(genre.compare(node->key.film) > 0){
        node->right = node-> right;
        return completeSearchFilmPrivate(node->right, genre);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchFilmPrivate(node->left, genre);
    }
}

ActorActressNode* BSTActorActress:: partialSearchFilm(BSTActorActress bst, string genre, bool modify){
    
    return partialSearchFilmPrivate(bst.Root(), genre, modify);
}


ActorActressNode * BSTActorActress:: partialSearchFilmPrivate(ActorActressNode *node, string genre, bool modify){
    
    string temp = genre;
    string temp2 = node->key.film;
    
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Film: "<< itemsFound[i]->key.film << " Name: " << itemsFound[i]->key.actorName << endl;
                
            }
            
            cout<< "What would you like to do now?"  << endl;
            cout << "1. Peform a second search from this output" << endl;
            cout <<"2. Start a new search" << endl;
            cout << "3. Exit from search" << endl;
            cin >> input;
            if( input == 3){
                return nullptr;
            }
            
            if( input == 1){
                partialSecondSearch();
            }
            
            else{
                cout <<"Enter your new search for genre2:" << endl;
                cin >> genre;
                itemsFound.clear();
                
                partialSearchFilm(*this, genre, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }    }
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        itemsFound.push_back(node);
    }
    
    
    if (node ->left != nullptr){
        partialSearchFilmPrivate(node->left, genre, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchFilmPrivate(node->right, genre, modify);
    }
    
    
    return node;
}

