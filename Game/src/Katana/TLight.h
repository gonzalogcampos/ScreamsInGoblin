#include "../../lib/GL/glew.h"
#include "../../lib/glm/ext.hpp"

class TEntity;
class TLight : public TEntity
{
    private:
        glm::vec4 intensity = glm::vec4(1.0,1.0,1.0,1.0);
        bool activated;
    public:
        TLight(){}
        ~TLight(){}

        //Get & Set
        void setIntesity(glm::vec4 i){ intensity = i;};
        glm::vec4 getIntensity(){ return intensity;};
        void setActivated(bool a){activated = a;};
        bool getActivated(){return activated;};

        void beginDraw(){}
        void endDraw(){}
};