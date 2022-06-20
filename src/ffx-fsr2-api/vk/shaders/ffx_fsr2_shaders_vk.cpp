// This file is part of the FidelityFX SDK.
//
// Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "ffx_fsr2_shaders_vk.h"

#include "ffx_fsr2_autogen_reactive_pass_permutations.h"
#include "ffx_fsr2_accumulate_pass_permutations.h"
#include "ffx_fsr2_compute_luminance_pyramid_pass_permutations.h"
#include "ffx_fsr2_depth_clip_pass_permutations.h"
#include "ffx_fsr2_lock_pass_permutations.h"
#include "ffx_fsr2_prepare_input_color_pass_permutations.h"
#include "ffx_fsr2_reconstruct_previous_depth_pass_permutations.h"
#include "ffx_fsr2_rcas_pass_permutations.h"
#include <string.h>

#if defined(POPULATE_PERMUTATION_KEY)
#undef POPULATE_PERMUTATION_KEY
#endif // #if defined(POPULATE_PERMUTATION_KEY)
#define POPULATE_PERMUTATION_KEY(options, key)                                                                \
key.index = 0;                                                                                                \
key.FFX_FSR2_OPTION_USE_LANCZOS_LUT = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_LANCZOS_LUT);                     \
key.FFX_FSR2_OPTION_HDR_COLOR_INPUT = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_HDR_COLOR_INPUT);                 \
key.FFX_FSR2_OPTION_LOW_RESOLUTION_MOTION_VECTORS = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_LOW_RES_MOTION_VECTORS);   \
key.FFX_FSR2_OPTION_JITTERED_MOTION_VECTORS = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_JITTER_MOTION_VECTORS);   \
key.FFX_FSR2_OPTION_INVERTED_DEPTH = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_DEPTH_INVERTED);                   \
key.FFX_FSR2_OPTION_APPLY_SHARPENING = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_ENABLE_SHARPENING);                 \
key.FFX_HALF = FFX_CONTAINS_FLAG(options, FSR2_SHADER_PERMUTATION_ALLOW_FP16);

#if defined(POPULATE_SHADER_BLOB)
#undef POPULATE_SHADER_BLOB
#endif // #if defined(POPULATE_SHADER_BLOB)
#define POPULATE_SHADER_BLOB(info, index)  { info[index].blobData, info[index].blobSize, info[index].numStorageImageResources, info[index].numSampledImageResources, info[index].numUniformBufferResources, info[index].storageImageResourceNames, info[index].storageImageResourceBindings, info[index].sampledImageResourceNames, info[index].sampledImageResourceBindings, info[index].uniformBufferResourceNames, info[index].uniformBufferResourceBindings  }

Fsr2ShaderBlobVK fsr2GetPrepareInputColorPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_prepare_input_color_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_prepare_input_color_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_prepare_input_color_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetDepthClipPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_depth_clip_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_depth_clip_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_depth_clip_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetReconstructPreviousDepthPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_reconstruct_previous_depth_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_reconstruct_previous_depth_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_reconstruct_previous_depth_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetLockPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_lock_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_lock_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_lock_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetAccumulatePassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_accumulate_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_accumulate_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_accumulate_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetRCASPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_rcas_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_rcas_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_rcas_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetComputeLuminancePyramidPassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_compute_luminance_pyramid_pass_PermutationKey key;

    key.index = 0;                                                                                                
    key.FFX_FSR2_OPTION_USE_LANCZOS_LUT = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_LANCZOS_LUT);                     
    key.FFX_FSR2_OPTION_HDR_COLOR_INPUT = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_HDR_COLOR_INPUT);
    key.FFX_FSR2_OPTION_LOW_RESOLUTION_MOTION_VECTORS = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_LOW_RES_MOTION_VECTORS);
    key.FFX_FSR2_OPTION_JITTERED_MOTION_VECTORS = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_JITTER_MOTION_VECTORS);
    key.FFX_FSR2_OPTION_INVERTED_DEPTH = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_DEPTH_INVERTED);
    key.FFX_FSR2_OPTION_APPLY_SHARPENING = FFX_CONTAINS_FLAG(permutationOptions, FSR2_SHADER_PERMUTATION_ENABLE_SHARPENING);

    const int32_t tableIndex = g_ffx_fsr2_compute_luminance_pyramid_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_compute_luminance_pyramid_pass_PermutationInfo, tableIndex);
}

Fsr2ShaderBlobVK fsr2GetAutogenReactivePassPermutationBlobByIndex(uint32_t permutationOptions) {

    ffx_fsr2_autogen_reactive_pass_PermutationKey key;

    POPULATE_PERMUTATION_KEY(permutationOptions, key);

    const int32_t tableIndex = g_ffx_fsr2_autogen_reactive_pass_IndirectionTable[key.index];
    return POPULATE_SHADER_BLOB(g_ffx_fsr2_autogen_reactive_pass_PermutationInfo, tableIndex);
}

FfxErrorCode fsr2GetPermutationBlobByIndex(FfxFsr2Pass passId, uint32_t permutationOptions, Fsr2ShaderBlobVK* outBlob)
{
    switch (passId) {

    case FFX_FSR2_PASS_PREPARE_INPUT_COLOR:
    {
        Fsr2ShaderBlobVK blob = fsr2GetPrepareInputColorPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_DEPTH_CLIP:
    {
        Fsr2ShaderBlobVK blob = fsr2GetDepthClipPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_RECONSTRUCT_PREVIOUS_DEPTH:
    {
        Fsr2ShaderBlobVK blob = fsr2GetReconstructPreviousDepthPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_LOCK:
    {
        Fsr2ShaderBlobVK blob = fsr2GetLockPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_ACCUMULATE:
    case FFX_FSR2_PASS_ACCUMULATE_SHARPEN:
    {
        Fsr2ShaderBlobVK blob = fsr2GetAccumulatePassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_RCAS:
    {
        Fsr2ShaderBlobVK blob = fsr2GetRCASPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_COMPUTE_LUMINANCE_PYRAMID:
    {
        Fsr2ShaderBlobVK blob = fsr2GetComputeLuminancePyramidPassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    case FFX_FSR2_PASS_GENERATE_REACTIVE:
    {
        Fsr2ShaderBlobVK blob = fsr2GetAutogenReactivePassPermutationBlobByIndex(permutationOptions);
        memcpy(outBlob, &blob, sizeof(Fsr2ShaderBlobVK));
        return FFX_OK;
    }

    default:
        FFX_ASSERT_FAIL("Should never reach here.");
        break;
    }

    // return an empty blob
    memset(outBlob, 0, sizeof(Fsr2ShaderBlobVK));
    return FFX_OK;
}