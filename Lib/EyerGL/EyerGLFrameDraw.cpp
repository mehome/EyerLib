#include "EyerGL.hpp"
#include "Shader.hpp"

namespace Eyer
{
    EyerGLFrameDraw::EyerGLFrameDraw()
    {
        float vertex[] = {
                1.0, 1.0, 0.0,
                1.0, -1.0, 0.0,
                -1.0, -1.0, 0.0,
                -1.0, 1.0, 0.0
        };
        float coor[] = {
                1.0, 1.0, 0.0,
                1.0, 0.0, 0.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0
        };
        unsigned int vertexIndex[] = {
                0, 1, 2,
                0, 2, 3
        };

        textureDraw = new EyerGLDraw(GL_SHADER::FRAME_VERTEX_SHADER, GL_SHADER::FRAME_FRAGMENT_SHADER);
        textureDraw->Init();

        vao = new EyerGLVAO();

        vao->AddVBO(vertex, sizeof(vertex), 0);
        vao->AddVBO(coor, sizeof(coor), 1);
        vao->SetEBO(vertexIndex, sizeof(vertexIndex));

        textureDraw->SetVAO(vao);
    }

    EyerGLFrameDraw::~EyerGLFrameDraw()
    {
        if(textureDraw != nullptr){
            delete textureDraw;
            textureDraw = nullptr;
        }
        if(vao != nullptr){
            delete vao;
            vao = nullptr;
        }
    }

    int EyerGLFrameDraw::SetYTexture(EyerGLTexture * _yTex)
    {
        yTex = _yTex;
        return 0;
    }

    int EyerGLFrameDraw::SetVideoWH(int w, int h)
    {
        videoW = w;
        videoH = h;
        return 0;
    }

    int EyerGLFrameDraw::Draw()
    {
        if(yTex != nullptr){
            textureDraw->PutTexture("y",yTex, 0);
        }
        textureDraw->Draw();
        return 0;
    }
}