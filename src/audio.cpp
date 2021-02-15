//
//  audio.cpp
//  PMCMiniProject
//
//  Created by Mario A. Sánchez on 25/12/2018.
//

#include "audio.hpp"

audio::audio(){
    
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth()/5; ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    numSquareHarmonics = 0;
    numSawHarmonics = 0;
    numTriHarmonics = 0;
    
    fundamentalFrequency = 300.0;
    
    
}
//----------------------------
void audio::setupAudio(){
    // Maximilian audio stuff
    sampleRate = 44100; /* Sampling Rate */
    bufferSize= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
}

//----------------------------
void audio::setupSquare(){
    
    numSawHarmonics = 0;
    numTriHarmonics = 0;
    
    oscillators.clear();
    frequencies.clear();
    amplitudes.clear();
    
    for (int k = 1; k <= numSquareHarmonics; ++k) {
        maxiOsc newOsc;
        oscillators.push_back(newOsc);
        
        //Square Summation
        frequencies.push_back((2.0*k-1.0)*fundamentalFrequency);
        amplitudes.push_back(1.0/(2.0*k-1.0));
        
        std::cout << "k = " << k << ", f = " << frequencies[k-1] << ", a = " << amplitudes[k-1] << std::endl;
    }
    
    numHarmonics = numSquareHarmonics + numSawHarmonics + numTriHarmonics;
}

//----------------------------
void audio::setupSaw(){
    
    numSquareHarmonics = 0;
    numTriHarmonics = 0;
    
    oscillators.clear();
    frequencies.clear();
    amplitudes.clear();
    
    for (int k = 1; k <= numSawHarmonics; ++k) {
        maxiOsc newOsc;
        oscillators.push_back(newOsc);
        
        //Saw Summation
        frequencies.push_back(k*fundamentalFrequency);
        amplitudes.push_back(1.0/(k*PI));
        
        std::cout << "k = " << k << ", f = " << frequencies[k-1] << ", a = " << amplitudes[k-1] << std::endl;
    }
    
    numHarmonics = numSquareHarmonics + numSawHarmonics + numTriHarmonics;
}

//----------------------------
void audio::setupTri(){
    
    numSquareHarmonics = 0;
    numSawHarmonics = 0;
    
    oscillators.clear();
    frequencies.clear();
    amplitudes.clear();
    
    for (int k = 1; k <= numTriHarmonics; ++k) {
        maxiOsc newOsc;
        oscillators.push_back(newOsc);
        
        //Triangle Summation
        frequencies.push_back((2.0*k-1.0)*fundamentalFrequency);
        amplitudes.push_back(pow(-1,k)/pow((2.0*k-1.0),2));
        
        std::cout << "k = " << k << ", f = " << frequencies[k-1] << ", a = " << amplitudes[k-1] << std::endl;
    }
    
    numHarmonics = numSquareHarmonics + numSawHarmonics + numTriHarmonics;
}

//----------------------------
void audio::drawWave(){
    
    ofTranslate(ofGetWidth()/5, ofGetHeight()/2.7);
    ofSetColor(0, 0, 255);
    ofFill();
    int oldX = 0;
    int oldY = 0;
    for(int i = 0; i < ofGetWidth()/1.6; ++i) {
        ofDrawLine(oldX, oldY, i, waveform[i] * ofGetHeight()/2.);
        oldX = i;
        oldY = waveform[i] * ofGetHeight()/2.;
    }
    
}

//----------------------------
void audio::audioOut(float *output, int bufferSize, int nChannels){
    
    //Always loop through the whole buffer
    for (int i = 0; i < bufferSize; ++i){
        
        //fill the output buffer
        for (int k = 0; k < numHarmonics; ++k) {
            output[i * nChannels] += (amplitudes[k] * oscillators[k].sinewave(frequencies[k]))/5;
        }
        
        output[i * nChannels + 1] = output[i * nChannels]; // right channel is the same as the left
        
        //Hold the values so the draw method can draw them
        waveform[waveIndex] =  output[i * nChannels];
        ++waveIndex;
        if (waveIndex > (ofGetWidth() - 1))
            waveIndex = 0;
    }
    
}

//----------------------------
void audio::updateSampleRate(int samplingRate){
    
    sampleRate = samplingRate;
    
}

