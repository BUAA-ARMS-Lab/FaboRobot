#include "System.h"

namespace Fabo
{

System *System::mpSystem = new (std::nothrow) System();

System *System::GetInstance()
{
    return mpSystem;
}

void System::DeleteInstance() {
    if (mpSystem) {
        delete mpSystem;
        mpSystem = nullptr;
    }
}

}