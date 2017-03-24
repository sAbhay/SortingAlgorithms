#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i = 0; i < length; i++)
    {
        n[i] = (int) rand() % ofGetHeight()/2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    ofSetColor(255);
    
    for(int i = 0; i < length; i++)
    {
        ofDrawRectangle((ofGetWidth()/length)*i, ofGetHeight() - n[i], ofGetWidth()/length, n[i]);
    }
    
    MergeSort(0, length);
}

void ofApp::BubbleSort()
{
    if(cycleCount <= length) // bubble sort
    {
        for(int i = 0; i < length-1-cycleCount; i++)
        {
            if(n[i] > n[i+1])
            {
                int temp = n[i];
                
                n[i] = n[i+1];
                n[i+1] = temp;
            }
        }
    }
    
    cycleCount++;
}

void ofApp::CocktailSort()
{
    //for(int i = 0; i < length/2; i++) //cocktail shaker sort
    {
        //        bool swapped = false;
        
        for(int j = length - cycleCount; j > cycleCount; j--)
        {
            if(n[j] > n[j-1])
            {
                int temp = n[j];
                
                n[j] = n[j-1];
                n[j-1] = temp;
                
//              swapped = true;
            }
        }
        
        for(int j = cycleCount; j < length - cycleCount; j++)
        {
            if(n[j] < n[j+1])
            {
                int temp = n[j];
                
                n[j] = n[j+1];
                n[j+1] = temp;
                
//              swapped = true;
            }
        }
        
        cycleCount++;
        
        // if(!swapped) break;
    }
}

void ofApp::SinghalSort()
{
    for(int i = 1; i < length-1-cycleCount; i++) //Singhal sort
    {
        ofSetColor(255);
    
        if(n[i] > n[i+1])
        {
            int temp = n[i];
            
            n[i] = n[i+1];
            n[i+1] = temp;
        }
        
        if(n[i] < n[i-1])
        {
            int temp = n[i];
            
            n[i] = n[i-1];
            n[i-1] = temp;
        }
        
        ofDrawRectangle((ofGetWidth()/length)*i, ofGetHeight() - n[i], ofGetWidth()/length, n[i]);
    }
    
    cycleCount++;
}

void ofApp::IdkSort()
{
    for(int i = 0; i < length/mergeCycles; i+=mergeCycles)
    {
        for(int j = 0; j < length/mergeCycles; j+=mergeCycles)
        {
    
            if(i != j)
            {
                if(n[i] < n[j])
                {
                    int temp = n[i];
                    
                    n[i] = n[j];
                    n[j] = temp;
                }
            }
        }
    }
    
    mergeCycles++;
}

void ofApp::MergeSort(int low, int high)
{
    int mid;
    
    if(low < high)
    {
        mid = (low + high)/2;
        MergeSort(low, mid);
        MergeSort(mid+1, high);
        Merge(low, mid, high);
    }
}

void ofApp::Merge(int low, int mid, int high)
{
    int h, i, j, b[1440];
    h = low;
    i = low;
    j = mid+1;
    
    while(h <= mid && j <= high)
    {
        if(n[h] <= n[j])
        {
            b[i] = n[h];
            h++;
        }
        else
        {
            b[i] = n[j];
            j++;
        }
    i++;
    }
    
    if(h > mid)
    {
        for(int k = j; k <= high; k++)
        {
            b[i] = n[k];
            i++;
        }
    }
    else
    {
        for(int k = h; k <= high; k++)
        {
            b[i] = n[k];
            i++;
        }
    }
    
    for(int k = low; k <= high; k++)
    {
        n[k] = b[k];
    }
}
