#ifndef CORE_GRAPH_OPTIMIZER_HPP
#define CORE_GRAPH_OPTIMIZER_HPP

#include "tensorflow/c/experimental/grappler/grappler.h"

namespace land {
namespace graph {

typedef struct Optimizer {
} Optimizer;

void *OptimizerCreate();

void OptimizerDestroy(void *optimizer);

void OptimizerOptimize(void *optimizer, const TF_Buffer *graph_buf,
                       const TF_GrapplerItem *item,
                       TF_Buffer *optimized_graph_buf, TF_Status *status);
}  // namespace graph
}  // namespace land

#endif
