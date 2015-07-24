#include <iostream>
#include <cstdlib>
#include "tree.h"
using namespace std;
cBST::cBST()
{
    root = NULL;
}

cBST::node* cBST::createLeaf(int key)
{
    node* n = new node();
    n->key = key;
    n->right = NULL;
    n->left = NULL;
    return n;
}

void cBST::addLeaf(int key)
{
    addLeafPrivate(key, root);
}

void cBST::addLeafPrivate(int key, node* Ptr)
{
    if(root == NULL)
    {
        root = createLeaf(key);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left!=NULL)
        {
            addLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = createLeaf(key);
        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right!=NULL)
        {
            addLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = createLeaf(key);
        }
    }
    else
    {
        cout << "Key " << key << "already added in the tree\n";
    }
}

void cBST::printOrder()
{
    printOrderPrivate(root);
}

void cBST::printOrderPrivate(node *Ptr)
{
    if(root!=NULL)
    {
        if(Ptr->left!=NULL)
        {
            printOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if(Ptr->right!=NULL)
        {
            printOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "Tree are empty\n";
    }
}

void cBST::printPreOrder()
{
    printPreOrderPrivate(root);
}

void cBST::printPreOrderPrivate(node *Ptr)
{
    if(root!=NULL)
    {
        if(Ptr->right!=NULL)
        {
            printPreOrderPrivate(Ptr->right);
        }
        cout << Ptr->key << " ";
        if(Ptr->left!=NULL)
        {
            printPreOrderPrivate(Ptr->left);
        }
    }
    else
    {
        cout << "Tree are empty\n";
    }
}

cBST::node* cBST::ReturnPtrToNode(int key)
{
    return ReturnPtrToNodePrivate(key, root);
}

cBST::node* cBST::ReturnPtrToNodePrivate(int key, node* Ptr)
{
    if(Ptr!=NULL)
    {
        if(Ptr->key == key)
        {
            return Ptr;
        }
        else if(key<Ptr->key)
        {
            return ReturnPtrToNodePrivate(key,Ptr->left);
        }
        else
        {
            return ReturnPtrToNodePrivate(key,Ptr->right);
        }
    }
    else
    return NULL;
}

int cBST::ReturnRootKey()
{
    if(root!=NULL)
    return root->key;
    else
    return -1;
}

void cBST::PrintChildren(int key)
{
    node* Ptr = ReturnPtrToNode(key);
    if(Ptr!=NULL)
    {
        cout << "\nParent " << Ptr->key <<endl;
        Ptr->left == NULL ? cout << "Left child NULL\n"
        : cout << "Key left child " << Ptr->left->key << endl;

        Ptr->right == NULL ? cout << "Left child NULL\n"
        : cout << "Key left child " << Ptr->right->key << endl;
    }
    else
    cout << "Key " << key << " is not in the tree\n";
}

int cBST::FindSmallestKey()
{
    return FindSmallestKeyPrivate(root);
}

int cBST::FindSmallestKeyPrivate(node* Ptr)
{
    if(root == NULL) return -1;
    else
    {
        if(Ptr->left != NULL)
        return FindSmallestKeyPrivate(Ptr->left);
        else
        return Ptr->key;
    }
}

void cBST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void cBST::RemoveNodePrivate(int key, node* parent)
{
    if(root!=NULL)
    {
        if(root->key == key)//debug root->key = 50
        {
            RemoveRootMatch();
        }
        else
        {
            if(key < parent->key && parent->left!=NULL)
            {
                int parentKey = parent->key;
                if(parent->left->key == key)
                {
                    RemoveMatch(parent, parent->left,true);
                }
                else
                {
                    RemoveNodePrivate(key, parent->left);
                }
            }
            else if(key > parent->key && parent->right!=NULL)
            {
                int parentKey = parent->key;
                //parent->key = 4//parent = 038
                if(parent->right->key == key)//parent->right->key = 15
                {
                    RemoveMatch(parent, parent->right,false);
                }
                else
                {
                    RemoveNodePrivate(key, parent->right);
                }

            }
            else
            {
                cout << "Key " << key << " not found in tree\n";
            }
        }
    }
    else
    {
        cout << "Tree empty\n";
    }
}



void cBST::RemoveMatch(node *parent, node* match, bool left)
{ //bool indicate relationship beetween parent and match
    if(root!=NULL)
    {
        node* delPtr;// parent 038; match 068
        int matchKey = match->key;//matchKey(match ptr) is key to delete
        int parentKey = parent->key;//parent(parent ptr) key of matchKey
        int smallestInRightSubTree;
        //case 0 children
        if(match->left == NULL && match->right == NULL)
        {//RemoveMatch(parent, parent->left,true)
            left == true ? parent->left = NULL : parent->right = NULL;
            cout << "The node contain key " << matchKey <<
            " was rm(no child)\n";
        }
        //case 1
        else if(match->left == NULL && match->right != NULL)
        {
            left == true
            ? parent->left = match->right
            :parent->right = match->right;
            match->right = NULL;
            cout << "The node contain key " << matchKey <<
            " was rm(1 right child )\n";
        }
        else if(match->left != NULL && match->right == NULL)
        {
            left == true ? parent->left = match->left
            : parent->right = match->left;
            match->left = NULL;
            cout << "The node contain key " << matchKey <<
            " was rm\n(1 left child)";
        }
        //case 2 child
        else
        {
            int matchKeySmallest = match->key;
            smallestInRightSubTree = FindSmallestKeyPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubTree, match);
            match->key = smallestInRightSubTree;// replace deledted node vs smallest node
        }
    }
    else
    {
        cout << "Can't rm match. Tree is empty\n";
    }
}

void cBST::RemoveRootMatch()
{
    if(root!=NULL)
    {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;
        //case 0 left NULL right NULL
        if(delPtr->left == NULL && delPtr->right)
        {
            root = NULL;
            delete delPtr;
        }
        //case 1 left NULL right != NULL
        if(delPtr->left == NULL && delPtr->right !=NULL)
        {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted"
                    << "\nNew root key is " << root->key << endl;
        }
        //case 1 left !=NULL right == NULL
        if(delPtr->left != NULL && delPtr->right == NULL)
        {
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted"
                    << "\nNew root key is " << root->key << endl;
        }
        //case 1 wife 2 child
        else
        {
            smallestInRightSubtree = FindSmallestKeyPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key contain key " << rootKey <<
                    " was overwritten by " << root->key << endl;
        }
    }
    else
    {
        cout << "Can't rm root. The tree is empty\n" << endl;
    }
}
