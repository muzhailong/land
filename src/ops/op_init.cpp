#include <mutex>

#include "ops/op_init.hpp"

namespace land {
namespace op {

void RegisterOps() {
    RegisterAddOp();
    RegisterReluOp();
}

}  // namespace op
}  // namespace land
