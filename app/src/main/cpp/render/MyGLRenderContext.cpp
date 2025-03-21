/**
 *
 * Created by 公众号：字节流动 on 2020/4/18.
 * https://github.com/githubhaohao/NDK_OpenGLES_3_0
 * 最新文章首发于公众号：字节流动，有疑问或者技术交流可以添加微信 Byte-Flow ,领取视频教程, 拉你进技术交流群
 *
 * */

#include <TriangleSample.h>
#include <TextureMapSample.h>
#include <NV21TextureMapSample.h>
#include <VaoSample.h>
#include <FBOSample.h>
#include <FBOLegLengthenSample.h>
#include <CoordSystemSample.h>
#include <BasicLightingSample.h>
#include <TransformFeedbackSample.h>
#include <MultiLightsSample.h>
#include <DepthTestingSample.h>
#include <InstancingSample.h>
#include <Instancing3DSample.h>
#include <StencilTestingSample.h>
#include <BlendingSample.h>
#include <ParticlesSample.h>
#include <Noise3DSample.h>
#include <SkyBoxSample.h>
#include <Model3DSample.h>
#include <PBOSample.h>
#include <BeatingHeartSample.h>
#include <CloudSample.h>
#include <TimeTunnelSample.h>
#include <BezierCurveSample.h>
#include <BigEyesSample.h>
#include <FaceSlenderSample.h>
#include <BigHeadSample.h>
#include <RotaryHeadSample.h>
#include <VisualizeAudioSample.h>
#include <ScratchCardSample.h>
#include <AvatarSample.h>
#include <ShockWaveSample.h>
#include <MRTSample.h>
#include <FBOBlitSample.h>
#include <TextureBufferSample.h>
#include <UniformBufferSample.h>
#include <RGB2YUYVSample.h>
#include <SharedEGLContextSample.h>
#include <TextRenderSample.h>
#include <PortraitStayColorExample.h>
#include <GLTransitionExample.h>
#include <GLTransitionExample_2.h>
#include <GLTransitionExample_3.h>
#include <GLTransitionExample_4.h>
#include <ConveyorBeltExample.h>
#include <RGB2NV21Sample.h>
#include <RGB2I420Sample.h>
#include <RGB2I444Sample.h>
#include <CopyTextureExample.h>
#include <BlitFrameBufferExample.h>
#include <BinaryProgramExample.h>
#include <Render16BitGraySample.h>
#include "MyGLRenderContext.h"
#include "LogUtil.h"
#include "RenderP010Sample.h"
#include "RenderNV21Sample.h"
#include "RenderI420Sample.h"
#include "RenderI444Sample.h"
#include "RenderYUYVSample.h"
#include "ComputeShaderSample.h"
//#include "ComputeShader2Sample.h"
#include "PortraitModeSample.h"
#include "MultiSampleAntiAliasingSample.h"
#include "FullScreenTriangleSample.h"
//#include "HardwareBufferExample.h"

#include "log.h"

MyGLRenderContext* MyGLRenderContext::m_pContext = nullptr;

MyGLRenderContext::MyGLRenderContext()
{
	m_pCurSample = new BeatingHeartSample();
	m_pBeforeSample = nullptr;
}

MyGLRenderContext::~MyGLRenderContext()
{
	if (m_pCurSample)
	{
		delete m_pCurSample;
		m_pCurSample = nullptr;
	}

	if (m_pBeforeSample)
	{
		delete m_pBeforeSample;
		m_pBeforeSample = nullptr;
	}

}


void MyGLRenderContext::SetParamsInt(int paramType, int value0, int value1)
{
	LOGD("MyGLRenderContext::SetParamsInt paramType = %d, value0 = %d, value1 = %d", paramType, value0, value1);

	if (paramType == SAMPLE_TYPE)
	{
		m_pBeforeSample = m_pCurSample;

		LOGD("MyGLRenderContext::SetParamsInt 0 m_pBeforeSample = %p", m_pBeforeSample);

		switch (value0)
		{
			case SAMPLE_TYPE_KEY_TRIANGLE:
				m_pCurSample = new TriangleSample();
				break;
			case SAMPLE_TYPE_KEY_TEXTURE_MAP:
				m_pCurSample = new TextureMapSample();
				break;
			case SAMPLE_TYPE_KEY_YUV_TEXTURE_MAP:
				m_pCurSample = new NV21TextureMapSample();
				break;
			case SAMPLE_TYPE_KEY_VAO:
				m_pCurSample = new VaoSample();
				break;
			case SAMPLE_TYPE_KEY_FBO:
				m_pCurSample = new FBOSample();
				break;
			case SAMPLE_TYPE_KEY_FBO_LEG_LENGTHEN:
				m_pCurSample = new FBOLegLengthenSample();
				break;
			case SAMPLE_TYPE_KEY_COORD_SYSTEM:
				m_pCurSample = new CoordSystemSample();
				break;
			case SAMPLE_TYPE_KEY_BASIC_LIGHTING:
				m_pCurSample = new BasicLightingSample();
				break;
			case SAMPLE_TYPE_KEY_TRANSFORM_FEEDBACK:
				m_pCurSample = new TransformFeedbackSample();
				break;
			case SAMPLE_TYPE_KEY_MULTI_LIGHTS:
				m_pCurSample = new MultiLightsSample();
				break;
			case SAMPLE_TYPE_KEY_DEPTH_TESTING:
				m_pCurSample = new DepthTestingSample();
				break;
			case SAMPLE_TYPE_KEY_INSTANCING:
				m_pCurSample = new Instancing3DSample();
				break;
			case SAMPLE_TYPE_KEY_STENCIL_TESTING:
				m_pCurSample = new StencilTestingSample();
				break;
			case SAMPLE_TYPE_KEY_BLENDING:
				m_pCurSample = new BlendingSample();
				break;
			case SAMPLE_TYPE_KEY_PARTICLES:
				m_pCurSample = new ParticlesSample();
				break;
			case SAMPLE_TYPE_KEY_SKYBOX:
				m_pCurSample = new SkyBoxSample();
				break;
			case SAMPLE_TYPE_KEY_3D_MODEL:
				m_pCurSample = new Model3DSample();
				break;
			case SAMPLE_TYPE_KEY_PBO:
				m_pCurSample = new PBOSample();
				break;
            case SAMPLE_TYPE_KEY_BEATING_HEART:
                m_pCurSample = new BeatingHeartSample();
                break;
            case SAMPLE_TYPE_KEY_CLOUD:
                m_pCurSample = new CloudSample();
                break;
			case SAMPLE_TYPE_KEY_TIME_TUNNEL:
				m_pCurSample = new TimeTunnelSample();
				break;
			case SAMPLE_TYPE_KEY_BEZIER_CURVE:
				m_pCurSample = new BezierCurveSample();
				break;
            case SAMPLE_TYPE_KEY_BIG_EYES:
                m_pCurSample = new BigEyesSample();
                break;
			case SAMPLE_TYPE_KEY_FACE_SLENDER:
				m_pCurSample = new FaceSlenderSample();
				break;
			case SAMPLE_TYPE_KEY_BIG_HEAD:
				m_pCurSample = new BigHeadSample();
				break;
			case SAMPLE_TYPE_KEY_RATARY_HEAD:
				m_pCurSample = new RotaryHeadSample();
				break;
			case SAMPLE_TYPE_KEY_VISUALIZE_AUDIO:
				m_pCurSample = new VisualizeAudioSample();
				break;
			case SAMPLE_TYPE_KEY_SCRATCH_CARD:
				m_pCurSample = new ScratchCardSample();
				break;
            case SAMPLE_TYPE_KEY_AVATAR:
                m_pCurSample = new AvatarSample();
                break;
			case SAMPLE_TYPE_KEY_SHOCK_WAVE:
				m_pCurSample = new ShockWaveSample();
				break;
			case SAMPLE_TYPE_KEY_MRT:
				m_pCurSample = new MRTSample();
				break;
			case SAMPLE_TYPE_KEY_FBO_BLIT:
				m_pCurSample = new FBOBlitSample();
				break;
            case SAMPLE_TYPE_KEY_TBO:
                m_pCurSample = new TextureBufferSample();
                break;
			case SAMPLE_TYPE_KEY_UBO:
				m_pCurSample = new UniformBufferSample();
				break;
			case SAMPLE_TYPE_KEY_RGB2YUYV:
				m_pCurSample = new RGB2YUYVSample();
				break;
			case SAMPLE_TYPE_KEY_MULTI_THREAD_RENDER:
				m_pCurSample = new SharedEGLContextSample();
				break;
			case SAMPLE_TYPE_KEY_TEXT_RENDER:
				m_pCurSample = new TextRenderSample();
				break;
			case SAMPLE_TYPE_KEY_STAY_COLOR:
				m_pCurSample = new PortraitStayColorExample();
				break;
			case SAMPLE_TYPE_KEY_TRANSITIONS_1:
				m_pCurSample = new GLTransitionExample();
				break;
			case SAMPLE_TYPE_KEY_TRANSITIONS_2:
				m_pCurSample = new GLTransitionExample_2();
				break;
			case SAMPLE_TYPE_KEY_TRANSITIONS_3:
				m_pCurSample = new GLTransitionExample_3();
				break;
			case SAMPLE_TYPE_KEY_TRANSITIONS_4:
				m_pCurSample = new GLTransitionExample_4();
				break;
			case SAMPLE_TYPE_KEY_RGB2NV21:
				m_pCurSample = new RGB2NV21Sample();
				break;
            case SAMPLE_TYPE_KEY_RGB2I420:
                m_pCurSample = new RGB2I420Sample();
                break;
			case SAMPLE_TYPE_KEY_RGB2I444:
				m_pCurSample = new RGB2I444Sample();
				break;
			case SAMPLE_TYPE_KEY_COPY_TEXTURE:
				m_pCurSample = new CopyTextureExample();
				break;
            case SAMPLE_TYPE_KEY_BLIT_FRAME_BUFFER:
                m_pCurSample = new BlitFrameBufferExample();
                break;
			case SAMPLE_TYPE_KEY_BINARY_PROGRAM:
				m_pCurSample = new BinaryProgramExample();
				break;
//			case SAMPLE_TYPE_KEY_HWBuffer:
//				m_pCurSample = new HardwareBufferExample();
//				break;
			case SAMPLE_TYPE_KEY_RENDER_16BIT_GRAY:
				m_pCurSample = new Render16BitGraySample();
				break;
            case SAMPLE_TYPE_KEY_RENDER_P010:
                m_pCurSample = new RenderP010Sample();
                break;
			case SAMPLE_TYPE_KEY_RENDER_NV21:
				m_pCurSample = new RenderNV21Sample();
				break;
			case SAMPLE_TYPE_KEY_RENDER_I420:
				m_pCurSample = new RenderI420Sample();
				break;
			case SAMPLE_TYPE_KEY_RENDER_I444:
				m_pCurSample = new RenderI444Sample();
				break;
			case SAMPLE_TYPE_KEY_RENDER_YUYV:
				m_pCurSample = new RenderYUYVSample();
				break;
			case SAMPLE_TYPE_KEY_COMPUTE_SHADER:
				m_pCurSample = new ComputeShaderSample();
				break;
            case SAMPLE_TYPE_KEY_PORTRAIT_MODE:
                m_pCurSample = new PortraitModeSample();
                break;
			case SAMPLE_TYPE_KEY_MSAA:
				m_pCurSample = new MultiSampleAntiAliasingSample();
				break;
			case SAMPLE_TYPE_KEY_FULLSCREEN_TRIANGLE:
				m_pCurSample = new FullScreenTriangleSample();
				break;
			default:
			    m_pCurSample = nullptr;
				break;
		}

		LOGD("MyGLRenderContext::SetParamsInt m_pBeforeSample = %p, m_pCurSample=%p", m_pBeforeSample, m_pCurSample);
	}
}

void MyGLRenderContext::SetParamsFloat(int paramType, float value0, float value1) {
	LOGD("MyGLRenderContext::SetParamsFloat paramType=%d, value0=%f, value1=%f", paramType, value0, value1);
	if(m_pCurSample)
	{
		switch (paramType)
		{
			case SAMPLE_TYPE_KEY_SET_TOUCH_LOC:
				m_pCurSample->SetTouchLocation(value0, value1);
				break;
			case SAMPLE_TYPE_SET_GRAVITY_XY:
                m_pCurSample->SetGravityXY(value0, value1);
				break;
			default:
				break;

		}
	}

}

void MyGLRenderContext::SetParamsShortArr(short *const pShortArr, int arrSize) {
	LOGD("MyGLRenderContext::SetParamsShortArr pShortArr=%p, arrSize=%d, pShortArr[0]=%d", pShortArr, arrSize, pShortArr[0]);
	if(m_pCurSample)
	{
		m_pCurSample->LoadShortArrData(pShortArr, arrSize);
	}

}

void MyGLRenderContext::UpdateTransformMatrix(float rotateX, float rotateY, float scaleX, float scaleY)
{
	LOGD("MyGLRenderContext::UpdateTransformMatrix [rotateX, rotateY, scaleX, scaleY] = [%f, %f, %f, %f]", rotateX, rotateY, scaleX, scaleY);
	if (m_pCurSample)
	{
		m_pCurSample->UpdateTransformMatrix(rotateX, rotateY, scaleX, scaleY);
	}
}

void MyGLRenderContext::SetImageDataWithIndex(int index, int format, int width, int height, uint8_t *pData)
{
	LOGD("MyGLRenderContext::SetImageDataWithIndex index=%d, format=%d, width=%d, height=%d, pData=%p", index, format, width, height, pData);
	NativeImage nativeImage;
	nativeImage.format = format;
	nativeImage.width = width;
	nativeImage.height = height;
	nativeImage.ppPlane[0] = pData;

	switch (format)
	{
		case IMAGE_FORMAT_NV12:
		case IMAGE_FORMAT_NV21:
			nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
			break;
		case IMAGE_FORMAT_I420:
			nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
			nativeImage.ppPlane[2] = nativeImage.ppPlane[1] + width * height / 4;
			break;
		default:
			break;
	}

	if (m_pCurSample)
	{
		m_pCurSample->LoadMultiImageWithIndex(index, &nativeImage);
	}

}

void MyGLRenderContext::SetImageData(int format, int width, int height, uint8_t *pData)
{
	LOGD("MyGLRenderContext::SetImageData format=%d, width=%d, height=%d, pData=%p", format, width, height, pData);
	NativeImage nativeImage;
	nativeImage.format = format;
	nativeImage.width = width;
	nativeImage.height = height;
	nativeImage.ppPlane[0] = pData;

	switch (format)
	{
		case IMAGE_FORMAT_NV12:
		case IMAGE_FORMAT_NV21:
			nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
			break;
		case IMAGE_FORMAT_I420:
			nativeImage.ppPlane[1] = nativeImage.ppPlane[0] + width * height;
			nativeImage.ppPlane[2] = nativeImage.ppPlane[1] + width * height / 4;
			break;
		default:
			break;
	}

	if (m_pCurSample)
	{
		m_pCurSample->LoadImage(&nativeImage);
	}

}

void MyGLRenderContext::OnSurfaceCreated()
{
	LOGD("MyGLRenderContext::OnSurfaceCreated");
	glClearColor(1.0f,1.0f,1.0f, 1.0f);
}

void MyGLRenderContext::OnSurfaceChanged(int width, int height)
{
	LOGD("MyGLRenderContext::OnSurfaceChanged [w, h] = [%d, %d]", width, height);
	glViewport(0, 0, width, height);
	m_ScreenW = width;
	m_ScreenH = height;
}

void MyGLRenderContext::OnDrawFrame()
{
	LOGD("MyGLRenderContext::OnDrawFrame");
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	if (m_pBeforeSample)
	{
		m_pBeforeSample->Destroy();
		delete m_pBeforeSample;
		m_pBeforeSample = nullptr;
	}

	if (m_pCurSample)
	{
		m_pCurSample->Init();
		m_pCurSample->Draw(m_ScreenW, m_ScreenH);
	}
}

MyGLRenderContext *MyGLRenderContext::GetInstance()
{
	LOGD("MyGLRenderContext::GetInstance");
	if (m_pContext == nullptr)
	{
		m_pContext = new MyGLRenderContext();
	}
	return m_pContext;
}

void MyGLRenderContext::DestroyInstance()
{
	LOGD("MyGLRenderContext::DestroyInstance");
	if (m_pContext)
	{
		delete m_pContext;
		m_pContext = nullptr;
	}

}



