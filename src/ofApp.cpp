#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //icon vector
    std::vector<std::string> files = {
//        "Icons/BCSicon_small.png",
//        "Icons/GTicon_small.png",
//        "Icons/RSicon_small.png",
//        "Icons/BCSicon_80x80.png",
//        "Icons/GTicon_80x80.png",
//        "Icons/RSicon_80x80.png",
        "Icons/BCSiconFramed.png",
        "Icons/GTiconFramed.png",
        "Icons/RSiconFramed.png",
    };
    
    //icon location
    float x = iconPadding;
    float y = iconPadding;
    
    //load each icon via vector
    for (std::size_t i = 0; i < files.size(); ++i){
        //load icons
        ofTexture tex;
        ofLoadImage(tex, files[i]);
        
        //place icons at top right corner
        x = ofGetWidth() - (tex.getWidth() + iconPadding);
       
        // Set the position.
        glm::vec2 position = { x, y };
        iconPositions.push_back(position);
        icons.push_back(tex);
        y += (iconPadding+ tex.getHeight());}
    
    //load frame
    //frameSmall.load("Icons/frameSmall.gif");
    
    //BASE COLOR models vector
    std::vector<std::string> modelsB = {
        "Models/BirdedCurvedSword/BCSbaseColor.obj",
        "Models/GnawtoothBlade/GT.obj",
        "Models/RotScythe/RSbaseColor.obj"};
    
    for (std::size_t i = 0; i < modelsB.size(); ++i){
        ofxAssimpModelLoader modelB;
        modelB.loadModel(modelsB[i]);
        modelB.setScale(2, 2, 2);
        modelsBase.push_back(modelB);}
    
    //ROUGHNESS models vector
    std::vector<std::string> modelsR = {
        "Models/BirdedCurvedSword/BCSroughness.obj",
        "Models/GnawtoothBlade/GTroughness.obj",
        "Models/RotScythe/RSroughness.obj"};
    
    for (std::size_t i = 0; i < modelsR.size(); ++i){
        ofxAssimpModelLoader modelR;
        modelR.loadModel(modelsR[i]);
        modelR.setScale(2, 2, 2);
        modelsRoughness.push_back(modelR);}
    
    //METALNESS models vector
    std::vector<std::string> modelsM = {
        "Models/BirdedCurvedSword/BCSmetalness.obj",
        "Models/GnawtoothBlade/GTmetalness.obj",
        "Models/RotScythe/RSmetalness.obj"};
    
    for (std::size_t i = 0; i < modelsM.size(); ++i){
        ofxAssimpModelLoader modelM;
        modelM.loadModel(modelsM[i]);
        modelM.setScale(2, 2, 2);
        modelsMetalness.push_back(modelM);}
    
    //NORMAL models vector
    std::vector<std::string> modelsN = {
        "Models/BirdedCurvedSword/BCSnormal.obj",
        "Models/GnawtoothBlade/GTnormal.obj",
        "Models/RotScythe/RSnormal.obj"};
    
    for (std::size_t i = 0; i < modelsN.size(); ++i){
        ofxAssimpModelLoader modelN;
        modelN.loadModel(modelsN[i]);
        modelN.setScale(2, 2, 2);
        modelsNormal.push_back(modelN);}
    
    //AMBIENT OCCLUSION models vector
    std::vector<std::string> modelsAO = {
        "Models/BirdedCurvedSword/BCSao.obj",
        "Models/GnawtoothBlade/GTao.obj",
        "Models/RotScythe/RSao.obj"};
    
    for (std::size_t i = 0; i < modelsAO.size(); ++i){
        ofxAssimpModelLoader modelAO;
        modelAO.loadModel(modelsAO[i]);
        modelAO.setScale(2, 2, 2);
        modelsAmbientOcclusion.push_back(modelAO);}
    
    //INVERT models vector
    std::vector<std::string> modelsI = {
        "Models/BirdedCurvedSword/BCSinvert.obj",
        "Models/GnawtoothBlade/GTinvert.obj",
        "Models/RotScythe/RSinvert.obj"};
    
    for (std::size_t i = 0; i < modelsI.size(); ++i){
        ofxAssimpModelLoader modelI;
        modelI.loadModel(modelsI[i]);
        modelI.setScale(2, 2, 2);
        modelsInvert.push_back(modelI);}
    
    //sound effects
    increaseDrawSize.load("SFX/increaseDraw02.wav");
    decreaseDrawSize.load("SFX/decreaseDraw02.wav");
//    increaseDrawSize.setVolume(0.3);
//    decreaseDrawSize.setVolume(0.3);
    increaseDrawSize.setMultiPlay(true);
    decreaseDrawSize.setMultiPlay(true);
    
    drawSizeLowerLimit.load("SFX/drawSize_lowerLimit.wav");
    drawSizeUpperLimit.load("SFX/drawSize_upperLimit.wav");
    drawSizeLowerLimit.setMultiPlay(true);
    drawSizeUpperLimit.setMultiPlay(true);
    
    increaseOpacity.load("SFX/increaseOpacity02.wav");
    decreaseOpacity.load("SFX/decreaseOpacity02.wav");
    increaseOpacity.setMultiPlay(true);
    decreaseOpacity.setMultiPlay(true);
    opacityLowerLimit.load("SFX/opacityLowerLimit.wav");
    opacityUpperLimit.load("SFX/opacityUpperLimit.wav");
    opacityLowerLimit.setMultiPlay(true);
    opacityUpperLimit.setMultiPlay(true);

    resetCamera.load("SFX/resetCamera.wav");
    texturedSFX.load("SFX/texturedView.wav");
    wireframeSFX.load("SFX/wireframeView.wav");
    pointsSFX.load("SFX/pointsView.wav");
    pointsWireframeSFX.load("SFX/pointsWireframeView.wav");
    resetCamera.setMultiPlay(true);
    texturedSFX.setMultiPlay(true);
    wireframeSFX.setMultiPlay(true);
    pointsSFX.setMultiPlay(true);
    pointsWireframeSFX.setMultiPlay(true);
    
    invertSFX.load("SFX/invertSFX_bassHit.wav");
    invertSFX.setLoop(true);
    invertSFX.setVolume(0);
    invertSFX.play();
    
    invertWireframeSFX.load("SFX/invertWireframeSFX_Synth.wav");
    invertWireframeSFX.setLoop(true);
    invertWireframeSFX.setVolume(0);
    invertWireframeSFX.play();
    
    invertPointsSFX.load("SFX/invertPointsSFX_Synth.wav");
    invertPointsSFX.setLoop(true);
    invertPointsSFX.setVolume(0);
    invertPointsSFX.play();
    
    resetSFX.load("SFX/resetSFX.wav");
    resetSFX.setMultiPlay(true);
    
    //icon SFX
    BCSbutton.load("SFX/BCSbutton.wav");
    GTbutton.load("SFX/GTbutton.wav");
    RSbutton.load("SFX/RSbutton.wav");
    BCSbutton.setMultiPlay(true);
    GTbutton.setMultiPlay(true);
    RSbutton.setMultiPlay(true);
    BCSbutton.setVolume(1);
    GTbutton.setVolume(1);
    RSbutton.setVolume(1);
    
    //channel SFX
    roughSFX.load("SFX/roughSFX.wav");
    roughSFX.setLoop(true);
    roughSFX.setVolume(0);
    roughSFX.play();
    
    metalSFX.load("SFX/metalSFX.wav");
    metalSFX.setLoop(true);
    metalSFX.setVolume(0);
    metalSFX.play();
    
    normalSFX.load("SFX/normalSFX.wav");
    normalSFX.setLoop(true);
    normalSFX.setVolume(0);
    normalSFX.play();
    
    aoSFX.load("SFX/aoSFX.wav");
    aoSFX.setLoop(true);
    aoSFX.setVolume(0);
    aoSFX.play();
    
    invertedSFX.load("SFX/invertedSFX.wav");
    invertedSFX.setLoop(true);
    invertedSFX.setVolume(0);
    invertedSFX.play();
    
    //backround audio
    backroundSFX.load("SFX/backroundSFX.wav");
    backroundSFX.setLoop(true);
    backroundSFX.setVolume(0.5f);
    backroundSFX.play();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update icon position based on window width
    for (std::size_t i = 0; i < icons.size(); ++i){
        iconPositions[i].x = ofGetWidth() - (icons[i].getWidth() + iconPadding);}
    
    //update gif
    //if (ofGetElapsedTimeMillis() % 3)
    //{index++; if (index > frameSmall.pages.size()-1) index = 0;}
    
    //update draw mode
    if(meshDisplayCounter == 0){mDisplay = FILL_ON;}
    if(meshDisplayCounter == 1){mDisplay = WIREFRAME_ON;}
    if(meshDisplayCounter == 2){mDisplay = POINTS_ON;}
    if(meshDisplayCounter == 3){mDisplay = WIREFRAME_POINTS_ON;}
    
    //update background and HUD color
    if(backgroundCounter > 1){backgroundCounter = 0;}
    if(backgroundCounter == 0){
        backgroundColor = 0;
        invertedSFX.setVolume(0);       //background SFX OFF
        HUDColor = 255;}
    if(backgroundCounter == 1){
        backgroundColor = 255;
        invertedSFX.setVolume(1);       //background SFX ON
        HUDColor = 0;}

    //channel display
    if(cDisplay == BASE_ON){
        modelsContainer = modelsBase;
        channelDotY = 20;}
    if(cDisplay == ROUGH_ON){
        modelsContainer = modelsRoughness;
        channelDotY = 40;}
    if(cDisplay == METAL_ON){
        modelsContainer = modelsMetalness;
        channelDotY = 60;}
    if(cDisplay == NORMAL_ON){
        modelsContainer = modelsNormal;
        channelDotY = 80;}
    if(cDisplay == AO_ON){
        modelsContainer = modelsAmbientOcclusion;
        channelDotY = 100;}
    if(cDisplay == INVERT_ON){
        modelsContainer = modelsInvert;
        channelDotY = 120;}
    
    //update draw size
    glPointSize(drawSize);
    glLineWidth(drawSize);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(backgroundColor);

    //draw icons highlighted
    for (std::size_t i = 0; i < icons.size(); ++i)
    {
        // We tint the image based on if it is selected.
        if (i == selectedIconIndex)
        {ofSetColor(ofColor::white);
        }
        else
        {ofSetColor(ofColor::white, 80);}
        
        // Draw the icon at the position.
        icons[i].draw(iconPositions[i]);
    }
    
    //draw .gif frame
    //for (std::size_t i = 0; i < icons.size(); ++i)
    //{frameSmall.pages[index].draw(iconPositions[i]);}
    
    //draw models
    ofEnableDepthTest();
    cam.begin();
    ofSetColor(255, 255, 255, (modelOpacity));
    
    if  (mDisplay == FILL_ON){
        modelsContainer[selectedIconIndex].draw(OF_MESH_FILL);
    }
    
    if  (mDisplay == WIREFRAME_ON)
    {
        modelsContainer[selectedIconIndex].draw(OF_MESH_WIREFRAME);
        ofSetColor(0);
        modelsContainer[selectedIconIndex].draw(OF_MESH_FILL);
    }
    if  (mDisplay == POINTS_ON)
    {
        modelsContainer[selectedIconIndex].draw(OF_MESH_POINTS);
        ofSetColor(0);
        modelsContainer[selectedIconIndex].draw(OF_MESH_FILL);
    }
    if  (mDisplay == WIREFRAME_POINTS_ON)
    {
        modelsContainer[selectedIconIndex].draw(OF_MESH_POINTS);
        modelsContainer[selectedIconIndex].draw(OF_MESH_WIREFRAME);
        ofSetColor(0);
        modelsContainer[selectedIconIndex].draw(OF_MESH_FILL);
    }

    ofSetColor(255);
    cam.end();
    ofDisableDepthTest();
    
    ofSetColor(HUDColor);
    //HUD
    if(selectedIconIndex == 0){
    ofDrawBitmapString("BIRDED CURVEDSWORD",                        20, 20);}
    if(selectedIconIndex == 1){
    ofDrawBitmapString("GNAWTOOTH BLADE",                           20, 20);}
    if(selectedIconIndex == 2){
    ofDrawBitmapString("ROT SCYTHE",                                20, 20);}
    ofPushMatrix();
    ofTranslate(0, 30);
    ofDrawBitmapString(" *     *",                                  20, channelDotY);
    ofDrawBitmapString("1 ::::: BASE COLOR",                        20, 20);
    ofDrawBitmapString("2 ::::: ROUGHNESS",                         20, 40);
    ofDrawBitmapString("3 ::::: METALNESS",                         20, 60);
    ofDrawBitmapString("4 ::::: NORMAL",                            20, 80);
    ofDrawBitmapString("5 ::::: AMBIENT OCCLUSION",                 20, 100);
    ofDrawBitmapString("6 ::::: INVERTED",                          20, 120);
    ofDrawBitmapString("TAB ::: DRAW MODE",                         20, 150);
    if  (mDisplay == FILL_ON){
    ofDrawBitmapString("::::::: FILL",                              20, 170);}
    if  (mDisplay == WIREFRAME_ON){
    ofDrawBitmapString("::::::: WIREFRAME",                         20, 170);}
    if  (mDisplay == POINTS_ON){
    ofDrawBitmapString("::::::: POINTS",                            20, 170);}
    if  (mDisplay == WIREFRAME_POINTS_ON){
    ofDrawBitmapString("::::::: WIREFRAME & POINTS",                20, 170);}
    if(tLabel == true){ofDrawBitmapString("   *   *",               20, 150);}
    ofPopMatrix();
    if(rLabel == true){ofDrawBitmapString(" *     *",               20,   ofGetHeight()-100);}
    if(fLabel == true){ofDrawBitmapString(" *     *",               20,   ofGetHeight()-80);}
    if(bLabel == true){ofDrawBitmapString(" *     *",               20,   ofGetHeight()-60);}
    if(oLabel == true){ofDrawBitmapString("   *   *",               20,   ofGetHeight()-40);}
    if(dLabel == true){ofDrawBitmapString("   *   *",               20,   ofGetHeight()-20);}
    ofDrawBitmapString("R ::::: RESET SOUND",                       20,   ofGetHeight()-100);
    ofDrawBitmapString("F ::::: RESET CAMERA",                      20,   ofGetHeight()-80);
    ofDrawBitmapString("B ::::: INVERT BACKGROUND",                 20,   ofGetHeight()-60);
    ofDrawBitmapString("-/+ ::: INCREASE/DECREASE OPACITY: "
                       + ofToString(modelOpacity)+"/255",           20,   ofGetHeight()-40);
    ofDrawBitmapString("[/] ::: INCREASE/DECREASE DRAW SIZE: "
                       + ofToString(drawSize)+"/65",                20,   ofGetHeight()-20);
    ofDrawBitmapString("   L.MOUSE DRAG ::::::: ROTATE",ofGetWidth()-260, ofGetHeight()-60);
    ofDrawBitmapString("   R.MOUSE DRAG ::::::::: ZOOM",ofGetWidth()-260, ofGetHeight()-40);
    ofDrawBitmapString("   OPTION.L.MOUSE DRAG ::: PAN",ofGetWidth()-260, ofGetHeight()-20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //channel display                       //channel sounds
    if(key == '1'){cDisplay = BASE_ON;}
    if(key == '2'){cDisplay = ROUGH_ON;     roughSFX.setVolume  (1);}
    if(key == '3'){cDisplay = METAL_ON;     metalSFX.setVolume  (1);}
    if(key == '4'){cDisplay = NORMAL_ON;    normalSFX.setVolume (1);}
    if(key == '5'){cDisplay = AO_ON;        aoSFX.setVolume     (.5);}
    if(key == '6'){cDisplay = INVERT_ON;    invertSFX.setVolume (1);}
    
    //mesh display
    if(key == OF_KEY_TAB){meshDisplayCounter += 1;
        if(meshDisplayCounter >  3){        meshDisplayCounter = 0;}
        if(meshDisplayCounter == 0){        texturedSFX.play();}
        if(meshDisplayCounter == 1){        wireframeSFX.play();}
        if(meshDisplayCounter == 2){        pointsSFX.play();}
        if(meshDisplayCounter == 3){        pointsWireframeSFX.play();}}
    
    if(key == 'r'){
        resetSFX.play();
        invertSFX.setVolume                 (0);
        invertPointsSFX.setVolume           (0);
        invertWireframeSFX.setVolume        (0);
        invertPointsWireframeSFX.setVolume  (0);
        roughSFX.setVolume                  (0);
        metalSFX.setVolume                  (0);
        normalSFX.setVolume                 (0);
        aoSFX.setVolume                     (0);
        invertedSFX.setVolume               (0);
    }
    if(key == 'b'){backgroundCounter += 1;}
    if(key == 'f'){cam.reset(); resetCamera.play();}
    if(key == '-'){
        modelOpacity = ofClamp((modelOpacity - 10), 0, 255);
        decreaseOpacity.play();
        if(modelOpacity == 0){opacityLowerLimit.play();}}   
    if(key == '='){
        modelOpacity = ofClamp((modelOpacity + 10), 0, 255);
        increaseOpacity.play();
        if(modelOpacity == 255)
{opacityUpperLimit.play();}}
    if(key == '['){
        drawSize = ofClamp((drawSize - 1), 0, 65);
        decreaseDrawSize.play();
        if(drawSize == 0)
        {drawSizeLowerLimit.play();}}
    if(key == ']'){drawSize = ofClamp((drawSize + 1), 0, 65);
        increaseDrawSize.play();
        if(drawSize == 65){drawSizeUpperLimit.play();}}
    
    if(key == OF_KEY_TAB){      tLabel = true;}
    if(key == 'r'){             rLabel = true;}
    if(key == 'f'){             fLabel = true;}
    if(key == 'b'){             bLabel = true;}
    if(key == '-'|key == '='){  oLabel = true;}
    if(key == '['|key == ']'){  dLabel = true;}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_TAB){      tLabel = false;}
    if(key == 'r'){             rLabel = false;}
    if(key == 'f'){             fLabel = false;}
    if(key == 'b'){             bLabel = false;}
    if(key == '-'|key == '='){  oLabel = false;}
    if(key == '['|key == ']'){  dLabel = false;}

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(button == OF_MOUSE_BUTTON_LEFT){
        for(std::size_t i = 0; i < icons.size(); ++i){
            ofTexture tex = icons[i];
            glm::vec2 position = iconPositions[i];
            
            //bounding box of icon selection
            ofRectangle rect(position.x,position.y,tex.getWidth(),tex.getHeight());
            
            //check if mouse is over bounding box
            if(rect.inside(x, y))
                
            //ICON SFX
            {selectedIconIndex = i;
            if(i == 0){BCSbutton.play();}
            if(i == 1){GTbutton.play();}
            if(i == 2){RSbutton.play();}}}}
    
}

//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  &&&&&&&&*** **&&&&8888&&&&&&&&&&&&&&&***** ***********&&&&&&&&& && &&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&& *************&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&& && &&
//  &&&&&&&&*** **&&&&8888&&&&&&&&&&&&&&&*****************&&&&&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&&* ************&&&&& && &&
//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  &&&&&&&&*** **&&&&8888&&&&&&&&&&&&&&&*****************&&&&&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&&*** **********&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  &&&&&&&&*** **&&&&8888&&&&&&&&&&&&&&&*****************&&&&&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&&******* ******&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  &&&&&&&&******&&&&8888&&&&&&&&&&&&&&&************** **&&&&&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&&******* ******&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&888&&&&&&&&&&&&***&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//  &&&&&&&&******&&&&8888&&&&&&&&&&&&&&&************** **&&&&&&&&&&&&&&&
//  &&&&&&&&&&&&&&&&&&8888888888&&&&&&&&&&&&&&&&******* ******&&&&&&&&&&&
//  MAK HEPLER-GONZALEZ
