#pragma once

// GLM
#include <glm/glm.hpp>

// Project
#include "staticMesh3D.h"

namespace static_meshes_3D {

    /**
     * Plain ground static mesh.
     */
    class Plane : public StaticMesh3D
    {
    public:
        Plane(bool withPositions = true, bool withTextureCoordinates = true, bool withNormals = false);

        static glm::vec3 vertices[4]; // Array of mesh vertices
        static glm::vec2 textureCoordinates[4]; // Array of mesh texture coordinates

        void render() const override;

    protected:
        void initializeData() override;
    };

} // namespace static_meshes_3D