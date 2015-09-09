//
//  ofxBase64.h
//
//  Created by ISHII 2bit on 2015/09/10.
//
//

#ifndef ofxBase64_h
#define ofxBase64_h

#include "Poco/Base64Decoder.h"
#include "Poco/Base64Encoder.h"
#include "ofMain.h"

void ofxBase64Decode(const string &base64String, ofBuffer &output) {
    stringstream ss(base64String);
    Poco::Base64Decoder base64decoder(ss);
    base64decoder >> output;
}

void ofxBase64Encode(string &base64String, const ofBuffer &input) {
    std::ostringstream str;
    Poco::Base64Encoder encoder(str);
    encoder.write(input.getBinaryBuffer(), input.size());
    encoder.close();
    base64String = str.str();
}

#endif
