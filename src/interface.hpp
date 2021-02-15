//
//  interface.hpp
//  PMCMiniProject
//
//  Created by Mario A. Sánchez on 25/12/2018.
//

#ifndef interface_hpp
#define interface_hpp

#include <stdio.h>
#include "ofMain.h"
#include "audio.hpp"
#include "ofxGui.h"

class interface{
    public:
        interface();
        void drawCanvas();
        void drawWaveBackground();
        void drawUI(int squareHarmonics, int sawHarmonics, int triangleHarmonics);
        void setupGUI(ofParameter<float> fundamental);
        void drawGUI();
        void updateGUI();
        void clearGUI();
        void drawInformativeText(bool squareInfo, bool sawInfo, bool triangleInfo, bool sampleRateInfo);
    
    audio sliders;
    bool guiCheck;
    
    private:
        ofTrueTypeFont myFont;
        ofxPanel gui;
        ofMouseEventArgs checkMouse;
    
    
    
};

#endif /* interface_hpp */
