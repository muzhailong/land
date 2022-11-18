#include "graph/optimizer.hpp"
#include "graph/tf_buffer.hpp"
#include "tensorflow/c/tf_status.h"
#include "utils/graph.pb.h"

namespace land {
namespace graph {

void *OptimizerCreate() {
    auto *optimizer = new Optimizer;
    return reinterpret_cast<void *>(optimizer);
}

void OptimizerDestroy(void *optimizer) {
    if (optimizer != nullptr) {
        delete reinterpret_cast<Optimizer *>(optimizer);
    }
}

void OptimizerOptimize(void *optimizer, const TF_Buffer *graph_buf,
                       const TF_GrapplerItem *item,
                       TF_Buffer *optimized_graph_buf, TF_Status *status) {
    land::GraphDef graph_def;
    BufferToMessage(graph_buf, graph_def, status);
    if (TF_GetCode(status) != TF_OK) {
        return;
    }

    land::GraphDef optimized_graph_def = graph_def;
    MessageToBuffer(optimized_graph_def, optimized_graph_buf, status);
    if (TF_GetCode(status) != TF_OK) return;
}

}  // namespace graph
}  // namespace land