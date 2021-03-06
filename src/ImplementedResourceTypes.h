#ifndef IOTIVITY_BAKALARKA_IMPLEMENTEDRESOURCETYPES_H
#define IOTIVITY_BAKALARKA_IMPLEMENTEDRESOURCETYPES_H

#include "exceptions/UnknownTypeServerException.h"
#include "ResourceRepresentation.h"
#include "LightServer.h"
#include "ResourceArgumentsBundle.h"
#include "LightResource.h"
#include "UnknownTypeResRepr.h"


static vector<string> typesDatabase{
        FALSE_STRING_RETURN_VALUE,
        OIC_LIGHT_TYPE,
        OIC_TEMPERATURE_TYPE,
};

using namespace std;

class ImplementedResourceTypes {
public:
    enum types{
        ERROR,
        LIGHT_TYPE,
        TEMPERATURE_TYPE,
    };
    static int findInDatabase(const string &type){
        for (unsigned int i = 0; i < typesDatabase.size(); i++){
            if(typesDatabase[i] == type){
                return i;
            }
        }
        return -1;
    }
    static Server *createServerOfType(const string &type, const string &name ) throw(UnknownTypeServerException){
        int typeValue = findInDatabase(type);

        switch (typeValue){
            case LIGHT_TYPE:
                return new LightServer(name);
            case ERROR:
                throw UnknownTypeServerException();
            default:
                throw UnknownTypeServerException();
        }
    };

    static ResourceRepresentation *createResourceRepresentationOfType(const string &type, ResourceArgumentsBundle args){
        int typeValue = findInDatabase(type);
        switch (typeValue){
            case LIGHT_TYPE:
                return new LightResource(args);
            default:
                return new UnknownTypeResRepr(args);
        }

    };

};

#endif //IOTIVITY_BAKALARKA_IMPLEMENTEDRESOURCETYPES_H
