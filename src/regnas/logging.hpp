#pragma once

#include <quill/LogMacros.h>
#include <quill/Logger.h>

namespace rgn {

quill::Logger* get_or_create(const char* name);

} // namespace ksn
