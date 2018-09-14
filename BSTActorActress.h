//Abyel Romero
//Binary search tree of actor-actress

#ifndef BSTACTORACTRESS_H
#define BSTACTORACTRESS_H

#include <iostream>
#include "ActorActress.h"
#include "ActorActressNode.h"
#include <vector>


using namespace std;

class BSTActorActress{
    
private:
    
    int size;
    ActorActressNode * root;
    void addNodePrivate(ActorActressNode *node, ActorActress pic);
    ActorActressNode * deleteNodePrivate(ActorActressNode *node, ActorActress pic);
    void printInOrderPrivate(ActorActressNode * node, vector<int> searches);
    bool seconds;
    
  
    void saveAsOrOverwritePrivate(ActorActressNode * node, ofstream & out);
    
    
    ActorActressNode* partialSearchActorNamePrivate(ActorActressNode * node,string name, bool modify);
    ActorActressNode* completeSearchActorNamePrivate(ActorActressNode * node, string name);
    
    ActorActressNode* partialSearchYearPrivate(ActorActressNode * node,int year, bool modify);
    ActorActressNode* completeSearchYearPrivate(ActorActressNode * node,int year);
    
    ActorActressNode* partialSearchWinnerPrivate(ActorActressNode * node,int nominations, bool modify);
    ActorActressNode* completeSearchWinnerPrivate(ActorActressNode * node,int nominations);
    
    
    ActorActressNode* partialSearchAwardPrivate(ActorActressNode * node,string release, bool modify);
    ActorActressNode* completeSearchAwardPrivate(ActorActressNode * node,string release);
    
    ActorActressNode* partialSearchFilmPrivate(ActorActressNode * node,string synopsis, bool modify);
    ActorActressNode* completeSearchFilmPrivate(ActorActressNode * node,string synopsis);
    
    
    ActorActressNode * partialSecondSearch();
    ActorActressNode * completeSecondSearch();
    
    
    
    
    void addToVector(vector <ActorActressNode *> & temp, ActorActressNode * temp2);

    
    vector<ActorActressNode*> itemsFound;
    
    ActorActressNode* setParameters(ActorActressNode * node, ActorActress temp);
    
    void addNodeYearPrivate(ActorActressNode * node, ActorActress actor);
    void addNodeAwardPrivate(ActorActressNode * node, ActorActress actor);
    
public:
    
    void addNodeYear(ActorActress actor);
    void addNodeAward(ActorActress actor);
    
    
    BSTActorActress();
    //    ~BSTPictures();
    
    ActorActressNode* Root();
    void setRoot(ActorActressNode *_root);
    
    
    
    void addNode(ActorActress pic);
    void deleteNode(ActorActress pic);
    void deleteMainMenu();
    
    void printInOrder(); //I think I'll provide a menu for them to choose what to print
    
    
    ActorActressNode* partialSearchActorName(BSTActorActress bst,string name, bool modify);
    ActorActressNode* completeSearchActorName(BSTActorActress bst, string name);
    
    ActorActressNode* partialSearchYear(BSTActorActress bst,int year, bool modify);
    ActorActressNode* completeSearchYear(BSTActorActress bst,int year);
    
    ActorActressNode* partialSearchWinner(BSTActorActress bst,int nominations, bool modify);
    ActorActressNode* completeSearchWinner(BSTActorActress bst,int nominations);
    
 
    ActorActressNode* partialSearchAward(BSTActorActress bst,string release, bool modify);
    ActorActressNode* completeSearchAward(BSTActorActress bst,string release);
    
    ActorActressNode* partialSearchFilm(BSTActorActress bst,string synopsis, bool modify);
    ActorActressNode* completeSearchFilm(BSTActorActress bst,string synopsis);
    
    
    
    void readFile();//read pictures.csv
    
    void outputSearchReport();
    
    
    void modifyInfo();
    
    void saveAs();
    void overwrite();
    
    
    void sortByYear(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node);
    void sortByAward(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node);

    void sortByActorName(BSTActorActress & currentBST, BSTActorActress & newSortedBST, ActorActressNode * node);

    ActorActressNode * min(ActorActressNode* node);
    
};



#endif

