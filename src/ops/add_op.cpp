#include <memory>

#include "ops/op_init.hpp"
#include "tensorflow/c/ops.h"

namespace land {
namespace op {
void RegisterAddOp() {
    TF_OpDefinitionBuilder* add = TF_NewOpDefinitionBuilder("_Add");
    TF_OpDefinitionBuilderAddInput(add, "in_0: T");
    TF_OpDefinitionBuilderAddInput(add, "in_1: T");
    TF_OpDefinitionBuilderAddOutput(add, "out_0: T");
    TF_OpDefinitionBuilderAddAttr(add, "T: {bfloat16, float, double}");
    TF_Status* status = TF_NewStatus();
    TF_RegisterOpDefinition(add, status);
    if (TF_GetCode(status) != TF_OK) { /* handle errors */
    }
}

}  // namespace op
}  // namespace land
