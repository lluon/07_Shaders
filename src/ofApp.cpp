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
		uniform mat4 modelViewProjectionMatrix; // from OF programmable renderer
		uniform float appTime;

		in vec4 position;	// position (vertex attribute from mesh)
		in vec3 normal;		// normal (vertex attribute from mesh)
		in vec2 texcoord;	// texture coordinate (vertex attribute from mesh)
		out vec2 vtexcoord;	// passed to fragment shader

		void main(){
			vtexcoord = texcoord;
			vec4 pos = position;
			pos.z += 0.1*sin(355./113. * 4. * pos.x + appTime);
			gl_Position = modelViewProjectionMatrix * pos;
		}
	)", R"(
		// Fragment program
		in vec2 vtexcoord;		// interpolant from vertex shader
		out vec4 fragColor;		// output pixel color (RGBA)

		void main(){
			vec3 col = vec3(vtexcoord, 0.);
			fragColor = vec4(col, 1.);
		}
	)");

	mesh = ofMesh::plane(2.,2., 64,64);
}

//--------------------------------------------------------------
void ofApp::update(){
	//printf("frame:%u dt:%f, fps:%f (%g)\n", (unsigned)ofGetFrameNum(), ofGetLastFrameTime(), ofGetFrameRate(), ofGetTargetFrameRate());
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	shader.begin();
	shader.setUniform1f("appTime", ofGetFrameNum()/ofGetTargetFrameRate());
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
