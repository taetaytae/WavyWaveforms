//
//  interface.cpp
//  PMCMiniProject
//
//  Created by Mario A. Sánchez on 25/12/2018.
//

#include "interface.hpp"
#include <string>

interface::interface(){
    
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    gui.setup("Frequency","settings.xml",ofGetWidth()/1.6,ofGetHeight()/6);
    
    guiCheck = false;
    
}

//------------------------------
void interface::setupGUI(ofParameter<float> fundamental){
    
    gui.add(fundamental);
    
}

//------------------------------
void interface::drawCanvas(){
    
    //Update Font Size if Window Size Changes
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    gui.setPosition(ofGetWidth()/1.6, ofGetHeight()/6);
    
    //Bottom
    ofSetColor(155, 255, 155);
    ofDrawRectangle(0, ofGetHeight()-ofGetHeight()/30, ofGetWidth(), ofGetHeight()/25);
    //Top
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()/30);
    //Right
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()-ofGetWidth()/40, 0, ofGetWidth()/30, ofGetHeight());
    //Left
    ofDrawRectangle(0, 0, ofGetWidth()/40, ofGetHeight());
    
}

//------------------------------
void interface::drawWaveBackground(){
    
    ofSetColor(240,240,240);
    ofDrawRectangle(ofGetWidth()/5, ofGetHeight()/6, ofGetWidth()/1.6, ofGetHeight()/2.6);
    
    ofSetColor(0);
    myFont.drawString("Waveform", ofGetWidth()/5, ofGetHeight()/6.5);
    
    
}

//------------------------------
void interface::drawUI(int squareHarmonics, int sawHarmonics, int triangleHarmonics){
    
    //Information Panel
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/25, ofGetHeight()/10, ofGetWidth()/7, ofGetHeight()/1.8);
    //Information Panel Text
    ofSetColor(0);
    myFont.drawString("Info Panel", ofGetWidth()/16, ofGetHeight()/11);
    
    //Sampling Rate Title Panel
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/25, ofGetHeight()/1.4, ofGetWidth()/7, ofGetHeight()/7);
    //Sampling Rate Buttons
    ofSetColor(155, 255, 155);
    ofDrawRectangle(ofGetWidth()/25, ofGetHeight()/1.15, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    ofDrawRectangle(ofGetWidth()/8.3, ofGetHeight()/1.15, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    //Sampling Rate Text
    ofSetColor(0);
    myFont.drawString("Sampling Rate", ofGetWidth()/21, ofGetHeight()/1.43);
    //
    myFont.load("Ardour3d.ttf", ofGetWidth()/70);
    //
    myFont.drawString("44,100", ofGetWidth()/21, ofGetHeight()/1.114);
    myFont.drawString("88,200", ofGetWidth()/7.8, ofGetHeight()/1.114);
    
    //Frequency Panel
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/1.195, ofGetHeight()/6, ofGetWidth()/8, ofGetHeight()/7);
    //Amplitude Panel
    ofDrawRectangle(ofGetWidth()/1.195, ofGetHeight()/2.8, ofGetWidth()/8, ofGetHeight()/7);
    //Frequency/Amplitude Text
    ofSetColor(0);
    myFont.drawString("Frequency", ofGetWidth()/1.175, ofGetHeight()/2.97);
    myFont.drawString("Amplitude", ofGetWidth()/1.170, ofGetHeight()/1.89);
    
    //Square Wave Panel
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/4, ofGetHeight()/1.5, ofGetWidth()/7, ofGetHeight()/7);
    //Square Wave Buttons
    ofSetColor(155, 255, 155);
    ofDrawRectangle(ofGetWidth()/4, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    ofDrawRectangle(ofGetWidth()/3.03, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    //Square Wave Text
    ofSetColor(0);
    myFont.drawString("Square", ofGetWidth()/3.45, ofGetHeight()/1.53);
    //
    myFont.load("Ardour3d.ttf", ofGetWidth()/20);
    //
    myFont.drawString("-", ofGetWidth()/3.70, ofGetHeight()/1.17);
    myFont.drawString("+", ofGetWidth()/2.90, ofGetHeight()/1.17);
    
    //Saw Wave Panel
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/1.5, ofGetWidth()/7, ofGetHeight()/7);
    //Saw Wave Buttons
    ofSetColor(155, 255, 155);
    ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    ofDrawRectangle(ofGetWidth()/1.72, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    //Saw Wave Text
    ofSetColor(0);
    myFont.drawString("Saw", ofGetWidth()/1.82, ofGetHeight()/1.53);
    //
    myFont.load("Ardour3d.ttf", ofGetWidth()/20);
    //
    myFont.drawString("-", ofGetWidth()/1.925, ofGetHeight()/1.17);
    myFont.drawString("+", ofGetWidth()/1.68, ofGetHeight()/1.17);
    
    //Triangle Wave Panel
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    ofSetColor(255, 155, 255);
    ofDrawRectangle(ofGetWidth()/1.3, ofGetHeight()/1.5, ofGetWidth()/7, ofGetHeight()/7);
    //Triangle Wave Buttons
    ofSetColor(155, 255, 155);
    ofDrawRectangle(ofGetWidth()/1.3, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    ofDrawRectangle(ofGetWidth()/1.177, ofGetHeight()/1.22, (ofGetWidth()/7)/2.3, (ofGetHeight()/7)/4);
    //Saw Wave Text
    ofSetColor(0);
    myFont.drawString("Triangle", ofGetWidth()/1.25, ofGetHeight()/1.53);
    //
    myFont.load("Ardour3d.ttf", ofGetWidth()/20);
    //
    myFont.drawString("-", ofGetWidth()/1.269, ofGetHeight()/1.17);
    myFont.drawString("+", ofGetWidth()/1.157, ofGetHeight()/1.17);
    
    //Harmonics Information
    myFont.load("Ardour3d.ttf", ofGetWidth()/50);
    
    myFont.drawString("Number of\nHarmonics: ", ofGetWidth()/3.7, ofGetHeight()/1.42);
    auto square = std::to_string(squareHarmonics);
    myFont.drawString(square, ofGetWidth()/3.17, ofGetHeight()/1.27);
    
    myFont.drawString("Number of\nHarmonics: ", ofGetWidth()/1.92, ofGetHeight()/1.42);
    auto saw = std::to_string(sawHarmonics);
    myFont.drawString(saw, ofGetWidth()/1.77, ofGetHeight()/1.27);
    
    myFont.drawString("Number of\nHarmonics: ", ofGetWidth()/1.27, ofGetHeight()/1.42);
    auto triangle = std::to_string(triangleHarmonics);
    myFont.drawString(triangle, ofGetWidth()/1.20, ofGetHeight()/1.27);
    
    //Draw Title
    myFont.load("Ardour3d.ttf", ofGetWidth()/15);
    myFont.drawString("Wavy Waveforms", ofGetWidth()/2.8, ofGetHeight()/8);
    
}

//------------------------------
void interface::drawInformativeText(bool squareInfo, bool sawInfo, bool triangleInfo, bool sampleRateInfo){
    
    myFont.load("raleway.ttf", ofGetWidth()/130);
    
    //Frequency Panel Text
    myFont.drawString(" If the frequency is\n altered, add or\n subtract  a harmonic\nto update the waveform.\n300 Hz is the default\nfrequency for clear\nvisualization.",ofGetWidth()/1.179, ofGetHeight()/5.1);
    //Amplitude Panel Text
    myFont.drawString(" Each harmonic has a\nunique amplitude \nthat contributes\nto the construction\nof each waveform.",ofGetWidth()/1.179, ofGetHeight()/2.6);
    //Sample Rate Panel Text
    myFont.drawString("  Change the sampling rate\n in order to input frequen-\ncies  above the human\nhearing range. This will\nresult in aliased frequencies.", ofGetWidth()/21, ofGetHeight()/1.35);
    
    //Default Info Panel Text
    myFont.setLineHeight(20);
    if(!squareInfo && !sawInfo && !triangleInfo && !sampleRateInfo){
         myFont.drawString("  Hello there guys and gals,\n this is a wavy little informative\nprogram  on waveforms  and\nhow humans perceive them.\n \nClick on the plus buttons to\nstart building the waveforms\nusing sine waves and I'll give\nyou some information about\nthem. Stay wavy.", ofGetWidth()/22, ofGetHeight()/8);
    }
    
    //Square Wave Info Panel Text
    if(squareInfo){
        myFont.drawString("  If  you  keep adding square\nwave harmonics you'll start\nseeing a square wave,\na type of pulse wave. Its cycle\nis equally divided into two\nconstantly alternating\namplitudes.\n \nThe frequency and amplitude\nof the harmonics are\ncalculated using a summation\nwhere the fundamental\nfrequency is multiplied by\n2k-1 and the amplitude by\n1/(2k-1), k being the number\nthat corresponds to each\nparticular harmonic.", ofGetWidth()/22, ofGetHeight()/8);
    }
    //Saw Wave Info Panel Text
    if(sawInfo){
        myFont.drawString("  If  you  keep adding saw\nwave harmonics you'll start\nseeing a sawtooth wave, the\nmost extreme asymmetrical\ntriangle wave. The sawtooth is\nthe richest in terms of\nharmonics.\n \nThe frequency and amplitude\nof the harmonics are\ncalculated using a summation\nwhere the fundamental\nfrequency is multiplied by\nk and the amplitude by\n1/(k x PI), k being the number\nthat corresponds to each\nparticular harmonic.", ofGetWidth()/22, ofGetHeight()/8);
    }
    //Triangle Wave Info Panel Text
    if(triangleInfo){
        myFont.drawString("  If  you  keep adding triangle\nwave harmonics you'll start\nseeing a triangle wave. The\ntriangle wave is comparable\nto the square wave in that it\ncontains a fundamental sound\nplus odd harmonics.\n \nThe frequency and amplitude\nof the harmonics are\ncalculated using a summation\nwhere the fundamental\nfrequency is multiplied by\n2k-1. The amplitude is\ncalculated by finding (-1)^k\nand dividing it by (2k-1)^2,\nk being the number that\ncorresponds to each\nparticular harmonic.", ofGetWidth()/22, ofGetHeight()/8);
    }
    //Sample Rate Info Panel Text
    if(sampleRateInfo){
        myFont.drawString("  The sampling rate is set to\n44,100 Hz by default. This is\nthe standard that was set\nbased on the human hearing\nrange, which goes from\n20 Hz to 20,000 Hz. Despite\nthis, the frequencies on the\nhigher and lower ends of the\nspectrum are really hard to\nperceive. \n \n  You'll notice that if you set\nthe sampling rate to 88,200 Hz,\n you can still hear audio.\nThis is because past a certain\nfrequency, the computer\nproduces  aliases of lower\nfrequencies. Aliasing happens\nwhen a system is measured\nat  an insufficient  sampling\nrate.", ofGetWidth()/22, ofGetHeight()/8);
    }
}

//------------------------------
void interface::drawGUI(){
    
    gui.draw();
    
}

//------------------------------
void interface::updateGUI(){
    
    if(gui.mouseDragged(checkMouse)){
        guiCheck = true;
    }
    
}

//------------------------------
void interface::clearGUI(){
    
    gui.clear();
    
}
