#include "Control/Observer.h"

namespace Control {

    Observer::Observer() {
        this->pIM = Managers::Input::getInstance();
        pIM->Attach(this);
    }

    Observer::~Observer() {
        pIM->Detach(this);
    }

} // namespace Control