//
//  audio.hpp
//  PMCMiniProject
//
//  Created by Mario A. Sánchez on 25/12/2018.
//

#ifndef audio_hpp
#define audio_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"

class audio{
    public:
        audio();
        void drawWave();
        void setupSquare();
        void setupTri();
        void setupSaw();
    
        void clearSquare();
        void clearSaw();
        void clearTri();
    
    void setupAudio();
    void updateSampleRate(int samplingRate);
    void audioOut(float * output, int bufferSize, int nChannels);
    
    //Maximilian
    int sampleRate;
    int bufferSize;
    
    int numSquareHarmonics;
    int numSawHarmonics;
    int numTriHarmonics;
    
    ofParameter<float> fundamentalFrequency;
    
    private:
        // For drawing
        float waveform[4096]; //make this bigger, just in case
        int waveIndex;
    
        //Maximilian
        std::vector<maxiOsc> oscillators;
        std::vector<float> frequencies;
        std::vector<float> amplitudes;
    
        int numHarmonics;
    
};

#endif /* audio_hpp */
