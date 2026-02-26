#include "ofApp.h"
#include "ofGraphicsUtil.h"
using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup camera (for 3D rendering)
    cam.setPosition(vec3(0., 0., 2.));
    cam.setNearClip(0.05);
    cam.setFarClip(100.);
    
    // Other setup for 3D rendering
    ofEnableDepthTest();
    ofSetFrameRate(40); // must be set for ofGetTargetFrameRate to work
    
    // Build shader (from GLSL code)
    build(shader, R"(
  // Vertex program
      uniform mat4 projectionMatrix;
      uniform mat4 viewMatrix;
      uniform mat4 modelMatrix;

      in vec4 position;
      in vec3 normal;
      in vec3 color;
      out vec3 vcolor;

      void main(){
 
         vec3 pos = (modelMatrix*position).xyz;//convert from object to world space
         vec3 N = normalize(mat3(modelMatrix)*normal); //assumes only uniform scaling
         gl_Position = projectionMatrix * viewMatrix * vec4(pos,1.);
 
             vcolor = color ;
             vec3 L = vec3 (0., 1., 0.) ;
             float a = 0.2;
             float d = max ( dot (N, L), 0.) ;
             vcolor *= (d+a);
             
 
        }
 
 )", R"(
  // Fragment program
  in vec3 vcolor;
  out vec4 fragColor;
 
  void main(){
    vec3 col = vcolor;
   fragColor = vec4(col, 1.);
  }
 )");
    
    
    mesh = ofMesh::sphere(1.,32);
    for (auto pos : mesh.getVertices())
         mesh.addColor(ofFloatColor(0, 0, 1));
}

//--------------------------------------------------------------
void ofApp::update(){
	//printf("frame:%u dt:%f, fps:%f (%g)\n", (unsigned)ofGetFrameNum(), ofGetLastFrameTime(), ofGetFrameRate(), ofGetTargetFrameRate());
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	shader.begin();
	//shader.setUniform1f("appTime", ofGetFrameNum()/ofGetTargetFrameRate());
	mesh.draw();
	shader.end();
	cam.end();
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
