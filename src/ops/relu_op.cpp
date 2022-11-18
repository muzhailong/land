#include <memory>

#include "ops/op_init.hpp"
#include "tensorflow/c/ops.h"

namespace land {
namespace op {
void RegisterReluOp() {
    TF_OpDefinitionBuilder* relu = TF_NewOpDefinitionBuilder("_Relu");
    TF_OpDefinitionBuilderAddInput(relu, "in_0: T");
    TF_OpDefinitionBuilderAddOutput(relu, "out_0: T");
    TF_OpDefinitionBuilderAddAttr(relu, "T: {bfloat16, float, double}");
    TF_Status* status = TF_NewStatus();
    TF_RegisterOpDefinition(relu, status);
    if (TF_GetCode(status) != TF_OK) { /* handle errors */
    }
}

}  // namespace op
}  // namespace land