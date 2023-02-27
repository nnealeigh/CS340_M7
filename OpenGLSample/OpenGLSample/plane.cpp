// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Project
#include "Plane.h"

namespace static_meshes_3D {

    glm::vec3 Plane::vertices[4] =
    {
        glm::vec3(-10.0f, 0.0f, -5.0f), // Left-back point
        glm::vec3(-10.0f, 0.0f, 5.0f), // Left-front point
        glm::vec3(10.0f, 0.0f, -5.0f), // Right-back point
        glm::vec3(10.0f, 0.0f, 5.0f) // Right-front point
    };

    glm::vec2 Plane::textureCoordinates[4] =
    {
        glm::vec2(0.0f, 1.0f),
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(1.0f, 0.0f)
    };

    Plane::Plane(bool withPositions, bool withTextureCoordinates,bool withNormals) 
        : StaticMesh3D(withPositions, withTextureCoordinates, withNormals)
    {
        initializeData();
    }

    void Plane::render() const
    {
        if (!_isInitialized) {
            return;
        }

        glBindVertexArray(_vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void Plane::initializeData()
    {
        if (_isInitialized) {
            return;
        }

        glGenVertexArrays(1, &_vao);
        glBindVertexArray(_vao);

        const auto numVertices = 4;
        const auto vertexByteSize = getVertexByteSize();
        _vbo.createVBO(vertexByteSize * numVertices);
        _vbo.bindVBO();

        if (hasPositions()) {
            _vbo.addRawData(vertices, sizeof(glm::vec3) * numVertices);
        }

        if (hasTextureCoordinates()) {
            _vbo.addRawData(textureCoordinates, sizeof(glm::vec2) * numVertices);
        }

        _vbo.uploadDataToGPU(GL_STATIC_DRAW);
        setVertexAttributesPointers(numVertices);
        _isInitialized = true;
    }

} // namespace static_meshes_3D