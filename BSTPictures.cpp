 //Abyel Romero
//Pictures Tree functions definitions

#include <fstream>
#include <sstream>
#include "BSTPictures.h"
#include "Picture.h"
#include <iomanip>
#include <string>
#include <algorithm>



BSTPictures::BSTPictures(){ root = nullptr; seconds = false;  size = 0;}

//BSTPictures::~BSTPictures(){ delete root;}

//
PictureNode* BSTPictures:: Root(){ return root;}

void BSTPictures::setRoot(PictureNode *_root) {root = _root;}

void BSTPictures:: addNode(Picture pic){
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
void BSTPictures:: addNodePrivate(PictureNode *node, Picture pic){
    
    
    
    if (pic.name.compare(node->key.name) < 0){
        if (node->left != nullptr){

            addNodePrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;

        }
    }

    else if (pic.name.compare(node->key.name) > 0){
        if (node->right != nullptr){

            addNodePrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;

        }
    }//if
}//function



PictureNode* BSTPictures:: deleteNodePrivate(PictureNode *node, Picture pic){
    


    if (node == nullptr){
        return root;
        
    }

    else if(pic.name.compare(node->key.name) < 0){
        node->left = deleteNodePrivate(node->left, pic);

    }
    else if (pic.name.compare(node->key.name) > 0){
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
            PictureNode *temp = node;
            PictureNode *temp2 = node->parent;
            
            node = node->right;
            node->parent = temp2;
            delete temp;
            size--;
        }
        else if (node->right == nullptr) { //other way around
            PictureNode *temp = node;
            PictureNode *temp2 = node->parent;

            node = root->left;
            node->parent = temp2;

            delete temp;
            size--;
        }
        else {
            PictureNode *temp = min(node->right);
            node->key = temp->key;
            node->right = deleteNodePrivate(node->right, temp->key);

        }
    }
    return node;

}

void BSTPictures:: deleteMainMenu(){
    
    bool repeat = true;
    bool modify = true;
    
    while(repeat == true){
        
        int search;
        cout << "Search for a record to delete. What kind of search would you like to perform?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Rating" << endl;
        cout << "5. Duration" << endl;
        cout << "6. Genre 1" << endl;
        cout << "7. Genre 2" << endl;
        cout << "8. Release" << endl;
        cout << "9. Metacritic" << endl;
        cout << "10. Synopsis" << endl;
        cin >> search;
        
        
    if(search == 1 || search == 2 || search == 3 ||  search == 4 || search == 5 || search == 6 || search == 7 || search == 8 || search == 9){
        switch (search) {
                case 1:{
                    string input;
                    
                    cout << "You chose search for actor name. Enter your input" << endl;
                    cin >> input;
                    
                    partialSearchName(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to delete?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Name: " << itemsFound[i]->key.name << endl;
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
                            cout << i+1 << ". Year: "<< itemsFound[i]->key.year << " Name: " << itemsFound[i]->key.name << endl;
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
                    
                    cout << "You chose search for nominations. Enter your input" << endl;
                    cin >> input;
                    partialSearchNominations(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Nominations: "<< itemsFound[i]->key.nominations << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 4:{
                    
                    double input;
                    
                    cout << "You chose search for rating. Enter your input" << endl;
                    cin >> input;
                    partialSearchRating(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Rating: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
                            
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 5:{
                    
                    int input;
                    
                    cout << "You chose search for duration. Enter your input" << endl;
                    cin >> input;
                    partialSearchDuration(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Duration: "<< itemsFound[i]->key.duration << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        deleteNode(itemsFound[x-1]->key);
                        
                        repeat = false;
                        
                    }
                    break;
                }
                
            case 6:{
                string input;
                
                cout << "You chose search for actor genre 1. Enter your input" << endl;
                cin >> input;
                
                partialSearchGenre1(*this, input, modify);
                
                if (itemsFound.size() == 0){
                    cout << "No records found for the input: " << input << endl;
                    repeat = false;
                    break;
                }
                
                else{
                    cout << "These are the records found. Which one would you like to delete?" << endl;
                    
                    for (int i = 0; i < itemsFound.size(); i++){
                        cout << i+1 << ". Name: " << itemsFound[i]->key.name  << " Genre 1: " << itemsFound[i]->key.genre1 << endl;
                    }
                    
                    int x;
                    cin >> x;
                    
                    deleteNode(itemsFound[x-1]->key);
                    
                    repeat = false;
                }
                break;
            }
                
          
            case 7:{
                string input;
                
                cout << "You chose search for genre 2. Enter your input" << endl;
                cin >> input;
                
                partialSearchGenre2(*this, input, modify);
                
                if (itemsFound.size() == 0){
                    cout << "No records found for the input: " << input << endl;
                    repeat = false;
                    break;
                }
                
                else{
                    cout << "These are the records found. Which one would you like to delete?" << endl;
                    
                    for (int i = 0; i < itemsFound.size(); i++){
                        cout << i+1 << ". Name: " << itemsFound[i]->key.name << " Genre 2: "<< itemsFound[i]->key.genre2 << endl;
                    }
                    
                    int x;
                    cin >> x;
                    
                    deleteNode(itemsFound[x-1]->key);
                    
                    repeat = false;
                }
                break;
            }
                
            case 8:{
                string input;
                
                cout << "You chose search for release. Enter your input" << endl;
                cin >> input;
                
                partialSearchRelease(*this, input, modify);
                
                if (itemsFound.size() == 0){
                    cout << "No records found for the input: " << input << endl;
                    repeat = false;
                    break;
                }
                
                else{
                    cout << "These are the records found. Which one would you like to delete?" << endl;
                    
                    for (int i = 0; i < itemsFound.size(); i++){
                        cout << i+1 << ". Name: " << itemsFound[i]->key.name << " Release: "  << itemsFound[i]->key.releaseMonth << endl;
                    }
                    
                    int x;
                    cin >> x;
                    
                    deleteNode(itemsFound[x-1]->key);
                    
                    repeat = false;
                }
                break;
            }
                
            case 9:{
                int input;
                
                cout << "You chose search for metacritic. Enter your input" << endl;
                cin >> input;
                
                partialSearchMetacritic(*this, input, modify);
                
                if (itemsFound.size() == 0){
                    cout << "No records found for the input: " << input << endl;
                    repeat = false;
                    break;
                }
                
                else{
                    cout << "These are the records found. Which one would you like to delete?" << endl;
                    
                    for (int i = 0; i < itemsFound.size(); i++){
                        cout << i+1 << ". Name: " << itemsFound[i]->key.name << " Metacritic: "  << itemsFound[i]->key.metacritic << endl;
                    }
                    
                    int x;
                    cin >> x;
                    
                    deleteNode(itemsFound[x-1]->key);
                    
                    repeat = false;
                }
                break;
            }
                
            case 10:{
                string input;
                
                cout << "You chose search for synopsis. Enter your input" << endl;
                cin >> input;
                
                partialSearchSynopsis(*this, input, modify);
                
                if (itemsFound.size() == 0){
                    cout << "No records found for the input: " << input << endl;
                    repeat = false;
                    break;
                }
                
                else{
                    cout << "These are the records found. Which one would you like to delete?" << endl;
                    
                    for (int i = 0; i < itemsFound.size(); i++){
                        string print;
                        for(int j = 0; j < 20; j++){
                            print = print + itemsFound[i]->key.synopsis[j];
                        }
                        
                        cout << i+1<< " . Name: " << itemsFound[i]->key.name << " Synopsis: " << print << "..." <<endl;                    }
                    
                    int x;
                    cin >> x;
                    
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



void BSTPictures::deleteNode(Picture pic){

    if(deleteNodePrivate(root, pic) == nullptr){
        root = nullptr;
    }

}


void BSTPictures:: modifyInfo(){
    
    bool repeat = true;
    bool modify = true;

    while(repeat == true){
        
        int search;
        cout << "Search for a record to modify. What kind of search would you like to perform?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Nominations" << endl;
        cout << "4. Rating" << endl;
        cout << "5. Duration" << endl;
        cout << "6. Genre 1" << endl;
        cout << "7. Genre 2" << endl;
        cout << "8. Release" << endl;
        cout << "9. Metacritic" << endl;
        cout << "10. Synopsis" << endl;
        cin >> search;
        
        
        if(search == 1 || search == 2 || search == 3 ||  search == 4 || search == 5 || search == 6 || search == 7 || search == 8 || search == 9 || search == 10){
            switch (search) {
                case 1:{

                    string input;

                    cout << "You chose search for name. Enter your input" << endl;
                    cin >> input;
                    
                    partialSearchName(*this, input, modify);

                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }

                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;

                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;

                        Picture modify = itemsFound[x-1]->key;

                        cout << "Alright! Enter the new name for this record" << endl;
                        cin >> input;

                        Picture temp = itemsFound[x-1]->key;

                        temp.name = input;

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
                            cout << i+1 << ". Year: "<< itemsFound[i]->key.year << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new year for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.year = input; // don't need to sort this node because we are just changing the year not the name
                       
                        repeat = false;
                        
                    }
                    break;
                }
                    
                case 3:{
                    
                    int input;
                    
                    cout << "You chose search for nominations. Enter your input" << endl;
                    cin >> input;
                    partialSearchNominations(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Nominations: "<< itemsFound[i]->key.nominations << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new nominations for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.nominations = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 4:{
                    
                    double input;
                    
                    cout << "You chose search for rating. Enter your input" << endl;
                    cin >> input;
                    partialSearchRating(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Rating: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
                            
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new rating for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.rating = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 5:{
                    
                    int input;
                    
                    cout << "You chose search for duration. Enter your input" << endl;
                    cin >> input;
                    partialSearchDuration(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Duration: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new duration for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.duration = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 6:{
                    
                    string input;
                    
                    cout << "You chose search for genre 1. Enter your input" << endl;
                    cin >> input;
                    partialSearchGenre1(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre1 << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new genre for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.genre1 = input;
                        repeat = false;
                        
                    }
                    break;
                }
                    
                case 7:{
                    
                    string input;
                    
                    cout << "You chose search for genre 2. Enter your input" << endl;
                    cin >> input;
                    partialSearchGenre2(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre2 << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new genre for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.genre2 = input;

                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 8:{
                    
                    string input;
                    
                    cout << "You chose search for release month. Enter your input" << endl;
                    cin >> input;
                    partialSearchRelease(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            cout << i+1 << ". Release: "<< itemsFound[i]->key.releaseMonth << " Name: " << itemsFound[i]->key.name << endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new release month for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.releaseMonth = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 9:{
                    
                    int input;
                    
                    cout << "You chose search for metacritic. Enter your input" << endl;
                    cin >> input;
                    partialSearchMetacritic(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                        cout << i+1 << ". Metacritic: "<< itemsFound[i]->key.metacritic << " Name: " << itemsFound[i]->key.name << endl;
                            
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new metacritic for this record" << endl;
                        cin >> input;
                        
                       
                        itemsFound[x-1]->key.metacritic = input;
                        
                        repeat = false;
                        
                    }
                    break;
                }
                case 10:{
                    
                    string input;
                    
                    cout << "You chose search for synopsis. Enter your input" << endl;
                    cin >> input;
                    partialSearchSynopsis(*this, input, modify);
                    
                    if (itemsFound.size() == 0){
                        cout << "No records found for the input: " << input << endl;
                        repeat = false;
                        break;
                    }
                    
                    else{
                        cout << "These are the records found. Which one would you like to modify?" << endl;
                        
                        for (int i = 0; i < itemsFound.size(); i++){
                            string print;
                            for(int j = 0; j < 20; j++){
                                print = print + itemsFound[i]->key.synopsis[j];
                            }
                            
                            cout << i+1<< " . Name: " << itemsFound[i]->key.name << " Synopsis: " << print << "..." <<endl;
                        }
                        int x;
                        cin>>x;
                        
                        Picture modify = itemsFound[x-1]->key;
                        
                        cout << "Alright! Enter the new synopsis for this record" << endl;
                        cin >> input;
                        
                        itemsFound[x-1]->key.synopsis = input; // don't need to sort this node because we
                        //are just changing the year not the name
                        
                        
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
    



void BSTPictures:: printInOrder(){
    
    vector<int> searches;
    cout << "Enter which fields you would like to print. Enter something like this 1 2 4 or 8 9 6 or 1 3 4 2 etc" << endl;
    cout << "1. Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Nominations" << endl;
    cout << "4. Rating" << endl;
    cout << "5. Duration" << endl;
    cout << "6. Genre 1 " << endl;
    cout << "7. Genre 2" << endl;
    cout << "8. Release" << endl;
    cout << "9. Metacritic" << endl;
    cout << "10. Synopsis" << endl;
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

void BSTPictures:: printInOrderPrivate(PictureNode *node, vector<int> searches){

    if (root != nullptr){

        if (node ->left != nullptr){
            printInOrderPrivate(node->left, searches);
        }
        
        for(int i = 0; i < searches.size(); i++){
            if(searches[i]==1){
                cout << " Name: " << node->key.name;

            }

            
            if(searches[i]==2){
                cout << " Year: "<< node->key.year;
            
            }
            
            if(searches[i]==3){
                cout << " Nominations: "<< node->key.nominations;
                
            }
            
            if(searches[i]==4){
                cout<< " Rating: " << node->key.rating;
                
            }
            
            if(searches[i]==5){
                cout<< " Duration: " << node->key.duration;
                
            }
            
            if(searches[i]==6){
                cout<< " Genre1: " << node->key.genre1;
                
            }
            
            if(searches[i]==7){
                cout << " Genre2: "<< node->key.genre2;
                
            }
            
            if(searches[i]==8){
                cout << " Release Month: "<< node->key.releaseMonth;
                
            }
            
            if(searches[i]==9){
                cout << " Metacritic: "<< node->key.metacritic;
                
            }
            
            if(searches[i]==10){
                string print;
                
                for(int j = 0; j < 30; j++){
                    print = print + node->key.synopsis[j];
                }
                
                cout <<" Synopsis: " << print << "..." <<endl;
            }
            
            cout << "\n";

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






void BSTPictures:: outputSearchReport(){
    
    if (itemsFound.size() == 0){
        cout <<"Error. First perform a search." << endl;
    }
    
    else{
        ofstream out;
        
        out.open("Pictures Search Report.txt");
        
        out << setw(7) << "Name:" << setw(15) << "Year" << setw(15) << "Nominations:" << setw(15) << "Rating:" << setw(15) << "Duration:" << setw(15) << "Genre 1:" << setw(15) << "Genre 2:" << setw(15) << "Release:" << setw(15) << "Metacritic:" << setw(15) << "Synopsis:" << endl;
        
        for (int i = 0; i < itemsFound.size(); i++){
            out << setw(7) << itemsFound[i]->key.name << setw(15) << itemsFound[i]->key.year << endl;
            
            
        }
        
        itemsFound.clear();
        out.close();
    }
    
    
}

void BSTPictures:: saveAs(){
    
    string name;
    cout << "Enter the name for the new file without extention" << endl;
    cin.ignore();
    getline(cin, name);
    
    
    
    ofstream out;
    out.open(name + ".csv");
    out << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis\n";
    saveAsOrOverwritePrivate(root, out);
}

void BSTPictures::saveAsOrOverwritePrivate(PictureNode * node, ofstream & out){
    
    if (root != nullptr){
        
        if (node ->left != nullptr){
            saveAsOrOverwritePrivate(node->left, out);
        }
        
        out << " " << node->key.name << "," << node->key.year << "," << node->key.nominations << "," << node->key.rating << ","<< node->key.duration << ","<< node->key.genre1 << ","<< node->key.genre2 << ","<< node->key.releaseMonth << "," << node->key.metacritic << "," << node->key.synopsis << "\n";
        
        if (node->right!= nullptr){
            saveAsOrOverwritePrivate(node->right, out);
        }
        
    }
    
    else{
        cout << "Error! Empty tree.";
    }
    
    
}

void BSTPictures:: overwrite(){
    
    ofstream out;
    out.open("Pictures.csv");
    out << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis\n";

    
    saveAsOrOverwritePrivate(root, out);
}


void  BSTPictures:: readFile(){
    
    Picture p;
    ifstream input;
    input.open("pictures.csv");
    bool x = true;
    
    string name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsys;
    
//    input.ignore();
    

    while (getline(input, name, ',' )){
        
        
        getline(input, year, ',' );
        getline(input, nominations, ',' );
        getline(input, rating, ',' );
        getline(input, duration, ',' );
        getline(input, genre1, ',' );
        getline(input, genre2, ',' );
        getline(input, release, ',' );
        getline(input, metacritic, ',' );
        getline(input, synopsys);
        input.ignore();
        
        
        //these lines set the parameters of the picture object to the string read by the ifstream object
        
        p.name = name;
        
        try{ //try catch for year conversion to int
            
            p.year = stoi(year);
        }
        
        catch(std::invalid_argument& e){
            p.year = -1;
        }
        
        try{ //try catch for nomination conversion to int
            
            p.nominations = stoi(nominations);
        }
        
        catch(std::invalid_argument& e){
            p.nominations = -1;
        }
        
        try{ //try catch for rating conversion to int
            
            p.rating = stod(rating);
        }
        
        catch(std::invalid_argument& e){
            p.rating = -1;
        }
        
        try{//try catch for duration conversion to int
            
            p.duration = stoi(duration);
        }
        
        catch(std::invalid_argument& e){
            p.duration = -1;
        }
        
        p.genre1 = genre1;
        p.genre2 = genre2;
        p.releaseMonth = release;
        
        try{//try catch for metacritic score conversion to int
            
            p.metacritic = stoi(metacritic);
        }
        
        catch(std::invalid_argument& e){
            p.metacritic = -1;
        }
        
        p.synopsis = synopsys;
        
        if (x == false){
            addNode(p);
        }
        
        else{
            x = false;
        }
    }
}
    


PictureNode* BSTPictures ::min(PictureNode* node)
{
    PictureNode* tempNode = node;
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


PictureNode* BSTPictures:: setParameters(PictureNode*  node, Picture temp){
    node = new PictureNode;
    
    node->key.name = temp.name;
    node->key.year = temp.year;
    node->key.nominations = temp.nominations;
    node->key.rating = temp.rating;
    node->key.duration = temp.duration;
    node->key.genre1 = temp.genre1;
    node->key.genre2 = temp.genre2;
    node->key.releaseMonth = temp.releaseMonth;
    node->key.metacritic = temp.metacritic;
    node->key.synopsis = temp.synopsis;
    
    return node;

}
void BSTPictures:: addToVector(vector <PictureNode *> & temp, PictureNode * temp2){
    
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

void BSTPictures::addNodeYear(Picture pic){
    
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodeYearPrivate(root, pic);
    }
    
}

void BSTPictures:: addNodeYearPrivate(PictureNode *node, Picture pic){
    
    
    if (pic.year <  node->key.year){
        if (node->left != nullptr){
            
            addNodeYearPrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.year >  node->key.year){
        if (node->right != nullptr){
            
            addNodeYearPrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTPictures::addNodeNominations(Picture pic){
    
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodeYearPrivate(root, pic);
    }
    
}

void BSTPictures:: addNodeNominationsPrivate(PictureNode *node, Picture pic){
    
    
    if (pic.nominations <  node->key.nominations){
        if (node->left != nullptr){
            
            addNodeNominationsPrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.nominations >  node->key.nominations){
        if (node->right != nullptr){
            
            addNodeNominationsPrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTPictures::addNodeRating(Picture pic){
    
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodeYearPrivate(root, pic);
    }
    
}

void BSTPictures:: addNodeRatingPrivate(PictureNode *node, Picture pic){
    
    
    if (pic.rating <  node->key.rating){
        if (node->left != nullptr){
            
            addNodeRatingPrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.rating >  node->key.rating){
        if (node->right != nullptr){
            
            addNodeRatingPrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTPictures::addNodeDuration(Picture pic){
    
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodeDurationPrivate(root, pic);
    }
    
}

void BSTPictures:: addNodeDurationPrivate(PictureNode *node, Picture pic){
    
    
    if (pic.duration <  node->key.duration){
        if (node->left != nullptr){
            
            addNodeDurationPrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.duration >  node->key.duration){
        if (node->right != nullptr){
            
            addNodeDurationPrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTPictures::addNodeRelease(Picture pic){
    
    if (root == nullptr){
        
        root = setParameters(root, pic);
        size++;
    }
    
    else{
        addNodeReleasePrivate(root, pic);
    }
    
}

void BSTPictures:: addNodeReleasePrivate(PictureNode *node, Picture pic){
    
    
    if (pic.releaseMonth.compare(node->key.releaseMonth) < 0){
        if (node->left != nullptr){
            
            addNodeReleasePrivate(node->left, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->left = temp;
            temp->parent = node; //this
            size++;
        }
    }
    
    //    maybe later check if less than or equal
    else if (pic.releaseMonth.compare(node->key.releaseMonth) > 0){
        if (node->right != nullptr){
            
            addNodeReleasePrivate(node->right, pic);
        }
        else {
            PictureNode * temp = new PictureNode;
            temp = setParameters(temp, pic);
            
            node->right = temp;
            temp->parent = node; //this
            size++;
        }
    }//if
    
}

void BSTPictures:: sortByMovieName(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){ //no bubble sort since trees are by default sorted by name
    
    if (root != nullptr){
        
        if (node->left != nullptr){
            sortByMovieName(currentBST, newSortedBST, node->left);
        }
        
        newSortedBST.addNode(node->key);

        cout << node->key.name << endl;
        
        if (node->right!= nullptr){
            sortByMovieName(currentBST, newSortedBST, node->right);
        }
        
    }
    else{
        cout << "Error! Empty tree.";
    }
    
    currentBST.setRoot(newSortedBST.Root());
}

void BSTPictures:: sortByYear(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){// bubble sort
    
    vector<PictureNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){
            
            if(temp[j]->key.year > temp[i]->key.year){
                
                PictureNode * temp2;
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

void BSTPictures:: sortByNominations(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){
    
    vector<PictureNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){
            
            if(temp[j]->key.nominations > temp[i]->key.nominations){
                
                PictureNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeNominations(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
}

void BSTPictures:: sortByRating(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){
    
    vector<PictureNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){
            
            if(temp[j]->key.rating > temp[i]->key.rating){
                
                PictureNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeRating(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
}

void BSTPictures:: sortByDuration(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){
    
    vector<PictureNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){
            
            if(temp[j]->key.duration > temp[i]->key.duration){
                
                PictureNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeDuration(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
}

void BSTPictures:: sortByRelease(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node){
    
    vector<PictureNode *> temp;
    
    addToVector(temp, currentBST.Root());
    
    for(int j = 0; j < size; j++){
        
        for(int i = j + 1; i < size; i++){
            
            if(temp[j]->key.releaseMonth > temp[i]->key.releaseMonth){
                
                PictureNode * temp2;
                temp2 = temp[j];
                temp[j] = temp[i];
                temp[i]= temp2;
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        newSortedBST.addNodeRelease(temp[i]->key);
    }
    
    currentBST.setRoot(newSortedBST.Root());
}


PictureNode* BSTPictures:: completeSecondSearch(){
    seconds = true;
    
    BSTPictures temp;
    for (int i = 0; i < itemsFound.size(); i ++){
        temp.addNode(itemsFound[i]->key);
    }
    itemsFound.clear();
    cout <<"What type of search would you like to perform now?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Nominations" << endl;
    cout << "4. Rating" << endl;
    cout << "5. Duration" << endl;
    cout << "6. Genre 1" << endl;
    cout << "7. Genre 2" << endl;
    cout << "8. Release" << endl;
    cout << "9. Metacritic" << endl;
    cout << "10. Synopsis" << endl;
    
    int input;
    cin >> input;
    
    int search;
    string search2;
    double search3;
    
    cout <<"Enter your input:" << endl;
    
    if(input == 1){
        cin >> search2;
        completeSearchName(temp, search2);
    }

    else if(input == 2){
        cin >> search;
        completeSearchYear(temp, search);
    }

    else if(input == 3){
        cin >> search;
        completeSearchNominations(temp, search);

    }
    else if(input == 4){
        cin >> search3;
        completeSearchRating(temp, search3);
    }

    else if(input == 5){
        cin >> search;
        completeSearchDuration(temp, search);
    }

    else if(input == 6){
        cin >> search2;
        completeSearchGenre1(temp, search2);
    }

    else if(input == 7){
        cin >> search2;
        completeSearchGenre2(temp, search2);
    }

    else if(input == 8){
        cin >> search2;
        completeSearchRelease(temp, search2);
    }

    else if(input == 9){
        cin >> search;
        completeSearchMetacritic(temp, search);
    }

    else if(input == 10){
        cin >> search2;
        completeSearchSynopsis(temp, search2);
    }
    return nullptr;

}


PictureNode* BSTPictures:: partialSecondSearch(){
    bool modify = false;

    BSTPictures temp;
    for (int i = 0; i < itemsFound.size(); i ++){
        temp.addNode(itemsFound[i]->key);
    }
    itemsFound.clear();

    cout <<"What type of search would you like to perfor?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Nominations" << endl;
    cout << "4. Rating" << endl;
    cout << "5. Duration" << endl;
    cout << "6. Genre 1" << endl;
    cout << "7. Genre 2" << endl;
    cout << "8. Release" << endl;
    cout << "9. Metacritic" << endl;
    cout << "10. Synopsis" << endl;
    
    int input;
    cin >> input;
    
    int search;
    string search2;
    double search3;
    
    cout <<"Enter your input:" << endl;
    
    if(input == 1){
        cin >> search2;
        partialSearchName(temp, search2, modify);
    }
    
    else if(input == 2){
        cin >> search;
        partialSearchYear(temp, search, modify);
    }
    
    else if(input == 3){
        cin >> search;
        partialSearchNominations(temp, search, modify);
        
    }
    else if(input == 4){
        cin >> search3;
        partialSearchRating(temp, search3, modify);
    }
    
    else if(input == 5){
        cin >> search;
        partialSearchDuration(temp, search, modify);
    }
    
    else if(input == 6){
        cin >> search2;
        partialSearchGenre1(temp, search2, modify);
    }
    
    else if(input == 7){
        cin >> search2;
        partialSearchGenre2(temp, search2, modify);
    }
    
    else if(input == 8){
        cin >> search2;
        partialSearchRelease(temp, search2, modify);
    }
    
    else if(input == 9){
        cin >> search;
        partialSearchMetacritic(temp, search, modify);
    }
    
    else if(input == 10){
        cin >> search2;
        partialSearchSynopsis(temp, search2, modify);
    }
    return nullptr;
    
}



//searches (didn't have time to implement templetes or something for these to have less functions)

//name
PictureNode* BSTPictures:: completeSearchName(BSTPictures bst, string name){
    
    return completeSearchPrivateName(bst.Root(), name);
}


PictureNode * BSTPictures:: completeSearchPrivateName(PictureNode * node, string name){
    
    if (node == nullptr){ //if the search is over
        int input;

        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Name: " << itemsFound[i]->key.name << endl;
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

            completeSearchName(*this, name);
            return nullptr;

        }
    }
    
    else if (node->key.name == name){
        itemsFound.push_back(node);
        
    }
    
    
    if(name.compare(node->key.name) > 0){
        node->right = node-> right;
        return completeSearchPrivateName(node->right, name);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateName(node->left, name);
    }
    
   
    
}



PictureNode* BSTPictures:: partialSearchName(BSTPictures bst, string name, bool modify){
    
    return partialSearchPrivateName(bst.Root(), name, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateName(PictureNode *node, string name, bool modify){
    
    string temp = name;
    string temp2 = node->key.name;
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Name: " << itemsFound[i]->key.name << endl;
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
                
                partialSearchName(*this, name, modify);
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
        partialSearchPrivateName(node->left, name, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateName(node->right, name, modify);
    }

    return node;
}

//year

PictureNode* BSTPictures:: completeSearchYear(BSTPictures bst,int year){
    
    return completeSearchPrivateYear(bst.Root(), year);
}


PictureNode * BSTPictures:: completeSearchPrivateYear(PictureNode * node, int year){
    
    if (node == nullptr){
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Name: " << itemsFound[i]->key.name << " Year: " << itemsFound[i]->key.year << endl;
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
        return completeSearchPrivateYear(node->right, year);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateYear(node->left, year);
    }
}


PictureNode* BSTPictures:: partialSearchYear(BSTPictures bst,int year, bool modify){
    
    return partialSearchPrivateYear(bst.Root(), year, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateYear(PictureNode *node, int year, bool modify){
    
    string temp = to_string(year);
    string temp2 = to_string(node->key.year);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Name: " << itemsFound[i]->key.name << "Year: " << itemsFound[i]->key.year << endl;
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
        partialSearchPrivateYear(node->left, year, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateYear(node->right, year, modify);
    }
    return node;
}

//nominations

PictureNode* BSTPictures:: completeSearchNominations(BSTPictures bst,int nominations){
    
    return completeSearchPrivateNominations(bst.Root(), nominations);
}


PictureNode * BSTPictures:: completeSearchPrivateNominations(PictureNode * node, int nominations){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Nominations: "<< itemsFound[i]->key.nominations << " Name: " << itemsFound[i]->key.name << endl;
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

            completeSearchNominations(*this, nominations);
            return nullptr;
            
        }    }
    
    else if (node->key.nominations == nominations){
        itemsFound.push_back(node);
        
    }
    
    
    if(nominations < node->key.nominations ){
        node->right = node-> right;
        return completeSearchPrivateNominations(node->right, nominations);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateNominations(node->left, nominations);
    }
}


PictureNode* BSTPictures:: partialSearchNominations(BSTPictures bst,int nominations, bool modify){
    
    return partialSearchPrivateNominations(bst.Root(), nominations, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateNominations(PictureNode *node, int nominations, bool modify){
    
    string temp = to_string(nominations);
    string temp2 = to_string(node->key.nominations);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Nominations: "<< itemsFound[i]->key.nominations << " Name: " << itemsFound[i]->key.name << endl;
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

                partialSearchNominations(*this, nominations, modify);
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
        partialSearchPrivateNominations(node->left, nominations, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateNominations(node->right, nominations, modify);
    }
    return node;
}

//rating

PictureNode* BSTPictures:: completeSearchRating(BSTPictures bst,double rating){
    
    return completeSearchPrivateRating(bst.Root(), rating);
}


PictureNode * BSTPictures:: completeSearchPrivateRating(PictureNode * node, double rating){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Rating: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
            
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
            cout <<"Enter your new search for rating:" << endl;
            cin >> rating;
            itemsFound.clear();

            completeSearchRating(*this, rating);
            return nullptr;
            
        }

    
    }

    
    else if (node->key.rating == rating){
        itemsFound.push_back(node);
        
    }
    
    
    if(rating < node->key.rating ){
        node->right = node-> right;
        return completeSearchPrivateRating(node->right, rating);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateRating(node->left, rating);
    }
}


PictureNode* BSTPictures:: partialSearchRating(BSTPictures bst,double rating, bool modify){
    
    return partialSearchPrivateRating(bst.Root(), rating, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateRating(PictureNode *node, double rating, bool modify){
    
    string temp = to_string(rating);
    string temp2 = to_string(node->key.rating);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Rating: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
                
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
                cout <<"Enter your new search for rating:" << endl;
                cin >> rating;
                itemsFound.clear();

                partialSearchRating(*this, rating, modify);
                return nullptr;
                
            }
        }
        
        else{
            return nullptr;
        }
        
    }
    
    
    else if (temp2.find(temp) != std::string::npos){ // if found add to vector
        
        
        itemsFound.push_back(node);
        
    }
    
    if (node ->left != nullptr){
        partialSearchPrivateRating(node->left, rating, modify);
    }
    
    if (node->right!= nullptr){
        partialSearchPrivateRating(node->right, rating, modify);
    }
    return node;
}

//duration

PictureNode* BSTPictures:: completeSearchDuration(BSTPictures bst,int duration){
    
    return completeSearchPrivateDuration(bst.Root(), duration);
}


PictureNode * BSTPictures:: completeSearchPrivateDuration(PictureNode * node, int duration){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Duration: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
            
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
            cout <<"Enter your new search for duration:" << endl;
            cin >> duration;
            itemsFound.clear();

            completeSearchDuration(*this, duration);
            return nullptr;
            
        }
        
    }
    
    else if (node->key.duration == duration){
        itemsFound.push_back(node);
        
    }
    
    
    if(duration < node->key.duration ){
        node->right = node-> right;
        return completeSearchPrivateDuration(node->right, duration);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateNominations(node->left, duration);
    }
}


PictureNode* BSTPictures:: partialSearchDuration(BSTPictures bst,int duration, bool modify){
    
    return partialSearchPrivateNominations(bst.Root(), duration, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateDuration(PictureNode *node, int duration, bool modify){
    
    string temp = to_string(duration);
    string temp2 = to_string(node->key.duration);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Duration: "<< itemsFound[i]->key.rating << " Name: " << itemsFound[i]->key.name << endl;
                
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
                cout <<"Enter your new search for duration:" << endl;
                cin >> duration;
                itemsFound.clear();

                partialSearchDuration(*this, duration, modify);
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
        partialSearchPrivateDuration(node->left, duration, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateDuration(node->right, duration, modify);
    }
    return node;
}


//genre1
PictureNode* BSTPictures:: completeSearchGenre1(BSTPictures bst, string genre){
    
    return completeSearchPrivateGenre1(bst.Root(), genre);
}


PictureNode * BSTPictures:: completeSearchPrivateGenre1(PictureNode * node, string genre){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre1 << " Name: " << itemsFound[i]->key.name << endl;
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

            completeSearchGenre1(*this, genre);
            return nullptr;
            
        }
        
    }
    
    else if (node->key.genre1 == genre){
        itemsFound.push_back(node);
        
    }
    
    
    
    if(genre.compare(node->key.genre1) > 0){
        node->right = node-> right;
        return completeSearchPrivateGenre1(node->right, genre);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateGenre1(node->left, genre);
    }
}



PictureNode* BSTPictures:: partialSearchGenre1(BSTPictures bst, string genre, bool modify){
    
    return partialSearchPrivateGenre1(bst.Root(), genre, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateGenre1(PictureNode *node, string genre, bool modify){
    
    string temp = genre;
    string temp2 = node->key.genre1;

    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre1 << " Name: " << itemsFound[i]->key.name << endl;
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

               partialSearchGenre1(*this, genre, modify);
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
        partialSearchPrivateGenre1(node->left, genre, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateGenre1(node->right, genre, modify);
    }
    
    
    return node;
}

//genre2

PictureNode* BSTPictures:: completeSearchGenre2(BSTPictures bst, string genre){
    
    return completeSearchPrivateGenre2(bst.Root(), genre);
}


PictureNode * BSTPictures:: completeSearchPrivateGenre2(PictureNode * node, string genre){
    
    if (node == nullptr){
            int input;
        
        
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre2 << " Name: " << itemsFound[i]->key.name << endl;
                
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

                completeSearchGenre2(*this, genre);
                return nullptr;
                
            }
        }

    
    else if (node->key.genre2 == genre){
        itemsFound.push_back(node);
        
    }
    
    if(genre.compare(node->key.genre2) > 0){
        node->right = node-> right;
        return completeSearchPrivateGenre2(node->right, genre);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateGenre2(node->left, genre);
    }
}

PictureNode* BSTPictures:: partialSearchGenre2(BSTPictures bst, string genre, bool modify){
    
    return partialSearchPrivateGenre2(bst.Root(), genre, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateGenre2(PictureNode *node, string genre, bool modify){
    
    string temp = genre;
    string temp2 = node->key.genre2;
    
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Genre: "<< itemsFound[i]->key.genre2 << " Name: " << itemsFound[i]->key.name << endl;
                
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

                partialSearchGenre2(*this, genre, modify);
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
        partialSearchPrivateGenre2(node->left, genre, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateGenre2(node->right, genre, modify);
    }
    
    
    return node;
}


//Reelease
PictureNode* BSTPictures:: completeSearchRelease(BSTPictures bst,string release){
    
    return completeSearchPrivateName(bst.Root(), release);
}


PictureNode * BSTPictures:: completeSearchPrivateRelease(PictureNode * node, string release){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Release: "<< itemsFound[i]->key.releaseMonth << " Name: " << itemsFound[i]->key.name << endl;            }
        
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
            cout <<"Enter your new search for release:" << endl;
            cin >> release;
            itemsFound.clear();

            completeSearchRelease(*this, release);
            return nullptr;
            
        }
        
    }
    
    else if (node->key.name == release){
        itemsFound.push_back(node);
        
    }
    
    
    if(release.compare(node->key.releaseMonth) > 0){
        node->right = node-> right;
        return completeSearchPrivateName(node->right, release);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateRelease(node->left, release);
    }
}



PictureNode* BSTPictures:: partialSearchRelease(BSTPictures bst,string release, bool modify){
    
    return partialSearchPrivateRelease(bst.Root(), release, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateRelease(PictureNode *node, string release, bool modify){
    
    string temp = release;
    string temp2 = node->key.releaseMonth;
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Release: "<< itemsFound[i]->key.releaseMonth << " Name: " << itemsFound[i]->key.name << endl;            }
            
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
                cout <<"Enter your new search for release:" << endl;
                cin >> release;
                itemsFound.clear();

                partialSearchRelease(*this, release, modify);
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
        partialSearchPrivateRelease(node->left, release, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateRelease(node->right, release, modify);
    }
    
    
    return node;
}

//metacritic

PictureNode* BSTPictures:: completeSearchMetacritic(BSTPictures bst,int metacritic){
    
    return completeSearchPrivateMetacritic(bst.Root(), metacritic);
}


PictureNode * BSTPictures:: completeSearchPrivateMetacritic(PictureNode * node, int metacritic){
    
    if (node == nullptr){
        
        int input;
        
        
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            cout << i+1 << ". Metacritic: "<< itemsFound[i]->key.metacritic << " Name: " << itemsFound[i]->key.name << endl;
            
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
            cout <<"Enter your new search for metacritic:" << endl;
            cin >> metacritic;
            itemsFound.clear();

            completeSearchMetacritic(*this, metacritic);
            return nullptr;
            
        }
        
    }
    
    else if (node->key.metacritic == metacritic){
        itemsFound.push_back(node);
        
    }
    
    
    if(metacritic < node->key.metacritic ){
        node->right = node-> right;
        return completeSearchPrivateMetacritic(node->right, metacritic);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateMetacritic(node->left, metacritic);
    }
}


PictureNode* BSTPictures:: partialSearchMetacritic(BSTPictures bst,int metacritic, bool modify){
    
    return partialSearchPrivateMetacritic(bst.Root(), metacritic, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateMetacritic(PictureNode *node, int metacritic, bool modify){
    
    string temp = to_string(metacritic);
    string temp2 = to_string(node->key.metacritic);
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                cout << i+1 << ". Metacritic: "<< itemsFound[i]->key.metacritic << " Name: " << itemsFound[i]->key.name << endl;
                
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
                cout <<"Enter your new search for metacritic:" << endl;
                cin >> metacritic;
                itemsFound.clear();

                partialSearchMetacritic(*this, metacritic, modify);
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
        partialSearchPrivateMetacritic(node->left, metacritic, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateMetacritic(node->right, metacritic, modify);
    }
    return node;
}

//Synopsis
PictureNode* BSTPictures:: completeSearchSynopsis(BSTPictures bst,string synopsis){
    
    return completeSearchPrivateSynopsis(bst.Root(), synopsis);
}


PictureNode * BSTPictures:: completeSearchPrivateSynopsis(PictureNode * node, string synopsis){
    
    if (node == nullptr){
        
        int input;
    
        cout <<"These are the records found" << endl;
        for (int i = 0; i < itemsFound.size(); i++){
            string print;
            for(int j = 0; j < 20; j++){
                print = print + itemsFound[i]->key.synopsis[j];
            }
            
            cout << i+1<< " . Name: " << itemsFound[i]->key.name << " Synopsis: " << print << "..." <<endl;
            
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
            cout <<"Enter your new search for synopsis:" << endl;
            cin.ignore();
            getline(cin, synopsis);
            itemsFound.clear();
            completeSearchSynopsis(*this, synopsis);
            return nullptr;
            
        }    }
    
    else if (node->key.name == synopsis){
        itemsFound.push_back(node);
        
    }
    
    
    if(synopsis.compare(node->key.synopsis) > 0){
        node->right = node-> right;
        return completeSearchPrivateSynopsis(node->right, synopsis);
        
    }
    
    else {
        node->left = node->left;
        
        return completeSearchPrivateSynopsis(node->left, synopsis);
    }
}



PictureNode* BSTPictures:: partialSearchSynopsis(BSTPictures bst,string synopsis, bool modify){
    
    return partialSearchPrivateSynopsis(bst.Root(), synopsis, modify);
}


PictureNode * BSTPictures:: partialSearchPrivateSynopsis(PictureNode *node, string synopsis, bool modify){
    
    string temp = synopsis;
    string temp2 = node->key.synopsis;
    
    
    //found this line on cplusplus.com It will make the word being search all upper case which helps finding the word
    std::transform(temp.begin(), temp.end(), temp.begin(), std::ptr_fun<int, int>(toupper));
    std::transform(temp2.begin(), temp2.end(), temp2.begin(), std::ptr_fun<int, int>(toupper));
    
    if (node == nullptr){
        
        if (modify == false){
            int input;
            
            
            cout <<"These are the records found" << endl;
            for (int i = 0; i < itemsFound.size(); i++){
                string print;
                for(int j = 0; j < 20; j++){
                    print = print + itemsFound[i]->key.synopsis[j];
                }
                
                cout << i+1<< " . Name: " << itemsFound[i]->key.name << " Synopsis: " << print << "..." <<endl;
                
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
                cout <<"Enter your new search for synopsis:" << endl;
                cin.ignore();
                getline(cin, synopsis);
                itemsFound.clear();
                partialSearchSynopsis(*this, synopsis, modify);
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
        partialSearchPrivateSynopsis(node->left, synopsis, modify);
    }
    
    
    if (node->right!= nullptr){
        partialSearchPrivateSynopsis(node->right, synopsis, modify);
    }
    
    
    return node;
}
