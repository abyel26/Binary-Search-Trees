// Abyel Romero
// Tree Final Project


#include <iostream>

#include "PictureNode.h"
#include "ActorActressNode.h"
#include "ActorActress.h"
#include "BSTPictures.h"
#include "BSTActorActress.h"

int main() {
  
    BSTPictures bstPicture;
    BSTActorActress bstActor;
    cout <<"Welcome!" << endl << endl;
    bstPicture.readFile();
    bstActor.readFile();
    
    string  input;
    while(true){
    
        cout << "What would you like to perform?" << endl;
        cout <<"a. Print Pictures Binary Search Tree." << endl;
        cout <<"b. Print Actor-Actress Binary Search Tree." << endl;
        cout <<"c. Add a new record to Pictures BST." << endl;
        cout << "d. Add a new record to Actor-Actress BST." << endl;
        cout << "e. Search for a record on the Pictures BST." << endl;
        cout << "f. Search for a record on the Actor-Actress BST." << endl;
        cout << "g. Sort Pictures BST." << endl;
        cout << "h. Sort Actor-Actress BST." << endl;
        cout << "i. Modify a record on the Pictures BST." << endl;
        cout << "j. Modify a record on the Actor-Actress BST." << endl;
        cout << "k. Delete a record on the Pictures BST." << endl;
        cout << "l. Delete a record on the Actor-Actress BST." << endl;
        cout << "m. Output report for Pictures BST." << endl;
        cout << "n. Output report for Actor-Actress BST." << endl;
        cout << "o. Write to file for Pictrues BST." << endl;
        cout << "p. Write to file for Actor-Actress BST." << endl;
        cout << "q. Exit." << endl;
        
        cin >> input;
        cout << "\n\n";

        if(input == "a"){
            
            bstPicture.printInOrder();
        }
        
        else if(input == "b"){
            bstActor.printInOrder();
        }
        
        else if(input == "c"){
            
            string name, genre1, genre2, release, synopsys;
            int year, nomination, duration, metacritic;
            double rating;
            
            Picture pic;
            cout << "Enter the movie name for the new record:" << endl;
            cin.ignore();
            getline(cin, name);
            
            pic.name = name;
            cout << "Enter the year:" << endl;
            cin >> year;
            pic.year = year;
            cout << "Enter the nominations:" << endl;
            cin >> nomination;
            pic.nominations = nomination;
            cout << "Enter the rating:" << endl;
            cin >> rating;
            pic.rating = rating;
            cout << "Enter the duration:" << endl;
            cin >> duration;
            pic.duration = duration;
            cout << "Enter the genre 1:" << endl;
            cin >> genre1;
            pic.genre1 = genre1;
            cout << "Enter the genre 2:" << endl;
            cin >> genre2;
            pic.genre2 = genre2;
            cout << "Enter the release month:" << endl;
            cin >> release;
            pic.releaseMonth = release;
            cout << "Enter the metacritic score:" << endl;
            cin >> metacritic;
            pic.metacritic= metacritic;
            cout << "Enter the synopsis:" << endl;
            
            cin.ignore();
            getline(cin, synopsys);
            
            pic.synopsis = synopsys;
            
            
            bstPicture.addNode(pic);
        }
        
        else if(input == "d"){
            string name, film, award;
            int year, winner;
            
            ActorActress actor;
            cout << "Enter the actor or actress name for the new record:" << endl;
            cin.ignore();
            getline(cin, name);
            actor.actorName = name;
            cout << "Enter the year:" << endl;
            cin >> year;
            actor.year= year;
            cout << "Enter the award:" << endl;
            cin.ignore();
            getline(cin, award);
            actor.award = award;
            cout << "Enter if winner:" << endl;
            cin >> winner;
            
            actor.winner = winner;
            cout << "Enter the film name:" << endl;
            cin.ignore();
            getline(cin, film);
            
            actor.film = film;
            bstActor.addNode(actor);

        }
        
        else if(input == "e"){
            
            int input, input2;
            cout << "What type of search would you like to perform?" << endl;
            cout <<"1. Partial" << endl;
            cout << "2. Complete" << endl;
            cin >> input;
            
            cout <<"What would you like to search for" << endl;
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
            cin >> input2;
            
            cout << "Enter your input:" << endl;
            
            if(input2 == 1){
                string name;
                cin.ignore();
                getline(cin, name);
                
                if(input == 1){
                    bstPicture.partialSearchName(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchName(bstPicture, name);
                }
                
            }
            
            else if(input2 == 2){
                int  name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchYear(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchYear(bstPicture, name);
                }
                
            }
            
          else  if(input2 == 3){
                int name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchNominations(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchNominations(bstPicture, name);
                }
                
            }
            
           else if(input2 == 4){
                double name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchRating(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchRating(bstPicture, name);
                }            }
            
          else  if(input2 == 5){
                int name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchDuration(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchDuration(bstPicture, name);
                }            }
            
            else if(input2 == 6){
                string name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchGenre1(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchGenre1(bstPicture, name);
                }            }
            
           else if(input2 == 7){
                string name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchGenre2(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchGenre2(bstPicture, name);
                }            }
            
            else if(input2 == 8){
                string name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchRelease(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchRelease(bstPicture, name);
                }
                
            }
            
            else if(input2 == 9){
                int name;
                cin >> name;
                
                if(input == 1){
                    bstPicture.partialSearchMetacritic(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchMetacritic(bstPicture, name);
                }
                
            }
            
            else if(input2 == 10){
                string name;
                cin.ignore();
                getline(cin, name);
                
                if(input == 1){
                    bstPicture.partialSearchSynopsis(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchSynopsis(bstPicture, name);
                }
                
            }
            
            else{
                cout << "Enter a valid input." << endl;
            }
            
            
        }
        
        else if(input == "f"){
            int input, input2;
            cout << "What type of search would you like to perform?" << endl;
            cout <<"1. Partial" << endl;
            cout << "2. Complete" << endl;
            cin >> input;
            
            cout <<"What would you like to search for" << endl;
            cout << "1. Actor Name" << endl;
            cout << "2. Year" << endl;
            cout << "3. Winner" << endl;
            cout << "4. Award" << endl;
            cout << "5. Film" << endl;
            cin >> input2;
            
            cout << "Enter your input:" << endl;
            
            if(input2 == 1){
                string name;
                cin.ignore();
                getline(cin, name);
                
                if(input == 1){
                    bstPicture.partialSearchName(bstPicture, name, false);
                }
                
                else if(input == 2){
                    bstPicture.completeSearchName(bstPicture, name);
                }
                
            }
            
            else if(input2 == 2){
                int  name;
                cin >> name;
                
                if(input == 1){
                    bstActor.partialSearchYear(bstActor, name, false);
                }
                
                else if(input == 2){
                    bstActor.completeSearchYear(bstActor, name);
                }
                
            }
            
            else if(input2 == 3){
                int name;
                cin >> name;
                
                if(input == 1){
                    bstActor.partialSearchWinner(bstActor, name, false);
                }
                
                else if(input == 2){
                    bstActor.completeSearchWinner(bstActor, name);
                }
                
            }
            
            else if(input2 == 4){
                string name;
                cin >> name;
                
                if(input == 1){
                    bstActor.partialSearchAward(bstActor, name, false);
                }
                
                else if(input == 2){
                    bstActor.completeSearchAward(bstActor, name);
                }
                
            }
            
           else if(input2 == 5){
                string name;
                cin >> name;
                
                if(input == 1){
                    bstActor.partialSearchFilm(bstActor, name, false);
                }
                
                else if(input == 2){
                    bstActor.completeSearchFilm(bstActor, name);
                }
                
            }
   
        }
        
        else if(input == "g"){
            BSTPictures tempBST;
            
            cout <<"What kind of sort would you like to perform?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Year" << endl;
            cout << "3. Nominations" << endl;
            cout << "4. Rating" << endl;
            cout << "5. Duration" << endl;
            cout << "6. Release" << endl;
            int input;
            cin >> input;
            
            cout << "Enter your input:" << endl;
            
            if(input == 1){
              
                bstPicture.sortByMovieName(bstPicture, tempBST, bstPicture.Root());

            }
            
            else if(input == 2){
                bstPicture.sortByYear(bstPicture, tempBST, bstPicture.Root());

                
            }
            
            if(input == 3){
                bstPicture.sortByNominations(bstPicture, tempBST, bstPicture.Root());

                
            }
            
            if(input == 4){
                bstPicture.sortByRating(bstPicture, tempBST, bstPicture.Root());

                
            }
            
            if(input == 5){
                bstPicture.sortByDuration(bstPicture, tempBST, bstPicture.Root());

            }
            
            if(input == 6){
                bstPicture.sortByRelease(bstPicture, tempBST, bstPicture.Root());

            }
            
            else{
                cout << "Enter a valid input" << endl;
            }
          

        }
        
        else if(input == "h"){
            BSTActorActress tempBST;
            
            cout <<"What kind of sort would you like to perform?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Year" << endl;
            cout << "3. Award" << endl;
            
            int input;
            cin >> input;
            
            cout << "Enter your input:" << endl;
            
            if(input == 1){
                
                bstActor.sortByActorName(bstActor, tempBST, bstActor.Root());
                
            }
            
            else if(input == 2){
                bstActor.sortByYear(bstActor, tempBST, bstActor.Root());
            }
            
            else if(input == 3){
                bstActor.sortByAward(bstActor, tempBST, bstActor.Root());
            }
            
            else{
                cout << "Enter a valid input" << endl;
            }
        }
        
        else if(input == "i"){
            bstPicture.modifyInfo();
        }
        
        else if(input == "j"){
            bstActor.modifyInfo();
        }
        
        else if(input == "k"){
            bstPicture.deleteMainMenu();
        }
        
        else if(input == "l"){
            bstActor.deleteMainMenu();
        }
        
        else if(input == "m"){
            bstPicture.outputSearchReport();
        }
        
        else if(input == "n"){
            bstActor.outputSearchReport();
            
        }
        
        else if(input == "o"){
            cout <<"What kind of output do you want to perform?" << endl;
            cout <<"1. Save as" << endl;
            cout <<"2. Overwrite " << endl;
            int in;
            cin >> in;
            
            if( in == 1){
                bstPicture.saveAs();
            }
            
            else if(in == 2){
                bstPicture.overwrite();
                
            }
            
            else{
                cout << "Enter a valid input" << endl;
            }
        }
        
        else if(input == "p"){
            
            cout <<"What kind of output do you want to perform?" << endl;
            cout <<"1. Save as" << endl;
            cout <<"2. Overwrite " << endl;
            int in;
            cin >> in;
            
            if( in == 1){
                bstActor.saveAs();
            }
            
            else if(in == 2){
                bstActor.overwrite();
                
            }
            
            else{
                cout << "Enter a valid input" << endl;
            }
        }
        
        
        else if (input == "q"){
            cout << "See you later." << endl << endl;
            exit(0);
            
        }
        else{
            cout << "Enter a valid selection." << endl << endl;
            
        }

        
        
    }
    
    
}
