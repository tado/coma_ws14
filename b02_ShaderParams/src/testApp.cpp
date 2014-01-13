#include "testApp.h"

//波の数
static const int NUM = 20;
//Shaderへ渡す周波数の配列
float freq[NUM];

//--------------------------------------------------------------
void testApp::setup(){
    //Shaderの画面サイズ設定
    width = 400;
    height = 300;
    fbo.allocate(width, height);
    
    //Shaderファイルの読込み
    shader.load("shader");
    
    //ランダムに周波数の配列を生成
    for (int i = 0; i < NUM; i++) {
        freq[i] = ofRandom(4.0, 10.0);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //Shaderパラメータ設定
    float resolution[] = {width, height};
    float mousePoint[] = {mouse.x, mouse.y};
    float time = ofGetElapsedTimef();
    
    //FBO開始
    fbo.begin();
    shader.begin();
    //Shaderに渡す値(時間、解像度、マウスの位置)
    shader.setUniform1f("time", time);
    shader.setUniform2fv("resolution", resolution);
    shader.setUniform2fv("mouse", mousePoint);
    
    //freqの配列をShaderに渡す
    shader.setUniform1fv("freq", freq, NUM);

    //画面全体に描画する
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    fbo.end();
    
    fbo.draw(0, ofGetHeight(), ofGetWidth(), -ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'r': // Reload shader
            shader.load("shader");
            break;
        case 'f':
            ofToggleFullscreen();
            break;
        case 'o': // Open shader file on external editor.
            string command = "open ../../../data/shader.frag";
            system(command.c_str());
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}