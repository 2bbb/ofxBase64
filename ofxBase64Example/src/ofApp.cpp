#include "ofMain.h"

#include "ofxBase64.h"

class ofApp : public ofBaseApp{
public:
    void setup() {
        string str;
        ofBuffer input;
        input.append("\07\01\02", 3);
        ofxBase64Encode(str, input);
        
        ofLogNotice() << str;
        
        ofBuffer output;
        ofxBase64Decode(str, output);
        for(int i = 0; i < output.size(); i++) {
            ofLogNotice() << i << " : " << (int)output.getBinaryBuffer()[i];
        }
        ofExit();
    }
};

int main() {
    ofSetupOpenGL(1024, 768, OF_WINDOW);
    ofRunApp(new ofApp);
}
