#ifndef NYAYA_SUTRAS_H
#define NYAYA_SUTRAS_H

#include <string>

namespace DivineEarthlyKernels::Logic {
class NyayaSutras {
public:
    static bool infer(const std::string& premise, const std::string& conclusion);
};
}
#endif