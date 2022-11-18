#include "graph/optimizer.hpp"
#include "tensorflow/c/experimental/grappler/grappler.h"
void TF_InitGraph(TP_OptimizerRegistrationParams* params, TF_Status* status) {
    params->struct_size = TP_OPTIMIZER_REGISTRATION_PARAMS_STRUCT_SIZE;
    params->optimizer_configs->struct_size = TP_OPTIMIZER_CONFIGS_STRUCT_SIZE;
    params->optimizer->struct_size = TP_OPTIMIZER_STRUCT_SIZE;

    // Define some configs to turn off existing optimizers.
    params->optimizer_configs->remapping = TF_TriState_Off;
    params->optimizer_configs->layout_optimizer = TF_TriState_Off;

    // Set functions to create a new optimizer.
    params->device_type = "MY_DEVICE";
    params->optimizer->create_func = (land::graph::OptimizerCreate);
    params->optimizer->optimize_func = (land::graph::OptimizerOptimize);
    params->optimizer->destroy_func = (land::graph::OptimizerDestroy);
}