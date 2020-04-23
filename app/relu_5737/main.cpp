#include "nvdla_api.h"

int main()
{
    nvdlaInit();

    float values1[] = {4, 1, 4, 3, 4, 1, 2, 2, 2};
    addInputOp(1234, 1, 1, 3, 4);
    auto weights = addFloatWeights(values1, 9);
    auto bias = addFloatWeights(nullptr, 0);

    addConvOp(1234, 2345, 9, 1, 1, 0, 0, 1, 1, 1, 1, weights, bias, 1);
    addReluOp(2345, 4567);
    
    nvdlaCompile();
    
    return 0;
}