#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void mousePressed(int x, int y, int button);
        void keyPressed(int key);
        void keyReleased(int key);
    
    //draw modes
    enum meshDisplay{
        FILL_ON,                //0
        WIREFRAME_ON,           //1
        POINTS_ON,              //2
        WIREFRAME_POINTS_ON};   //3
    meshDisplay mDisplay = FILL_ON;
    int meshDisplayCounter = 0;
        
    //icons
    std::vector<ofTexture> icons;
    std::vector<glm::vec2> iconPositions;
    std::size_t selectedIconIndex = 0;
    float iconPadding = 10;
    
    //gif variable
    //ofxGIF::fiGifLoader frameSmall;
    //int index = 0;
    
    //models
    std::vector<ofxAssimpModelLoader> modelsContainer;
    std::vector<ofxAssimpModelLoader> modelsBase;
    std::vector<ofxAssimpModelLoader> modelsRoughness;
    std::vector<ofxAssimpModelLoader> modelsMetalness;
    std::vector<ofxAssimpModelLoader> modelsNormal;
    std::vector<ofxAssimpModelLoader> modelsAmbientOcclusion;
    std::vector<ofxAssimpModelLoader> modelsInvert;
    
    //channel states
    enum channelDisplay{
        BASE_ON,
        ROUGH_ON,
        METAL_ON,
        NORMAL_ON,
        AO_ON,
        INVERT_ON,};
    channelDisplay cDisplay = BASE_ON;
     
    //HUD
    int backgroundCounter = 0;
    int backgroundColor = 0;
    int HUDColor = 255;
    int channelDotY = 20;
    int drawSize = 3;
    int modelOpacity = 255;
    
    bool tLabel = false;
    bool rLabel = false;
    bool fLabel = false;
    bool bLabel = false;
    bool oLabel = false;
    bool dLabel = false;

    //camera
    ofEasyCam cam;
    
    //sound effects
    ofSoundPlayer increaseDrawSize;
    ofSoundPlayer decreaseDrawSize;
    ofSoundPlayer resetCamera;
    ofSoundPlayer texturedSFX;
    ofSoundPlayer wireframeSFX;
    ofSoundPlayer pointsSFX;
    ofSoundPlayer pointsWireframeSFX;
    ofSoundPlayer backroundSFX;
    ofSoundPlayer invertSFX;
    ofSoundPlayer invertWireframeSFX;
    ofSoundPlayer invertPointsSFX;
    ofSoundPlayer invertPointsWireframeSFX;
    ofSoundPlayer drawSizeLowerLimit;
    ofSoundPlayer drawSizeUpperLimit;
    ofSoundPlayer increaseOpacity;
    ofSoundPlayer decreaseOpacity;
    ofSoundPlayer opacityLowerLimit;
    ofSoundPlayer opacityUpperLimit;
    ofSoundPlayer resetSFX;
    
    ofSoundPlayer BCSbutton;
    ofSoundPlayer GTbutton;
    ofSoundPlayer RSbutton;


    //channel SFX
    ofSoundPlayer roughSFX;
    ofSoundPlayer metalSFX;
    ofSoundPlayer normalSFX;
    ofSoundPlayer aoSFX;
    ofSoundPlayer invertedSFX;
    

};
