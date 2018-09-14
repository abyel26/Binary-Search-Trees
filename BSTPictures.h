//Abyel Romero
//Binary search tree of pictures

#ifndef BSTPICTURESTREE_H
#define BSTPICTURESTREE_H

#include <iostream>
#include "Picture.h"
#include "PictureNode.h"
#include <vector>


using namespace std;

class BSTPictures{
    
private:
    
    int size;
    PictureNode * root;
    void addNodePrivate(PictureNode *node, Picture pic);
    PictureNode * deleteNodePrivate(PictureNode *node, Picture pic);
    void printInOrderPrivate(PictureNode * node, vector<int> searches);
    bool seconds;
    
    PictureNode* partialSearchPrivateName(PictureNode * node, string name, bool modify);
    PictureNode* completeSearchPrivateName(PictureNode * node, string name);
    
    PictureNode* partialSearchPrivateYear(PictureNode * node,int year, bool modify);
    PictureNode* completeSearchPrivateYear(PictureNode * node,int year);
    
    PictureNode* partialSearchPrivateNominations(PictureNode * node,int nominations, bool modify);
    PictureNode* completeSearchPrivateNominations(PictureNode * node,int nominations);
    
    PictureNode* partialSearchPrivateRating(PictureNode * node,double rating, bool modify);
    PictureNode* completeSearchPrivateRating(PictureNode * node,double rating);
    
    PictureNode* partialSearchPrivateDuration(PictureNode * node,int duration, bool modify);
    PictureNode* completeSearchPrivateDuration(PictureNode * node,int duration);
    
    PictureNode* partialSearchPrivateGenre1(PictureNode * node,string genre, bool modify);
    PictureNode* completeSearchPrivateGenre1(PictureNode * node,string genre);
    
    PictureNode* partialSearchPrivateGenre2(PictureNode * node,string genre, bool modify);
    PictureNode* completeSearchPrivateGenre2(PictureNode * node,string genre);
    
    PictureNode* partialSearchPrivateRelease(PictureNode * node,string release, bool modify);
    PictureNode* completeSearchPrivateRelease(PictureNode * node,string release);
    
    PictureNode* partialSearchPrivateMetacritic(PictureNode * node,int metacritic, bool modify);
    PictureNode* completeSearchPrivateMetacritic(PictureNode * node,int metacritic);
    
    PictureNode* partialSearchPrivateSynopsis(PictureNode * node,string synopsis, bool modify);
    PictureNode* completeSearchPrivateSynopsis(PictureNode * node,string synopsis);
    
    void saveAsOrOverwritePrivate(PictureNode * node, ofstream & out);

    
    PictureNode * partialSecondSearch();
    PictureNode * completeSecondSearch();
    
    void addToVector(vector <PictureNode *> & temp, PictureNode * temp2);
    vector<PictureNode*> itemsFound;
    
    PictureNode* setParameters(PictureNode * node, Picture temp);

    void addNodeYearPrivate(PictureNode * node, Picture pic);
    void addNodeMovieNamePrivate(PictureNode * node, Picture pic);
    void addNodeNominationsPrivate(PictureNode * node, Picture pic);
    void addNodeRatingPrivate(PictureNode * node, Picture pic);
    void addNodeDurationPrivate(PictureNode * node, Picture pic);
    void addNodeReleasePrivate(PictureNode * node, Picture pic);

    
public:
    
    
    void addNodeYear(Picture pic);
    void addNodeNominations( Picture pic);
    void addNodeRating(Picture pic);
    void addNodeDuration(Picture pic);
    void addNodeRelease(Picture pic);
    
    BSTPictures();
//    ~BSTPictures();
    
    PictureNode* Root();
    void setRoot(PictureNode *_root);


    
    void addNode(Picture pic);
    void deleteNode(Picture pic);
    void deleteMainMenu();
    void printInOrder(); //I think I'll provide a menu for them to choose what to print
    
    
    PictureNode* partialSearchName(BSTPictures bst,string name, bool modify);
    PictureNode* completeSearchName(BSTPictures bst, string name);
    
    PictureNode* partialSearchYear(BSTPictures bst,int year, bool modify);
    PictureNode* completeSearchYear(BSTPictures bst,int year);
    
    PictureNode* partialSearchNominations(BSTPictures bst,int nominations, bool modify);
    PictureNode* completeSearchNominations(BSTPictures bst,int nominations);

    PictureNode* partialSearchRating(BSTPictures bst,double rating, bool modify);
    PictureNode* completeSearchRating(BSTPictures bst,double rating);
    
    PictureNode* partialSearchDuration(BSTPictures bst,int duration, bool modify);
    PictureNode* completeSearchDuration(BSTPictures bst, int duration);
    
    PictureNode* partialSearchGenre1(BSTPictures bst,string genre, bool modify);
    PictureNode* completeSearchGenre1(BSTPictures bst,string genre);
    
    PictureNode* partialSearchGenre2(BSTPictures bst,string genre, bool modify);
    PictureNode* completeSearchGenre2(BSTPictures bst,string genre);
    
    PictureNode* partialSearchRelease(BSTPictures bst,string release, bool modify);
    PictureNode* completeSearchRelease(BSTPictures bst,string release);
    
    PictureNode* partialSearchMetacritic(BSTPictures bst,int metacritic, bool modify);
    PictureNode* completeSearchMetacritic(BSTPictures bst,int metacritic);
    
    PictureNode* partialSearchSynopsis(BSTPictures bst,string synopsis, bool modify);
    PictureNode* completeSearchSynopsis(BSTPictures bst,string synopsis);
    
    
    
   
    void readFile();//read pictures.csv
    
    void outputSearchReport();

    
    void modifyInfo(); //later
    
    void saveAs();
    void overwrite();
    
    
    void sortByMovieName(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);
    void sortByYear(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);
    void sortByNominations(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);
    void sortByRating(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);
    void sortByDuration(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);
    void sortByRelease(BSTPictures & currentBST, BSTPictures & newSortedBST, PictureNode * node);

    
    
    PictureNode* min(PictureNode* node);

    
    
};



#endif

