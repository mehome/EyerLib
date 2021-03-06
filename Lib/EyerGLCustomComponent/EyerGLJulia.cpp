#include "EyerGLCustomComponent.hpp"
#include "EyerGLShader/Shader.hpp"

namespace Eyer
{
    EyerGLJulia::EyerGLJulia()
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

        textureDraw = new EyerGLDraw(EYER_GL_SHADER::JULIA_VERTEX_SHADER, EYER_GL_SHADER::JULIA_FRAGMENT_SHADER);
        textureDraw->Init();

        vao = new EyerGLVAO();

        vao->AddVBO(vertex, sizeof(vertex), 0);
        vao->AddVBO(coor, sizeof(coor), 1);
        vao->SetEBO(vertexIndex, sizeof(vertexIndex));

        textureDraw->SetVAO(vao);

        startTime = 0;
        // startTime = Eyer::EyerTime::GetTime() * 1.0f;
    }

    EyerGLJulia::~EyerGLJulia()
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

    int EyerGLJulia::SetWH(int _w, int _h)
    {
        w = _w;
        h = _h;
        return 0;
    }

    int EyerGLJulia::Draw()
    {
        startTime += 0.1f;
        textureDraw->PutUniform1f("width", w);
        textureDraw->PutUniform1f("height", h);
        textureDraw->PutUniform1f("iTime", startTime * 1.0f);
        textureDraw->Draw();
        return 0;
    }
}