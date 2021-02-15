#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(155, 155, 255);
    waveForms.setupSquare();
    waveForms.setupSaw();
    waveForms.setupTri();
    
    square = false;
    saw = false;
    triangle = false;
    
    squareInfo = false;
    sawInfo = false;
    triangleInfo = false;
    sampleRateInfo = false;
    
    canvas.setupGUI(waveForms.fundamentalFrequency.set("", 300, 0., 20000.));
    
    waveForms.setupAudio();
    ofSoundStreamSetup(2,0,this, waveForms.sampleRate, waveForms.bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */

}

//--------------------------------------------------------------
void ofApp::update(){
    
    canvas.updateGUI();
    
    if(canvas.guiCheck){
        //
        if(square){
            waveForms.setupSquare();
        }
        //
        if(saw){
            waveForms.setupSaw();
        }
        //
        if(triangle){
            waveForms.setupTri();
        }
        
        canvas.guiCheck = false;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Canvas
    canvas.drawCanvas();
    //Waveform Background
    canvas.drawWaveBackground();
    //UI
    canvas.drawUI(waveForms.numSquareHarmonics, waveForms.numSawHarmonics, waveForms.numTriHarmonics);
    //Informative Text
    canvas.drawInformativeText(squareInfo, sawInfo, triangleInfo, sampleRateInfo);
    //Waveform Info
    canvas.drawGUI();
    //Waveforms
    waveForms.drawWave();

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    waveForms.audioOut(output, bufferSize, nChannels);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //Square Takeaway
    if(x > ofGetWidth()/4 && x < ((ofGetWidth()/4) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4) && waveForms.numSquareHarmonics > 0){
        
        waveForms.numSquareHarmonics -= 1;
        waveForms.setupSquare();
        
        square = true;
        saw = false;
        triangle = false;
        
        squareInfo = true;
        sawInfo = false;
        triangleInfo = false;
        sampleRateInfo = false;
        std::cout<<"BABY!!!"<<std::endl;
    }
    
    //Square Give
    if(x > ofGetWidth()/3.03 && x < ((ofGetWidth()/3.03) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4)){
        
        waveForms.numSquareHarmonics += 1;
        waveForms.setupSquare();
        
        square = true;
        saw = false;
        triangle = false;
        
        squareInfo = true;
        sawInfo = false;
        triangleInfo = false;
        sampleRateInfo = false;
        std::cout<<"BOBBY!!!"<<std::endl;
        
    }
    
    //Saw Takeaway
    if(x > ofGetWidth()/2 && x < (ofGetWidth()/2) + ((ofGetWidth()/7)/2.3) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4) && waveForms.numSawHarmonics > 0){
        
        waveForms.numSawHarmonics -= 1;
        waveForms.setupSaw();
        
        square = false;
        saw = true;
        triangle = false;
        
        squareInfo = false;
        sawInfo = true;
        triangleInfo = false;
        sampleRateInfo = false;
        std::cout<<"BABY!!!"<<std::endl;
    }
    
    //Saw Give
    if(x > ofGetWidth()/1.72 && x < ((ofGetWidth()/1.72) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4)){
        
        waveForms.numSawHarmonics += 1;
        waveForms.setupSaw();
        
        square = false;
        saw = true;
        triangle = false;
        
        squareInfo = false;
        sawInfo = true;
        triangleInfo = false;
        sampleRateInfo = false;
        std::cout<<"BOBBY!!!"<<std::endl;
        
    }
    
    //Triangle Takeaway
    if(x > ofGetWidth()/1.3 && x < (ofGetWidth()/1.3) + ((ofGetWidth()/7)/2.3) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4) && waveForms.numTriHarmonics > 0){
        
        waveForms.numTriHarmonics -= 1;
        waveForms.setupTri();
        
        square = false;
        saw = false;
        triangle = true;
        
        squareInfo = false;
        sawInfo = false;
        triangleInfo = true;
        sampleRateInfo = false;
        std::cout<<"BABY!!!"<<std::endl;
    }
    
    //Triangle Give
    if(x > ofGetWidth()/1.177 && x < ((ofGetWidth()/1.177) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.22 && y < ((ofGetHeight()/1.22)+(ofGetHeight()/7)/4)){
        
        waveForms.numTriHarmonics += 1;
        waveForms.setupTri();
        
        square = false;
        saw = false;
        triangle = true;
        
        squareInfo = false;
        sawInfo = false;
        triangleInfo = true;
        sampleRateInfo = false;
        std::cout<<"BOBBY!!!"<<std::endl;
        
    }
    
    //Sample Rate Change 44100
    if(x > ofGetWidth()/25 && x < ((ofGetWidth()/25) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.15 && y < ((ofGetHeight()/1.15)+(ofGetHeight()/7)/4)){
        
        squareInfo = false;
        sawInfo = false;
        triangleInfo = false;
        sampleRateInfo = true;
        
        waveForms.updateSampleRate(44100);
        canvas.clearGUI();
        canvas.setupGUI(waveForms.fundamentalFrequency.set("", 300, 0., 20000.));
        
    }
    
    //Sample Rate Change 88200
    if(x > ofGetWidth()/8.3 && x < ((ofGetWidth()/8.3) + ((ofGetWidth()/7)/2.3)) && y > ofGetHeight()/1.15 && y < ((ofGetHeight()/1.15)+(ofGetHeight()/7)/4)){
        
        squareInfo = false;
        sawInfo = false;
        triangleInfo = false;
        sampleRateInfo = true;
        
        waveForms.updateSampleRate(88200);
        canvas.clearGUI();
        canvas.setupGUI(waveForms.fundamentalFrequency.set("", 300, 0., 40000.));
        
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
