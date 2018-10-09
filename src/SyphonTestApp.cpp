#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"\

#include "Server.h"
#include "cinder/gl/Fbo.h"


using namespace ci;
using namespace ci::app;
using namespace std;

#define SYWIDTH 800
#define SYHEIGHT 600

class SyphonTestApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;

	reza::syphon::Server syphonServer;
	gl::TextureRef m_texSyRef;
	gl::Fbo m_fboSy;
	
};

void SyphonTestApp::setup()
{
	syphonServer.setName("parts");

	m_texSyRef = gl::Texture::create(SYWIDTH, SYHEIGHT);

	gl::Fbo::Format format2;
	format2.enableDepthBuffer(false);
	//format2.enableColorBuffer(true, 1);
	//format2.setMinFilter(GL_LINEAR);
	//format2.setMagFilter(GL_LINEAR);
	//format2.setWrap(GL_CLAMP, GL_CLAMP);
	//format2.setColorInternalFormat(GL_RGBA16F_ARB);

	//m_fboSy = gl::Fbo(SYWIDTH, SYHEIGHT, format2);
}

void SyphonTestApp::mouseDown( MouseEvent event )
{
}

void SyphonTestApp::update()
{
}

void SyphonTestApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 

	m_fboSy.bindFramebuffer();
	gl::setMatricesWindow(m_fboSy.getSize());
	gl::setViewport(m_fboSy.getBounds());

	*m_texSyRef = m_fboSy.getTexture();
	syphonServer.publishTexture(m_texSyRef);
}

CINDER_APP( SyphonTestApp, RendererGl )
