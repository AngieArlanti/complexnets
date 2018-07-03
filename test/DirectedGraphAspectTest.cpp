//
// Created by María de los Ángeles Arlanti on 01/07/18.
// Modified by ... on ../../..
//
#include <gtest/gtest.h>
#include <src/core/inc/typedefs.h>
#include "DirectedGraphAspect.h"


namespace connectivityVerifierTest
{

    using namespace graphpp;
    using namespace std;
    using ::testing::Test;

    class DirectedGraphAspectTestFixture : public Test
    {

    public:

        DirectedGraph directedGraph;
        DirectedVertex* vertex;
        DirectedVertex* neighbour;

        DirectedGraphAspectTestFixture(){
            vertex = new DirectedVertex(1);
            neighbour = new DirectedVertex(2);
            //directedGraph = new DirectedGraphAspect();
        }

        virtual ~DirectedGraphAspectTestFixture(){
            delete  vertex;
            delete neighbour;
            //delete directedGraph;
        }

    };

    TEST_F(DirectedGraphAspectTestFixture, RemoveVertexTest){

        vertex->addEdge(neighbour);
        neighbour->addEdge(vertex);
        ASSERT_EQ(vertex->degree(), 1);
        ASSERT_EQ(neighbour->degree(), 1);

        directedGraph.removeVertex(vertex);

        ASSERT_EQ(neighbour->degree(), 0);
    }
}

